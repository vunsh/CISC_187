## Tasks

### 1. Proof that, under the average-case scenario, the insertion sort has a time complexity of $O(N^2)$. Draw a clear figure and show all the operations clearly.  **2 pts**
An insertion sort has to go through each element of the array and check the previous element. This means that in every scenario, each run of the outer loop can cause a run of the inner loop up to "i" times. This causes a time complexity of O(N^2). In the average case, this inner loop will have to be called, which means it's time complexity will be O(N^2).


<img width="741" height="711" alt="image" src="https://github.com/user-attachments/assets/b8f87d45-0cc1-4eff-a6a9-239670508b02" />



### 2. Insertion sort normally begins with i = 1 (0-based indexing).
Let N = 5 and assume the array is in descending order (worst case).

Count operations where:

a comparison is A[j] > key

a shift is A[j+1] = A[j]

**a) Start the algorithm at i = 1. Verify the total operations = 20.**  

Array (descending): [5, 4, 3, 2, 1]

Worst case -> each element shifts through entire sorted portion.

i = 1 -> 1 comparison, 1 shift  
i = 2 -> 2 comparisons, 2 shifts  
i = 3 -> 3 comparisons, 3 shifts  
i = 4 -> 4 comparisons, 4 shifts  

Total comparisons = 1 + 2 + 3 + 4 = 10  
Total shifts = 1 + 2 + 3 + 4 = 10  

Total operations = 10 + 10 = 20

**b) Start the algorithm at i = 2, then i = 3. Count operations again.** 
i = 2 -> 2 comparisons, 2 shifts  
i = 3 -> 3 comparisons, 3 shifts  
i = 4 -> 4 comparisons, 4 shifts  

Total comparisons = 2 + 3 + 4 = 9  
Total shifts = 2 + 3 + 4 = 9  

Total operations = 18

**Start at i = 3**

i = 3 → 3 comparisons, 3 shifts  
i = 4 → 4 comparisons, 4 shifts  

Total comparisons = 3 + 4 = 7  
Total shifts = 3 + 4 = 7  

Total operations = 14

**c) For (b), does the algorithm still sort the entire array? Explain.**     
Total: **4 pts**

No, the whole array isn't sorted. Insertion sort assumes that the subarray from index 0 to i−1 is already sorted before each iteration.If the algorithm starts at i = 2 or i = 3, the earlier elements are never guaranteed to be sorted. Because of this, the algorithm does not build up a prefix of sorted elements. If starting at a later index means the first elements are unsorted, the whole array isn't being sorted.


3. The following function returns whether or not a capital “X” is present within a string.  **4 pt**

```
function containsX(string) {
	foundX = false;
	for(let i = 0; i < string.length; i++) { 
		if (string[i] === "X") {
			foundX = true; 
		}
	}
	return foundX; 
}
```

**(a) What is this function’s time complexity regarding Big O Notation?**
The function loops through the entire string from index 0 to string.length - 1. In the worst case, the character X is not there, so the loop runs N times. Therefore, the time complexity is just: O(N)

**(b) Then, modify the code to improve the algorithm’s efficiency for best- and average-case scenarios.**

The original function continues looping even after finding the character X.
We can improve efficiency by returning right after finding X.

Improved code:
```
function containsX(string) {
    for (let i = 0; i < string.length; i++) {
        if (string[i] === "X") {
            return true;
        }
    }
    return false;
}
```
Best case: O(1)  
If X is the first character, the function returns immediately.

Average case: O(N/2), or O(N)  
On average, the loop stops halfway through.

Worst case: O(N)  
If "X" is not present, the loop still checks all characters


video: https://youtu.be/zghQLmXyTZg

This improves efficiency in the best case scenarios at least, while the average and worst remain closer to O(N).
