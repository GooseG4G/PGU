#include <iostream>
#include "chiper.hpp"

int main(){
    cout << "Cipher ready. Input key: ";
    string key;
    string input_path;
    string output_path;
    cin >> key;
    cin.get();
    int op;
    cout << "Key loaded\n";
        chiper AES(key);
        do {
            cout << "Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
            cin >> op;
            cin.get();
            if (op > 2) {
                cout << "Illegal operation\n";
            }
            else if (op > 0) {
            	cout << "Encrypter ready.\n";
            	cout << "Input 'd' to default settings else input_path: ";
                cin >> input_path;
                if (op == 1) {
                    if (input_path == "d")
                    	AES.encrypt("/home/danila/CryptoProg/chiper/file", "/home/danila/CryptoProg/chiper/encrypted");
                    else{
                    	cout << "Input output_path: ";
                    	cin >> output_path;
                    	AES.encrypt(input_path, output_path);
                    }
                    cout << "completed"<< endl;
                }
                else {
                    if (input_path == "d")
                    	AES.decrypt("/home/danila/CryptoProg/chiper/encrypted", "/home/danila/CryptoProg/chiper/decrypted");
                    else{
                    	cout << "Input output_path: ";
                    	cin >> output_path;
                    	AES.decrypt(input_path, output_path);
                    }
                    cout << "completed"<< endl;
                }
            }
        } while (op != 0);
    
    return 0;
};
