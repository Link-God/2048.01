#include"stdafx.h"
void sort_down(int a[4][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i > 0; i--)
		{
			if (a[i][j] == 0)
			{
				for (int k = i - 1; k >= 0; k--)
				{
					if (a[k][j] != 0)
					{
						a[i][j] = a[k][j];
						a[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void sort_up(int a[4][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (a[i][j] == 0)
			{
				for (int k = i+1; k < 4; k++)
				{
					if (a[k][j] != 0)
					{
						a[i][j] = a[k][j];
						a[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void sort_right(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (a[i][j] == 0)
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if (a[i][k] != 0)
					{
						a[i][j] = a[i][k];
						a[i][k] = 0;
						break;
					}
				}
			}
		}
	}

}

void sort_left(int a[4][4])
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == 0)
			{
				for (int k = j + 1; k < 4; k++)
				{
					if (a[i][k] != 0)
					{
						a[i][j] = a[i][k];
						a[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}

void down(int a[4][4])
{
	sort_down(a);
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i > 0; i--)
		{
			if (a[i][j] == a[i - 1][j])
			{
				a[i][j] += a[i - 1][j];
				a[i - 1][j] = 0;
			}
		}
	}
	sort_down(a);
}

void up(int a[4][4])
{
	sort_up(a);
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (a[i][j] == a[i + 1][j])
			{
				a[i][j] += a[i + 1][j];
				a[i + 1][j] = 0;
			}
		}
	}
	sort_up(a);
}

void right_1(int a[4][4])
{
	sort_right(a);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (a[i][j] == a[i][j - 1])
			{
				a[i][j] += a[i][j - 1];
				a[i][j - 1] = 0;
			}
		}
	}
	sort_right(a);
}

void left_1(int a[4][4])
{
	sort_left(a);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == a[i][j + 1])
			{
				a[i][j] += a[i][j + 1];
				a[i][j + 1] = 0;
			}
		}
	}
	sort_left(a);
}

bool proverka(int a[4][4])
{
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] == 0)  k += 1;
		}
	}
	if (k == 0)
	{
		return true;
	}
	else return false;
}

#include <iostream>
#include <iomanip>h
using namespace std;
void print(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		cout << endl;
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] == 0) cout << setw(4) << "*";
			else
			{
				cout << setw(4) << a[i][j];
			}
		}
	}
	cout << endl;
}

#include <iostream>
using namespace std;
void read(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> a[i][j];
		}
	}
}

void lose(int a[4][4],bool l)
{
	if (proverka(a) )
	{
		cout << "lose" << endl;
		l = true;
		system("pause");
	}
}
#include <iostream>
using namespace std;
void sdvig( int a[4][4])
{
	bool lose1 = false;
	char op ;
	bool q=true;
	while (q )
	{
		lose(a,&lose1);
		if (lose1) break;
		cin >> op;
		switch (op)
		{
		case 'j':
			down(a);
			print(a);
			cout << endl;
			break;
		case 'k':
			up(a);
			print(a);
			cout << endl;
			break;
		case 'h':
			left_1(a);
			print(a);
			cout << endl;
			break;
		case 'l':
			right_1(a);
			print(a);
			cout << endl;
			break;
		case 'q':
			system("pause");
			q = false;
		default:
			cout << "enter error " << "new op= " << endl;
		}
	}
}

#include <iostream>
int main()
{
	int matrix[4][4];
	read(matrix);
	sdvig(matrix);
	return 0;
}
