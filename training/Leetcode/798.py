class Solution:
    def bestRotation(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        B = [1] * n
        for i in range(n): B[(i - A[i] + 1) % n] -= 1
        for i in range(n - 1): B[i + 1] += B[i]
        return B.index(max(B))
