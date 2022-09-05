#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <algorithm> 
#include <stdlib.h>
#include <time.h>

using namespace std;

#define ITOG "Yes"

struct for_kart
{
    int number;
    int mast;
    int status;
};

struct otchet
{
    int koloda;
    int player1;
    int player2;
    int kozur_basa;
};

struct PlayersCards
{
    int *player1 = new int [6];
    int *player2 = new int [6];
    int *koloda = new int [36];
};

enum ConsoleColor
{
        Black         = 0,
        Blue          = 1,
        Green         = 2,
        Cyan          = 3,
        Red           = 4,
        Magenta       = 5,
        Brown         = 6,
        LightGray     = 7,
        DarkGray      = 8,
        LightBlue     = 9,
        LightGreen    = 10,
        LightCyan     = 11,
        LightRed      = 12,
        LightMagenta  = 13,
        Yellow        = 14,
        White         = 15
};

void SetColor1(int text)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, text);
}

bool kartStart()
{
    char cmdLog = 'a'; 
    while (cmdLog != '\r') 
        {
            SetColor1 (Blue);
            cout << "\nStart the game? (y/n) ";
            SetColor1 (Yellow);   
            cmdLog = getche();
            if (cmdLog == 'y') return (1);
                else if (cmdLog == 'n') {SetColor1 (White); exit(0);}
                    else { system ("cls"); continue;}
        }
    return (0);
}

void shuffle (PlayersCards *AllCards1)
{
    int temp = 0;
    int randomIndex = 0;
    for (int i=0; i<36; i++)
        {
            randomIndex = rand() % 36;
            temp = (AllCards1->koloda[i]);
            AllCards1->koloda[i] = AllCards1->koloda[randomIndex];
            AllCards1->koloda[randomIndex] = temp;
        }
}

void InitFirstCardsForPlayers(PlayersCards *AllCards)
{
    /*for (int i=0; i<6; i++)
        {
            AllCards->player1[i] = AllCards->koloda[i];
            AllCards->player2[i] = AllCards->koloda[i+6];
        }*/
}

void GameLog()
{
    const int redHeart = 0, redDiamond = 1, blackHeart = 2, blackKrest = 3;
    system("cls");
}

void StartSettingGame(otchet *OtchetFull, PlayersCards *AllCards )
{
    int i;
    srand(time(NULL));
    OtchetFull->kozur_basa = rand() % 4;
    for (i = 0; i < 36; i++)
        AllCards->koloda[i] = i;
    shuffle(AllCards);
    for (i = 0; i < 6; i++)
        {
            AllCards->player1[i] = AllCards->koloda[36-i];
            AllCards->player2[i] = AllCards->koloda[36-i-6];
        }
    
}

void kartu1()
{
    otchet OtchetFull = {36,6,6,0};
    PlayersCards AllCards;
    StartSettingGame(&OtchetFull, &AllCards);
    

}


int main ()
{
    kartu1();
    return 0;
}