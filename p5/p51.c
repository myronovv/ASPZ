#include <stdio.h>
#include <string.h>

struct A {
    int x;
    char y;
};

struct B {
    int x;
    char y;
    int z;
};

int main() {
    struct A a = {42, 'a'};
    struct B b = {0};

    printf("Before :\n");
    printf("b.x = %d, b.y = %c, b.z = %d\n", b.x, b.y, b.z);

    memcpy(&b, &a, sizeof(struct A)); 

    printf("After :\n");
    printf("b.x = %d, b.y = %c, b.z = %d\n", b.x, b.y, b.z);

    return 0;
}
