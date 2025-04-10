# Simple Crypto - Encryption Algorithms

This project demonstrates the implementation of **encryption algorithms** in **C**. The algorithms included are:

1. **One-Time Pad (OTP)**
2. **Caesar Cipher**
3. **Vigenere Cipher**

Each of these algorithms has been implemented with the aim of exploring basic cryptographic principles and providing a hands-on understanding of how they function. The project also features a demo program that allows the user to interact with each encryption algorithm.

---

## 🎓 Project Info

- **Course**: Cyber Security
- **Institution**: Technical University of Crete (TUC)
- **Department**: School of Electrical and Computer Engineering
- **Semester**: Spring 2021
- **Project Type**: Individual assignment
- **Language**: C
- **Platform**: Linux

---

## 🧱 File Structure

| File Name           | Description                                              |
|---------------------|----------------------------------------------------------|
| **simple_crypto.c**  | Library containing the implementations of cipher algorithms |
| **simple_crypto.h**  | Header file with function declarations for the algorithms |
| **demo.c**           | Demo program that demonstrates the use of the cipher functions |
| **Makefile**         | Makefile for building the project                        |
| **Readme.txt**       | This file                                                |

---

## 🚀 Technologies Used

- **C Language** for implementation
- **`/dev/urandom`** for secure random number generation
- **Basic cryptographic techniques**: XOR, ASCII manipulation, shifting characters

---

## 🛠️ Installation

### Prerequisites

To build and run this program, you'll need any Linux distribution.

### Build and Run

```bash
#  Remove the compiled files that were created
make clean

# Compile the code
make [all]

# Run the demo
./demo
```

---

## 📚 Code Documentation

1. **One Time Pad Algorithm**

```c
void oneTimePad(char* text, char* randomKey)
```

The input "text" (which is the plaintext) of the function were given by the user in the main function. The *randomKey* input is created with the use of **/dev/urandom**, which creates a random string of bytes/character of *N* bytes, *N* being the number of characters in the text.

For the encryption of the plain-text, using for-loop, each character of the text is is combined with the corresponding character of the key with XOR operand. The unique characters aren't supposed to be a part of the alphabet of the program, so, to print the result
of the encryption there is an extra part of code where, if the character, that is supposed to be printed, is not a usable character (0-9, A-Z, a-z), using the numbers of ASCII table, an *x* will be printed instead.

For the decryption, the same method is being used as the opposite operand of XOR is again XOR operand.

2. **Caesar's cipher**

```c
void caesarAlgorithm(char* text, int key)
```

For the encryption of the text, there is a need of checking and shifting each byte/character one by one as there was a need to check that the shifting of the characters was made with a circular process, where the numbers 0-9 would shift to capital letters A-Z,
capital letters to lowercase letters a-z and lowercase letters to numbers. So, each character is being shifted one position at time and everytime it is supposed to turn into a unique character, it immediatly changes into a character that is supposed to be in the alphabet that we work in.

The decryption is implemented as the opposite way of the encryption, meaning that now the key will be used to the encrymented text to shift backwards (subtraction). The same circular alpahbet will be used. 

3. **Vigenere's cipher**

```c
void vigenereAlgorithm(char* text, char* key)
```

The key is supposed to be the same length as the text the user gives as input. At the start of the function, if the length of the key doesn't match the length of the text, the key is being repeated as match as it should be to match the length of the input.

For the implementation of this algorithm, two simple equations were used which can express the algorithm in algebraic form:

- **Encryption:**

  $$
  E(i) = (\text{Text}(i) + \text{Key}(i)) \% 26
  $$

- **Decryption:**

 $$
  D(i) = (E(i) - \text{Key}(i) + 26) \% 26
 $$

So, again, using a for-loop, each byte/character is being changed via the equation that is used.
