#include <stdio.h>
#include "utils.h"

void printError(char *errorMessage){
    printf("\033[0;31mERROR:\t%s\033[0;0m\n",errorMessage);
}

void help(){
    printf("\nHELP MENU\n");
    printf("Available commands\n");
    printf("\t\"help\"                Displays Quick Maths help menu\n");
    printf("\t\"table\"               Displays symbols table on screen\n");
    printf("\t\"constants\"           Displays a list of the available constants\n");
    printf("\t\"functions\"           Displays a list of the available functions\n");
    printf("\t\"load <filename>\"     Loads and executes math operations from a file\n");
    printf("\t\"clear\"               Clears the screen\n");
    printf("\t\"exit\"                Terminates the program\n");
}

void constants(){
    printf("\n\nLIST OF AVAILABLE CONSTANTS\n");
    printf("e:                        Euler\'s number                                                  2.7182\n");
    printf("pi:                       Ratio of a circle\'s circumference to its diameter.              3.1416\n");
    printf("phi:                      Golden ratio                                                    1.618\n");
    printf("gamma:                    Euler–Mascheroni constant                                       0.5772\n");
    printf("L:                        Avogadro constant                                               6.023*10^23\n");
}

void functions(){
    printf("\n\nLIST OF AVAILABLE FUNCTIONS\n");
    printf("cos(<argument>)           Cosine of <argument>\n");
    printf("sin(<argument>)           Sine of <argument>\n");
    printf("tan(<argument>)           Tangent of <argument>\n");
    printf("acos(<argument>)          Arcosine of <argument>\n");
    printf("asin(<argument>)          Arcsine of <argument>\n");
    printf("atan(<argument>)          Arctangent of <argument>\n");
    printf("cosh(<argument>)          Hyperbolic cosine of <argument>\n");
    printf("sinh(<argument>)          Hyperbolic sine of <argument>\n");
    printf("tanh(<argument>)          Hyperbolic tangent of <argument>\n");
    printf("log(<argument>)           Natural logarithm <argument>\n");
    printf("log10(<argument>)         Common logarithm <argument>\n");
    printf("exp(<argument>)           e raised to the given power <argument>\n");
    printf("exp2(<argument>)          2 raised to the given power <argument>\n");
    printf("sqrt(<argument>)          Square root of <argument>\n");
    printf("abs(<argument>)           Absolute value of <argument>\n");
}

void clear(){
    for(int i=0; i<80; i++)printf("\n");
}