# Stack Using Linked List

## Overview
The program in this folder implements a stack using a single linked list. A stack follows in Last In, First Out stucture, which means the last element added is the first one removed.

## How it works
The stack works using a linked list where each node contains a value and a pointer to the next node. The top pointer in the stack always points to the most recent element. When pushing, a new node is added to the front. When popping, the top node is removed.

## Time Complexity
Both push and pop run in O(1) time because they only update the top pointer.

## Reflection Questions

1. A linked list is efficient for implementing a stack because it allows dynamically allocating memory. It also means we don't have to shift elements during operations, since all operations happen at the top.
  
2. The time complexity of push and pop is O(1) since both operations only modify the top pointer.
   
3. If memory is not dealloated after pop, it can cause memory leaks. Over time, this can significantly reduce performance and waste system memory.

4. A stack using an array has a fixed size so it can run into overflow issues, but it is simple and fast. A linked list stack allows it to grow dynamically without a fixed limit, but it has to use extra memory to store pointers.
