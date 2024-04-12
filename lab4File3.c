#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pizzaMaker
{
    char topping [30];		// the topping you want
    struct pizzaMaker * next;	//pointer to next topping (if you want more toppings)
};

typedef struct pizzaMaker pizzaNode;

pizzaNode * AddTopping1(char *s, pizzaNode * head);
void AddTopping2(char *s, pizzaNode * head);
void displayAllToppingsR (pizzaNode * head);

void clearList (pizzaNode * head);

int main(int agrc, char * argv[]) {
    
    pizzaNode * headPizza = NULL;
    pizzaNode * ptr, * newNode;
    
    pizzaNode * pnode1;
    
    pnode1 = malloc (sizeof (pizzaNode));
    
    strcpy (pnode1->topping, "onion");
    pnode1->next = NULL;
    
    headPizza = pnode1;
    
    newNode = malloc (sizeof (pizzaNode));
    
    printf ("Enter the topping that you want:");
    scanf ("%s", newNode->topping);
    newNode->next = NULL;
    
    ptr = headPizza;
    
    while (ptr -> next != NULL) {
        
        ptr = ptr -> next;
    }
    
    ptr->next = newNode;
    
    ptr = headPizza;
    while ( ptr != NULL ) {
        printf ( "%s\n", ptr->topping );
        ptr = ptr->next;
    }
    
    headPizza = AddTopping1 ("Green Pepper", headPizza);
    
    ptr = headPizza;
    
    printf ("After inserting in beginning\n");
    while ( ptr != NULL ) {
        printf ( "%s\n", ptr->topping );
        ptr = ptr->next;
    }
    
    
    AddTopping2 ("Pepperoni", headPizza);
    
    ptr = headPizza;
    
    printf ("After inserting at end\n");
    displayAllToppingsR (ptr);
    
    return 0;
}


void displayAllToppingsR (pizzaNode * head) {
    
    if (head != NULL) {
        printf ("%s \n", head->topping);
        displayAllToppingsR (head->next);
    }
    
}

pizzaNode * AddTopping1 (char *s, pizzaNode * head)
{
    
    pizzaNode * newPtr = (pizzaNode *)(malloc(sizeof(pizzaNode)));
    
    // set values of the new node
    strcpy(newPtr->topping, s);
    newPtr->next = NULL;
    
    // Add the topping to the beginning of the list:
    if (head == NULL)
    {
        head = newPtr;
    }
    else
    {
        newPtr->next = head;
        //head = newPtr;
    }
    
    return newPtr;	// newPtr is the new head now
}

void AddTopping2 (char *s, pizzaNode * head)
{
    
    pizzaNode * newPtr = (pizzaNode *)(malloc(sizeof(pizzaNode)));
    pizzaNode * temp = head;
    
    // set values of the new node
    strcpy(newPtr->topping, s);
    newPtr->next = NULL;
    
    if (newPtr != NULL) {
        // Add the topping to the end of the list:
        if (head == NULL)
        {
            head = newPtr;       // new node becomes the head
        }
        else
        {
            while (temp->next != NULL) {
                temp = temp -> next;
            }
            
            temp -> next = newPtr;
            
        }
    }
}

void clearList(pizzaNode * head) {
    
    free (head);
}










