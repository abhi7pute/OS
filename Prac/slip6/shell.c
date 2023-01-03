//OS_Slip4_2
/*Write a program to implement the shell. It should display the command 
 prompt “myshell$”. Tokenize the command line and execute the given 
 command by creating the child process. Additionally it should interpret the 
 following commands. 
 myshell$ search a filename pattern :- To search all the occurrence of 
 pattern in the file. 
 myshell$ search c filename pattern :- To count the number of occurrence 
 of pattern in the file.*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_toks(char *s, char *tok[])
{
 int i=0;
 char *p;

 p = strtok(s," ");
 while(p!=NULL)
 {
  tok[i++]=p;
  p=strtok(NULL," ");
 }

 tok[i]=NULL;
}

void search(char *fn, char op, char *pattern)
{
 int fh,count=0,i=0,j=0;
 char buff[255],c,*p;

 fh = open(fn,O_RDONLY);
 if(fh==-1)
 {
  printf("File %s Not Found\n",fn);
  return;
 }

 switch(op)
 {
 case 'f':
  while(read(fh,&c,1))
  {
   buff[j++]=c;
   if(c=='\n')
   {
    buff[j]='\0';
    j=0;
    i++;
    if(strstr(buff,pattern))
    {
     printf("%d: %s",i,buff);
     break;
    }
   }
  }
  break;
 case 'c':
  while(read(fh,&c,1))
  {
   buff[j++]=c;
   if(c=='\n')
   {
    buff[j]='\0';
    j=0;
    p = buff;
    while(p=strstr(p,pattern))
    {
     count++;
     p++;
    }
   }
  }
  printf("Total No.of Occurrences = %d\n",count);
  break;
 case 'a':
  while(read(fh,&c,1))
  {
   buff[j++]=c;
   if(c=='\n')
   {
    buff[j]='\0';
    j = 0;
    i++;
    if(strstr(buff,pattern))
     printf("%d: %s",i,buff);
   }
  }
 }//switch
 close(fh);
}//search

int main()
{
 char buff[80],*args[10];
 int pid;

 while(1)
 {
  printf("myshell$");
  fflush(stdin);
  fgets(buff,80,stdin);
  buff[strlen(buff)-1]='\0';
  make_toks(buff,args);
  if(strcmp(args[0],"search")==0)
   search(args[3],args[1][0],args[2]);
  else
  {
   pid = fork();
   if(pid>0)
    wait();
   else
   {
    if(execvp(args[0],args)==-1)
     printf("Bad command.\n");
   }
  }
 }

 return 0;
}