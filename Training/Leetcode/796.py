#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution:
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        return len(A) == len(B) and B in A + A
