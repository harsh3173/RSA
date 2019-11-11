#include<stdio.h>
#include<string.h>
int len;
int text[1000000];

// Find the Greatest Common Divisor between two numbers
int gcd(int num1, int num2) {
    int temp;

    while(num2 > 0) {
        temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }

    return num1;
}

// d = (1/e) mod n
int mod_inverse(int u, int v)
{
    int inv, u1, u3, v1, v3, t1, t3, q;
    int iter;
    /* Step X1. Initialise */
    u1 = 1;
    u3 = u;
    v1 = 0;
    v3 = v;
    /* Remember odd/even iterations */
    iter = 1;
    /* Step X2. Loop while v3 != 0 */
    while (v3 != 0)
    {
        /* Step X3. Divide and "Subtract" */
        q = u3 / v3;
        t3 = u3 % v3;
        t1 = u1 + q * v1;
        /* Swap */
        u1 = v1;
        v1 = t1;
        u3 = v3;
        v3 = t3;
        iter = -iter;
    }
    /* Make sure u3 = gcd(u,v) == 1 */
    if (u3 != 1)
        return 0;   /* Error: No inverse exists */
    /* Ensure a positive result */
    if (iter < 0)
        inv = v - u1;
    else
        inv = u1;
    return inv;
}


// Check if the input number is a prime number or not
int check_prime(int num) {

    if(num == 0 || num == 1) {
        return false;
    }

    // Return true if the number can only divide 1 and itself
    for(int i = 2; i < num; i++) {
        if (num % i == 0 && i != num) {
            return 0;
        }
    }

    return 1;
}

// Check if input e is valid
int check_e(int e,int phi) {

    // e and phi must have gcd of 1, 1 < e < phi
    if(gcd(e,phi) == 1 && e > 1 && e < phi) {
        return 1;
    } else {
        return 0;
    }
}

// The Modular Exponentiation Algorithm
int MEA(int p, int e, int n) {

    int r2 = 1;
    int r1 = 0;
    int Q = 0;
    int R = 0;

    while( e != 0 ) {
        R = (e % 2);
        Q = ((e - R) / 2);

        r1 = ((p * p) % n);

        if(R == 1) {
            r2 = ((r2 * p) % n);
        }
        p = r1;
        e = Q;
    }
    return r2;
}

// Received input from user
void encode(int e,int n,FILE *in,FILE *op) {
    int i = 0;
    char ch;
    while((ch=fgetc(in)) != EOF) {
        text[i] = MEA(ch, e, n);

        len++;
        i++;
    }

    i = 0;
    printf("\n\n");
    for(int i = 0; i < len; i++) {
        fprintf(op,"%d ",text[i]);
    }
}

void decode(int d,int n,FILE *in,FILE *op) {
    printf("\n");
    int x,i=0;
    printf("beforeloop");
    for(i = 0; fscanf(in,"%d",&x) != EOF; i++) {
        text[i] = MEA(x, d, n);
        printf("%c", text[i]);
    }
    len = i;

    printf("\nDeciphered text:\t");

    for(int i = 0; i < len; i++) {

    }

    for(int i = 0; i < len; i++) {
        fprintf(op,"%c",text[i]);
    }
}

// Clears the text array
void clear_input() {
    memset(text,0,sizeof(text));
    len = 0;
}

