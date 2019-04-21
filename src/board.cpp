#include "header.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void FillPrint(int m, int n)
{
	char a[m][n];

	for (int i = m; i > 0; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 8)
			{
				a[i][1] = 'X';
				a[i][2] = 'S';
				a[i][3] = 'I';
				a[i][4] = 'W';
				a[i][5] = 'Q';
				a[i][6] = 'I';
				a[i][7] = 'S';
				a[i][8] = 'X';
			}

			if (i == 7)
			{
				a[i][j] = 'O';
			}

			if (i == 3 || i == 4 || i == 5 || i == 6)
			{
				a[i][j] = ' ';
			}

			if (i == 2)
			{
				a[i][j] = 'o';
			}
			if (i == 1)
			{
				a[i][1] = 'x';
				a[i][2] = 's';
				a[i][3] = 'i';
				a[i][4] = 'w';
				a[i][5] = 'q';
				a[i][6] = 'i';
				a[i][7] = 's';
				a[i][8] = 'x';
			}
		}
	}

 	cout << "Press Esc for Exit" << endl;
	cout << endl;
	for (int i = m; i > 0; i--)
	{
		cout << i << "  ";
		for (int j = 1; j <= n; j++)
		{
			cout << "|" << a[i][j] ;
		}
		cout <<"|" << endl;
	}
	cout << endl <<  "    1 2 3 4 5 6 7 8" << endl;
	cout << "    A B C D E F G H" << endl << endl;
	cout << endl << endl;






	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			cout << "**** player's ONE turn ****" << endl;
			cout << "---------------------------" << endl;
		}
		else
		{
			cout << "**** player's TWO turn ****" << endl;
			cout << "---------------------------" << endl;
		}

		int x1, y1;
		cout << "Which figure: " << endl;
		cin >> x1 >> y1;
		a[x1][y1] = ' ';
		cout << endl;

		int x2, y2;
		cout << "Where to go: " << endl;
		cin >> x2 >> y2;
		if (i % 2 == 0)  //проверка на шаг не больше 1 (или 2 при старте)  сверху
		{
			if(a[x2][y2] == 'o')
			{
				cout << "Error!" << endl;
				break;
			}

			if (x1 == 7)
			{
				if ((x1 - x2) > 2)
				{
					a[x2][y2] = ' ';
					a[x1][y1] = 'O';
					i--;
				}
				else
				{
					a[x1][y1] = ' ';
					a[x2][y2] = 'O';
				}
			}
			else
			{
				if ((x1 - x2) > 1)
				{
					a[x1][y1] = 'O';
					a[x2][y2] = ' ';
					i--;
				}
				else
				{
					a[x1][y1] = ' ';
					a[x2][y2] = 'O';
				}
			}
			if (y1 != y2)
			{
				a[x1][y1] = 'O';
				a[x2][y2] = ' ';
				i--;
			}
		}
		else
		{
			if(a[x2][y2] == 'o' || a[x2][y2] == 'O')
			{
				cout << "Error!" << endl;
				break;
			}

			if (x1 == 2)
			{
				if ((x2 - x1) > 2)
				{
					a[x1][y1] = 'o';
					a[x2][y2] = ' ';
					i--;
				}
				else
				{
					a[x1][y1] = ' ';
					a[x2][y2] = 'o';
				}
			}
			else
			{
				if ((x2 - x1) > 1)
				{
					a[x1][y1] = 'o';
					a[x2][y2] = ' ';
					i--;
				}
				else
				{
					a[x1][y1] = ' ';
					a[x2][y2] = 'o';
				}
			}
			if (y1 != y2)
			{
				a[x1][y1] = 'o';
				a[x2][y2] = ' ';
				i--;
			}
		}
	cout << endl;


	cout << "Press Esc for Exit" << endl;
	cout << endl;
	for (int i = m; i > 0; i--)
	{
		cout << i << "  ";
		for (int j = 1; j <= n; j++)
		{
			cout << "|" << a[i][j] ;
		}
		cout <<"|" << endl;
	}
	cout << endl <<  "    1 2 3 4 5 6 7 8" << endl;
	cout << "    A B C D E F G H" << endl << endl;
	cout << endl << endl;

	char c = cin.get();
 	if(c == 27)
    		{
      			break;
    		}
	}
}
