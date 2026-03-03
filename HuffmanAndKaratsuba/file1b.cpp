#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long karatsuba(long long x, long long y)
{
    if (x < 10 || y < 10)
        return x * y;
    string sx = to_string(x);
    string sy = to_string(y);
    int n = max(sx.size(), sy.size());
    int half = n / 2;
    long long powerOf10 = 1;
    for (int i = 0; i < half; i++)
        powerOf10 *= 10;
    long long a = x / powerOf10;
    long long b = x % powerOf10;
    long long c = y / powerOf10;
    long long d = y % powerOf10;
    long long P1 = karatsuba(a, c);
    long long P2 = karatsuba(b, d);
    long long P3 = karatsuba(a + b, c + d);
    return P1 * (powerOf10 * powerOf10) + (P3 - P1 - P2) * powerOf10 + P2;
}
int main()
{
    long long num1, num2;
    cout << "Name: MISTRY NISHK NILESHKUMAR\nRegistration number: 24BCE5236\n";
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    long long result = karatsuba(num1, num2);
    cout << "Result: " << result << endl;
    return 0;
}