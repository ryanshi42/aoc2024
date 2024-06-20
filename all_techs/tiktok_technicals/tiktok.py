# encoding: utf-8
# a = input("please input a number:")
print("hello world")

class Node():
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def assign_left(self, left):
        self.left = left
    
    def assign_right(self, right):
        self.right = right

def bfs_print_leaves(root):
    if not root:
        return

    # the root is valid
    queue = []
    queue.append((root, [root.val]))
    while queue:
        new_level = []
        for (node, curr_path) in queue:
            if node.left:
                new_level.append((node.left, curr_path + [node.left.val]))
            if node.right:
                new_level.append((node.right, curr_path + [node.right.val]))
            if not node.left and not node.right:
                # this is a leaf
                print("->".join([str(x) for x in curr_path]))

        queue = new_level

# path = []

def dfs_print_leaves(root, path):
    # if not root:
    #     return
    # if not root.left and not root.right:
    #     print(path)
    #     path.pop()

    # if root.left:
    #     dfs_print_leaves(root.left, path + [root.left.val])
    # if root.right:
    #     dfs_print_leaves(root.right, path + [root.right.val])
    # path.pop()
    # return

    # the root is valid
    stack = []
    seen_left = set()
    seen_right = set()
    seen_left.add(None)
    seen_right.add(None)

    stack.append(root)
    while stack:
        # print(stack)
        # print([node.val for node in stack if node])
        # print([node.val for node in seen_left if node])
        # print([node.val for node in seen_right if node])
        # print([node in seen_left and node in seen_right for node in stack if node])

        if not stack[-1]:
            _ = stack.pop()
            continue

        if stack[-1] in seen_left and stack[-1] in seen_right:
            if stack[-1] and not stack[-1].left and not stack[-1].right:
                print([node.val for node in stack if node])
            stack.pop()
        elif stack[-1] not in seen_left:
            seen_left.add(stack[-1])
            stack.append(stack[-1].left)
        elif stack[-1] not in seen_right:
            seen_right.add(stack[-1])
            stack.append(stack[-1].right)
            # print(b)

            # stack.pop()
            # print([node.val for node in stack])

            # break

            # print(stack)

    # while True:
    #     if curr:
    #         stack.append(curr)
    #         curr = curr.left
    #     elif stack:
    #         curr = stack.pop()
    #         if not curr.right:
    #             print([s.val for s in stack + [curr]])
    #         curr = curr.right
    #     else:
    #         break


# def iterative_dfs_traversal(tree):
#   stack = []
#   stack.append(tree)
#   path = []

#   while stack:
#     node = stack.pop()
#     path.append(node.val)
#     if not node.right and not node.left:
#       print(' -> '.join([str(v) for v in path]))
#     if node.right:
#       stack.append(node.right)
#     if node.left:
#       stack.append(node.left)


print("Begin Testing")

node_1 = Node(1)
node_1.left = Node(22)
node_1.right = Node(333)
node_1.left.left = Node(4)
node_1.left.right = Node(5)
node_1.right.right = Node(66)
node_1.right.right.left = Node(7)
# bfs_print_leaves(node_1)
dfs_print_leaves(node_1, [node_1.val])
# iterative_dfs_traversal(node_1)