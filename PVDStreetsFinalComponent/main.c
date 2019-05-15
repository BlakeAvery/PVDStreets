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

    street_t weybosset10;
    strcpy(weybosset10.name, "Weybosset exit left");
    weybosset10.street_left = NULL;
    weybosset10.street_right = NULL;
    weybosset10.street_str = NULL;

    street_t weybosset5;
    strcpy(weybosset5.name, "Weybosset exit right");
    weybosset5.street_str = NULL;
    weybosset5.street_left = NULL;
    weybosset5.street_right = NULL;

    street_t dorrance3;
    strcpy(dorrance3.name, "Dorrance Exit Bottom");
    dorrance3.street_str = NULL;
    dorrance3.street_left = NULL;
    dorrance3.street_right = NULL;

    street_t dorrance2;
    strcpy(dorrance2.name, "Dorrance/Pine");

    street_t westminister2;
    strcpy(westminister2.name, "Westminister/Dorrance");

    street_t dorrance1;
    strcpy(dorrance1.name, "Dorrance/Weybosset north");
    dorrance1.street_str = NULL;
    dorrance1.street_left = &westminister2;
    dorrance1.street_right = NULL;

    street_t weybosset9;
    strcpy(weybosset9.name, "Weybosset/Dorrance left");
    weybosset9.street_str = &weybosset5;
    weybosset9.street_left = &dorrance1;
    weybosset9.street_right = &dorrance2;

    street_t page1, pine2;
    strcpy(page1.name, "Page st");
    page1.street_str = NULL;
    page1.street_left = NULL;
    page1.street_right = &pine2;

    street_t weybosset3;
    strcpy(weybosset3.name, "Weybosset/Matthewson/Page left");
    weybosset3.street_str = &weybosset9;
    weybosset3.street_left = &page1;
    weybosset3.street_right = NULL;

    street_t richmond1, pine3;
    strcpy(richmond1.name, "Richmond st");
    richmond1.street_str = NULL;
    richmond1.street_left = &weybossetnum;
    richmond1.street_right = &weybosset3;

    strcpy(pine3.name, "Pine/Chestnut");
    pine3.street_str = &pine4;
    pine3.street_left = NULL;
    pine3.street_right = NULL;

    //definitions for pine2, variable declared with page1
    strcpy(pine2.name, "Pine/Richmond");
    pine2.street_str = &pine3;
    pine2.street_left = NULL;
    pine2.street_right = &richmond1;

    street_t weybosset8;
    strcpy(weybosset8.name, "Weybosset/Matthewson/Page right");

    street_t weybosset4;
    strcpy(weybosset4.name, "Weybosset/Dorrance right");
    weybosset4.street_str = &weybosset8;
    weybosset4.street_left = &page1;
    weybosset4.street_right = NULL;

    street_t dorrance5;
    strcpy(dorrance5.name, "Dorrance/Weybosset south");
    dorrance5.street_str = &dorrance2;
    dorrance5.street_left = &weybosset5;
    dorrance5.street_right = &weybosset4;

    street_t dorrance4;
    strcpy(dorrance4.name, "Dorrance entry Botttom/Pine");
    dorrance4.street_str = &dorrance1;
    dorrance4.street_right = &weybosset5;
    dorrance4.street_left = &weybosset4;



    street_t pine1;
    strcpy(pine1.name, "Pine Right/page");
    pine1.street_str = &pine2;
    pine1.street_right = &dorrance4;
    pine1.street_left = &dorrance3;

    street_t westminister4;
    strcpy(westminister4.name, "Westminister exit left");
    westminister4.street_str = NULL;
    westminister4.street_left = NULL;
    westminister4.street_right = NULL;

    street_t chestnut1;
    strcpy(chestnut1.name, "Chestnut st");
    chestnut1.street_str = NULL;
    chestnut1.street_left = NULL;
    chestnut1.street_right = &pine4;

    street_t weybosset2;
    strcpy(weybosset2.name, "Weybosset/Richmond left");
    weybosset2.street_str = &weybosset3;
    weybosset2.street_left = NULL;
    weybosset2.street_right = NULL;

    street_t empire1;
    strcpy(empire1.name, "Empire south");
    empire1.street_str = &chestnut1;
    empire1.street_right = &weybosset10;
    empire1.street_left =  &weybosset2;

    street_t westminister1;
    strcpy(westminister1.name, "Westminister/Matthewson");
    westminister1.street_str = &westminister4;
    westminister1.street_right = NULL;
    westminister1.street_left = &empire1;

    street_t empire2;
    strcpy(empire2.name, "Empire north");
    empire2.street_str = NULL;
    empire2.street_left = &westminister4;
    empire2.street_right = NULL;

    street_t weybosset1;
    strcpy(weybosset1.name, "Weybosset entry left");
    weybosset1.street_right = &chestnut1;
    weybosset1.street_str = &weybosset2;
    weybosset1.street_left = &empire2;

    street_t weybosset6;
    strcpy(weybosset6.name, "Weybosset entry right");


    street_t weybosset7;
    strcpy(weybosset7.name, "Weybosset/Richmond");

    street_t westminister3;
    strcpy(westminister3.name, "Westminister entry right");
    westminister3.street_str = &westminister2;
    westminister3.street_left = &dorrance5;
    westminister3.street_right = NULL;

    /*street_t dorrance6;
    strcpy(dorrance6.name, "Dorrance/Westminister");*/

    street_t matthewson1;
    strcpy(matthewson1.name, "Matthewson st");
    matthewson1.street_str = NULL;
    matthewson1.street_left = &westminister1;
    matthewson1.street_right = NULL;

    return 0;
}