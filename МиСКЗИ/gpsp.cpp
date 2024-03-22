#include <iostream>
#include <bitset>
#include <fstream>

using namespace std;

bool generate(std::bitset<17> &polinom1, std::bitset<111> &polinom2){
    bool sum1 = polinom1[13] ^ polinom1[16];
    bool sum2 = polinom2[100] ^ polinom2[110];
    bool res = sum1 ^ sum2;

    polinom1 <<= 1;  // Сдвиг влево на 1 позицию
    polinom1[0] = sum1;
    polinom2 <<= 1;  // Сдвиг влево на 1 позицию
    polinom2[0] = sum2;

    return res;
}

int main() {
    int temp;
    
    cout << "Enter second seed: ";
    cin >> temp;
    bitset<17> polinom1(temp); 
    
    cout << "Enter second seed: ";
    cin >> temp;
    bitset<111> polinom2(temp); 

    cout << "Enter len: ";
    cin >> temp;

    cout << endl;
    for (int i = 0; i < temp; i++) {
        cout << generate(polinom1, polinom2);
    }
    cout << endl;

    system("pause");
    return 0;
}
