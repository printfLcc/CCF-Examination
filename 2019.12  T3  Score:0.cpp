// INFO BEGIN
//
// User = 201911511538(卢昶诚) 
// Group = C/C++ 
// Problem = 化学方程式 
// Language = CPP11 
// SubmitTime = 2019-12-15 14:47:13 
//
// INFO END

#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	int n;
	cin >> n;
	string* list = new string[n];
	bool* isLegal = new bool[n];
	memset(isLegal, 0, sizeof(isLegal));
	for (int i = 0; i < n; i++)
		cin >> list[i];
		
	for (int i = 0; i < n; i++)
	{
		int size = list[i].length();
		int equalNum = 0;
		for (int j = 0; j < size; j++)
		{
			if (list[i][j] == '=' && j != 0 && j != size - 1)
				equalNum++;
		}
		if (equalNum != 1)
			continue;
		
		for (int j = 0; j < size; j++)
		{
			if ('A' <= list[i][j] && list[i][j] <= 'Z')
			{
				if ('a' <= list[i][j+1] && list[i][j+1] <= 'z')
					continue;
			}
			if (list[i][j] == '+')
			{
				if (list[i][j-1] == '+' || list[i][j-1] == '=' || j == size - 1)
					continue;
				if (j < size - 1)
				{
					if ('a' <= list[i][j+1] && list[i][j+1] <= 'z')
						continue;
				}
			}
		}
		
		isLegal[i] = true;	
	}
	
	for (int i = 0; i < n; i++)
	{
		int size = list[i].length();
		int preEqual[256] = {0};
		int behindEqual[256] = {0};
		int j = 0;
		for (j; j < size && list[i][j] != '='; j++)
			preEqual[list[i][j]]++;
		for (j = j + 1; j < size; j++)
			behindEqual[list[i][j]]++;
		
		for (j = 0; j < 256; j++)
		{
			if(preEqual[j] != behindEqual[j])
			{
				isLegal[i] = false;
				break;
			}
		}
	}
	
	for (int i = 0; i < n - 1; i++)
		cout << isLegal[i] << endl;
	cout << isLegal[n-1];
	delete[] isLegal;
	return 0;
}
