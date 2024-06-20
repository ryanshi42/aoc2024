

n = int(input())
arr = list(map(int, input().split()))

import heapq

def DecreasingArray(arr, n):
    ans = 0

    # max heap
    pq = []
    heapq.heapify(pq)
    for i in range(n - 1, -1, -1):
        if pq and -pq[0] > arr[i]:
            ans += abs(arr[i] + pq[0])
            heapq.heappop(pq)
            heapq.heappush(pq, -arr[i])
        heapq.heappush(pq, -arr[i])
    return ans


arr = list(reversed(arr))
print(DecreasingArray(arr, n))
