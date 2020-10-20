#include "simple_crypto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The first function will be the implemented version of the algorithm One-Time Pad
void oneTimePad(char* text, char* randomKey){
    int numberOfBytes;
    numberOfBytes = strlen(text);

    //Encryption of the plain text
    char* encryptedMessage;
    encryptedMessage = (char*)malloc((numberOfBytes+1)*sizeof(char));
    // ^ is a bitwise operator where it is supposed to perform the XOR operation
    for (int i=0; i<numberOfBytes; i++){
        encryptedMessage[i] = text[i] ^ randomKey[i];
    }
    encryptedMessage[numberOfBytes] = '\0';
    printf("[OTP] encrypted: ");
    for (int i=0; i<numberOfBytes; i++){
        if(!((encryptedMessage[i]>=48 && encryptedMessage[i]<=57) || (encryptedMessage[i]>=65 && encryptedMessage[i]<=90) || (encryptedMessage[i]>=97 && encryptedMessage[i]<=122))){
            printf("x"); //for every non printable characters an x will take its place
        }else{
            printf("%c", encryptedMessage[i]);
        }
    }
    printf("\n");

    //Decryption of the plain text
    char* decryptedMessage;
    decryptedMessage = (char*)malloc((numberOfBytes+1)*sizeof(char));
    for (int i=0; i<numberOfBytes; i++){
        decryptedMessage[i] = encryptedMessage[i] ^ randomKey[i];
    }
    decryptedMessage[numberOfBytes] = '\0';
    printf("[OTP] decrypted: %s\n", decryptedMessage);
    free(encryptedMessage);
    free(decryptedMessage);
}


//Implementation of the Caesar's cipher algorithm
void caesarAlgorithm(char* text, int key){
    int textLength;
    textLength = strlen(text);
    char helper;

    char* encrypted;
    encrypted = (char*)malloc((textLength+1)*sizeof(char));
    for(int i=0; text[i]!='\0'; i++){
        helper = text[i];
        //The whole point of this process is to ignore the unique characters from the ASCII table and make the character set in a way
        //that it will consists 0-9 -> A-Z -> a-z. 
        if((text[i]<=57 && text[i]>=48) || (text[i]>=65 && text[i]<=90) || (text[i]>=97 && text[i]<=122)){
            for(int i=key; i>0; i--){
                if((helper+1)==58){
                    helper = 64;
                }else if(helper+1==91){
                    helper = 96;
                }else if(helper+1==123){
                    helper = 47;
                }
                helper++;
            }
        }
        encrypted[i] = helper;
    }
    encrypted[textLength] = '\0';
    printf("[Caesars] encrypted: %s\n", encrypted);

    char* decrypted;
    decrypted = (char*)malloc((textLength+1)*sizeof(char));
    for(int i=0; encrypted[i]!='\0'; i++){
        helper = encrypted[i];
        if((encrypted[i]<=57 && encrypted[i]>=48) || (encrypted[i]>=65 && encrypted[i]<=90) || (encrypted[i]>=97 && encrypted[i]<=122)){
            for(int i=key; i>0; i--){
                if((helper-1)==47){
                    helper = 123;
                }else if(helper-1==64){
                    helper = 58;
                }else if(helper-1==96){
                    helper = 91;
                }
                helper--;
            }
        }
        decrypted[i] = helper;
    }
    decrypted[textLength] = '\0';
    printf("[Caesars] decrypted: %s\n", decrypted);
    free(encrypted);
    free(decrypted);
}


//Implementation of the Vigenere's cipher algorithm
void vigenereAlgorithm(char* text, char* key){
    //Firstly, I am going to expand the key so its length matches the length of the plaintext
    int textLength = strlen(text);
    char* keyWord;
    keyWord = (char*)malloc((textLength+1)*sizeof(char));
    int keyLength = strlen(key);
    keyWord = key;
    if(textLength!=keyLength){
        int counter=0;
        for(int i=keyLength; i<textLength; i++){
            keyWord[i] = key[counter];
            counter++;
        }
    }

    //According to articles, the Vigenere's cipher algorithm can be expressed in algebraic form, using
    //the equation Ei = (Text(i)+Key(i))%26 for encryption and Di = (E(i)-Key(i)+26)%26 for decryption
    char* encryptedText;
    encryptedText = (char*)malloc((textLength+1)*sizeof(char));
    for(int i=0; i<textLength; i++){
        encryptedText[i] = (text[i]+keyWord[i])%26+'A';
    }
    encryptedText[textLength] = '\0';
    printf("[Vigenere] encrypted: %s\n", encryptedText);

    char* decryptedText;
    decryptedText = (char*)malloc((textLength+1)*sizeof(char));
    for(int i=0; i<textLength; i++){
        decryptedText[i] = ((encryptedText[i]-keyWord[i]+26)%26)+'A';
    }
    decryptedText[textLength] = '\0';
    printf("[Vigenere] decrypted: %s\n", decryptedText);
    free(encryptedText);
    free(decryptedText);
}




