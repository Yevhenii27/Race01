#include "header.h"

char *mx_strtrim(const char *str)
{
	int length;
	char *trim_str;
	
	if (str == NULL)
		return NULL;
	
	while (mx_isspace(*str))
		str++;
	
	length = mx_strlen(str);
	while (mx_isspace(*str) && length > 0)
		length--;
	
	trim_str = mx_strnew(length);
	return mx_strncpy(trim_str, str, length);
}

