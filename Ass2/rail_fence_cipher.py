def encrypt(txt, key):
    rail = [['\n' for i in range(len(txt))] for j in range(key)]
    dir_down = False
    row, col = 0, 0
    for i in range(len(txt)):
        if (row == 0) or (row == key-1):
            dir_down = not dir_down
        rail[row][col] = txt[i]
        col += 1
        if dir_down:
            row += 1
        else:
            row -= 1
    res = []
    for i in range(key):
        for j in range(len(txt)):
            if rail[i][j] != '\n':
                res.append(rail[i][j])
    return "".join(res)

def decrypt(txt, key):
    rail = [['\n' for i in range(len(txt))] for j in range(key)]
    dir_down = None
    row, col = 0, 0
    for i in range(len(txt)):
        if row == 0:
            dir_down = True
        if row == key - 1:
            dir_down = False

        rail[row][col] = '*'
        col += 1

        if dir_down:
            row += 1
        else:
            row -= 1
    idx = 0
    for i in range(key):
        for j in range(len(txt)):
            if ((rail[i][j] == '*')) and (idx < len(txt)):
                rail[i][j] = txt[idx]
                idx += 1
    res = []
    row, col = 0,0
    for i in range(len(txt)):
        if row == 0:
            dir_down = True
        if row == key-1:
            dir_down = False

        if (rail[row][col] != '*'):
            res.append(rail[row][col])
            col += 1

        if dir_down:
            row += 1
        else:
            row -= 1
    return("".join(res))

if __name__ == "__main__":
    print(encrypt("problem3", 3))
    print(decrypt(encrypt("problem3", 3), 3))

