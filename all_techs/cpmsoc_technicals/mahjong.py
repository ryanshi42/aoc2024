from collections import Counter
# assume max card is 14
stuff = [1, 1, 1, 2, 2, 2, 2, 3, 4, 4, 5, 6, 9, 9]

stuff.sort()

def backtrack(stuff, curr, has_pair=False):
    if sum([item for item in curr.values()]) == 14 and has_pair:
        return True
    
    # has triplets
    for i in range(0, 14):
        # choose
        if i in stuff and stuff[i] >= 3:
            stuff[i] -= 3
            curr[i] += 3
            # explore
            if backtrack(stuff, curr, has_pair):
                return True
            # unchoose
            stuff[i] += 3
            curr[i] -= 3
        

    for i in range(0, 12):
        # choose
        if stuff[i] >= 1 and stuff[i + 1] >= 1 and stuff[i + 2] >= 1:
            stuff[i] -= 1
            curr[i] += 1
            stuff[i + 1] -= 1
            curr[i + 1] += 1
            stuff[i + 2] -= 1
            curr[i + 2] += 1
            # explore
            if backtrack(stuff, curr, has_pair):
                return True
            # unchoose
            stuff[i] += 1
            curr[i] -= 1
            stuff[i + 1] += 1
            curr[i + 1] -= 1
            stuff[i + 2] += 1
            curr[i + 2] -= 1

    if not has_pair:
        for i in range(0, 14):
            # choose
            if i in stuff and stuff[i] >= 2:
                stuff[i] -= 2
                curr[i] += 2
                # explore
                if backtrack(stuff, curr, True):
                    return True
                # unchoose
                stuff[i] += 2
                curr[i] -= 2
            # explore
            # unchoose
    
    return False

print(backtrack(Counter(stuff), Counter(), False))
