#include <iostream>
#include <locale.h>
#define MAX_LEN 100

using namespace std;

int str_len1(char* source)
{
	int i = 0;
	while (source[i]) // (source[i]!='\0')
	{
		i++;
	}
	return i;
}
int str_len2(char* source)
{
	int i = 0;
	for (; source[i] != '\0'; i++)
	{
	}
	return i;
}
int str_len3(char source[])
{
	int i = 0;
	for (; source[i]; i++)
	{
	}
	return i;
}
int str_len4(char source[])
{
	int i = 0;
	while (source[i]) // (source[i]!='\0')
	{
		i++;
	}
	return i;
}

int str_cmp1(const char* left_s, const char* right_s)
{
	int result = 0;
	int i = 0;
	while (left_s[i] || right_s[i])
	{
		result = left_s[i] - right_s[i];
		if (result != 0)
		{
			return result / abs(result);
		}
		i++;
	}
	if (left_s[i])
	{
		result = 1;
	}
	if (right_s[i])
	{
		result = -1;
	}
	return result;
}
int str_cmp2(const char* left_s, const char* right_s)
{
	int result = 0;
	int i = 0;
	do
	{
		result = left_s[i] - right_s[i];

		if (!left_s[i] && !right_s[i]) // (!(left_s[i] || right_s[i]) )
		{
			result = 0;
			return result;
		}
		if (!left_s[i])  // left_s[i]=='\0'
		{
			result = -1;
			return result;
		}
		if (!right_s[i])
		{
			result = 1;
			return result;
		}
		i++;
	} while (result != 0);
	return result / abs(result);
	return result;

}

int str_cmp3(const char* left_s, const char* right_s)
{
	for (int i = 0;; i++)
	{
		if (left_s[i] != right_s[i])
			return left_s[i] < right_s[i] ? -1 : 1;
		if (left_s[i] == '\0')
			return 0;
	}
}

int str_cmp4(const char* left_s, const char* right_s)
{
	return *left_s > *right_s ?
		1 : *left_s < *right_s ? -1 :
		*left_s ? str_cmp4(left_s + 1, right_s + 1)
		: 0;

}
void str_del1(int length, char* str, int p, int k)
{
	const char whitespace = ' ';
	int i, j;

	for (i = 0; i <= length; i++)
		if (str[i] == whitespace)
			for (j = i; j <= length; j++)
				str[j] = str[j + 1];
	// обычно еще нужно занулить последний символ строки str[j]="\0";
}

void str_copy1(char* destination, char* source)
{
	int i = 0;
	while (source[i]) // source[i]!='\0'
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}
void str_copy2(char* destination, char* source)
{
	int i;
	for (i = 0; i < strlen(source); i ++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}
void str_copy3(char* destination, char* source)
{
	while (*source != '\0')
	{
		*destination++ = *source++;
	}
	*destination = '\0';
}
void str_copy4(char* destination, char* source)
{
	do 
	{
		*destination++ = *source;
	} while (*source++);
}

int main()
{
	char s2[MAX_LEN] = "123", s1[MAX_LEN] = "122";
	printf("strlen2('%s')=%d\n", s2, str_len2(s2));
	printf("strlen1('%s')=%d\n", s2, str_len1(s2));
	printf("strlen3('%s')=%d\n", s2, str_len3(s2));
	printf("strlen4('%s')=%d\n", s2, str_len4(s2));
	printf(
		"str_cmp1('%s,%s')=%d %d\n",
		s2, s1, str_cmp1(s2, s1),
		str_cmp1(s2, s1) == strcmp(s2, s1)
	);
	strcpy(s2, "123");
	//s1 = "12";
	printf(
		"str_cmp1('%s,%s')=%d %d\n",
		s2,s1, str_cmp1(s2,s1),
		str_cmp1(s2, s1)==strcmp(s2,s1)
	);


}

