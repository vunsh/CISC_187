# Activity 12 - Recursions


## Question 1

### Prompt

The following function prints every other number from a low number to a high number.

```ruby
def print_every_other(low, high) 
    return if low > high
    puts low
    print_every_other(low + 2, high)
end
```

Identify the base case in the function.

### Answer

The base case is:

```ruby
return if low > high
```

### Explanation

A base case is just the condition that stops the recursive function from continuing forever. In this function, the value of low increases by 2 during each recursive call:

```ruby
print_every_other(low + 2, high)
```

Eventually, low becomes greater than `high`. When that happens, this line runs:

```ruby
return if low > high
```

This stops the function and prevents infinite recursion, therefore it is the base case.

---

## Question 2

### Prompt

The factorial function was changed so that it computes factorial based on `n - 2` instead of `n - 1`.

```ruby
def factorial(n)
    return 1 if n == 1
    return n * factorial(n - 2)
end
```

Predict what will happen when we run `factorial(10)`.

### Answer

Running `factorial(10)` will cause infinite recursion and eventually a stack overflow error.

### Explanation

The function only stops when n = 1.

However, since the function subtracts 2 each time, starting with 10 eans the function will go through even numbers only:

```text
factorial(10)
10 * factorial(8)
10 * 8 * factorial(6)
10 * 8 * 6 * factorial(4)
10 * 8 * 6 * 4 * factorial(2)
10 * 8 * 6 * 4 * 2 * factorial(0)
10 * 8 * 6 * 4 * 2 * 0 * factorial(-2)
...
```

The function never reaches n = 1, so the base case is never triggered.

Because of this, the function keeps calling itself forever until the program runs out of stack memory.

---

## Question 3

### Prompt

The following function returns the sum of all numbers from `low` to `high`, but it is missing the base case.

```ruby
def sum(low, high)
    return high + sum(low, high - 1)
end
```

Fix the code by adding the correct base case.

### Answer

```ruby
def sum(low, high)
    return low if high == low
    return high + sum(low, high - 1)
end
```

### Explanation

The base case is:

```ruby
return low if high == low
```

The function keeps subtracting 1 from high during each recursive call.

For example:

```text
sum(1, 10)
10 + sum(1, 9)
10 + 9 + sum(1, 8)
10 + 9 + 8 + sum(1, 7)
...
```

Eventually, hjigh becomes equal to low.

At that point, the function returns low instead of calling itself again. This stops the recursion.

For example:

```text
sum(1, 10) = 55
```

---

## Question 4

### Prompt

Here is an array containing both numbers and other arrays, which also contain numbers and arrays.

Write a recursive function that prints all the numbers and just the numbers.

### Answer

```cpp
#include <iostream>
#include <vector>
#include <variant>

using namespace std;

struct NestedArray;

using Element = variant<int, NestedArray>;

struct NestedArray {
    vector<Element> elements;
};

void printNumbers(const NestedArray& array) {
    for (const Element& element : array.elements) {
        if (holds_alternative<int>(element)) {
            cout << get<int>(element) << endl;
        } else {
            printNumbers(get<NestedArray>(element));
        }
    }
}

int main() {
    NestedArray array = {{
        1,
        2,
        3,
        NestedArray{{4, 5, 6}},
        7,
        NestedArray{{
            8,
            NestedArray{{
                9, 10, 11,
                NestedArray{{12, 13, 14}}
            }}
        }},
        NestedArray{{
            15, 16, 17, 18, 19,
            NestedArray{{
                20, 21, 22,
                NestedArray{{
                    23, 24, 25,
                    NestedArray{{26, 27, 29}}
                }},
                30, 31
            }},
            32
        }},
        33
    }};

    printNumbers(array);

    return 0;
}
```

### Explanation

This program uses recursion to go through a nested array structure.

The function printsNumbers checks every element in the array.

If the element is an integer, it prints the number:

```cpp
cout << get<int>(element) << endl;
```

If the element is another nested array, the function calls itself again:

```cpp
printNumbers(get<NestedArray>(element));
```

This continues until all nested arrays have been searched and all numbers have been printed.

### Expected Output

```text
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
29
30
31
32
33
```
