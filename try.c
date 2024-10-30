#include <math.h>
#include <stdio.h>
#include<string.h>

int getBits(char x[], char y[]) {
    int sizeX = (int)strlen(x);
    int sizeY = (int)strlen(y);
    int arrX[sizeX]; 
    int arrY[sizeY]; 
    int sumX=0;
    int sumY=0;
    for(int i=0;i<sizeX;i++) {
        arrX[i]=(int)x[i]-48;
            if(arrX[i]==1) {
                sumX+=pow(2,sizeX-1-i);
        }
    }
    printf("First Number Value: %d\n", sumX);
    for(int i=0;i<sizeY;i++) {
        arrY[i]=(int)y[i]-48;
            if(arrY[i]==1) {
                sumY+=pow(2,sizeY-1-i);
        }
    }
    printf("Second Number Value: %d\n", sumY);
    long long int decimalValue=(long long int)sumX*sumY;
    printf("Multiplied Value in Decimals: %lld\n", decimalValue);
    int bits=1;
    while(decimalValue>pow(2,bits)-1) {
        bits++;
    }
return bits;
}

int main() {
    // create a string to take in the bits
    char x[100];
    char y[100];
    int availableBits;
    printf("Enter the SIZE of your register (in BITS): ");
    scanf("%d", &availableBits);
    printf("Enter First Binary Number: ");
    scanf("%s", x);
    printf("Enter Second Binary Number: ");
    scanf("%s", y);
    int bitsRequired  = getBits(x, y);
    printf("The number of bits you need (MIN): %d\n", bitsRequired);
    if(availableBits<bitsRequired) {
        printf("Caution: Result might flow out of range. You need to use MULL / More than 1 registers to store the output");
    }
    else {
        printf("In range.");
    }
    return 0;
}