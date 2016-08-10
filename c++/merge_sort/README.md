Merge Sort

Features
-------------------------
1. Best case, worst case, average case time complexity O(n) O(nlogn)
2. Efficient for sorting problems with large inputs

Pseudocode
-------------------------
MergeSort(A, p, r):
    if p < r
        q = floor((p + r) / 2)
        MergeSort(A, p, q)
        MergeSort(A, q, r)
        Merge(A, p, q, r)

Merge(A, p, q, r):
    n1 = q - p + 1
    n2 = r - q
    let L[1 .. n1 + 1] and R[1..n2 + 1] be arrays
    for i = 1 to n1
        L[i] = A[p + i - 1]
    for j = 1 to n2
        R[j] = A[q + j]
    L[n1 + 1] = inf
    L[n2 + 1] = inf
    i = 1
    j = 1
    for k = p to r
        if L[i] <= R[j]
            A[k] = L[i]
            i++
        else 
            A[k] = R[j]
            j++

