#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "validations.h"

void initialize_P(int PP,int ingredients, int P[PP][ingredients]){
    for(int i = 0; i < PP; i++){
		for(int j = 0; j < ingredients; j++){
			P[i][j] = 0;
		}
	}
}

void fill_P(FILE * restrict fp, int PP, int ingredients, int P[PP][ingredients], char difQuantities[20][10]){
    char lines[1024];
    int lineCounter = 0;
    int ingredientsNumberPerPlate = 0;
    while(fgets(lines, 1024,fp)){
        char *word;
        char *rest=lines;
        if(lineCounter==0){
            lineCounter++;
        }else{
            word = strtok_r(rest, " ", &rest);
            ingredientsNumberPerPlate = atoi(word);
            for(int i=0; i<ingredientsNumberPerPlate; i++){
                word = strtok_r(rest, " ", &rest);
                char *aux = (char*)malloc(sizeof(char*));
                delete_spaces(aux, word);
                for(int j=0;j<ingredients;j++){
                    int cmp = strcmp(difQuantities[j],aux);
                    if(cmp == 0){
                        P[lineCounter-1][j] = 1;
                        j=ingredients;
                    }
                }
            }
            lineCounter++;
        }
    }
}

void print_P(int PP, int ingredients, int P[PP][ingredients]){
    for(int i=0; i< PP; i++){
        for(int j=0; j<ingredients; j++){
            printf(" %d ", P[i][j]);
        }
        printf("\n");
    }
}

void print_trans_P(int PP, int ingredients, int P[PP][ingredients]){
    for(int i=0; i< ingredients; i++){
        for(int j=0; j<PP; j++){
            printf(" %d ", P[j][i]);
        }
        printf("\n");
    }
}

void fill_AP(int NTPP, int AP[NTPP]){
    for(int i=0; i < NTPP; i++){
        AP[i] = i;
    }
}

void print_AP(int NTPP, int AP[NTPP]){
    for(int i=0; i< NTPP; i++){
        printf(" %d ", AP[i]);
    }
    printf("\n");
}

int print_orderP2(char * line, char * aux_line, char * second_aux_line, int order, int ingredients, int PP, int P[PP][ingredients],char difQuantities[20][10], int NTPP, int AP[NTPP], int P2){
    for(int i = 0; i <= (P2-1); i++) {
		for(int j = 0; j < ingredients; j++) {
			if(P[AP[2*i]][j] == 1 || P[AP[2*i+1]][j] == 1) {
				strcat(second_aux_line, difQuantities[j]);
				strcat(second_aux_line, " ,");
			}
		}
		sprintf(aux_line, "%d", order);
		strcpy(line, "The order ");
		strcat(line, aux_line);
		strcat(line, " contains: ");
		strcat(line, second_aux_line);
		printf("%s\n", line);
		order++;
	}

    return order;
}

int print_orderP3(char * line, char * aux_line, char * second_aux_line, int order, int ingredients, int PP, int P[PP][ingredients],char difQuantities[20][10], int NTPP, int AP[NTPP], int P3, int OP3){

    for(int i = 0; i <= (P3-1); i++) {
		strcpy(second_aux_line, "");
		for(int j = 0; j < ingredients; j++) {
			if(P[AP[OP3+(3*i)]][j] == 1 || P[AP[OP3+(3*i)+1]][j] == 1 || P[AP[OP3+(3*i)+2]][j] == 1) {
				strcat(second_aux_line, difQuantities[j]);
				strcat(second_aux_line, " ,");
			}
		}
		sprintf(aux_line, "%d", order);
		strcpy(line, "The order ");
		strcat(line, aux_line);
		strcat(line, " contains: ");
		strcat(line, second_aux_line);
		printf("%s\n", line);
		order++;
	}
    return order;
}

int print_orderP4(char * line, char * aux_line, char * second_aux_line, int order, int ingredients, int PP, int P[PP][ingredients],char difQuantities[20][10], int NTPP, int AP[NTPP], int P4, int OP4){
    for(int i = 0; i <= (P4-1); i++) {
		strcpy(second_aux_line, "");
		for(int j = 0; j < ingredients; j++) {
			if(P[AP[OP4 + (4*i)]][j] == 1 || P[AP[OP4 + (4*i) + 1]][j] == 1 || P[AP[OP4 + (4*i) + 2]][j] == 1 || P[AP[OP4 + (4*i) + 3]][j] == 1) {
				strcat(second_aux_line, difQuantities[j]);
				strcat(second_aux_line, " ,");
			}
		}
		sprintf(aux_line, "%d", order);
		strcpy(line, "The order ");
		strcat(line, aux_line);
		strcat(line, " contains: ");
		strcat(line, second_aux_line);
		printf("%s\n", line);
		order++;
	}

    return order;
}

void print_final_ingredients(int ingredients, int PP, int P[PP][ingredients], char difQuantities[20][10], int NTPP, int AP[NTPP], int P2, int P3, int P4){
	int order = 0;
	int OP3 = P2*2;
	int OP4 = OP3 + (3*P3);
    char * line = (char *) malloc(sizeof(char) * 11);
    char * aux_line = (char *) malloc(sizeof(char) * 11);
    char * second_aux_line = (char *) malloc(sizeof(char) * 11);

    int orderAfterP2 = print_orderP2(line, aux_line, second_aux_line, order, ingredients, PP, P, difQuantities, NTPP, AP, P2);
	
	int orderAfterP3 = print_orderP3(line, aux_line, second_aux_line, orderAfterP2, ingredients, PP, P, difQuantities, NTPP, AP, P3, OP3);

	print_orderP4(line, aux_line, second_aux_line, orderAfterP3, ingredients, PP, P, difQuantities, NTPP, AP, P4, OP4);

}