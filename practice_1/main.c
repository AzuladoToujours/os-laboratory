#include "validations.h"
#include "function.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char*argv[]){
    path_specified(argc);

    FILE* fp = fopen(argv[1], "r");

    file_opened(fp, argv);

    int quantities[4];
    char difQuantities[20][10];
    int ingredients=get_ingredients_count(fp, quantities, difQuantities);
    fclose(fp);

    if (ingredients > 0){
        int PP = quantities[0];
        int P2 = quantities[1];
        int P3 = quantities[2];
        int P4 = quantities[3];
        int NTPP = calculate_NTPP(quantities);
        printf("PP: %d \n", PP);
        printf("I: %d \n", ingredients);
        printf("Two dishes' orders: %d \n", P2);
        printf("Three dishes' orders: %d \n", P3);
        printf("Four dishes' orders: %d \n", P4);
        printf("NTPP: %d \n", NTPP);
        int P[PP][ingredients];
        initialize_P(PP, ingredients, P);
        fp = fopen(argv[1], "r");
        fill_P(fp, PP, ingredients, P, difQuantities);
        printf("Dishes' Matrix: \n");
        print_trans_P(PP, ingredients, P);
        int AP[NTPP];
        fill_AP(NTPP, AP);
        printf("-----------------------------\n");
        int *MAX = (int*)malloc(sizeof(int));
        *MAX = 0;
        int *MAX_AP = (int*)malloc(sizeof(int)*NTPP);

        permute(AP, 0, NTPP-1, PP, ingredients, P, P2, P3, P4, MAX, MAX_AP);
        printf("SOLUTION VECTOR: \n");
        print_AP(NTPP, MAX_AP);

        printf("TOTAL DIFFERENT INGREDIENTS: %d \n", *MAX);
        
        print_final_ingredients(ingredients, PP, P, difQuantities, NTPP, AP, P2, P3, P4);


    }else{
        switch (ingredients)
        {
        case -1:
            printf("Fatal Error: Wrong dishes number\n");
            break;
        case -2:
            printf("Fatal Error: NTPP Not Correct\n");
            break;
        case -3:
            printf("Fatal Error: Wrong ingredients number\n");
            break;
        case -4:
            printf("Fatal Error: Less words found\n");
            break;
        default:
            break;
        }
    return EXIT_FAILURE;
    }
}