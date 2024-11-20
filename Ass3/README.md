# DES Block Cipher Modes Implementation

Given des.h acts as a header file to the main.cpp where I have implemented 4 pairs of encryption and decryption functions along side main() where it reads the number of mode and runs the corresponding functions.

### Features:
- **DES CBC (Cipher Block Chaining) Mode**: Chaining mechanism where each plaintext block is XORed with the previous ciphertext block before encryption.
- **DES CFB (Cipher Feedback) Mode**: Converts DES into a self-synchronizing stream cipher with feedback-dependent block processing.
- **DES OFB (Output Feedback) Mode**: Converts DES into a synchronous stream cipher using feedback derived from the previous encryption output.
- **DES CTR (Counter) Mode**: Operates as a stream cipher by encrypting incremented counters and XORing them with plaintext.

### Functionality:
1. **Encryption**: The plaintext is encrypted using the chosen DES mode.
2. **Decryption**: The ciphertext is decrypted to retrieve the original plaintext.
3. **Modes Supported**: Switch between modes using the `BLOCK_MODE` macro in the code:
   - `1`: CBC
   - `2`: CFB
   - `3`: OFB
   - `4`: CTR

### Key Elements:
- **Key**: A fixed 8-byte key used for DES encryption.
- **IV (Initialization Vector)**: An 8-byte IV used in CBC, CFB, and OFB modes to ensure randomness.
- **Counter**: A unique counter value used in CTR mode.

## How to run

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/DES-Block-Modes.git
   ```
2. Open the `main.cpp` file in your preferred IDE or text editor.
3. Modify the `BLOCK_MODE` macro to select the desired mode of operation.
4. Compile the code using a C++ compiler:
   ```bash
   g++ -o des_modes main.cpp des.cpp
   ```
5. Run the executable:
   ```bash
   ./des_modes
   ```

## Example Output
For **CBC Mode** with the following inputs:
- Plaintext: `Computer Security`
- Key: `security`
- IV: `iloveyou`

**Output:**
```plaintext
Block Mode: 1
Plain text: Computer Security
ms_len: 16
Cipher text: 4d5a6f2c...
Decrypted message: Computer Security
```
