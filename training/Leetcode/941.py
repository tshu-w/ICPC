class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        flag = False
        i, n = 1, len(A)
        while i < n - 1 and A[i - 1] < A[i] < A[i + 1]:
            i += 1
        if i < n - 1 and A[i - 1] < A[i] > A[i + 1]:
            i += 1
            flag = True
        while i < n - 1 and A[i - 1] > A[i] > A[i + 1]:
            i += 1

        return i == n - 1 and flag
