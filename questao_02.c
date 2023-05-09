#include <stdio.h>
#include <string.h>

int romanToDecimal(char romanNum[]) {
    int decimalNum = 0;
    int i;
    
    for (i = 0; i < strlen(romanNum); i++) {
        switch (romanNum[i]) {
            case 'I':
                if (romanNum[i + 1] == 'V') {
                    decimalNum += 4;
                    i++;
                } else if (romanNum[i + 1] == 'X') {
                    decimalNum += 9;
                    i++;
                } else {
                    decimalNum += 1;
                }
                break;
            case 'V':
                decimalNum += 5;
                break;
            case 'X':
                if (romanNum[i + 1] == 'L') {
                    decimalNum += 40;
                    i++;
                } else if (romanNum[i + 1] == 'C') {
                    decimalNum += 90;
                    i++;
                } else {
                    decimalNum += 10;
                }
                break;
            case 'L':
                decimalNum += 50;
                break;
            case 'C':
                if (romanNum[i + 1] == 'D') {
                    decimalNum += 400;
                    i++;
                } else if (romanNum[i + 1] == 'M') {
                    decimalNum += 900;
                    i++;
                } else {
                    decimalNum += 100;
                }
                break;
            case 'D':
                decimalNum += 500;
                break;
            case 'M':
                decimalNum += 1000;
                break;
            default:
                printf("Character does not belong to Roman numerals.\n");
                return -1;
        }
    }
    
    return decimalNum;
}

// Function to verify that there are only Roman numeral characters in the string, if there is any "strange" character
// it returns false and stops the execution

int verificaString(char str[]) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != 'I' && str[i] != 'V' && str[i] != 'X' && str[i] != 'L' && str[i] != 'C' && str[i] != 'D' && str[i] != 'M') {
            return 0; 
        }
    }
    return 1;
}

int main() 
{
    char romanNum[100];
    
    printf("Enter a roman number: ");
    scanf("%s", romanNum);
    
     if (verificaString(romanNum)) {
        int decimalNum = romanToDecimal(romanNum);
        if (decimalNum != -1) {
            printf("The corresponding decimal number is: %d\n", decimalNum);
        }
    } else {
        printf("String contains at least one character invalid for Roman numerals.\n");
    }
    
    return 0;
}