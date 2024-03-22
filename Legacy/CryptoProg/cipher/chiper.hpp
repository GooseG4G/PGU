#pragma once
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

class chiper{
    private:
        string pass;
    public:
        chiper() = delete;
        chiper(string key);
        string encrypt(const string input_path, const string output_path);
        string decrypt(const string input_path, const string output_path);
};