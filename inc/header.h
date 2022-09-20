#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
char *mx_itoa(long long num);

int mx_strlen(const char *s);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printerr(const char *s);

char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strtrim(const char *str);

int mx_add(int a, int b);
int mx_sub(int a, int b);
int mx_mul(int a, int b);
int mx_div(int a, int b);
double mx_pow(double n, unsigned int pow);

void mx_checks_args(char* operand1, char* operation,
	char* operand2, char* res);
void mx_compute(char *operand1, char *operation, char *operand2,
	char *result);

#endif
