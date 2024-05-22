#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

// Hàm tính ước số chung lớn nhất của a và b
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Hàm kiểm tra xem n có phải là số nguyên tố hay không
bool is_prime(long long n) {
    if (n <= 1)
        return false;
    for (long long i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

// Hàm tạo khóa công khai và khóa riêng tư
void generate_keys(long long p, long long g, long long& x, long long& y) {
    // Chọn khóa riêng tư x trong khoảng [1, p-1]
    x = rand() % (p - 1) + 1;
    
    // Tính khóa công khai y
    y = pow(g, x, p);
}

// Hàm mã hóa chuỗi
vector<pair<long long, long long>> encrypt(string m, long long p, long long g, long long y) {
    vector<pair<long long, long long>> ciphertext;
    for (char c : m) {
        long long k = rand() % (p - 1) + 1;
        long long c1 = pow(g, k, p);
        long long c2 = (static_cast<long long>(c) * pow(y, k, p)) % p;
        ciphertext.emplace_back(c1, c2);
    }
    return ciphertext;
}

// Hàm giải mã chuỗi
string decrypt(vector<pair<long long, long long>> ciphertext, long long p, long long x) {
    string plaintext;
    for (const auto& pair : ciphertext) {
        long long c1 = pair.first;
        long long c2 = pair.second;
        long long m = (c2 * pow(c1, p - 1 - x, p)) % p;
        plaintext += static_cast<char>(m);
    }
    return plaintext;
}

int main() {
    srand(time(NULL));
    
    long long p = 23, g = 5, x, y;
    string message = "Hello, World!";
    
    // Tạo khóa công khai và khóa riêng tư
    generate_keys(p, g, x, y);
    cout << "Khóa công khai: " << y << endl;
    cout << "Khóa riêng tư: " << x << endl;
    
    // Mã hóa chuỗi
    auto ciphertext = encrypt(message, p, g, y);
    cout << "Ciphertext: ";
    for (const auto& pair : ciphertext) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;
    
    // Giải mã chuỗi
    string plaintext = decrypt(ciphertext, p, x);
    cout << "Plaintext: " << plaintext << endl;
    
    return 0;
}