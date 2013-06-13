#vim:fileencoding=utf8  
from ctypes import * 
import numpy as np

formula=np.ctypeslib.load_library("formula.so",".")
formula.mys.argtypes=[
np.ctypeslib.ndpointer(dtype=np.float32),
np.ctypeslib.ndpointer(dtype=np.float32)]
formula.mys.restype = c_void_p

a = np.arange(1.,7.,dtype=np.float32)
b = np.arange(0.,3.,dtype=np.float32)
print a
formula.mys(a,b)
print b


