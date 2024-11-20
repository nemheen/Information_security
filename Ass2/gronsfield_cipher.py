def generateKey(string, key):
    key = list(key)
    if len(string) == len(key):
        return key
    else:
        for i in range(len(string) - len(key)):
            key.append(key[i % len(key)])
    return key

def cipherText(string, key):
    cipher_text = []
    for i in range(len(string)):
        if key[i].isalpha():
            x = (ord(string[i]) + ord(key[i])) % 26
        else:
            x = (ord(string[i]) - ord('a') + int(key[i]))%26
        x += ord('a')
        cipher_text.append(chr(x))
    return ''.join(cipher_text)

def originalText(cipher_text, key):
    orig_text = []
    for i in range(len(cipher_text)):
        if key[i].isalpha():
            x = (ord(cipher_text[i]) - ord(key[i]) + 26) % 26
        else:
            x = ((ord(cipher_text[i]) - ord('a')) - int(key[i]))%26
        x += ord('a')
        orig_text.append(chr(x))
    return ''.join(orig_text)

if __name__ == "__main__":
    string = input().lower()
    key = input().lower()
    key = generateKey(string, key)
    cipher_text = cipherText(string, key)
    print("Ciphertext:", cipher_text)
    print("Original/Decrypted Text:", originalText(cipher_text, key))
