#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_crypto.h"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    
    //One-Time-Pad
    char* text;
    printf("[OTP] input: ");
    scanf("%ms", &text); //Using %ms it allocates as much memory as it is needed for the particular

    int numberOfBytes;
    numberOfBytes = (int)strlen(text); //Firstly, I will use strlen function that calculates the length of the given string

    char* randomKey;  //Allocating memory for the key we will use
    randomKey = (char*)malloc(numberOfBytes*sizeof(char));
    int fp = open("/dev/urandom", O_RDONLY);
    read(fp, randomKey, strlen(text));
    close(fp);
    oneTimePad(text, randomKey);
    //free(text);
    free(randomKey);

    //Caesar's Cipher
    char* caesarText;
    printf("[Caesars] input: ");
    scanf("%ms", &caesarText);

    int keyNumber;
    printf("[Caesars] key: ");
    scanf("%d", &keyNumber);
    caesarAlgorithm(caesarText, keyNumber);
    free(caesarText);

    //Vigenere's Cipher
    char* vinText;
    printf("[Vigenere] input: ");
    scanf("%ms", &vinText);

    char* keyWord;
    printf("[Vigenere] key: ");
    scanf("%ms", &keyWord);
    vigenereAlgorithm(vinText, keyWord);
    free(vinText);
    free(keyWord);
}