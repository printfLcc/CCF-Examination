// INFO BEGIN
//
// User = 201911511538(卢昶诚) 
// Group = C/C++ 
// Problem = 回收站选址 
// Language = CPP11 
// SubmitTime = 2019-12-15 14:11:37 
//
// INFO END

#include <iostream>
using namespace std;

struct Node
{
	int x;
	int y;	
};
int main()
{
	int score[5] = {0};
	int n;
	cin >> n;
	Node* list = new Node[n];
	for (int i = 0; i < n; i++)
		cin >> list[i].x >> list[i].y;
		
	
	for (int i = 0; i < n; i++)
	{
		int cntCondition = 0;
		for (int j = 0; j < n; j++)
		{
			if (list[i].x == list[j].x && list[i].y == list[j].y + 1)
				cntCondition++;
			if (list[i].x == list[j].x && list[i].y == list[j].y - 1)
				cntCondition++;
			if (list[i].x == list[j].x + 1 && list[i].y == list[j].y)
				cntCondition++;
			if (list[i].x == list[j].x - 1 && list[i].y == list[j].y)
				cntCondition++;
		}
		if (cntCondition >= 4)
		{
			int examScore = 0;
			for (int j = 0; j < n; j++)
			{
				if (list[i].x == list[j].x - 1 && list[i].y == list[j].y - 1)
					examScore++;
				if (list[i].x == list[j].x - 1 && list[i].y == list[j].y + 1)
					examScore++;
				if (list[i].x == list[j].x + 1 && list[i].y == list[j].y - 1)
					examScore++;
				if (list[i].x == list[j].x + 1 && list[i].y == list[j].y + 1)
					examScore++;
			}
			score[examScore]++;
		}
	}
	
	for (int i = 0; i < 5; i++)
		cout << score[i] << endl;
	
	delete[] list;
	return 0;
}
