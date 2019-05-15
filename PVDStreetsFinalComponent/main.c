#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car_t { //defines the structure of a node in the list
    long id; //identification number of car
    char turn_dir; //0 for straight, 1 for left, 2 for right. Determined at end of queue.
    long time_in_system; //increments on engine loop. Counts how long car is in simulation.
    int street_tracker[20];
    struct street_t *cur_street;
    struct car_t *next;
}car_t;

typedef struct street_t { //defines structure of the street_t header
    car_t *fptr;
    char name[30];
    int count; //Represents max amount of cars the street_t can hold
    int traffic_light_status; //Status of traffic light at end of this queue
    int timer;
    int arrival_rate; //Is only defined for entry points, amount of engine runs that it takes to have one car enter. If not entry, 0.
    int exit_rate;
    struct street_t *street_str; //Pointer to next street_t queue that this street_t leads to straight
    struct street_t *street_left; //left
    struct street_t *street_right; //right - If one of these three are null we can't go this direction
    //to fill in more
    car_t *rptr;
}street_t;

int main() {
    //First declare street variables
    street_t pine1,
    pine2, pine3, pine4;
    street_t page1, richmond1, chestnut1;
    street_t weybosset1, weybosset2, weybosset3, weybosset4, weybosset5,
    weybosset6, weybosset7, weybosset8, weybosset9, weybosset10;
    street_t dorrance1, dorrance2, dorrance3, dorrance4, dorrance5;
    street_t empire1, empire2;
    street_t westminister1, westminister2, westminister3, westminister4;

    //then, street metadata
    strcpy(pine4.name, "Pine exit left");
    pine4.street_str = NULL;
    pine4.street_right = NULL;
    pine4.street_left = NULL;
    pine4.count = 2;
    pine4.arrival_rate = 0;

    strcpy(weybosset10.name, "Weybosset exit left");
    weybosset10.street_left = NULL;
    weybosset10.street_right = NULL;
    weybosset10.street_str = NULL;
    weybosset10.count = 2;
    weybosset10.arrival_rate = 0;

    strcpy(weybosset5.name, "Weybosset exit right");
    weybosset5.street_str = NULL;
    weybosset5.street_left = NULL;
    weybosset5.street_right = NULL;
    weybosset5.count = 2;
    weybosset5.arrival_rate = 0;

    strcpy(dorrance3.name, "Dorrance Exit Bottom");
    dorrance3.street_str = NULL;
    dorrance3.street_left = NULL;
    dorrance3.street_right = NULL;
    dorrance3.count = 2;
    dorrance3.arrival_rate = 0;

    strcpy(westminister4.name, "Westminister exit left");
    westminister4.street_str = NULL;
    westminister4.street_left = NULL;
    westminister4.street_right = NULL;
    westminister4.count = 2;
    westminister4.arrival_rate = 0;

    strcpy(westminister2.name, "Westminister/Dorrance");
    westminister2.street_str = &westminister1;
    westminister2.street_right = NULL;
    westminister2.street_left = NULL;
    westminister2.count = 39;
    westminister2.arrival_rate = 0;

    strcpy(dorrance1.name, "Dorrance/Weybosset north");
    dorrance1.street_str = NULL;
    dorrance1.street_left = &westminister2;
    dorrance1.street_right = NULL;
    dorrance1.count = 22;
    dorrance1.arrival_rate = 0;

    strcpy(weybosset4.name, "Weybosset/Dorrance right");
    weybosset4.street_str = &weybosset8;
    weybosset4.street_left = &page1;
    weybosset4.street_right = NULL;
    weybosset4.count = 15;

    strcpy(dorrance5.name, "Dorrance/Weybosset south");
    dorrance5.street_str = &dorrance2;
    dorrance5.street_left = &weybosset5;
    dorrance5.street_right = &weybosset4;
    dorrance5.count = 22;
    dorrance5.arrival_rate = 0;

    strcpy(dorrance4.name, "Dorrance entry Botttom/Pine");
    dorrance4.street_str = &dorrance1;
    dorrance4.street_right = &weybosset5;
    dorrance4.street_left = &weybosset4;
    dorrance4.count = 22;
    dorrance4.arrival_rate = 5;

    strcpy(pine1.name, "Pine Right/page");
    pine1.street_str = &pine2;
    pine1.street_right = &dorrance4;
    pine1.street_left = &dorrance3;
    pine1.count = 22;
    pine1.arrival_rate = 0;

    strcpy(dorrance2.name, "Dorrance/Pine");
    dorrance2.street_str = NULL;
    dorrance2.street_left = NULL;
    dorrance2.street_right = &pine1;
    dorrance2.count = 22;
    dorrance2.arrival_rate = 0;

    strcpy(weybosset9.name, "Weybosset/Dorrance left");
    weybosset9.street_str = &weybosset5;
    weybosset9.street_left = &dorrance1;
    weybosset9.street_right = &dorrance2;
    weybosset9.count = 15;
    weybosset9.arrival_rate = 0;

    strcpy(page1.name, "Page st");
    page1.street_str = NULL;
    page1.street_left = NULL;
    page1.street_right = &pine2;
    page1.count = 27;
    page1.arrival_rate = 0;

    strcpy(weybosset3.name, "Weybosset/Matthewson/Page left");
    weybosset3.street_str = &weybosset9;
    weybosset3.street_left = &page1;
    weybosset3.street_right = NULL;
    weybosset3.count = 15;
    weybosset3.arrival_rate = 0;

    strcpy(weybosset7.name, "Weybosset/Richmond right");
    weybosset7.street_str = &weybosset5;
    weybosset7.street_left = &chestnut1;
    weybosset7.street_right = &empire2;
    weybosset7.count = 15;
    weybosset7.arrival_rate = 0;

    strcpy(richmond1.name, "Richmond st");
    richmond1.street_str = NULL;
    richmond1.street_left = &weybosset7;
    richmond1.street_right = &weybosset3;
    richmond1.count = 32;
    richmond1.arrival_rate = 0;

    strcpy(pine3.name, "Pine/Chestnut");
    pine3.street_str = &pine4;
    pine3.street_left = NULL;
    pine3.street_right = NULL;
    pine3.count = 22;
    pine3.arrival_rate = 0;

    strcpy(pine2.name, "Pine/Richmond");
    pine2.street_str = &pine3;
    pine2.street_left = NULL;
    pine2.street_right = &richmond1;
    pine2.count = 22;
    pine2.arrival_rate = 0;

    strcpy(weybosset2.name, "Weybosset/Richmond left");
    weybosset2.street_str = &weybosset3;
    weybosset2.street_left = NULL;
    weybosset2.street_right = NULL;
    weybosset2.count = 15;
    weybosset2.arrival_rate = 0;

    strcpy(chestnut1.name, "Chestnut st");
    chestnut1.street_str = NULL;
    chestnut1.street_left = NULL;
    chestnut1.street_right = &pine4;
    chestnut1.count = 23;
    chestnut1.arrival_rate = 0;

    strcpy(empire1.name, "Empire south");
    empire1.street_str = &chestnut1;
    empire1.street_right = &weybosset10;
    empire1.street_left =  &weybosset2;
    empire1.count = 23;
    empire1.arrival_rate = 0;

    strcpy(westminister1.name, "Westminister/Matthewson");
    westminister1.street_str = &westminister4;
    westminister1.street_right = NULL;
    westminister1.street_left = &empire1;
    westminister1.count = 39;
    westminister1.arrival_rate = 0;

    street_t matthewson1;
    strcpy(matthewson1.name, "Matthewson st");
    matthewson1.street_str = NULL;
    matthewson1.street_left = &westminister1;
    matthewson1.street_right = NULL;
    matthewson1.count = 36;
    matthewson1.arrival_rate = 0;

    strcpy(weybosset8.name, "Weybosset/Matthewson/Page right");
    weybosset8.street_str = &weybosset7;
    weybosset8.street_left = NULL;
    weybosset8.street_right = &matthewson1;
    weybosset8.count = 15;
    weybosset8.arrival_rate = 0;

    strcpy(empire2.name, "Empire north");
    empire2.street_str = NULL;
    empire2.street_left = &westminister4;
    empire2.street_right = NULL;
    empire2.count = 23;
    empire2.arrival_rate = 0;

    strcpy(weybosset1.name, "Weybosset entry left");
    weybosset1.street_right = &chestnut1;
    weybosset1.street_str = &weybosset2;
    weybosset1.street_left = &empire2;
    weybosset1.count = 2;
    weybosset1.arrival_rate = 4;

    strcpy(weybosset6.name, "Weybosset entry right");
    weybosset6.street_str = &weybosset4;
    weybosset6.street_left = &dorrance2;
    weybosset6.street_right = &dorrance1;
    weybosset6.count = 2;
    weybosset6.arrival_rate = 5;

    strcpy(westminister3.name, "Westminister entry right");
    westminister3.street_str = &westminister2;
    westminister3.street_left = &dorrance5;
    westminister3.street_right = NULL;
    westminister3.count = 2;
    westminister3.arrival_rate = 6;

    return 0;
}