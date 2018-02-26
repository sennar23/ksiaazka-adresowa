#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct Osoba
{
   int id;
   string imie, nazwisko, numerTelefonu, email, adres;
};
int dodajOsobe();
 dodajOsobe(Osoba osoby[], int iloscOsob)
{
    string imie, nazwisko, numerTelefonu, email, adres;
    cout << "Podaj imie: "; cin >> imie;
    cout << "Podaj nazwisko: "; cin >> nazwisko;
    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin,numerTelefonu);
    cout << "Podaj email: "; cin >> email;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin,adres);

    osoby[iloscOsob].id = iloscOsob + 1;
    osoby[iloscOsob].imie = imie;
    osoby[iloscOsob].nazwisko = nazwisko;
    osoby[iloscOsob].numerTelefonu = numerTelefonu;
    osoby[iloscOsob].email = email;
    osoby[iloscOsob].adres = adres;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << osoby[iloscOsob].id <<"|";
        plik << osoby[iloscOsob].imie <<"|";
        plik << osoby[iloscOsob].nazwisko << "|";
        plik << osoby[iloscOsob].numerTelefonu << "|";
        plik << osoby[iloscOsob].email << "|";
        plik << osoby[iloscOsob].adres << endl;
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }
    cout << endl << "Osoba zostala dodana" << endl; system("pause");
    return iloscOsob + 1;
}

int wczytajOsobyZPliku(Osoba osoby[])
{
    string linia; // tworze zmienna do ktorej bede zapisywal odczytane linie z pliku tekstowego
    int nr_linii = 1;
    int iloscOsob = 0;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::in);  // aby otworzyc plik do odczytu
    if (plik.good() == true)
    {
        // odczytuje linie po kolei. Linie w pliku tekstowym w przeciwienstwie do tablic sa numerowane od 1
        // funkcja getline odczytuje ze zmiennej plikowej plik i zapisuje linie jako stringa do zmiennej linia.
        // funkcja zwraca true dopoki sa linie do odczytania. Zwroci false, gdy plik sie skonczy
        while (getline(plik,linia))
        {
            switch (nr_linii)
            {
            case 1:
                osoby[iloscOsob].id = atoi(linia.c_str());
                break;
            case 2:
                osoby[iloscOsob].imie = linia;
                break;
            case 3:
                osoby[iloscOsob].nazwisko = linia;
                break;
            case 4:
                osoby[iloscOsob].numerTelefonu = linia;
                break;
            case 5:
                osoby[iloscOsob].email = linia;
                break;
            case 6:
                osoby[iloscOsob].adres = linia;
                break;
            }
            if (nr_linii >= 6)
            {
                nr_linii = 1;
                iloscOsob++;
            }
            else
            {
                nr_linii++;
            }
        }
        plik.close();
    }
    return iloscOsob;
}

void wyswietlWszystkieOsoby(Osoba osoby[], int iloscOsob)
{
    for (int i = 0; i < iloscOsob; i++)
    {
        cout << endl;
        cout << osoby[i].id <<"|" ;
        cout << osoby[i].imie << "|" << osoby[i].nazwisko << "|" ;
        cout << osoby[i].numerTelefonu << "|" ;
        cout << osoby[i].email << "|" ;
        cout << osoby[i].adres << "|" ;
        cout << endl;
        }

    system("pause");
}

void wyszukajPoImieniu(Osoba osoby[], int iloscOsob)
{
    string imie;
    cout << "Poda imie osoby jaka mamy wyszukac: "; cin >> imie;
    for (int i = 0; i < iloscOsob; i++)
    {
        if (osoby[i].imie == imie)
        {
        cout << endl;
        cout << osoby[i].id <<"|" ;
        cout << osoby[i].imie << "|" << osoby[i].nazwisko << "|" ;
        cout << osoby[i].numerTelefonu << "|" ;
        cout << osoby[i].email << "|" ;
        cout << osoby[i].adres << "|" ;
        cout << endl;
        }
        }

    system("pause");
}

void wyszukajPoNazwisku(Osoba osoby[], int iloscOsob)
{
    string nazwisko;
    cout << "Poda nazwisko osoby jaka mamy wyszukac: "; cin >> nazwisko;
    for (int i = 0; i < iloscOsob; i++)
    {
        if (osoby[i].nazwisko == nazwisko)
        {
        cout << endl;
        cout << osoby[i].id <<"|" ;
        cout << osoby[i].imie << "|" << osoby[i].nazwisko << "|" ;
        cout << osoby[i].numerTelefonu << "|" ;
        cout << osoby[i].email << "|" ;
        cout << osoby[i].adres << "|" ;
        cout << endl;
        }
    }
    system("pause");
}


int main()
{
    vector <int> osoby;
    int iloscOsob = 0;
    char wybor;

    iloscOsob = osoby.size();

    while (true)
    {
        system("cls");
        cout << "1. Dodaj osobe" << endl;
        cout << "2. Wyszukaj po imieniu" << endl;
        cout << "3. Wyszukaj po nazwisku" << endl;
        cout << "4. Wyswietl wszystkie osoby" << endl;
        cout << "9. Zakoncz program" << endl; cin >> wybor;

        if (wybor == '1')
        {
            iloscOsob = dodajOsobe(osoby, iloscOsob);
        }
        else if (wybor == '2')
        {

            wyszukajPoImieniu(osoby, iloscOsob);
        }
        else if (wybor == '3')
        {

            wyszukajPoNazwisku(osoby, iloscOsob);
        }
        else if (wybor == '4')
        {
            wyswietlWszystkieOsoby(osoby, iloscOsob);
        }
        else if (wybor == '9')
        {
            exit(0);
        }
    }
    return 0;
}
