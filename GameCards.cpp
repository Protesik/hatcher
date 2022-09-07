#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <algorithm> 
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

#define ColorConsolWhite SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White)

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

int CheckKozur(int y, int m);
string CheckNumber(int num);
bool Turn(otchet *OtchetFull, PlayersCards *AllCards, int Choice, bool WhoseTurn);

//Выбор цвета текста
string SetColorOfText(int color, string text)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
   return text;
}

//Функция запроса о старте игры
bool kartStart()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Blue);
    char cmdLog = 'a'; 
    while (cmdLog != '\r') 
        {
            cout << "Start the game? (y/n) "; 
            cmdLog = getche();
            if (cmdLog == 'y') return (1);
                else if (cmdLog == 'n') {ColorConsolWhite; exit(0);}
                    else { system ("cls"); continue;}
        }
    return (0);
}

//Перетасовка карт
void shuffle (otchet *OtchetFull)
{
    int temp = 0;
    int randomIndex = 0;
    for (int i=0; i < OtchetFull->KolodaKolvo; i++)
        {
            randomIndex = rand() % OtchetFull->KolodaKolvo;
            temp = (OtchetFull->koloda[i]);
            OtchetFull->koloda[i] = OtchetFull->koloda[randomIndex];
            OtchetFull->koloda[randomIndex] = temp;
        }
}


//Присваивания карт игрокам
void FirstCardOfPlayers(otchet *OtchetFull, PlayersCards *AllCards)
{  
    int Kolvo = 35; 
    for (int i = 0; i < OtchetFull->player1; i++)
        AllCards->player1.push_back(OtchetFull->koloda[Kolvo - i]);
    Kolvo -= 6;
    for (int j = 0; j < OtchetFull->player2; j++)
        AllCards->player2.push_back(OtchetFull->koloda[Kolvo - j]);
    OtchetFull->KolodaKolvo = Kolvo - 5;
}

//Результата математики карт
bool ResultOfMath(otchet *OtchetFull, int P1, int P2)
{
    if (OtchetFull->InitCards[P1].mast == OtchetFull->InitCards[P2].mast)    
        if (OtchetFull->InitCards[P1].number > OtchetFull->InitCards[P2].number ) return 1;
        else return 0;
    else if (OtchetFull->InitCards[P1].mast == OtchetFull->kozur_basa && OtchetFull->InitCards[P2].mast != OtchetFull->kozur_basa) return 1;
        else return 0;
}

//Проверка на козырь
int CheckKozur(int y, int m)
{
    if (y == m) return Yellow;
    return White;
}

//Смотр значения карта для вывода на экран
string CheckNumber(int num)
{
    switch (num)
    {
    case 11:
        return ("Valet");
        break;
    case 12:
        return ("Dama");
        break;
    case 13:
        return ("King");
        break;
    case 14:
        return ("Tuz");
        break;
    default:
        return (to_string(num));
        break;
    }
}

//Инициация первичных карт
void InitFirstCardsForPlayers(otchet *OtchetFull, PlayersCards *AllCards)
{
    int i = 0, m = 6;
    OtchetFull->kozur_basa = rand() % 4;
    while (i < OtchetFull->KolodaKolvo)
        {
            for (int j = 0; j < 4; j++)
                {
                    OtchetFull->koloda[i] = i;
                    OtchetFull->InitCards[i].number = m;
                    OtchetFull->InitCards[i].mast = j;
                    i++; 
                }
            m++;
        }

    shuffle(OtchetFull);

    int Kolvo = 35; 
    for (int i = 0; i < OtchetFull->player1; i++)
        AllCards->player1.push_back(OtchetFull->koloda[Kolvo - i]);
    Kolvo -= 6;
    for (int j = 0; j < OtchetFull->player2; j++)
        AllCards->player2.push_back(OtchetFull->koloda[Kolvo - j]);
    OtchetFull->KolodaKolvo = Kolvo - 5;
}

//Вывод на экран текущих данных
void GameLog(otchet *OtchetFull, PlayersCards *AllCards, bool WhoseTurn)
{
    //const int redHeart = 0, redDiamond = 1, blackHeart = 2, blackKrest = 3;
    //system("cls");
    int i;
    string kozur[4] = {"RedHeart", "RedDiamond", "BlackHeart", "BlackKrest"};
    cout << SetColorOfText( LightGreen, "Your size of cards: = ") << OtchetFull->player1;
    cout << SetColorOfText( Red, "\tSize of enemy cards: = ") << OtchetFull->player2;
    cout << SetColorOfText( LightCyan, "\tSize of Colodu: = ") << OtchetFull->KolodaKolvo << SetColorOfText( Yellow, "\tKozur: = ") << kozur[OtchetFull->kozur_basa] << endl;
    ColorConsolWhite;
    for (i = 0; i<AllCards->player1.size(); i++)
        {
            cout << i+1 << " card - " << CheckNumber(OtchetFull->InitCards[AllCards->player1[i]].number) << " " << SetColorOfText( CheckKozur(OtchetFull->InitCards[AllCards->player1[i]].mast, OtchetFull->kozur_basa), kozur[OtchetFull->InitCards[AllCards->player1[i]].mast]) << endl;
            ColorConsolWhite;
        }
    if (WhoseTurn != 0)
        cout << SetColorOfText(Green, "\nYour turn. Chouse your card... ");
    else cout << SetColorOfText(Red, "\nNow is turn the enemy. Use your cards for counter the enemy card: ");
    ColorConsolWhite;
}

int EnemyTurn(vector<int> &result, otchet *OtchetFull, PlayersCards *AllCards)
{
    int min = result[0];
    for (int i = 1; i < result.size()-1; i++)
        if (min > OtchetFull->InitCards[result[i]].number) exit(0);
    return (1);
}


void PlayerPass(bool PlayerWhoPassed)
{

}

void ResultOfTurn(otchet *OtchetFull, PlayersCards *AllCards, vector<int> &result)
{
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
}

bool Turn(otchet *OtchetFull, PlayersCards *AllCards, int Choice, bool WhoseTurn)
{
    int i;
    vector<int> result;
    if (WhoseTurn)
        {
            for (i = 0; i<AllCards->player2.size(); i++)
                if (ResultOfMath(OtchetFull, AllCards->player1[Choice], AllCards->player2[i])) result.push_back(AllCards->player2[i]);
            if (result.empty()) PlayerPass(0);
                else if(result.size() == 1) ResultOfTurn(OtchetFull, AllCards, result);
                    else EnemyTurn(result, OtchetFull, AllCards);
        }
    else 
        {
            for (i = 0; i<AllCards->player1.size(); i++)
                {
                if (ResultOfMath(OtchetFull, AllCards->player2[Choice], AllCards->player1[i])) result.push_back(i);
                }
        }
    
    return 1;
}

//Голова программы
void kartu1()
{
    int Choice = 0;
    char YourChoose;
    bool EndofGame = 1, WhoseTurn = 1, WhoDef = 0;
    otchet OtchetFull;
    PlayersCards AllCards;
    InitFirstCardsForPlayers(&OtchetFull, &AllCards);
    GameLog(&OtchetFull, &AllCards, WhoseTurn); 
    while (!EndofGame)
        {
            do
                {
                    cin >> Choice;
                    if (Choice > 0 && Choice <= AllCards.player1.size()) break;
                        else {Choice = 0; cout << "\b \b";}
                } 
            while (!Choice);
        
        }
    
}

void jjm(otchet *Ujj)
{

}

//Главная функция всей программы
int main ()
{
    srand(time(NULL));
    system("cls");
    kartu1();
    return 0;
}