#!/usr/bin/env python
# -*- coding: utf-8 -*-

def f(x):
    return x % 3 == 0 or x % 5 == 0

print(sum(filter(f, range(1000))))
