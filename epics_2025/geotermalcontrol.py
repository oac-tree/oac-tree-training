from p4p.rpc import rpc, quickRPCServer
from p4p.nt import NTScalar
import math

max_temp = 24
min_temp = 6
sunrise_time = "06:45:00"
sunset_time = "18:30:00"
humidity = 58


class Greenhouse(object):
        @rpc(NTScalar('d', extra=[('result', 'I')]))
        def get_out_temperature(self, minutes):
            sunrise_in_minutes = 6 * 60 + 45
            sunset_in_minutes = 18 * 60 + 30
            temp_range = max_temp - min_temp
            temp_mid = min_temp + temp_range / 2
            temp = temp_mid + temp_range / 2 * math.sin(math.pi * (minutes - sunrise_in_minutes) / (sunset_in_minutes - sunrise_in_minutes))
            return {"result": 0, "value": temp}





class Summer(object):
    @rpc(NTScalar('d', extra=[('result', 'I')]))
    def add(self, lhs, rhs):
        result = float(lhs) + float(rhs)
        # return [result]
        return {"result": 0, "value": result}

adder = Summer()
greenhouse = Greenhouse()

import logging
logging.basicConfig(level=logging.DEBUG)


quickRPCServer(provider="Example",
               prefix="greenhouse:",  # A prefix for method PV names.
               target=greenhouse)
