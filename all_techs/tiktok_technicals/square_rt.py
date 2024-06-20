

def square_root(n):
    # Input: 9 
    # Output: 3

    # Input: 2
    # Output: 1.4121
    # 5 decimal places

    if n == 1:
        return 1

    l = 1
    r = n

    def is_close_to(x, y):
        return abs(x - y) < 0.000001

    while l < r:
        mid = l + (r - l) / 2
        if is_close_to(mid * mid, n):
            return mid
        elif mid * mid < n:
            l = mid
        else:
            r = mid

    return l

print(square_root(9))
print(square_root(1))
print(square_root(2))
print(square_root(3))