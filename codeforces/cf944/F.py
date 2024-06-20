t = int(input())


for i in range(t):
    r = int(input())
    if r == 1:
        print(8)
    elif r == 2:
        print(16)
    # elif r == 3:
    #     print(20)
    # elif r == 4:
    #     print(24)
    else:
        # lt = 0
        # rt = r
        # while lt < rt:
        #     mid = (lt + rt + 1) // 2
        #     if r ** 2 + mid ** 2 >= (r + 1) ** 2:
        #         rt = mid - 1
        #     else:
        #         lt = mid
        # print("lt", lt)
        # bb = lt 
        # prev_missing = 4
        # lt = 0
        # rt = r - 1
        # while lt < rt:
        #     mid = (lt + rt + 1) // 2
        #     if (r - 1) ** 2 + mid ** 2 >= (r) ** 2:
        #         rt = mid - 1
        #     else:
        #         lt = mid
        # prev_missing = 4 + (r - 2 - lt)
        aa = r
        bb = 1
        cc = 0
        cnt = 0
        while True:
            # print(aa, bb, r)
            if aa == bb and (bb ** 2) + (aa ** 2) < (r + 1) ** 2:
                cc = 1
                break
            elif bb > aa:
                # print(aa, bb, r)
                break
            elif r ** 2 <= (bb ** 2) + (aa ** 2) < (r + 1) ** 2:
                bb += 1
                cnt += 1
                if (bb ** 2) + (aa ** 2) >= (r + 1) ** 2:
                    aa -= 1
                    bb -= 1
                    if (bb ** 2) + (aa ** 2) < (r) ** 2:
                        bb += 1
            else:
                print("wtf?", aa, bb, cc, r, r ** 2, (bb ** 2) + (aa * 2),  (r + 1) ** 2)
                break
        # print(aa, bb, cc)
            
        print(4 * (1 + 2 * cnt + cc)) 