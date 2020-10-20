//Here we will have the documentation of the program

/**
    @brief Implement the algorithm One-Time-Pad. With this algorithm, each byte/character of the
    plaintext is compined (with XOR operand) with the corresponding byte/character from the random
    key. The random key will be generated via /dev/urandom.

    @param text This is supposed to be the plaintext that the user has put as input
    to encrypt and decypher with this certain algorithm. This input will be given by the
    user in the demo.

    @param randomKey The key is supposed to be the random stream that we get from the use 
    of /dev/urandom where it will be used for XOR operation with the input of the user 

    @returns Void function
*/
void oneTimePad(char* text, char* randomKey);


/**
    @brief Implement the algorithm Caesar's cipher. In this algorithm, each byte/character
    of the plaintext is replaced by a character/byte found at some fixed number of positions
    down the alphabet/ASCII set. For the ecryption, each byte/character of the plaintext will be
    incremented by the number(key) that the user will give as input and for the decryption, the
    ecrypted text will be used and will be decremented by the same number.

    @param text This is supposed to be the plaintext that the user has put as input
    to encrypt and decypher with this certain algorithm. This input will be given by the
    user in the demo.

    @param key The key for this algorithm is supposed to be the number which we will use
    to shift each character of the text that the user gives as input.

    @returns Void function
*/
void caesarAlgorithm(char* text, int key);


/**
    @brief Implement the algorithm Vigenere's Cipher

    @param text This is supposed to be the plaintext that the user has put as input
    to encrypt and decypher with this certain algorithm. This input will be given by the
    user in the demo.

    @param key The key is a string where it will be made to match the length of the text.

    @returns Void function
*/
void vigenereAlgorithm(char* text, char* key);