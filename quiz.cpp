#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <locale.h> 

using namespace std;

string imie;

class Pytanie
{
    private:
        string q;
        string odpowiedzi[4];
        string odp;

    public:
        static int punkty;

    Pytanie(string pyt,string opcja[4],string poprawna)
    {
        static string odpow;
        q = pyt;
        odp = poprawna;
        for(int i = 0;i < 4; i++)
        {
            odpowiedzi[i] = opcja[i];
        }

        cout << q << endl;

        cout << "a)" << odpowiedzi[0] << endl;
        cout << "b)" << odpowiedzi[1] << endl;
        cout << "c)" << odpowiedzi[2] << endl;
        cout << "d)" << odpowiedzi[3] << endl;

        cin >> odpow;
        if(odpow == odp)
        {
            punkty++;
            cout << "Dobra odpowiedź";
        }
        else
        {
            cout << "Zła odpowiedź";
        }
        Sleep(3000);
        system("cls");
    }
};
int Pytanie::punkty = 0;

bool endsWith(
            const string str,
            const string subStr) {
            size_t strLen = str.length();
            size_t subStrLen = subStr.length();

            return  strLen >= subStrLen &&
                str.compare(strLen - subStrLen, subStrLen, subStr) == 0;
}

int main()
{
    setlocale(LC_ALL, "Polish");
   
    cout << "Podaj imie:";
    cin >> imie;
    string pytania[5][4] = {{"1989","1970","2000","2001"},{"Street fighter II","Super Mario Bros","Sonic the Hedgehog 2","The legend of Zelda"},{"sega cd","sega 16x","sega 64x","sega powerhouse"},{"Blast Processing","antialiasing","fidelityFX","DLSS"},{"Tak","Nie","Nwm",":)"}};
    
    Pytanie pyt1("W jakim roku konosla sega mega drive/genesis miała premiere w USA?",pytania[0],"a");
    Pytanie pyt2("Jaka byla najlepiej sprzedająca sie gra na sega mega drive?",pytania[1],"c");
    Pytanie pyt3("Jaki moduł wyszedł do segi genesis?",pytania[2],"a");
    Pytanie pyt4("Co takiego posiadała konsola segi, czcego brakowało konsoli nintendo?",pytania[3],"a");
    Pytanie pyt5("Czy kartridże do Segi Mega Drive(japońskie wydanie) pasowały do segi genesis(Amerykańskie wydanie)?",pytania[4],"b");


    if(endsWith(imie,"a")){
        cout<<"Gratulacje " << imie <<",zdobyłaś "<<Pytanie::punkty<<"/5 punktów";
    }
    else{
        cout<<"Gratulacje " << imie <<",zdobyłeś "<<Pytanie::punkty<<"/5 punktów";
    }
    Sleep(3000);
    return 0;
}
