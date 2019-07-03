from functools import reduce
class Solution:
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        return chr(reduce(lambda x, y: x ^ ord(y), s + t, 0))
