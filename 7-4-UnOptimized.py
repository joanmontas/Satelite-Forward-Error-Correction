# Copyright Joan Montas
# All rights reserved.
# License under GNU General Public License v3.0

import math

def numberOfParityBitsCalulator(m):
    p = 0
    while p * p < p + m + 1:
        p = p + 1
    return p

def isPowerOfTwo(n):
    return math.ceil((math.log2(n))) == math.floor(math.log2(n))

def intToArrayOfBits(n, numberOfBits):
    ar = [0 for i in range(numberOfBits)]
    if int(math.log2(n)) > len(ar):
        raise IndexError(f"Given number does not fit in the given bit field")
    countOfBits = 0
    while n > 0:
        if n % 2 == 1:
            ar[countOfBits] = 1
        else:
            ar[countOfBits] = 0
        countOfBits = countOfBits + 1
        n = n >> 1
    return ar

if __name__ == '__main__':
    # MSB -> LSB
    message = [1, 0, 0, 1]
    message = [1, 0, 1, 1]
    message = [1, 0, 0, 0]
    message = [0, 1, 0, 0]

    # bits sizing
    m = len(message)
    p = numberOfParityBitsCalulator(m)
    nb = m + p
    print(f"m = {m}, p = {p}, nb = {nb}")

    # hamming code
    hamming = ['_' for i in range (nb + 1)]
    hamming[0] = 'x'

    # set non-parity bits on the hamming code
    messageBitLocation = 3
    for i in range(nb, 0, -1):
        if not isPowerOfTwo(i):
            hamming[i] = message[messageBitLocation]
            messageBitLocation = messageBitLocation - 1

    print(f"message-only = {hamming}")

    # generate two-dimentional array
    ar = []
    for i in range(nb, 0, -1):
        if (hamming[i] == 1):
            ar.append(intToArrayOfBits(i, p))

    # Utilize two-dimentional array to calculate parity bits
    generatedParity = []
    for i in range(0, len(ar[0])):
        countOfSetBits = 0
        for j in range(len(ar)):

            if ar[j][i] == 1:
                countOfSetBits = countOfSetBits + 1
        generatedParity.append(countOfSetBits % 2)
    print(f"Generated-parity-bits = {generatedParity}")

    # place generated piraty bits into hamming code
    messageBitLocation = 0
    for i in range(1, nb + 1):
        if isPowerOfTwo(i):
            hamming[i] = generatedParity[messageBitLocation]
            messageBitLocation = messageBitLocation + 1

    # prints MSB -> LSB
    print(f"final-hamming-code = {[hamming[i] for i in range(1, len(hamming))]}")
    print(hamming)
