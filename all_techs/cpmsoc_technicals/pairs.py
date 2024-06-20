import itertools

distances = []
for i in range(10):
    distances.append(int(input()))

distances.sort()

def do():
    for combination in set(itertools.combinations(distances, 4)):
        # print(combination)
        proposed = [0, combination[0], combination[1], combination[2], combination[3]]
        temp = distances[:]

        # try from here
        try:
            # print('here', temp)
            temp.remove(combination[0])
            temp.remove(combination[1])
            temp.remove(combination[2])
            temp.remove(combination[3])

            temp.remove(combination[3] - combination[0])
            temp.remove(combination[2] - combination[0])
            temp.remove(combination[1] - combination[0])

            temp.remove(combination[3] - combination[1])
            temp.remove(combination[2] - combination[1])

            temp.remove(combination[3] - combination[2])

            for p in proposed:
                print(p)
            return
        except:
            continue
    print(-1)

do()