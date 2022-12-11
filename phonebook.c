
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void login(){
int a=0, i=0;
char uname[10], c=' ' ;
char pword[10], code[10];
char user[20]="riana";
char pass[10]="hahaha";
do
{

    printf("\n               LOGIN FIRST                       ");
    printf("\n\n            ENTER USERNAME:-");
    scanf("%s", &uname);
    printf("\n\n            ENTER PASSWORD:-");
    while (i<10)
    {

        pword[i]=getch();
        c=pword[i];
        if(c==13)
            break;
        else
            printf("x");
        i++;

    }
    pword[i]='\0';

    i=0;

    if(strcmp(uname,user)==0 && strcmp(pword, pass)==0 ){
        printf("\n\n\n      \t WELCOME TO PHONEBOOK APPLICATION!!! \n\t\t YOUR LOGIN IS SUCCESSFULL");

        printf("  \n\n\n\t\t\t PRESS ANY KEY TO CONTINUE......  ");
        getch(); // holds the screen;
        break;
    }
    else
    {
        printf("\n    SORRY ! LOGIN IS UNSUCCESSFULL :( ");
        a++;

        getch();
    }

    }
    while (a<=2);
    if(a>2)
    {

        printf("\n SORRY you have enter the wrong user name and password for four times!... ");
        getch();

    }

    system("cls");

    }


 struct phonebook {
 char name [20] ;
 char address[50];
 char number[20];
 char email[50];
 } p;

 int seat=60;

 void add_contact();
 void search_contact();
 void save_contact();
 void group_contact();
 void modify_contact();
 void old_contact();
 void daily_activities();
 void check_phone_code();
 void review_of_user();
 void delete_contact();
 void viewall();
 void exit();

 void main()
 {

     login();


   int ch;
   do{
    printf("\n");
    printf("\n");
    printf("\t ****PHONE BOOK APPLICATION****") ;
    printf("\n");
    printf("\n---------------------------------");


    printf("\n Enter 1. To Add contacts");
    printf("\n Enter 2. To search contacts");
    printf("\n Enter 3. To save contacts");
    printf("\n Enter 4. To group contacts");
    printf("\n Enter 5. To modify contacts");
    printf("\n Enter 6. To old contacts");
    printf("\n Enter 7. To daily activities ");
    printf("\n Enter 8. To check phone code");
    printf("\n Enter 9. To review of users");
    printf("\n Enter 10.To delete contact ");
    printf("\n Enter 11.To view all ");
    printf("\n Enter 12. exit");


    printf("enter your choice: \n ");
    scanf("%d" , &ch);
    system("cls");

    switch (ch)
    {

       case 1:
       add_contact();
       break;
        case 2:
       search_contact();
        break;
        case 3:
            save_contact();


         break;
         case 4:
        groupcontact();
        case 5:
        modifycontact();
          break;
        case 6:
        old_contact();
         break;
        case 7:
       dailyactivities();
        break;
      case 8:
     phonecode();
      break;
      case 9:
        review();
        break;
       case 10:
      delete_contact();
       break;
       case 11:
        viewall();
        break;
       case 12:
        exit();
        break;






      default:
        printf("thank you for check this application!!");
        break;



   }
            } while (ch!=12);
            }


            void add_contact(){
                FILE*fp;
                fp=fopen("contact.txt", "a");
                system("cls");
                printf("\t*******ADD CONTACT*******");
                printf("\n\tName      :-  ");
                char name[20];
                scanf("%s ", name);
                printf("\n\tMob num :-  ");
                char mob[20];
                scanf("%s",mob);
                fprintf(fp,"%s %s ",name,mob);
                fclose(fp);
                printf("press any key to continue.....");
                getch();
                main();
                }




void viewAll()
{

	char ch;
	FILE *fp;

	fp = fopen("contact.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}

	fclose(fp);
}
void search_contact(){
    FILE*fp;
 fp =fopen("contact.txt" , "r");
 system ("cls");

 printf("\t******SEARCH CONTACT******");
 printf("\n\tEnter Name:-");
 char  name[20];
 scanf("%s",name);
  char name1[20], mob[20];
 while (fscanf(fp,"%s %s" ,name1,mob)!=EOF)
 {

     if (strcmp(name,name1)==0){
        printf("\n\tName:-    %s\n", name1);
        printf("\n\tMob No:-   %s\n",mob);
        char mob[50];
        scanf("%s", mob);
        fprintf(fp,"%s %s\n", name1,mob);
        fclose(fp);
        printf("press any key to continue.......");
        getch();
        main();



     }
 void delete_contact(){
 FILE*fp,*fp1;
 fp=fopen("contact.txt", "r+");
 fp1=fopen("temp.txt" , "w");
 system("cls");
 printf("*******DELETE CONTACT******");
 printf("\n\t Enter name: ");
 char name[20];
 scanf("%s", name);
 char name1[20], mob[20];
 while (fscanf(fp,"%s %s", name1,mob)!=EOF)
 {

     if(strcmp(name,name1)==0){
        continue;
     }
     fprintf(fp1,"%s %s \n", name1,mob);

 }
 fclose(fp);
 fclose(fp1);
 fp=fopen("contact.txt", "w");
 fp1=fopen("temp.txt", "r");
 while(fscanf(fp1, "%s %s ", name1,mob)!=EOF)
 {

     fprintf(fp,"%s %s\n" , name1,mob);

 }
 fclose(fp);
 fclose(fp1);
 remove("temp.txt");
 printf("\n\tpress any key to continue.....");
 getch();
 main();
 }





