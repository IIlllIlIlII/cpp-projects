# C++ projects

### Luhn algorythm
Algorythm to validate credit card numbers:
- Starting from the second-to-last digit, double every second digit moving left
- If a doubled digit is greater than 9, subtract 9 from it (or add its digits together)
- Add all the results from step 1 and 2
- Then, add the sum of the digits that were not doubled (i.e., every other digit starting from the last one)
- If the total sum is divisible by 10, the credit card number is valid

### Encryption / Decryption tool (Bitwise manipulation, XOR, ASCII, Input validation, Modular design)
- Input: password (string, 8 to 16 chars)
- Encryption Methods: XOR based/ string Mixer / multi layered encryption

XOR based encryption:
- Uses a fixed 16-character key (ENCRYPTION_KEY) for encryption and decryption.
- Loops over each character in the password and performs a bitwise XOR with the corresponding character in the ENCRYPTION_KEY 

String Mixer
- Uses a character mapping table for ASCII 32–127
- TThe left side contains characters in standard order
- the right side is user-defined from a .txt file in the root directory (Layout: a#[YOUR REPLACEMENT)
- A reverse map is automatically generated for decryption

Multi-layered encription algorythm
- Uses multiple independant layers to encrypt the password
- Layers are fully modular and can be removed / extended
- Current layers: 1.Bit rotation / 2. Character swapping / 3. XOR with ENCRYPTION_KEY
