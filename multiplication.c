#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR)
{
    //variables to perform multiplication
    long long num1 = 0;
    long long num2 = 0;

    Dlist *temp = *head1;
//convert first list into numbers
    while(temp)
    {
        num1 = num1 * 10 + temp->data;
        temp = temp->next;
    }

    temp = *head2;

    /*convert second list into number*/
    while(temp)
    {
        num2 = num2 * 10 + temp->data;
        temp = temp->next;
    }

    //multiply numbers
    long long res = num1 * num2;

    if(res == 0)
    {
        insert_at_last(headR, tailR, 0);
        return SUCCESS;
    }

//array to store result string
    char str[100];

    //convert integer into string
    sprintf(str, "%lld", res);

    //convert string into linked list
    digit_to_list(str, headR, tailR);

    return SUCCESS;
}