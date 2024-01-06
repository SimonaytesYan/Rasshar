#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Human
{
    int height;
    int weight;

    char* name;
};

void HumanCtor(Human* human, int height, int weight, char* name)
{
    human->height = height;
    human->weight = weight;

    human->name = (char*)calloc(10, sizeof(char));
    strcpy(human->name, name);
}

void HumanDump(Human* human)
{
    printf("%s info\n",     human->name);
    printf("height = %d\n", human->height);
    printf("weight = %d\n", human->weight);
}

void HumanDtor(Human* human)
{
    free(human->name);

    human->weight = -1;
    human->height = -1;
}

//=====================
//        0x1000
// | | | | 'J' | 'o' | 'n' | 0 | 0 |  |
//0x100
// | 'M' | 'i' | 'k' | 'e' | 0 | 0 | 0 | 0 | 0 | 0 |
//0x200
// | 'J' | 'o' | 'n' | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
//=====================

int main()
{
    char name[10] = {};

    strcpy(name, "Mike");

    Human mike;
    Human jon;
    
    HumanCtor(&mike, 180, 70, name);

    strcpy(name, "Jon");

    HumanCtor(&jon,  160, 50, name);
    
    HumanDump(&mike);
    HumanDump(&jon);

    HumanDtor(&mike);
    HumanDtor(&jon);
}