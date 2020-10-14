#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<string> genre(n);
	vector<int> play(n);

	for (int i = 0; i < n; i++)
	{
		cin >> genre[i] >> play[i];
	}

	vector<pair<string,int>> genreCmp;
	vector<int> playCnt(n,0);

	int cnt = 0;
	bool isContinue = false;
	while (cnt<n)
	{
		isContinue = false;
		for(int i =0;i< genreCmp.size();i++)
		{
			if (genreCmp[i].first == genre[cnt])
			{
				genreCmp[i].second += play[cnt];
				isContinue = true;
			}
		}
		if (isContinue)
		{
			cnt++;
			continue;
		}
		genreCmp.push_back(make_pair(genre[cnt], 0));
		genreCmp[genreCmp.size() - 1].second += play[cnt];
		cnt++;
	}

	sort(genreCmp.begin(), genreCmp.end(), [](auto& left, auto& right) {
		return left.second > right.second;
	});

	/*for (int i = 0; i < genreCmp.size(); i++)
	{
		cout << genreCmp[i].first << " " << genreCmp[i].second << endl;
	}*/


	cnt = 0;
	int loop = 0;
	int maxCount = 0;
	int temp = -1;
	string songGenre;
	while (loop < genreCmp.size())
	{
		while (cnt < 2)
		{
			songGenre = genreCmp[loop].first;
			for (int i = 0; i < n; i++)
			{
				if (songGenre == genre[i])
				{
					if (play[i] > maxCount)
					{
						maxCount = play[i];
						temp = i;
					}
				}
			}
			if (temp != -1)
			{
				cout << temp << endl;
				play[temp] = 0;
			}
			cnt++;
			temp = -1;
			maxCount = 0;
		}
		cnt = 0;
		loop++;
	}
	return 0;
}