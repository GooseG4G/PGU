#include <iostream>
#include <vector>

using namespace std;

vector<bool> handler(int seed1, int seed2, int len) {
    vector<bool> polinom1(17);
    vector<bool> polinom2(111);
    vector<bool> result(len);

    // Инициализация начальных битов полиномов
    for (int i = 16; i >= 0; --i) {
        polinom1[i] = seed1 & 1;
        seed1 >>= 1;
    }

    for (int i = 110; i >= 0; --i) {
        polinom2[i] = seed2 & 1;
        seed2 >>= 1;
    }

    for (int i = 0; i < len; ++i) {
        bool bit14 = polinom1[13];
        bool bit17 = polinom1[16];
        bool bit101 = polinom2[100];
        bool bit111 = polinom2[110];

        bool sum1 = bit14 ^ bit17;
        bool sum2 = bit101 ^ bit111;
        bool sum = sum1 ^ sum2;

        // Сдвигаем биты и обновляем значения
        for (int j = 16; j > 0; --j) {
            polinom1[j] = polinom1[j - 1];
        }
        polinom1[0] = sum1;

        for (int j = 110; j > 0; --j) {
            polinom2[j] = polinom2[j - 1];
        }
        polinom2[0] = sum2;

        result[i] = sum;
    }

    // Преобразуем биты обратно в число
    int convert = 0;
    for (bool bit : result) {
        convert = (convert << 1) | bit;
    }

    cout << "Resulting number: " << convert << endl;
    return result;
}

int main() {
    while (true) {
        int seed1, seed2, len;

        cout << "Enter the seed for first polynomial: ";
        cin >> seed1;

        cout << "Enter the seed for second polynomial: ";
        cin >> seed2;

        cout << "Enter the number of iterations len: ";
        cin >> len;

        vector<bool> result = handler(seed1, seed2, len);
    };

    return 0;
}
