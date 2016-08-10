#include <iostream>
#include <array>
#include <stdio.h>
#include <vector>

using namespace std;

void printArray(vector<int> vec) {
   for(int k = 0; k < vec.size(); k++)
       cout << vec[k];
   cout << endl;
}

void insertionSort(vector<int> vec) {
    for(int i = 1; i < vec.size(); i++) {
       int current = vec[i];
       int j = i - 1;
       while(j >= 0 && current < vec[j]) {
            vec[j+1] = vec[j];
            j--;
       }
       vec[j+1] = current;
       printArray(vec);
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    printArray(vec);

    insertionSort(vec);
}
