#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "rsa.c"
int len = 0;
int text[1000000];

int main(int argc, char* argv[]) {

    if(argc!=3) {
        errno=EINVAL;
        perror("Bad Arguments");
        return errno;
    }

    FILE *in=fopen(argv[1],"r");
    FILE *op=fopen(argv[2],"w");


    if (in== NULL) {
        printf("\nError reading file!\n");
    }

    if (op == NULL) {
        printf("\nError writing file!\n");
    }
    // Header
    printf("\n");
    printf("        RSA (Encryption/ Decryption) Program       \n");

    int selection = 0;
    int p = 0; // Prime 1
    int q = 0; // Prime 2
    int n = 0; // n = p * q;
    int e = 0; // Public exponent
    int d = 0; // d = (1/e) mod (phi)
    int phi = 0; // (p - 1) * (q - 1)

    int valid_input = 1;

//Encryption
    do {
        printf("\nEnter the first prime number: ");
        scanf("%d", &p);

        if(check_prime(p) == 0) {
            valid_input = 0;

            printf("The number entered is not a prime number. Try again.\n");
        } else {
            valid_input = 1;
        }

    } while(valid_input == 0);

    do {
        printf("\nEnter the second prime number: ");
        scanf("%d", &q);

        if(check_prime(q) == 0) {
            valid_input = 0;
            printf("The number entered is not a prime number. Try again.\n");
        } else {
            valid_input = 1;
        }

    } while(valid_input == 0);

    n = p * q;
    phi = (p-1)*(q-1);


    // For testing (Shows value of n & phi
    do {
        printf("\nEnter a value for public exponent 'e': ");
        scanf("%d", &e);

        if(check_e(e,phi) == 0) {
            valid_input = 0;
            printf("The 'e' value is not compatible. Try again.\n");
        } else {
            valid_input = 1;
        }

    } while(valid_input == 0);

    d = mod_inverse(e, phi);

    printf("  Public encryption key: \n");
    printf("    e = %d\n", e);
    printf("    n = %d\n", n);
    printf("\n");

    printf("  Private decryption key: \n");
    printf("    d = %d\n", d);
    printf("    n = %d", n);
    printf("\n\n");

    encode(e,n,in,op);

    printf("\n  Total number of characters: %d", len);
    printf("\n\n");
    clear_input();
    fclose(in);
    fclose(op);
    return 0;
}


