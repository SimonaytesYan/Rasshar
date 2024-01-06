#include <stdio.h>
#include <stdlib.h>

int global = 0;

void f(int* a)
{
    (*a)++;
}

void g(int a)
{
    a++;
}

int main()
{
    int a = sizeof(int);
    int b = 0;

    int* heap = (int*)calloc(10, sizeof(int));

    printf("f      = %p\n", f);
    printf("global = %p\n", &global);
    printf("heap   = %p\n", heap);
    printf("b      = %p\n", &b);
    printf("a      = %p\n", &a);
}

//==========================================================
//| code | global | heap | | | | | | | | | | | stack | 
//==========================================================