class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        k = min(k, len(arr) - 1)
        count = 0
        cur = arr[0]
        for i in range(1, len(arr)):
            if (cur > arr[i]):
                count += 1
            else:
                count = 1
                cur = arr[i]

            if (count == k):
                    return cur

        return max(arr)
