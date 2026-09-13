#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start = NULL;

void create_ll();
void display();
void insert_beg();
void insert_end();
void insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_node();

int main()
{
    int option;

    do
    {
        printf("\n\n***** MAIN MENU *****");
        printf("\n1. Create a list");
        printf("\n2. Display the list");
        printf("\n3. Add a node at the beginning");
        printf("\n4. Add a node at the end");
        printf("\n5. Add a node before a given node");
        printf("\n6. Add a node after a given node");
        printf("\n7. Delete a node from the beginning");
        printf("\n8. Delete a node from the end");
        printf("\n9. Delete a given node");
        printf("\n10. Exit");

        printf("\n\nEnter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                create_ll();
                printf("\nLinked List Created");
                break;

            case 2:
                display();
                break;

            case 3:
                insert_beg();
                break;

            case 4:
                insert_end();
                break;

            case 5:
                insert_before();
                break;

            case 6:
                insert_after();
                break;

            case 7:
                delete_beg();
                break;

            case 8:
                delete_end();
                break;

            case 9:
                delete_node();
                break;

            case 10:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid Option!");
        }

    } while(option != 10);

    return 0;
}


/* Create Linked List */
void create_ll()
{
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");
    scanf("%d", &num);

    while(num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));

        new_node->data = num;
        new_node->next = NULL;
        new_node->prev = NULL;

        if(start == NULL)
        {
            start = new_node;
        }
        else
        {
            ptr = start;

            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = new_node;
            new_node->prev = ptr;
        }

        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
}


/* Display Linked List */
void display()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    printf("\nLinked List: ");

    ptr = start;

    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}


/* Insert at Beginning */
void insert_beg()
{
    struct node *new_node;
    int num;

    printf("\nEnter data: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = num;
    new_node->prev = NULL;
    new_node->next = start;

    if(start != NULL)
    {
        start->prev = new_node;
    }

    start = new_node;

    printf("\nNode inserted at beginning.");
}


/* Insert at End */
void insert_end()
{
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter data: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = num;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(start == NULL)
    {
        start = new_node;
    }
    else
    {
        ptr = start;

        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = new_node;
        new_node->prev = ptr;
    }

    printf("\nNode inserted at end.");
}


/* Insert Before Given Node */
void insert_before()
{
    struct node *new_node, *ptr, *preptr;
    int num, val;

    printf("\nEnter data: ");
    scanf("%d", &num);

    printf("Enter value before which to insert: ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if(start == NULL)
    {
        printf("\nList is empty");
        free(new_node);
        return;
    }

    if(start->data == val)
    {
        new_node->next = start;
        new_node->prev = NULL;
        start->prev = new_node;
        start = new_node;
        return;
    }

    ptr = start;

    while(ptr != NULL && ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL)
    {
        printf("\nNode not found!");
        free(new_node);
    }
    else
    {
        preptr->next = new_node;
        new_node->prev = preptr;
        new_node->next = ptr;
        ptr->prev = new_node;
    }
}


/* Insert After Given Node */
void insert_after()
{
    struct node *new_node, *ptr;
    int num, val;

    printf("\nEnter data: ");
    scanf("%d", &num);

    printf("Enter value after which to insert: ");
    scanf("%d", &val);

    ptr = start;

    while(ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }

    if(ptr == NULL)
    {
        printf("\nNode not found!");
        return;
    }

    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = num;
    new_node->next = ptr->next;
    new_node->prev = ptr;

    if(ptr->next != NULL)
    {
        ptr->next->prev = new_node;
    }

    ptr->next = new_node;

    printf("\nNode inserted.");
}



void delete_beg()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    ptr = start;
    start = start->next;

    if(start != NULL)
    {
        start->prev = NULL;
    }

    free(ptr);

    printf("\nFirst node deleted.");
}



void delete_end()
{
    struct node *ptr, *preptr;

    if(start == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    if(start->next == NULL)
    {
        free(start);
        start = NULL;
        printf("\nLast node deleted.");
        return;
    }

    ptr = start;

    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;

    free(ptr);

    printf("\nLast node deleted.");
}


/* Delete Given Node */
void delete_node()
{
    struct node *ptr, *preptr;
    int val;

    printf("\nEnter value to delete: ");
    scanf("%d", &val);

    if(start == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    if(start->data == val)
    {
        ptr = start;
        start = start->next;

        if(start != NULL)
        {
            start->prev = NULL;
        }

        free(ptr);

        printf("\nNode deleted.");
        return;
    }

    ptr = start;

    while(ptr != NULL && ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL)
    {
        printf("\nNode not found!");
    }
    else
    {
        preptr->next = ptr->next;

        if(ptr->next != NULL)
        {
            ptr->next->prev = preptr;
        }

        free(ptr);

        printf("\nNode deleted.");
    }
}
