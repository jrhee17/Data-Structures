#include <iostream>

//using namespace std;

int main() {

    for(int i = 1; i < 20; i+=2) {
        for(int j = 0; j < i; j+=1) {
            std::cout << "1";
        }
        std::cout << std::endl;
    }
}
