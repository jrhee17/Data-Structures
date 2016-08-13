#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> vec) {
    for(int i = 1; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

void max_heapify(vector<int> &vec, int root, int heapsize) {
    int left = root << 1;
    int right = (root << 1) + 1;

    int max = root;
    if(heapsize > left && vec[left] > vec[max])
        max = left;

    if(heapsize > right && vec[right] > vec[max])
        max = right;

    if(max != root) {
        int swap = vec[root];
        vec[root] = vec[max];
        vec[max] = swap;

        max_heapify(vec, max, heapsize);
    }
    
}

void build_max_heap(vector<int> &vec) {
    int position = vec.size();
    while(position > 0) {
        max_heapify(vec, position, vec.size());
        position--;
    }
    cout << "-----Max heap-----" << endl;
    print_vector(vec);
}

void mergesort(vector<int> &vec) {

    build_max_heap(vec);

    cout << "-----Starting merge sort-----" << endl;
    for(int i = vec.size() - 1; i > 0; i--) {
        print_vector(vec);
        int swap = vec[1];
        vec[1] = vec[i];
        vec[i] = swap;
        max_heapify(vec, 1, i);
    }
}

int main() {

    int arr[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int)); 
    print_vector(vec);

    mergesort(vec);

    cout << "-----Merge sort complete-----" << endl;
    print_vector(vec);
}
