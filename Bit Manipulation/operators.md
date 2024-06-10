# Operators

### AND 
       all true - True
       1 false - false

### OR 
        1 true -> true
        all false -> false

### XOR 
        no. of 1s - odd - 1
        no. of 1s - even - 0

### Right shift(>>) 
        x >> k = x/2^k
        
13 >> 1 (13 right shift of 1)
        = 6


Ex- 13 >> 1

13 = 1 1 0 1 = (1*2^3 + 1*2^2 + 0*2^1 + 1*2^0)

after 1 right shift - 1 1 0 = (1*2^2 + 1*2^1 + 0*2^0) 
Which means everything is divided by 2^1

Integers are stored in 32-bit binary number in which 1st bit(from right to left) is reversed for sign and rest of them is for number

0 is for +ve and 1 is for -ve

When the computer has to store a -ve number it converts it into 2's compliment

Method for converting it into 2's compliment -
Step 1 - Take 1's compliment(flip the bits)
Step 2 - Add 1 to the result

Longest number that a integer variable can hold = (2^31 - 1) = INT_MAX

### Left Shift(<<) 
                    x << k = x*2^k

13 << 1
13 = 0 0 0 0 _________ 1 1 0 1 
After left shift - 0 0 0 0 _ _ _ _ _ 1 1 0 1 0



(2^31 - 1) << 1 --> This is the case of overflow 

### Not(~)  
Steps:
- 1-Flip
- 12-Check for -ve - If yes, take 2's compliment of bit other than sign bit  otherwise stop

If number is -ve first convert it into 2's compliment then take not of it