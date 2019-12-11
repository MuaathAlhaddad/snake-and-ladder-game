//    THIS IS THE PROJECT OF 2016 SEM 1
//      which is a ladder and snake game using c++ code
//      we hope that you will enjoy it *_*
/*GROUP MEMBERS :
    1-Muaadh Esmail Qaid Almrham(the leader)......1529799
    2-Muhammad Hanif Bin Mohd Sapiai (the handsome guy).....1610923
    3-Che Ku Muhammad Syaukani Bin Che Ku Aris(the macho man).....1619963
    4-Fadhirul Ikhwan Bin Nor Aswan(the good guy).....1613999
    5-Aiman Asyraff Bin Zulkafli(Mr
*/


#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
struct details{                 //a structure that has the details of player
    std :: string name1, name2;
    int check;
    };
using namespace std;
string filename1 = "player1.txt"; //the external files
string filename2 = "player2.txt";
void game(int dice,int num,details players);
void welcome(void);
int main()
{
    details players ;
    int dice = 0, point= 0;
    char key;
    players.check = 0;

    system("color A");
    welcome();

    system("color B");
    cout<<"Enter player's 1 name  : ";
    cin>>players.name1;
    cout<<"Enter player's 2 name  : ";
    cin>>players.name2;

    system("cls");

    ofstream send_file1(filename1.c_str());
    send_file1<<point;                          //to start the file1 with zero value
    ofstream send_file2(filename2.c_str());
    send_file2<<point;                          //to start the file1 with zero value


     for(int x=0 ;x < 50; x++)    //number of attempts available to not get boring *_^
    {
//======================================================================================
//----------player1-------------------------------------------------------------------//|
             system("color E");                                                       //|
        cout<<"=========================="<<endl;                                     //|
        cout <<players.name1<<endl;                                                   //|
        cout<<"=========================="<<endl;                                     //|
                                                                                      //|
        cout<<"Press any key to roll the dice : ";                                    //|
        cin>>key;                                                                     //|
//------------------------------------------------------------------------------------//|
        dice = (srand() % 6 + 1);        //to generate a random number                 //|
        cout <<"you got : "<<dice<<endl ; //this variable stores the random number    //|
//------------------------------------------------------------------------------------//|
        ifstream receive_player1 ;                                                    //|
        receive_player1.open(filename1.c_str());                                      //|
        receive_player1>>point;                //get the value from the file          //|
                                                                                      //|
        players.check = 1;                     //to check which player is playing now //|
                                                                                      //|
            game(dice,point,players); //function is going to let to the player1 to go //|
                                      //through the values of snake and ladder        //|
//----------player2-------------------------------------------------------------------//|
                                                                                      //|
            cout<<"=========================="<<endl;                                 //|
            cout <<players.name2<<endl;                                               //|
            cout<<"=========================="<<endl;                                 //|
            cout<<"Press any key to roll the dice : ";                                //|
            cin>>key;                                                                 //|
//------------------------------------------------------------------------------------//|
            dice = (rand() % 6 + 1);         //to generate a random number            //|
            cout <<"u got : "<<dice<<endl ;  //this variable stores the random number?//|
//------------------------------------------------------------------------------------//|
                                                                                      //|
            ifstream receive_player2 ;                                                //|
            receive_player2.open(filename2.c_str());                                  //|
                                                                                      //|
            receive_player2>>point; //receive the value(point)of player2 from the file//|
                                                                                      //|
            players.check = 2;              //to check which player is playing now    //|
                                                                                      //|
            game(dice,point,players); //function is going to let to the player2 to go //|
                                      //through the values of snake and ladder        //|
//=======================================================================================
        }

    return 0;
}
/*************************************************************************/
                        /*Welcome Function*/
/*************************************************************************/
void welcome(void)
{
    char key;
    cout<<"\t        ";
       cout<<"\n\t%%      %% %%%%%%% %%      %%%%%%%  %%%%%%  %%%%  %%%%  %%%%%%%";
       cout<<"\n\t%%      %% %%      %%      %%       %%  %%  %%  %%% %%  %%       ";
       cout<<"\n\t%%  %%  %% %%%%%   %%      %%       %%  %%  %%  %%% %%  %%%%%      ";
       cout<<"\n\t%%  %%  %% %%      %%      %%       %%  %%  %%      %%  %%           ";
       cout<<"\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%%  %%%%%%  %%      %%  %%%%%%%     ";
       cout<<"\n\n\t\t\t        %%%%%%%%  %%%%%        ";
       cout<<"\n\t\t\t           %%     %   %      ";
       cout<<"\n\t\t\t           %%     %   %    ";
       cout<<"\n\t\t\t           %%     %%%%%"<<endl<<endl<<endl;

       cout<<setw(50)<<"SNAKE AND LADDER GAME"<<endl<<endl<<endl;

       cout<<"Press any key to continue : ";
       cin>>key;
       system("cls");
}
/*************************************************************************/
            /*Function has the ladder and the snake ranges */
/*************************************************************************/
void game(int dice, int num, details players)
{
        int zero =0 ;
        num = num +  dice;              //to accumulate to the points of the player
        cout<<"your number now is : "<<num<<endl;

            if(num >= 100)
            {
                if(players.check == 1)   //to recognize who is playing
                    {
                        cout<<players.name1<<" won"<<endl;

                        exit(1);
                    }
                else if(players.check == 2)
                    {
                        cout<<players.name2<<" won"<<endl;

                        exit(1);
                    }
            }

                        //**SNAKES RANGES**//

int &snake = num ;              //these variables can be used interchangeably
    switch(snake)
    {
        case 23 : snake = 7;
             cout <<"the snake got u , your number now is "<<snake<<endl;break;

        case 55 :snake = 13;
             cout <<"the snake got u , your number now is "<<snake<<endl;break;

        case 70 : snake = 32;
             cout <<"the snake got u , your number now is "<<snake<<endl;break;

        case 93 : snake = 67;
             cout <<"the snake got u , your number now is "<<snake<<endl;break;

        case 99 : snake = 3;
             cout <<"the snake got u , your number now is "<<snake<<endl;break;
    }

                      //**LADDER RANGE**//

    int &ladder = num ;           //these variables can be used interchangeably
    switch(ladder)
    {
        case 4 :num = 44;
             cout <<"Good!,you got the ladder , your number now is "<<num<<endl;break;

        case 11 :ladder = 33;
             cout <<"Good!,you got the ladder , your number now is "<<num<<endl;break;

        case 25 :ladder = 85;
             cout <<"Good!,you got the ladder , your number now is "<<num<<endl;break;

        case 37 :ladder = 61;
             cout <<"Good!,you got the ladder , your number now is "<<num<<endl;break;

        case 68 :num = 90;
             cout <<"Good!,you got the ladder , your number now is "<<num<<endl;break;

        case 79 :num = 97;
             cout <<"Good!,you got the ladder , your number now is "<<num<<endl;break;

    }

        if(players.check == 1)
            {
                ofstream send;
                send.open(filename1.c_str());
                send<<num;                      //to send the point of  player 1 to his/her file
            }
        else if(players.check == 2)
            {
                ofstream send;
                send.open(filename2.c_str());
                send<<num;                       //to send the point of  player 2 to his/her file
            }


}
//*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!PROGRAM ENDS HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
