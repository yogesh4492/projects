#include<stdio.h>
#include<string.h>

void add();
void displayall();
void display();
void update();
void delete();
struct student{
	int roll;
	char name[25];
	float percentage;
	char grade;
}s[100];
int st=0;
int main(){
	int choice;
	up:
	printf("\n 1.Add New Student.");
	printf("\n 2.Display All Student.");
	printf("\n 3.Display Particular Student.");
	printf("\n 4.Update Student Data.");
	printf("\n 5.Dlete Student Data.");
	printf("\n enter your choice:=");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			add();
			break;
		case 2:
			displayall();
			break;
		case 3:
			display();
			break;
		case 4:
			update();
			break;
		case 5:
		    delete();
			break;
		deafult:
			printf("\n Invalid Input.");
			printf("\n please try again");
			goto up;
	}
	char ch;
	printf("\n Press 'Y' To Continue and 'N' To Exit:=");
	scanf(" %c",&ch);
	if(ch=='y'||ch=='Y'){
		goto up;
	}
	return 0;
}

void add(){
	int count,i;
	printf("\n enter the number of student=");
	scanf("%d",&count);
	for(i=0;i<count;i++){
	
		printf("\n Enter The student[%d] Roll NO =",st+1);
		
		scanf("%d",&s[st].roll);
		printf("\n Enter The student[%d] Name=",st+1);
		scanf("%s",&s[st].name);
		printf("\n Enter The student[%d] Percentage=",st+1);
		scanf("%f",&s[st].percentage);
		if(s[st].percentage>=80){
			s[st].grade='A';
		}
		else if(s[st].percentage<80 && s[st].percentage>=35){
			s[st].grade='B';
		}
		else{
			s[st].grade='C';
		}
		st++;
	}
	
}

void displayall()
{
	int i;
	printf("\n --------------------------------------------------------\n");
	printf("\n Roll    ||Name           ||Percentage    ||Grade");
	printf("\n ---------------------------------------------------------\n");
	for(i=0;i<st;i++){
		
	printf("\n %d   \t%s            \t%.2f          \t%c",s[i].roll,s[i].name,s[i].percentage,s[i].grade);
	}
}
void display(){
	int choice,roll,i;
	char str[25];
	float per;
	char grd;
	down:
	printf("\n 1.Search By Roll No:");
	printf("\n 2.Search By Name:");
	printf("\n 3.Search By Percentage.");
	printf("\n 4.Search By Grade.");
	printf("\n enter your choice=");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\n Enter The Roll no=");
			scanf("%d",&roll);
			printf("\n --------------------------------------------------------\n");
	        printf("\n Roll    ||Name           ||Percentage    ||Grade");
	        printf("\n ---------------------------------------------------------\n");
			for(i=0;i<st;i++){
				if(s[i].roll==roll){
					printf("\n %d   \t%s            \t%.2f          \t%c",s[i].roll,s[i].name,s[i].percentage,s[i].grade);
				}
			}
			break;
		case 2:
			printf("\n Enter The Name=");
			scanf("%s",&str);
			printf("\n --------------------------------------------------------\n");
	        printf("\n Roll    ||Name           ||Percentage    ||Grade");
	        printf("\n ---------------------------------------------------------\n");
	        for(i=0;i<st;i++){
	        	int res = strcmp(str,s[i].name);
	        		if(res==0){
					
	        			printf("\n %d   \t%s            \t%.2f          \t%c",s[i].roll,s[i].name,s[i].percentage,s[i].grade);}
				}
			
			break;
		case 3:
			printf("\n Enter The Percentage=");
			scanf("%f",&per);
			
			printf("\n 1. Less Than.");
			printf("\n 2.Greater Than.");
			printf("\n Enter Your Choice=");
			scanf("%d",&choice);
			switch(choice){
				case 1:
				   printf("\n --------------------------------------------------------\n");
	               printf("\n Roll    ||Name           ||Percentage    ||Grade");
	               printf("\n ---------------------------------------------------------\n");
						for(i=0;i<st;i++){
					      if(s[i].percentage<per){
						         printf("\n %d   \t%s            \t%.2f          \t%c",s[i].roll,s[i].name,s[i].percentage,s[i].grade);
						}
					}
					break;
				case 2:
			        printf("\n --------------------------------------------------------\n");
	                printf("\n Roll    ||Name           ||Percentage    ||Grade");
	                printf("\n ---------------------------------------------------------\n");
	                   for(i=0;i<st;i++){
					      if(s[i].percentage>per){
						       printf("\n %d   \t%s            \t%.2f          \t%c",s[i].roll,s[i].name,s[i].percentage,s[i].grade);
						}
					}
					break;
			}
			break;
		case 4:
			printf("\n Enter The Grade=");
			scanf(" %c",&grd);
			printf("\n --------------------------------------------------------\n");
	        printf("\n Roll    ||Name           ||Percentage    ||Grade");
	        printf("\n ---------------------------------------------------------\n");
			for(i=0;i<st;i++){
				if(s[i].grade==grd){
					printf("\n %d   \t%s            \t%.2f          \t%c",s[i].roll,s[i].name,s[i].percentage,s[i].grade);
						
				}
			}
			break;
		default:
			printf("\n invalid input.");
			printf("\n Please try again.");
			goto down;
}
	char ch;
	printf("\n Press 'Y' to continue Searching and 'N'  to exit searching ");
	scanf(" %c",&ch);
	if(ch=='y'||ch=='Y'){
		goto down;
	}
}
void update(){
	int id,choice,i;
	char nnm[50];
	float nper;
	i:
	printf("\n enter the id to update data=");
	scanf("%d",&id);
	printf("\n 1.Name  Update.");
	printf("\n 2.Percentage update.");
	printf("\n enter your choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\n enter New Name=");
			scanf("%s",&nnm);
			for(i=0;i<st;i++){
				if(id==s[i].roll){
					strcpy(s[i].name,nnm);
				}
			}
			break;
		case 2:
			printf("\n Enter new PErcentage=");
			scanf("%f",&nper);
			for(i=0;i<st;i++){
				if(id==s[i].roll){
					s[i].percentage=nper;
					if(nper>80){
						s[i].grade='A';
					}
					else if(nper>35 &&nper<=80){
						s[i].grade='B';
					}
					else{
						s[i].grade='C';
					}
				}
			}
	}
	char ch;
	printf("\n do you update another student data?y/n==");
	scanf(" %c",&ch);
	if(ch=='y'||ch=='Y'){
		goto i;
	}
}
void delete()
{
	int id,i,index1;
	printf("\n enter your id for delete data=");
	scanf("%d",&id);
	for(i=0;i<st;i++){
		if(id==s[i].roll){
			index1=i;
		}
	}
	for(i=index1;i<st-1;i++){
			
			
			s[i].roll=s[i+1].roll;
			strcpy(s[i].name,s[i+1].name);
			s[i].percentage=s[i+1].percentage;
			s[i].grade=s[i+1].grade;
	
	}
	st--;
}

