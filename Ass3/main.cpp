#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <bitset>
#include "des.h"

#define BLOCK_MODE 1

using namespace std;

#define BLOCK_SIZE 8
#define DES_ROUND 16

typedef unsigned char BYTE;
typedef unsigned int UINT;
typedef unsigned long long UINT64;

void DES_CBC_Enc(BYTE *p_text, BYTE *c_text, BYTE *IV, BYTE *key, int msg_len);
void DES_CBC_Dec(BYTE *c_text, BYTE *d_text, BYTE *IV, BYTE *key, int msg_len);
void DES_CFB_Enc(BYTE *p_text, BYTE *c_text, BYTE *IV, BYTE *key, int msg_len);
void DES_CFB_Dec(BYTE *c_text, BYTE *d_text, BYTE *IV, BYTE *key, int msg_len);
void DES_OFB_Enc(BYTE *p_text, BYTE *c_text, BYTE *IV, BYTE *key, int msg_len);
void DES_OFB_Dec(BYTE *c_text, BYTE *d_text, BYTE *IV, BYTE *key, int msg_len);
void DES_CTR_Enc(BYTE *p_text, BYTE *c_text, UINT64 ctr, BYTE *key, int msg_len);
void DES_CTR_Dec(BYTE *c_text, BYTE *d_text, UINT64 ctr, BYTE *key, int msg_len);
void print_hex(BYTE* data, int length);


void DES_CBC_Enc(BYTE *p_text, BYTE *c_text, BYTE *IV, BYTE *key, int msg_len) {
    BYTE block[BLOCK_SIZE], temp[BLOCK_SIZE];
    memcpy(temp, IV, BLOCK_SIZE); //copying from IV to temp 

    for (int i = 0; i < msg_len; i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = p_text[i + j] ^ temp[j];
        }
        DES_Encryption(block, temp, key);
        memcpy(c_text + i, temp, BLOCK_SIZE);
    }
}
void DES_CBC_Dec(BYTE *c_text, BYTE *d_text, BYTE *IV, BYTE *key, int msg_len) {
    BYTE block[BLOCK_SIZE], temp[BLOCK_SIZE], prev_block[BLOCK_SIZE];
    memcpy(temp, IV, BLOCK_SIZE); // Copy IV to temp

    for (int i = 0; i < msg_len; i += BLOCK_SIZE) {
        // Save current ciphertext block
        memcpy(prev_block, c_text + i, BLOCK_SIZE);

        // Decrypt current ciphertext block
        DES_Decryption(c_text + i, block, key);

        // XOR decrypted block with previous ciphertext block or IV
        for (int j = 0; j < BLOCK_SIZE; j++) {
            d_text[i + j] = block[j] ^ temp[j];
        }

        // Update temp to the current ciphertext block for the next iteration
        memcpy(temp, prev_block, BLOCK_SIZE);
    }
}


void DES_CFB_Enc(BYTE *p_text, BYTE *c_text, BYTE *IV, BYTE *key, int msg_len, int feedback_bits) {
    BYTE temp[BLOCK_SIZE], tempOut[BLOCK_SIZE];
    memcpy(temp, IV, BLOCK_SIZE);
    int feedback_bytes = feedback_bits / 8;

    for (int i = 0; i < msg_len; i += feedback_bytes) {
        // Encrypt the temp buffer to get the output
        DES_Encryption(temp, tempOut, key);

        // XOR the feedback size bytes of plaintext with tempOut to get the ciphertext
        for (int j = 0; j < feedback_bytes && (i + j) < msg_len; j++) {
            c_text[i + j] = p_text[i + j] ^ tempOut[j];
        }

        // Shift the temp buffer left by the feedback size and insert the new ciphertext bytes
        memmove(temp, temp + feedback_bytes, BLOCK_SIZE - feedback_bytes);
        memcpy(temp + (BLOCK_SIZE - feedback_bytes), c_text + i, feedback_bytes);
    }
}

void DES_CFB_Dec(BYTE *c_text, BYTE *d_text, BYTE *IV, BYTE *key, int msg_len, int feedback_bits) {
    BYTE temp[BLOCK_SIZE], tempOut[BLOCK_SIZE];
    int feedback_bytes = feedback_bits / 8;
    memcpy(temp, IV, BLOCK_SIZE);

    for (int i = 0; i < msg_len; i += feedback_bytes) {
        // Encrypt the temp buffer to get the output
        DES_Encryption(temp, tempOut, key);

        // XOR the feedback size bytes of ciphertext with tempOut to get the plaintext
        for (int j = 0; j < feedback_bytes && (i + j) < msg_len; j++) {
            d_text[i + j] = c_text[i + j] ^ tempOut[j];
        }

        // Shift the temp buffer left by the feedback size and insert the new ciphertext bytes
        memmove(temp, temp + feedback_bytes, BLOCK_SIZE - feedback_bytes);
        memcpy(temp + (BLOCK_SIZE - feedback_bytes), c_text + i, feedback_bytes);
    }
}


void DES_OFB_Enc(BYTE *p_text, BYTE *c_text, BYTE *IV, BYTE *key, int msg_len, int feedback_bits) {
    BYTE temp[BLOCK_SIZE], tempOut[BLOCK_SIZE];
    memcpy(temp, IV, BLOCK_SIZE);
    int feedback_bytes = feedback_bits / 8;

    for (int i = 0; i < msg_len; i += feedback_bytes) {
        // Encrypt the temp buffer to get the output
        DES_Encryption(temp, tempOut, key);

        // Shift the temp buffer left by the feedback size and insert the new output bytes
        memmove(temp, temp + feedback_bytes, BLOCK_SIZE - feedback_bytes);
        memcpy(temp + (BLOCK_SIZE - feedback_bytes), tempOut, feedback_bytes);

        // XOR the feedback size bytes of plaintext with tempOut to get the ciphertext
        for (int j = 0; j < feedback_bytes && (i + j) < msg_len; j++) {
            c_text[i + j] = p_text[i + j] ^ tempOut[j];
        }
    }
}

void DES_OFB_Dec(BYTE *c_text, BYTE *d_text, BYTE *IV, BYTE *key, int msg_len, int feedback_bits) {
    BYTE temp[BLOCK_SIZE], tempOut[BLOCK_SIZE];
    memcpy(temp, IV, BLOCK_SIZE);
    int feedback_bytes = feedback_bits / 8;

    for (int i = 0; i < msg_len; i += feedback_bytes) {
        // Encrypt the temp buffer to get the output
        DES_Encryption(temp, tempOut, key);

        // Shift the temp buffer left by the feedback size and insert the new output bytes
        memmove(temp, temp + feedback_bytes, BLOCK_SIZE - feedback_bytes);
        memcpy(temp + (BLOCK_SIZE - feedback_bytes), tempOut, feedback_bytes);

        // XOR the feedback size bytes of ciphertext with tempOut to get the plaintext
        for (int j = 0; j < feedback_bytes && (i + j) < msg_len; j++) {
            d_text[i + j] = c_text[i + j] ^ tempOut[j];
        }
    }
}

void increment_counter(BYTE *ctr, int size) {
    for (int i = size - 1; i >= 0; --i) {
        if (++ctr[i] != 0) break;
    }
}

void DES_CTR_Enc(BYTE *p_text, BYTE *c_text, BYTE *ctr, BYTE *key, int msg_len) {
    BYTE temp[BLOCK_SIZE], tempOut[BLOCK_SIZE];
    BYTE local_ctr[BLOCK_SIZE];
    memcpy(local_ctr, ctr, BLOCK_SIZE);

    for (int i = 0; i < msg_len; i += BLOCK_SIZE) {
        // Copy the current counter value to temp
        memcpy(temp, local_ctr, BLOCK_SIZE);

        // Encrypt the counter value
        DES_Encryption(temp, tempOut, key);

        // XOR the plaintext with the encrypted counter value to get the ciphertext
        for (int j = 0; j < BLOCK_SIZE && (i + j) < msg_len; j++) {
            c_text[i + j] = p_text[i + j] ^ tempOut[j];
        }

        // Increment the counter
        increment_counter(local_ctr, BLOCK_SIZE);
    }
}

void DES_CTR_Dec(BYTE *c_text, BYTE *d_text, BYTE *ctr, BYTE *key, int msg_len) {
    BYTE temp[BLOCK_SIZE], tempOut[BLOCK_SIZE];
    BYTE local_ctr[BLOCK_SIZE];
    memcpy(local_ctr, ctr, BLOCK_SIZE);

    for (int i = 0; i < msg_len; i += BLOCK_SIZE) {
        // Copy the current counter value to temp
        memcpy(temp, local_ctr, BLOCK_SIZE);

        // Encrypt the counter value
        DES_Encryption(temp, tempOut, key);

        // XOR the ciphertext with the encrypted counter value to get the plaintext
        for (int j = 0; j < BLOCK_SIZE && (i + j) < msg_len; j++) {
            d_text[i + j] = c_text[i + j] ^ tempOut[j];
        }

        // Increment the counter
        increment_counter(local_ctr, BLOCK_SIZE);
    }
}
void print_hex(BYTE* data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main()
{
    int i, feedback = 8;
    BYTE p_text[128]={0,};
    BYTE key[9]={0,};
    BYTE IV[9]={0,};
    BYTE c_text[128]={0,};
    BYTE d_text[128]={0,};
    int msg_len, msg_len_d;
    UINT64 counter_value=0x661f98cd37a38b4b;
    BYTE ctr[BLOCK_SIZE] = {
        (BYTE)(counter_value >> 56),
        (BYTE)(counter_value >> 48),
        (BYTE)(counter_value >> 40),
        (BYTE)(counter_value >> 32),
        (BYTE)(counter_value >> 24),
        (BYTE)(counter_value >> 16),
        (BYTE)(counter_value >> 8),
        (BYTE)(counter_value)
    };

	strcpy((char*)p_text, "Computer Security");
    strcpy((char*)key, "security");
    strcpy((char*)IV, "iloveyou");

    msg_len = (strlen((char *)p_text) % BLOCK_SIZE) ? ((strlen((char *)p_text) / BLOCK_SIZE + 1) * 8) 
                                                    : strlen((char *)p_text);
    if (BLOCK_MODE == 1)
        DES_CBC_Enc(p_text, c_text, IV, key, msg_len); // DES-CBC encryption
    else if (BLOCK_MODE == 2)
        DES_CFB_Enc(p_text, c_text, IV, key, msg_len, feedback); // DES-CFB encryption
    else if (BLOCK_MODE == 3)
        DES_OFB_Enc(p_text, c_text, IV, key, msg_len, feedback); // DES-OFB encryption
    else
        DES_CTR_Enc(p_text, c_text, ctr, key, msg_len); // DES-CTR encryption

    
	printf("\nBlock Mode: %d", BLOCK_MODE);
    printf("\nPlain text: %s", p_text);
    printf("\nms_len: %d", msg_len);
	printf("\nCipher text: ");
    print_hex(c_text, msg_len);
    // for(i=0; i<msg_len; i++)
    //     printf("%c", c_text[i]);
    // printf("\n");

    if(BLOCK_MODE==1)
    	DES_CBC_Dec(c_text, d_text, IV, key, msg_len);//DES-CBC Decryption
    else if (BLOCK_MODE==2)
    	DES_CFB_Dec(c_text, d_text, IV, key, msg_len, feedback);//DES-CFB Decryption
    else if (BLOCK_MODE==3)
    	DES_OFB_Dec(c_text, d_text, IV, key, msg_len, feedback);//DES-CFB Decryption
    else
    	DES_CTR_Dec(c_text, d_text, ctr, key, msg_len);//DES-CTR Decryption

    // /* Output of decrypted message */
    msg_len_d = (strlen((char *)d_text) % BLOCK_SIZE) ? ((strlen((char *)d_text) / BLOCK_SIZE + 1) * 8) 
                                                    : strlen((char *)d_text);
    printf("\nms_len_d: %d", msg_len_d);
    printf("\nDecrypted message: ");
	//print_hex(d_text, msg_len_d);
    for(i=0; i<msg_len_d; i++)
        printf("%c", (char(d_text[i])));
    printf("\n");

    return 0;
}
