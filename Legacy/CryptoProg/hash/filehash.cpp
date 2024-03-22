#include "filehash.hpp"

using namespace std;

filehash::filehash(){};
string filehash::hashing(const string path){
    using namespace CryptoPP;
    Weak::MD5 hash;
    std::string digest;
    // создаем цепочку преобразования
    StringSource(path, true,             // источник-стока
                 new HashFilter(hash,       // фильтр-"хеширователь"
                                new HexEncoder(     // кодировщик в строку цифр
                                //new Base64Encoder(   // альтернатива - кодировщик в base64
                                    new StringSink(digest))));  // строка-приемник
    return digest;
}
