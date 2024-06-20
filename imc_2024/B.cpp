//
// Created by Franco Reyes on 13/3/2024.
//

#include <bits/stdc++.h>
using namespace std;

int sides[3];

int main(void) {
    cin >> sides[0] >> sides[1] >> sides[2];
    sort(sides, sides + 3);

    if (sides[0] == sides[1] && sides[1] == sides[2]) {
        cout << "EQUILATERAL\n";
    }
    else if (sides[0] + sides[1] <= sides[2] || sides[1] + sides[2] <= sides[0] || sides[0] + sides[2] <= sides[1]) {
        cout << "NOT A TRIANGLE\n";
    }  else if (sides[0] == sides[1] || sides[1] == sides[2]) {
        cout << "ISOSCELES\n";
    } else if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
        cout << "RIGHT ANGLED\n";
    } else {
        cout << "SCALENE\n";
    }
}