#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <algorithm> 
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

#define ITOG "Yes"

struct for_kart
{
    int number;
    int mast;
};

struct otchet
{
    int koloda[36];
    int player1 = 6;
    int player2 = 6;
    int kozur_basa = 0;
    int KolodaKolvo = 36;
    for_kart InitCards[36];
};

struct PlayersCards
{
    vector<int> player1;
    vector<int> player2;
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

void shuffle (otchet *OtchetFull)
{
    int temp = 0;
    int randomIndex = 0;
    for (int i=0; i<36; i++)
        {
            randomIndex = rand() % 36;
            temp = (OtchetFull->koloda[i]);
            OtchetFull->koloda[i] = OtchetFull->koloda[randomIndex];
            OtchetFull->koloda[randomIndex] = temp;
        }
}

void InitFirstCardsForPlayers(otchet *OtchetFull)
{
    int i = 0;
    OtchetFull->kozur_basa = rand() % 4;
    OtchetFull->player1 = 6;
    OtchetFull->player2 = 6;
    while (i<36)
        {
            for (int j = 0; j < 4; j++)
                {
                    OtchetFull->koloda[i] = i;
                    OtchetFull->InitCards[i].number = i;
                    OtchetFull->InitCards[i].mast = j;
                    i++; 
                }
        }
}

void CheckCardOfPlayers(otchet *OtchetFull, PlayersCards *AllCards, int P1, int P2)
{
    for (int i = 0; i < OtchetFull->player1; i++)
        {
            AllCards->player1[i] = OtchetFull->koloda[OtchetFull->KolodaKolvo-i];

        }
    for (int i = 0; i < OtchetFull->player2; i++)
        {
            AllCards->player1[i] = OtchetFull->koloda[OtchetFull->KolodaKolvo-i];

        }
}

void GameLog()
{
    const int redHeart = 0, redDiamond = 1, blackHeart = 2, blackKrest = 3;
    system("cls");
}

void StartSettingGame(otchet *OtchetFull, PlayersCards *AllCards )
{
    int i;
    InitFirstCardsForPlayers(OtchetFull);
    /*for (i=0;i<36;i++)
        cout << "Second : " << OtchetFull->InitCards[i].number << endl;*/
    shuffle(OtchetFull);
    CheckCardOfPlayers(OtchetFull, AllCards, 0, 0);
    
}

void kartu1()
{
    int P1Need = 0, P2Need = 0;
    otchet OtchetFull;
    PlayersCards AllCards;
    StartSettingGame(&OtchetFull, &AllCards);
    cout <<OtchetFull.koloda[25]<< endl;
    

}


int main ()
{
    //srand(time(NULL));
    int yy = 56;
    vector<int> imm;
    for (int i =0; i<5; i++)
        {
        imm.push_back(i);
        cout << imm[i] << " pervui\n";
        }
    cout << "\nFirst Size " << imm.size();
    imm.push_back(yy);
    cout << "\nSecond Size " << imm.size();
    for ( int i = 0; i < imm.size(); i++)
        cout << "\n vtoru " << imm[i];
    //int ikk[3] = {3,2,1};
    //imm.insert(ikk);
    //for ( int i = 0; i < imm.size(); i++)
        //cout << "\n tri " <<imm[i];
    //kartu1();
    return 0;
}