
def isMatch(string, pattern):
    # Idea: Go through the pattern and check if the str matches the next pattern
    # Assume no cases like (ab){5}

    pattern = pattern.replace(',}', ',9}')

    # Edge Cases
    if not string and not pattern:
        return True
    elif not string or not pattern:
        return False

    str_idx = 0
    pat_idx = 0
    while pat_idx < len(pattern):

        # This means that the str has been exhausted
        if str_idx >= len(string):
            return False

        # Check if the next thing is a quantifier
        quantifier_min = 0
        quantifier_max = 0
        next_idx = pat_idx
        if pat_idx + 1 < len(pattern) and pattern[pat_idx + 1] == '{':
            # next_idx = pat_idx + 1
            # while pattern[next_idx] != '}':
            #     next_idx += 1
            
            # # now pattern next_idx = '}'
            # # pat_idx = 'a'
            # # pat_idx + 1 = '{'
            # # pat_idx + 2 = '1'
            # # next_idx = '}'
            # quantifier = int(pattern[pat_idx+2:next_idx])
            while next_idx < len(pattern):
                if pattern[next_idx] != pattern[pat_idx] or not (next_idx + 1 < len(pattern) and pattern[next_idx + 1] == '{'):
                    break
                if pattern[next_idx + 3] == '}':
                    quantifier_min += int(pattern[next_idx + 2])
                    quantifier_max += int(pattern[next_idx + 2])
                    next_idx = next_idx + 4
                else:
                    # There is a comma
                    quantifier_min += int(pattern[next_idx + 2])
                    quantifier_max += int(pattern[next_idx + 4])
                    # next_idx + 5 will be the '}'
                    next_idx = next_idx + 6

        # print(quantifier_max, quantifier_min)
        if quantifier_min == 0:
            if string[str_idx] != pattern[pat_idx]:
                return False
            str_idx += 1
            pat_idx += 1
        else:
            # check for all quantifiers between 1 to 9 whether there's a match
            # This is inclusive
            has_valid_quantifier = False
            for quantifier in range(quantifier_max, quantifier_min - 1, -1):
                if str_idx + quantifier <= len(string) and string[str_idx:str_idx + quantifier] == pattern[pat_idx] * quantifier:
                    str_idx += quantifier
                    pat_idx = next_idx
                    has_valid_quantifier = True
                    break
            if not has_valid_quantifier:
                return False

    # isMatchRecursive(string, pattern, str_idx, pat_idx):
        # does string[str_idx:] and pattern[pat_idx:] match:
        # isMatch(string, pattern) = isMatchRecursive(string, pattern, 0, 0)

    # "aaaaaaaaaaaa" "a"
    if str_idx == len(string) and pat_idx == len(pattern):
        return True
    else:
        return False


"""
We now want to extend the parsing capabilities to handle the situation when the max repetition quantifier is not specified like in the following example:

# a{1,} = a{1,9}
# pattern.replace(',}', ',9}')
isMatch("aa","a{1,}") → true
isMatch("aabb","a{3,}b{1,}") → false
isMatch("aaabbb","a{1,}b{3,}") → true
isMatch("aaabbbc","a{1,}b{3,}") → false

"""

def test_pattern_match3(f):
    print('isMatch tests Part 3')
    test_cases_true = [
        ('aa', 'a{1,}'),
        ('aaabbb', 'a{1,}b{3,}')
    ]
    for str1, str2 in test_cases_true:
        assert f(str1, str2), f'isMatch({str1}, {str2}) returned false, expected true'

    test_cases_false = [
        ("aabb", "a{3,}b{1,}"),
        ("aaabbbc", "a{1,}b{3,}")
    ]
    for str1, str2 in test_cases_false:
        assert not f(str1, str2), f'isMatch({str1}, {str2}) returned true, expected false'
    
"""
We now want to extend the parsing capabilities to handle ambigous cases in a greedy way (i.e. matching the longest possible string)

isMatch("aaaaaa","a{1,3}a{1,3}") → true
isMatch("aaaaaa","a{1,4}a{1,3}") → true
isMatch("aaaaaa","a{1,2}a{1,3}") → false
"""

# a{1,3}a{1,3} = a{2,6}
# a{1,3}a{1,} = a{2,12}

def test_pattern_match4(f):
    print('isMatch tests Part 4')
    test_cases_true = [
        ('aaaaaa', 'a{1,3}a{1,3}'),
        ('aaaaaa', 'a{1,4}a{1,3}')
    ]
    for str1, str2 in test_cases_true:
        assert f(str1, str2), f'isMatch({str1}, {str2}) returned false, expected true'

    test_cases_false = [
        ("aaaaaa", "a{1,2}a{1,3}")
    ]
    for str1, str2 in test_cases_false:
        assert not f(str1, str2), f'isMatch({str1}, {str2}) returned true, expected false'

# Test cases
if __name__ == '__main__':
    #print(f'1 Expected: False, your code: {isMatch("aa","a")}')
    #print(f'2 Expected: True, your code: {isMatch("aa","aa")}')
    #print(f'3 Expected: False, your code: {isMatch("aaa","aa")}')
    #print(f'4 Expected: False, your code: {isMatch("a", "a{5}")}')
#
    #print(f'5 Expected: True, your code: {isMatch("aa","a{2}")}')
    #print(f'6 Expected: True, your code: {isMatch("aa","a{1,3}")}')
    #print(f'7 Expected: True, your code: {isMatch("aaa","a{1,3}")}')
#
    #print(f'8 Expected: True, your code: {isMatch("ab","a{1,3}b{1,3}")}')
    #print(f'9 Expected: False, your code: {isMatch("ab","a{1,3}b{2,3}")}')
#
    #print(f'10 Expected: True, your code: {isMatch("abc","a{1,3}b{1,3}c")}')
    #print(f'11 Expected: True, your code: {isMatch("abbc","a{1,3}b{1,2}c")}')
    #print(f'12 Expected: False, your code: {isMatch("abbbc","a{1,3}b{1,2}c")}')
#
    #print(f'13 Expected: False, your code: {isMatch("abca","a{1,3}b{1,3}c")}')
    #print(f'14 Expected: False, your code: {isMatch("acbac","a{1,3}b{1,3}c")}')
    #print(f'15 Expected: False, your code: {isMatch("abccccc","a{1,3}b{1,3}cc{1,3}")}')

    # # a{1,3}aa{1,3} = a{3,7}

    #test_pattern_match3(isMatch)
    #jprint('done part3')
    test_pattern_match4(isMatch)
    print('done part4')
    