# encoding: utf-8
# a = input("please input a number:")

def fraction_string(numerator, denominator):
    # Handle edge cases first
    if denominator == 0:
        return ""
    elif numerator == 0:
        return "0"

    # Handle cases where the % could break because of negatives
    sign = ""
    if denominator * numerator < 0:
        sign = "-"
    denominator = abs(denominator)
    numerator = abs(numerator)

    division = numerator // denominator
    remainder = numerator % denominator

    # example: remainder = 4

    result = sign + str(division)
    if remainder == 0:
        return result
    
    # Now, a decimal remainder exists
    result += "."

    # Tracks the last seen element
    seen = {}
    # seen[remainder] = len(result)

    # Iteratively calculate the remainder
    while remainder != 0 and remainder not in seen:
        # if seen remainder, return
        seen[remainder] = len(result)
        remainder *= 10
        result += str(remainder // denominator)
        print(remainder // denominator)
        print(remainder)
        remainder %= denominator

    # print(result)
    if remainder != 0:
        # repeating
        return result[:seen[remainder]] + "(" + result[seen[remainder]:] + ")"
    else:
        return result

print("Begin Test 1")

print(fraction_string(1, 2))
    
print("End Test 1")

print("Begin Test 2")

print(fraction_string(2, 1))
    
print("End Test 2")

print("Begin Test 3")

print(fraction_string(4, 333))
    
print("End Test 3")

print("Begin Test 4")

print(fraction_string(2, 17))
    
print("End Test 4")