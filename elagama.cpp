#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check_Prime(int n)
{
    if (n < 2)
        return false;
    else
    {
        for (int i = 2; i < sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}
int generate_Prime()
{
    int n;
    srand((int)time(0));
    while (!check_Prime(n))
    {
        n = 1 + rand() % 200;
    }
    return n;
}

ll pow_Mod(int a, int b, int m)
{
    ll res = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b /= 2;
    }
    return res;
}

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    else if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int EculidExtended(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *y = 0;
        *x = 1;
        return a;
    }
    int x1, y1;
    int gcd = EculidExtended(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

int modInvers(int a, int m)
{
    int x, y;
    int g = EculidExtended(a, m, &x, &y);
    if (g == 1)
    {
        int results = (x % m + m) % m;
        return results;
    }
    return -1;
}

void encrypt(int m, int p, int a, int y, int &c1, int &c2)
{
    cout << "Vui long chon k : ";
    int k;
    cin >> k;
    while (k < 1 || k > p - 1)
    {
        cout << "Vui long nhap lai : ";
        cin >> k;
    }
    int K = pow_Mod(y, k, p);
    c1 = pow_Mod(a, k, p);
    c2 = (K * m) % p;
}

int decrypt(int c1, int c2, int p, int a, int x)
{
    int K = pow_Mod(c1, x, p);
    int K_1 = modInvers(K, p);

    int M = (c2 * K_1) % p;
    return M;
}

main()
{
    // int p = generate_Prime();
    int p = 97;
    cout << "Tao so p : " << p << endl;
    int a = 5;
    cout << "Vui lONG CHON X : ";
    int x = 58;
    // cin >> x;
    int y = pow_Mod(a, x, p);
    cout << "Khoa cong khai : " << p << " " << a << " " << y << endl;
    cout << "Khoa Bi Mat  : " << p << " " << a << " " << x << endl;

    cout << "Vui long nhap ban can ma hoa : ";
    int m = 3;
    // cin >> m;
    int c1, c2;
    encrypt(m, p, a, y, c1, c2);
    cout << "Ban ma : " << c1 << " " << c2 << endl;

    m = decrypt(c1, c2, p, a, x);
    cout << "Ban ro sau khi ma hoa : " << m << endl;
}