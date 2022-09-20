#include "header.h"

char *mx_itoa(long long num) {
	char *num_s = NULL;
	
	if (num == 0) {
		num_s = mx_strnew(1);
		num_s[0] = '0';
		return num_s;
	}
	
	int lng = 0;
	long long num_cpy = num;
	if (num_cpy < 0) {
		lng++;
		num_cpy *= -1;
	}
	while (num_cpy != 0) {
		num_cpy /= 10;
		lng++;
	}
	
	num_s = mx_strnew(lng);
	
	if (num < 0) {
		num_s[0] = '-';
		num *= -1;
	}
	num_s[lng--] = '\0';
	while ((num != 0 && lng >= 0)
		&& num_s[lng] != '-') {
		num_s[lng--] = (num % 10) + '0';
		num /= 10;
	}
	return num_s;
}

