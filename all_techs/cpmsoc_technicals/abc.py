curr = set('I')

while True:
    old = curr

    for elem in curr:
        if elem == 'I':
            curr.add('A')
            curr.add('B')
            curr.add('C')
        else:
            if elem[-1] != 'A' and elem[-1] != 'C' and elem[-1] != 'C':
                curr.add(elem + 'A')
            if elem[-1] != 'B':
                curr.add(elem + 'B')
            if elem[-1] != 'C':
                curr.add(elem + 'C')

    if curr == old:
        break    