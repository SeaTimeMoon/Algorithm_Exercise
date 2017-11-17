// StringContainSubStr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

using namespace std;

bool StringContain(string &orgStr, string &newStr)
{
	bool isSubStr = false;
	int hash = 0;
	for (int i=0; i<orgStr.length(); ++i)
	{
		hash |= (1<<(orgStr[i] - 'A'));
	}

	for (int i=0; i<newStr.length(); ++i)
	{
		if ((hash &(1<<(newStr[i]) - 'A')) == 0)
		{
			isSubStr = false;
			return isSubStr;
		}
	}

	isSubStr = true;
	return isSubStr;
}


int _tmain(int argc, _TCHAR* argv[])
{
	string orgStr = "abcdjfiejfkj";
	string subStr = "aijfj";
	bool isSubStr = StringContain(orgStr, subStr);

	if (isSubStr)
	{
		printf("is SubStr:true\n");
	}
	else
	{
		printf("is SubStr:false\n");
	}
	
	
	system("pause");
	return 0;
}

