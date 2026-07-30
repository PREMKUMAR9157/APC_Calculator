#include "apc.h"
//function of division to perform division operation
int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    //variables to store converted numbers
    long long num1 = 0;
    long long num2 = 0;
//temporary pointer for traversal
    Dlist *temp = *head1;


    //convert first linked list into number
    while(temp)
    {
        num1 = num1 * 10 + temp->data;
        temp = temp->next;
    }

    //traverse second list
    temp = *head2;

    //convert second linked list into number
    while(temp)
    {
        num2 = num2 * 10 + temp->data;
        temp = temp->next;
    }

    //check division by zero
    if(num2 == 0)
    {
        printf("Division by zero not possible\n");
        return FAILURE;
    }

    //store division result
    long long res = num1 / num2;

    //character array to store result as string
    char str[100];

    //convert result into string
    sprintf(str, "%lld", res);
    
//convert string into linked list
    digit_to_list(str, headR, tailR);

    return SUCCESS;
}