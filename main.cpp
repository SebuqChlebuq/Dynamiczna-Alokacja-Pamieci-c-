#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int *p= NULL;
int n = 0;
fstream plik;
char sciezka[255] = "Tablica.txt";

int ZapiszDoPliku()
{
    plik.open(sciezka, ios::out | ios::trunc);
    if(!plik.is_open()) return -1;

    cout << " Zapisujesz do pliku" << endl;
    for(int i=0; i<n; i++)
        plik << p[i] << endl;

    plik.close();
    return 0;
}

int OdczytZPliku()
{
    plik.open(sciezka, ios::in);
    if(!plik.is_open()) return -1;

    cout << " Wczytujesz z pliku do tablicy" << endl;

    n = -1;
    string line;
    while(!plik.eof())
    {
        getline(plik, line);
        n++;
    }
    cout << "w pliku jest " << n <<  " liczb";
    plik.close();

    plik.open(sciezka, ios::in);
    if(!plik.is_open()) return -1;

    int i = 0;
    p = new int[n];
    while(!plik.eof())
    {
        if(i == n) break;
        getline(plik, line);
        p[i] = atoi(line.c_str());
        i++;
    }

    plik.close();
    return 0;
}

int DodajElement()
{
    cout << " dodajesz element" << endl;
    cout << " podaj wartosc: ";
    int x;
    cin>>x;

    //p = new int[n];
    n++;
    int *p2 = NULL;
    p2 = new int[n];
    if(p != NULL)
    {
        for(int i=0;i<n-1;i++)
        {
            p2[i] = p[i];
        }
    }
    p2[n-1] = x;
    delete []p;
    p = p2;

    return 0;
}

int WstawElement()
{
    cout << " wstawiasz element" << endl;
    cout << " podaj index  : ";
    int ix;
    cin>>ix;
    cout << " podaj wartosc: ";
    int x;
    cin>>x;

    n++;

    int *p2 = NULL;
    p2 = new int[n];
    if(p != NULL)
    {
        for(int i=0;i<ix;i++)
        {
            p2[i] = p[i];
        }
        for(int i = ix; i<n-1;i++)
        {
            p2[i+1] = p[i];
        }
    }
    p2[ix] = x;
    delete []p;
    p = p2;

    return 0;
}

int UsunElement()
{
    cout << " usuwasz element" << endl;
    cout << " podaj index  : ";
    int ix;
    cin>>ix;

    n--;

    int *p2 = NULL;
    p2 = new int[n];
    if(p != NULL)
    {
        for(int i=0;i<ix;i++)
        {
            p2[i] = p[i];
        }
        for(int i = ix+1; i<=n;i++)
        {
            p2[i-1] = p[i];
        }
    }
    delete []p;
    p = p2;


    return 0;
}

int WyswietlTablice()
{
    cout << " wyswietlasz tablice" << endl;
    for(int i=0; i<n; i++)
        cout << p[i] << " ";

    return 0;
}

int Menu()
{
    for(;;)
    {
        cout << endl;
        cout << "________________________" << endl;
        cout << "         M E N U        " << endl;
        cout << "________________________" << endl;
        cout << "1:|  Dodaj element," << endl;
        cout << "2:|  Wstaw element," << endl;
        cout << "3:|  Usun element, " << endl;
        cout << "4:|  Wyswietl tablice," << endl;
        cout << "5:|  Odczyt z pliku," << endl;
        cout << "6:|  Zapis do pliku," << endl;
        cout << "7:|  Wyjscie" << endl;
        cout << "Wybierz:  ";

        int wybor;
        cin >> wybor;
        if(wybor < 1 || wybor > 7) cout << "Podano niepoprawna opcje" << endl;
        else if(wybor == 1) DodajElement();
        else if(wybor == 2) WstawElement();
        else if(wybor == 3) UsunElement();
        else if(wybor == 4) WyswietlTablice();
        else if(wybor == 5) OdczytZPliku();
        else if(wybor == 6) ZapiszDoPliku();
        else if(wybor == 7) return 0;
    }
}

int main()
{
    Menu();
    return 0;
}
