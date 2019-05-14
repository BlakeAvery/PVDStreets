#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car_t { //defines the structure of a node in the list
    long id; //identification number of car
    char turn_dir; //0 for straight, 1 for left, 2 for right. Determined at end of queue.
    long time_in_system; //increments on engine loop. Counts how long car is in simulation.
    int street_tracker[20];
    struct car_t *next;
}car_t;

typedef struct street_t { //defines structure of the street_t header
    car_t *fptr;
    char name[30];
    int count; //Represents max amount of cars the street_t can hold
    int traffic_light_status; //Status of traffic light at end of this queue
    int timer;
    int arrival_rate;
    int exit_rate;
    struct street_t *street_str; //Pointer to next street_t queue that this street_t leads to straight
    struct street_t *street_left; //left
    struct street_t *street_right; //right - If one of these three are null we can't go this direction
    //to fill in more
    car_t *rptr;
}street_t;

int main() {
    //First, let's define metadata for the streets.
    street_t pine4;
    strcpy(pine4.name, "Pine exit left");
    pine4.street_str = NULL;
    pine4.street_right = NULL;
    pine4.street_left = NULL;

    street_t pine2;
    strcpy(pine2.name, "Pine/Richmond");


    street_t empire2;
    strcpy(empire2.name, "Empire north");

    street_t chestnut1;
    strcpy(chestnut1.name, "Chestnut st");

    street_t page1;
    strcpy(page1.name, "Page st");
    page1.street_str = NULL;
    page1.street_left = NULL;
    page1.street_right = &pine2;

    street_t weybosset9;
    strcpy(weybosset9.name, "Weybosset/Dorrance left");

    street_t weybosset3;
    strcpy(weybosset3.name, "Weybosset/Matthewson/Page left");
    weybosset3.street_str = &weybosset9;
    weybosset3.street_left = &page1;
    weybosset3.street_right = NULL;

    street_t weybosset2;
    strcpy(weybosset2.name, "Weybosset/Richmond");
    weybosset2.street_str = &weybosset3;
    weybosset2.street_left = NULL;
    weybosset2.street_right = NULL;

    street_t weybosset1;
    strcpy(weybosset1.name, "Weybosset entry left");
    weybosset1.street_right = &chestnut1;
    weybosset1.street_str = &weybosset2;
    weybosset1.street_left = &empire2;


    street_t weybosset4;
    strcpy(weybosset4.name, "Weybosset/Dorrance");


    street_t weybosset5;
    strcpy(weybosset5.name, "Weybosset exit right");


    street_t weybosset6;
    strcpy(weybosset6.name, "Weybosset entry right");


    street_t weybosset7;
    strcpy(weybosset7.name, "Weybosset/Richmond");


    street_t weybosset8;
    strcpy(weybosset8.name, "Weybosset/Matthewson/Page right");


    street_t weybosset10;
    strcpy(weybosset10.name, "Weybosset exit left");


    street_t westminister1;
    strcpy(westminister1.name, "Westminister entry left");


    street_t westminister2;
    strcpy(westminister2.name, "Westminister/Matthewson");


    street_t westminister3;
    strcpy(westminister3.name, "Westminister/Dorrance");


    street_t westminister4;
    strcpy(westminister4.name, "Westminister exit right");


    street_t westminister5;
    strcpy(westminister5.name, "Westminister entry right");


    street_t westminister6;
    strcpy(westminister6.name, "Westminister/Matthewson");


    street_t westminister7;
    strcpy(westminister7.name, "Westminister/Dorrance");


    street_t westminister8;
    strcpy(westminister8.name, "Westminister exit left");


    street_t dorrance1;
    strcpy(dorrance1.name, "Dorrance Top/Weybosset");


    street_t dorrance2;
    strcpy(dorrance2.name, "Dorrance/Pine");


    street_t dorrance3;
    strcpy(dorrance3.name, "Dorrance Exit Bottom");


    street_t dorrance4;
    strcpy(dorrance4.name, "Dorrance entry Botttom/Pine");


    street_t dorrance5;
    strcpy(dorrance5.name, "Dorrance/Weybosset");


    street_t dorrance6;
    strcpy(dorrance6.name, "Dorrance/Westminister");


    street_t pine1;
    strcpy(pine1.name, "Pine Right/page");


    street_t pine3;
    strcpy(pine3.name, "Pine/Chestnut");

    street_t richmond1;
    strcpy(richmond1.name, "Richmond st");



    street_t matthewson1;
    strcpy(matthewson1.name, "Matthewson st");


    street_t empire1;
    strcpy(empire1.name, "Empire south");

    return 0;
}