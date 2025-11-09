class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        i, j = 0, 0
        a, b = 0, 0
        while (i < len(nums1) and j < len(nums2)):
            if (nums1[i] < nums2[j]):
                a += nums1[i]
                i += 1
            elif (nums1[i] > nums2[j]):
                b += nums2[j]
                j += 1
            else:
                a = b = max(a + nums1[i], b + nums2[j])
                i += 1
                j += 1

        while (i < len(nums1)):
            a += nums1[i]
            i += 1

        while (j < len(nums2)):
            b += nums2[j]
            j += 1

        return max(a, b) % 1000000007
