#ifndef VALIDATIONS_H
#define VALIDATIONS_H
#include <stdio.h>

int path_specified(int argc);

int file_opened(FILE *fp, char*argv[]);

int get_ingredients_count(FILE * restrict fp, int quantities[], char difQuantities[20][10]);

int calculate_NTPP(int quantities[]);

void delete_spaces(char* restrict str_trimed, const char* restrict str_untrimmed);

#endif