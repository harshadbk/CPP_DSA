#include<stdio.h>

struct student{
  char name[50];
  int roll_no;
  float percentage;
};

int main(){

    struct student s1[3];

    for(int i=0;i<3;i++){
        printf("Enter deails for student %d\n",i+1);
        printf("Enter the name ");
        scanf("%s",s1[i].name);
        printf("Enter the roll_no ");
        scanf("%d",&s1[i].roll_no);
        printf("Enter the percentage ");
        scanf("%f",&s1[i].percentage);
    }

    printf("\n--------------------\n");

    for(int i=0;i<3;i++){
        printf("details for student %d\n",i+1);
        printf("Name of student :%s \n",s1[i].name);
        printf("roll_no of student :%d \n",s1[i].roll_no);
        printf("percentage of studnet: %f\n",s1[i].percentage);
    }

    return 0;
}