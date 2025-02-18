

d = int(input())

# if d > 10:
#     print(1, 2, 3)
# else:
#     print(11, 51, 100)

for a in range(1, 101):
    for b in range(1, 101):
        for c in range(1, 101):
            if a == b or a == c or a == d or b == c or b == d or c == d :
                continue
            found = False

            p = [(a, [b, c]), (b, [a, c]), (c, [a, b])]
            while p and not found:
                new_p = []
                for x, left in p:
                    if x == d:
                        found = True
                    else:
                        for l in left:
                            new_p.append((x + l, [m for m in left if m != l]))
                            new_p.append((x - l, [m for m in left if m != l]))
                            new_p.append((l - x, [m for m in left if m != l]))
                            new_p.append((x * l, [m for m in left if m != l]))
                            if l != 0:
                                new_p.append((x / l, [m for m in left if m != l]))
                            if x != 0:
                                new_p.append((l / x, [m for m in left if m != l]))

                p = new_p
            if not found:
                print(a, b, c)
                exit(0)


