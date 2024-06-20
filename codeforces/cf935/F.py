
t = int(input())

arr = list(map(int, input().split()))

while len(arr) > 1:
    for i in range(len(arr) - 1):
        if arr[i] < arr[i + 1]:
            del arr[i]
            break
        elif arr[i] == arr[i + 1]:
            arr[i + 1] *= 2
            del arr[i]
            break
    if len(arr) >= 2 and arr[-1] < arr[-2]:
        arr.pop()

print(arr[0])