#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	//char *name;
	//name = (char*)calloc(50,sizeof(char));
	char name[50];
	int rno; float cgpa;
}STUDENT;

void read(STUDENT *p)
{
	printf("Enter name : ");
	scanf("%s",p->name);
	printf("Enter roll. no. : ");
	scanf("%d",&p->rno);
	printf("Enter cgpa : ");
	scanf("%f",&p->cgpa);
}

void print(STUDENT *p)
{
	printf("Name of student : %s\n",p->name);
	printf("Roll. no. of student : %d\n",p->rno);
	printf("CGPA of student : %2f\n",p->cgpa);
}

void sort(STUDENT p[], int n)
{
	int i,j;
	STUDENT t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].rno > p[j].rno)
			{
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
}

void main()
{
	int num,i=1;
	printf("Enter no. of students : ");
	scanf("%d", &num);
	STUDENT *s;
	s = (STUDENT*)calloc(num,sizeof(STUDENT));
	STUDENT *ptr;
	STUDENT *plast;
	plast=s+num-1;
	/*
	if(!(ptr = calloc(num,sizeof(int))))
	{
		exit(0);
	}
	*/
	printf("\nEnter details : \n");
	for(ptr=s;ptr<=plast;ptr++)
	{
		printf("Student %d :\n",i);
		read(ptr);
		i++;
	}
	i=1;
	printf("\nDetails of students : \n");
	for(ptr=s;ptr<=plast;ptr++)
	{
		printf("Student %d :\n",i);
		print(ptr);
		i++;
	}
	printf("\nSorted list according to roll. nos. :\n");
	sort(s,num);
	i=1;
	for(ptr=s;ptr<=plast;ptr++)
	{
		printf("Student %d :\n",i);
		print(ptr);
		i++;
	}
}