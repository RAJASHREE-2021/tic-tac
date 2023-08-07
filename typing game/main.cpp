#include <iostream>
#include <windows.h>
#include <time.h>          // header files
#include <stdlib.h>
#include<conio.h>
/*here i divided the width part in the two section --->1.display part of the game and
                                                       2. score board part           */
#define SCREEN_WIDTH 90    //#define is a preprocessor directive that is used to define macros in a C++ program(macros directive).
#define SCREEN_HEIGHT 25
#define WIN_WIDTH 70       //#define directive is used to declare some constant values or an expression with a name that can be used throughout program.
using namespace std;

HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);     // This syntax is used to set the cursor position
COORD CursorPosition;                               //COORD is a structure to hold screen COORDinates X and Y

char key[10];//maximum 10 alphabet will display on the screen // 1D char array--used to display the keys  in monitor
int keyPos[10][2];   // 2D  int array--used to display the position of the keys  in monitor               //here key , keyPos and score are global variable
int score=0;         //for calculating score
void gotoxy(int x,int y){
    CursorPosition.X=x;      // this is the gotoxy function using this we can set the position
    CursorPosition.Y=y;
    SetConsoleCursorPosition(console,CursorPosition);
}
void setcursor(bool visible,DWORD size){
    if(size==20)
        size=20;
    CONSOLE_CURSOR_INFO cursor;    //  set cursor function visible on time (copy from net)
    cursor.bVisible=visible;
    cursor.dwSize=size;
    SetConsoleCursorInfo(console,&cursor);
}
void border(){
for(int i=0;i<SCREEN_WIDTH;i++){          //setting  a border like margin in the game display
    gotoxy(i,SCREEN_HEIGHT);              //in width portion
    cout<<"+";
}
for(int i=0;i<SCREEN_HEIGHT;i++){         //setting the border into the height portion
        gotoxy(0,i);cout<<"+";
    gotoxy(SCREEN_WIDTH,i);cout<<"+";
}
for(int i=0;i<SCREEN_HEIGHT;i++){
    gotoxy(WIN_WIDTH,i);
    cout<<"+";
}
}
void alpha(int alp){   //for displaying  alphabet on screen // rand is used for randomly seleted value
key[alp]=65+rand()%25; //65 is the ascii vale of A so i started from 65 ..here i used 25 because array start from zero and there has total 26 character
keyPos[alp][0]=2+ rand()%(WIN_WIDTH-2);//displaying the key position
keyPos[alp][1]=1;
}
void drawalpha(int alp){  // draw alphabet function
if(keyPos[alp][0]!=0){      //it should not be at y=0 axis
    gotoxy(keyPos[alp][0],keyPos[alp][1]);
    cout<<key[alp];
}
}
void erasealpha(int alp){  //erase the alphabet when we press the key from keyboard
if(keyPos[alp][0]!=0){   //should not touch at y=0 axis
    gotoxy(keyPos[alp][0],keyPos[alp][1]);
    cout<<"  ";
}
}
void resetalpha(int alp){    // when we press the key after that reset function is important
erasealpha(alp);    //in reset at first called erase function then generate it again
alpha(alp);
}
void gameover(){
system("cls");      // clear  the screen
cout<<endl;           //gameover function
cout<<"\t\t----------------------------"<<endl;
cout<<"\t\t--------GAME OVER-----------"<<endl; //when alphabet touch the x=0 axis then called the function for ending the game
cout<<"\t\t----------------------------"<<endl;
cout<<"\t\t PRESS ENTER TO BACK MENU"<<endl;
getch();  //pressing any key is important when we call getch() function
}
void upscore(){           //updation score board
gotoxy(WIN_WIDTH +7,5);     //declare the position where i wants to displaying the score board in display
cout<<"SCORE:"<<score<<endl; //displaying score
}
void instruct(){     // there are some instruction about the game
system("cls");
cout<<"Instructions"<<endl;
cout<<"------------"<<endl;
cout<<"you will see the falling character "<<endl;
cout<<"press key from keyboard"<<endl;
cout<<"if you want to exit the game press escape keyword"<<endl;
cout<<"\t\t PRESS ENTER TO BACK MENU"<<endl;
getch();
}
void play(){       // playing game function
score=0;      //when we started the score is zero
for(int i=0;i<10;i++)
{                    //falling the keys
    keyPos[i][0]=keyPos[i][1]=1;
}
system("cls");
border();
upscore();
for(int i=0;i<10;i++)
    alpha(i);     //score board
    gotoxy(WIN_WIDTH +5,2);
    cout<<"Typing game";
    gotoxy(WIN_WIDTH +6,4);
    cout<<"-------------"; //position of board
 gotoxy(18,5);
 cout<<"press any key to start!";
 getch();
 gotoxy(18,5);
cout<<"             ";
while(1){
    if(kbhit()){   //kbhit function is used to determine if a key has been pressed or not.
        char ch=getch();//To use kbhit function in your program you should include the header file “conio. h”.
        for(int i=0;i<10;i++){
            if(ch==key[i] || ch-32  == key[i]){ //32-space ascii
                resetalpha(i);
                score++;
                upscore();
            }
        }
        if(ch==27){  //27 ascii of ESC key
            break;  //exit program
        }
    }
    for(int i=0;i<10;i++)
        drawalpha(i);
    Sleep(500);      //use this function for pausing your program execution for desired number of seconds:
     for(int i=0;i<10;i++){   // sleep(x); x can take any value in seconds.
        erasealpha(i);
        keyPos[i][1]++;
       if(keyPos[i][1]>SCREEN_HEIGHT){  //if alphabet touch the border then gameover
        gameover();
       }
     }
   }
}
int main(){  //int function
setcursor(0,0);   //setting the cursor at 0,0 position
//The srand() function in C++ seeds the pseudo-random number generator used by the rand() function.It is defined in the cstdlib header file.
srand( (unsigned)time(NULL));
do{
    system("cls");
    gotoxy(10,5); cout<<"====================";
    gotoxy(10,6); cout<<"     Typing Game    "; //using gotoxy function to set the position of displaying object
    gotoxy(10,7); cout<<"====================";
    gotoxy(10,9); cout<<"1.Start game";
    gotoxy(10,10); cout<<"2.Instruction ";
    gotoxy(10,11); cout<<"3.Quit ";
    gotoxy(10,14); cout<<"Select any option: ";
    int p;
    cin>>p;
    switch(p){     //switch case for giving condition in program
    case 1: play();break;
    case 2:instruct();break;
    case 3:exit(0);break;
    default:cout<<"wrong input";
    }
}while(1);
return 0;
}
