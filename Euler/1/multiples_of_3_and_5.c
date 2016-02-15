#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long fizzbuzz(long n) {
    long n_three = 0;
    long n_five = 0;
    long n_fifteen = 0;
    long max_three = 0;
    long max_five = 0;
    long max_fifteen = 0;
    if (n > 3) {
        n_three = (n - 4) / 3 + 1;
        max_three = 3 + (n_three - 1) * 3;
    }
    if (n > 5) {
        n_five = (n - 6) / 5 + 1;
        max_five = 5 + (n_five - 1) * 5;
    }
    if (n > 15) {
        n_fifteen = (n - 16) / 15 + 1;
        max_fifteen = 15 + (n_fifteen - 1) * 15;
    }
    
    return n_three * (max_three + 3) / 2 + n_five * (max_five + 5) / 2 - n_fifteen * (max_fifteen + 15) / 2;
}

int main() {
    int T;
    int N;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        printf("%ld\n", fizzbuzz(N)); 
    }
    return 0;
}
