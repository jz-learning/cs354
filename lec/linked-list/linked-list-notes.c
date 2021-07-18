#include <stdio.h>
#include <stdlib.h>

//* Node structure for linked list
typedef struct node {
    int data;
    struct node *next;
} node;

/* ######################## HELPER FUNCTIONS ############################# */

//* Function to append node to linked list
node *Append(node *head, int data) {
    // create a new node on heap
    struct node *new_node = malloc(sizeof(node));

    // set the data of new node
    new_node->data = data;
    new_node->next = NULL;

    printf("Adding node: %i\n", data);

    // Connect the new node to the head
    if (head == NULL)
        return new_node;
    else {
        // temp node to point to head
        node *temp = head;

        // traverse to the last node, and append to it
        while (temp->next != NULL) temp = temp->next;
        temp->next = new_node;
        return head;
    }
}

//* Function to print the linked list
void Print_List(node *head) {
    if (head == NULL) {
        printf("Oops, empty list\n");
    }

    node *temp = head;

    while (temp != NULL) {
        printf("%i ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//* Function to delete the head of the linked list
void Delete_Head(node **pointer_head) {
    if (*pointer_head == NULL) return;

    // Grab the value of the pointer to the head
    // which is the head itself
    printf("Deleting node: %i\n", (*pointer_head)->data);

    node *temp = *pointer_head;
    *pointer_head = (*pointer_head)->next;

    // Free the memory of the head
    free(temp);
}

/* ############################# MAIN FUNCTION ############################ */
// main method
int main(int argc, char const *argv[]) {
    // create a new linked list
    // Need a head pointer to the first node
    node *head = NULL;  //! in the stack

    //  Create the first node
    node *first = malloc(sizeof(node));  //! reserves memory on the heap

    // Assign data to the first node
    first->data = 10;
    first->next = NULL;

    // Assign head to the first node
    head = first;  //! both are pointing to the same node in the heap

    // Print the list
    Print_List(head);

    // Append the second node
    head = Append(head, 20);
    Print_List(head);

    Delete_Head(&head);
    Print_List(head);
    Delete_Head(&head);
    Print_List(head);
}