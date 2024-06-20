
n = int(input())
queries = []
for i in range(n):
    x = int(input())
    q = map(int, input().split())
    queries.append((x, *q))

for i in range(1, n + 1):
    t = 0
    (x, *apples) = queries[i - 1]
    apples.sort()
    # print(x, apples)

    # if even just ignore lol
    if x == 1:
        t = 1
    elif x * 2 - 1 == len(apples):
        
        j = 1
        k = len(apples) - 2

        # know at least 3 elements exist
        wrong = False
        target = apples[0] + apples[-1]
        while j < k:
            if apples[j] + apples[k] == target:
                j += 1
                k -= 1
            else:
                if wrong:
                    t = 0
                    break
                wrong = True
                if apples[j] + apples[k] < target:
                    t = target - apples[j]
                    j += 1
                else:
                    t = target - apples[k]
                    k -= 1

        if not wrong:
            t = target - apples[j]
        
    if x > 1 and t == 0:
        # print("yes")
        # try append or try put at start of list
        target = apples[1] + apples[-1]
        test = target - apples[0]
        y = False

        j = 1
        k = len(apples) - 1
        while j < k:
            if apples[j] + apples[k] == target:
                j += 1
                k -= 1

            else:
                y = True
                break
        if not y:
            t = test

        
        # try append or try put at start of list
        target = apples[0] + apples[-2]
        test = target - apples[-1]
        y = False

        j = 0
        k = len(apples) - 2
        while j < k:
            if apples[j] + apples[k] == target:
                j += 1
                k -= 1

            else:
                y = True
                break
        if not y:
            if t == 0:
                t = test
            else:
                t = min(t, test)





    ans = t if t != 0 else -1
    print(f"Case #{i}: {ans}")
