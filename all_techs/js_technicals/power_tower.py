# 2^2 = 2^2, (-2)^2, 4^1

# 3^3 = 3^3, 27^1

# 4^4 = 2^8, (-2)^8, 16^2, (-16)^2, 256^1, 4^4, (-4)^4

# 5^5 = 5^5, 3125^1

# 6^6 = 6^6, 36^3, 46656^1, 216^2, (-216)^2, (-6)^6

# 7^7 = (2)

# (2^4 3^2)^72 = (2^2 3)^144 = 


from collections import defaultdict
def primeFactors(n):

    blah = n
    map = defaultdict(lambda : 0) 
    while (n % 2 == 0):
        # print(n)
        map[2] += 1
        n = n // 2


    import math
    for i in range(3, math.floor(math.sqrt(n)) + 1): 
        # print(i)
        while (n % i == 0):

            map[i] += 1
            n = n//i
 
    if (n > 2):
        map[n] += 1


    product = 1

    for v in map.values():
        product *= v
 
    bob = product
    # print(map.items())
    # print("map finished")


    for v in map.values():
        bob = math.gcd(bob, v)

    # print("bob is", bob)

    n = blah
    x = n
    y = n
    if bob != 1:
        y *= bob
        x = math.pow(x, 1/bob)

    res = 0
    # print("y is", y)
    factors = set()
    for i in range(1, math.ceil(math.sqrt(y)) + 1, 1):
        if (y % i == 0 and i <= math.sqrt(y)):
            print(i)
            factors.add(i)
            if (y == i * i):
                if (i % 2 == 0):
                    res += 2
                else: 
                    res += 1
                
                
            else:
                ff = i
                sf = int(y // i)
                
                factors.add(sf)
                factors.add(ff)

                if (ff % 2 == 0):
                    res += 2
                else:
                    res += 1
                

                if (sf % 2 == 0):
                    res += 2
                else:
                    res += 1

    print(len(factors), factors)
    return res

 


# y = pow(3, 16)

# z = pow(2, 4) * pow(3, 12) * pow(5, 0)
z = pow(2, 2) * pow(3, 16) * pow(5, 16)
result = primeFactors(z)
print("res is ", z, result)

# for z in range(2, 17):
#     result = primeFactors(z)
#     print("res is ", z, result)

# for (long long int n = 2 n <= 10000000 n++) {
#     long long int x = pow(n, 2)
#     result = primeFactors(x)
#     // cout << x << " " << result << endl
#     if (result % (17 * 17) == 0) {
#         // break
#         cout << x << " " << result << endl
#     }
# }


# rule is that a^b * c^d * e^f, all coprime => (gcd(b, d, f) + 1)(b + 1)(d + 1)(f + 1)
# 2^2 * 3^(16) * 5^(16)
# 
# 2^(16) * 3^(5) * 3^()

# 2^8 * 3^16 * 