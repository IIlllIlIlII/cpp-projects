#include "header.h"
#include <iostream>

//declarations
std::string xorEncryption(std::string password);
std::string xorDecryption(std::string password);

//global
constexpr std::string ENCRYPTION_KEY = "x8Rp2fLzPqW9mB1n";



std::string xorEncryption(std::string password) {
    int length = (int) password.length(); //safe -> password length cannot exceed PASSWORD_MAX
    //std::string encryptedPassword;
    

    for (int i = 0; i < length; i++) {
        password[i] = password[i] ^ ENCRYPTION_KEY[i];
        
    }
    
    return password;
}


std::string xorDecryption(std::string password) {
    
    for(int i = 0; i < password.length(); i++) {
        password[i] = password[i] ^ ENCRYPTION_KEY[i];
    }
    
    return  password;
}

