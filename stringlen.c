#include <stdio.h>
#include <string.h>

int main()
{
	char Str[100];
	int i;
    printf("\nEnter the String:");
	scanf("%s", Str);

	for (i = 0; Str[i] != '\0'; ++i);
    printf("\nLength of the string is %d",i);
    return 0;
}
