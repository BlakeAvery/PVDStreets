#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include <unistd.h>

//define structure car_s
typedef struct car_s
{	
	int cnum;//4Bytes
	int will;//1:left, 2:straight, 3:right
	struct car_s *next_s;//4 Bytes
}car_s;//8 Bytes

//define structure st_s
typedef struct st_s
{
	int cars;//4 Bytes
	int ncars;//the number of null cars
	int max;
	int light;//4 Bytes
	int spawn;//how many seconds need to spawn car
	int entry;
	int exit;
	char name[20];//20Bytes
	struct st_s *right=NULL;//4 Bytes
	struct st_s *left=NULL;//4 Bytes
	struct st_s *str=NULL;//4Bytes
	struct car_s *fptr=NULL;//4 Bytes
	struct car_s *rptr=NULL;//4 Bytes
}st_s;

//print current time
ptime(int time){
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

/*
int pcars(st_s street[]){
	int i;
	int S=25;//#of streets
	for(i=1;i<=S;i++){
		printf("\n%s\n",street[i].name);
		//define new, current, and previous pointers.
		car_s *cptr;
		car_s *pptr;
		
		//set pointer at the header
		cptr=street[i].fptr;
		pptr=street[i].fptr;
		while(cptr!=NULL){//scan all nodes until reach the final node and print each node
				
			printf("©%d",cptr->cnum);//print car number
			pptr=cptr;//the previous pointer keep the address pointed by the current pointer 
			cptr=cptr->next_s;//the current pointer points the next node
			}
	}
	return 0;
}
*/

int pcars(st_s street[],st_s ent[], st_s exit[]){
	int i;
	int E=6;//#of entrances
	int X=6;//#of exits
	int S=25;//#of streets
	
	printf("\n\nOn streets\n");
	for(i=1;i<=S;i++){
		
		//define new, current, and previous pointers.
		car_s *cptr;
		car_s *pptr;
		
		//set pointer at the header
		cptr=street[i].fptr;
		pptr=street[i].fptr;
		printf("\n");
		while(cptr!=NULL){//scan all nodes until reach the final node and print each node
				
			printf("%d ",cptr->cnum);//print car number
			pptr=cptr;//the previous pointer keep the address pointed by the current pointer 
			cptr=cptr->next_s;//the current pointer points the next node
			}
	}
	
	printf("\n\nEntering Cars\n");
	for(i=1;i<=E;i++){
		
		//define new, current, and previous pointers.
		car_s *cptr;
		car_s *pptr;
		
		//set pointer at the header
		cptr=ent[i].fptr;
		pptr=ent[i].fptr;
		printf("\n");
		if(cptr!=NULL){
			while(cptr!=NULL){//scan all nodes until reach the final node and print each node
				
			printf("%d,%d ",i,cptr->cnum);//print car number
			pptr=cptr;//the previous pointer keep the address pointed by the current pointer 
			cptr=cptr->next_s;//the current pointer points the next node
			}
		}
	
	}
	
	printf("\n\nCars leaving\n");
	for(i=1;i<=X;i++){
		
		//define new, current, and previous pointers.
		car_s *cptr;
		car_s *pptr;
		
		//set pointer at the header
		cptr=exit[i].fptr;
		pptr=exit[i].fptr;
		//printf("\n");
		if(cptr!=NULL){
			while(cptr=NULL){//scan all nodes until reach the final node and print each node
				
			printf("%d ",cptr->cnum);//print car number
			pptr=cptr;//the previous pointer keep the address pointed by the current pointer 
			cptr=cptr->next_s;//the current pointer points the next node
			}
		}
		
	}
	return 0;
}

int pbar(st_s street[]){
	int i;
	int N=25;//#of streets
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


int inist(st_s street[],st_s ent[], st_s exit[]){
	
	strcpy(street[1].name,"Westminster W1");//assign name into the new node
	street[1].max=95;	
	street[1].str=&exit[1];
	street[1].left=&street[5];
			
	
	strcpy(street[2].name,"Westminster W2");//assign name into the new node
	street[2].max=95;
	street[2].str=&street[1];
		
	strcpy(street[3].name,"Westminster E1");//assign name into the new node
	street[3].max=95;
	street[3].str=&street[4];
	
	strcpy(street[4].name,"Westminster E2");//assign name into the new node
	street[4].max=95;
	street[4].str=&exit[2];
	street[4].right=&street[8];
	
	strcpy(street[5].name,"Empire S");//assign name into the new node
	street[5].max=57;
	street[5].str=&street[14];
	street[5].left=&street[12];
	street[5].right=&exit[3];
	
	strcpy(street[6].name,"Empire N");//assign name into the new node
	street[6].max=57;
	street[6].left=&exit[1];
	street[6].right=&street[3];
	
	strcpy(street[7].name,"Mathewson");//assign name into the new node
	street[7].max=40;
	street[7].left=&street[1];
	street[7].right=&street[4];
	
	strcpy(street[8].name,"Dorrace S1");//assign name into the new node
	street[8].max=40;
	street[8].str=&street[17];
	street[8].left=&exit[4];
	street[8].right=&street[11];
	
	strcpy(street[9].name,"Dorrace N1");//assign name into the new node
	street[9].max=40;
	street[9].left=&street[2];
	street[9].right=&exit[2];
	
	strcpy(street[10].name,"Weybosset W1");//assign name into the new node
	street[10].max=60;
	street[10].str=&exit[3];
	street[10].left=&street[14];
	street[10].right=&street[6];
	
	strcpy(street[11].name,"Weybosset W2");//assign name into the new node
	street[11].max=60;
	street[11].str=&street[22];
	street[11].left=&street[16];
	
	strcpy(street[12].name,"Weybosset E1");//assign name into the new node
	street[12].max=60;
	street[12].str=&street[23];
	street[12].right=&exit[15];

	strcpy(street[13].name,"Weybosset E2");//assign name into the new node
	street[13].max=60;
	street[13].str=&exit[4];
	street[13].left=&street[9];
	street[13].right=&street[17];
	
	strcpy(street[14].name,"Chestnut");//assign name into the new node
	street[14].max=57;
	street[14].right=&exit[5];
	
	strcpy(street[15].name,"Richmond");//assign name into the new node
	street[15].max=30;
	street[15].left=&street[10];
	street[15].right=&street[23];
	
	strcpy(street[16].name,"Page");//assign name into the new node
	street[16].max=29;
	street[16].right=&street[25];
	
	strcpy(street[17].name,"Dorrace S2");//assign name into the new node
	street[17].max=60;
	street[17].str=&exit[6];
	street[17].right=&street[20];

	strcpy(street[18].name,"Dorrace N2");//assign name into the new node
	street[18].max=60;
	street[18].str=&street[14];
	street[18].left=&street[12];
	street[18].right=&exit[3];
	
	strcpy(street[19].name,"Pine 1");//assign name into the new node
	street[19].max=40;
	street[19].str=&exit[5];

	strcpy(street[20].name,"Pine 2");//assign name into the new node
	street[20].max=40;
	street[20].str=&street[25];
		
	strcpy(street[21].name,"Weybosset W3");//assign name into the new node
	street[21].max=10;
	street[21].str=&street[10];
		
	strcpy(street[22].name,"Weybosset W4");//assign name into the new node
	street[22].max=10;
	street[22].str=&street[21];
	street[22].right=&exit[7];
	
	strcpy(street[23].name,"Weybosset E3");//assign name into the new node
	street[23].max=10;
	street[23].str=&street[24];
	street[23].left=&street[7];
		
	strcpy(street[24].name,"Weybosset E4");//assign name into the new node
	street[24].max=10;
	street[24].str=&street[13];
	street[24].right=&exit[16];
	
	strcpy(street[25].name,"Pine 3");//assign name into the new node
	street[25].max=15;
	street[25].str=&street[19];
	street[25].right=&exit[15];
	
	ent[1].right=&street[5];
	ent[1].str=&street[3];
	ent[1].spawn=7;
	
	ent[2].left=&street[8];
	ent[2].str=&street[2];
	ent[2].spawn=14;
	
	ent[3].left=&street[6];
	ent[3].str=&street[12];
	ent[3].spawn=8;
	
	ent[4].right=&street[9];
	ent[4].str=&street[11];
	ent[4].left=&street[17];
	ent[4].spawn=10;
	
	ent[5].right=&street[18];
	ent[5].str=&street[20];
	ent[5].left=&exit[6];
	ent[5].spawn=15;
	
	ent[6].str=&street[18];
	ent[6].left=&street[20];
	ent[6].spawn=15;
		
	int i;
	
	for(i=1;i<=25;i++){
		street[i].cars=0;
	}
	//define new pointer.
	car_s *nptr;
	
	for(i=1;i<=25;i++){//when the file is not empty
	int j;
	for(j=0;j<street[i].max;j++){//until reader reaches "eof"
	
		//new pointer points available space
		
		nptr=(car_s*)malloc(sizeof(car_s));
				
		nptr->cnum=NULL;//assign car number into the new node
		nptr->next_s=NULL;//the new node points null
		if(street[i].fptr==NULL){
			street[i].fptr=nptr;
			street[i].rptr=nptr;	
		}
		
		else{
			street[i].rptr->next_s=nptr;
			street[i].rptr=nptr;
			//printf("\n%d,%d", street[i].max,street[i].cars);
		}
		}
		
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

int trans(st_s street[],int from,int to){
	car_s *eptr;
	eptr=deque(street,from);//dequeue the first car from street1
	enque(street,to,eptr);//enqueue the dequeued car 8
	return 0;
}

int newcar(st_s ent[],st_s street[], st_s exit[],int time, int &id){
	
	int i;
	
	if(time!=0){
		for(i=1;i<=6;i++){
			
			
			if(time%ent[i].spawn==0){
				
				//define new pointer.
				car_s *nptr;
				nptr=(car_s*)malloc(sizeof(car_s));
				
				id++;
				nptr->cnum=id;
				nptr->next_s=NULL;//the new node points null
				
				if(ent[i].fptr==NULL){
					ent[i].fptr=nptr;
					ent[i].rptr=nptr;
					ent[i].cars++;
				
				}
				
				else{
					ent[i].rptr->next_s=nptr;
					ent[i].rptr=nptr;
					ent[i].cars++;
				}
			
		}
	}
	
}

return 0;
}


int light(st_s street[],st_s ent[],int time){
	int i=1;
	int E=6;//#of entrances
	int X=6;//#of exits
	int S=25;//#of streets
	if(time==0){
		for(i=1;i<=S;i++){
		street[i].light=1;
	}
	
	}
	else{
		if(time%72<32){
			for(i=1;i<=S;i++){
		street[i].light=1;
		}
		}
		
		else{
				for(i=1;i<=S;i++){
		street[i].light=0;
		}
			
		}
		
	}
	
	for(i=1;i<=E;i++){
		ent[i].light=1;
	}
	
	if(time==0){
		for(i=1;i<=E;i++){
		ent[i].light=1;
	}
}
	
	else{
		if(time%72<32){
			for(i=1;i<=E;i++){
		ent[i].light=1;
		}
		}
		
		else{
				for(i=1;i<=E;i++){
		ent[i].light=0;
		}
			
		}
		
	}
	return 0;
}

int smove(st_s street[], st_s exit[],int time){
	
	int i=1;
	int E=6;//#of entrances
	int X=6;//#of exits
	int S=25;//#of streets
	
	for(i=1;i<=S;i++){
		
		if(street[i].fptr->cnum==NULL){
			car_s *dptr;
			dptr=deque(street,i);
			enque(street,i,dptr);			
		}
		
		else{
			if(street[i].light==0){
				
				//define current, and previous pointers.
				car_s *cptr;
				car_s *pptr;
				car_s *kptr;
				
				//set pointers at the header
				cptr=street[i].fptr;
				pptr=street[i].fptr;
				kptr=street[i].fptr;
				pptr=cptr;//the previous pointer keep the address pointed by the current pointer 
				cptr=cptr->next_s;//the current pointer points the next node
				while(cptr!=NULL){//scan all nodes until reach the final node and print each node
				if(cptr->cnum!=NULL&&pptr->cnum==NULL){
					kptr->next_s=cptr;
					pptr->next_s=cptr->next_s;
					cptr->next_s=pptr;
					cptr=pptr;
					pptr=kptr->next_s;
				}
							
				kptr=pptr;
				pptr=cptr;//the previous pointer keep the address pointed by the current pointer 
				cptr=cptr->next_s;//the current pointer points the next node
			
				}
				printf("How many seconds do you want to run it?:");
			}
			
			else if(street[i].light==1){
			int go=0;
			//decide which way will a car go
			while(go==0){
			
			int random=rand();
			if(random==1){
				if(street[i].left==NULL){
					go=0;
				}
				else{
					go=1;
					street[i].fptr->will=1;
				}
			}
			else if(random==2){
				if(street[i].str==NULL){
					go=0;
				}
				else{
					go=1;
					street[i].fptr->will=2;
				}
			}
			
			else if(random==3){
				if(street[i].right==NULL){
					go=0;
				}
				else{
					go=1;
					street[i].fptr->will=3;
				}
			}
			}
			
			car_s *tptr;
			tptr=deque(street,i);
			
			if(street[i].fptr->will==1){
					street[i].left->rptr->next_s=tptr;
					street[i].rptr=tptr;
					tptr->next_s=NULL;
					street[i].left->cars++;
			}
			else if(street[i].fptr->will==2){
					street[i].str->rptr->next_s=tptr;
					street[i].rptr=tptr;
					tptr->next_s=NULL;
					street[i].left->cars++;
			}
			
			else if(street[i].fptr->will==3){
					street[i].right->rptr->next_s=tptr;
					street[i].rptr=tptr;
					tptr->next_s=NULL;
					street[i].left->cars++;
			}
							
			}
		
	
		
		}
		}
		
	return 0;
}

int emove(st_s street[], st_s ent[],int time){
	
	int i=1;
	int E=6;//#of entrances
	int X=6;//#of exits
	int S=25;//#of streets
	
	for(i=1;i<=E;i++){
		
		/*if(){
			car_s *dptr;
			dptr=deque(ent,i);
			enque(ent,i,dptr);			
		}*/
		
		if(ent[i].fptr!=NULL){
			if(ent[i].light==1){
			int go=0;
			
			//decide which way will a car go
			while(go==0){
			
			int random=rand();
			random=random%3;
			
			if(random==1){
				if(ent[i].left==NULL){
					go=0;
				}
				else{
					go=1;
						
					ent[i].fptr->will=1;
					
				}
			}
			else if(random==2){
				if(ent[i].str==NULL){
					go=0;
					
				}
				else{
					go=1;
					ent[i].fptr->will=2;
					
				}
			}
			
			else if(random==3){
				if(ent[i].right==NULL){
					go=0;
				}
				else{
					go=1;
					ent[i].fptr->will=3;
				}
			}
			}
			
			
			car_s *dptr;
			dptr=ent[i].fptr;
			if(ent[i].fptr->next_s!=NULL){
				ent[i].fptr=ent[i].fptr->next_s;
			}
			dptr->next_s=NULL;
			
			printf("\n%d,%d,%d",i,ent[i].fptr->will,go);
			if(ent[i].fptr->will==1){
					
					ent[i].left->rptr->next_s=dptr;
					ent[i].rptr=dptr;
			printf("\n%d,%d,%d",i,ent[i].fptr->will,go);
					ent[i].left->cars++;
						
			}
			
			else if(ent[i].fptr->will==2){	
					
					ent[i].str->rptr->next_s=dptr;
					ent[i].rptr=dptr;
				
					ent[i].str->cars++;
			printf("\n%d,%d,%d",i,ent[i].fptr->will,go);		
			}
			
			else if(ent[i].fptr->will==3){
					
					ent[i].right->rptr->next_s=dptr;
					ent[i].rptr=dptr;
							
					ent[i].right->cars++;
					printf("\n%d,%d",i,ent[i].fptr->will);	
						
			}
							
			}
				
		}
		
		}
		
	return 0;
}


int count(st_s street){
	int i=1;
	int E=6;//#of entrances
	int X=6;//#of exits
	int S=25;//#of streets
	
	for(i=1;i<=S;i++){
	car_s *cptr;
	while(cptr!=NULL){//scan all nodes until reach the final node and print each node
			
			cptr=cptr->next_s;//the current pointer points the next node
			}
	}
	return 0;
}


int main(){
	
	st_s street[26];
	st_s ent[7];
	st_s exit[7];
	
	
	inist(street,ent,exit);
	
	int time=0;
	int runtime=0;
	int id=1000;
	float slptime=0;
	printf("How many seconds do you want to run it?:");
	scanf("%d",&runtime);
		
	while(runtime>=time){
	system("cls");
	ptime(time);
	prate(time,40,50);
	light(street,ent,time);

	smove(street,exit,time);
	emove(street,ent,time);
	
	newcar(ent,street,exit,time,id);
	
	pbar(street);
	pcars(street,ent,exit);
	
	time++;
	//trans(Street,2,1);
	usleep(slptime);//sleep 1sec
	}
	
	return 0;
}
