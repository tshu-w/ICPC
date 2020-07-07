class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        ans = 1
        for it, n in enumerate(b[::-1]):
            ans = ans * (a ** n) % 1337
            a = a ** (10 if it != len(b) else 1) % 1337

        return ans % 1337
