#include <stdio.h>
#include <string.h>

int main() {
    char buf[8];

    memcpy(buf, 'AAAAAAAAAAAAAAAAAAAAAAAAA', 25);

    return 0;
}
