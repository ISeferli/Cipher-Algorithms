------------------------
Assignment 1
Course: HPY 414
Seferli Iliodora 2017030094
------------------------

------------------------
I. File List           
------------------------
simple_crypto.c  Library with all the cipher algorithms implemented
simple_crypto.h  C Function declarations of the algorithms
demo.c           A demo program where the functions are used
Makefile         Makefile of the program
Readme.txt       This File

------------------------
II. Requirements
------------------------
any Linux distribution


------------------------
III. Compilation
------------------------
make [all]  - to buld both simple_crypto.c and demo.
make clean  - to remove the compiled files that were created

------------------------
IV. Execution
------------------------
./demo

------------------------
V. Design
------------------------
A. One Time Pad Algorithm 
void oneTimePad(char* text, char* randomKey)

The input "text" (which is the plaintext) of the function were given by the user in 
the main function. The "randomKey" input is created with the use of /dev/urandom, which
creates a random string of bytes/character of N bytes, N being the number of characters
in the text.
For the encryption of the plain-text, using for-loop, each character of the text is 
is combined with the corresponding character of the key with XOR operand. The unique
characters aren't supposed to be a part of the alphabet of the program, so, to print the result
of the encryption there is an extra part of code where, if the character, that is supposed to
be printed, is not a usable character (0-9, A-Z, a-z), using the numbers of ASCII table,
an 'x' will be printed instead.
For the decryption, the same method is being used as the opposite operand of XOR is again
XOR operand.

B. Caesar's cipher
void caesarAlgorithm(char* text, int key)

For the encryption of the text, there is a need of checking and shifting each byte/character
one by one as there was a need to check that the shifting of the characters was made
with a circular process, where the numbers 0-9 would shift to capital letters A-Z,
capital letters to lowercase letters a-z and lowercase letters to numbers. So, each
character is being shifted one position at time and everytime it is supposed to turn into
a unique character, it immediatly changes into a character that is supposed to be in the
alphabet that we work in.
The decryption is implemented as the opposite way of the encryption, meaning that now the key
will be used to the encrymented text to shift backwards (subtraction). The same circular
alpahbet will be used. 

C. Vigenere's cipher
void vigenereAlgorithm(char* text, char* key)

The key is supposed to be the same length as the text the user gives as input. At the start of the 
function, if the length of the key doesn't match the length of the text, the key is being repeated
as match as it should be to match the length of the input.
For the implementation of this algorithm, two simple equations were used which can express the 
algorithm in algebraic form (Ei = (Text(i)+Key(i))%26 for encryption and Di = (E(i)-Key(i)+26)%26 for decryption).
So, again, using a for-loop, each byte/character is being changed via the equation that is used.
