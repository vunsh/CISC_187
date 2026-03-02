# Activity 4b Adaptive sorting

---

## Part A - Adaptive Sorting Selection

### Case Detection

Let N = 50. Consider adjacent pairs (A[i], A[i+1]) for i = 0 to 48, giving 49 total pairs.

Pairs counted:

- ascendingPairs = number of times A[i] <= A[i+1]
- descendingPairs = number of times A[i] >= A[i+1]

Ratios:

- ascendingRatio = ascendingPairs / 49
- descendingRatio = descendingPairs / 49

Thresholds used:

- Best case: ascendingRatio >= 0.90
- Worst case: descendingRatio >= 0.90
- Average case: otherwise

This method determines how ordered the array is using only one pass.

### Deciding Which Sorting Method

If the detected case is Best, the program selects insertion sort.

Otherwise, the program selects selection sort.

Insertion sort performs better when the array is already sorted or nearly sorted.
Selection sort performs the same number of comparisons regardless of order.

---

## Part B - Case Classification Without Sorting

The program classifies the array using the same threshold before sorting.

If descendingRatio >= 0.90, it is Worst Case.
Otherwise, it is Average Case.

Classification happens before sorting.

---

## Part C - Documentation

### Why This Threshold is Reasonable

Counting adjacent pairs provides a clear measure of how ordered the array is.

If most adjacent pairs are ascending, the array is already sorted or nearly sorted.
If most adjacent pairs are descending, the array is nearly reverse sorted.
Anything in between behaves like average input.

Using 90 percent allows a few elements to be out of place while still recognizing strongly ordered input.

### How Input Order Affects the Algorithms

Selection sort always performs about N^2 comparisons regardless of input order.

Insertion sort depends heavily on input order.
If the array is already sorted, insertion sort runs in O(N).
If the array is reverse sorted, insertion sort runs in O(N^2).
Random input also results in O(N^2) on average.

---

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

enum CaseType { Best, Average, Worst };

CaseType classify(const vector<int>& a, double threshold) {
    int asc = 0;
    int desc = 0;
    int pairs = a.size() - 1;

    for (int i = 0; i < pairs; i++) {
        if (a[i] <= a[i + 1]) asc++;
        if (a[i] >= a[i + 1]) desc++;
    }

    double ascRatio = (double)asc / pairs;
    double descRatio = (double)desc / pairs;

    if (ascRatio >= threshold) return Best;
    if (descRatio >= threshold) return Worst;
    return Average;
}

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        int temp = a[i];
        a[i] = a[minIdx];
        a[minIdx] = temp;
    }
}

void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    const int N = 50;
    const double threshold = 0.90;

    vector<int> a(N);

    cout << "Enter 50 integers:\n";
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    CaseType result = classify(a, threshold);

    if (result == Best) {
        cout << "Detected: Best Case\n";
        cout << "Using Insertion Sort\n";
        insertionSort(a);
    } else {
        if (result == Worst)
            cout << "Detected: Worst Case\n";
        else
            cout << "Detected: Average Case\n";

        cout << "Using Selection Sort\n";
        selectionSort(a);
    }

    cout << "Sorted Array:\n";
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }

    cout << "\n";
    return 0;
}
```
