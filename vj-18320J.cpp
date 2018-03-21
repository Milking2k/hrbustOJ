#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[])
{
	std::vector<string> words[1005];
	int wordLen[200];
	string line;
	int linNum=0;

	memset(wordLen,0,sizeof(wordLen));
	while(getline(cin,line))
	{
		string temp;
		stringstream ss(line);
		int count=0;
		while(ss >> temp)
		{
			int cntLen = temp.length();
			wordLen[count] = max(wordLen[count],cntLen);
			count++;
			words[linNum].push_back(temp);
		}
		linNum++;
	}
	for (int i = 0; i < linNum; ++i)
	{
		for (int j = 0; j < words[i].size(); ++j)
		{
			cout << words[i][j];
			int wdSize = (int)words[i][j].size();
			if (j!=words[i].size()-1)
			{
				for (int k = wdSize; k < wordLen[j]; ++k)
				{
					printf(" ");
				}
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}