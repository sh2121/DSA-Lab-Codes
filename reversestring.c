#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("\nEnter a string:");
    scanf("%s",str);
    printf("\nReversed string is %s", strrev(str));
    return 0;
}
