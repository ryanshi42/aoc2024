
valid = "RB"

for i in range(3, 6):
    num_seats = i
    # table = ["." for _ in range()]
    arrangements = []

    def dfs(left, cur, num_seats):
        if left == num_seats:
            arrangements.append(''.join(cur))
            return
        dfs(left + 1, cur + ["."], num_seats)
        dfs(left + 1, cur + ["R"], num_seats)
        # dfs(left + 1, cur + ["B"], num_seats)
    
    dfs(0, [], num_seats)
    # print(arrangements)

    seen = set()

    def is_rotation(s1, s2):
        temp = s1 + s1
        if s2 in temp:
            return True
        else:
            return False

    for a in arrangements:
        existing = False
        # for found in seen:
        #     if is_rotation(a, found):
        #         existing = True
        #         break
        if not existing:
            seen.add(a)
    print(seen)

    scores = 0
    for s in seen:
        score = 0
        new_s = list(s)
        for i, char in enumerate(s):
            if char == "R":
                if i > 0 and new_s[i - 1] == ".":
                    new_s[i - 1] = "B"
                elif i == 0 and new_s[-1] == ".":
                    new_s[-1] = "B"

                if i + 1 < len(new_s) and new_s[i + 1] == ".":
                    new_s[i + 1] = "B"
                elif i + 1 == len(new_s) and new_s[0] == ".":
                    new_s[0] = "B"
        
        for i, char in enumerate(new_s):
            if char == "B" or char == "R":
                score += 1
        # print(new_s)
        scores += score
        # print(score)
    print(scores)

print([7 * 2 ** (n - 3) * (n) for n in range(3, 50)])
