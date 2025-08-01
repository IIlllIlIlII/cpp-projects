# C++ projects

### Luhn algorythm
- Starting from the second-to-last digit, double every second digit moving left.
- If a doubled digit is greater than 9, subtract 9 from it (or add its digits together).
- Add all the results from step 1 and 2.
- Then, add the sum of the digits that were not doubled (i.e., every other digit starting from the last one).
- If the total sum is divisible by 10, the credit card number is valid.

### Encryption / Decryption tool
-> Input: password (string, 8 to 16 chars)
-> Encryption Methods: XOR based/ string Mixer / compley multi layered encryption

XOR based encryption:
- Uses a fixed 16-character key (ENCRYPTION_KEY) for encryption and decryption.
- Loops over all password characters to perform XOR between the input and the ENCRYPTION_KEY

String Mixer
- Uses a mapping table between ASCII characters 32–127, where the left side is in standard chronological order
- The right side is a user-defined order specified in a .txt file located in the root directory
- Creates a second reverse mapping table by swapping keys and values of the first map, enabling decryption by converting the encrypted characters back to the original ones
