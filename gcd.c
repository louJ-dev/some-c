#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while(b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    int a = 100;
    int b = 1000000;
    
    int result = gcd(a, b);

    printf("%i\n", result);
    return 0;
}
