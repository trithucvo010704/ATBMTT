#include <bits/stdc++.h>
using namespace std;
string bin_to_hex(string s)
{ // ham chuyen he 2 sang he 10
    string hex = "";
    for (int i = 0; i < s.size(); i += 4)
    {
        string k = "";
        for (int j = i; j < i + 4; j++)
            k += s[j];
        if (k == "0000")
            hex += '0';
        else if (k == "0001")
            hex += '1';
        else if (k == "0010")
            hex += '2';
        else if (k == "0011")
            hex += '3';
        else if (k == "0100")
            hex += '4';
        else if (k == "0101")
            hex += '5';
        else if (k == "0110")
            hex += '6';
        else if (k == "0111")
            hex += '7';
        else if (k == "1000")
            hex += '8';
        else if (k == "1001")
            hex += '9';
        else if (k == "1010")
            hex += 'A';
        else if (k == "1011")
            hex += 'B';
        else if (k == "1100")
            hex += 'C';
        else if (k == "1101")
            hex += 'D';
        else if (k == "1110")
            hex += 'E';
        else if (k == "1111")
            hex += 'F';
    }
    return hex;
}

string hex_to_bin(string s)
{
    string bin = "";
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '0')
        {
            bin += '0000';
        }
        else if (s[i] == '1')
        {
            bin += '0001';
        }
        else if (s[i] == '2')
        {
            bin += '0010';
        }
        else if (s[i] == '3')
        {
            bin += '0011';
        }
        else if (s[i] == '4')
        {
            bin += '0100';
        }
        else if (s[i] == '5')
        {
            bin += '0101';
        }
        else if (s[i] == '6')
        {
            bin += '0110';
        }
        else if (s[i] == '7')
        {
            bin += '0111';
        }
        else if (s[i] == '8')
        {
            bin += '1000';
        }
        else if (s[i] == '9')
        {
            bin += '1001';
        }
        else if (s[i] == 'A')
        {
            bin += '1010';
        }
        else if (s[i] == 'B')
        {
            bin += '1011';
        }

        else if (s[i] == 'C')
        {
            bin += '1100';
        }
        else if (s[i] == 'D')
        {
            bin += '1101';
        }
        else if (s[i] == 'E')
        {
            bin += '1110';
        }
        else if (s[i] == 'F')
        {
            bin += '1111';
        }
    }
    return bin;
}

string dec_to_bin(int n)
{
    // dau vao la 1 so he 10
    string bin = "";
    while (n > 0)
    {
        bin = (char)(n % 2 + '0');
        n /= 2;
    }
    while (bin.size() < 4)
    {
        bin = '0' + bin; // neu khong du 4 bit them bit 0  vao truoc
    }
    return bin;
}

int bin_to_dec(string b)
{
    // dau vao la chuoi nhi phan
    int demicalNum = 0;
    int pos = 0;
    for (int i = b.size() - 1; i >= 0; i--)
    {
        if (b[i] == '1')
        {
            demicalNum += pow(2, pos);
        }
        ++pos;
    }
    return demicalNum;
}

string permute(string k, int arr[], int n)
{
    // dau vao cua ham tren la chuoi dau vao k
    // mang co dinh de chuyen doi arr
    // so phan tu can chuyen doi

    string permutenation = "";
    for (int i = 0; i < n; i++)
    {
        permutenation += k[arr[i] - 1];
    }
    return permutenation;
}
string shift_left(string k, int nth_shifts)
{
    // function nay dung trong sinh khoa
    // dau vao la mot chuoi k va dich trai vi tri thuc n
    string s = k;
    for (int i = 0; i < nth_shifts; i++)
    {
        char temp = s[i];
        s.erase(0, 1); // xoa ky tu dau tien
        s += temp;     // dau ptu dau tien ve cuoi
    }
    return s;
}
string Xor(string a, string b)
{
    string s = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            s += '1';
        }
        else
            s += '0';
    }
    return s;
}

// them bang
//    # Table of Position of 64 bits at initial level: Initial Permutation Table
// bang IP
int initial_perm[64] = {58, 50, 42, 34, 26, 18, 10, 2,
                        60, 52, 44, 36, 28, 20, 12, 4,
                        62, 54, 46, 38, 30, 22, 14, 6,
                        64, 56, 48, 40, 32, 24, 16, 8,
                        57, 49, 41, 33, 25, 17, 9, 1,
                        59, 51, 43, 35, 27, 19, 11, 3,
                        61, 53, 45, 37, 29, 21, 13, 5,
                        63, 55, 47, 39, 31, 23, 15, 7};

// # Expansion D-box Table
int exp_d[48] = {32, 1, 2, 3, 4, 5, 4, 5,
                 6, 7, 8, 9, 8, 9, 10, 11,
                 12, 13, 12, 13, 14, 15, 16, 17,
                 16, 17, 18, 19, 20, 21, 20, 21,
                 22, 23, 24, 25, 24, 25, 26, 27,
                 28, 29, 28, 29, 30, 31, 32, 1};

// #Straight Permutation Table
int per[32] = {16, 7, 20, 21,
               29, 12, 28, 17,
               1, 15, 23, 26,
               5, 18, 31, 10,
               2, 8, 24, 14,
               32, 27, 3, 9,
               19, 13, 30, 6,
               22, 11, 4, 25};

// #S - box Table
int sbox[8][4][16] = { // S-box
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},
    {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
     {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
     {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
     {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},
    {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
     {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
     {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
     {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},
    {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
     {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
     {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
     {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},
    {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
     {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
     {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
     {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},
    {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
     {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
     {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
     {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},
    {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
     {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
     {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
     {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},
    {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
     {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
     {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
     {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}};

// #Final Permutation Table Ip-1
int final_perm[64] = {40, 8, 48, 16, 56, 24, 64, 32,
                      39, 7, 47, 15, 55, 23, 63, 31,
                      38, 6, 46, 14, 54, 22, 62, 30,
                      37, 5, 45, 13, 53, 21, 61, 29,
                      36, 4, 44, 12, 52, 20, 60, 28,
                      35, 3, 43, 11, 51, 19, 59, 27,
                      34, 2, 42, 10, 50, 18, 58, 26,
                      33, 1, 41, 9, 49, 17, 57, 25};

string encrypt(string pt, string rkb[], string rk[])
{
    // chuyen thanh nhiphan 64 bits
    pt = hex_to_bin(pt);
    // qua cuc IP ban dau
    pt = permute(pt, initial_perm, 64);
    cout << "Sau khi qua IP : " << bin_to_hex(pt) << endl;
    // chia doi du lieu
    string left = pt.substr(0, 32);
    string right = left.substr(32, 64);
    // duyet 16 vong
    for (int i = 0; i < 16; i++)
    {
        // Expansion D-box: Mở rộng 32 bit thành 48 bit
        string right_expand = permute(right, exp_d, 48);

        // XOR với RoundKey[i]
        string xor_x = Xor(right_expand, rkb[i]);

        // S-boxes: Thay thế giá trị từ bảng S-box
        std::string sbox_str = "";
        for (int j = 0; j < 8; j++)
        {
            int row = bin_to_dec(xor_x.substr(j * 6, 1) + xor_x.substr(j * 6 + 5, 1));
            int col = bin_to_dec(xor_x.substr(j * 6 + 1, 4));
            int val = sbox[j][row][col];
            sbox_str += dec_to_bin(val);
        }
        // DAU RA SAU VONG FOR LA SBOX_STR 32 BITS

        sbox_str = permute(sbox_str, per, 32);

        // XOR với nửa trái
        string result = Xor(left, sbox_str);
        left = result;
    }
}