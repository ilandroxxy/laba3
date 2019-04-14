#include <iostream>
#include <cstdlib>
#include <ostream>
#include <fstream>


using namespace std;

#define SIZE 8

int main()
{
    while(1)
    {
        ofstream myfile("/home/ilya/Документы/laba3/compile.txt");
        myfile << "Wecome you in my Chess GAME!\n\n";
      //  myfile << "X - White\n- is black\n";
        myfile << "   A     B     C     D     E     F     G     H\n\n";
        
        // for(int i = 1; i <= SIZE; i++)
        //  {  
        //     myfile << "   ";
            for(int j = 1; j <= SIZE;j++)
            {
                if(j == 1)
                myfile << "   r     n     b     q     k     b     n     r   " << j << endl;

                if(j > 2 && j < 7)
                  myfile << "                                                 " << j << endl;
                if(j == 2)
                myfile << "   p     p     p     p     p     p     p     p   " << j << endl;

                if(j == 7)
                myfile << "   P     P     P     P     P     P     P     P   " << j << endl;

                if(j == 8)
                myfile << "   R     N     B     Q     K     B     N     R   " << j << endl;
                 
            }
       
      //   }       
         
         
         char c = cin.get();
         if(c == 27)
         {
            myfile.close();
            break;  
         }     

    }

    return 0;
}
