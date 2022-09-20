#include "header.h"

int main(int argc, char* argv[])
{
	if (argc != 5) {
		mx_printerr("usage: ./part_of_the_matrix [operand1] ");
		mx_printerr("[operation] [operand2] [result]\n");
		exit(-1);
	}
	
	char *op1 = mx_strdup(mx_strtrim(argv[1]));
	char *op2 = mx_strdup(mx_strtrim(argv[3]));
	char *oper = mx_strdup(mx_strtrim(argv[2]));
	char *res = mx_strdup(mx_strtrim(argv[4]));
	
	mx_checks_args(op1, oper, op2, res);
	mx_compute(op1, oper, op2, res);
	
	free(op1);
	free(op2);
	free(oper);
	free(res);
	op1 = op2 = oper = res = NULL;
}
