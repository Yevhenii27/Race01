#include "header.h"

static void is_operand(char *operand) {
	if (mx_strlen(operand) == 0) {
		mx_printerr("Invalid operand: ");
		mx_printerr(operand);
		mx_printerr("\n");
		exit(-1);
	}
	
	for (int v = 0; operand[v] != '\0'; v++) {
		if (operand[0] == '-')
			continue;

		if (!mx_isdigit(operand[v])
			&& operand[v] != '?') {
			mx_printerr("Invalid operand: ");
			mx_printerr(operand);
			mx_printerr("\n");
			exit(-1);
		}
	}
}

static void is_operation(char *operation) {
	if (mx_strlen(operation) != 1
		&& operation[0] != '+'
		&& operation[0] != '-'
		&& operation[0] != '*'
		&& operation[0] != '/'
		&& operation[0] != '?') {
		mx_printerr("Invalid operation: ");
		mx_printerr(operation);
		mx_printerr("\n");
		exit(-1);
	}
}

static void is_result(char *result) {
	if (mx_strlen(result) == 0) {
		mx_printerr("Invalid result: ");
		mx_printerr(result);
		mx_printerr("\n");
		exit(-1);
	}
	
	for (int k = 0; result[k] != '\0'; k++) {
		if (result[0] == '-')
			continue;

		if (!mx_isdigit(result[k])
			&& result[k] != '?') {
			mx_printerr("Invalid result: ");
			mx_printerr(result);
			mx_printerr("\n");
			exit(-1);
		}
	}
}

void mx_checks_args(char* operand1, char* operation,
	char* operand2, char* res) {
	is_operation(operation);
	is_operand(operand1);
	is_operand(operand2);
	is_result(res);
	return;
}
	
