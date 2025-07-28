# C++ projects

### Luhn algorythm
- Starting from the second-to-last digit, double every second digit moving left.
- If a doubled digit is greater than 9, subtract 9 from it (or add its digits together).
- Add all the results from step 1.
- Then, add the sum of the digits that were not doubled (i.e., every other digit starting from the last one).
- If the total sum is divisible by 10, the credit card number is valid.
