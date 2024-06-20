


def go():
    ma = 16
    mb = mc = 6

    v = {}

    l = 2024
    for b in range(0, l + 1):
        print(b)
        new_v = {}
        for i in range(ma):
            for j in range(mb):
                for k in range(mc):
                    if (b == 0):
                        new_v[(i, j, k)] = 1
                        continue
                    else:
                        for x in range(i + 1):
                            for y in range(j + 1):
                                for z in range(k + 1):
                                    if ((i, j, k) not in new_v):
                                        new_v[(i, j, k)] = 0
                                    new_v[(i, j, k)] += v[(x, y, z)]
                    # print(i, j, k)
        v = new_v
    print(v[(ma - 1, mb - 1, mc - 1)])

go()