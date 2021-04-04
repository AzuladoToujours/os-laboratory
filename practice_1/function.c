#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void swap(int *firstValue, int *secondValue){
	int aux;
	aux = *firstValue;
	*firstValue = *secondValue;
	*secondValue = aux;
}

int p2_summatory(int P2, int ingredients, int NTPP, int P[NTPP][ingredients], int AP[NTPP]){
    int sum = 0;
    	for(int i=0; i < P2 ; i++){
            for(int j=0; j < ingredients; j++){
                if( P[AP[2*i]][j] || P[AP[(2*i)+1]][j] ){
                    sum++;
                }
            }
	    }
    return sum;
}

int p3_summatory(int P3, int ingredients, int NTPP, int P[NTPP][ingredients], int AP[NTPP], int OP3){
    int sum=0;
    for(int i=0; i<P3; i++){
		for(int j=0; j < ingredients; j++){
			if( P[AP[(OP3+(3*i))]][j] || P[AP[(OP3+(3*i)+1)]][j] || P[AP[(OP3+(3*i)+2)]][j]){
				sum++;
			}
		}
	}
    return sum;
}

int p4_summatory(int P4, int ingredients, int NTPP, int P[NTPP][ingredients], int AP[NTPP], int OP4){
    int sum = 0;
    for(int i=0; i < P4; i++){
		for(int j = 0; j < ingredients; j++){
			if(P[AP[(OP4+(4*i))]][j] || P[AP[(OP4+(4*i)+1)]][j] || P[AP[(OP4+(4*i)+2)]][j] || P[AP[(OP4+(4*i)+3)]][j]){
				sum++;
			}
		}
	}
    return sum;
}

int ingredients_summatory(int NTPP, int AP[NTPP], int ingredients, int P[NTPP][ingredients], int P2, int P3, int P4){
    int sum = 0;
    int OP3 = 2 * P2;
    int OP4 = OP3 + (3 * P3);

	/*Suma para las ordenes de 2 platos*/
	/*for(int i=0; i < p2 ; i++){
		for(int j=0; j < total_ingredients; j++){
			if( p[ap[2*i]][j] || p[ap[(2*i)+1]][j] ){
				sum++;
			}
		}
	}*/

    int sumP2 = p2_summatory(P2, ingredients, NTPP, P, AP);

	/*Suma para las ordenes de 3 platos*/
	/*for(int i=0; i<p3; i++){
		for(int j=0; j < total_ingredients; j++){
			if( p[ap[(op3+(3*i))]][j] || p[ap[(op3+(3*i)+1)]][j] || p[ap[(op3+(3*i)+2)]][j]){
				sum++;
			}
		}
	}*/

    int sumP3 = p3_summatory(P3, ingredients, NTPP, P, AP, OP3);

	/*Suma para las ordenes de 4 platos*/
	/*for(int i=0; i < p4; i++){
		for(int j = 0; j < total_ingredients; j++){
			if(p[ap[(op4+(4*i))]][j] || p[ap[(op4+(4*i)+1)]][j] || p[ap[(op4+(4*i)+2)]][j] || p[ap[(op4+(4*i)+3)]][j]){
				sum++;
			}
		}
	}*/

    int sumP4 = p4_summatory(P4, ingredients, NTPP, P, AP, OP4);

    sum = sumP2 + sumP3 + sumP4;

	return sum;
}

void permute(int *AP, int start, int finish, int PP, int ingredients, int P[PP][ingredients], int P2, int P3, int P4, int *MAX, int *MAX_AP){
    /*Indica el fin de una permutacion*/
	if(start == finish){
		int suma = 0;
		suma = ingredients_summatory(PP, AP, ingredients, P, P2, P3, P4);
		if(suma > *MAX){
			for(int i = 0; i < PP; i++){
				MAX_AP[i] = AP[i];
			}
			*MAX = suma;
		}
	}
	int i;
	for(i = start; i<= finish;i++){
		swap((AP+i), (AP+start));
		permute(AP, start+1, finish, PP, ingredients, P, P2, P3, P4, MAX, MAX_AP);
		swap((AP+i), (AP+start));
	}
}


