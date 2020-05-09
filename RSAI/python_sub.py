import paho.mqtt.subscribe as subscribe

class Communication(object):
    def __init__(self):
        super(Communication, self).__init__()
        subscribe.callback(lambda client, userdata, message: self.onMessageReceive(message.payload), "/dtc", hostname="localhost")
    
    def onMessageReceive(self, dtc_msg):
        print(dtc_msg)

c = Communication()
