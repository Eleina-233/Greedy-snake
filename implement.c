#include"test.h"
Array c;
int canvas_value;
int pos_x, pos_y;
int target_x, target_y;
int v_x, v_y;
int score;
char x_ch;


using namespace std;

void init()
{
	x_ch = 'd';
	pos_x = 15; pos_y = 1; v_x = 1; v_y = 1;

	for (int i = 0; i < ::right; i++)
	{
		c.canvas[0][i] = -1;
		c.canvas[bottom - 1][i] = -1;
	}
	for (int i = 0; i < bottom; i++)
	{
		c.canvas[i][0] = -2;
		c.canvas[i][::right - 1] = -2;
	}

	for (int y = pos_y, x = pos_x; y > 0; y--)
	{
		c.canvas[x][y] = y;
	}
	canvas_value = c.canvas[pos_x][pos_y];

	srand(time(0));
	target_x = rand() % (bottom - 2);
	target_y = rand() % (::right - 2 );
	c.canvas[target_x][target_y] = -3;
}
	

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void show()
{

	gotoxy(0, 0);
	CONSOLE_CURSOR_INFO cursor_infor = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_infor);

	for (int i = 0; i < bottom; i++)
	{
		for (int j = 0; j < ::right; j++)
		{
			if (c.canvas[i][j] == -2)
				cout << "|";
			else if (c.canvas[i][j] == -1)
				cout << "-";
			else if (i == pos_x && j == pos_y)
				cout << "#";
			else if (c.canvas[i][j] > 0 && !(i == pos_x && j == pos_y))
				cout << "*";
			else if (c.canvas[i][j] == -3)
				cout << "@";
			else if (c.canvas[i][j] == 0)
				cout << " ";
		}
		cout << endl;
	}

	cout << "您的得分是：" << score  << endl;
}

void WithInput()
{
	if (_kbhit())
	{
		char ch = _getch();
		if (x_ch == 'd' && ch == 'a');
		else if (x_ch == 'a' && ch == 'd');
		else if (x_ch == 'w' && ch == 's');
		else if (x_ch == 's' && ch == 'w');
		else
		x_ch = ch;
	}
}

void WithoutInput()
{
	if (x_ch == 'a')
		pos_y -= v_y;
	else if (x_ch == 'd')
		pos_y += v_y;
	else if (x_ch == 'w')
		pos_x -= v_x;
	else if (x_ch == 's')
		pos_x += v_x;

	for (int i = 0; i < bottom; i++)
	{
		for (int j = 0; j < ::right; j++)
		{
			if (c.canvas[i][j] > 0)
				c.canvas[i][j] -= 1;
		}
	}




	if (pos_x == target_x && pos_y == target_y)
	{
		srand(time(0));
		target_x = rand() % (bottom - 2 );
		target_y = rand() % (::right - 2);
		c.canvas[target_x][target_y] = -3;
		canvas_value++;
		score++;
	}
	if (c.canvas[pos_x][pos_y] == -1 || c.canvas[pos_x][pos_y] == -2 ||
		c.canvas[pos_x][pos_y] > 0)
	{
		printf("游戏结束！\n");
		system("pause");
		exit(0);
	}

	c.canvas[pos_x][pos_y] = canvas_value;

	

	Sleep(70);
}
