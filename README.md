# PVDStreets
CSIS 1112 Project 3
#include <stdio.h>
#include <stdlib.h>

// This code is for making all of the street queues.

typedef struct Street{
	char street_name[30];
	int light;
	int timer;
	int max;
	int rexit;
	int rarrival;
	int cars;
	struct Street * right;
	struct Street * left;
	struct Street * straight;
}street;


typedef struct car{
	typedef struct car_t { //defines the structure of a node in the list
    long id; //identification number of car
    char turn_dir; //0 for straight, 1 for left, 2 for right. Determined at end of queue.
    long time_in_system; //increments on engine loop. Counts how long car is in simulation.
    int street_tracker[20];
    struct car_t *next;
}car_t;

street weybosset1;
weybosset1.street_name = "Weybosset entry left";


street weybosset2;
weybosset2.street_name = "Weybosset/Richmond";


street weybosset3;
weybosset3.street_name = "Weybosset/Matthewson/Page";


street weybosset4;
weybosset4.street_name = "Weybosset/Dorrance";


street weybosset5;
weybosset5.street_name = "Weybosset exit right";


street weybosset6;
weybosset6.street_name = "Weybosset entry right";


street weybosset7;
weybosset7.street_name = "Weybosset/Richmond";


street weybosset8;
weybosset8.street_name = "Weybosset/Matthewson/Page";


street weybosset9;
weybosset9.street_name = "Weybosset/Dorrance";


street weybosset10;
weybosset10.street_name = "Weybosset exit left";


street westminister1;
westminister1.street_name = "Westminister entry left";


street westminister2;
westminister2.street_name = "Westminister/Matthewson";


street westminister3;
westminister3.street_name = "Westminister/Dorrance";


street westminister4;
westminister4.street_name = "Westminister exit right";


street westminister5;
westminister5.street_name = "Westminister entry right";


street westminister6;
westminister6.street_name = "Westminister/Matthewson";


street westminister7;
westminister7.street_name = "Westminister/Dorrance";


street westminister8;
westminister8.street_name = "Westminister exit left";


street dorrance1;
dorrance1.street_name = "Dorrance Top/Weybosset";


street dorrance2;
dorrance2.street_name = "Dorrance/Pine";


street dorrance3;
dorrance3.street_name = "Dorrance Exit Bottom";


street dorrance4;
dorrance4.street_name = "Dorrance entry Botttom/Pine";


street dorrance5;
dorrance5.street_name = "Dorrance/Weybosset";


street dorrance6;
dorrance6.street_name = "Dorrance/Westminister";


street pine1;
pine1.street_name = "Pine Right/page";


street pine2;
pine2.street_name = "Pine/Richmond";


street pine3;
pine3.street_name = "Pine/Chestnut";


street pine4;
pine4.street_name = "Pine exit left";


street page1;
street page1.street_name = "Page st";


street richmond1;
richmond1.street_name = "Richmond st";


street chestnut1;
chestnut1.street_name = "Chestnut st";


street matthewson1;
matthewson1.street_name = "Matthewson st";


street empire1;
empire1.street_name = "Empire south";


street empire2;
empire2.street_name = "Empire north";
