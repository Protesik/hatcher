#include <iostream>
#include <iomanip>
#include <conio.h>
#include<windows.h>
using namespace std;

#define ITOG "Yes"

struct for_kart
{
    int number;
    int mast;
    int kozur;
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

struct part
{
    int model;
    int partnumber;
    float cost;
};

struct direc
{
    int feet;
    float inches;
};

struct hhb
{
    direc heh;
    part hn;
};
//struct test1
void struct11()
{
    part Test;
    Test.cost = 22.15F;
    Test.partnumber = 15;
    Test.model = 1;
    cout << "Model: " << Test.model
    << "\nNumber: " << Test.partnumber
    << "\nCost: " << Test.cost;
    part Test2 = {1,2,24.5F};
    cout << "\nModel: " << Test2.model
    << "\nNumber: " << Test2.partnumber
    << "\nCost: " << Test2.cost;
}

void struct12()
{
    direc d1,d3, d2 = {11, 6.25F};
    cout << "\nVvedite funt: "; cin >> d1.feet;
    cout << "\nVvedite dum: "; cin >> d1.inches;
    d3.inches = d1.inches + d1.inches;
    d3.feet = 0;
    if (d3.inches >= 12.0)
        {
            d3.inches -= 12.0;
            d3.feet++;
        }
    d3.feet +=d1.feet + d2.feet;
    cout << d1.feet <<"\' - " << d1.inches << "\' + ";
    cout << d2.feet <<"\' - " << d2.inches << "\' + ";
    cout << d3.feet <<"\' - " << d3.inches << "\' + ";
    hhb yik = {{2, 6.44F}, {55,21, 7.8F}};
}

int main ()
{
    struct12();
    return 0;
    /*while (ch != '\r')
    {
        ch = getche();
        if (ch == 'u') exit(0);
        cout << "\b \b";
    }*/
}