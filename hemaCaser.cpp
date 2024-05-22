// input : khoa k va tu ngu dau vao

// dung bang ma cua my de moa hoa

#include <bits/stdc++.h>
using namespace std;
string encode(string a, int k)
{
    string results = "";
    int n = a.length();
    char new_char;
    char base;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
        {
            base = (a[i] >= 'a' && a[i] <= 'z') ? 'a' : 'A';
            new_char = ((a[i] - base + k) % 26) + base;
            results += new_char;
        }
        else
        {
            results += a[i];
        }
    }
    return results;
}
string decode(string a, int k)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
        {
            char base = (a[i] >= 'a' && a[i] <= 'z') ? 'a' : 'A';
            int x = a[i] - base;
            a[i] = (x - k + 26) % 26 + base;
        }
    }
    return a;
}
// Neu muon decode tru truyen t3

int main()
{
    string s;
    getline(cin, s);
    int k = 3;
    cout << s << endl;
    cout << encode(s, k) << endl;
    cout << encode(encode(s, k), -k) << endl;
}
