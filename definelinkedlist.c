#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}node_t;

//printing list

void print_list(node_t *head)
{
    node_t *current = head;

    while(current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}
//adding item to end of list
void push_end(node_t *head, int val)
{
    node_t *current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL; 
}

//adding item to the beginning of list
    //Create a new item and set its value
    //Link the new item to point to the head of the list
    //Set the head of the list to be our new item
//we must pass (a double pointer) so we will be able to modify the pointer itself.
void push_start(node_t **head, int val)
{
    node_t *new_node;
    new_node = (node_t *)malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}
//Removing first item from the list also called pop
    //Take the next item that the head points to and save it
    //Free the head item
    //Set the head to be the next item that we've stored on the side
int pop_first(node_t **head)
{
    int retval = -1;
    node_t *next_node = NULL;

    if (*head == NULL)
        return (-1);
    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;
    return (retval);

}

int pop_last(node_t *head)
{
    int retval = 0;
    //if only one item is in the list
    if(head->next == NULL)
    {
        free(head);
        return retval;
    }
    //get to second last node in the list
    node_t *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    //current is now pointing tos econd last elem
    //we have to remove current->next now to remove last elem
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

//remove a specific item either y index or value

int    remove_by_index(node_t **head, int n)
{
    int i = 0;
    int retval = -1;
    node_t *current = *head;
    node_t *temp_node = NULL;

    if (n == 0)
        return(pop_first(head));
    while (i < n-1)
    {
        if (current->next == NULL)
            return (-1);
        current = current->next;
        i++;
    }
    if (current->next == NULL)
        return (-1);
    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);
    return (retval);
}

int main()
{
    node_t *head = NULL;
    head = (node_t *)malloc(sizeof(node_t));
    if (head == NULL)
        return 1;
    head->val = 5;
    head->next = (node_t *)malloc(sizeof(node_t));
    head->next->val = 10;
    head->next->next = (node_t *)malloc(sizeof(node_t));
    head->next->next->val = 15;
    head->next->next->next = NULL;
    
    printf("----The nodes are--\n");
    print_list(head);
    printf("----push to end--\n");
    push_end(head, 20);
    print_list(head);
    printf("------push to start------\n");
    push_start(&head, 0);
    push_start(&head, 1);
    push_start(&head, 2);
    push_start(&head, 3);
    print_list(head);
    printf("-------removed from first------------\n");  
    pop_first(&head);
    print_list(head);
    printf("-------removed from last------------\n");
    pop_last(head);
    print_list(head);
    printf("-------removed by index- test 5th index-----------\n");
    remove_by_index(&head, 5);
    print_list(head);
}