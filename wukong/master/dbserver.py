#!/usr/bin/python
# vim: ts=2 sw=2 expandtab

# author: Penn Su
import dateutil.parser

from gevent import monkey; monkey.patch_all()
import gevent
import serial
import platform
import os, sys, zipfile, re, time
import tornado.ioloop, tornado.web
import tornado.template as template
import simplejson as json
from jinja2 import Template
import logging
import hashlib
from threading import Thread
import traceback
import StringIO
import shutil, errno
import datetime
from datetime import date, timedelta
import glob
import copy
import fcntl, termios, struct
from types import *

import tornado.options
tornado.options.define("appdir", type=str, help="Directory that contains the applications")
tornado.options.parse_command_line()
from configuration_db import *

if WKPFCOMM_AGENT == "ZWAVE":
  try:
    import pyzwave
    m = pyzwave.getDeviceType
  except:
    print "Please install the pyzwave module in the wukong/tools/python/pyzwave by using"
    print "cd ../tools/python/pyzwave; sudo python setup.py install"
    sys.exit(-1)
import pymongo


import tornado.options

if(MONITORING == 'true'):
    try:
      from pymongo import MongoClient
    except:
      print "Please install python mongoDB driver pymongo by using"
      print "easy_install pymongo"
      sys.exit(-1)

    try:
        mongoDBClient = MongoClient(MONGODB_URL)

    except:
      print "MongoDB instance " + MONGODB_URL + " can't be connected."
      print "Please install the mongDB, pymongo module."
      sys.exit(-1)

tornado.options.parse_command_line()
#tornado.options.enable_pretty_logging()

IP = sys.argv[1] if len(sys.argv) >= 2 else '127.0.0.1'

landId = 100
node_infos = []



from make_js import make_main
from make_fbp import fbp_main
def import_wuXML():
  make_main()
  
def make_FBP():
  test_1 = fbp_main()
  test_1.make() 

wkpf.globals.location_tree = LocationTree(LOCATION_ROOT)

def initializeVirtualNode():
    # Add the server as a virtual Wudevice for monitoring
    wuclasses = {}
    wuobjects = {}

    # 1 is by default the network id of the controller
    node = WuNode(1, '/' + LOCATION_ROOT, wuclasses, wuobjects, 'virtualdevice')
    wuclassdef = WuObjectFactory.wuclassdefsbyid[44]
    wuobject = WuObjectFactory.createWuObject(wuclassdef, node, 1, False)
    wkpf.globals.virtual_nodes[1] = node


# using cloned nodes
def rebuildTree(nodes):
  nodes_clone = copy.deepcopy(nodes)
  wkpf.globals.location_tree = LocationTree(LOCATION_ROOT)
  wkpf.globals.location_tree.buildTree(nodes_clone)
  flag = os.path.exists("../LocalData/landmarks.txt")
  if(flag):
      wkpf.globals.location_tree.loadTree()
  wkpf.globals.location_tree.printTree()

# Helper functions
def setup_signal_handler_greenlet():
  logging.info('setting up signal handler')
  gevent.spawn(wusignal.signal_handler)
def allowed_file(filename):
  return '.' in filename and \
      filename.rsplit('.', 1)[1] in ALLOWED_EXTENSIONS

def copyAnything(src, dst):
  try:
    shutil.copytree(src, dst)
  except OSError as exc: # python >2.5
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print traceback.print_exception(exc_type, exc_value, exc_traceback,
                                  limit=2, file=sys.stdout)
    if exc.errno == errno.ENOTDIR:
      shutil.copy(src, dst)
    else: raise

def getAppIndex(app_id):
  # make sure it is not unicode
  app_id = app_id.encode('ascii','ignore')
  for index, app in enumerate(wkpf.globals.applications):
    if app.id == app_id:
      return index
  return None

def delete_application(i):
  try:
    shutil.rmtree(wkpf.globals.applications[i].dir)
    wkpf.globals.applications.pop(i)
    return True
  except Exception as e:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print traceback.print_exception(exc_type, exc_value, exc_traceback,
                                  limit=2, file=sys.stdout)
    return False

def load_app_from_dir(dir):
  app = WuApplication(dir=dir)
  app.loadConfig()
  return app

def update_applications():
  logging.info('updating applications:')

  application_basenames = [os.path.basename(app.dir) for app in wkpf.globals.applications]

  for dirname in os.listdir(APP_DIR):
    app_dir = os.path.join(APP_DIR, dirname)
    if dirname.lower() == 'base': continue
    if not os.path.isdir(app_dir): continue

    logging.info('scanning %s:' % (dirname))
    if dirname not in application_basenames:
      logging.info('%s' % (dirname))
      wkpf.globals.applications.append(load_app_from_dir(app_dir))
      application_basenames = [os.path.basename(app.dir) for app in wkpf.globals.applications]

class idemain(tornado.web.RequestHandler):
  def get(self):
    self.content_type='text/html'
    self.render('templates/ide.html')
# List all uploaded applications
class main(tornado.web.RequestHandler):
  def get(self):
    print "[WEB PORT]= %d" %(MONITORING_BUFSIZE)
    getComm()
    self.render('templates/application.html', connected=wkpf.globals.connected)

settings = dict(
  static_path=os.path.join(os.path.dirname(__file__), "static"),
  debug=True
)

ioloop = tornado.ioloop.IOLoop.instance()
wukong = tornado.web.Application([
  (r"/", main),
  (r"/ide", idemain),
  (r"/main", main),

], IP, **settings)

logging.info("Starting up...")
setup_signal_handler_greenlet()
WuClassLibraryParser.read(COMPONENTXML_PATH)
initializeVirtualNode();
#WuNode.loadNodes()
update_applications()
import_wuXML()
make_FBP()
wukong.listen(MASTER_PORT)

if __name__ == "__main__":
  ioloop.start()
