// Normally function arguments are passed by vallues
// that means they are copied in and out of functions
//arguments by reference means passing a pointer to the variable instead of the value itself
//Advantages
//Allows function to have control over the vvariable and structs of parent function not just copy
//directly allows reading and writting the original object


//for examples
#include <stdio.h>

// passing by value

void ft_addone(int n)
{
    n = n + 1;
}

// passing by reference using pointers

void ft_add1(int *n)
{
    *n = *n + 1;
}
int main(void)
{
    //passing by value
    int nbr = 0;
    printf("Before: %d\n", nbr);// output 0
    ft_addone(nbr);
    printf("After: %d\n", nbr); // output 0

    // passing by reference
    int num = 0;
    printf("Before: %d\n", num);// output 0
    ft_add1(&num); //passing pointer reference to the function
    printf("Before: %d\n", num);// output 1
}

// when arguments are passed by value, copy of original value is passed 
//Any changes done inside the function has no effect on original value
//the result is 0 in both cases
//since, ft_addone doesnot modify the original value of nbr
