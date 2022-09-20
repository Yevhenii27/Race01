#include "header.h"

char *mx_strdup(const char *str)
{
	char *dst = NULL;
	char *temp;
	int len = mx_strlen(str) + 1;
	
	dst = mx_strnew(len);
	
	if (str == NULL)
		return NULL;

	temp = mx_strcpy(dst, str);
	
	return temp;
}

