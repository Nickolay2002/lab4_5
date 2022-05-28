#include <iostream>
#include <locale.h>
#include <fstream>
#define MAX_LEN 100
#define INVALID_ARGUMENTS 1
#define INDEX_OUT_OF_RANGE 2

using namespace std;

#pragma region str_len
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
#pragma endregion

#pragma region str_cmp
/// <summary>
///  compare two strings
/// </summary>
/// <param name="left_s"></param>
/// <param name="right_s"></param>
/// <returns>0 if left_s == right_s </returns>
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
		1 : (
			*left_s < *right_s ? -1 :
			(
				*left_s ? str_cmp4(left_s + 1, right_s + 1) : 0
				)
			);

}
#pragma endregion

#pragma region str_del
int str_del1(char* src, int p, int k)
{
	if (k <= 0)
	{
		printf("InvalidArguments\n");
		return INVALID_ARGUMENTS;
	}
	// memorizatiom
	int length = str_len1(src);
	if ((p < 0) || (p >= length))
	{
		printf("IndexOutOfRange!\n");
		return INDEX_OUT_OF_RANGE;
	}
	if ((p + k) >= length)
	{
		src[p] = '\0';
		return 0;
	}
	int i = p;
	while (true)
	{
		src[i] = src[i + k];
		if (is_empty_symbol(src[i]))
		{
			break;
		}
		i++;
	}
	return 0;
}
int str_del2(char* src, int p, int k)
{
	if (k <= 0)
	{
		printf("InvalidArguments\n");
		return INVALID_ARGUMENTS;
	}
	// memorizatiom
	int length = str_len1(src);
	if ((p < 0) || (p >= length))
	{
		printf("IndexOutOfRange!\n");
		return INDEX_OUT_OF_RANGE;
	}
	if ((p + k) >= length)
	{
		src[p] = '\0';
		return 0;
	}
	char* str = src;
	while (*(str + (p + k) * sizeof(char)))
	{
		*(str + p) = *(str + p + k); //+ sizeof(char)
		str++; // + sizeof(char) 
	}
	*str = '\0';
	return 0;
}
int str_del3(char* src, int p, int k)
{
	if (k <= 0)
	{
		printf("InvalidArguments\n");
		return INVALID_ARGUMENTS;
	}
	// memorizatiom
	int length = str_len1(src);
	if ((p < 0) || (p >= length))
	{
		printf("IndexOutOfRange!\n");
		return INDEX_OUT_OF_RANGE;
	}
	if ((p + k) >= length)
	{
		src[p] = '\0';
		return 0;
	}
	int i = p;
	for (;; i++)
	{
		src[i] = src[i + k];
		if (is_empty_symbol(src[i]))
		{
			break;
		}
	}
	return 0;
}
int str_del4(char* src, int p, int k)
{
	if (k <= 0)
	{
		printf("InvalidArguments\n");
		return INVALID_ARGUMENTS;
	}
	// memorizatiom
	int length = str_len1(src);
	if ((p < 0) || (p >= length))
	{
		printf("IndexOutOfRange!\n");
		return INDEX_OUT_OF_RANGE;
	}
	if ((p + k) >= length)
	{
		src[p] = '\0';
		return 0;
	}
	int i = p;
	do
	{
		src[i] = src[i + k];
		i++;
	} while (!(is_empty_symbol(src[i])));
	return 0;
}
#pragma endregion

#pragma region str_ins
char* str_ins1(char* src, char* sub, int pos)
{
	int src_length = strlen(src);
	int sub_length = strlen(sub);
	int res_length = src_length + sub_length;
	char* result = new char[res_length];
	int k = 0;
	//strncpy(result, src, pos)
	for (size_t i = 0; i < pos; i++)
	{
		result[k++] = src[i];
		//k++;
	}
	for (size_t j = 0; j < sub_length; j++)
	{
		result[k++] = sub[j];
		//result[pos + j] = sub[j];
	}
	for (size_t i = pos; i < src_length; i++)
	{
		result[k++] = src[i];
		//result[pos+sub_length+i] = src[i];
	}
	result[k] = '\0';
	return result;
}
char* str_ins2(char* src, char* sub, int pos)
{
	int src_length = strlen(src);
	int sub_length = strlen(sub);
	int res_length = src_length + sub_length;
	char* result = new char[res_length];
	int k = 0, i = 0, j = 0;
	while (i < pos)
	{
		result[k++] = src[i];
		i++;
	}
	i = pos;
	while (j < sub_length)
	{
		result[k++] = sub[j];
		j++;
	}
	while (i < src_length)
	{
		result[k++] = src[i];
		i++;
	}
	result[k] = '\0';
	return result;
}
char* str_ins3(char* src, char* sub, int pos)
{
	int src_length = strlen(src);
	int sub_length = strlen(sub);
	int res_length = src_length + sub_length;
	char* result = new char[res_length];
	int k = 0, i = 0, j = 0;
	do
	{
		result[k++] = src[i];
		i++;
	} while (i < pos);
	i = pos;
	do
	{
		result[k++] = sub[j];
		j++;
	} while (j < sub_length);
	do
	{
		result[k++] = src[i];
		i++;
	} while (i < src_length);
	result[k] = '\0';
	return result;
	return 0;
}
char* str_ins4(char* src, char* sub, int pos)
{
	int sub_length = strlen(sub);
	return 0;
}
// to do
#pragma endregion 

#pragma region str_copy
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
	for (i = 0; i < strlen(source); i++)
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
#pragma endregion  

#pragma region str_pos
int str_pos1(char* src, char* sub)
{
	int result = -1; // -1 not found
	int current_index = -1;
	while (src[current_index]) //  aaassss  aas
	{
		current_index++;
		if (str_cmp1(src + current_index, sub) == 0)//str_cmp1(&src[current_index], sub);
		{
			result = current_index;
			break;
		}
	}
	return result;
}
int str_pos2(char* src, char* sub)
{
	int result = -1;
	int current_index = -1;
	do
	{
		current_index++;
		if (str_cmp1(src + current_index, sub) == 0)
		{
			result = current_index;
			break;
		}
	} while (src[current_index]);
	return result;
}
int str_pos3(char* src, char* sub)
{
	return 0;
}
int str_pos4(char* src, char* sub)
{
	return 0;
}
//to do 3 4
#pragma endregion

bool is_empty_symbol(char c) //predicate
{
	return c == '\0'; // !c
}
// caching of function call result   --runtime   ++memory    trade off
// f(1)  //cach: function f -- arg 1  -- result 0
// f(1)  //
// f(2)  //cach: function f -- arg 2  -- result 1
// f(3)  //cach: function f -- arg 3  -- result 2
// 0x0
// 0x1
// 0x2
// ...
// 9x9
//
//

/// <summary>
/// del from source
/// </summary>
/// <param name="source_str"></param>
/// <param name="start"></param>
/// <param name="number"></param>
/// <param name="result_str"></param>
/// <returns></returns>
bool test_strdel(char* source_str, int start, int number, char* result_str, int result = 0)
{
	//printf("\nprevious str = %s (%d) (%d)\n", source_str, start, number);
	;
	//printf("result str = %s\n", source_str);
	if (
		str_del1(source_str, start, number) != result
		&&
		str_cmp1(result_str, source_str) != 0
		)
	{
		return false;
	}
	return true;
}
/*
 short curcuit
false && x == false
true || x == true  (0|0 =0  0|1=1  1|0=1 1|1=1)
false || x = x 
if (true || x){}
*/

void test_out_of_range_strdel()
{
	int      start[MAX_LEN] = { 10,-10,0 },
		number[MAX_LEN] = { 2,2,12 };
	char in_str[3][MAX_LEN] = { "123abc", "123abc", "" },
		out_str[3][MAX_LEN] = { "123abc", "123abc", "" };

	bool result = true;
	for (size_t i = 0; i < 3; i++)
	{
		if (!test_strdel(in_str[i], start[i], number[i], out_str[i]))
		{
			printf("%d, %u", i, test_strdel(in_str[i], start[i], number[i], out_str[i]));
			result = false;
			break;
		}
	}
	printf("\n test_out_of_range_strdel: %s\n", result ? "passed" : "failed");
}

int main()
{
	char file_name[MAX_LEN] = "";
	int tests_number = 0;
	char  s1[MAX_LEN] = "", s2[MAX_LEN] = "";
	char* s3 = nullptr;
	int position = 0;
#pragma region test_str_len
	strcpy_s(s2, "");
	strcpy_s(s1, "122");
	printf("strlen1('%s')=%d %u\n", s1, str_len1(s1), strlen(s1));
	printf("strlen2('%s')=%d %u\n", s1, str_len2(s1), strlen(s1));
	printf("strlen3('%s')=%d %u\n", s1, str_len3(s1), strlen(s1));
	printf("strlen4('%s')=%d %u\n", s1, str_len4(s1), strlen(s1));
	printf("strlen1('%s')=%d %u\n", s2, str_len1(s2), strlen(s2));
	printf("strlen2('%s')=%d %u\n", s2, str_len2(s2), strlen(s2));
	printf("strlen3('%s')=%d %u\n", s2, str_len3(s2), strlen(s2));
	printf("strlen4('%s')=%d %u\n", s2, str_len4(s2), strlen(s2));
#pragma endregion

#pragma region test_str_cmp
	printf(
		"str_cmp1('%s,%s')=%d %d\n",
		s2, s1, str_cmp1(s2, s1),
		str_cmp1(s2, s1) == strcmp(s2, s1)
	);
	strcpy_s(s2, "123");
	//s1 = "12";
	printf(
		"str_cmp1('%s,%s')=%d %d\n",
		s2, s1, str_cmp1(s2, s1),
		str_cmp1(s2, s1) == strcmp(s2, s1)
	);
#pragma endregion

#pragma region test_str_del
	tests_number = 7;
	int length_start = 5;
	int length_del_number = 8;

	strcpy_s(s2, "asdfg");
	int str_len = strlen(s2);
	int      start_2[MAX_LEN],
		del_number_2 = 0;
	for (size_t i = 0; i < length_start; i++)
	{
		start_2[0] = -1;
		start_2[1] = 0;
		start_2[2] = str_len;
		start_2[3] = str_len + 1;
		start_2[4] = str_len - 1;
	}
	for (size_t i = 0; i < length_start; i++)
	{
		strcpy_s(s2, "asdfg");
		del_number_2 = -start_2[i] + str_len + 1;
		//test_strdel(s2, start_2[i], del_number_2[j], str_out[]);
		str_del1(s2, start_2[i], del_number_2);
		printf(s2);

		/*	strcpy_s(s2, "asdfg");
			str_del2(s2, start_2[i], del_number_2);
			printf(s2);*/

		strcpy_s(s2, "asdfg");
		del_number_2 = -start_2[i] + str_len - 1;
		//test_strdel(s2, start_2[i], del_number_2[j], str_out[]);
		str_del1(s2, start_2[i], del_number_2);
		printf(s2);

		strcpy_s(s2, "asdfg");
		del_number_2 = -start_2[i] + str_len;
		str_del1(s2, start_2[i], del_number_2);
		printf(s2);

		strcpy_s(s2, "asdfg");
		del_number_2 = 0;
		str_del1(s2, start_2[i], del_number_2);
		printf(s2);

		strcpy_s(s2, "asdfg");
		del_number_2 = str_len;
		str_del1(s2, start_2[i], del_number_2);
		printf(s2);

		strcpy_s(s2, "asdfg");
		del_number_2 = -start_2[i] + 1;
		str_del1(s2, start_2[i], del_number_2);
		printf(s2);

		strcpy_s(s2, "asdfg");
		del_number_2 = -start_2[i] - 1;
		str_del1(s2, start_2[i], del_number_2);
		printf(s2);

		strcpy_s(s2, "asdfg");
		del_number_2 = -start_2[i];
	}
	//
	//#pragma region read_file
	//	strcpy_s(file_name, "lab4_5.txt");
	//	ifstream in_file(file_name);
	//	int      startt[MAX_LEN] = { 1,6,1,10,-10,5,0 };
	//	if (!(in_file >> startt[0]))
	//	{
	//		printf("1");
	//	};
	//	in_file >> tests_number;
	//	in_file >> tests_number;
	//	int* start = new int[tests_number];
	//	int* del_number = new int[tests_number];
	//	char** in_str = new char* [tests_number];
	//	for (size_t i = 0; i < MAX_LEN; i++)
	//	{
	//		in_str[i] = new char[MAX_LEN];
	//	}
	//	char** out_str = new char* [tests_number];
	//	for (size_t i = 0; i < MAX_LEN; i++)
	//	{
	//		out_str[i] = new char[MAX_LEN];
	//	}
	//	for (int i = 0; i < tests_number; ++i)
	//	{
	//		in_file >> start[i];
	//		in_file >> del_number[i];
	//		in_file >> in_str[i];
	//	}
	//	// read data
	//	/*7
	//	1 2   123abc 1abc
	//	6 2   123abc 123abc
	//	1 12  123abc 123abc
	//	0 2   123abc 123abc
	//	-10 2 123abc 123abc
	//	5 0   123abc 123abc*/
	//	for (int i = 0; i < tests_number; i++)
	//	{
	//		printf("%d %d %s", start[i], del_number[i], in_str[i]);
	//		//printf("%s %s", in_str[i], out_str[i]);
	//	}
	//#pragma endregion

		////char in_str[7][MAX_LEN]= { "123abc", "123abc", "123abc" , "123abc", "123abc", "123abc", "" },
	 //  //char out_str[7][MAX_LEN] = { "1abc", "123abc", "1", "123abc","123abc","123abc","" };

		//for (size_t i = 0; i < tests_number; i++)
		//{
		//	printf("%s (%s %d %d %s)\n",
		//		test_strdel(in_str[i], start[i], del_number[i], out_str[i]) ? "passed" : "failed",
		//		in_str[i], start[i], del_number[i], out_str[i]
		//	);
		//}
		////test_out_of_range_strdel();
		//// edge case
#pragma endregion

#pragma region test_str_ins
	position = 3;
	strcpy_s(s1, "123abc");
	strcpy_s(s2, "df");
	s3 = str_ins1(s1, s2, position);
	printf("\n%s\n", s3);
	free(s3);
	s3 = nullptr;
	position = 3;
	strcpy_s(s1, "123abc");
	strcpy_s(s2, "df");
	s3 = str_ins1(s1, s2, position);
	printf(s3);
	free(s3);
	s3 = nullptr;
#pragma endregion

#pragma region test_str_copy

#pragma endregion

#pragma region test_str_pos

#pragma endregion
}