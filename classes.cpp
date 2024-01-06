#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int k = 10;

struct Human
{

    // private | protected | public

private :
    int height;
    int weight;

protected:
    char* name;

public : 
    Human(int height, int weight, char* name)
    {
        printf("Human Ctor\n");

        this->height = height;
        this->weight = weight;
        
        this->name = (char*)calloc(10, sizeof(char));
        strcpy(this->name, name);
    }

    virtual void Drink()
    {
        printf("Human Drink\n");
    }

    int GetHeight() const
    { return height; }

    void SetHeight(int value)
    { this->height = value; }

    void Dump()
    {
        printf("%s info\n",     this->name);
        printf("height = %d\n", this->height);
        printf("weight = %d\n", this->weight);
    }

    ~Human()
    {
        printf("Human Dtor\n");

        free(this->name);

        this->weight = -1;
        this->height = -1;
    }
};

struct Russian : public Human
{

private :
    double promile;

public : 
    Russian(int _height, int _weight, char* _name) : 
    Human(_height, _weight, _name)
    {
        printf("Russian Ctor\n");
        promile = 5;
    }

    void Drink() override
    {
        promile += 0.5;
        printf("%s promile = %lg\n", name, promile);
    }

    ~Russian()
    {
        printf("Russian Dtor\n");
    }
};

struct English : public Human
{
    private :
    int tea;

public : 
    English(int _height, int _weight, char* _name) : 
    Human(_height, _weight, _name)
    {
        printf("English Ctor\n");
        tea = 0;
    }

    void Drink() override
    {
        tea += 1;
        printf("tea time! (%d)\n", tea);
    }

    ~English()
    {
        printf("English Dtor\n");
    }
};

int main()
{ 
    Human* humans[2] = {}; 


    Russian ivan(190, 90, "Ivan");
    English nick(175, 70, "Nick");

    const Russian& ivan1 = ivan;
    ivan1.GetHeight();

    humans[0] = &ivan;
    humans[1] = &nick;

    for (int i = 0; i < 2; i++)
        humans[i]->Drink();
}