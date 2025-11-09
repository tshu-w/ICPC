class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        t = [None] * len(s)
        for i in indices:
            t[indices[i]] = s[i]

        return "".join(t)
