## Tasks

### 1. Explain how to create an array of 100 elements. You can choose any data type of your choice. (requires C++ code) - **1 pts**


To make an array, you first specify the data type, then the name of the array, and then the size of the array in square brackets.
```cpp
#include <iostream>

int main() {
    int arr[100];
    return 0;
}
```

### 2. What will be the size of each element of an array. (requires C++ code) - **1 pts**

The elements of an array each have the size of their data type. If I made an array of integers, each element would be the size of an integer, or 4 bytes. You can use the sizeof() function to find the size of an element.
```cpp
#include <iostream>

int main() {
    int arr[100];
    std::cout << sizeof(arr[0]) << std::endl; // Would be 4 bytes on my laptop
    return 0;
}
``` 

### 3. For an array containing 100 elements, provide the number of steps the following operations would take: (theoretical) - **6 pts**
- Reading
- Searching for a value not contained within the array
- Insertion at the beginning of the array
- Insertion at the end of the array
- Deletion at the beginning of the array
- Deletion at the end of the array

a) Reading would take one step, as using arr[i] access the element via it's index directly.

b) Searching for a value not within the array would take 100 steps, as you would have to check every element in the array to conclude it's not there, and there are 100 elements.

c) Inserting an element at the beginning of the array would take 100 steps, because you would have to shift all the existing elements one position to the right.

d) Inserting an element at the end of the array would take one step, since you just have to add it onto the next open slot.

e) Deleting an element at the beginning would take 100 steps, since you would have to shift every element one position to the left.

f) Deleting an element at the end of the array would take one step, since you just have to remove the last element.

### 4. Normally the search operation in an array looks for the first instance of a given value. But sometimes we may want to look for every instance of a given value. For example, say we want to count how many times the value “apple” is found inside an array. How many steps would it take to find all the “apples”? Give your answer in terms of N. (theoretical) - **1 pts**

To find every instance of a value in an array, you would have to check every single element in the array, so it would take N steps.

### 5. Research how to find the memory address of an array. You can use any programming language of your choice. (requires code) **1 pts**

I can use the & operator to find the memory address of an array. Finding the memory address of the first element in an array is the same as finding the memory address of the array itself.

```cpp
#include <iostream>

int main() {
    int arr[100];
    std::cout << &arr[0] << std::endl; // This would print the memory address of the array
    return 0;
}
```






