#include<iostream>
#include<string>
#include <cctype>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>
#include<unistd.h>
#include<iomanip>
#include<conio.h>
#include<thread>

using namespace std;
string word="hello";
string hint="wow";
int correct_guess=0,tries_left,wins=0;
bool flag1;
char guess='0';
ifstream inFile0;
ifstream inFile1;
ifstream inFile2;
ifstream inFile3;
ifstream inFile4;


//-----------------------------------------------------

struct node
{
    char data;
    bool flag=false;
    node*next;
};
struct node*head;
struct node*l;
struct node*temp;
//-----------------------------------------------------
struct node2
{
    char data2;
    node2*next2;
};
struct node2*head2;
struct node2*l2;
struct node2*temp2;
//-----------------------------------------------------
void insert_word(string word);
void display(char letter);
void insert_wrong_guess(char d);
void display_wrong();
void game();
void game_name();
void instructions();
void loading();


//-----------------------------------------------------


void reset()
{

    correct_guess=0;
    l=head;
    l2=head2;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        delete(temp);
    }

    while(head2 != NULL)
    {
        temp2 = head2;
        head2 = head2->next2;
        delete(temp2);
    }
}

//-----------------------------------------------------

void level_0 ()
{

    getline(inFile0,word,',');
    getline(inFile0,hint,';');
}
void level_1()
{

    getline(inFile1,word,',');
    getline(inFile1,hint,';');

}
void level_2()
{

    getline(inFile2,word,',');
    getline(inFile2,hint,';');

}
void level_3()
{

    getline(inFile3,word,',');
    getline(inFile3,hint,';');

}
void level_4()
{

    getline(inFile4,word,',');
    getline(inFile4,hint,';');

}

//-----------------------------------------------------
void game()
{
    int word_length=word.length();
    char guess;
    insert_word(word);
    tries_left= word_length+1;
    for(int a =0; tries_left>=1; a++)
    {
        if(correct_guess== word_length)
        {
            break;
        }
        cout<<endl<<setw(50)<<"LEVEL "<<wins<<endl<<endl;
        cout<<endl<<"hint: "<<hint<<endl<<endl;

        display(guess);

        cout<<"wrong guesses: ";
        display_wrong();

        cout<<endl;

        cout<<"Tries Left: "<<tries_left<<endl;
        cout<<"Correct guesses: "<<correct_guess<<endl;

        cout<<"letter: ";
        if(correct_guess!=word_length && (tries_left!=0))
        {
            cin>>guess;
        }
        guess = tolower(guess);
        cout<<endl;
        while(isalpha(guess)==false)
        {
            cout<<"~ WRONG INPUT!!! ~"<<endl;
            cout<<"Please enter letter only (Aa - Zz): ";
            cout<<"letter: ";
            if(correct_guess!=word_length && (tries_left!=0))
            {
                cin>>guess;
            }
            guess = tolower(guess);
            cout<<endl;
        }

        system("CLS");

    }
    if (correct_guess==word_length)
    {
        cout<<endl<<endl<<setw(10)<<"YAY!... You won the level!"<<endl;
        wins++;
    }
    else
        cout<<endl<<endl<<setw(10)<<"OH NO!... You lost the game"<<endl;
    sleep(1);
    system("CLS");

}


//-----------------------------------------------------

int main()
{

    inFile0.open("Level 0.txt");
    inFile1.open("Level 1.txt");
    inFile2.open("Level 2.txt");
    inFile3.open("Level 3.txt");
    inFile4.open("Level 4.txt");

    game_name();
    sleep(2);
    system("CLS");
    instructions();
    cout<<"\n PRESS ENTER TO START GAME..."<<endl;
    getch();
    system("CLS");
    while(wins<=5)
    {
        switch(wins)
        {
        case 0:
            level_0();
            game();
            reset();
            cin.clear();
            break;
        case 1:
            level_1();
            game();
            reset();
            cin.clear();
            break;

        case 2:
            level_2();
            game();
            reset();
            cin.clear();
            break;
        case 3:
            level_3();
            game();
            reset();
            cin.clear();
            break;
        case 4:
            level_4();
            game();
            reset();
            cin.clear();
            break;
        case 5:
            cout<<"You have won all levels";
        default:
            return(0);

        }
    }
    return (0);
}

//-----------------------------------------------------
void insert_word(string word)
{
    for(int i=0; i<=word.length(); i++)
    {
        l=head;
        if (head == NULL)
        {
            head= new node;
            head -> data =word[i];
            head -> next = NULL;
        }
        else
        {
            while (l->next != NULL)
            {
                l= l-> next;
            }

            if(l-> next == NULL)
            {
                temp = new node;
                temp -> data= word[i];
                temp -> next = NULL;
                l -> next = temp;
            }
        }
    }
}
//-----------------------------------------------------
void display(char letter)
{
    bool Duplicate=0;
    flag1=0;
    l=head;
    while(l->next!=NULL)
    {
        if(l->data==letter)
        {
            if(l->flag == true){
                    Duplicate = 1;
                    cout<<"Letter already guessed...\n"<<endl;
                    cout<<endl;
            }
            else{
                correct_guess= correct_guess+1;}
            l->flag=true;
            flag1=1;
        }
        l=l->next;
    }
    if(flag1==0){
        insert_wrong_guess(letter);
        tries_left--;}
    l=head;


        while(l->next!=NULL)
    {
        if(l->flag==true)
        {
                cout<<l->data;
        }
        else if(l->flag!=true)
        {
            cout<<"-";
        }
        l=l->next;

    }

    cout<<endl<<endl;

}
//-----------------------------------------------------
void insert_wrong_guess(char d)
{
    bool duplicate=0;

    l2=head2;
    if (head2 == NULL)
    {
        head2= new node2;
        head2 -> data2 =d;
        head2 -> next2 = NULL;
    }
    else
    {
        l2=head2;
        while (l2->next2 != NULL)
        {
            l2= l2-> next2;

            if(l2->data2==d )
            {
                duplicate=1;
                tries_left++;
                cout<<"Letter already guessed...\n"<<endl;
                cout<<endl;
                goto duplicate;
            }

        }

        if(l2-> next2 == NULL)
        {
            temp2 = new node2;
            temp2 -> data2= d;
            temp2 -> next2 = NULL;
            l2 -> next2 = temp2;
        }

    }
duplicate:
    {
        //do nothing
    }

}
//-----------------------------------------------------
void display_wrong()
{
    l2=head2;
    while (l2-> next2 != NULL)
    {
        cout<< l2->data2<<" ";
        l2 = l2->next2;
    }
    if(l2->next2 == NULL)
        cout<<l2->data2;
}
//-----------------------------------------------------

void instructions()
{
    cout<<setw(50)<<"HANGMAN"<<endl<<endl<<endl;
    cout<<setw(10)<<"INSTRUCTIONS"<<endl<<endl;
    cout<<"1- You will be given a word to guess."<<endl;
    cout<<"2- You have to guess the word in given tries."<<endl;
    cout<<"3- Don't try to input an invalid character."<<endl;
    cout<<"4- You have 5 tries in total to input wrong alphabet."<<endl;
    cout<<"5- Every time when you will guess a wrong word, you will be punished."<<endl;
    cout<<"6- When you will lose all your 5 tries, you will be hanged."<<endl;
}

//-----------------------------------------------------

void game_name()
{
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    for(int i=1; i<=15; i++)
    {
        cout<<setw(30);
        for(int j=1; j<=60; j++)
        {
            //H
            if((i==1 && (j<5 || (j>6 && j<11))) || (i==10 && (j<5 || (j>6 && j<11))) || (i==5 && (j==5 || j==6)) || (i==6 && (j==5 || j==6)))
                cout<<"-";
            else if((i<10 && j==1) || (i<10 && j==10) ||(j==4 && i<5) || (j==4 && (i>6 && i<10)) || (j==7 && i<5) || (j==7 && (i>6 && i<10)))
                cout<<"|";
            //a
            else if((i==6 && j==11) || (i==9 && j==15) || (i==7 && j==12))
                cout<<"/";
            else if((i==9 && j==11) || (i==6 && j==15) || (i==8 && j==12))
                cout<<"\\";
            else if(i==5 && (j>11 && j<15) || (i==10 && (j>11 && j<15)) || (i==5 && j==17) || (i==10 && j==17))
                cout<<"-";
            else if((i==6 && j==16) || (i==9 && j==16) || ((i>5 && i<10) && j==18) || ((i==7 || i==8) && j==14))
                cout<<"|";
            //n
            else if((i==5 && j== 19) || (i==5 && (j>21 && j<25)) || (i==10 && j==19) || (i==10 && j==24) || (i==6 && j==22))
                cout<<"-";
            else if(((i>5 && i< 10 ) && j==20) || ((i>5 && i<10 ) && j==25) || ((i>6 && i< 10) && j==23))
                cout<<"|";
            else if(i==6 && j==21)
                cout<<"/";
            //g
            else if((i==5 && (j>26 && j<30)) || (i==10 && (j>26 && j<30)) || (i==5 && j==32) || (i==15 && (j==31 || j==30 || j==29)) || (i==13 && (j==30 || j==29)) || (i==11 && j==27))
                cout<<"-";
            else if(((i==6 || i==9 || i==10 || i==11) && j==31) || ((i>5 && i<13) && j==33))
                cout<<"|";
            else if((i==6 && j==26) || (i==9 && j==30) || (i==7 && j==27) || (i==8 && j==29) || (i==12 && j==31) || (i==13 && j==33) || (i==14 && j==32))
                cout<<"/";
            else if((i==9 && j==26) || (i==6 && j==30) || (i==8 && j==27) || (i==7 && j==29) || (i==12 && j==28) || (i==12 && j==26) || (i==13 && j==27) || (i==14 && j==28))
                cout<<"\\";
            //M
            else if(i==1 && (j==33 || j==34 || j==35 || j==36) || (i==10 && (j==34 || j==35)) || (i==1 && (j==41 || j==42 || j==43 || j==44)) || (i==10 && (j==42 || j==43 || j==44)))
                cout<<"-";
            else if((i<6 && j==33) || (i<10 && j==44) || ((i>4 && i<10) && j==41) || ((i>4 && i<10) && j==36))
                cout<<"|";
            else if((i==2 && j==37) || (i==3 && j==38) || (i==5 && j==37) || (i==6 && j==38))
                cout<<"\\";
            else if((i==3 && j==39) || (i==2 && j==40) || (i==6 && j==39) || (i==5 && j==40))
                cout<<"/";
            //a
            else if((i==6 && j==45) || (i==9 && j==49) || (i==7 && j==46))
                cout<<"/";
            else if((i==9 && j==45) || (i==6 && j==49) || (i==8 && j==46))
                cout<<"\\";
            else if(i==5 && (j>45 && j<49) || (i==10 && (j>45 && j<49)) || (i==5 && j==51) || (i==10 && j==51))
                cout<<"-";
            else if((i==6 && j==50) || (i==9 && j==50) || ((i>5 && i<10) && j==52) || ((i==7 || i==8) && j==48))
                cout<<"|";
            //n
            else if((i==5 && j==53) || (i==5 && (j>55 && j<59)) || (i==10 && j==53) || (i==10 && j==58) || (i==6 && j==56))
                cout<<"-";
            else if(((i>5 && i<10 ) && j==54) || ((i>5 && i<10 ) && j==59) || ((i>6 && i< 10) && j==57))
                cout<<"|";
            else if(i==6 && j==55)
                cout<<"/";
            else
                cout<<" ";
        }
        cout<<endl;
    }
}

//-----------------------------------------------------
