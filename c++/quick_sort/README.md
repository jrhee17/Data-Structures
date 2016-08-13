Quick Sort

Features
--------------------
1. Invariant
    1) If p <= k <= i, then A[k] <= x
    2) If i + 1 <= k <= j - 1, then A[k] > x
    3) If k = r, then A[k] = x
2. Quicksort analysis
    Worst-case: O(n^2)
        T(n) = T(n - 1) + T(0) + \theta(n)
             = T(n - 1) + \theta(n)
    Best case: O(nlogn)
        T(n) = 2T(n/2) + \theta(n)
        Constant split a:b: O(nlog_{(a+b)/a}n) where a > b
    

Pseudocode
--------------------
Quicksort(A, p, r)
    if(p < r)
        q = Partition(A, p, r)
        Quicksort(A, p, q - 1)
        Quicksort(A, q + 1, r)

Partition(A, p, r)
    x = A[r]
    i = p - 1
    for j = p to r - 1
        if A[j] <= x
            i = i + 1
            exchange A[i] with A[j]
    exchange A[i + 1] with A[r]
    return i + 1

Randomized-Partition(A, p, r)
    i = Random(p, r)
    exchange A[r] with A[i]
    return Partition(A, p, r)

Randomized-Quicksort(A, p, r)
    q = Randomized-Partition(A, p, r)
    Randomized-Quicksort(A, p, q-1)
    Randomized-Quicksort(A, q+1, r)
