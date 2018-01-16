#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};

static struct Node* get_odd_or_center_node(struct Node* head)
{
    struct Node* odd_node = head;
    struct Node* current = head;
    int count = 0;

    while (current != NULL)
    {
        if (count == 2)
        {
            odd_node = odd_node->next;
            count = 0;
        }

        current  = current->next;
        count++;
    }

    return (odd_node);
}

static void insert_node(struct Node* node, int new_data)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = node->next;

    /* move the head to point to the new node */
    node->next   = new_node;
}

/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

static void insert_node_in_center(struct Node** head, int new_data)
{
    struct Node* odd_node;

    odd_node = get_odd_or_center_node(*head);

    if (odd_node)
    {
        insert_node(odd_node, new_data);
    }
    else
    {
        push(head, new_data);
    }
}
