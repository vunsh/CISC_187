# Stacks and Queues

## Task 1

We start with an empty stack S stored in array S[1..6].

Initial state  
top = 0  
S = [ _, _, _, _, _, _ ]

PUSH(S, 4)

top = 1  
S = [ 4, _, _, _, _, _ ]

PUSH(S, 1)

top = 2  
S = [ 4, 1, _, _, _, _ ]

PUSH(S, 3)

top = 3  
S = [ 4, 1, 3, _, _, _ ]

POP(S)

The value 3 is removed.

top = 2  
S = [ 4, 1, _, _, _, _ ]

PUSH(S, 8)

top = 3  
S = [ 4, 1, 8, _, _, _ ]

POP(S)

The value 8 is removed.

top = 2  
S = [ 4, 1, _, _, _, _ ]

Final stack state:  
top = 2  
S = [ 4, 1, _, _, _, _ ]

This shows how a stack works with the last in first out rule. The most recent pushed element is always the first one removed.

---

## Task 2

Now we use a queue Q stored in array Q[1..6].

Initial state  
head = 1  
tail = 1  
Q = [ _, _, _, _, _, _ ]

ENQUEUE(Q, 4)

head = 1  
tail = 2  
Q = [ 4, _, _, _, _, _ ]

ENQUEUE(Q, 1)

head = 1  
tail = 3  
Q = [ 4, 1, _, _, _, _ ]

ENQUEUE(Q, 3)

head = 1  
tail = 4  
Q = [ 4, 1, 3, _, _, _ ]

DEQUEUE(Q)

The value 4 is removed.

head = 2  
tail = 4  
Q = [ _, 1, 3, _, _, _ ]

ENQUEUE(Q, 8)

head = 2  
tail = 5  
Q = [ _, 1, 3, 8, _, _ ]

DEQUEUE(Q)

The value 1 is removed.

head = 3  
tail = 5  
Q = [ _, _, 3, 8, _, _ ]

Final queue state:  
head = 3  
tail = 5  
Q = [ _, _, 3, 8, _, _ ]

This shows the first in first out rule. The first element put into the queue is the first one removed.

---

## Task 3

To make queue operations safer, we can check for over and underflow. Overflow happens when we try to insert into a queue that is already full. Underflow happens when we try to remove an element from an empty queue.

For ENQUEUE:

Before inserting a new element, we check whether the queue is full. If the next position of tail would equal head, the queue is full and we mark as overflow. Otherwise, we can place the new value at Q[tail] and move tail forward.

For DEQUEUE:

Before removing an element, we check whether the queue is empty. If head equals tail, the queue is empty and we mark as underflow. Otherwise, we can remove the value at Q[head], move head forward, and return the removed value.

This will pevent invalid operations and protect the overall structure of the queue.
---

## Task 4

A deque let's us insertion and deletion from both the front and the rear. Using an array and two pointers, we can implement four operations that all run in O(1) time.

InsertFront(D, x)

Start by checking if the deque is full. If it is full, report overflow. If it is empty, set both front and rear to the first position. Otherwise move front one position backward using wraparound and place x at that position.

InsertRear(D, x)

Start by checking if the deque is full. If it is full, report overflow. If it is empty, set front and rear to the first position. Otherwise move rear forward using wraparound and place x there.

DeleteFront(D)

Start by checking if the deque is empty. If it is empty, report underflow. Otherwise remove the element at the front. If that was the only element, reset the deque to empty. Otherwise move front forward.

DeleteRear(D)

Start by checking if the deque is empty. If it is empty, report underflow. Otherwise remove the element at the rear. If it was the only element, reset the deque. Otherwise move rear backward.

Each of these operations runs in constant time because they only update a few pointer values and do not require shifting any elements in the array, just like a vector or array.
