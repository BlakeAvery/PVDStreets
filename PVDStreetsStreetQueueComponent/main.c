#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This code will not compile on its own! The tons of errors are intentional!

typedef struct car_t { //defines the structure of a node in the list
    long id; //identification number of car
    char turn_dir; //0 for straight, 1 for left, 2 for right. Determined at end of queue.
    long time_in_system; //increments on engine loop. Counts how long car is in simulation.
    int street_tracker[20];
    struct car_t *next;
}car_t;

typedef struct street_t { //defines structure of the street header
    car_t *fptr;
    char name[30];
    int count; //Represents max amount of cars the street can hold
    int traffic_light_status; //Status of traffic light at end of this queue
    int timer;
    int arrival_rate;
    int exit_rate;
    struct street_t *street_str; //Pointer to next street queue that this street leads to straight
    struct street_t *street_left; //left
    struct street_t *street_right; //right - If one of these three are null we can't go this direction
    //to fill in more
    car_t *rptr;
}street_t;

typedef struct head_t { //linked list to hold all cars in system
    long count;
    car_t *fptr;
};

int new_node();
int output_list();
int is_list_empty();
int dequeue();

int main() {
    header.count = 0;
    header.fptr = NULL;
    header.rptr = NULL;
    int opt;

    printf("QueueDemo v1 - Select an option\n");
    while(1) {
        printf("1 - Insert into queue\n2 - Display queue\n3 - De-queue\n4 - Exit program\n");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                new_node(header);
                break;
            case 2:
                output_list();
                break;
            case 3:
                dequeue();
                break;
            default:
                break;
        }
        if(opt > 3) {
            break;
        }
    }
    return 0;
}

int new_node() {
    node_t *new_ptr = NULL;
    node_t *cur_ptr = NULL;
    char name[25];
    int age;
    //Populate values for new node
    printf("Enter name:\n");
    scanf("%s", name);
    printf("Enter age:\n");
    scanf("%d", &age);
    //Create the new node
    new_ptr = (node_t*)malloc(sizeof(node_t));
    strcpy(new_ptr->name, name);
    new_ptr->age = age;
    new_ptr->next = NULL;
    //Next, we have to determine where to place the node
    if(is_list_empty()) { //List is empty, point fptr in header to new node.
        header.rptr = new_ptr;
        header.fptr = new_ptr;
        header.count++;
    } else { //we place the node at end of list
        cur_ptr = header.rptr;
        cur_ptr->next = new_ptr;
        header.rptr = new_ptr;
        header.count++;
    }
    return 0;
}

int is_list_empty() {
    if(header.count > 0) {
        return 0;
    } else {
        return 1;
    }
}

int output_list() {
    node_t *ptr = header.fptr;
    printf("Header claims there are %d nodes in this list.\n", header.count);
    while(ptr != NULL) {
        printf("Address: %p\tName: %s\tAge: %d\n",ptr, ptr->name, ptr->age);
        ptr = ptr->next;
    }
    printf("End of list.\n");
    return 0;
}

int dequeue() {
    if(header.fptr == NULL && header.rptr == NULL) {
        printf("This queue is empty. Try adding someone to it.\n");
        return 1;
    } else if (header.fptr == header.rptr) {
        node_t *ptr = header.fptr;
        header.fptr = NULL;
        header.rptr = NULL;
        header.count--;
        free(ptr);
        return 0;
    } else {
        node_t *ptr = header.fptr;
        header.fptr = ptr->next;
        header.count--;
        free(ptr);
        return 0;
    }
}