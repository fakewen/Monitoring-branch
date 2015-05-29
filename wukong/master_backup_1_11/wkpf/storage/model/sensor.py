import json
import datetime

class SensorData:

    def __init__(self, node_id, wuclass_id, port, value, timestamp):
        self.node_id = node_id
        self.wuclass_id = wuclass_id
        self.port = port
        self.value = value
        self.timestamp = timestamp

    @classmethod
    def createByPayload(self, node_id, payload):
        if (len(payload) >= 7):
            class_id = (payload[2] << 8) + payload[3]
            port = payload[4]
            type = payload[5]
            if type == 1: #boolean
                value = payload[6]
            else:
                value = (payload[6] << 8) + payload[7]
	    now=datetime.datetime.now()
            return SensorData(node_id, class_id, port, value, now.year*10000000000+now.month*100000000+now.day*1000000+now.hour*10000+now.minute*100+now.second)
        return None

    @classmethod
    def createByCollection(self, document):

        return SensorData(document['node_id'], document['wuclass_id'], document['port'],
                          document['value'], document['timestamp'])

    def toDocument(self):

        return json.dumps({'node_id': self.node_id, 'wuclass_id': self.wuclass_id, 'port':
                           self.port, 'value': self.value, 'timestamp': self.timestamp })


