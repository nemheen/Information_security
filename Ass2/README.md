# Classic Cipher Practice

This repository contains Python implementations of three classic cipher algorithms: **Affine Cipher**, **Gronsfeld Cipher**, and **Rail Fence Cipher**. The goal is to understand the operation principles behind these ciphers by coding them from scratch without using any cryptographic libraries. Each cipher showcases a unique method for encrypting and decrypting text.

---

## **1. Affine Cipher**

The Affine Cipher encrypts plaintext by applying a mathematical transformation to each character:  
\[
E(x) = (a \cdot x + b) \, \text{mod} \, m
\]  
where `a` and `b` are keys, `x` is the numerical value of a character, and `m` is the size of the alphabet.

- **How it works:**
  - Choose values for `a` and `b` such that `a` is coprime with `m`.
  - The program handles both encryption and decryption, showing how modular arithmetic is used in cryptography.

- **Use Case:** Learn how simple mathematical formulas can secure text and practice modular arithmetic concepts.

---

## **2. Gronsfeld Cipher**

The Gronsfeld Cipher is a number-based variant of the Vigenère Cipher. Instead of using letters as a key, it uses a sequence of numbers to determine how much to shift each character.

- **How it works:**
  - Input a numeric key (e.g., `1234`) and plaintext.
  - The program shifts each character in the plaintext by the corresponding value in the key, repeating the key as necessary.

- **Example:**
  - Plaintext: `gronsfeld`
  - Key: `1234`
  - Ciphertext: `htrrthhpe`

- **Use Case:** Explore how numerical keys are applied in encryption and how this method expands on the concept of Caesar shifts.

---

## **3. Rail Fence Cipher**

The Rail Fence Cipher rearranges text into a zigzag pattern across multiple "rails" (rows). The resulting scrambled text is then read row by row for encryption.

- **How it works:**
  - Specify the plaintext and the number of rails.
  - The program writes the text in a zigzag pattern and reads it row by row for encryption.
  - For decryption, the process is reversed.

- **Use Case:** Visualize how text rearrangement techniques can provide security and practice implementing data structures for reordering characters.

---

## **Features**
- Pure Python implementations—no external libraries required.
- Handles both encryption and decryption for each cipher.
- Easy to run and test with example inputs.

---

## **Running the Code**
1. Clone the repository:
   ```bash
   git clone https://github.com/YourUsername/ClassicCipherPractice.git
   cd ClassicCipherPractice
   ```

2. Enter plaintext and keys as prompted, and the program will display the results.

---

## **Objectives**
- Understand how classic ciphers work through hands-on coding.
- Explore different encryption techniques and their unique principles.
- Build a foundation for understanding more advanced cryptographic algorithms.
