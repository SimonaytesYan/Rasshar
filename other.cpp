#include <stdio.h>
#include <stdlib.h>

struct Point
{
    double x;
    double y;
};


int sum(int a, int b)
{
    printf("sum int\n");
    return a + b;
}

double sum(double a, double b)
{
    printf("sum double\n");
    return a + b;
}

int sum(int a)
{
    return a + 1;
}

Point operator+(Point a, Point b)
{
    Point res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return res;
}

template<typename Type>
struct Array
{
    int  size;
    Type* data;

    Array(int _size)
    {
        size = _size;
        data = (Type*)calloc(sizeof(Type), size);
    }

    Type& operator[] (int index)
    {
        return data[index];
    }

    ~Array()
    {
        free(data);
    }
};

template<typename Type>
Type SUM(Type a, Type b)
{
    return a + b;
}

int main()
{
    printf("SUM = %d\n", SUM<int>(1, 2));
    Point a = {1, 2};
    Point b = {-3, 4};
    Point p = a + b;

    printf("p = (%lg %lg)\n", p.x, p.y);

    Array<int> arr(10);

    for (int i = 0; i < arr.size; i++)
        arr[i] = i * i;
    
    Array<double> arr1(10);
    Array<Point>  arr2(10);
}
