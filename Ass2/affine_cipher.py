def egcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        g, y, x = egcd(b % a, a)
        return g, x - (b // a) * y, y

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('Modular inverse does not exist')
    else:
        return x % m

def encrypt(pt, k1, k2):
    ciphertext = ''
    for p in pt:
        if p.isalpha():
            ciphertext += chr(((ord(p) - ord('a'))*k1 + k2) % 26 + ord('a'))
        else:
            ciphertext += p
    return ciphertext

def decrypt(ct, k1, k2):
    plain = ''
    k1 = modinv(k1, 26)
    for c in ct:
        if c.isalpha():
            plain += chr((((ord(p) - ord('a')) - k2) * k1) % 26 + ord('a'))
        else:
            plain += p
    return plain

def main():
    str = input()
    n = int(input())
    m = int(input())
    print(encrypt(str, n, m))

if __name__ == "__main__":
    main()
