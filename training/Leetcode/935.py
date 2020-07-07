class Solution:
    def knightDialer(self, N: int) -> int:
        neighbors = [[4, 6], [6, 8], [7, 9], [4, 8], [0, 3, 9], [], [0, 1, 7], [2, 6], [1, 3], [2, 4]]
        cur = [1] * 10

        for i in range(N - 1):
            nxt = [0] * 10
            for j in range(10):
                for neighbor in neighbors[j]:
                    nxt[j] += cur[neighbor]
            cur = nxt

        return sum(cur) % (10 ** 9 + 7)
