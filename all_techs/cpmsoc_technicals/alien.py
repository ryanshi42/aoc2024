n, k = map(int, input().split())
numbers = []
for i in range(n):
    numbers.append(int(input()))

numbers.sort(reverse=True)
print(numbers[k - 1])