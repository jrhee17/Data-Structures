Insertion sort

Features
------------------------------------
1. Sorts values in-place
2. Best case time complexity O(n), Worst case time complexity O(n^2)
3. Space complexity O(n)

Pseudocode
------------------------------------
for j = 2 to A.length
    key = A[j]
    i = j - 1
    while i > 0 and A[i] > key
        A[i+1] = A[i]
        i = i - 1
    A[i + 1] = key
