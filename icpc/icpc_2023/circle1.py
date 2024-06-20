import math, sys


n = int(input())

points = []


def is_equal_float(f1, f2) -> bool:
    return abs(f1 - f2) < 10 ** -9

if n < 3:
    print("Yes")

else:
    for i in range(n):
        (x, y) = map(float, input().split())
        points.append((x, y))

    # first three points
    f1, f2, f3 = points[0:3]

    # midpoints
    mp1 = ((f1[0] + f2[0]) / 2, (f1[1] + f2[1]) / 2)
    mp2 = ((f2[0] + f3[0]) / 2, (f2[1] + f3[1]) / 2)

    # same horizontal line
    if (f1[1] - f2[1]) == 0 and (f2[1] - f3[1]) == 0:
        print("No")
        sys.exit(0)

    # first line is vertical
    elif (f1[1] - f2[1]) == 0:
        # perp gradient
        p2 = -(f2[0] - f3[0]) / (f2[1] - f3[1])

        b2 = mp2[1] - (p2) * mp2[0]

        ipx = mp1[0]
        ipy = p2 * ipx + b2
        ans = True

        # print(ipx, ipy)
        
        dist1 = math.sqrt((ipx - f1[0]) ** 2 + (ipy - f1[1]) ** 2)

        for point in points[1:]:
            d = math.sqrt((ipx - point[0]) ** 2 + (ipy - point[1]) ** 2)
            # print(d, dist1)
            if not is_equal_float(dist1, d):
                ans = False
        if ans:
            print("Yes")
        else:
            print("No")

    # second line is vertical
    elif (f2[1] - f3[1]) == 0:
        p1 = -(f1[0] - f2[0]) / (f1[1] - f2[1])


        b1 = mp1[1] - (p1) * mp1[0]

        ipx = mp2[0]

        ipy = p1 * ipx + b1
        ans = True

        # print(ipx, ipy)
        
        dist1 = math.sqrt((ipx - f1[0]) ** 2 + (ipy - f1[1]) ** 2)

        for point in points[1:]:
            d = math.sqrt((ipx - point[0]) ** 2 + (ipy - point[1]) ** 2)
            # print(d, dist1)
            if not is_equal_float(dist1, d):
                ans = False
        if ans:
            print("Yes")
        else:
            print("No")

    # no vertical lines
    else:
        p1 = -(f1[0] - f2[0]) / (f1[1] - f2[1])
        p2 = -(f2[0] - f3[0]) / (f2[1] - f3[1])

        b1 = mp1[1] - (p1) * mp1[0]
        b2 = mp2[1] - (p2) * mp2[0]

        # print(mp1, mp2)
        # print(p1, p2)
        # print(b1, b2)

        if (p1 == p2):
            print("No")
            sys.exit(0)

        ipx = -(b1 - b2) / (p1 - p2)
        ipy = p1 * ipx + b1
        ans = True

        # print(ipx, ipy)
        
        dist1 = math.sqrt((ipx - f1[0]) ** 2 + (ipy - f1[1]) ** 2)
        
        for point in points[1:]:
            d = math.sqrt((ipx - point[0]) ** 2 + (ipy - point[1]) ** 2)
            # print(d, dist1)
            if not is_equal_float(dist1, d):
                ans = False

        if ans:
            print("Yes")
        else:
            print("No")
