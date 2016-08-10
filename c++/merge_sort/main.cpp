#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void print_vec(vector<int> vec, int p, int r) {
    for(int i = p; i < r; i++)
        cout << vec[i] << ' ';
    cout << endl;
}

void merge_sort(vector<int> vec, int p, int r) {
    print_vec(vec, p, r);
    if(r - 1 > p) {
       int q = (p + r) / 2;
       cout << "p: " << p << " q: " << q << " r: " << r << endl;
       merge_sort(vec, p, q);
       merge_sort(vec, q, r);
    } 
}

int main() {
    int input[] = {2,4,5,7,1,2,3,6};
    vector<int> vec(input, input + sizeof(input) / sizeof(int));

    merge_sort(vec, 0, vec.size());
}
