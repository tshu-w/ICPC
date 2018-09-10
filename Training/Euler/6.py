#!/usr/bin/env python
# -*- coding: utf-8 -*-

from math import *

def sqr(x):
    return x * x

print(sqr(sum(range(1, 101))) - sum(map(sqr, range(1, 101))))
