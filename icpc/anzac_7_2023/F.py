n = int(input())

def replacements(s):
    d = {'B':'8','G':'C','I':'1','O':'0','Q':'0','S':'5','U':'V','Y':'V','Z':'2'}
    for key,val in d.items():
        s = s.replace(key,val)
    return s

def digits(s):
    digits='0123456789ACDEFHJKLMNPRTVWX'
    number =list(map(lambda c : digits.index(c),s))
    return number

def f(s):
    s = replacements(s)
    d = digits(s)
    
    checksum = 2*d[0]+4*d[1]+5*d[2]+7*d[3]+8*d[4]+10*d[5]+11*d[6]+13*d[7]
    checksum = checksum%27

    #print(s,d,checksum)

    if checksum!=d[-1]:
        return "Invalid"
    
    total = 0
    b = 1
    for digit in reversed(d[:-1]):
        total += b*digit
        b*=27

    return str(total)

for _ in range(n):
    k,s=input().split()
    print(k,f(s))