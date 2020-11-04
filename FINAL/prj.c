

#include"prj.h"

char * univ[6]={"Purdue", "Michigan", "IUPUI", "Louisville", "Illinois", "Cincinnatti"};
char *pos[4]={"systems engineer", "software engineer", "controls engineer", "engineering management"}; 

void fillData(struct anonApplication *X, int clockTime )
{
	int i;
	int numb;
	
	static int val=1001;
	
	X->appID=val;
	val+=1+(rand()%7);
	X->appDate=clockTime;
	X->timeIn=0;
	numb=rand()%4;
	strcpy(X->positionApplied, pos[numb]);
	numb=rand()%6;
	strcpy(X->university, univ[numb]);
	X->collegeGPA= 2.8 + 0.5*((rand()%3)>=1)+ 0.7*((rand()%100)/100.0);

	X->skillLevelCircDesign=1+(rand()%5);
	X->skillLevelPrjManage=1+(rand()%5);
	X->skillLevelProgramming=1+(rand()%5);
	X->nextApp=NULL;
}

struct anonApplication*checkForApp(struct anonApplication* head, int x){

	while(head!=NULL)
	{

		if(head->appID==x)
			break;
		head=head->nextApp;
	}

	return head;
}

struct anonApplication*makeInitialList(int clocktime)
{ 
	struct anonApplication*H;
	struct anonApplication*ptr;
	struct anonApplication*last;
	int i;


	H=(struct  anonApplication *)malloc(sizeof(struct  anonApplication ));

 fillData(H, clocktime );
 last=H;
	for(i=0;i<20;i++)
	{
		ptr=(struct  anonApplication *)malloc(sizeof(struct  anonApplication ));
        fillData(ptr, clocktime );
		last->nextApp=ptr;
		last=last->nextApp;
	}

	H=sortByAvgSkill(H);




	return H;
}

//goes in library
struct anonApplication *NewApplications(int clocktime)
{
	struct anonApplication *head;
	struct anonApplication *ptr, *prev;
	int num=3;
	int i;
	num=num+(rand()%5);
	


	head=(struct anonApplication *)malloc(sizeof(struct anonApplication));
	fillData(head, clocktime);
	prev=head;
	for(i=0; i<num-1;i++)
	{
		ptr=(struct anonApplication *)malloc(sizeof(struct anonApplication));
	    fillData(ptr, clocktime);
		prev->nextApp=ptr;
		prev=ptr;
	}


	

	return head;
}


void printApps(struct anonApplication *X)
{
	struct anonApplication *ptr;

	ptr=X;
	printf("%10s %6s  %6s   %30s %10s\n", "pointer","Date", "ID", "positionApplied", "nextApp");
	while(ptr!=NULL)
	{
		printf("%10d %6d  %6d   %30s %10d\n", ptr, ptr->appDate, ptr->appID, ptr->positionApplied, ptr->nextApp);
		ptr=ptr->nextApp;
    }
}


/*
struct anonApplication *  InsertByUniv(struct anonApplication *head,  struct anonApplication *to_add)
{
	struct anonApplication*ptr;
	struct anonApplication *prev;

	ptr=head;

	while(strcmp(to_add->university, ptr->university)>=0)
	{
		ptr=ptr->nextApp;

		if(ptr==NULL)
			break;
	}
	if(ptr!=head)
	{
	    prev=head;
		while(prev->nextApp!=ptr)
			prev=prev->nextApp;

		prev->nextApp=to_add;
		to_add->nextApp=ptr;

}

}
*/