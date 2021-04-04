#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>

void initialize_P(int PP,int ingredients, int P[PP][ingredients]);

void fill_P(FILE * restrict fp, int PP, int ingredients, int P[PP][ingredients], char difQuantities[20][10]);

void print_P(int PP, int ingredients, int P[PP][ingredients]);

void fill_AP(int NTPP, int AP[NTPP]);

void print_AP(int NTPP, int AP[NTPP]);

void print_trans_P(int PP, int ingredients, int P[PP][ingredients]);

void print_final_ingredients(int ingredients, int PP, int P[PP][ingredients], char difQuantities[20][10], int NTPP, int AP[NTPP], int P2, int P3, int P4);

#endif