#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

const int mw = 15;
const int mh = 20;
const int sh = mh + 3;

int blocktype = 0;
int blockangle = 0;

int bx = 6;
int by = -4;

//0-�ո�1-���飬2-���ķ���
int mapData[mh][mw] = {
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
};

void printTitle()//��ӡ����
{
	cout << "******************************" << endl;
	cout << "*         ����˹����         *" << endl;
	cout << "******************************" << endl;
}

const int allBlocks[7][4][4][4] = {
	//����
	{
		{
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		},
		{
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		},
		{
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		},
		{
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		}
	},
	//����
	{
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		}
	},
	//͹
	{
		{
			0, 0, 0, 0,
			0, 1, 0, 0,
			1, 1, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 1, 0, 0,
			1, 1, 0, 0,
			0, 1, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			1, 1, 1, 0,
			0, 1, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 1, 0, 0,
			0, 1, 1, 0,
			0, 1, 0, 0
		}
	},
	//Z
	{
		{
			0, 0, 0, 0,
			1, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 1, 0,
			0, 1, 1, 0,
			0, 1, 0, 0
		},
		{
			0, 0, 0, 0,
			1, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 1, 0,
			0, 1, 1, 0,
			0, 1, 0, 0
		}
	},
	//��Z
	{
		{
			0, 0, 0, 0,
			0, 0, 1, 1,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 1, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 1, 1,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 1, 0
		}
	},
	//L
	{
		{
			0, 0, 0, 0,
			0, 1, 0, 0,
			0, 1, 1, 1,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 1, 1, 0
		},
		{
			0, 0, 0, 0,
			1, 1, 1, 0,
			0, 0, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		}
	},
	//��L
	{
		{
			0, 0, 0, 0,
			0, 0, 1, 0,
			1, 1, 1, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0
		},
		{
			0, 0, 0, 0,
			0, 1, 1, 1,
			0, 1, 0, 0,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 1, 0
		}
	}
};

void printMap(int mapData[mh][mw], int mh, int mw)
{
	for (int i = 0; i < mh; i++)
	{
		for (int j = 0; j < mw; j++)
		{
			char* pch = " ";
			switch (mapData[i][j])
			{
			case 1:
				pch = "��";
				break;
			case 2:
				pch = "��";
				break;
			default:break;
			}
			int relax = j - bx;
			int relay = i - by;
			if (relax < 4 && relay < 4 && relax >= 0 && relay >= 0)
			{
				switch (allBlocks[blocktype][blockangle][relay][relax])
				{
				case 1:pch = "��"; break;
				case 2:pch = "��"; break;
				default: break;
				}
			}
			cout << setw(2) << pch;
		}
		cout << endl;
	}
}

void redraw(int mapData[mh][mw], int mh, int mw)
{
	system("color 71");
	system("cls");
	printTitle();
	printMap(mapData, mh, mw);
}

void input()
{
	int code = getch();
	switch (code)
	{
	case'a':
	case'A':
		bx -= 1;
		break;
	case'd':
	case'D':
		bx += 1;
		break;
	case's':
	case'S':
		by += 1;
		break;
	case'w':
	case'W':
		blockangle = (blockangle + 1) % 4;
		break;
	default:break;
	}
}

void logic()
{

}

void newABlock()
{
	blocktype = rand() % 7;
	blockangle = rand() % 4;
	bx = 6;
	by = -4;
}

void init()
{
	srand(unsigned(time(0)));
	newABlock;
}

void main()
{
	init();
	while (1)
	{
		redraw(mapData, mh, mw);
		input();
		logic();
	}
}