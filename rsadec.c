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
    printf("        RSA Decryption Program       \n");

    int selection = 0;
    int p = 0; // Prime 1
    int q = 0; // Prime 2
    int n = 0; // n = p * q;
    int e = 0; // Public exponent
    int d = 0; // d = (1/e) mod (phi)
    int phi = 0; // (p - 1) * (q - 1)

    printf("\nEnter the private decryption key: \n");
    printf("Enter 'd' value: ");
    scanf("%d", &d);
    printf("Enter 'n' value: ");
    scanf("%d", &n);


    decode(d,n,in,op);
    printf("\n\n");
    return 0;
}


