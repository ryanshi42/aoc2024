n = int(input())

arr = []
for _ in range(n):
    x = int(input())
    arr.append(x)

arr.sort()

if len(arr) == 2:
    print(arr[0] + arr[-1])

elif arr[0] == 0:
    print(arr[-1])

elif arr[0] == arr[-1]:
    print(arr[0] + 1)

else:
    print(ceil(sum(arr) / (len(arr) - 1)))

# 2 4 5
# 2 2 3
# 2 1 2
# 1 1 1
# 0 0 1
# 0 0 0


