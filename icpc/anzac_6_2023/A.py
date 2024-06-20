

import math

h, r, da, dw = map(int, input().split())



# va = vt + vh

# wa = da * va
# ww = dw * vw

def calck(t):
    ma = (h - t) * da
    mw = t * dw

    ca = h + (h - t) / 2
    cw = t / 2

    k = (ca * ma + cw * mw) / (ma + mw)
    return k




# l = 0
# r = 10 ** 15

# # import sys

# while l < r:
#     mid = (l + r) // 2
#     mid = mid / (10 ** 12)
#     print(mid, calck(mid))
#     # if mid <= 1:
#     #     print("????")
#     if calck(mid - 1) >= calck(mid) and calck(mid + 1) >= calck(mid):
#         print(mid)
#         break
#     elif calck(mid - 1) >= calck(mid):
#         l = mid + 1
#     elif calck(mid + 1) >= calck(mid):
#         r = mid - 1
#     else:
#         print(calck(mid - 1), calck(mid), calck(mid + 1))
#         print("hkjasdfhladksjhfakljashdlfkjahs")
#         break
# print(mid)

