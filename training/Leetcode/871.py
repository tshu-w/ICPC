from heapq import *

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        stations.append([target, 0])
        ans, heap = 0, []
        for station in stations:
            while heap and startFuel < station[0]:
                ans += 1
                startFuel -= heappop(heap)
            if startFuel < station[0]:
                return -1
            heappush(heap, -station[1])

        return ans
