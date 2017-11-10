#include <stdio.h>

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

void LeftRotateString(char *s, int length, int middle)
{
	middle %= length;
	ReverseString(s,0, middle-1);
	ReverseString(s,middle, length-1);
	ReverseString(s,0,length-1);

}

int main()
{
	char str[] = "HelloWorld";
	printf("old string is %s\n", str);
	LeftRotateString(str,10,5);
	printf("new string is %s\n", str);	

}