#include<stdio.h>
int frame[5][2],nf; 
int searchFrames(int sv) 
{ 
 int x; 
for(x=0;x<nf;x++) 
 { 
 if(sv==frame[x][0]) 
{ 
 return x; 
 } 
 } 
 return -2; 
} 
void displayMemory() 
{ 
 int i; 
printf("\n\nFrame Contains |"); 
 for(i=0;i<nf;i++) 
 printf(" %d | ",frame[i][0]); 
} 
int findFreeFrame() 
{ 
 int i,max=frame[0][1],ri=0; 
 for(i=0;i<nf;i++) 
 { 
 if(frame[i][1]==-1) 
 { 
 return i; 
 } 
 } 
 for(i=0;i<nf;i++) 
 { 
 if(max<frame[i][1]) 
 { 
 max=frame[i][1]; 
 ri=i; 
 } 
 } 
 return ri; 
} 
main() 
{ 
 int rs[]={12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8}; 
 int ts=0; 
int n=16,i,j,pf=0,srch,insert_index; 
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
 if(srch==-2) 
 { 
 pf++; 
 insert_index=findFreeFrame(); 
 frame[insert_index][0]=rs[i]; 
 frame[insert_index][1]=ts++; 
 } 
 else
 { 
 frame[srch][1]=ts++; 
 } 
 
 displayMemory(); 
 } 
 printf("\n\nTotal Page Faults Occured is %d\n",pf); 
}