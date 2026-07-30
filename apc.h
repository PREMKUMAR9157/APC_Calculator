#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

//doubly linked list structure
typedef struct node
{
    int data;//strore digit
    struct node *prev;//pointer to previous
    struct node *next;//pointer to next
}Dlist;

//function declaration

//insert node at last
int insert_at_last(Dlist **head, Dlist **tail, int data);
//insert node at first
int insert_at_first(Dlist **head, Dlist **tail, int data);
//function for printing list
void print_list(Dlist *head);
//deleting of list
void delete_list(Dlist **head, Dlist **tail);
//convert string into linked list
void digit_to_list(char *str, Dlist **head, Dlist **tail);
//compare two linked lists
int compare_list(Dlist *head1, Dlist *head2);
//remove leading zeros from result
void remove_leading_zeros(Dlist **head, Dlist **tail);

//addition function
int addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR);

 //substraction function            
int subtraction(Dlist **head1, Dlist **tail1,
                Dlist **head2, Dlist **tail2,
                Dlist **headR, Dlist **tailR);

//multiplication function                
int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR);
//division function
int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR);

#endif