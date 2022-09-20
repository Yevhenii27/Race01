#include "header.h"

int mx_atoi(const char *str)
{
	int result = 0;
	int i = 0;
	int sign = 1;
	
	while (str[i] != '\0')
	{
		if (str[i] == '-') {
			sign = -1;
			i++;
			break;
		}
		else if (str[i] == '+') {
			sign = 1;
			i++;
			break;
		}		

		if (mx_isspace(str[i]) && str[i] != '"') {
			break;
		}
		else if (mx_isdigit(str[i]))
			break;
		else
			return 0;
	}
	
	while (str[i] != '\0')
	{
		if (mx_isdigit(str[i])) {
			result = result * 10 + str[i] - 48;
			i++;
		}
		else {
			result = 0;
			break;
		}
	}
	
	return result * sign;
}

