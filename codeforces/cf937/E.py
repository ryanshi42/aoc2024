
t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    factors = []

    for i in range(1, n // 2 + 1):
        if (n % i == 0):
            factors.append(i)
            factors.append(n // i)

    factors.sort()

    ans = n
    for f in factors:
        d = dict()
        found = True
        for i in range(n // f):

            substr = s[i * f:(i + 1) * f]
            # print(substr)
            if substr in d:
                d[substr] += 1
            else:
                d[substr] = 1
            if len(d) > 2:
                found = False
                break

        if not found:
            continue
        l = list(d.keys())
        # print(d)

        def check(a, b):
            e = 0
            for i in range(len(a)):
                if a[i] != b[i]:
                    e += 1

            return e < 2
        if len(l) == 1 or ((d[l[0]] < 2 or d[l[1]] < 2) and check(l[0], l[1])):
            ans = f
            break

        
    print(ans)

    