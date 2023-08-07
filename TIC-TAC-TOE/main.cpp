#include<iostream>
#include<stdlib.h>
using namespace std;                                             //declare the board
 char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};   //DECLARED AS A GLOBAL VARIABLE
char turn='X';
 bool draw;
int row,coloum;
void display(){                                                //DISPLAY FUNCTION
   system("cls");
 cout<<"\n\t\tTIC-TAC-TOE GAME IN C++"<<endl;
    cout<<"\n\t\tplayer 1 -- symbol : X"<<endl;
    cout<<"\t\tplayer 2 -- symbol : 0"<<endl;

                                                          //LEADER BOARD SET-UP
  cout<<"\n\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"\t\t ____|_____|______"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
   cout<<"\t\t ____|_____|______"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
    cout<<"\t\t     |     |     "<<endl;
}
void player(){                     //this is the player function where the turn will come one by one
 int choice;

if(turn == 'X')
{
    cout<<"\n\t player1 [X] turn:";
}
if(turn == '0')
{
    cout<<"\n\t player2 [0] turn:";         //PRESS THE POSITION WHERE YOU WANTS TO PUT THE SYMBOL
}
     cin>>choice;
    switch(choice){                 //using switch case conditional statements are here
        case 1:row=0;coloum=0;
            break;
        case 2:row=0;coloum=1;
            break;
        case 3:row=0;coloum=2;
            break;
       case 4:row=1;coloum=0;
            break;
        case 5:row=1;coloum=1;
            break;
        case 6:row=1;coloum=2;
            break;
        case 7:row=2;coloum=0;
            break;
        case 8:row=2;coloum=1;
            break;
        case 9:row=2;coloum=2;
            break;
            default:
            cout<<"wrong input";
    }

    if(turn=='X' && board[row][coloum]!='X' && board[row][coloum]!='0'){
        board[row][coloum]='X';
        turn='0';                                        //calculating terms
    }
    else if(turn=='0'  && board[row][coloum]!='X' && board[row][coloum]!='0'){
        board[row][coloum]='0';
        turn='X';
    }
    else{
        cout<<"box already filled .try again"<<endl;    //if the box already filled then cannot store again a value
        player();
    }
}
bool gameover(){                       //GAME OVER CODE
     for(int i=0;i<3;i++)           //if player win row wise
    if(board[i][0]==board[i][1] && board[i][0]== board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i]  ) //COLUMN WISE & ROW WISE GAME OVER SETUP
     return false;
if((board[0][0]==board[1][1] && board[0][0]==board[2][2]  )||(board[0][2]==board[1][1] && board[0][2]==board[2][0]  ) )
return false;                  //if player win column wise


for(int i=0;i<3;i++)
{                                   //players playing the game
for(int j=0;j<3;j++)
{
    if(board[i][j]!='X' && board[i][j]!='0')
return true;}
}


  draw=true;                        //DRAW MATCH SET-UP
return false;
}

int main()
{
   while(gameover()){               //MAIN FUNCTION
     display();
     player();
    //  system("cls");
    display();
    gameover();
}
if(turn=='X' && draw== false)      //WINNER DECLARATION function
{
    cout<<"\tCONGRATULATION !!player2[0] win  the  game" <<endl;
}
else if(turn=='0' && draw== false)
{
    cout<<"\tCONGRATULATION !!player1[X] win  the  game" <<endl;
}
else
cout<<"\t\tgame draw"<<endl;
return 0;
}
