//dynamic allocation allows building complex data structures like linkedlist
//allocating memory dynamically helps to store data without knowing the size of data in the time of writting program
//to allocate we need to have a pointer ready to store the location of newly alloced mem
//we access the value using same pointer and free the memory using same pointer

// to dynamically allocate a struct
#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    char    *name;
    int     age;
}Person;

int main(void)
{
    Person *newperson;
    newperson = (Person *)malloc(sizeof(Person));
    // we need to include (person *) while using malloc
    //otherwise malloc returns (void *) that doesnot have type
    //we need to simply typecase value of pointer returned by malloc to desired (person *)
    //we can skip this since C will implicitly convert the type of returned pointer to that of the pointer it is assigned
    newperson->name = "Krishna";
    newperson->age = 29;
    printf("%s is %d years old\n", newperson->name, newperson->age);
    free(newperson);

}