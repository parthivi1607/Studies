#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* arg[])
{
    FILE* f1 = fopen(arg[1], "r");
    FILE* f2 = fopen(arg[2],"w");
    char c;
    while((c = fgetc(f1))!=EOF)
    {
        fputc(c,f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}