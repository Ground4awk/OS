/*Ques. 41. Write a program which incorporate Peterson's solution for synchronizing two processes those are simultaneously trying to write on a shared file named as File.txt. 
*/


#include<stdio.h>
#include<pthread.h>
void *f1(void *);
void *f2(void *);
int f[2];//Used to indicate if a process is ready to enter the critical 	
FILE*fptr;// file pointer
int queue=0;//queue indicates whose right it is to enter the crtical section(cs) 
int i=0;
int main()
{

	pthread_t t1; 	//process 1
	pthread_t t2; 	//process 2
	pthread_create(&t1,NULL,f1,NULL);	
	pthread_create(&t2,NULL,f2,NULL);	
	pthread_join(t1,NULL);	
	pthread_join(t2,NULL);
	return 0;
}

void *f1(void *p) 	//process 1 active function
{
	int *file1();
    while(i<2)		
    {
        f[0]=1;	//active process p1 state
        queue=1;		//queue of process p1
        while(f[1]==1 && queue==1);
		file1();	//critical state 
        f[0]=0;	//exiting
        i++;
    }
}

void *f2(void *p) 	//process 2 active function
{ 
	int *file2();
    while(i<2)		
    {
        f[1]=1;	//active process p2 state
        queue=0;		//queue of process p2
        while(f[0]==1 && queue==0);
        file2();	// cs
        f[1]=0;	//exiting
        i++;
    }
}

// Although the functions to write into file are given different names, The file to which it is written is same.

int file1() 		//function for writing to the file 
{
	fptr=fopen("FILE.txt","w");
	//writing to file
	if(fptr==NULL)
	{
		printf("File does not exist.\n");
	}
	else
	{
		printf("\nP1 is writing to file");
		fprintf(fptr,"\nHello from P1");
		fprintf(fptr,"\nFile has been updated");
	}
	
	fclose(fptr);
	return 0;
}

int file2() 		//function for writing to the file 
{
	fptr=fopen("FILE.txt","w");
	//writing to file
	if(fptr==NULL)
	{
		printf("FILE DOES'NT EXISTS.");
	}
	else
	{
		printf("\nP2 is writing to file");
		fprintf(fptr,"\nHello from P2");
		fprintf(fptr,"\nFile has been updated");
	}
	
	fclose(fptr);
	return 0;
}

