#include "header.h"
#include <iostream>

//declarations
std::string multiLayeredEncryption(std::string password);
std::string multiLayeredDecryption(std::string password);

//global
constexpr std::string ENCRYPTION_KEY = "x8Rp2fLzPqW9mB1n";

std::string multiLayeredEncryption(std::string password) {
    int length = (int)password.length();
    
    //Layer 1
    for (int i = 0; i < length; i++) {
        // 1234 --> 4123
        std::bitset<8> temp_bitset(static_cast<unsigned char>(password[i]));
        temp_bitset = (temp_bitset >> 1) | (temp_bitset << 7); //8 - 1 (size - shift value)
        password[i] = static_cast<char>(temp_bitset.to_ulong());
    }
    
    //Layer 2
    char temp_char;
    if (length % 2 == 0) { //check if password.length() is not equal
        //4123 -> 1432
        for (int i = 0; i < length; i+=2) {
            temp_char = password[i];
            password[i] = password[i+1];
            password[i+1] = temp_char;
        }
    }
    else { //change everything except the last char
        for (int i = 0; i < length - 1; i+=2) { //make length even e.g. 9-1 = 8
            temp_char = password[i];
            password[i] = password[i+1];
            password[i+1] = temp_char;
        }
    }
    
    //Layer 3
    for (int i = 0; i < length; i++) {
        password[i] = password[i] ^ ENCRYPTION_KEY[i]; //ENCRYPTION_KEY is as long as PASSWORD_MAX
    }
    
    return password;
}


std::string multiLayeredDecryption(std::string password) {
    int length = (int)password.length();
    
    //reverse Layer 3
    for (int i = 0; i < length; i++) {
        password[i] = password[i] ^ ENCRYPTION_KEY[i];
    }
    
    //reverse Layer 2
    char temp_char;
    if (length % 2 == 0) { //check if password.length() is not equal
        //4123 -> 1432
        for (int i = 0; i < length; i+=2) {
            temp_char = password[i];
            password[i] = password[i+1];
            password[i+1] = temp_char;
        }
    }
    else { //change everything except the last char
        for (int i = 0; i < length - 1; i+=2) { //make length even e.g. 9-1 = 8
            temp_char = password[i];
            password[i] = password[i+1];
            password[i+1] = temp_char;
        }
    }

    //reverse Layer 1
    for (int i = 0; i < length; i++) {
        std::bitset<8> temp_bitset(static_cast<unsigned char>(password[i]));
        temp_bitset = (temp_bitset << 1) | (temp_bitset >> 7);
        password[i] = static_cast<char>(temp_bitset.to_ulong());
    }
    
    
    
    
    
    return password;
}
