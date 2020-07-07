class Solution:
    def customSortString(self, S: str, T: str) -> str:
        # return "".join(sorted(T, key=S.find))

        ordering = {v: k for k, v in enumerate(S)}
        return ''.join(sorted(T, key=lambda x: ordering.get(x, -1)))
