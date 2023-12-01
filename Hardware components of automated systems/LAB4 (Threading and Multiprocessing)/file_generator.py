import os
from string import ascii_letters as letters
from string import digits
from random import choice

ABC = f'{letters}{digits}'
SIZE_TABLE = {'B': 1, 'KB': 1024, 'MB': 1024 * 1024}


def fill(size=1, suff='MB', encoding='utf-8'):
    fileName = ''.join(choice(ABC) for n in range(8))
    writeString = bytes('', encoding=encoding)
    while len(writeString) < SIZE_TABLE[suff] * size:
        writeString += bytes(choice(ABC), encoding=encoding)
    tempFile = open(fileName, 'wb+')
    tempFile.write(writeString)
    tempFile.close()
    os.remove(os.path.join(os.getcwd(), fileName))
