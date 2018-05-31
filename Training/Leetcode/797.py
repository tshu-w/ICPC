class Solution:
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        def dfs(v, path):
            if v == n - 1:
                result.append(path)
                return
            for u in graph[v]:
                dfs(u, path + [u])
        n = len(graph)
        result = []
        dfs(0, [0])
        return result
