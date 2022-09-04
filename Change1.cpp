#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

#define ITOG "Yes"
// остаток от деления
void visu1(int b)
{
    int a =1;
    cout << "Jacc =" << a+b <<endl  //6
    << "Jacc1 =" << 7 %8 <<endl  //7
    << "Jacc2 =" << 2 %5 <<endl  //2
    << "Jacc3 =" << 3 %4 <<endl;  //3
    
}

// комбинировани * / + - %
// операция на сложение на ++PARAMETR
string hac1(int a, int b, int h)
{
    string hacc;
    int hjj = 55, uj = 3;
    ++uj;
    hjj -= a;
    b += hjj;
    a *= h;
    cout << hjj << endl << uj << endl << a << endl << h << endl;
    if (a == 15) hacc = "Yes";
    else hacc = "No";
    return hacc;
}

//Префиксная и постфиксная формы .
//Если впереди ++, то сначала он выполниться, а есле после, то после всех.
//С -- тоже самое будет. Это назывется Декремент.
string hac2(int a)
{
    string result;
    cout << "Otvet = " << a <<endl
    << "Otvet = " << ++a <<endl
    << "Otvet = " << a <<endl
    << "Otvet = " << a++ <<endl
    << "Otvet = " << a <<endl;
    if (a == 15) result = "Yes";
    else result = "No";
    return (result);

}

//IF примеры
string oikk()
{
    int numb;
    cout << "Vvedite chiclo ";
    cin >> numb;
    cout << "numb < 10 = " << (numb < 10) << endl
    << "numb > 10 = " << (numb > 10) << endl 
    << "numb = 10 = " << (numb == 10) << endl
    << "numb != 10 = " << (numb != 10) << endl //Не равно
    << "numb >= 10 = " << (numb >= 10) << endl // Больше или равно
    << "numb <= 10 = " << (numb <= 10) << endl; // Меньше или равно
    if (numb == 10) return ITOG;
    else return "No";  
}


//Сложный if
string if_hard()
{
    char dir = 'a';
    int x = 10, y = 10;
    cout << "Enter to exit" << endl;
    while (dir != '\r')
        {
            cout <<"\n Your coordinats: " << x << ", " << y << endl;
            dir = getche();
            if (dir == 's') y--;
                else if (dir == 'w') y++;
                    else if (dir == 'd') x++;
                        else if (dir == 'a') x--;
        }
    return ITOG;    
}

//Цикл for
string cukl1(int b)
{
    unsigned int a;
    int hhh = 10;
    for (a = 0; a < b; a++, --hhh)
    cout << "b = " << hhh << endl << "Next" << endl;
    for (a = 0; a < b+8; a++)
        {
            cout << "Nugget #" << a << endl;
            if (a>=b+8) return "No";
        }
    return ITOG;
}

//Цикл While
string cukl2(int gg)
{
    int a = 1;
    while (gg != 0)
        {
            cout << gg << endl;
            gg -= a;
        }
    return ITOG;
}

//Цикл While do
string cukl3(int gg)
{
    int a = 1;
    do
        {
            cout << gg << endl;
            gg -= a;
        }
    while (gg != 0);
    return ITOG;
}

//Switch base
string switch1()
{
    int speed;
    cout << "Vvedite speed: ";
    cin >> speed;
    switch (speed)
        {
            case 33:
                cout << "Vubor 1\n";
                break;
            case 45:
                cout << "Vubor 2\n";
                break;
            case 76:
                cout << "Vubor 3\n";
                break;
        }
    return ITOG;
}

string switch2()
{
    char dir = 'a';
    int x = 10, y = 10;
    while (dir != '\r')
        {
            cout << "Coordinats: " << x << ", " << y << endl
            << "Napravlenue: \n";
            dir = getche();
            switch(dir)
                {
                    case 'a': x--; break;
                    case 'd': x++; break;
                    case 's': y--; break;
                    case 'w': y++; break;
                    case '\r': cout << "Exit...\n"; break;
                    default: cout << "Vubere napravlenue\n";
                }
        }
    return ITOG;
}

//Getche
string getche11()
{
    int a = 0, b=1;
    char ch;
    cout << "Vvedite stroky: ";
    while ((ch = getche()) != '\r')
        {
            if ( ch == ' ' )
            b++;
            else
            a++;
        }
    cout <<"\nSlov: " << b << endl
    << " Bukv: " << a << endl;
    return ITOG;
}

//Условная операция (j%8) ? a : b
string if_hard2()
{
    char ch;
    for (int j = 0; j<80; j++)
        {
            cout << ((j%8) ? ' ' : 'x');
        }
    cout << endl;
    return ITOG;
}

//switch + if
string switch3()
{
    char dir = 'a';
    int x = 10, y = 10;
    while (dir != '\r')
        {
            cout << "Coordinats: " << x << ", " << y << endl
            << "Napravlenue: ";
            dir = getche();
            switch (dir)
                {
                    case 'a': x--; cout << endl; break;
                    case 'd': x++; cout << endl; break;
                    case 's': y--; cout << endl; break;
                    case 'w': y++; cout << endl; break;
                    case 'i': x = 10; y = 10; cout << "\nZanovo\n"; break;
                    case '\r': cout << "Exit...\n"; break;
                    default: cout << "\nVubere napravlenue\n";
                }
            if (x==7 && y==12)
                {
                    cout << "Pozdravlau\n";
                    exit(0);
                }
            if (x<5 || x>12)
                {
                    cout << "Nazad\n";
                    if (x<5) ++x;
                        else --x;
                }    
        }
    return ITOG;
}

//Картинка
string break1()
{
    const unsigned char WHITE = 219;
    const unsigned char GRAY = 176;
    unsigned char ch;
    for (int count = 0; count <80*25-1; count++)
        {
            ch = WHITE;
            for(int j=2; j<count; j++)
                if (count %j == 0)
                    {
                        ch = GRAY;
                        break;
                    }
            cout << ch;
        }
    getch();
    return ITOG;
}

//continue
string continue1()
{
    long dig1,dig2;
    char ch;
    do
    {
        cout << "\nVvevide 1 chiclo: ";
        cin >> dig1; 
        cout << "\nVvedite 2 chiclo ";
        cin >> dig2;
        if (dig2 == 0)
            {
            system("cls");
            cout << "\nNa 0 delit nelza. Zanovo\n";
            continue;
            }
        cout << "Celoe chiclo: " << dig1 / dig2
        << "\nOstatok: " << dig1 % dig2;
        cout << "\nZanovo?(y/n)\n";
        cin >> ch;
        if (ch == 'y') {system("cls"); continue;}
    } while (ch != 'n');
    return ITOG;
}

int main()
{
    int yi = 10, ui = 15;
    string result = continue1();
    if (result == "Yes") cout << "Da eto tak" << endl;
    else cout << "Ne tak" << endl;
    return 0;
}