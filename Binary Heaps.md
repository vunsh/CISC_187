# Activity - Binary Heaps

## Task 1

We are inserting the value 11 into the given heap.

In a heap, insertion happens at the next available position, and then we bubble up to maintain the property.

After inserting 11, it is placed at the next spot at the bottom level. Then we compare it with its parent and swap if needed until the heap property is satisfied.

Final heap (diagram):

        55
       /  \
     22    34
    / \    /
  10   2  99
  /
11

(If it's a max heap, 11 does not move up much since it's smaller than its parent.)


## Task 2

Deleting the root node:

Steps:
1. Replace the root with the last element in the heap
2. Remove the last element
3. Bubble down the new root to maintain heap property

After removing the root (55), we move 11 to the root and then compare with its children.

Final heap after reheapifying:

        34
       /  \
     22    11
    / \    /
  10   2  99

(Values may shift depending on swaps, but the idea is restoring heap order.)


## Task 3

We insert the following numbers into a heap in this order:

55, 22, 34, 10, 2, 99, 68

After inserting all values into a max heap, we repeatedly remove the root (largest value) and store it in a new array.

This is essentially heap sort.

Step-by-step removals:
- Remove 99
- Remove 68
- Remove 55
- Remove 34
- Remove 22
- Remove 10
- Remove 2

Final array after popping all elements:

[99, 68, 55, 34, 22, 10, 2]


## Explanation

A binary heap is a complete binary tree that satisfies the heap property.

- In a max heap, parent nodes are always greater than their children.
- Insertion uses bubble up
- Deletion uses bubble down

This structure is efficient because both operations run in O(log n) time.

The third task shows how heaps can be used for sorting, where the largest element is always removed first.
