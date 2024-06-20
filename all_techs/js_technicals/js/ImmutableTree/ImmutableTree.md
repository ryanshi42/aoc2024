# Part 1:

Create a constructor for an immutable N-ary tree class `Node` - the class has attributes `String data` and `Node[] children`, but you can add more if needed.

You also want to implement a `hash()` function to _efficiently_ return the hash of the node. The hash of a node is given by the below formula, where `sha256` is a provided String -> String hashing function:
```
hash(node) = sha256(hash(child_0) + hash(child_1) + ... + hash(child_n) + sha256(data))
```

# Part 2:

You left a file containing the data structure open on your laptop and suspect someone else walked in and edited some part. The implication of this is, when you load the data structure back into the program there may be inconsistencies.

Implement a method `Node verify()` to find which node (if any) was modified. This should return the Node that was modified or NULL if none.

You can assume that only a single bit in either the data or the hash of some Node has been modified. The number of children, or the pointers to children have not been modified.

# Part 3:

You have a tree on a client and server. The tree may be differences between the two. The goal is to find what nodes are missing from the server (there may be nodes missing from the client - ignore these). Implement a method `Set<Node> missingFromServer()` that returns all missing nodes.

They give you a function `boolean[] isNodeInServer(String[] hashes)` which is thought of as making a call to the server and asking it whether a hash is present in the server's tree. You can query at most 200 nodes in one call. **Important:** you want to minimise calls to the server.

Example:
```
   Client            Server
     Q                 A
    / \               / \
   A   R             B   C  
  / \   \
 B   C   S
 
Missing from server: Q, R, S
```
