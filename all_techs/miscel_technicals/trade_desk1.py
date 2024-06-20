

# Part 1
def abbreviate(word):
    n = len(word)
    if n <= 2:
        return word
    
    return word[0] + str(n - 2) + word[-1]

# Part 2
def abbreviate_sentence(sentence):
    if not sentence:
        return None
    result = [abbreviate(word) for word in sentence.split(" ")] 
    return " ".join(result)

# Part 3
def unique_abbreviate(word, seen, mapping):
    """
        word
        seen = a set of already taken encodings
        mapping = if we've mapped better -> be3r before and we see another better, just return be3r
    """
    if word in mapping:
        return mapping[word]
    
    n = len(word)
    if n <= 2:
        return word 

    # better -> b4r
    new_word = abbreviate(word)
    temp = word
    i = 1
    
    # # O(N)
    # while new_word in mapping.values():
    # # O(1)
    # while new_word in seen:
    
    while new_word in seen and len(temp) > 2:
        # b
        # temp = etter
        temp = word[i:]
        # new_word = be3r, word[0:i] = b, temp = etter, abbreviate(temp) = e3r
        new_word = word[0:i] + abbreviate(temp)
        i += 1

    seen.add(new_word)
    mapping[word] = new_word
    return new_word
    
    
def unique_abbreviate_sentence(sentence):
    seen = set()
    mapping = {}
    if not sentence:
        return None
    result = [unique_abbreviate(word, seen, mapping) for word in sentence.split(" ")] 
    return " ".join(result)
    
# Part 3
    
def test_level_1():
    print(abbreviate('Internationalization'))
    print(abbreviate('Kubernetes'))
    print(abbreviate('cat'))
    print(abbreviate('c'))
 
def test_level_2():
    print(abbreviate_sentence("Internationalization is really really cool"))
    print(abbreviate_sentence("I like sunny weather"))
    print(abbreviate_sentence(""))
    
def test_level_3():
    print(unique_abbreviate_sentence("butter is better than batter or is batter better than butter"))
    print(unique_abbreviate_sentence("tan tin ton"))
    print(unique_abbreviate_sentence(""))
    print(unique_abbreviate_sentence("Kubernetes Kubernetes Kubernetes"))

test_level_1()
test_level_2()
test_level_3()
