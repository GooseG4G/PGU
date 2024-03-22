#include "chiper.hpp"
#include <cstddef>
#include <cryptopp/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/tiger.h>
#include <iostream>
using namespace std;

chiper::chiper(string key){
    string pass = key;
};
string chiper::encrypt(const string input_path, const string output_path){
    using namespace CryptoPP;

    byte pass_b[pass.size()];
    StringSource(pass, true, new HexEncoder(new ArraySink(pass_b, sizeof(pass_b))));
    size_t plen = strlen((const char*)pass_b);
    AutoSeededRandomPool SALT_gen;
    byte SALT[AES::BLOCKSIZE];
    SALT_gen.GenerateBlock(SALT, sizeof(SALT));
    byte key[Tiger::DIGESTSIZE];
    size_t slen = strlen((const char*)SALT);
    PKCS5_PBKDF1<Tiger> key_obj;
    byte unused = 0;
        
    key_obj.DeriveKey(key, sizeof(key), unused, pass_b, plen, SALT, slen, 128, 0.0f);
    AutoSeededRandomPool prng;
    byte IV[ AES::BLOCKSIZE ];
    prng.GenerateBlock(IV, sizeof(IV));
        

    ofstream key_file("/home/danila/CryptoProg/chiper/key_file");
    ArraySource(key, sizeof(key), true, new FileSink(key_file));
    ofstream IV_file("/home/danila/CryptoProg/chiper/iv_file");
    ArraySource(IV, sizeof(IV), true, new FileSink(IV_file));
        
    CBC_Mode< AES >::Encryption encryptor;
    encryptor.SetKeyWithIV(key, sizeof(key), IV );
    ifstream input_file(input_path);
    ofstream output_file(output_path);
    FileSource(input_file, true, new StreamTransformationFilter( encryptor, new FileSink(output_file)));
    input_file.close();
    output_file.close();
    return "sdfgsdf";
}
string chiper::decrypt(const string input_path, const string output_path){
    using namespace CryptoPP;
    byte key[Tiger::DIGESTSIZE];
    FileSource("/home/danila/CryptoProg/chiper/key_file", true, new ArraySink(key, sizeof(key)));
    byte IV[ AES::BLOCKSIZE ];
    FileSource("/home/danila/CryptoProg/chiper/iv_file", true, new ArraySink(IV, sizeof(IV)));
        
    CBC_Mode< AES >::Decryption decryptor;
    decryptor.SetKeyWithIV(key, sizeof(key), IV);
    ifstream input_file(input_path);
    ofstream output_file(output_path);
    FileSource(input_file, true, new StreamTransformationFilter( decryptor, new FileSink(output_file)));
    return "sfewrr";
}
