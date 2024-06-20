// C++ program to prlong long int all prime factors
#include <bits/stdc++.h>
#include <map>
#include <numeric>
#include <iostream>
#include <cmath>
using namespace std;
 
// A function to prlong long int all prime
// factors of a given number n
long long int primeFactors(long long int n)
{
    long long int blah = n;
    // cout << n << endl;
    std::map<long long int, long long int> map;
    // Prlong long int the number of 2s that divide n
    while (n % 2 == 0)
    {
        map[2]++;
        // cout << map[2] << " " << endl;
        n = n/2;
    }
    


    // n must be odd at this polong long int. So we can skip
    // one element (Note i = i +2)
    for (long long int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, prlong long int i and divide n
        while (n % i == 0)
        {
            // cout << i << " ";

            map[i]++;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        map[n]++;

    //! Execute the core logic now

    long long int product = 1;

    for (const auto &pair : map) {
        product *= pair.second;
    }

 
    // cout << "product is " << product << endl;
    long long int gcd = product;
    // cout << product << endl;
    for (const auto &pair : map) {
        // cout << "I'm in the hashmap and I have value " << pair.first << " " << pair.second << endl;
        gcd = std::gcd(gcd, pair.second);  
    }

    n = blah;
    long long int x = n;
    long long int y = n;
    
    // cout << "gcd is " << gcd << endl;
    if (gcd == 1) {
        ;
    } else {    
        y *= gcd;
        x = std::pow(x, 1/gcd);
    }

    //! now y is the greatest gcd

    // cout << "y is " << y << endl;

    long long int res = 0;
    for (long long int i = 1; i <= sqrt(y); i++) {
        if (y % i == 0) {
            // cout << "factor is " << i << "," << "res is " << res << endl;
            if (y == i * i) {
                if (i % 2 == 0) {
                    res += 2;
                } else {
                    res += 1;
                
                }
                // break;
            } else {
                long long int ff = i;
                long long int sf = y / i;

                if (ff % 2 == 0) {
                    res += 2;
                } else {
                    res += 1;
                } 

                if (sf % 2 == 0) {
                    res += 2;
                } else {
                    res += 1;
                }
            }
        }
    }

    return res;




}
 
/* Driver code */
int main()
{
    long long int result;

    long long int y = pow(3, 16);

    for (int a = 0; a <= 8; a += 1) {
       for (int b = 0; b <= 8; b += 1) {
            long long int z = y * pow(5, a) * pow(2, b);
            result = primeFactors(z);
            cout << z << " " << result << endl;

            if (result > 2023) {
                break;
            }
        
    } 
    }
    long long int z =pow(2, 2) * pow(3, 16) * pow(5, 16) ;
    result = primeFactors(z);
    cout << z << " " << result << endl; 
    return 0;

    for (long long int n = 2; n <= 10000000; n++) {
        long long int x = pow(n, 2);
        result = primeFactors(x);
        // cout << x << " " << result << endl;
        if (result % (17 * 17) == 0) {
            // break;
            cout << x << " " << result << endl;
        }
    }
    
}
