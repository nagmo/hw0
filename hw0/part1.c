//
//  main.c
//  hw0
//
//  Created by Nevo Agmon on 3/24/17.
//  Copyright © 2017 Nevo Agmon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getNumbers(int inputArr[], int inputSize);
int printPowerOf2(int inputArr[], int inpurSize);

int main() {
    
    fprintf(stdout,"Enter size of input:\n");
    int inputSize;
    if(!scanf(" %d",&inputSize) || inputSize <= 0){
        fprintf(stdout, "Invalid size\n");
        return 0;
    };
    
    int *inputArr = malloc(sizeof(int)*inputSize);
    if(!inputArr) return 0;
    fprintf(stdout, "Enter numbers:\n");
    if(!getNumbers(inputArr, inputSize)) return 0;
    
    int sumOfExponents = printPowerOf2(inputArr,inputSize);
    fprintf(stdout, "Total exponent sum is %d\n", sumOfExponents);
    
    free(inputArr);
    return 0;
}

int getNumbers(int inputArr[], int inputSize){
    for(int i=0; i < inputSize; i++){
        int temp = 0;
        if(!scanf(" %d", &temp)){
            fprintf(stdout, "Invalid number\n");
            return 0;
        };
        inputArr[i] = temp;
    }
    return 1;
}

int printPowerOf2(int inputArr[], int inputSize){
    int sumOfExponents=0;
    for(int i=0; i<inputSize; i++){
        double tempExponent = log2(inputArr[i]);
        if(!(tempExponent - (int)tempExponent)){
            fprintf(stdout, "The number %d is a power of 2: %d = 2^%d\n",
                    inputArr[i], inputArr[i], (int)tempExponent);
            sumOfExponents += (int)tempExponent;
        }
    }
    return sumOfExponents;
}
