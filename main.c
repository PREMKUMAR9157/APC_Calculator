#include "apc.h"
//inserting node at last
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    //create new node
    Dlist *new = malloc(sizeof(Dlist));

    //check memory allocation
    if(new == NULL)
        return FAILURE;

        //store data in node
    new->data = data;
    //intialize links
    new->next = NULL;
    new->prev = NULL;

    //if list is empty
    if(*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }

    //link new node at end
    (*tail)->next = new;
    new->prev = *tail;
    //update tail
    *tail = new;

    return SUCCESS;
}

int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    //create new node
    Dlist *new = malloc(sizeof(Dlist));

    //check memory allocation
    if(new == NULL)
        return FAILURE;

        //store data
    new->data = data;

    //intialize links
    new->next = NULL;
    new->prev = NULL;

    //if list empty
    if(*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }

    //link node at begining
    new->next = *head;
    (*head)->prev = new;

    //update head
    *head = new;

    return SUCCESS;
}

void print_list(Dlist *head)
{
    //check if list empty
    if(head == NULL)
    {
        printf("0\n");
        return;
    }

    //traverse and print
    while(head)
    {
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n");
}

void delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    //delete nodes one by one
    while(*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    //uodate tail
    *tail = NULL;
}

//Function to convert string into linked list 
void digit_to_list(char *str, Dlist **head, Dlist **tail)
{
    //traverse string
    for(int i = 0; str[i]; i++)
    {
        //convert charcter into integer digit
        insert_at_last(head, tail, str[i] - '0');
    }
}

//function to compare two linked list
int compare_list(Dlist *head1, Dlist *head2)
{
    int len1 = 0, len2 = 0;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    //find length of first list
    while(temp1)
    {
        len1++;
        temp1 = temp1->next;
    }

    //find the length of second list
    while(temp2)
    {
        len2++;
        temp2 = temp2->next;
    }

    //compare length
    if(len1 > len2)
        return 1;

    if(len2 > len1)
        return -1;

        //compare digit by digit
    while(head1 && head2)
    {
        if(head1->data > head2->data)
            return 1;

        if(head2->data > head1->data)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }
//numbers are equal
    return 0;
}

//function to remove leading zeros
void remove_leading_zeros(Dlist **head, Dlist **tail)
{
    //remove zeros from begining
    while(*head && (*head)->data == 0 && (*head)->next)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

int main(int argc, char *argv[])
{
    //check command line argument
    if(argc != 4)
    {
        printf("Usage : ./a.out num1 operator num2\n");
        return 0;
    }

    //head and tail for first number
    Dlist *head1 = NULL, *tail1 = NULL;
    //head and tail for second number
    Dlist *head2 = NULL, *tail2 = NULL;
    //head and tail for result
    Dlist *headR = NULL, *tailR = NULL;

    //validation for addition and substraction

/* Variable to store signs */
int sign1 = 1, sign2 = 1;

/* Check first number sign */
if(argv[1][0] == '-')
{
    sign1 = -1;
}

/* Check second number sign */
if(argv[3][0] == '-')
{
    sign2 = -1;
}

/* Validate first operand */
for(int i = (argv[1][0] == '-' ? 1 : 0); argv[1][i]; i++)
{
    if(!isdigit(argv[1][i]))
    {
        printf("Invalid first number\n");
        return 0;
    }
}
//validation completed

/* Validate second operand */
for(int i = (argv[3][0] == '-' ? 1 : 0); argv[3][i]; i++)
{
    if(!isdigit(argv[3][i]))
    {
        printf("Invalid second number\n");
        return 0;
    }
}

    for(int i = 0; argv[1][i]; i++)
    {
        if(!isdigit(argv[1][i]))
        {
            printf("Invalid number\n");
            return 0;
        }
    }

    //validate second number
    for(int i = 0; argv[3][i]; i++)
    {
        if(!isdigit(argv[3][i]))
        {
            printf("Invalid number\n");
            return 0;
        }
    }

    //convert first number into list
    digit_to_list(argv[1], &head1, &tail1);
    //convert second number into list
    digit_to_list(argv[3], &head2, &tail2);

    //perform opeeration
    switch(argv[2][0])
    {
        case '+':
        //addition
            addition(&head1, &tail1,
                     &head2, &tail2,
                     &headR, &tailR);
            break;

        case '-':
        //substraction
            subtraction(&head1, &tail1,
                        &head2, &tail2,
                        &headR, &tailR);
            break;

        case '*':
        //multiolication
            multiplication(&head1, &tail1,
                           &head2, &tail2,
                           &headR, &tailR);
            break;

        case '/':
        //division
            division(&head1, &tail1,
                     &head2, &tail2,
                     &headR, &tailR);
            break;

        default:
            printf("Invalid Operator\n");
            return 0;
    }

    printf("Result : ");
    print_list(headR);

    //delete all lists
    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return 0;
}