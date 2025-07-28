#include <iostream>

//declarations
int step1and2(std::string creditCardNum);
int step3(std::string creditCardNum);
int step4(int int1, int int2);

int main() {
    std::string creditCardNum;
    std::cout << "Enter credit card number to be validated: ";
    std::cin >> creditCardNum;

    int sum = step4(step1and2(creditCardNum), step3(creditCardNum));

    if (sum % 10 == 0)
    {
        std::cout << "valid";
    }
    else
    {
        std::cout << "not valid";
    }
    

    return 0;
}

int step1and2(std::string creditCardNum) {
    int sum = 0;

    for(int i = creditCardNum.size() - 2; i >= 0; i -= 2) {
        int digit = (creditCardNum[i] - '0') *2;
        if (digit > 9)
        {
            sum += digit / 10;
            sum += digit % 10;
        }
        else
        {
            sum += digit;
        }
    }

    return sum;
}

int step3(std::string creditCardNum) {
    int sum = 0;

    for(int i = creditCardNum.size() - 1; i >= 0; i-=2) {
        int digit = creditCardNum[i] - '0';
        sum += digit;
    }

    return sum;
}

int step4(int int1, int int2) {
    int sum = int1 + int2;

    return sum;
}
