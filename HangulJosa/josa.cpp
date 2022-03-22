#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "kstbl.h"

/**
* ���� �ѱ� ���ڿ� ���� Ȯ��
**/
int IsHangulString(unsigned char *str)
{
	for (int i = 0; i < (int)strlen((const char*)str); i += 2) {
		if (!(str[i] >= 0xb0 && str[i] <= 0xc8 && str[i+1] >= 0xa1 && str[i+1] <= 0xfe) ){
			return 0;
		}
	}
	return 1;
}

/**
* ��ħ�� �����ϴ� �������� ����
**/
int HasSupportHan(char *str)
{
	unsigned char high, low;
	int hightmp, lowtmp;
	int len;
	int found = 0;

	len = strlen(str);

	if (len < 2) {
		return 0;
	}

	lowtmp = str[len - 1];
	len -= 2;
	hightmp = str[len];

	if (lowtmp > -1) {
		while (len) {
			len--;
			if (len < 0)
				break;
			lowtmp = hightmp;
			hightmp = str[len];
			if ((hightmp < -1) && (lowtmp < -1)) {
				found = 1;
				break;
			}
		}
	}
	else {
		found = 1;
	}

	if (!found) {
		return 0;
	}

	high = hightmp;
	low = lowtmp;

	high = KStbl[(high - 0xb0) * 94 + low - 0xa1] & 0x1f;

	if (high < 2 || high > 28) {
		return 0;
	}

	return 1;
}

/**
* ����ó�� �Լ�
* char *str : ó�� ��� ���ڿ�
* char *first : str�� ��ħ�� ���� ��� ����� ���� ( ��: ��,��,�� )
* char *second : str�� ��ħ�� ���� ��� ����� ���� ( ��: ��,��,�� )
**/
char *MakeJosa(char *str, char *first, char *second )
{
	const char *err = "<!����>";

	if (!str || !*str) {
		return (char*)err;
	}

	if (HasSupportHan(str)) {
		return first;
	}
	else {
		return second;
	}

	return (char*)err;
}