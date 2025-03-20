from p4p.rpc import rpc, quickRPCServer
from p4p.nt import NTScalar
import math

humidity_mid = 58

class Greenhouse(object):
    @rpc(NTScalar('d', extra=[('result', 'I')]))
    def get_out_humidity(self, minutes):
        humidity_range = 20
        humidity = humidity_mid + humidity_range / 2 * math.sin(math.pi * (minutes - 12 * 60) / (24 * 60))
        return {"result": 0, "value": humidity}

    @rpc(NTScalar('d', extra=[('result', 'I')]))
    def get_in_humidity(self, minutes, in_temperature, current_humidity):
        out_humidity = get_out_humidity(minutes)
        in_humidity = current_humidity + 0.5 * (out_humidity - current_humidity)
        return {"result": 0, "value": in_humidity}

    @rpc(NTScalar('d', extra=[('result', 'd')]))
    def activate_sprinklers(self):
        return {"result": 0, "value": 30/60}

    @rpc(NTScalar('d', extra=[('result', 'd')]))
    def activate_ventilation(self):
        return {"result": 0, "value": 10/60}


greenhouse = Greenhouse()

import logging
logging.basicConfig(level=logging.DEBUG)


quickRPCServer(provider="Greenhouse in oac-tree",
               prefix="greenhouse:",
               target=greenhouse)
