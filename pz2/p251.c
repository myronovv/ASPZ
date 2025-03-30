#include <stdio.h>

void functionA() {
}

void functionB() {
    functionA();
}

int main() {
    functionB();
    return 0;
}