#include<iostream>
using namespace std;
struct student {
   char name[50];
   int roll_no;
};
int main(){
    struct student s1[5];
    printf("Enter students details...\n");
    for(int i=0;i<5;i++){
         printf("Enter details for student %d",i);
         printf("Enter name :");
         scanf("%s",s1[i].name);
         printf("Enter roll no:");
         scanf("%d",&s1[i].roll_no);
    }

    printf("\nDetails for students ...\n");
     for(int i=0;i<5;i++){
         printf("details for student %d\n",i);
         printf("Name:");
         printf("%s\n",s1[i].name);
         printf("roll no:");
         printf("%d",s1[i].roll_no);
    }
    return 0;
}