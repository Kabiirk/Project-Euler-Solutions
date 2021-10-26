'''
Problem 59
Each character on a computer is assigned a unique code and the preferred
standard is ASCII (American Standard Code for Information Interchange).
For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to
ASCII, then XOR each byte with a given value, taken from a secret key.
The advantage with the XOR function is that using the same encryption key
on the cipher text, restores the plain text; for example, 65 XOR 42 = 107,
then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text
message, and the key is made up of random bytes. The user would keep the
encrypted message and the encryption key in different locations, and without
both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified
method is to use a password as a key. If the password is shorter than the
message, which is likely, the key is repeated cyclically throughout the message.
The balance for this method is using a sufficiently long password key for security,
but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower
case characters. Using p059_cipher.txt (right click and 'Save Link/Target As...'),
a file containing the encrypted ASCII codes, and the knowledge that the plain
text must contain common English words, decrypt the message and find the sum
of the ASCII values in the original text.

Answer : 129448
'''

'''
TIPS:
The solution was obtained by frequency analysis of alphabets that gave valid XOR results
for respective rotated message elements

Note : the key & Decrypted message was initially a religious text, but was changed
due to issues and is now  as follows :
Old Key:
god

New Key:
exp

New Decrypted Text :
"An extract taken from the introduction of one of Euler's most celebrated papers,
"De summis serierum reciprocarum" [On the sums of series of reciprocals]:
I have recently found, quite unexpectedly, an elegant expression for the entire
sum of this series 1 + 1/4 + 1/9 + 1/16 + etc., which depends on the quadrature
of the circle, so that if the true sum of this series is obtained, from it at
once the quadrature of the circle follows. Namely, I have found that the sum of
this series is a sixth part of the square of the perimeter of the circle whose
diameter is 1; or by putting the sum of this series equal to s, it has the ratio
sqrt(6) multiplied by s to 1 of the perimeter to the diameter. I will soon show
that the sum of this series to be approximately 1.644934066842264364; and from
multiplying this number by six, and then taking the square root, the number 3.141592653589793238
is indeed produced, which expresses the perimeter of a circle whose diameter is 1.
Following again the same steps by which I had arrived at this sum, I have discovered
that the sum of the series 1 + 1/16 + 1/81 + 1/256 + 1/625 + etc. also depends on the
quadrature of the circle. Namely, the sum of this multiplied by 90 gives the
biquadrate (fourth power) of the circumference of the perimeter of a circle 

whose diameter is 1. And by similar reasoning I have likewise been able to
determine the sums of the subsequent series in which the exponents are even numbers."

older text can still be viewed at these solution links but would give the wrong answer :
https://radiusofcircle.blogspot.com/2016/06/problem-59-project-euler-solution-with-python.html
https://www.mathblog.dk/project-euler-59-xor-encryption/

The reason for he change was as follows :
Please note that the cipher text for this problem was replaced on Tuesday 5 February 2019.

When the original text was chosen there were three criteria:
1. Uses simple English words.
2. No copyright restrictions.
3. Contains a typical distribution of common words and letter frequencies.

For this reason the original text was an extract taken from the New Testament and the key was "god".

Team Project Euler did not want members of different religions to feel uncomfortable being exposed to a text from
another religion and similarly they did not wish Christians to feel offended that their sacred text
was being used in a less than reverent context.

'''

from itertools import product

ascii_lowercase = 'abcdefghijklmnopqrstuvwxyz'
keywords = [''.join(i) for i in product(ascii_lowercase, repeat = 3)]
# print(keywords) ['aaa', 'aab', 'aac', 'aad',....'zzx', 'zzy', 'zzz' ]

def check_valid_alphabet(cipher_letter, english_letter):
    xor = cipher_letter ^ english_letter
    if 32 <= xor and xor <= 90:
        return True
    elif 97 <= xor and xor <= 122:
        return True
    return False

def decrypt(message, key):
    decoded_mssg = []
    for i in range(0, len(message)):
        decoded_mssg.append(message[i]^key[i%len(key)])

    total = sum(decoded_mssg)
    # convert array to string
    decoded_mssg = ''.join(chr(j) for j in decoded_mssg)

    return decoded_mssg, total


# Read file
with open('p059_cipher.txt') as f:
    lines = f.readlines()[0]
    cipher = list(map(int, lines.split(',')))

    f.close()

# Lowercase ascii eng letters
ascii_eng_letters = list(range(97, 123))

letter1 = {}
for j in ascii_eng_letters:
    letter1[str(j)] = 1
    for i in range(0, len(cipher), 3):
        if check_valid_alphabet(cipher[i], j):
            letter1[str(j)]+=1
letter2 = {}
for j in ascii_eng_letters:
    letter2[str(j)] = 1
    for i in range(1, len(cipher), 3):
        if check_valid_alphabet(cipher[i], j):
            letter2[str(j)]+=1
letter3 = {}
for j in ascii_eng_letters:
    letter3[str(j)] = 1
    for i in range(2, len(cipher), 3):
        if check_valid_alphabet(cipher[i], j):
            letter3[str(j)]+=1

l1 = int(max(letter1, key=letter1.get))
l2 = int(max(letter2, key=letter2.get))
l3 = int(max(letter3, key=letter3.get))

key = [l1, l2, l3]

mssg, total = decrypt(cipher, key)

# key = ''.join(chr(j) for j in key)
# print(key) # exp
print(total)
print(mssg)