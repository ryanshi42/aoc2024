n = int(input())
numbers = []
for i in range(n):
    numbers.append(int(input()))

field = ["." for _ in range(n)]

if n == 1:
    if numbers[0] == 1:
        print("*")
    elif numbers[0] == 0:
        print(".")  
    else:
        print("X")
    exit(0)


if numbers[0] == 2:
    numbers[0] -= 2
    numbers[1] -= 2
    numbers[2] -= 1
    field[0] = "*"
    field[1] = "*"

if numbers[n - 1] == 2:
    numbers[n - 1] -= 2
    numbers[n - 2] -= 2
    numbers[n - 3] -= 1

    field[n - 1] = "*"
    field[n - 2] = "*"

for i in range(0, n - 1):
    if numbers[i] == 1 and numbers[i + 1] >= 1 and (i == n - 2 or numbers[i + 2] >= 1):
        field[i + 1] = "*"
        numbers[i] -= 1
        numbers[i + 1] -= 1
        if i != n - 2:
            numbers[i + 2] -= 1

# print(numbers)
for x in numbers:
    if x != 0:
        print("X")
        exit(0)

print(''.join(field))