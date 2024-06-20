
// 3,000 and at most 10,000

#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 3000; i < 10000; i++) {
        if (i % 4 == 1 && i % 9 == 1 && i % 16 == 1 && i % 25 == 1 && i % 36 == 1) {
            sum += i;
        }
    }
    cout << sum;
}