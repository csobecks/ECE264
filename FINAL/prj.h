
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _STUFF_
#define _STUFF_

struct anonApplication {
	int appID;
	int appDate;
	int timeIn;
	char positionApplied[30];
	char university[30];
	float collegeGPA;
	int skillLevelProgramming;   // 1 to 5 where 5 is most skilled
	int skillLevelCircDesign;     // 1 to 5 where 5 is most skilled
	int skillLevelPrjManage;      // 1 to 5 where 5 is most skilled
    struct anonApplication *nextApp;

};
#endif

void fillData(struct anonApplication *X, int clockTime );
void printApps(struct anonApplication *X);
struct anonApplication  *sortByAvgSkill(struct anonApplication *head);
struct anonApplication  *makeInitialList(int ct);
void fillData(struct anonApplication *node, int clockTime);
struct anonApplication*checkForApp(struct anonApplication* head, int x);
struct anonApplication* NewApplications(int clocktime);