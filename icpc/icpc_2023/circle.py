def skew(u, v):
    return u[0] * v[1] - u[1] * v[0]

def norm_squared(u):
    return u[0] ** 2 + u[1] ** 2

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


    A, B, *points = points

    angles = []

    for p in points:
        u = (A[0] - p[0], A[1] - p[1])
        v = (B[0] - p[0], B[1] - p[1])
        angles.append(skew(u, v) ** 2 / norm_squared(u) / norm_squared(v))

    if all(is_equal_float(angle, angles[0]) and not is_equal_float(angle, 0) for angle in angles):
        print("Yes")
    else:
        print("No")

