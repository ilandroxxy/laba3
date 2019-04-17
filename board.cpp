#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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
				a[i][j] = 'o';
			}

			if (i == 3 || i == 4 || i == 5 || i == 6)
			{
				a[i][j] = ' ';
			}

			if (i == 2)
			{
				a[i][j] = '*';
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
}

