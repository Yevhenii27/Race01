#include "header.h"

void mx_printint(int n)
{
	if (n == 0)
		mx_printchar(0);
	else if (n < 0) {
		n *= -1;
		mx_printchar('-');
	}
	else if (n > 9)
		mx_printint(n / 10);
	
	int c = n % 10 + 48;
	mx_printchar(c);
}

