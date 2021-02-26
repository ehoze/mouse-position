#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
using namespace std;
string ciag;
int score;
class mouseposition
{
                vector <string> positions;
        public:
                void injected();  
				int filesave(const char *);           
};

void mouseposition::injected()
{

		fstream plik;  
        string wprowadzany;
        plik.open("B:\\Programowanie z Panem Fulaa\\Zadanie Mat. 63.1&2\\ciagi.txt", ios::in); 
         if(plik.good()) 
            while(!plik.eof()) 
                  {
                	plik >> wprowadzany;
                	positions.push_back(wprowadzany);
                   }
                   plik.close();     
        			
}


//Eryk Kucharski
//int mouseposition::obliczanie()
//{
//	    while (1)
//    {
//        POINT cursorPos;
//        GetCursorPos(&cursorPos);
//        float x = 0;
//        x = cursorPos.x;
//        float y = 0;
//        y = cursorPos.y;
//        if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0)
//        {
//            cout << x << ',' << y << endl;
//            
//            Sleep(0);
//            
//        }
//        Sleep(0);
//    }
//}
int mouseposition::filesave(const char *nazwa)
{	
        ofstream plik;
        plik.open(nazwa);
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
	        }
	        Sleep(0);
    	}
        plik.close();        
}

int main()
{
//Eryk Kucharski
	mouseposition x;
    x.injected();
    x.filesave("B:\\Programowanie z Panem Fulaa\\Pozycja myszy\\wynik.txt");
    return 0;
}
