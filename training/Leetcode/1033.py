class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        a, b, c = sorted([a, b, c])
        imin = (min(b - a - 1, 1) + min(c - b - 1, 1))
        if min(b - a, c - b) == 2:
            imin = min(imin, 1)
        imax = b - a - 1 + c - b - 1
        return [imin, imax]
