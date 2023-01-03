#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct PROCESS 
{ 
 char name[80] ; 
 int at , bt , ct , tat , tbt , wt , priority ; 
}PROCESS ; 
PROCESS jobs[10] ; 
int time = 0 , processCount , totalTat=0 , totalWt = 0 ; 
float avgTat , avgWt ; 
void sort() 
{ 
 int i , j ; 
 PROCESS p ; 
for(i = 0 ; i<processCount ; i++) 
 { 
 for(j=0 ; j<processCount ; j++) 
 { 
 if(jobs[i].at < jobs[j].at) 
 { 
 p = jobs[i] ; 
 jobs[i] = jobs[j] ; 
jobs[j] = p ; 
 } 
 } 
 } 
} 
int getJob() 
{ 
 int i , job , min = 999 ; 
for(i=0 ; i<processCount ; i++) 
 { 
 if(jobs[i].at<=time && jobs[i].tbt!=0) 
 { 
 if(jobs[i].priority <= min) 
 { 
 min = jobs[i].tbt ; 
 job = i ; 
 } 
 } 
 } 
 return job ; 
} 
void getProcess() 
{ 
 int i ; 
printf("\nEnter the number of processes: ") ; 
 scanf("%d",&processCount) ; 
 for(i=0 ; i<processCount ; i++) 
 { 
 printf("\nEnter the process name: ") ; 
 scanf("%s",jobs[i].name) ; 
 printf("Enter the CPU Burst time: ") ; 
scanf("%d",&jobs[i].bt) ; 
 printf("Enter the Arrival time: ") ; 
scanf("%d",&jobs[i].at) ; 
 jobs[i].tbt = jobs[i].bt ; 
 printf("Enter the process priority: ") ; 
scanf("%d",&jobs[i].priority) ; 
 } 
 sort() ; 
} 
void process() 
{ 
 int job , count = 0 ; 
char currentJob[10] , prevJob[10] = "NULL" ; 
 printf("\tGantt Chart\n\n") ; 
 printf("_________________________________________________\n") ; 
 printf("|") ; 
printf("0") ; 
while(1) 
 { 
 job = getJob() ; 
 jobs[job].tbt-- ; 
strcpy(currentJob,jobs[job].name) ; 
 if(strcmp(currentJob,prevJob) !=0 ) 
 { 
 printf(" %s %d|%d ",currentJob,time , time) ; 
 } 
 time++ ; 
 if(jobs[job].tbt==0) 
 { 
 jobs[job].ct = time ; 
jobs[job].tat = jobs[job].ct - jobs[job].at ; 
 jobs[job].wt = jobs[job].tat-jobs[job].bt ; 
 count++ ; 
 totalTat += jobs[job].tat ; 
 totalWt+=jobs[job].wt ; 
 } 
 strcpy(prevJob , currentJob) ; 
if(count==processCount) 
 break ; 
 } 
 printf("\n_________________________________________________\n") ; 
 avgTat = (float)totalTat/processCount ; 
 avgWt = (float)totalWt/processCount ; 
} 
void display() 
{ 
 int i = 0 ; 
printf("\n\n--------------------------------------------------------------
-------------------------------------\n") ; 
 printf("Process name\tArrival Time\tBurst Time\tCPU Time\tTurn Around 
time\tWait Time\n"); 
 printf("------------------------------------------------------------------
---------------------------------\n"); 
 for(i=0 ; i<processCount ; i++) 
 printf(" %s\t%d\t%d\t%d\t%d\t%d\n",jobs[i].name , jobs[i].at , 
jobs[i].bt , jobs[i].ct , jobs[i].tat , jobs[i].wt ) ; 
 printf("------------------------------------------------------------------
---------------------------------") ; 
 printf("\n\nTotal Turn Around Time: %d",totalTat) ; 
 printf("\nTotal Waiting Time: %d",totalWt) ; 
printf("\n\nAverage Turn Around Time: %f",avgTat) ; 
 printf("\nAverage Waiting Time: %f\n",avgWt) ; 
} 
main() 
{ 
 system("clear"); 
getProcess() ; 
process() ; 
display() ; 
}