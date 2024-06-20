
a, b, c = map(int, input().split())
d, e, f = map(int, input().split())

m_1 = [a, b, c] if a > b and a > c else None
if not m_1:
    m_1 = [b, a, c] if b > a and b > c else [c, a, b]

import sys

if m_1[0] ** 2 != m_1[1] ** 2 + m_1[2] ** 2:
    print("NO")
    sys.exit()

m_2 = [d, e, f] if d > e and d > f else None
if not m_2:
    m_2 = [e, d, f] if e > d and e > f else [f, d, e]
    
if m_2[0] ** 2 != m_2[1] ** 2 + m_2[2] ** 2:
    print("NO")
    sys.exit()

if sorted(m_1) != sorted(m_2):
    print("NO")
    sys.exit()
print("YES")



