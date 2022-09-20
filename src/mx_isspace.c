#include "header.h"

bool mx_isspace(char c)
{
	if (c == ' ' || c == '\n'
		|| c == '\t' || c == '\f'
		|| c == '\r' || c == '\v')
		return true;
		
	return false;
}

