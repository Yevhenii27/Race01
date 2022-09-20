#include "header.h"

static void print_res(int op1, char *operation,
	int op2, int res) {
	if (op1 + op2 == res || op1 - op2 == res
		|| op1 * op2 == res || op1 / op2 == res) {
		mx_printint(op1);
		mx_printchar(' ');
		mx_printstr(operation);
		mx_printchar(' ');
		mx_printint(op2);
		mx_printstr(" = ");
		mx_printint(res);
		mx_printchar('\n');
	}
}

static bool is_negative(char *s) {
	if (s[0] == '-')
		return true;

	return false;
}

void mx_compute(char *operand1, char *operation, char *operand2,
	char *result) {
	if (*operation == '?') {
		mx_compute(operand1, "+", operand2, result);
		mx_compute(operand1, "-", operand2, result);
		mx_compute(operand1, "*", operand2, result);
		mx_compute(operand1, "/", operand2, result);
		return;
	}
	
	int op1_length = mx_strlen(operand1);
	int op2_length = mx_strlen(operand2);
	int res_length = mx_strlen(result);
	bool Nop1 = false;
	bool Nop2 = false;
	bool Nres = false;
	
	if (is_negative(operand1)) {
		Nop1 = true;
		operand1++;
		op1_length--;
	}
	if (is_negative(operand2)) {
		Nop2 = true;
		operand2++;
		op2_length--;
	}
	if (is_negative(result)) {
		Nres = true;
		result++;
		res_length--;
	}
			
	long num1 = mx_atoi(operand1);
	long num2 = mx_atoi(operand2);
	long res = mx_atoi(result);
	
	for (long i = 0; i < mx_pow(10, op1_length); i++) {
		if (num1 > 0)
			i = num1;
		char *stri = mx_itoa(i);
		int stri_lng = mx_strlen(stri);
		bool isICorrect = true;
		
		for (int a = 0; a < op1_length - stri_lng; a++) {
			if (mx_isdigit(operand1[a]) && operand1[a] != '0') {
				isICorrect = false;
				break;
			}
		}
		for (int a = op1_length - stri_lng, b = 0; a < op1_length; a++, b++) {
			if (operand1[a] != '?' && operand1[a] != stri[b]) {
				isICorrect = false;
				break;
			}
		}
		free(stri); stri = NULL;
		
		if (!isICorrect) continue;
		
		for (long long j = 0; j < mx_pow(10, op2_length); j++) {  
            if (num2 > 0) {
                j = num2;
            }

            char *strj = mx_itoa(j);
            int strj_lng = mx_strlen(strj);
            bool isJCorrect = true;

            for (int k = 0; k < op2_length - strj_lng; k++) {
                if (mx_isdigit(operand2[k]) && operand2[k] != '0') {
                    isJCorrect = false;
                    break;
                }
            }

            for (int k = op2_length - strj_lng, p = 0; k < op2_length; k++, p++) {
                if (operand2[k] != '?' && operand2[k] != strj[p]) {
                    isJCorrect = false;
                    break;
                }
            }

            free(strj); strj = NULL;

            if (!isJCorrect) {
                continue;
            }
            
            for (long long y = 0; y < mx_pow(10, res_length); y++) {
                if (res > 0) {
                    y = res;
                }
                char *stry = mx_itoa(y);
                int stry_lng = mx_strlen(stry);
                bool isYCorrect = true;

                for (int ph = 0; ph < res_length - stry_lng; ph++) {
                    if (mx_isdigit(result[ph]) && result[ph] != '0') {
                        isYCorrect = false;
                        break;
                    }
                }

                for (int ph = res_length - stry_lng, phy = 0; ph < res_length; ph++, phy++) {
                    if (result[ph] != '?' && result[ph] != stry[phy]) {
                        isYCorrect = false;
                        break;
                    }
                }

                free(stry);
                stry = NULL;

                if (!isYCorrect) {
                    continue;
                }
                
                if (Nop1) i *= -1;
                if (Nop2) j *= -1;
                if (Nres) y *= -1;
                
                print_res(i, operation, j, y);
                
                if (Nop1) i *= -1;
                if (Nop2) j *= -1;
                if (Nres) y *= -1;
                
                if (res > 0) break;
            }
            if (num2 > 0) break;
        }
        if (num1 > 0) break;
    }
    if (Nop1) operand1--;
    if (Nop2) operand2--;
    if (Nres) result--;	
}

