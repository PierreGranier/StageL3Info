#include "fonctions.c"
#include <string.h>
#include <stdio.h>

#define false	0
#define true 	1
typedef char boolean;

int main()
{
    char ch[] = "Bonjour les potes";
    remplacer(ch, "Bonjour", "Salut");
    printf("%s\n", ch);
    return 0;
}