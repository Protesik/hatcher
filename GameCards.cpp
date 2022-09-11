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
    int kozur_basa = 0;
    int KolodaKolvo = 36;
    for_kart InitCards[36];
    vector<int> PullOfCardsTurn;
    vector<int> WhichTurnCanUse;
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

//Результата математики карт
bool ResultOfMath(otchet *OtchetFull, int P1, int P2)
{
    if (OtchetFull->InitCards[P1].mast == OtchetFull->InitCards[P2].mast)    
        if (OtchetFull->InitCards[P1].number > OtchetFull->InitCards[P2].number ) return 1;
            else return 0;
    else if (OtchetFull->InitCards[P1].mast == OtchetFull->kozur_basa) return 1; 
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

//Если ход был в ничью, то обоим игрокам восстанавливается карты
void RefreshCards(otchet *OtchetFull, PlayersCards *AllCards, bool WhoTurn)
{
    int i;
    if (OtchetFull->KolodaKolvo > 0)
    if (WhoTurn)
        {
        for (i = AllCards->player1.size(); i < 6; i++)
            if (OtchetFull->KolodaKolvo > 0)
                {
                    AllCards->player1.push_back(OtchetFull->koloda[OtchetFull->KolodaKolvo]);
                    OtchetFull->KolodaKolvo -=1;
                }
            else break;
        
        for (i = AllCards->player2.size(); i < 6; i++)
            if (OtchetFull->KolodaKolvo > 0)
                {
                    AllCards->player2.push_back(OtchetFull->koloda[OtchetFull->KolodaKolvo]);
                    OtchetFull->KolodaKolvo -=1;
                }
            else break;
        }
    else 
        {
            for (i = AllCards->player2.size(); i < 6; i++)
            if (OtchetFull->KolodaKolvo > 0)
                {
                    AllCards->player2.push_back(OtchetFull->koloda[OtchetFull->KolodaKolvo]);
                    OtchetFull->KolodaKolvo -=1;
                }
            else break;

            for (i = AllCards->player1.size(); i < 6; i++)
            if (OtchetFull->KolodaKolvo > 0)
                {
                    AllCards->player1.push_back(OtchetFull->koloda[OtchetFull->KolodaKolvo]);
                    OtchetFull->KolodaKolvo -=1;
                }
            else break;
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
    OtchetFull->KolodaKolvo--;
    shuffle(OtchetFull);

    for (int i = 0; i < 6; i++)
    {
        AllCards->player1.push_back(OtchetFull->koloda[OtchetFull->KolodaKolvo]);
        OtchetFull->KolodaKolvo--;
        AllCards->player2.push_back(OtchetFull->koloda[OtchetFull->KolodaKolvo]);
        OtchetFull->KolodaKolvo--;
    }
}

//Может ли карта использоваться в данном ходу
string ResultOfTurn(otchet *OtchetFull, PlayersCards *AllCards, int Number, int j)
{
    if (OtchetFull->PullOfCardsTurn.empty())
        return SetColorOfText(Green, " Yes");
    else for(int i = 0; i < OtchetFull->PullOfCardsTurn.size(); i++)
            if (Number == OtchetFull->InitCards[OtchetFull->PullOfCardsTurn[i]].number) {OtchetFull->WhichTurnCanUse.push_back(j); return SetColorOfText(Green, " Yes");}
    return SetColorOfText(Red, " No");
}

//Вывод на экран текущих данных
void GameLog(otchet *OtchetFull, PlayersCards *AllCards, bool WhoseTurn)
{
    //system("cls");
    OtchetFull->WhichTurnCanUse.clear(); 
    int i;
    string kozur[4] = {"-", "--", "---", "----"};
    cout << SetColorOfText( LightGreen, "Your size of cards: = ") << AllCards->player1.size();
    cout << SetColorOfText( Red, "\tSize of enemy cards: = ") << AllCards->player2.size();
    cout << SetColorOfText( LightCyan, "\tSize of Colodu: = ") << OtchetFull->KolodaKolvo << SetColorOfText( Yellow, "\tKozur: = ") << kozur[OtchetFull->kozur_basa] << endl;
    ColorConsolWhite;
    for (i = 0; i<AllCards->player1.size(); i++)
        {
            cout << i+1 << " card - " << CheckNumber(OtchetFull->InitCards[AllCards->player1[i]].number) << " " << SetColorOfText(CheckKozur(OtchetFull->InitCards[AllCards->player1[i]].mast, OtchetFull->kozur_basa), kozur[OtchetFull->InitCards[AllCards->player1[i]].mast]) << " " << ResultOfTurn(OtchetFull, AllCards, OtchetFull->InitCards[AllCards->player1[i]].number, i) << endl;
            //SetColorOfText( CheckKozur(OtchetFull->InitCards[AllCards->player1[i]].mast, OtchetFull->kozur_basa), kozur[OtchetFull->InitCards[AllCards->player1[i]].mast])
            ColorConsolWhite;
        }
    if (WhoseTurn != 0)
        cout << SetColorOfText(Green, "\nYour turn. Chouse your card... ");
    else cout << SetColorOfText(Red, "\nNow is turn the enemy. Use your cards for counter the enemy card: ");
    ColorConsolWhite;
    cout << endl;
    for (i = 0; i<AllCards->player2.size(); i++)
        {
            cout << i+1 << " card - " << CheckNumber(OtchetFull->InitCards[AllCards->player2[i]].number) << " " << SetColorOfText(CheckKozur(OtchetFull->InitCards[AllCards->player2[i]].mast, OtchetFull->kozur_basa), kozur[OtchetFull->InitCards[AllCards->player2[i]].mast]) << " " << endl;
            //SetColorOfText( CheckKozur(OtchetFull->InitCards[AllCards->player1[i]].mast, OtchetFull->kozur_basa), kozur[OtchetFull->InitCards[AllCards->player1[i]].mast])
            ColorConsolWhite;
        }
    ColorConsolWhite;
}

//Смотр чем отбивается противник
int EnemyTurn(vector<int> &result, otchet *OtchetFull, PlayersCards *AllCards)
{
    int i, min;
    bool isOneNoKozur;
    for ( i = 0; i < result.size(); i++)
        if (OtchetFull->InitCards[AllCards->player2[result[i]]].mast != OtchetFull->kozur_basa)
            {
                min = result[i];
                isOneNoKozur = 1;
                break;
            }
    if (isOneNoKozur)
        {
            i++;
            while (i < result.size())
            {
                if (OtchetFull->InitCards[AllCards->player2[result[i]]].mast != OtchetFull->kozur_basa)
                    if (OtchetFull->InitCards[AllCards->player2[result[i]]].number < OtchetFull->InitCards[AllCards->player2[result[min]]].number)
                        min = result[i];
                i++;
            }
            return (min);
        }       
     else 
        {
            for ( i = 0; i < result.size(); i++)
                if (OtchetFull->InitCards[AllCards->player2[result[i]]].mast == OtchetFull->kozur_basa)
                    {
                        min = result[i];
                        break;
                    }
            for ( i++ ; i < result.size(); i++)
                if (OtchetFull->InitCards[AllCards->player2[result[i]]].mast == OtchetFull->kozur_basa) 
                    if (OtchetFull->InitCards[AllCards->player2[result[i]]].number < OtchetFull->InitCards[AllCards->player2[result[min]]].number)
                            min = result[i];
                        
            return (min);
        } 
}

//Игрок пасует
void PlayerPass(otchet *OtchetFull, PlayersCards *AllCards, bool WhoseTurn)
{
    int i;
    if (WhoseTurn)
    {
        for (i = 0; i < OtchetFull->PullOfCardsTurn.size(); i++)
            AllCards->player2.push_back(OtchetFull->PullOfCardsTurn[i]);
        
        for (i = AllCards->player1.size(); i < 6; i++)
            if (OtchetFull->KolodaKolvo > 0)
                {
                    AllCards->player1.push_back(OtchetFull->koloda[OtchetFull->KolodaKolvo]);
                    OtchetFull->KolodaKolvo--;
                }
            else break;
    }
    else {
        for (i = 0; i < OtchetFull->PullOfCardsTurn.size(); i++)
            AllCards->player1.push_back(OtchetFull->PullOfCardsTurn[i]);

        for (i = AllCards->player2.size(); i < 6; i++)
            if (OtchetFull->KolodaKolvo > 0)
                {
                    AllCards->player2.push_back(OtchetFull->koloda[OtchetFull->KolodaKolvo]);
                    OtchetFull->KolodaKolvo--;
                }
            else break;
    }
}

//Процесс хода
bool Turn(otchet *OtchetFull, PlayersCards *AllCards, int Choice, bool WhoseTurn)
{
    int i;
    vector<int> NumberOfcards;   
    if (WhoseTurn)
        {
            for (i = 0; i<AllCards->player2.size(); i++)
                if (ResultOfMath(OtchetFull, AllCards->player2[i], AllCards->player1[Choice])) NumberOfcards.push_back(i);
            OtchetFull->PullOfCardsTurn.push_back(AllCards->player1[Choice]); 
            AllCards->player1.erase(AllCards->player1.begin() + Choice); 
            if (NumberOfcards.empty()) return 0;
                else if(NumberOfcards.size() == 1) 
                    {                         
                        OtchetFull->PullOfCardsTurn.push_back(AllCards->player2[NumberOfcards[0]]);
                        AllCards->player2.erase(AllCards->player2.begin() + NumberOfcards[0]);
                        return 1;
                    }
                    else 
                        {
                            int key = EnemyTurn(NumberOfcards, OtchetFull, AllCards);
                            OtchetFull->PullOfCardsTurn.push_back(AllCards->player2[key]);
                            AllCards->player2.erase(AllCards->player2.begin() + key);
                            return 1;
                        }
        }
    else 
        {
            for (i = 0; i<AllCards->player1.size(); i++)
                {
                if (ResultOfMath(OtchetFull, AllCards->player2[Choice], AllCards->player1[i])) exit(0);
                }
        }
    
    return (WhoseTurn);
}

//Может ли игрок ходить
bool CanTurn(otchet *OtchetFull, PlayersCards *AllCards, int Turn)
{
    for (int i = 0; i < OtchetFull->WhichTurnCanUse.size(); i++)
        if (Turn == OtchetFull->WhichTurnCanUse[i]) return 1;
    return 0;
}

//Голова программы
void kartu1()
{
    int Choice = 0;
    int EndOfTurn1;
    bool EndofGame = 1, WhoseTurn = 1, WhoDef = 0, EnemyCanTurn;
    otchet OtchetFull;
    PlayersCards AllCards;
    InitFirstCardsForPlayers(&OtchetFull, &AllCards);
    while (EndofGame == 1)
        {
           EndOfTurn1 = 1; 
            if (WhoseTurn)
                do
                    {
                        GameLog(&OtchetFull, &AllCards, WhoseTurn);
                        cin >> Choice;
                        if (Choice > 0 && Choice <= AllCards.player1.size()) EnemyCanTurn = Turn(&OtchetFull, &AllCards, Choice - 1, WhoseTurn);
                            else 
                                {
                                    Choice = 0;
                                    continue;
                                }
                        if (EnemyCanTurn) 
                        {
                            do
                            {
                                GameLog(&OtchetFull, &AllCards, WhoseTurn);
                                if (OtchetFull.WhichTurnCanUse.size() > 0)
                                    {
                                    cin >> Choice;
                                    if (Choice > 0 && Choice <= AllCards.player1.size() && CanTurn(&OtchetFull, &AllCards, Choice-1)) EnemyCanTurn = Turn(&OtchetFull, &AllCards, Choice - 1, WhoseTurn);
                                        else 
                                            {
                                                Choice = 0; 
                                                continue;
                                            } 
                                    }
                                else 
                                    {
                                        RefreshCards(&OtchetFull, &AllCards, WhoseTurn);
                                        WhoseTurn = 0;
                                        EndOfTurn1 = 0;
                                    }
                    
                            } while (EnemyCanTurn);
                        }
                        if (!EnemyCanTurn) 
                            {
                                do
                                {
                                    GameLog(&OtchetFull, &AllCards, WhoseTurn);
                                    if (OtchetFull.WhichTurnCanUse.size() > 0)
                                        {
                                            cin >> Choice;
                                            if (Choice > 0 && Choice <= AllCards.player1.size() && CanTurn(&OtchetFull, &AllCards, Choice-1)) 
                                                {
                                                    OtchetFull.PullOfCardsTurn.push_back(AllCards.player1[Choice-1]);  
                                                    AllCards.player1.erase(AllCards.player1.begin() + (Choice-1));
                                                }
                                            else 
                                            {
                                                Choice = 0; 
                                                continue;
                                            } 
                                        }
                                    else 
                                        {
                                        PlayerPass(&OtchetFull, &AllCards, WhoseTurn);
                                        EndOfTurn1 = 0;
                                        }
                                } while (EndOfTurn1);
                            }
                        OtchetFull.PullOfCardsTurn.clear();
                    } while (EndOfTurn1);
            else 
            {
                GameLog(&OtchetFull, &AllCards, WhoseTurn);
                exit(0);
            }
        }
}

//Главная функция всей программы
int main ()
{
    srand(time(NULL));
    //system("cls");
    kartu1();
    return 0;
}