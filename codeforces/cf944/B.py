t = int(input())

for i in range(t):
    s = input()
    if all([c == s[0] for c in s]):
        print("NO")
        continue
    print("YES")
    x = s[0]
    for i in range(1, len(s)):
        if s[i] != x:
            temp = list(s)
            temp[0] = s[i]
            temp[i] = x
            print("".join(temp))
            break
