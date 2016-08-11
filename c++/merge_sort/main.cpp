#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

void print_vec(vector<int> vec, int p, int r) {
    for(int i = p; i < r; i++)
        cout << vec[i] << ' ';
    cout << endl;
}

void merge(vector<int> &vec, int p, int q, int r) {
    int n1 = q - p;
    int n2 = r - q;

    vector<int> left;
    for(int i = 0; i < n1; i++) {
       left.push_back(vec[p+i]); 
    }
    left.push_back(INT_MAX);

    vector<int> right;
    for(int i = 0; i < n2; i++) {
       right.push_back(vec[q+i]); 
    }
    right.push_back(INT_MAX);

    int ind1 = 0;
    int ind2 = 0;
    for(int i = 0; i < n1 + n2; i++) {
        if(left[ind1] < right[ind2]) {
            vec[p + i] = left[ind1];
            ind1++;
        } else {
            vec[p + i] = right[ind2];
            ind2++;
        }
    }
}

void merge_sort(vector<int> &vec, int p, int r) {
   print_vec(vec,p,r);
    if(r - 1 > p) {
       int q = (p + r) / 2;
       merge_sort(vec, p, q);
       merge_sort(vec, q, r);
       merge(vec, p, q, r);
    } 
}

int main() {
    int input[] = {2,4,5,7,1,2,3,6};
    vector<int> vec(input, input + sizeof(input) / sizeof(int));

    merge_sort(vec, 0, vec.size());
    print_vec(vec, 0, vec.size());
}
