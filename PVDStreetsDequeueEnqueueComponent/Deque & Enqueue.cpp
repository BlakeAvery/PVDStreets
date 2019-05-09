#include<stdio.h>
#include<stdlib.h>
#include<cstring>

//define structure car_s
typedef struct car_s
{	
	int cnum;//4Bytes
	int csize;//4Bytes
	struct car_s *next_s=NULL;//4 Bytes
}car_s;//8 Bytes

//define structure st_s
typedef struct st_s
{
	int cars;//4 Bytes
	int max;
	int st;//4 Bytes
	int light;//4 Bytes
	struct st_s *right=NULL;//4 Bytes
	struct st_s *left=NULL;//4 Bytes
	struct st_s *straight=NULL;//4Bytes
	struct car_s *fptr=NULL;//4 Bytes
	struct car_s *rptr=NULL;//4 Bytes
}st_s;

//enqueue function, need street structure you want to add a car into, and car pointer pointing  
int enque(st_s &street,car_s *dptr){
		
	street.rptr->next_s=dptr;
	street.rptr=dptr;
	dptr->next_s=NULL;
	street.cars++;
	
	return 0;
}

//dequeue function. need street structure you want to remove a car from.
//remove the first car from a street
car_s* deque(st_s &street){
	
	car_s *dptr;
	dptr=street.fptr;
	street.fptr=street.fptr->next_s;
	street.cars--;
	dptr->next_s=NULL;	
	
	return dptr;
}

int pcars(st_s street){
	printf("\n\nCars in Street%d",street.st);
	//define new, current, and previous pointers.
	car_s *cptr;
	car_s *pptr;
	
	//set pointer at the header
	cptr=street.fptr;
	pptr=street.fptr;
	printf("\nª");
	while(cptr!=NULL){//scan all nodes until reach the final node and print each node
			
		printf("\nCar number:%d ",cptr->cnum);//print car number
		pptr=cptr;//the previous pointer keep the address pointed by the current pointer 
		cptr=cptr->next_s;//the current pointer points the next node
		}

return 0;
}

inist(st_s &street){
	
	int cnum;
	char eof[4];//4B for age
	FILE * pFile;//file pointer
	pFile = fopen ("Cars.txt","r");//open file "Cars.txt" and "r"(read)
	
	//define new pointer.
	car_s *nptr;
	
	if(pFile!=NULL){//when the file is not empty
	
	while(street.cars!=street.max){//until reader reaches "eof"
	
	fscanf (pFile,"%d %s\n",&cnum,eof);//scan file, get name and age
	if(strcmp(eof,"eof")!=0){//when find eof
		//printf ("I have read:%s %i\n",name,age);
		//new pointer points available space
		
		nptr=(car_s*)malloc(sizeof(car_s));
		
		
		nptr->cnum=cnum;//assign car number into the new node
		nptr->next_s=NULL;//the new node points null
		if(street.fptr==NULL){
			street.fptr=nptr;
			street.rptr=nptr;
			street.cars++;
			
		}
		
		else{
			street.rptr->next_s=nptr;
			street.rptr=nptr;
			street.cars++;
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

trans(st_s &from, st_s &to){
	car_s *eptr;
	eptr=deque(from);//dequeue the first car from street1
	enque(to,eptr);//enqueue the dequeued car 8
	return 0;
}

//main function
//Simulate transfering car from street1 to 2
int main(void){
	
	st_s Street1;
	Street1.max=5;
	Street1.st=1;
	inist(Street1);//initialize street1
	pcars(Street1);//print all cars on street1
	
	st_s Street2;
	Street2.max=10;
	Street2.st=2;
	inist(Street2);//initialize street2
	pcars(Street2);//print all cars on street2
	
	int time=0;
	int ptime=0;
	printf("\n\nHow many seconds passed?:");
	scanf("%d",&ptime);
	time=time+ptime;
	
	int i;
	for(i=0;i<ptime;i++){//1car go forward the length of one car
	trans(Street1, Street2);
	}
	
	//car_s car=deque(Street1);//dequeue the first car from street1
	//enque(Street1,car);//enqueue the dequeued car 
	pcars(Street1);//print all cars
	pcars(Street2);//print all cars on street1
	
	return 0;
}
