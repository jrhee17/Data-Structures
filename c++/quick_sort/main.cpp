#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " "; 
    cout << endl;
    
}

int partition(vector<int> &vec, int p, int r) {
    int pivot = vec[r];
    int i = p -  1;

    for(int j = p; j < r; j++) {
        if(vec[j] < pivot) {
            i++;
            int swap = vec[i];
            vec[i] = vec[j];
            vec[j] = swap;
        }
    }
    i++;
    int swap = vec[i];
    vec[i] = pivot;
    vec[r] = swap;

    return i;
}

int randomized_partition(vector<int> &vec, int p, int r) {
    int t = rand() % (p - r + 1);
    int swap = vec[t];
    vec[t] = vec[r];
    vec[r] = swap;

    return partition(vec, p, r);
}

void quicksort(vector<int> &vec, int p, int r) {
    if(p < r) {
        print_vec(vec);
        int q = partition(vec, p, r);
        print_vec(vec);
        quicksort(vec, p, q - 1);
        quicksort(vec, q + 1, r);
    }
}

void randomized_quicksort(vector<int> &vec, int p, int r) {
    if(p < r) {
        print_vec(vec);
        int q = randomized_partition(vec, p, r);
        print_vec(vec);
        quicksort(vec, p, q - 1);
        quicksort(vec, q + 1, r);
    }
}

int main() {
    int input[] = {2, 8, 7, 1, 3, 5, 6, 4};
    vector<int> vec(input, input + sizeof(input) / sizeof(int));

    cout << "----- Input -----" << endl;
    print_vec(vec);

    cout << "----- Sort starting -----" << endl;
    randomized_quicksort(vec, 0, vec.size() - 1);

    cout << "----- Final -----" << endl;
    print_vec(vec);

}
