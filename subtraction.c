#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1,
                Dlist **head2, Dlist **tail2,
                Dlist **headR, Dlist **tailR)
{
    //comparing both list less than zero
    if(compare_list(*head1, *head2) < 0)
    {
        printf("Negative result not supported\n");
        return FAILURE;
    }

    //start from tail 
    Dlist *ptr1 = *tail1;
    Dlist *ptr2 = *tail2;

    //borrow variable 
    int borrow = 0;

    //traverse first link list
    while(ptr1)
    {
        //substract borrow
        int diff = ptr1->data - borrow;

        //substract second digit
        if(ptr2)
            diff -= ptr2->data;

        if(diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        //store result
        insert_at_first(headR, tailR, diff);

        //move pointer
        ptr1 = ptr1->prev;

        if(ptr2)
            ptr2 = ptr2->prev;
    }
//remove unneccessary zeros
    remove_leading_zeros(headR, tailR);

    return SUCCESS;
}