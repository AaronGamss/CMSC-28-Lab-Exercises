#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

//Dan Aaron P. Gamad - Queue implementation exercise (3)

//struct to represent the customer
typedef struct{
    char name[50];
    float total_amount;
} Customer;

//struct to represent the queue line
typedef struct{
    Customer items[MAX_SIZE];
    int front, rear;
} Queue;

//initialize empty queue
Queue* INIT(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

//check if queue is empty
bool EMPTY(Queue* q){
    return q->front == -1;
}

//gets front of the line or queue
Customer FRONT(Queue* q){
    return q->items[q->front];
}

//add a customer at end of the line or queue
void ENQUEUE(Customer customer, Queue* q){
    if (q->rear == MAX_SIZE - 1){
        printf("Queue is full. End of the line!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = customer;
}

//remove or return the front element of the queue
Customer DEQUEUE(Queue* q){
    Customer customer;
    if (EMPTY(q)){
        printf("Queue is empty. Take a break cashier.\n");
        return customer;
    }
    customer = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return customer;
}

//print checkout menu
void printMainMenu(){
    printf("\nTOYS R US! Counter 0:\n");
    printf("[1] Fall in line\n");
    printf("[2] Serve customer\n");
    printf("[3] Next customer\n");
    printf("[4] Closing time\n");
    printf("[0] Exit\n");
    printf("Enter choice: ");
}

int main(){
    Queue* checkout_queue = INIT(); //initialize checkout queue
    int choice;
    do{
        printMainMenu(); //main options are printed
        scanf("%d", &choice);
        switch (choice){
            case 1:{ //add customer the line or queue
                Customer customer;
                printf("Enter customer's name: ");
                scanf("%s", customer.name);
                printf("Enter total amount of toys to purchase: ");
                scanf("%f", &customer.total_amount);
                ENQUEUE(customer, checkout_queue);
                break;
            }
            case 2:{ //serve the customer in front of the line or queue
                if (!EMPTY(checkout_queue)){
                    Customer served_customer = DEQUEUE(checkout_queue);
                    printf("Now serving %s with total toys amount payable of %.0f.\n", served_customer.name, served_customer.total_amount);
                }else{
                    printf("The queue or line is EMPTY. No orders to serve, yay!\n");
                }
                break;
            }
            case 3:{ //checks for next customer to be served (next in line or queue)
                if (!EMPTY(checkout_queue)){
                    Customer next_customer = FRONT(checkout_queue);
                    printf("Next order: For %s with total toys amount payable of %.0f.\n", next_customer.name, next_customer.total_amount);
                }else{
                    printf("The queue or line is EMPTY. No orders to serve, yay!\n");
                }
                break;
            }
            case 4:{ //will serve all available customers (first in first out)
                if (!EMPTY(checkout_queue)){
                    printf("Closing time!! Serving lucky remaining customers.\n");
                    while (!EMPTY(checkout_queue)){
                        Customer served_customer = DEQUEUE(checkout_queue);
                        printf("Now serving %s with total toys amount payable of %.0f.\n", served_customer.name, served_customer.total_amount);
                    }
                    printf("All customers have been served. Good job!\n");
                }else{
                    printf("The queue or line is EMPTY. Take a break cashier.\n");
                }
                break;
            }
            case 0:{ //exit prog
                printf("Exiting the TOYS R US checkout system.\n");
                break;
            }
            default:{ //invalid inputs
                printf("Invalid choice. Please choose correctly.\n");
                break;
            }
        }
    }while(choice != 0);

    free(checkout_queue); //free memory allocation
    return 0;
}

