#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
    FILE *p1, *p2;

    char c;

    p1 = fopen("input.c", "r");
    p2 = fopen("output.txt", "w");

    if (!p1)
    {
        printf("\nFile can't be opened!");
        return 0;
    }

    while ((c = fgetc(p1)) != -1)
    {
        if ((c == '(') || (c == ')'))
            fputc(c, p2);
    }

    fclose(p1);
    fclose(p2);

    p2 = fopen("output.txt", "r");

    while ((c = fgetc(p2)) != -1)
        printf("%c", c);

    fclose(p2);
    return 0;
}