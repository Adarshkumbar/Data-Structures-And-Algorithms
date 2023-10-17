#include<bits/stdc++.h>
using namespace std;

char plr1,plr2,ch2,arr[9];
char num1,num2,num3,num4,num5,num6,num7,num8,num9;
int count1=1,k=0,count2=0,count3=0,count4=0;

void menu();

void about()
{
    char char1;
    system("CLS");
    cout<<"\n\n\t\t\tAbout :";
    cout<<"\n\t\t\t_______";
    cout<<"\n\n\n\t\t\t	Name  : Adarsh Kumbar ";
    cout<<"\n\n\n\t\t\tContact Details : adarshbkumbar1@gmail.com";
    cout<<"\n\n\n\n\t\t\t\t\thttps://github.com/Adarshkumbar";
    if(count4==1)
    {
        cout<<"\n\n\n\t\t\tPlease enter a valid choice!";
        count4=0;
    }
    cout<<"\n\n\n\t\t\tPlease enter 'B' to go back to main menu : ";
    cin>>char1;
    if(char1=='B' || char1=='b')
    {
        system("CLS");
        menu();
    }
    else
    {
        system("CLS");
        count4++;
        about();
    }
}

void disp()
{
    system("CLS");
    cout<<"\n\t\t\tTIC-TAC-TOE : ";
    cout<<"\n\t\t\t_____________";
    cout<<"\n\n\n\t\t\t|---|---|---|";
    cout<<"\n\t\t\t| "<<num1<<" | "<<num2<<" | "<<num3<<" |";
    cout<<"\n\t\t\t|---|---|---|";
    cout<<"\n\t\t\t| "<<num4<<" | "<<num5<<" | "<<num6<<" |";
    cout<<"\n\t\t\t|---|---|---|";
    cout<<"\n\t\t\t| "<<num7<<" | "<<num8<<" | "<<num9<<" |";
    cout<<"\n\t\t\t|---|---|---|\n";
    cout<<"\n\n\t\t\tPlayer 1  Symbol is : "<<plr1;
    cout<<"\n\n\t\t\tPlayer 2  Symbol is : "<<plr2;
}

void result()
{
    if((num1==num2 && num1==num3 && num1==plr1) || (num4==num5 && num4==num6 && num4==plr1) || (num7==num8 && num7==num9 && num7==plr1) || (num1==num4 && num1==num7 && num1==plr1) || (num2==num5 && num2==num8 && num2==plr1) || (num3==num6 && num3==num9 && num3==plr1) || (num1==num5 && num1==num9 && num1==plr1) || (num3==num5 && num3==num7 && num3==plr1))
    {
        count2++;
        disp();
        cout<<"\n\n\t\t\tPlayer 1  Won the game!";
    }
    else if((num1==num2 && num1==num3 && num1==plr2) || (num4==num5 && num4==num6 && num4==plr2) || (num7==num8 && num7==num9 && num7==plr2) || (num1==num4 && num1==num7 && num1==plr2) || (num2==num5 && num2==num8 && num2==plr2) || (num3==num6 && num3==num9 && num3==plr2) || (num1==num5 && num1==num9 && num1==plr2) || (num3==num5 && num3==num7 && num3==plr2))
    {
        count2++;
        disp();
        cout<<"\n\n\t\t\tPlayer 2 Won the game!";
    }
}

void choice()
{
    if(count1%2!=0)
        cout<<"\n\n\t\t\tPlayer 1 - Please enter any number <"<<plr1<<"> : ";
    else
        cout<<"\n\n\t\t\tPlayer 2 - Please enter any number <"<<plr2<<"> : ";
    cin>>ch2;
    if(ch2!='1' && ch2!='2' && ch2!='3' && ch2!='4' && ch2!='5' && ch2!='6' && ch2!='7' && ch2!='8' && ch2!='9')
    {
        disp();
        cout<<"\n\n\t\t\tPlease enter a valid number!";
        choice();
    }
    arr[k++]=ch2;
    for(int i=0;i<k-1;i++)
    {
        if(ch2==arr[i])
        {
            disp();
            cout<<"\n\n\t\t\tPlease enter a valid number!";
            k--;
            choice();
        }
    }
    if(ch2=='1' && count1%2!=0)
        num1=plr1;
    else if(ch2=='2' && count1%2!=0)
        num2=plr1;
    else if(ch2=='3' && count1%2!=0)
        num3=plr1;
    else if(ch2=='4' && count1%2!=0)
        num4=plr1;
    else if(ch2=='5' && count1%2!=0)
        num5=plr1;
    else if(ch2=='6' && count1%2!=0)
        num6=plr1;
    else if(ch2=='7' && count1%2!=0)
        num7=plr1;
    else if(ch2=='8' && count1%2!=0)
        num8=plr1;
    else if(ch2=='9' && count1%2!=0)
        num9=plr1;
    else if(ch2=='1' && count1%2==0)
        num1=plr2;
    else if(ch2=='2' && count1%2==0)
        num2=plr2;
    else if(ch2=='3' && count1%2==0)
        num3=plr2;
    else if(ch2=='4' && count1%2==0)
        num4=plr2;
    else if(ch2=='5' && count1%2==0)
        num5=plr2;
    else if(ch2=='6' && count1%2==0)
        num6=plr2;
    else if(ch2=='7' && count1%2==0)
        num7=plr2;
    else if(ch2=='8' && count1%2==0)
        num8=plr2;
    else if(ch2=='9' && count1%2==0)
        num9=plr2;
    count1++;
    if(count1<=10)
    {
        result();
        if(count2==1)
            return;
        if(count1==10)
            return;
        disp();
        choice();
    }
}

void select_Symb()
{
    num1='1',num2='2',num3='3',num4='4',num5='5',num6='6',num7='7',num8='8',num9='9';
    system("CLS");
    cout<<"\n\t\t\tPlease select your Symbols to start the game : ";
    cout<<"\n\t\t\t______________________________________________";
    cout<<"\n\n\t\t\t\tPlayer 1 : ";
    cin>>plr1;
    cout<<"\n\n\t\t\t\tPlayer 2 : ";
    cin>>plr2;
    disp();
    choice();
}


void menu()
{
    char ch1;
    cout<<"\n\t\t\tWelcome to Tic-Tac-Toe Game";
    cout<<"\n\t\t\t___________________________";
    cout<<"\n\n\t\t\t\tMain Menu : ";
    cout<<"\n\n\t\t\t\t S.Start\n\n\t\t\t\t A.About\n\n\t\t\t\t  E.Exit";
    if(count3==1)
    {
        cout<<"\n\n\t\t\tPlease enter a valid choice!";
        count3=0;
    }
    cout<<"\n\n\t\t\tEnter your choice : ";
    cin>>ch1;
    if(ch1!='S' && ch1!='s' && ch1!='A' && ch1!='a' && ch1!='E' && ch1!='e')
    {
        system("CLS");
        count3++;
        menu();
    }
    if(ch1=='S' || ch1=='s')
        select_Symb();
    else if(ch1=='E' || ch1=='e')
	about();
    else if(ch1=='E' || ch1=='e')
        exit(0);
}

int main()
{
    Restart :
    char ch3;
    menu();
    if(count2==0)
    {
        disp();
        cout<<"\n\n\t\t\tGame tied!";
    }
    cout<<"\n\n\t\t\tEnter 'E' to exit the game Or any key to go to main menu : ";
    cin>>ch3;
    if(ch3=='E' || ch3=='e')
        exit(0);
    else
    {
        system("CLS");
        count1=1;
        count2=0;
        k=0;
        goto Restart;
    }

    return 0;
}