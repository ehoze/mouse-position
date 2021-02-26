#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
class mouseposition
{
        public: 
				int filesave(const char *);           
};

//Eryk Kucharski

int mouseposition::filesave(const char *nazwa)
{	
        ofstream plik;
        plik.open(nazwa);
        cout << "F12 - Koniec programu\n";
        while (1)
    	{
	        POINT cursorPos;
	        GetCursorPos(&cursorPos);
	        float x = 0;
	        x = cursorPos.x;
	        float y = 0;
	        float earlx, early;
	        y = cursorPos.y;
	        if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0)
	        {
	            if (x != earlx || y != early)
	            {
	            	cout << x << ',' << y << endl;
					plik << x << ',' << y << endl;
				}
				else
				{
					cout << "";
				}
	            Sleep(0);  
	            earlx = x;
	        	early = y;
	        	if (GetKeyState(VK_F12))
	        	{
	        		plik.close();
	        		return 0;
				}
	        }
	        Sleep(0);
    	}      
}

int main()
{
//Eryk Kucharski
	mouseposition x;
    x.filesave("B:\\Programowanie z Panem Fulaa\\Pozycja myszy\\wynik.txt");
    return 0;
}
