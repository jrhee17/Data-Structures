Heap Sort

Features
-------------------------
1. Max-Heapify: runs in O(logn), maintains the max heap property
2. Build-Max-Heap: runs in O(n), produces a max heap from an unordered input array
    Proof:
    \sum_{h = 0}^{logn} n / (2^{h + 1}) O(h) = O(n \sum_{h = 0}^{logn} h / 2^h)
    \sum_{h / 2^h} = 1/2 / (1 - 1/2)^2 = 2
    O(n)
3. Heapsort: runs in O(nlogn), sorts an array in place
4. Max-Heap-Insert, Heap-Extract-Max, Heap-Increase-Key, Heap-Maximum: runs in O(logn), allows heap structure to implement a priority queue
5. 

Pseudocode
-------------------------
Max-Heapify(A, i):
    l = Left(i)
    r = Right(i)
    if(l <= A.heap-size and A[l] > A[i])
        largest = l
    else
        largest = i

    if(r <= A.heap-size and A[r] > A[largest])
        largest = r

    if(largest != i)
        exchange A[i] with A[largest]
        Max-Heapify(A, largest)

Build-Max-Heap(A):
    A.heap-size = A.length
    for i = floor(A.length / 2) to 1
        Max-Heapify(A, i)

Heapsort(A):
    Build-Max-Heap(A)
    for i = A.length to 2
        exchange A[1] with A[i]
        A.heap-size = A.heap-size - 1
        Max-Heapify(A, 1)

