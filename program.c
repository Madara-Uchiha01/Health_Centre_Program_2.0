//Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Global variables
int i=0,j=0,k=0,key;int logcount=0;
int medcount[60];int bookcount=0;
int bad=0,good=0,vgood=0,excellent=0;
int out=0,flag,cexit;
char name[25],usn[11];


//Structure to store individual user data
struct virus
{
    char name[20];
    char hostel[25];
    char room[4];
    char contact[11];
}cov[20];

struct login
{
    char name[25];
    char usn[11];
    char address[250];
    char gender;
    int age;
    char phno[11];
    char date[11];
    char appanswer[100];
    char question[100];
    char answer[200];
}user[60];


//structure to store individual user's medicine purchase data
struct medicine
{
    char med[25];
    int qty;
}hp[60][15];


//structure to keep track of facilities used by each user
struct facilities
{
    int buydata;
    int appdata;
    int askdata;
    int ratedata;

}userdata[60];


//Prototype declarations of all functions used
int intro();
void pre();
void initialiser();
void login();
void registered();
void develop();
void deleter();
void display();
void appdisplay();
void askdisplay();
void ratedisplay();
int uname(char []);
int options();
void medbuy();
int viewcart();
int confirm();
int detail();
void buythankmsg();
void book();
void bookthankmsg();
void ask();
void rating();
int intintroinput();//blocker for intro
int intpreinput();
int twoinput();
char nameinput();
char regnameinput();
char genderinput();
char usninput();
int ageinput();
int optinput();
int qtyinput();
char phnoinput();
char dateinput();
int rateinput();
char regusninput();
//char addressinput();
//Beginning of our main function
int main()
{
    system("cls");
    initialiser();//stores 0 to all elements of userdata array
    while(1)//an infinite loop to keep running our program until its made to stop
    {
     intro();//contains introduction statements
     if(key==2)
     {
         fflush(stdin);
         system("cls");
         ++out;
         printf("\n\n\tEnter your name:  ");gets(cov[out].name);
         printf("\n\n\tEnter hostel name: ");gets(cov[out].hostel);
         printf("\n\n\tEnter room number:  ");gets(cov[out].room);
         printf("\n\n\tEnter your contact number:  ");gets(cov[out].contact);
         system("cls");
         printf("\n\n\tThank You for bringing this to our notice");
         printf("\n\n\tWe'll take measures as soon as possible");
         printf("\n\n\tPress 0 to exit");getchar();

     }
     if(key==1)
     {
         do//another infinite loop to prompt user to input the right key out of 1 and 2
         {
             pre();//decision maker for new user or registered user
             if(key==1)
             {
                system("cls");
                j=0;
                login();//first time users save their data here
                break;

             }
             else if(key==7)
             {
                 develop();
                 return main();
             }

             else if(key==2)
             {
                 registered();
                 break;
             }

             else
             {
                 fflush(stdin);
                 system("cls");
                 printf("Hey buddy watch out what you're pressing press any key to try again: ");
                 getchar();
             }

         }while(1);

         do
         {
             system("cls");
            options();

            switch(key)
            {
                case 1:medbuy();
                       userdata[i].buydata++;
                       break;
                case 2: if(user[i].date[0]!='\0'&&user[i].appanswer[0]=='\0')
                        {
                            system("cls");
                            printf("\n\n\n\t\tYou've already requested for an appointment on\n");
                            printf("\n\t\t%s",user[i].date);
                            printf("\n\n\t\tWait until you've received an answer");
                            break;
                        }
                        if(user[i].date[0]!='\0'&&user[i].appanswer[0]!='\0')
                        {
                            system("cls");
                            printf("\n\t\tYour appointment has been confirmed on \n");
                            printf("\n\t\t%s",user[i].date);
                            printf("\n\t\t%s",user[i].appanswer);
                            break;
                        }
                        book();
                        userdata[i].appdata++;
                        break;
                case 3: if(user[i].question[0]!='\0'&&user[i].answer[0]=='\0')
                        {
                            system("cls");
                            printf("\n\t\tYou've already asked a question wait for it to get answered\n");
                            printf("\n\t\t%s",user[i].question);
                            break;
                        }
                        if(user[i].question[0]!='\0'&&user[i].answer[0]!='\0')
                        {
                            system("cls");
                            printf("\n\t\tYou've received an answer\n");
                            printf("\n\t\t%s",user[i].question);
                            printf("\n\t\t%s",user[i].answer);
                            break;
                        }

                        ask();
                        userdata[i].askdata++;

                        break;
                case 4: rating();
                        userdata[i].ratedata++;
                        break;
                case 0: break;

            }

            printf("\n\n\n\t\tpress 1 to main menu 0 to exit : ");
            scanf("%d",&key);

         }while(key!=0);
         i=logcount;


     }
     system("cls");
     printf("\n\t\tpress 0 to exit else continue\n\t\t\t");

     scanf("%d",&key);
     if(key==0)break;
     else
     {
        continue;
     }

    }

}

void initialiser()
{
    int q=0;
    for(q=0;q<60;q++)
    {
        userdata[q].buydata=0;
        userdata[q].appdata=0;
        userdata[q].askdata=0;
        userdata[q].ratedata=0;
    }

}


int intro()
{

    while(1)
    {
        system("cls");
        printf("\n\n\t\t               HELLO FOLKS !\n\n");
        printf("\n\t           WELCOME to our NMIT HEALTH CENTRE program  \n");
        printf("\n\n\t      PRESS \"1\" to \"CONTINUE\" ANY OTHER NUMBER KEY TO \"EXIT\" \n\t\t\t");
        printf("\n\n\n\t      PRESS \"2\" to \"REPORT SYMPTOMS\"  \n\t\t\t");
        key=intintroinput();
        if(key!=1||key!=2)break;
        else return key;

    }
}
void pre()
{
    system("cls");
    printf("\n\n\n\t\tIF YOU'RE A NEW USER PRESS \"1\"");
    printf("\n\n\n\t\tIF YOU'VE ALREADY REGISTERED WITH US PRESS \"2\"\n\t\t");
    key=intpreinput();

}

void registered()
{
    system("cls");

    printf("\n\n\t\t    Enter your Username :\n\n\t\t\t");
    do
    {
        regnameinput();

    }while(name[0]=='\0');

    i=uname(name);
    do
    {
        if(i<60)break;
        else
        {
            system("cls");

            printf("\n\n\n\t\t    ***  Name not found  ***\n\n\t\tTry again or press  enter to exit:\n\n\t\t");
            regnameinput();
        }


        if (name[0] == '\0')exit(0);

        i=uname(name);
    }while(i==100);


    system("cls");
    printf("\n\n\t\tEnter your password[USN]:\n\t\t");
    do
    {
        regusninput();

    }while(usn[0]=='\0');
    do
    {
        if(strcmp(usn,user[i].usn)==0)
        {
            j=medcount[i];
            break;
        }
        else
        {
            system("cls");
            printf("\n\n\n\t\t    ***  Wrong Password  ***\n\n\t\tTry again or press  enter to exit:\n\n\t\t");
            regusninput();
            if(usn[0]=='\0')return main();
        }
    }while(1);

}
int uname(char name[])
{
    int x=0;
    while(x<60)
    {
        if(strcmp(name,user[x].name)==0)return x;
        else x++;
    }
    return 100;


}

void login()
{

    printf("\n\t\tLet's begin with your introduction\n\n");
    printf("\n\t\tWhat should I call you?\n\t\t");
    nameinput();



    printf("\n\n\t\tAre you a boy or a gal [M/F]\n\t\t");
    genderinput();

    printf("\n\n\t\tWhat is your USN[10digits]?\n\t\t");
    usninput();

    printf("\n\n\t\tHow old are ya?\n\t\t");
    ageinput();
    getch();

    system("cls");
    printf("\n\n\n\t\t\t.........That's great ........\n\n\t\t\t  ...Now let's get started...\n");


    logcount++;
}

int options()
{
    printf("\n\n\n\n\t\tPress \" 1 \" to buy medicines");
    printf("\n\n\t\tPress \" 2 \" to book an appointment with your doctor");
    printf("\n\n\t\tPress \" 3 \" to ask your doctor any queries");
    printf("\n\n\t\tPress \" 4 \" to give user ratings");
    printf("\n\n\t\tPress \" 0 \" to exit\n\n\t\t");
    key=optinput();

}

void medbuy()
{

   system("cls");
   printf("\n\t\t[ You can buy upto 15 different medicines ]");

   do
   {

       printf("\n\n\n\t\tEnter medicine name\t\tQuantity\n\t\t");
       scanf("%s",hp[i][j].med);
       printf("\t\t\t\t\t\t");
       do
       {
           qtyinput();
           if(hp[i][j].qty==0)
           {
                printf("\n\n\t\tMedicine quantity can't be zero try again :");continue;

           }

       }while(hp[i][j].qty==0);

       printf("\n\n\t\tPress \"1\" to keep entering medicine name");
       printf("\n\n\t\tPress \"0\" to continue  ");
       key=twoinput();
       j++;
       if(j==15)
       {
           system("cls");
           printf("\n\n\n\n\t\tSorry You've reached your limit for today\n\n\t\tPress any key to continue\n\t\t");
           getch();fflush(stdin);break;
       }

   }while(key==1);
   medcount[i]=j;
   viewcart();
   confirm();
}

int viewcart()
{
    system("cls");
    printf("\n\tThe following ITEMS have been added to YOUR CART ");
    printf("\n\n\n\t\tMedicines\t\tQty");
    for(k=0;k<j;k++)
        printf("\n\n\t\t%s\t\t\t%d",hp[i][k].med,hp[i][k].qty);
}

int confirm()
{
    printf("\n\n\t\tEnter \"1\" to PROCEED to PAYMENT OPTION");
    printf("\n\n\t\tEnter \"0\" to CANCEL and EXIT program\n\t\t");
    key=twoinput();
    switch(key)
    {
        case 1:detail();
               buythankmsg();
               break;
        case 0:exit(0);
                break;
        default:confirm();
    }
}

int detail()
{
    system("cls");
    printf("\n\n\n\n\t\tENTER YOUR PHONE NUMBER:\n\t\t ");
    phnoinput();

    printf("\n\n\n\t\tENTER DELIVERY ADDRESS:\n\t\t ");
    fflush(stdin);
    fgets(user[i].address,249,stdin);
}
void buythankmsg()
{
    system("cls");
    printf("\n\n\n\t\t   \"\"\"  Thank You for your purchase  \"\"\"");
    printf("\n\n\n\t\"\"\"  Your package should reach you within 30 minutes  \"\"\"");

}
void book()
{
    system("cls");
    printf("\n\n\n\n\t\tENTER YOUR PHONE NUMBER:\n\t\t ");
    phnoinput();
    printf("\n\n\n\t\tEnter date for your appointment[dd/mm/yy]:\n\t\t");
    dateinput();
    bookthankmsg();
}
void bookthankmsg()
{
    system("cls");
    printf("\n\n\n\t\tYour appointment request has been registered successfully");
    printf("\n\n\n\t\tThe date is %s",user[i].date);
    bookcount++;
    printf("\n\n\n\n\t\tThe time of your appointment will be messaged\n\n\t\t  to your registered PHONE NUMBER shortly\n");
    getch();
    system("cls");
}
void ask()
{
    system("cls");
    printf("\n\n\n\t\tWrite your question(should be a one liner):\n\n\t\t");
    fflush(stdin);
    scanf("%[^\n]",user[i].question,250,stdin);
    printf("\n\n\n\t\tYour question's been registered\n\n\t\t%s",user[i].question);
    printf("\n\n\n\t\tWe'll get back to you soon with your answer");

}

void rating()
{

    system("cls");
    printf("\n\n\n\t\tHow would you rate our program\n\t\t");
    printf("\n\n\t\t1.Excellent\t\t2.Very good\n\n\n\t\t3.Good\t\t\t4.Bad\n\n\n\t\tEnter no:");
    key=rateinput();
    switch(key)
    {
        case 1:excellent++;
               break;
        case 2:vgood++;
               break;
        case 3:good++;
               break;
        case 4:bad++;
               break;
    }
}

void develop()
{
    do
    {
        system("cls");
        printf("\n\t\t\t   DEVELOPER MODE   ");
        if(out!=0)
        {
            printf("\n\n\t\tALERT! SYMPTOM HAS BEEN REPORTED");
            printf("\n\n\t\tNAME      \tHOSTEL  \tROOM  \tCONTACT");
            for(flag=1;out!=0;out--)
            {
                    printf("\n\n\t\t%s  \t%s  \t%s  \t%s\n",cov[out].name,cov[out].hostel,cov[out].room,cov[out].contact);
            }
            getch();system("cls");
        }

        printf("\n\n\t\tPress \" 0 \" to VIEW/CLEAR ORDERS ");
        printf("\n\n\t\tPress \" 1 \" to VIEW/CLEAR APPOINTMENT REQUESTS ");
        printf("\n\n\t\tPress \" 2 \" to VIEW QUESTIONS ");
        printf("\n\n\t\tPress \" 3 \" to VIEW RATINGS  ");
        printf("\n\n\t\tPress \" 99 \" to RETURN\n\n\t\t");
        scanf("%d",&key);

        switch(key)
        {
            case 99:break;

            case 0:display();

                    break;
            case 1:appdisplay();
                    break;
            case 2:askdisplay();
                    break;
            case 3:ratedisplay();
                    break;


        }

    }while(key!=99);



}

void display()
{
    system("cls");
    int n,m,x=0,y=0,counter=0;int del[60];
    for(n=0;n<logcount;n++)
    {
        if(userdata[n].buydata!=0)
        {
            counter++;
            del[n]=n;
            printf("\t    %d.  Name = %s\tPhNo. = %s\n",counter,user[n].name,user[n].phno);
            printf("\t        Address = %s\n\n",user[n].address);
            printf("\t        MEDICINE \t     QUANTITY \n\n");

            for(m=0;m<medcount[n];m++)
            {

                printf("\t        %s \t\t         %d\n ",hp[n][m].med,hp[n][m].qty);

            }
            printf("\n\t**********************************************\n");


        }
        else del[n]=99;
    }
    printf("\n         Enter entry to delete: \n         ");
    scanf("%d",&n);

    while(1)
    {
        if (del[x]!=99)y++;
        if(y==n)break;
        x++;

    }
    userdata[x].buydata=0;
    medcount[x]=0;
    system("cls");
    printf("\n\n\n\n         Entry deleted\n");
    printf("\n         Press \" 1 \" to refresh\n         Press \" 2 \" to main menu");
    scanf("%d",&key);
    if(key==1)
    {
                system("cls");

                display();
    }
    if(key==2)
    {
        system("cls");
        return;
    }


}

void appdisplay()
{
    system("cls");
    int n,m,x=0,y=0,counter=0;int del[60];
    for(n=0;n<logcount;n++)
    {
        if(userdata[n].appdata!=0)
        {
            counter++;
            del[n]=n;
            printf("\n\n\t    %d Name = %s\tPhNo. = %s\n",counter,user[n].name,user[n].phno);
            printf("\n\t    REQUESTED DATE = %s\n\n",user[n].date);
            printf("\n\t*********************************************\n");

        }
        else del[n]=99;
    }


    printf("\n\t    Press \" 1 \" to confirm time of appointment\n\t    Press \" 2 \" to delete request\n\t    Any other key to go Back to Main Menu\n\t    ");
    scanf("%d",&key);
    switch(key)
    {
        case 1:     printf("\n\n\t    Enter entry no. of appointment: ");
                    scanf("%d",&n);

                    while(1)
                    {
                        if (del[x]!=99)y++;
                        if(y==n)break;
                        x++;
                    }
                    fflush(stdin);
                    fgets(user[x].appanswer,199,stdin);
                    userdata[x].appdata=0;
                    printf("\n\n\t    Appointment confirmed\n");
                    printf("\n\n\t    Press \" 1 \" to refresh\n");
                    scanf("%d",&key);
                    if(key==1)
                    {
                                system("cls");
                                appdisplay();
                    }
                    else return;
                    break;



        case 2:    printf("\n\n\t    Enter entry to delete: ");
                   scanf("%d",&n);

                    while(1)
                    {
                        if (del[x]!=99)y++;
                        if(y==n)break;
                        x++;

                    }
                    userdata[x].appdata=0;
                    system("cls");
                    printf("\n\t    Entry deleted\n");
                    printf("\n\t    Press \" 1 \" to refresh\n\n\t    Any other key to return to main menu");
                    scanf("%d",&key);
                    if(key==1)
                    {
                                system("cls");
                                appdisplay();
                    }
                    else return;
                    break;
        default: return main();
    }

}

void askdisplay()
{
    system("cls");
    int n,m,x=0,y=0,counter=0;int del[60];
    for(n=0;n<logcount;n++)
    {
        if(userdata[n].askdata!=0)
        {
            counter++;
            del[n]=n;
            printf("\n\t\t    %d.  %s\n",counter,user[n].name);
            printf("\n\t\t        %s\n\n",user[n].question);
            printf("\n\t*********************************************\n");

        }
        else del[n]=99;
    }
    printf("\n\t\tPress \" 1 \" to ANSWER questions\n\n\t\tPress \" 2 \" to DELETE question\n\n\t\tAny other key to go back to Main Menu  ");
    scanf("%d",&key);
    switch(key)
    {
        case 1:     printf("\n\t\tEnter entry no. to answer: ");
                    scanf("%d",&n);

                    while(1)
                    {
                        if (del[x]!=99)y++;
                        if(y==n)break;
                        x++;
                    }
                    system("cls");
                    printf("\n\t\tWrite your answer here: \n\t\t");
                    fflush(stdin);
                    fgets(user[x].answer,199,stdin);
                    userdata[x].askdata=0;
                    printf("\n\t\tAnswered successfully\n");
                    printf("\n\t\tPress \" 1 \" to refresh\n");
                    scanf("%d",&key);
                    if(key==1)
                    {
                                system("cls");
                                askdisplay();
                    }
                    else return;
                    break;



        case 2:    printf("\n\t\tEnter entry to delete: ");
                   scanf("%d",&n);

                    while(1)
                    {
                        if (del[x]!=99)y++;
                        if(y==n)break;
                        x++;

                    }
                    system("cls");
                    userdata[x].askdata=0;
                    printf("\n\t\tEntry deleted\n");
                    printf("\n\t\tPress \" 1 \" to refresh\n\n\t\tAny other key to return to Main Menu  ");
                    scanf("%d",&key);
                    if(key==1)
                    {
                                system("cls");
                                askdisplay();
                    }
                    else return;
                    break;
        default: return main();
    }

}

void ratedisplay()
{
    int n,m,x=0,y=0,counter=0;int del[60];
    printf("\t    % users rated Excellent\n",excellent);
    printf("\t    % users rated Very good\n",vgood);
    printf("\t    % users rated Good\n",good);
    printf("\t    % users rated Bad\n",bad);
    /*printf("\t      Press 1 to show detailed review");
    scanf("%d",&key);
    if(key==1)
    {
            for(n=0;n<logcount;n++)
            {
                if(userdata[n].ratedata!=0)
                {
                    counter++;
                    del[n]=n;
                    printf("\t    %d Name = %s\tPhNo. = %s\n",counter,user[n].name,user[n].phno);
                    printf("\t    %s\n\n",user[n].question);
                    printf("\n\t***************************************\n");

                }
                else del[n]=0;
            }
            printf("\nEnter entry to delete: \n");
            scanf("%d",&n);

            while(1)
            {
                if (del[x]!=0)y++;
                if(y==n-1)break;
                x++;

            }
            userdata[x].askdata=0;
            printf("Entry deleted\n");
            printf("Press 1 to refresh\n");
            scanf("%d",&key);
            if(key==1)
            {
                system("cls");
                askdisplay();
            }
            else return;

    }*/

}

int intintroinput()
{
    int num=0,ch;
    do
    {
        ch=getch();
        if(ch>=48&&ch<=57)
        {
          printf("%c",ch);
          num=ch-48;
          break;
        }
        if(ch==13)break;
    }while(1);
    return num;

}
int intpreinput()
{
    int num=0,ch;
    do
    {
        ch=getch();
        if(ch==49||ch==50||ch==55)
        {
          printf("%c",ch);
          num=ch-48;
          break;
        }
        if(ch==13)break;
    }while(1);
    return num;

}

int twoinput()
{
    int num=0,ch;
    do
    {
        ch=getch();
        if(ch==48||ch==49)
        {
          printf("%c",ch);
          num=ch-48;
          break;
        }
        if(ch==13)break;
    }while(1);
    return num;

}

char nameinput()
{
    char a;int w=0;
    do
    {

        a=getch();
        if(a>='a'&&a<='z'||a>='A'&&a<='Z')
        {
            printf("%c",a);
            user[i].name[w]=a;
            w++;
            if(w==24)break;

        }

        if(a==13)
        {
            user[i].name[w]='\0';
            break;
        }


        else continue;

    }while(1);
    return user[i].name;
}

char regnameinput()
{
    char a;int w=0;
    do
    {

        a=getch();
        if(a>='a'&&a<='z'||a>='A'&&a<='Z')
        {
            printf("%c",a);
            name[w]=a;
            w++;
            if(w==24)break;

        }

        if(a==13)
        {
            name[w]='\0';
            break;
        }


        else continue;

    }while(1);
    return name;
}

char genderinput()
{
    char ch;
    do
    {
        ch=getch();
        if(ch=='m'||ch=='f'||ch=='M'||ch=='F')
        {
          printf("%c",ch);
          user[i].gender=ch;
          break;
        }
        if(ch==13)break;
    }while(1);
    return user[i].gender ;

}


char usninput()
{
    char a;int w=0;
    do
    {

        a=getch();
        if(a>='0'&&a<='9'||a>='A'&&a<='Z')
        {
            printf("%c",a);
            user[i].usn[w]=a;
            w++;
            if(w==10)
            {
                 user[i].usn[w]='\0';
                 break;

            }

        }

        else continue;

    }while(1);




    return user[i].usn;
}

char regusninput()
{
    char a;int w=0;
    do
    {

        a=getch();
        if(a>='0'&&a<='9'||a>='A'&&a<='Z')
        {
            printf("%c",a);
            usn[w]=a;
            w++;
            if(w==10)
            {
                 usn[w]='\0';
                 break;

            }

        }
        if(a==13)
        {
            usn[w]='\0';
            break;
        }
        else continue;

    }while(1);




    return usn;
}

int ageinput()
{
    int num=0,ch,counter=0;
    do
    {
        ch=getch();
        if(ch>=48&&ch<=57)
        {
          counter++;

          printf("%c",ch);
          num = num * 10 + (ch-48);
          user[i].age=num;
          if(counter==2)break;

        }
        if(ch==13)break;
    }while(1);
    return user[i].age;

}

int optinput()
{
    int num=0,ch;
    do
    {
        ch=getch();
        if(ch==48||ch==49||ch==50||ch==51||ch==52)
        {
          printf("%c",ch);
          num=ch-48;
          break;
        }

    }while(1);
    return num;

}

int qtyinput()
{
    int num=0,ch,counter=0;
    do
    {
        ch=getch();
        if(ch>=48&&ch<=57)
        {
          counter++;

          printf("%c",ch);
          num = num * 10 + (ch-48);
          hp[i][j].qty=num;
          if(counter==2)break;

        }
        if(ch==13)break;
    }while(1);
    return hp[i][j].qty;

}

char phnoinput()
{
    char a;int w=0;
    do
    {

        a=getch();
        if(a>='0'&&a<='9')
        {
            printf("%c",a);
            user[i].phno[w]=a;
            w++;
            if(w==10)
            {
                 user[i].phno[w]='\0';
                 break;

            }

        }

        else continue;

    }while(1);
    return user[i].phno[w];
}


/*char addressinput()
{
    char a;int w=0;
    do
    {

        a=getch();
        if(a>='a'&&a<='z'||a>='A'&&a<='Z')
        {
            printf("%c",a);
            user[i].name[w]=a;
            w++;
            if(w==24)break;

        }

        if(a==13)
        {
            user[i].name[w]='\0';
            break;
        }


        else continue;

    }while(1);

    return user[i].name;
}
*/

char dateinput()
{
    char a;int w=0;
    do
    {

        a=getch();
        if(a>='0'&&a<='9')
        {
            if(w==2||w==5)a='/';
            printf("%c",a);
            user[i].date[w]=a;
            w++;
            if(w==10)
            {
                 user[i].date[w]='\0';
                 break;

            }

        }

        else continue;

    }while(1);
    return user[i].date[w];
}

int rateinput()
{
    int num=0,ch;
    do
    {
        ch=getch();
        if(ch==49||ch==50||ch==51||ch==52)
        {
          printf("%c",ch);
          num=ch-48;
          break;
        }
        if(ch==13)break;
    }while(1);
    return num;

}

