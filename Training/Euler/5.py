# -*- coding: utf-8 -*-
#!/usr/bin/env python3

from math import *
from functools import *

def lcm(a,b): return abs(a * b) // gcd(a,b) if a and b else 0

print(reduce(lcm, range(1, 21)))
