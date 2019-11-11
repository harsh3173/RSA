RSA Encryption/Decryption Program
Author :- Harsh Wadhawe


  Create encryption & decryption keys:

    1. Enter two distinctive (greater than 10) primes p and q
    2. Enter an integer e so that gcd(e,phi(n)) = 1
    3. Use the Public encryption key to encrypt messages.
    4. Use the Private decryption key to decrypt messages.

  RSA Encryption:
	./en (name of file to be encrypted) (name of file where encrypted text should be stored)  
    1. Enter e and n values in the Public encryption key
    2. Enter message to be encrypted (< 1000000 chars)
    3. Record the ciphered text info
    4. Record the number of characters in the text

  RSA Decryption:
	./de (name of encrypted file) (name of file where decrypted text should be stored)  
    1. Enter d and n values in the Private decryption key
    2. Enter the number of chars in the encrypted text
    3. Enter the each chars in the encrypted text
