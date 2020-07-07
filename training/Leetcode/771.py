class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return sum(x in J for x in S)
