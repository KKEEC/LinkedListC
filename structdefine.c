#include <stdio.h>

// struct are defined as global variable so that its accessible from any function or file within a program
//global struct can be initialised once, allowing their value to be used throughout program
//defining globally eliminates the need to pass struct pointers to function arguments or create local copies

//without using typedef
struct person1
{
    char    *name;
    int     age;
};

// using typedef method allows us to define another name that is handy in terms of pointer and structs 
typedef struct person
{
    char    *name;
    int     age;
}person;

int main(void)
{
    //without using typedef
    struct person1 john;
    //with using typedef
    person johnny;
    //to access structs value we use dot(.) operator
    john.name = "Johh";
    john.age = 25;
    printf("%s is %d years old\n", john.name, john.age);

    johnny.name = "Johnny";
    johnny.age = 27;

    printf("%s is %d years old\n", johnny.name, johnny.age);

}
