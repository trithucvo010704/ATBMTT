#include <bits/stdc++.h>
using namespace std;

const int m = 26; // Số lượng ký tự trong bảng chữ cái tiếng Anh.
int modInvers(int A, int M)
{
    int m0 = M; // gan mo neu nhu co truong hop am
    int y = 0, x = 1;
    if (M == 1)
        return 0;
    while (A > 1)
    {
        int q = A / M;
        int t = M;
        M = A % M;
        A = t;

        t = y;
        // cap nhat y
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
int gcdExtend(int a, int m, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return m;
    }
    int x1, y1; // luu gia tri x y  moi
    int g = gcdExtend(a % m, a, &x1, &y1);
    *x = y1 - (m / a) * x1;
    *y = x1;
    return g;
}
int modeInvers2(int a, int m)
{
    int x, y;
    int g = gcdExtend(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        int res = (x % m + m) % m;
        x = res;
    }
    return g;
}
string encode(string s, int a, int b)
{
    string result = " ";
    char base;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            base = (s[i] >= 'a' && s[i] <= 'z') ? 'a' : 'A';
            int x = s[i] - base;
            s[i] = (a * x + b) % m + base;
            result += s[i];
        }
        else
        {
            result += s[i];
        }
    }
    return result;
}
string decode(string s, int a, int b)
{
    char base;
    int modinversA = modInvers(a, m); // tim nghich dao modul cua a
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            base = (s[i] >= 'a' && s[i] <= 'z') ? 'a' : 'A';
            int y = s[i] - base;
            s[i] = modinversA * (y - b + m) % m + base;
        }
    }
    return s;
}

int main()
{
    string s = "HOT";
    int a = 5, b = 6;
    cout << s << endl;
    cout << "-------" << endl;
    cout << encode(s, a, b) << endl;
    cout << "-------" << endl;
    cout << decode(encode(s, a, b), a, b) << endl;
    cout << "-------" << endl;
}