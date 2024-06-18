#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 10 

//LAB 3 - GAMAD/DUHAYLUNGSOD/MANALO
//CMSC 28 (K)

//stack struct
typedef struct {
    char items[MAX_SIZE][50]; //array used to hold the strings
    int top; //index of top element
} Stack;

//different function prototypes used
void initialize(Stack *s);
void push(Stack *s, const char *item);
char* pop(Stack *s);
bool full(Stack *s);
bool empty(Stack *s);
char* top(Stack *s);
void makeNull(Stack *s);
void displayMenu();
void addKitchenware(Stack *s);
void washKitchenware(Stack *s);
void topKitchenware(Stack *s);
void washAll(Stack *s);

//main func 
int main(){
	
    Stack kitchenwareStack;
    initialize(&kitchenwareStack);
    int choice;

    do{
        displayMenu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addKitchenware(&kitchenwareStack);
                break;
            case 2:
                washKitchenware(&kitchenwareStack);
                break;
            case 3:
                topKitchenware(&kitchenwareStack);
                break;
            case 4:
                washAll(&kitchenwareStack);
                break;
            case 0:
                printf("Bye bye!\n");
                break;
            default:
                printf("Invalid choice! enter valid option [0-4]\n");
        }
    }while(choice != 0);

    return 0;
}

//initializing stack
void initialize(Stack *s){
    s->top = -1;
}

//push item to stack
void push(Stack *s, const char *item){
    if(!full(s)){
        s->top++;
        strcpy(s->items[s->top], item);
    }
}

//pop an item from stack
char* pop(Stack *s){
    if(!empty(s)){
        return s->items[s->top--];
    }
    return NULL;
}

//check if stack is full
bool full(Stack *s){
    return (s->top == MAX_SIZE - 1);
}

//check if stack is empty
bool empty(Stack *s){
    return (s->top == -1);
}

//returns top item of stack
char* top(Stack *s){
    if(!empty(s)){
        return s->items[s->top];
    }
    return NULL;
}

//make stack empty
void makeNull(Stack *s){
    s->top = -1;
}

//display main menu
void displayMenu(){
    printf("\nKitchenware Washing Machine\n\n");
    printf("[1] Add kitchenware\n");
    printf("[2] Wash kitchenware\n");
    printf("[3] Top kitchenware\n");
    printf("[4] Wash all\n");
    printf("[0] Exit\n\n");
    printf("Enter choice: ");
}

//add kitchenware to stack
void addKitchenware(Stack *s){
    char item[50];
    if (!full(s)){
        printf("Please enter the kitchenware to be washed: ");
        scanf("%s", item);
        push(s, item);
    }else{
        printf("The stack is now full. Cannot add anymore kitchenware.\n");
    }
}

//wash kitchenware
void washKitchenware(Stack *s){
    if(!empty(s)){
        char *item = pop(s);
        printf("%s is now being washed.\n", item);
    }else{
        printf("The stack is now empty. No more kitchenware to wash, yay!\n");
    }
}

//display the kitchenware at top of the stack
void topKitchenware(Stack *s){
    if(!empty(s)){
        printf("%s at top of the stack, next one to be washed.\n", top(s));
    }else{
        printf("The stack is now empty. No  more kitchenware to wash, yay!\n");
    }
}

//wash all kitchenware
void washAll(Stack *s){
    if(!empty(s)){
        printf("Washing all kitchenware entered:\n");
        while(!empty(s)){
            washKitchenware(s);
        }
        printf("All kitchenware has now been washed.\n");
    }else{
        printf("The stack is empty. No more kitchenware to wash, yay!\n");
    }
}

