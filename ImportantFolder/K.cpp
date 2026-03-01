#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string add(string num1, string num2)
{
    string result = "";
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry + (i >= 0 ? num1[i--] - '0' : 0) + (j >= 0 ? num2[j--] - '0' : 0);
        result += to_string(sum % 10);
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}
string subtract(string num1, string num2)
{
    string result = "";
    int i = num1.size() - 1, j = num2.size() - 1, borrow = 0;
    while (i >= 0)
    {
        int sub = (num1[i--] - '0') - (j >= 0 ? num2[j--] - '0' : 0) - borrow;
        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result += to_string(sub);
    }
    while (result.size() > 1 && result.back() == '0')
        result.pop_back();
    reverse(result.begin(), result.end());
    return result;
}
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