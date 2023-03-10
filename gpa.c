#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct input
{
	char sub_name[100];
    char credits_str[2];
    int credits_int;
	char grade;	
    int grade_pnt;
    int sub_pnt;
}inp;

int isNumber(char s[])
{
    for (int i = 0; s[i]!= '\0'; i++)
    {
        if (isdigit(s[i]) == 0)
              return 0;
    }
    return 1;
}

void read1(inp arr[],int n)
{
    printf("\nEnter subject details as and when prompted\n");
    for(int i=0;i<n;i++)
    {
        printf("\n-------------------------------------------------\n");
  	    printf("Enter subject %d name\n",i+1);
  	    scanf("%s",&arr[i].sub_name);
        int flag1=0;
        while(flag1==0)
        {
            printf("Enter number of credits alloted for %s\n",arr[i].sub_name);
            scanf("%s",&arr[i].credits_str);
            if(isNumber(arr[i].credits_str)==1)
            {
                arr[i].credits_int=atoi(arr[i].credits_str);
                flag1=1;
            }
            else
            {
                printf("Invalid credit entry! Enter again...\n\n");
                flag1=0;
            }
        }
        int flag2=0;
        while(flag2==0)
        {
            printf("Enter grade of %s\n",arr[i].sub_name);
            scanf("%s",&arr[i].grade);
            char ch=arr[i].grade;
            switch(ch)
            {
    	        case 's':
                case 'S':
      	        arr[i].grade_pnt=10;
      	        flag2=1;
                break;
		
                case 'a':
                case 'A':
      	        arr[i].grade_pnt=9;
      	        flag2=1;
                break;
		
                case 'b':
                case 'B':
              	arr[i].grade_pnt=8;
                flag2=1;
                break;
		
                case 'c':
                case 'C':
              	arr[i].grade_pnt=7;
                flag2=1;
                break;
		
                case 'd':
                case 'D':
              	arr[i].grade_pnt=6;
              	flag2=1;
                break;
		
                case 'e':
                case 'E':
              	arr[i].grade_pnt=5;
              	flag2=1;
                break;
		
                case 'f':
                case 'F':
              	arr[i].grade_pnt=0;
                flag2=1;
                break;
		
                default:
      	        printf("invalid grade entered! enter again...\n\n");
      	        flag2=0;
                break;
            }
        }
        arr[i].sub_pnt=arr[i].grade_pnt*arr[i].credits_int;
    }
}

void display(inp arr[],int n,float gpa)
{	
    printf("\n\n---------------------RESULT----------------------\n\n");
    printf("Subject\t\tCredits\t\tGrade\n");
    printf("-------------------------------------------------\n");
    for(int k=0;k<n;k++)
    {
        printf("%-13s | %-10d | %6c\n",arr[k].sub_name,arr[k].credits_int,arr[k].grade);
    }
    printf("\n------------------FINAL GPA = %.2f -------------\n\n",gpa);  
}

float calc(inp arr[],int n)
{
    int tot_cred=0;
    int tot_pnt=0;
    for(int i=0;i<n;i++)
    {
        tot_cred=tot_cred+arr[i].credits_int;
        tot_pnt=tot_pnt+arr[i].sub_pnt;
    }
    float gpa=(float)tot_pnt/tot_cred;
    return gpa;
}

void score_calci(isa1,isa2,ass,grd_pt)
{
    int esa_target;
    float first50;
	float final_target;
	first50=((isa1+isa2)/2)+ass;
	final_target=((grd_pt)*10)-7.5;
	esa_target=(final_target-first50)*2;
    printf("Your Target ESA score for desired Grade is: %d\n",esa_target);
}

void read2()
{
  int isa1,isa2,ass,grade_pnt;
  char grade;
  printf("Enter ISA 1 Marks...\n");
  scanf("%d",&isa1);
  printf("Enter ISA 2 Marks...\n");
  scanf("%d",&isa2);
  printf("Enter Assignment Marks...\n");
  scanf("%d",&ass);
  printf("Enter target grade...\n");
  scanf("%s",&grade);
            switch(grade)
            {
    	        case 's':
                case 'S':
      	        grade_pnt=10;
                break;
		
                case 'a':
                case 'A':
      	        grade_pnt=9;
                break;
		
                case 'b':
                case 'B':
              	grade_pnt=8;
                break;
		
                case 'c':
                case 'C':
              	grade_pnt=7;
                break;
		
                case 'd':
                case 'D':
              	grade_pnt=6;
                break;
		
                case 'e':
                case 'E':
              	grade_pnt=5;
                break;
		
                case 'f':
                case 'F':
              	grade_pnt=0;
                break;
		
                default:
      	        printf("invalid grade entered! enter again...\n\n");
                break;
            }
    score_calci(isa1,isa2,ass,grade_pnt);
}

void main()
{
    printf("Enter your choice...\n");
    printf("(1) GPA Calculator\n");
    printf("(2) Target ESA Score Calculator\n");
    char input_sub[3];
    int n;
    float gpa;
    int flag3=0;
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    {
    while(flag3==0)
    {
        printf("Enter number of subjects...\n");
        scanf("%s",&input_sub);
        if(isNumber(input_sub)==1)
        {
            n=atoi(input_sub);
            flag3=1;
        }
        else
        {
            printf("Please enter a valid number of subjects...\n\n");
        }
    }
    inp arr[n];
    read1(arr,n);
    gpa=calc(arr,n);
    display(arr,n,gpa);  
    break;
    }
    case 2:
    {
    read2();
    break;
    }
    default:
    printf("Enter valid choice!\n\n");
    }
}
