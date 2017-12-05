#ifndef ERROR_CALC_H
#define ERROR_CALC_H

#define ERROR_DIVISION_BY_ZERO "Attempted a division by zero"
#define ERROR_NON_INITIALIZED_VARIABLE "Uninitialized variable"
#define ERROR_NOT_A_FUNCTION "Undefined function"
#define ERROR_FILE "Unable to open file"

void printError(char *errorMessage);
void help();
void clear();
void constants();
void functions();

#endif //ERROR_CALC_H