// INFO BEGIN
//
// User = 201911511538(卢昶诚) 
// Group = C/C++ 
// Problem = 报数 
// Language = CPP11 
// SubmitTime = 2019-12-15 13:42:30 
//
// INFO END

#include <iostream>
using namespace std;
bool isContainSeven(int num);
int main(int argc, char** argv)
{
	int cnt = 0;
	int index = 0;
	int n = 0;
	int count[4] = {0};
	int begin = 1;
	cin >> n;
	while (cnt < n)
	{
		if (begin % 7 == 0 || isContainSeven(begin))
		{
			begin++;
			count[index]++;
			index = (index + 1) % 4;
			continue;
		}
		begin++;
		index = (index + 1) % 4;
		cnt++;
	}
	
	for (int i = 0; i < 3; i++)
		cout << count[i] << endl;
	cout << count[3];
	return 0;
}

bool isContainSeven(int num)
{
	while(num > 0)
	{
		if (num % 10 == 7)
			return true;
		num /= 10;
	}
	return false;
}
