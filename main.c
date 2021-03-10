#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int correct(char input[])
{
    char circle[] = "circle";
    int i = 0, j = 0, k = 0, g = 0;
    while (input[i] == ' ') i++;                                                 
    for (; (input[i] != '(') && (isalpha(input[i]) > 0); i++, k++, g++) {        
        if (circle[g] != (tolower(input[i]))) {
            printf("Error at column %d '%c': expected 'circle'\n", i, input[i]); //сравнение ввода с примером circle, вывод сообщения об ошибке и
            exit(0);                                                             //позиции с ошибкой
        }
    }
    while (input[i] == ' ') { 
        i++;                                                                     
    }
    if (input[i] != '(') {
        printf("Error at column %d '%c': expected '('\n", i, input[i]);     
        exit(0);
    } else {
        i++;                                                                  
        k++; 
    }
    while ((isdigit(input[i]) == 0) && (input[i] != '-')) {                     
        if (input[i] == ' ') { 
        } else {
            printf("Error at column %d '%c': expected '<double>'\n", i, input[i]);
            exit(0); 
        }
    }
    if (input[i] == '-') { 
        i++;
        k++;
    }
    if (isdigit(input[i]) == 0) { 
        printf("Error at column %d '%c': expected '<double>'\n", i, input[i]);
        exit(0);
    }
    while ((isdigit(input[i]) > 0) || (input[i] == '.')) {
        if ((input[i] == '.') && (j == 0)) {
            j++;
        }
        i++;
        k++;
        if ((input[i] == '.') && (j > 0)) {
            printf("Error at column %d '%c': expected '<double>'\n", i, input[i]);
            exit(0);
        }
    }
    k++;
    while ((isdigit(input[i]) == 0) && (input[i] != '-')) {
        if (input[i] == ' ') {
            i++;
        } else {
            printf("Error at column %d '%c'", i, input[i]);
            printf(": expected '<double>' or 'space'\n");
            exit(0);
        }
    }
    if (input[i] == '-') {
        i++;
        k++;
    }

    if (isdigit(input[i]) == 0) {
        printf("Error at column %d '%c': expected '<double>'\n", i, input[i]);
        exit(0);
    }
    j = 0;
    while ((isdigit(input[i]) > 0) || (input[i] == '.')) {
        if ((input[i] == '.') && (j == 0)) {
            j = i;
        }
        i++;
        k++;
        if ((input[i] == '.') && (j > 0)) {
            printf("Error at column %d '%c': expected '<double>'\n", i, input[i]);
            exit(0);
        }
    }
    if ((input[j] == '.') && (isdigit(input[j + 1]) == 0)) {
        printf("Error at column %d '%c': expected '<double>'\n", i, input[i]);
        exit(0);
    }
    while (input[i] == ' ') {
        i++;
    }
    if (input[i] != ',') {
        printf("Error at column %d '%c': expected ','\n", i, input[i]);
        exit(0);
    } else {
        i++;
        k++;
    }
    k++;
    while (isdigit(input[i]) == 0) {
        if (input[i] == ' ') {
            i++;
        } else {
            printf("Error at column %d '%c'", i, input[i]);
            printf(": expected '<double>' or 'space'\n");
            exit(0);
        }
    }
    j = 0;
    while ((isdigit(input[i]) > 0) || (input[i] == '.')) {
        if ((input[i] == '.') && (j == 0)) {
            j = i;
        }
        i++;
        k++;
        if ((input[i] == '.') && (j > 0)) {
            printf("Error at column %d '%c': expected '<double>'\n", i, input[i]);
            exit(0);
        }
    }
    if ((input[j] == '.') && (isdigit(input[j + 1]) == 0)) {
        printf("Error at column %d '%c': expected '<double>'\n", i, input[i]);
        exit(0);
    }
    while (input[i] == ' ') {
        i++;
    }
    if (input[i] != ')') {
        printf("Error at column %d '%c': expected ')'\n", i, input[i]);
        exit(0);
    } else {
        i++;
        k++;
    }
    while (input[i] == ' ') {
        i++;
    }
    if (input[i] != '\n') {
        printf("Error at column %d '%c': unexpected token\n", i, input[i]);
        exit(0);
    }
    printf("Input is correct\n(case insensitive and ignoring whitespace)\n");
    return k;
}
void str_copy(char input[], char* output_circle)
{
    int i = 0, j;
    while (input[i] == ' ') {
        i++;
    }
    for (j = 0; (input[i] != '(') && (input[i] != ' '); i++, j++) {
        output_circle[j] = input[i];
    }
    output_circle[j] = '(';
    j++;
    while ((input[i] != '-') && (isdigit(input[i]) == 0)) {
        i++;
    }
    for (; input[i] != ' '; i++, j++) {
        output_circle[j] = input[i];
    }
    output_circle[j] = ' ';
    j++;
    while (input[i] == ' ') {
        i++;
    }
    for (; (input[i] != ',') && (input[i] != ' '); i++, j++) {
        output_circle[j] = input[i];
    }
    output_circle[j] = ',';
    j++;
    output_circle[j] = ' ';
    j++;
    while (input[i] == ' ') {
        i++;
    }
    if (input[i] == ',') {
        i++;
    }
    while (input[i] == ' ') {
        i++;
    }
    for (; (input[i] != ')') && (input[i] != ' '); i++, j++) {
        output_circle[j] = input[i];
    }
    output_circle[j] = ')';
    j++;
    output_circle[j] = '\0';
}
void output(char* output_circle)
{
    fputs(output_circle, stdout);
}
    int main()
{
    int max = 1000, size_output_circle;
    char* input = NULL;
    input = calloc(max, sizeof(char));
    char* output_circle = NULL;
    fgets(input, max, stdin);
    size_output_circle = correct(input);
    output_circle = calloc(size_output_circle, sizeof(char));
    str_copy(input, output_circle);
    output(output_circle);
    free(input);
    printf("\n");
    return 0;
}