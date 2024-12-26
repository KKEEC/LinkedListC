#include <stdio.h>

typedef struct coordinate
{
    int x;
    int y;
}coordinate;


void ft_origin(coordinate *ptr)
{
    (*ptr).x = 2;
    (*ptr).y = 2;
    printf("coordinate are %d and %d \n", (*ptr).x, (*ptr).y);
    //instead of using dot(.) notation to access, we can use (->) operator to dereference the pointer in struct
    ptr->x = 0;
    ptr->y = 0;
}
int main(void)
{
    coordinate origin;
    origin.x = 5;
    origin.y = 10;
    printf("coordinate are %d and %d \n", origin.x, origin.y);
    ft_origin(&origin);
    printf("coordinate are %d and %d \n", origin.x, origin.y);
}