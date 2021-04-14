#include<iostream>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<conio.h>
#include<graphics.h>
const int right = 30;
const int bottom = 30;
using namespace std;

class Array
{
public:
	vector<vector<int>> canvas;

	Array(int bottom = 30, int right = 30) {
		for (int i = 0; i < bottom; i++)
		{
			vector<int> a;
			for (int j = 0; j < right; j++)
			{
				a.push_back(0);
			}
			canvas.push_back(a);
		}
	};
};


//vector<vector<int>> Array::canvas(bottom, vector<int>(::right, 0));

void init();
void show();
void WithInput();
void WithoutInput();
