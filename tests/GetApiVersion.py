from vnctpmd import MdApi
from vnctptd import TdApi


md = MdApi()

td = TdApi()

print("MdApi Version:" + md.GetApiVersion())
print("TdApi Version:" + td.GetApiVersion())
