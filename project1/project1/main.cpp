#include <iostream>
#include "header.h"
#include <fstream>

//declarations
bool validateInput(std::string password);

//global
constexpr int PASSWORD_MIN = 8;
constexpr int PASSWORD_MAX = 16;




int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    
    
    std::bitset<4> bitset1 = (0001);
    bitset1 <<= 1;
    std::cout << bitset1 << std::endl;
    
    std::string password;
    
    std::cout << "Enter a password for encryption: ";
    std::cin >> password;
    
    while (!(validateInput(password))) {
        std::cout << "Wrong size, enter a password for encryption: ";
        std::cin >> password;
    }
    
    int option;
    std::cout << "Choose your prefered encryption method (1-3)" << std::endl;
    std::cout << "1. XOR based encryption \n";
    std::cout << "2. Custom string mixer \n";
    std::cout << "3. Complex multi layered encryption \n";
    std::cout << "option: ";
    std::cin >> option;
    std::cout << std::endl;
    
    switch (option) {
        case 1:
            password = xorEncryption(password);
            std::cout << "Encrypted password: " << password << "\n";
            password = xorDecryption(password);
            std::cout << "Decrypted password: " << password << std::endl;
            break;
        case 2:
            password = stringMixerEncrypt(password);
            std::cout << "Encrypted password: " << password << "\n";
            password = stringMixerDecrypt(password);
            std::cout << "Decrypted password: " << password << std::endl;
            break;
        case 3:
            break;
            
        default:
            break;
    }
    
    
    
    return 0;
}
    
bool validateInput(std::string password) {
    int length = (int) password.length();

    //check if password has valid length
    if (length >= PASSWORD_MIN && length <= PASSWORD_MAX) {
        
        //check if all chars are ASCII values >= 32
        for(int i = 0; i < length; i++) {
                    if (!((int)password.at(i) >= 32) || (char)password.at(i) == '#') {
                        return false; //invalid char
                    }
            
        }
        
        return true; //length and all chars are valid
    }
    else {
        return false; //invalid length
    }
}
