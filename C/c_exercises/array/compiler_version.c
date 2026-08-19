#include <stdio.h>

int main() {

#ifdef __STDC_VERSION__
    printf("%ld\n", __STDC_VERSION__);
#else
    printf("No standard version detected\n");
#endif

    return 0;
}