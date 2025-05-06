#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void leak() {
    const char* original = "приклад витоку пам'яті";
    char* duplicated = strdup(original);

    printf("duplicated string: %s\n", duplicated);
}

int main() {
    leak();
    return 0;
}
