
#include <stdio.h>
#include "prjstud.h"

struct anonApplication  *sortByUniversity(struct anonApplication *head)
{
	struct anonApplication* ptr1, * ptr2, *temp1, * temp2, * temp3;
	ptr1 = head;

	while (ptr1 != NULL)
	{
		ptr2 = ptr1->nextApp;
		while (ptr2 != NULL)
		{
			if((ptr1->university[0] < ptr2->university[0])!=0) //university name is already in alphabetical order
			{ 	
				ptr2 = ptr2->nextApp;
			}
			else if((ptr1->university[0] > ptr2->university[0])!=0) //university name needs to be swapped
			{
				if (ptr1 == head) //beginning of list
				{
					temp2 = head;
					while (temp2->nextApp != ptr2)
					{
						temp2 = temp2->nextApp;
					}
					temp2->nextApp = ptr1;
					head = ptr2;
					temp1 = ptr2->nextApp;
					ptr2->nextApp = ptr1->nextApp;
					ptr1->nextApp = temp1;

				}
				else //in list
				{
					temp2 = head;
					temp3 = head;
					while (temp2->nextApp != ptr2)
					{
						temp2 = temp2->nextApp;
					}
					while (temp3->nextApp != ptr1)
					{
						temp3 = temp3->nextApp;
					}
					temp3->nextApp = ptr2;
					temp2->nextApp = ptr1;
					temp1 = ptr2->nextApp;
					ptr2->nextApp = ptr1->nextApp;
					ptr1->nextApp = temp1;
					
				}
				ptr1 = ptr2;
				ptr2 = ptr2->nextApp;
			}
			else
			{
				if ((ptr1->university[1] <= ptr2->university[1]) != 0) //university name is already in alphabetical order
				{	
					ptr2 = ptr2->nextApp;
				}
				else //university name needs to be swapped
				{
					if (ptr1 == head) //beginning of list
					{
						temp2 = head;
						while (temp2->nextApp != ptr2)
						{
							temp2 = temp2->nextApp;
						}
						temp2->nextApp = ptr1;
						head = ptr2;
						temp1 = ptr2->nextApp;
						ptr2->nextApp = ptr1->nextApp;
						ptr1->nextApp = temp1;

					}
					else //in list
					{
						temp2 = head;
						temp3 = head;
						while (temp2->nextApp != ptr2)
						{
							temp2 = temp2->nextApp;
						}
						while (temp3->nextApp != ptr1)
						{
							temp3 = temp3->nextApp;
						}
						temp3->nextApp = ptr2;
						temp2->nextApp = ptr1;
						temp1 = ptr2->nextApp;
						ptr2->nextApp = ptr1->nextApp;
						ptr1->nextApp = temp1;

					}
					ptr1 = ptr2;
					ptr2 = ptr2->nextApp;
				}
				
			}
		}
		ptr1 = ptr1->nextApp;
	}
	return head;
}


struct anonApplication *deleteApplication  (struct anonApplication *head, struct anonApplication *to_be_gone)
{
	struct anonApplication* i = head;

	if (i == to_be_gone)
	{
		head = i->nextApp;
	}
	else
	{
		while (i->nextApp != to_be_gone)
		{
			i = i->nextApp;
		}
		i->nextApp = i->nextApp->nextApp;
	}
	
	return head;
}

struct anonApplication *processDay(struct anonApplication* head, int *clockTime)
{
	struct anonApplication* hold = head;
	struct anonApplication* NewApplication(int clocktime);
	struct anonApplication* ptr;

	*clockTime=*clockTime+1;
	while (hold != NULL)
	{
		if (hold->timeIn >= 5)
		{
			head=deleteApplication(head, hold);
		}
		hold = hold->nextApp;
	}

	head = sortByAvgSkill(head);
	hold = head;
	while (hold != NULL)
	{
		if (strcmp(hold->positionApplied, "systems engineer")==0)
		{
			printf("appID %d has been hired for the position is for systems engineer\n", hold->appID);
			break;
		}
		else
		{
			hold = hold->nextApp;
		}
	}
	if (hold != NULL)
	{
		head = deleteApplication(head, hold);
	}
	
	head = sortByAvgSkill(head);
	hold = head;
	while (hold != NULL)
	{
		if (strcmp(hold->positionApplied, "software engineer") == 0)
		{
			printf("appID %d has been hired for the position is for software engineer\n", hold->appID);
			break;
		}
		else
		{
			hold = hold->nextApp;
		}
	}
	if (hold != NULL)
	{
		head = deleteApplication(head, hold);
	}
	
	head = sortByAvgSkill(head);
	hold = head;
	while (hold != NULL)
	{
		if (strcmp(hold->positionApplied, "controls engineer") == 0)
		{
			printf("appID %d has been hired for the position is for controls engineer\n", hold->appID);
			break;
		}
		else
		{
			hold = hold->nextApp;
		}
	}
	if (hold != NULL)
	{
		head = deleteApplication(head, hold);
	}
	
	head = sortByAvgSkill(head);
	hold = head;
	while (hold != NULL)
	{
		if (strcmp(hold->positionApplied, "engineering management") == 0)
		{
			printf("appID %d has been hired for the position is for engineering management\n", hold->appID);
			break;
		}
		else
		{
			hold = hold->nextApp;
		}
	}
	if (hold != NULL)
	{
		head = deleteApplication(head, hold);
	}
	
	head = sortByAvgSkill(head);
	hold = head;
	while (hold != NULL)
	{
		hold->timeIn = hold->timeIn + 1;
		hold = hold->nextApp;
	}

	ptr = NewApplications(*clockTime);
	head = sortByAvgSkill(head);
	hold = head;
	while (hold->nextApp != NULL)
	{
		hold = hold->nextApp;
	}
	hold->nextApp = ptr;
	head = sortByAvgSkill(head);

	return head;
}

void printFormatted (struct anonApplication * head){
	struct anonApplication* temp = head;
	printf("appID  appDate  timeIn  ProgSkill  CircDesign  ProjManage    GPA       University       positionApplied\n==================================================================================================================\n");
	while (temp != NULL)
	{
		printf("%d      %d        %d       %d          %d           %d        %f     %s        %s\n", temp->appID, temp->appDate, temp->timeIn, temp->skillLevelProgramming, temp->skillLevelCircDesign, temp->skillLevelPrjManage, temp->collegeGPA, temp->university, temp->positionApplied);
		temp = temp->nextApp;
	}
}

void analyzeApplicantList (struct anonApplication * head)
{
	struct anonApplication *temp = head;
	double avgGPA[4] = { 0 };
	double avgCD[4] = { 0 };
	double avgPM[4] = { 0 };
	double appnum[4] = { 0 };
	double avgPROG[4] = { 0 };

	while (temp != NULL)
	{
		
		if (strcmp(temp->positionApplied, "systems engineer") == 0)
		{
			appnum[0] += 1;
			avgGPA[0] += temp->collegeGPA;
			avgCD[0] += temp->skillLevelCircDesign;
			avgPM[0] += temp->skillLevelPrjManage;
			avgPROG[0] += temp->skillLevelProgramming;
			temp = temp->nextApp;
		}
		else if (strcmp(temp->positionApplied, "software engineer") == 0)
		{
			appnum[1] += 1;
			avgGPA[1] += temp->collegeGPA;
			avgCD[1] += temp->skillLevelCircDesign;
			avgPM[1] += temp->skillLevelPrjManage;
			avgPROG[1] += temp->skillLevelProgramming;
			temp = temp->nextApp;
		}
		else if (strcmp(temp->positionApplied, "controls engineer") == 0)
		{
			appnum[2] += 1;
			avgGPA[2] += temp->collegeGPA;
			avgCD[2] += temp->skillLevelCircDesign;
			avgPM[2] += temp->skillLevelPrjManage;
			avgPROG[2] += temp->skillLevelProgramming;
			temp = temp->nextApp;
		}
		else
		{
			appnum[3] += 1;
			avgGPA[3] += temp->collegeGPA;
			avgCD[3] += temp->skillLevelCircDesign;
			avgPM[3] += temp->skillLevelPrjManage;
			avgPROG[3] += temp->skillLevelProgramming;
			temp = temp->nextApp;
		}
	}
	avgGPA[0] = avgGPA[0] / appnum[0];
	avgCD[0] = avgCD[0] / appnum[0];
	avgPM[0] = avgPM[0] / appnum[0];
	avgPROG[0] = avgPROG[0] / appnum[0];

	avgGPA[1] = avgGPA[1] / appnum[1];
	avgCD[1] = avgCD[1] / appnum[1];
	avgPM[1] = avgPM[1] / appnum[1];
	avgPROG[1] = avgPROG[1] / appnum[1];

	avgGPA[2] = avgGPA[2] / appnum[2];
	avgCD[2] = avgCD[2] / appnum[2];
	avgPM[2] = avgPM[2] / appnum[2];
	avgPROG[2] = avgPROG[2] / appnum[2];

	avgGPA[3] = avgGPA[3] / appnum[3];
	avgCD[3] = avgCD[3] / appnum[3];
	avgPM[3] = avgPM[3] / appnum[3];
	avgPROG[3] = avgPROG[3] / appnum[3];

	printf("System Engineering Info\n\nAverage GPA:%f\nAverage Circuit Design Skill Level:%f\nAverage Project Management Skill Level:%f\nAverage Programming Skill Level:%f\n\n", avgGPA[0], avgCD[0], avgPM[0], avgPROG[0]);
	printf("Software Engineering Info\n\nAverage GPA:%f\nAverage Circuit Design Skill Level:%f\nAverage Project Management Skill Level:%f\nAverage Programming Skill Level:%f\n\n", avgGPA[1], avgCD[1], avgPM[1], avgPROG[1]);
	printf("Controls Engineering Info\n\nAverage GPA:%f\nAverage Circuit Design Skill Level:%f\nAverage Project Management Skill Level:%f\nAverage Programming Skill Level:%f\n\n", avgGPA[2], avgCD[2], avgPM[2], avgPROG[2]);
	printf("Engineering Management Info\n\nAverage GPA:%f\nAverage Circuit Design Skill Level:%f\nAverage Project Management Skill Level:%f\nAverage Programming Skill Level:%f\n\n", avgGPA[3], avgCD[3], avgPM[3], avgPROG[3]);
}

void terminateAndWrite(struct anonApplication * head)
{
	FILE* fptr = fopen("output.txt", "w");
	struct anonApplication* temp = head;
	fprintf(fptr, "appID  appDate  timeIn  ProgSkill  CircDesign  ProjManage    GPA       University       positionApplied\n==================================================================================================================\n");
	while (temp != NULL)
	{
		fprintf(fptr, "%d      %d        %d       %d          %d           %d        %f     %s        %s\n", temp->appID, temp->appDate, temp->timeIn, temp->skillLevelProgramming, temp->skillLevelCircDesign, temp->skillLevelPrjManage, temp->collegeGPA, temp->university, temp->positionApplied);
		temp = temp->nextApp;
	}
	fclose(fptr);
	printf("\n\n\nbye!\n\n\n");
	exit(0);
}
