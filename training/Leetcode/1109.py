class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        cnt = [0] * (n + 1)
        for i, j, k in bookings:
            cnt[i - 1] += k
            cnt[j] -= k

        for i in range(n):
            if i:
                cnt[i] += cnt[i - 1]

        return cnt[:-1]
