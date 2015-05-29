#!/usr/bin/python
# vim: ts=2 sw=2 expandtab

# author: Penn Su
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
import glob
import copy
import fcntl, termios, struct

import tornado.options
tornado.options.define("appdir", type=str, help="Directory that contains the applications")
tornado.options.parse_command_line()
from configuration import *
'''
if WKPFCOMM_AGENT == "ZWAVE":
  try:
    import pyzwave
    m = pyzwave.getDeviceType
  except:
    print "Please install the pyzwave module in the wukong/tools/python/pyzwave by using"
    print "cd ../tools/python/pyzwave; sudo python setup.py install"
    sys.exit(-1)
    '''
import wkpf.wusignal
from wkpf.wuapplication import WuApplication
from wkpf.wuclasslibraryparser import *
from wkpf.wkpfcomm import *
from wkpf.util import *

import wkpf.globals
from configuration import *

import tornado.options

if(MONITORING == 'true'):
    try:
      from pymongo import MongoClient
    except:
      print "Please install python mongoDB driver pymongo by using"
      print "easy_install pymongo"
      sys.exit(-1)

    try:
        wkpf.globals.mongoDBClient = MongoClient(MONGODB_URL)

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


class Test:
  def __init__(self):
    self.id = 0
    self.sensor = 'light sensor'
    wkpf.globals.mongoDBClient = MongoClient(MONGODB_URL)
    self.value = wkpf.globals.mongoDBClient.wukong.readings.find().sort('timestamp',-1).limit(1)[2]
          #wkpf.globals.mongoDBClient.wukong.readings.find().sort({"timestamp":-1}).sort("timestamp":-1)['value']

class Monitoring(tornado.web.RequestHandler):
  def get(self):
      obj1 = Test()
      obj2 = Test()
      self.render('templates/index2.html', applications=[obj1,obj2])


def setup_signal_handler_greenlet():
  logging.info('setting up signal handler')
  gevent.spawn(wusignal.signal_handler)




settings = dict(
  static_path=os.path.join(os.path.dirname(__file__), "static"),
  debug=True
)

ioloop = tornado.ioloop.IOLoop.instance()
wukong = tornado.web.Application([
  (r"/monitoring",Monitoring)
], IP, **settings)

logging.info("Starting up...")
setup_signal_handler_greenlet()


if __name__ == "__main__":
  wkpf.globals.mongoDBClient = MongoClient(MONGODB_URL)
  print wkpf.globals.mongoDBClient.wukong.readings.find().sort('timestamp',-1).limit(1)[2]
  ioloop.start()
  
