#include <iostream>

using namespace std;

int cut_rod(int *arr, int size) {
    if(size == 0)
        return 0;
    int q = -100;
    for(int i = 1; i <= size; i++)
        q = max(q, arr[i-1] + cut_rod(arr, size-i));

    return q;
}

int memoized_cut_rod_aux(int* arr, int size, int* r) {
    if(size-1 >= 0 && r[size-1] >= 0)
        return r[size-1];

    int q;
    if(size == 0) {
        q = 0;
        return q;
    } else {
        q = -100;
        for(int i = 1; i <= size; i++) 
            q = max(q, arr[i-1] + memoized_cut_rod_aux(arr, size-i, r));
    }
    r[size-1] = q;
    return q;
}

int memoized_cut_rod(int* arr, int size) {
    int r[size];
    for(int i = 0; i < size; i++)
        r[i] = -100;
    return memoized_cut_rod_aux(arr, size, r);
}

int bottom_up_cut_rod(int* arr, int size) {
    int r[size+1];
    r[0] = 0;
    for(int i = 1; i <= size; i++) {
        int q = -100;
        for(int j = 1; j <= i; j++)
            q = max(q, arr[j-1] + r[i-j]);
        r[i] = q;
    }
    return r[size];
}

int main() {

    int arr[10] = {1,5,8,9,10,17,17,20,24,30};

    int max_price = cut_rod(arr, 10);
    cout << "Naive Result: " << max_price << endl;

    int topdown_max_price = memoized_cut_rod(arr, 10);
    cout << "Memoized Result1: " << topdown_max_price << endl;

    int bottomup_max_price = bottom_up_cut_rod(arr, 10);
    cout << "Memoized Result2: " << bottomup_max_price << endl;

}
