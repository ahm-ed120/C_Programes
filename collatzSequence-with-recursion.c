#include <stdio.h>
void collatzSequence(int number) {
    printf("%d ", number);
    if (number == 1) {
        return; 
    } else if (number % 2 == 0) {
        collatzSequence(number / 2); 
    } else {
        collatzSequence(number * 3 + 1);  
    }
}

int main() {
    int start = 3;
    printf("Collatz sequence starting from %d:\n", start);
    collatzSequence(start);
    printf("\n");  

    return 0;
}
