print("Hello world")

def triangle_num(row):
    return (row * (row + 1)) // 2
    
row = 1
curr_row = []
    
inp = [6, 6, 2, 8, 9, 3, 7, 8, 7, 5, 6, 9, 8, 2, 1]
T = []
for i, elem in enumerate(inp):
    curr_row.append(elem)
    if triangle_num(row) == i + 1:
        T.append(curr_row)
        row += 1
        curr_row = []
print(T)
n = len(T)

dp = [[0 for _ in range(n)] for _ in range(n)]

for i, row in enumerate(dp[::-1]):
    print(i, row)
    
