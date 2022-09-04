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

string getche11()
{
    int a = 0, b=1;
    char ch = 'y';
    cout << "Vvedite stroky: ";
    while (ch != '\r')
        {
            ch = getche();
            if ( ch == ' ' )
            b++;
            else
            a++;
        }
    cout <<"\nSlov: " << b << endl
    << " Bukv: " << a-1 << endl;
    return ITOG;
}

int main()
{
    int yi = 10;
    string result = getche11();
    if (result == "Yes") cout << "Da eto tak" << endl;
    else cout << "Ne tak" << endl;
    return 0;
}