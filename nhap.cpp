#include <iostream>
#include <vector>
using namespace std;

const int N = 3;                                                // Kích thước của ma trận khóa, ví dụ 3x3
int keyMatrix[N][N] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}; // Ma trận khóa
int inverseKeyMatrix[N][N];                                     // Ma trận nghịch đảo của khóa

// Hàm nhân ma trận
vector<int> multiplyMatrix(vector<int> messageVector, int matrix[N][N])
{
    vector<int> result(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result[i] += messageVector[j] * matrix[j][i];
        }
        result[i] %= 26;
    }
    return result;
}

// Hàm mã hóa Hill
string hillEncrypt(string message)
{
    // Đảm bảo độ dài thông điệp chia hết cho N
    while (message.size() % N != 0)
    {
        message += 'X'; // Thêm 'X' nếu cần
    }

    string encrypted = "";
    for (int i = 0; i < message.size(); i += N)
    {
        vector<int> messageVector(N);
        for (int j = 0; j < N; j++)
        {
            messageVector[j] = message[i + j] - 'A';
        }
        vector<int> encryptedVector = multiplyMatrix(messageVector, keyMatrix);
        for (int j = 0; j < N; j++)
        {
            encrypted += (char)(encryptedVector[j] + 'A');
        }
    }
    return encrypted;
}

// Hàm tìm ma trận nghịch đảo (được rút gọn cho mục đích giáo dục)
void findInverseKeyMatrix()
{
    // Viết mã để tính ma trận nghịch đảo của keyMatrix và lưu vào inverseKeyMatrix
    // ...
}

// Hàm giải mã Hill
string hillDecrypt(string encrypted)
{
    findInverseKeyMatrix(); // Tìm ma trận nghịch đảo trước khi giải mã

    string decrypted = "";
    for (int i = 0; i < encrypted.size(); i += N)
    {
        vector<int> encryptedVector(N);
        for (int j = 0; j < N; j++)
        {
            encryptedVector[j] = encrypted[i + j] - 'A';
        }
        vector<int> decryptedVector = multiplyMatrix(encryptedVector, inverseKeyMatrix);
        for (int j = 0; j < N; j++)
        {
            decrypted += (char)(decryptedVector[j] + 'A');
        }
    }
    return decrypted;
}

int main()
{
    string message = "HELLO WORLD";
    string encrypted = hillEncrypt(message);
    string decrypted = hillDecrypt(encrypted);

    cout << "Original Message: " << message << endl;
    cout << "Encrypted Message: " << encrypted << endl;
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}
