#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Animal
{
protected:
    int   weight;
    int   height;

public :
    Animal(int _weight,
           int _height)
    {
        weight = _weight;
        height = _height;
    }

    int GetWeight() const
    {
        return weight;
    }

    int GetHeight() const
    {
        return height;
    }

    virtual void PrintStat() const
    {
        printf("weight = %d\n", weight);
        printf("height = %d\n", height);
    }

    ~Animal()
    {
        height = 0;
        weight = 0;
    }
};

class Human : public Animal
{
private :
    char* name;

public :
    Human(int _weight, int _height, char* _name) :
    Animal(_weight, _height)
    {
        name = (char*)calloc(strlen(_name) + 1, sizeof(char));
        strcpy(name, _name);
    }

    Human(const Human& other) :
    Animal(other)
    {
        name = (char*)calloc(strlen(other.GetName()) + 1, sizeof(char));
        strcpy(name, other.GetName());
    }

    Human& operator=(const Human& other)
    {
        weight = other.GetWeight();
        height = other.GetHeight();
        name   = (char*)calloc(strlen(other.GetName()) + 1, sizeof(char));
        strcpy(name, other.GetName());

        return *this;
    }

    char* GetName() const
    {
        return name;
    }

    void PrintStat() const override
    {
        Animal::PrintStat();
        printf("name = \"%s\"\n", name);
    }

    ~Human()
    {
        free(name);
    }
};

int Sum(int x, int y)
{
    return x + y;
}

char* Sum(char* a, char* b)
{
    //...
}

Human Sum(Human a, Human b)
{
    //...
}

Human operator+(Human a, Human b)
{
    Human c(a.GetWeight() + b.GetWeight(), 180, "Loh");
    return c;
}

void f(int* a)
{
    if (a == NULL)
        return;
    *a = 10;
}

class Math
{
    public:
    static double cos(double angle)
    {
        return 0;
    }
};

int main()
{
    //Animal tiger(70, 175);

    /*const Human& copy_vasya = vasya;      //Human const* copy_vasya = &vasya;
    copy_vasya.GetName();
    copy_vasya.GetWeight();
    copy_vasya.PrintStat();*/

    Human  vasya(70, 175, "Вася");
    Human  petya(80, 190, "Петя");

    auto vasya_petya = Human(vasya + petya);
    vasya_petya.PrintStat();

    Human vasya_1(10, 10, "11");
    vasya_1 = vasya;

    auto cos = Math::cos(10);
}
