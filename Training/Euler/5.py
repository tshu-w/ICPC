#!/usr/bin/env python
# -*- coding: utf-8 -*-

from functools import *
from math import *

def lcm(a, b):
    return abs(a * b) // gcd(a, b) if a and b else 0

print(reduce(lcm, range(1, 21)))
