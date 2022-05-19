//Karol Chadzynski 2B
//Zad.2
/*
obliczanie pola ograniczonego dwoma
wykresami funkcji a,b - metoda trapezow

Polecam użyć programu w przedziale <-10;10> dla funkcji:
 f(x)= -((x/3)^2) +4
 g(x)= (x/3)^2 -4
 Dla ilosci trapezow tak conajmniej 5000
*/
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>

using namespace std;

clock_t start, stop;

double F(double x) //Funkcja 1
{
    return pow(x,2)+x-10;
}

double G(double x) //Funkcja 2
{
    return -pow(x,2)-15;
}

double S_WB(double x) //Suma wartosci bewzglednych
{
    return abs(F(x))+abs(G(x));
}

double WB_R_WB(double x) //Wartosc Bewzględna różnicy wartości bewzględnych
{
    return abs(abs(F(x))-(abs(G(x))));
}

bool War1(double x) //Warunek 1 (na to czy odjac do siebie wartosci funkcji czy dodac)
{
    if((F(x)>0&&G(x)>0)||(F(x)<0&&G(x)<0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool War2(double x) //Warunek 2 na to czy f(x)>g(x)
{
    if(F(x)>G(x))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool War3(double x) //Warunek 3 na to czy f(x)<g(x)
{
    if(F(x)<G(x))
    {
        return true;
    }
    else
    {
        return false;
    }
}

double oblicz(double a, double b, int n) //Obliczenie calego pola pomiedzy funkcjami
{
    double w=(b-a)/n, s=0;
    for(int i=1;i<n;i++)
    {
        if(War1(a+w*i))
        {
            s+=WB_R_WB(a+w*i);
        }
        else
        {
            s+=S_WB(a+w*i);
        }
    }
    if(War1(a))
        {
            if(War1(b))
            {
                return w/2*(WB_R_WB(a)+WB_R_WB(b)+2*s);
            }
            else
            {
                return w/2*(WB_R_WB(a)+S_WB(b)+2*s);
            }
        }
        else
        {
            if(War1(b))
            {
                return w/2*(S_WB(a)+WB_R_WB(b)+2*s);
            }
            else
            {
                return w/2*(S_WB(a)+S_WB(b)+2*s);
            }
        }
}

double FodG(double a, double b, int n) //Obliczenie Pola dla f(x)>g(x)
{
    double w=(b-a)/n, s=0;
    for(int i=1; i<n; i++)
    {
        if(War2(a+w*i))
        {
            if(War1(a+w*i))
            {
                s+=WB_R_WB(a+w*i);
            }
            else
            {
                s+=S_WB(a+w*i);
            }
        }
    }
    double a1=WB_R_WB(a),a2=S_WB(a),b1=WB_R_WB(b),b2=S_WB(b);

    if(!War2(a))
    {
        a1=0;
        a2=0;
    }
    if(!War2(b))
    {
        b1=0;
        b2=0;
    }
    if(War1(a))
        {
            if(War1(b))
            {
                return w/2*(a1+b1+2*s);
            }
            else
            {
                return w/2*(a1+b2+2*s);
            }
        }
        else
        {
            if(War1(b))
            {
                return w/2*(a2+b1+2*s);
            }
            else
            {
                return w/2*(a2+b2+2*s);
            }
        }
}

double GodF(double a, double b, int n) //Obliczenie Pola dla f(x)<g(x)
{
    double w=(b-a)/n, s=0;
    for(int i=1; i<n; i++)
    {
        if(War3(a+w*i))
        {
            if(War1(a+w*i))
            {
                s+=WB_R_WB(a+w*i);
            }
            else
            {
                s+=S_WB(a+w*i);
            }
        }
    }
    double a1=WB_R_WB(a),a2=S_WB(a),b1=WB_R_WB(b),b2=S_WB(b);

    if(!War3(a))
    {
        a1=0;
        a2=0;
    }
    if(!War3(b))
    {
        b1=0;
        b2=0;
    }
    if(War1(a))
        {
            if(War1(b))
            {
                return w/2*(a1+b1+2*s);
            }
            else
            {
                return w/2*(a1+b2+2*s);
            }
        }
        else
        {
            if(War1(b))
            {
                return w/2*(a2+b1+2*s);
            }
            else
            {
                return w/2*(a2+b2+2*s);
            }
        }
}


int main()
{
    double a,b;
    int n, w,p=true;
    while(true)
    {
        while(p)
        {
            p=false;
            cout <<"Podaj przedzial <a;b> //<4;9>: ";
            if (!(cin>>a>>b))
            {
                cerr<<"Nieprawdilowe dane";
                getchar();
                getchar();
                system("cls");
                p=true;
            }
            cout <<"Podaj liczbe trapezow n: ";
            cin>>n;
            if(n<=0||(a>=b))
            {
                cerr<<"\nNieprawidlowy przedzial lub liczba trapezow";
                getchar();
                getchar();
                system("cls");
                p=true;
            }
        }
        cout << "\n\nMENU GLOWNE\n";
        cout << "---------------------\n";
        cout << "f(x)= x^2+x-10\n";
        cout << "g(x)= -x^2-15\n";
        cout << "---------------------\n";
        cout << "1. Pole pomiedzy f(x) a g(x)\n";
        cout << "2. Pole f(x)>g(x)\n";
        cout << "3. Pole f(x)<g(x)\n";
        cout << "4. Koniec programu\n\n";
        cout << "Opcja: ";
        w=getch();
        start=clock();

        switch(w)
        {
        case '1':
            cout<<"1\nPole = "<<oblicz(a,b,n)<<"\n";
            break;

        case '2':
            cout<<"2\nPole = "<<FodG(a,b,n)<<"\n";
            break;

        case '3':
            cout<<"3\nPole = "<<GodF(a,b,n)<<"\n";
            break;

        case '4':
            {
                cout<<"4";
                exit(0);
                break;
            }

        default:
            cout<<"Nie ma takiej opcji w menu";
        }
        stop=clock();
        cout<<"\nWykonanie polecenia zajelo: "<<(double)(stop-start)/CLOCKS_PER_SEC<<" s\n\n[Kliknij Enter by kontynuowac]\n\n";
        getchar();
        getchar();
        p=true;
        system("cls");
    }
    return 0;
}
