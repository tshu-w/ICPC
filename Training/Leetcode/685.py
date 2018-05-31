# -*- coding: utf-8 -*-
#!/usr/bin/env python3

class Solution:
    def findRedundantDirectedConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def find(x):
            if f[x] == x: return x
            f[x] = find(f[x])
            return f[x]

        def union(x, y):
            x = find(x)
            y = find(y)
            f[x] = f[y]

        N = len(edges)
        f = list(range(0, N + 1))
        for x, y in edges:
            if (find(x) == find(y)): return[x, y]
            else: union(x, y)
