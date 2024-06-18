#include <stdio.h>
#include <stdlib.h>
//LAB 1 - GAMAD/DUHAYLUNGSOD/MANALO
//CMSC 28 (K)
//NOTE: INTEGER variable used for "add item" choice

//node structure used
struct Node{
    int data;
    struct Node* next;
};

//different function prototypes program will utilize
void addItStart(struct Node** head_ref, int new_data);
void addItEnd(struct Node** head_ref, int new_data);
void addItPos(struct Node** head_ref, int new_data, int position);
void deleteIt(struct Node** head_ref, int key);
void displayList(struct Node* node);
void deleteList(struct Node** head_ref);

//main function with menu
int main(){
    struct Node* head = NULL;
    int choice, item, position;

	//do while loop used for menu interaction (infinite loop for multiple uses until user decides to terminate)
    do{
        printf("\nProgram List MENU\n");
        printf("[1] Add Item (Num/Int)\n"); //integer var chosen for add item
        printf("[2] Delete Item\n");
        printf("[3] Display List\n");
        printf("[4] Delete List\n");
        printf("[0] Exit Program\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

		//switch statements for different menu choices
        switch (choice){
            case 1:
                printf("\nPlease enter the item to be added: ");
                scanf("%d", &item);
                printf("\nWhere to add the item?\n");
                printf("[1] Start of the list\n");
                printf("[2] End of the list\n");
                printf("[3] Specific position\n");
                printf("[0] Cancel\n");
                printf("\nEnter choice: ");
                scanf("%d", &position);
                switch (position){
                    case 1:
                        addItStart(&head, item);
                        break;
                    case 2:
                        addItEnd(&head, item);
                        break;
                    case 3:
                        printf("\nEnter the position to add the item: ");
                        scanf("%d", &position);
                        addItPos(&head, item, position);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 2:
                printf("\nEnter the item to delete: ");
                scanf("%d", &item);
                deleteIt(&head, item);
                break;
            case 3:
                printf("\nDisplaying the list:\n");
                displayList(head);
                break;
            case 4:
                deleteList(&head);
                printf("\nThe list has been emptied! You may add new items again.\n");
                break;
            case 0:
                printf("\nExiting the program! Sayonara!\n");
                break;
            default:
                printf("\nInvalid choice! Check menu list and try again.\n");
        }
    }while (choice != 0);

    return 0;
}

//adding item at the start of the list
void addItStart(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

//adding item at the end of the list
void addItEnd(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

//adding item at specific position in the list
void addItPos(struct Node** head_ref, int new_data, int position){
    if (position <= 0){
        printf("\nInvalid position!\n");
        return;
    }
    if (position == 1){
        addItStart(head_ref, new_data);
        return;
    }
    
    struct Node* current = *head_ref;
    int i = 1;
    for (; i < position - 1 && current != NULL; i++)
        current = current->next;
    if (current == NULL){
        printf("\nPosition exceeds the size, default position added at end.\n");
        addItEnd(head_ref, new_data);
    }else{
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->next = current->next;
        current->next = new_node;
    }
}

//delete only one item from current list
void deleteIt(struct Node** head_ref, int key){
    struct Node* temp = *head_ref, *prev;
    
    if (temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        printf("\nThe element %d has been deleted\n", key);
        return;
    }
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("\nThe list does not contain specified element\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    //Position calculation will be required here
    printf("\nThe element %d, has been successfully deleted\n", key); 
}

//display list made
void displayList(struct Node* node){
    int position = 1;
    while (node != NULL){
        printf("Position %d: %d\n", position++, node->data);
        node = node->next;
    }
}

//delete the entire list made
void deleteList(struct Node** head_ref){
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

