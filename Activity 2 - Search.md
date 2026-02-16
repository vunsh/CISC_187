## Tasks

### 1. How many steps would it take to perform a linear search for the number 8 in the ordered array, [2, 4, 6, 8, 10, 12, 13]? - **1 pt**

In C++, a linear search would take 4 steps to find the number 8 in the array. This is because it would start at the first element and check each element in order until it found the number 8, which is the 4th element in the array.

### 2. How many steps would binary search take for the previous example? - **1 pt**

A Binary search would take one step to find the number 8, as it first checks the middle element. Since the middle element of this array is 8, it would find the number 8 in one step.

### 3. What is the maximum number of steps it would take to perform a binary search on an array of size 100,000? - **1 pt**

A binary search halves the array each time, so it would can take a maximum of log_2(100,000) steps. Log_2(100,000) is about 16.6, so it would take a maximum of 17 steps to perform a binary search on an array of size 100,000.

### 4. Write a C++ program that implements both linear search and binary search algorithms using an array of 100,000 elements. The program should record and report the number of steps (comparisons) performed during each search operation. In addition, analyze and justify the observed behavior by providing a theoretical explanation using Big-O notation, demonstrating why linear search exhibits $O(N)$ complexity and binary search exhibits $O(\log N)$ complexity. - **2 pts**


```cpp
#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int key, int &steps) {
    steps = 0;
    for (int i = 0; i < size; i++) {
        steps++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key, int &steps) {
    int left = 0;
    int right = size - 1;
    steps = 0;

    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    const int SIZE = 100000;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }

    int key = 99999; // max value, so it should take the most steps
    int steps;

    linearSearch(arr, SIZE, key, steps);
    cout << "Linear Search Steps: " << steps << endl; // Linear search should take 100,000 steps

    binarySearch(arr, SIZE, key, steps);
    cout << "Binary Search Steps: " << steps << endl; // Binary search should take 17 steps

    return 0;
}
```

Linear search has a time complexity of O(N), because in the worst case scenario the total number of steps is the amount of elements in the array. Since Binary search halves the array each time, it has a time complexity of O(log N).

### 5. Write pseudocode for a randomized search algorithm that searches for a given key by randomly selecting indices __without repetition__. Use a dataset of 100,000 distinct elements, stored in a vector. Each element may be examined __at most__ once during the search. Analyze and state the best-case, average-case, and worst-case time complexities of this algorithm using Big-O notation. Then, implement the algorithm in C++, using only the following standard headers: ```<vector>``` for data storage, ```<random>``` for random index generation, and ```<iostream>``` for input and output. The implementation should track and report the number of comparisons performed during the search. Finally, compare and contrast the randomized search algorithm with linear search and binary search in terms of time complexity, data requirements (such as ordering), and practical efficiency. Discuss scenarios in which each approach may be preferred, highlighting the advantages and limitations of randomized search relative to linear and binary search. - **5 pts**

```
RandomizedSearch(vector V, key):
    Create a boolean array checked[100000] initialized to false
    comparisons = 0

    While there are unchecked indices:
        Pick a random index i
        If checked[i] == false:
            Mark checked[i] = true
            comparisons++

            If V[i] == key:
                Return FOUND and comparisons

    Return NOT_FOUND and comparisons
```

The best case for this algorithm is O(1), as it could theoretically find the target on it's first try. The average case is O(N) where half of the elements are checked before finding the target. The worst case is O(N) where every element is checked before finding the target.

```cpp
#include <vector>
#include <random>
#include <iostream>

using namespace std;

int randomizedSearch(vector<int>& data, int key, int &steps) {
    const int SIZE = data.size();
    vector<bool> checked(SIZE, false);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, SIZE - 1);

    steps = 0;
    int checked = 0;

    while (checked < SIZE) {
        int index = dist(gen);

        if (!checked[index]) {
            checked[index] = true;
            steps++;
            checked++;

            if (data[index] == key) {
                return index;
            }
        }
    }

    return -1;
}

int main() {
    const int SIZE = 100000;
    vector<int> data;

    for (int i = 0; i < SIZE; i++) {
        data.push_back(i);
    }

    int key = 99999;
    int steps;

    randomizedSearch(data, key, steps);

    cout << "Randomized Search Steps: " << steps << endl;

    return 0;
}
```

## Comparison of Linear, Binary, and Randomized Search

| Feature | Linear Search | Binary Search | Randomized Search |
|----------|--------------|--------------|------------------|
| Best Case Time | O(1) | O(1) | O(1) |
| Average Case Time | O(N) | O(log N) | O(N) |
| Worst Case Time | O(N) | O(log N) | O(N) |
| Requires Sorted Data? | No | Yes | No |
| Maximum Comparisons (N = 100,000) | 100,000 | 17 | 100,000 |
| Data Access Pattern | Sequential | Middle Element | Random Index Selection |
| Deterministic? | Yes | Yes | No (random order) |
| Practical Efficiency | Somewhat efficient for small/unsorted data | Very efficient for large sorted data | Generally inefficient compared to others |
| Memory Overhead | Minimal | Minimal | Additional tracking (checked array) |
| When Preferred | Small or unsorted datasets | Large sorted datasets | Rare cases requiring random checking |
