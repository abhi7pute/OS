#include<stdio.h>
int frame[5][2],nf; 
int searchFrames(int sv) 
{ 
 int x; 
for(x=0;x<nf;x++) 
 { 
 if(sv==frame[x][0]) 
 { 
 return 0; 
 } 
 } 
 return 1; 
} 
void displayMemory() 
{ 
 int i; 
printf("\n\nFrame Contains |"); 
 for(i=0;i<nf;i++) 
 printf(" %d | ",frame[i][0]);
 int findFreeFrame() 
{ 
 int i,min=frame[0][1],ri=0; 
 for(i=0;i<nf;i++) 
 { 
 if(frame[i][1]==-1) 
 { 
 return i; 
 } 
 } 
 //LRU
for(i=0;i<nf;i++) 
 { 
 if(min>frame[i][1]) 
 { 
 min=frame[i][1]; 
 ri=i; 
 } 
 } 
 return ri; 
} 
main() 
{ 
 int rs[]={3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6}; 
 int ts=0; 
int n=15,i,j,pf=0,srch,insert_index; 
 printf("Enter how many frames"); 
scanf("%d",&nf); 
 for(i=0;i<nf;i++) 
 { 
 for(j=0;j<2;j++) 
 frame[i][j]=-1; 
 } 
 displayMemory(); 
for(i=0;i<n;i++) 
 { 
 srch=searchFrames(rs[i]); 
 if(srch==1) 
 { 
 pf++; 
 insert_index=findFreeFrame(); 
 frame[insert_index][0]=rs[i]; 
 frame[insert_index][1]=ts++; 
 } 
 
 displayMemory(); 
 } 
 printf("\n\nTotal Page Faults Occured is %d\n",pf); 
}