#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include <unistd.h>

/*
 * Changes made - Refactored code a little for aesthetic purposes for easier integration
 * into FinalComponent.
 */

//define structure car_s
typedef struct car_s {
	int cnum;//4Bytes
	int csize;//4Bytes
	struct car_s *next_s=NULL;//4 Bytes
}car_s;//8 Bytes

//define structure st_s
typedef struct st_s {
	int cars;//4 Bytes
	int max;
	int light;//4 Bytes
	char name[20];//20Bytes
	struct st_s *right=NULL;//4 Bytes
	struct st_s *left=NULL;//4 Bytes
	struct st_s *straight=NULL;//4Bytes
	struct car_s *fptr=NULL;//4 Bytes
	struct car_s *rptr=NULL;//4 Bytes
}st_s;

//print current time
int ptime(int time){
	//system("cls");//clean the screen
	int min;//define time units
	int hour;
	int sec;
	int day;
	
	sec=time%60;//derive each value from running time(sec) into Day, HH:MM:SS
	min=time/60;
	min=min%60;
	hour=time/60/60;
	hour=hour%24;
	day=time/60/60/24;
	
	printf("Day%d, %02d:%02d:%02d",day,hour,min,sec);//print time
	return 0;
}

//Arrival/exit rate generator
int prate(int time,int arrival,int exit){
	
	if(time==0){
		printf("  Arrival Rate:- cars/sec");
		printf("  Exit Rate:- cars/sec");
	}
	
	else{
		float rarrival;
		rarrival=arrival/time;
		float rexit;
		rexit=exit/time;
		
		printf("  Arrival Rate:%.2f/sec",rarrival);
		printf("  Exit Rate:%.2f/sec",rexit);
	}
	
	return 0;
}

//prints out car information
int pcars(st_s street[]){
	int i;
	int N=2;//#of streets

	for(i=1;i<=N;i++){
		printf("\n%s\n",street[i].name);
		//define new, current, and previous pointers.
		car_s *cptr;
		car_s *pptr;
		
		//set pointer at the header
		cptr=street[i].fptr;
		pptr=street[i].fptr;

		while(cptr!=NULL){//scan all nodes until reach the final node and print each node
			printf("←%d",cptr->cnum);//print car number
			pptr=cptr;//the previous pointer keep the address pointed by the current pointer 
			cptr=cptr->next_s;//the current pointer points the next node
		}
	}
	return 0;
}

//also prints out car info
int pcars(st_s street[],char system[]){
	int i;
	int N=2;//#of streets
	printf("\n\n%s\n",system);
	for(i=1;i<=N;i++){
		
		//define new, current, and previous pointers.
		car_s *cptr;
		car_s *pptr;
		
		//set pointer at the header
		cptr=street[i].fptr;
		pptr=street[i].fptr;
		//printf("\n");
		while(cptr!=NULL){//scan all nodes until reach the final node and print each node
				
			printf("%d ",cptr->cnum);//print car number
			pptr=cptr;//the previous pointer keep the address pointed by the current pointer 
			cptr=cptr->next_s;//the current pointer points the next node
			}
	}
	return 0;
}

//print out progress bar for each street queue
int pbar(st_s street[]){
	int i;
	int N=2;//#of streets
	for(i=1;i<=N;i++){
		
		printf("\n\n%-15s|",street[i].name);
		int j;
		for(j=0;j<street[i].cars;j++){
			printf("]");
		}
		printf(" %d",street[i].cars);
	}
	return 0;
}

//set up street queue
int inist(st_s street[],int st){
	
	street[st].cars=0;
	int cnum;
	char eof[4];//check char for eof
	FILE * pFile;//file pointer
	pFile = fopen ("Cars.txt","r");//open file "Cars.txt" and "r"(read)
	
	//define new pointer.
	car_s *nptr;
	
	if(pFile!=NULL){//when the file is not empty
	
	while(street[st].cars!=street[st].max){//until reader reaches "eof"
	
	fscanf (pFile,"%d %s\n",&cnum,eof);//scan file, get name and age
	if(strcmp(eof,"eof")!=0){//when find eof
		//printf ("I have read:%s %i\n",name,age);
		//new pointer points available space
		
		nptr=(car_s*)malloc(sizeof(car_s));
		
		
		nptr->cnum=cnum;//assign car number into the new node
		nptr->next_s=NULL;//the new node points null
		if(street[st].fptr==NULL){
			street[st].fptr=nptr;
			street[st].rptr=nptr;
			street[st].cars++;
			
		}
		
		else{
			street[st].rptr->next_s=nptr;
			street[st].rptr=nptr;
			street[st].cars++;
		}
		}	
	else{
			break;
		}
		}
	fclose (pFile);//close the file
	
	}
	  
	else{//if the file is empty
		printf ("I could not read\n");
		}
	return 0;	
}

//enqueue function, need street structure you want to add a car into, and car pointer pointing  
int enque(st_s street[],int st,car_s *dptr){
		
	street[st].rptr->next_s=dptr;
	street[st].rptr=dptr;
	dptr->next_s=NULL;
	street[st].cars++;
	
	return 0;
}

//dequeue function. need street structure you want to remove a car from.
//remove the first car from a street
car_s* deque(st_s street[],int st){
	
	car_s *dptr;
	dptr=street[st].fptr;
	street[st].fptr=street[st].fptr->next_s;
	street[st].cars--;
	dptr->next_s=NULL;	
	
	return dptr;
}

//Move between queues
int trans(st_s street[],int from,int to){
	car_s *eptr;
	eptr=deque(street,from);//dequeue the first car from street1
	enque(street,to,eptr);//enqueue the dequeued car 8
	return 0;
}

int main(){
	
	st_s Street[3];
	strcpy(Street[1].name,"Kazuki");//assign name into the new node
	Street[1].max=5;
	inist(Street,1);//initialize street1
	
	strcpy(Street[2].name,"Jared");//assign name into the new node
	Street[2].max=10;
	inist(Street,2);//initialize street2
	
	
	int time=0;
	int runtime=0;
	printf("How many seconds do you want to run it?:");
	scanf("%d",&runtime);
		
	while(runtime>=time){
	system("cls");
	ptime(time);
	prate(time,40,50);
	
	char system[]="On streets";
	pcars(Street,system);//print all cars on street2
	pbar(Street);
	time++;
	trans(Street,1,2);
	//trans(Street,2,1);
	sleep(2);//sleep 1sec
	}
	
	return 0;
}
