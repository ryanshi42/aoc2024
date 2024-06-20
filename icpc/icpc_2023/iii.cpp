
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

// #include std;

string addOne(string x)
{
    int m = x.length() - 1;
    
    // Flip all the set bits
    // until we find a 0
    while( x[m] == '1' )
    {
        x[m] = '0';
        m -= 1;
    }
    
    if (m == -1) {
        return '1' + x;
    } 
    x[m] = '1';
    return x;
}

int main() {
    string num;
    cin >> num;

    if (num == "1") {
        cout << 10;
        return 0;
    }

    string curr = "0";

    while (true) {
        curr = addOne(curr);

        // cout << curr << "\n";

        size_t found = num.find(curr);
        // found = to_string(num).find('1');

        // cout << DecimalToBinary(curr);

        // cout << std::string::npos << "\n";
        // cout << (num) << "\n";

        // cout << num << "\n";


        if (found != std::string::npos) {
            continue;
        } else {
            cout << curr << "\n";
            return 0;
        }
    }
    return 1;
}

