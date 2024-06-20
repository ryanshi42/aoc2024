
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# 1 -> 2 -> 3
# 2 -> 2 -> 5

# 5 -> 3 -> 2 -> 2 -> 2 -> 1

l11 = Node(1)
l12 = Node(2)
l11.next = l12
l13 = Node(3)
l12.next = l13

l21 = Node(2)
l22 = Node(2)
l21.next = l22
l23 = Node(5)
l22.next = l23

def reverse(l):
    if not l:
        return None
    if not l.next:
        return l

    prev = None
    curr = l
    while curr:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next

    return prev 

def merge_and_reverse(l1, l2):
    if not l2:
        return reverse(l1)
    if not l1:
        return reverse(l2)
    
    head = l1
    if l1.data >= l2.data:
        head = l2
        l2 = l2.next
    else:
        l1 = l1.next

    curr = head

    # while we still have nodes to explore
    while l1 or l2:
        # compare the two heads of the linked list. If one is empty, then take the other
        if not l1:
            curr.next = l2
            break
            # l2 = l2.next
        elif not l2:
            curr.next = l1
            break
            # l1 = l1.next
        else:
            if l1.data >= l2.data:
                curr.next = l2
                l2 = l2.next
            else:
                curr.next = l1
                l1 = l1.next
        curr = curr.next

    return reverse(head)

result = merge_and_reverse(l11, l21)

while result:
    print(result.data)
    result = result.next