import operator


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        return sum(
            sum(map(operator.ne, [0] + row, row + [0]))
            for row in grid + [list(x) for x in zip(*grid)]
        )
