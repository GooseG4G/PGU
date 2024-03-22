#pragma once
#include <cryptopp/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK  1
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <iostream>

using namespace std;

class filehash{
    public:
        filehash();
        string hashing(const string path);
};
