#include <iostream>
#include "header.h"
#include <fstream>

//declarations
std::string stringMixerEncrypt(std::string password);
std::string stringMixerDecrypt(std::string password);
void getEncryptionTables();

//global
std::unordered_map<char, char> map;
std::unordered_map<char, char> reversedMap;
bool initialized = false;



std::string stringMixerEncrypt(std::string password) {
    
    if (!initialized) {
        getEncryptionTables();
        initialized = true;
    }
    
    
    for (int i = 0; i < password.length(); i++) {
        password[i] = map[password[i]];
    }
    return password;
}

std::string stringMixerDecrypt(std::string password) {
    for (int i = 0; i < password.length(); i++) {
        password[i] = reversedMap[password[i]];
    }
    return password;
}

void getEncryptionTables() {
    map.clear();
    reversedMap.clear();
    
    std::ifstream file("/Users/fabi/Documents/c++ projects/project1/project1/map.txt"); //path
    
    if (file.fail()) { //error handling
        std::cerr << "File error";
    }
    

    char c;
    char temp_left;
    char temp_right;
    int counter = 0;
    
    
    while (file.get(c)) { //loop the file
        if (!(c == '#') && !(c == '\n')) { //ignore # and new lines chars ('\n')
            
            if (counter == 0) {
                temp_left = c;
                counter++;
            }
            else {
                temp_right = c;
                counter = 0;
                map[temp_left] = temp_right; //add chars to map
            }
        }
        
    }
    
    for (auto pair : map) { //create reversed map for decryption
        temp_left = pair.first;
        temp_right = pair.second;
        reversedMap[temp_right] = temp_left;
    }

    
    file.close();
}
