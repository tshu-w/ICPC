import heapq


def getMedian(minh, maxh, k):
    return minh[0][0] if k & 1 else (-maxh[0][0] + minh[0][0]) / 2


def move(h1, h2):
    x, i = heapq.heappop(h1)
    heapq.heappush(h2, (-x, i))


class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> list[float]:
        minh, maxh = [], []
        for i, n in enumerate(nums[:k]):
            minh.append((n, i))

        heapq.heapify(minh)
        for i in range(k // 2):
            move(minh, maxh)

        res = [getMedian(minh, maxh, k)]
        for i, n in enumerate(nums[k:]):
            print(i)
            print(minh, maxh)
            if n >= minh[0][0]:
                heapq.heappush(minh, (n, i + k))
                if nums[i] <= minh[0][0]:
                    move(minh, maxh)
            else:
                heapq.heappush(maxh, (-n, i + k))
                if nums[i] >= minh[0][0]:
                    move(maxh, minh)

            while minh and minh[0][1] <= i:
                heapq.heappop(minh)
            while maxh and maxh[0][1] <= i:
                heapq.heappop(maxh)

            print(minh, maxh)
            res.append(getMedian(minh, maxh, k))

        return res
