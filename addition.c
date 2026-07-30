#include "apc.h"

int addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    //start from last nodes
    Dlist *ptr1 = *tail1;
    Dlist *ptr2 = *tail2;

    //carry variable 
    int carry = 0;

    //repeat until lists   and carry end
    while(ptr1 || ptr2 || carry)
    {
        //intialize sum with carry
        int sum = carry;

        //add first list digit
        if(ptr1)
        {
            sum += ptr1->data;
            ptr1 = ptr1->prev;
        }

        //add second list digit
        if(ptr2)
        {
            sum += ptr2->data;
            ptr2 = ptr2->prev;
        }
//store result digit
        insert_at_first(headR, tailR, sum % 10);

        //update carry
        carry = sum / 10;
    }

    return SUCCESS;
}