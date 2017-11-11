/*
* @Author: Carl Hu
* @Date:   2017-11-11 14:21:27
* @Last Modified by:   Carl Hu
* @Last Modified time: 2017-11-11 14:40:02
* @使用三步翻转法实现字符串的转转
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

//字符串翻转
void ReverseString(char *s, int from, int to)
{
	while(from < to)
	{
		char start = s[from];
		s[from] = s[to];
		from++;
		s[to] = start;
		to-- ;
	}
}

//字符串前面的字符移动到字符串的尾部
void LeftRotateString(char *s, int length, int middle)
{
	middle %= length;
	ReverseString(s,0, middle-1);
	ReverseString(s,middle, length-1);
	ReverseString(s,0,length-1);

}

//句子翻转，单词顺序不变
void ReverseWordSentence(char* s, char* newstr)
{
	char oldstr[100];
	strcpy(oldstr, s);
	int length = strlen(oldstr);
	int wordStart = 0;
	int wordEnd = 0;
	while(*s)
	{
		char t = *s;
		if (t==32)
		{
			ReverseString(oldstr,wordStart,wordEnd-1);
			wordStart = ++wordEnd;
		}
		else if(wordEnd==length-1)
		{
			ReverseString(oldstr,wordStart,wordEnd);
			++wordEnd;
		}
		else
		{
			++wordEnd;
		}

		++s;
	}
	ReverseString(oldstr, 0, wordEnd-1);
	strcpy(newstr, oldstr);
}

int main()
{
	char orgStr[] = "abcdef";
	char words[] = "I am a university student from shanghai city of China";

	printf("origin string:\n%s\n", orgStr);
	LeftRotateString(orgStr, strlen(orgStr), 3);
	printf("new string:\n%s\n", orgStr);

	printf("old sentence:\n%s\n", words);
	char newwords[100];
	
	ReverseWordSentence(words,newwords);

	printf("new sentence:\n%s\n",newwords);

	return 0;	

}