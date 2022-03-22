#include "pch.h"
#include <stdio.h>

char *MakeJosa(char *str, char *first, char *second);

int main()
{
	char str[256], first[32], second[32];

	while (1) {
		printf("입력법:\r\n[대상문자열] [받침있을때의조사] [받침없을때의조사]\r\n");

		if (scanf("%s %s %s", str, first, second) == 3) {
			printf("조사처리 결과 : %s%s\r\n", str, MakeJosa(str, first, second));
		}
	}
}

