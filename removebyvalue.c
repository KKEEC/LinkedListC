#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(node_t ** head, int val) {
    /* TODO: fill in your code here */
     int retval = -1;
    node_t *current = *head;
    if (*head == NULL)
        return retval;
    while ((*head)->val == val)
    {
        retval = (*head)->val;
        node_t *temp = *head;
        *head = (*head)->next;
        free(temp);
        return retval;
    }
    while (current->next != NULL)
    {
        if (current->next->val == val)
        {
            retval = current->next->val;
            node_t *temp = current->next;
            current->next = current->next->next;
            free(temp);
            break;
        }
        current = current->next;
    }
    return retval;
}

int main() {

    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
    
    node_t * current = test_list;

    while (current != NULL) {
        node_t *temp = current->next;
        free(current);
        current = temp;
    }
    free(test_list);
}