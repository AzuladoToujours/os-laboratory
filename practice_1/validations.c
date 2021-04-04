#include "validations.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int path_specified(int argc){
    if(argc < 2){
        printf("You must specify an input filepath\n");
		return EXIT_FAILURE;
	}
}

int file_opened(FILE *fp, char*argv[]){
    if(!fp){
        printf("Error while opening the file %s\n",argv[1]);
		return EXIT_FAILURE;
    }
}

int * get_quantities(int quantities[], char *word, char *rest, int termsCounter){
    while (word = strtok_r(rest," ",&rest)) {
				quantities[termsCounter] = atoi(word);
				termsCounter++;
	}
    return quantities;
}

bool check_NTPP(int quantities[]){
    if(quantities[0] != calculate_NTPP(quantities)){
        return false;
    }   
    
    return true;
}

int calculate_NTPP(int quantities[]){
    int NTPP = (2*quantities[1] + 3*quantities[2] + 4*quantities[3]);
    return NTPP;
}

void delete_spaces(char* restrict str_trimed, const char* restrict str_untrimmed) {
	while(*str_untrimmed != '\0') {
		if(!isspace(*str_untrimmed)) {
			*str_trimed = *str_untrimmed;
			str_trimed++;
		}
		str_untrimmed++;
	}
	*str_trimed = '\0';
}


int read_ingredients_per_dish(int ingredientsNumber, char *word, char *rest, bool flag, int ingredients, char difQuantities[20][10]){
    for (int i =0; i < ingredientsNumber; i++) {
				word = strtok_r(rest," ", &rest);
				flag = false;
				if ((word == NULL) || (word[0] =='\0')){
					return -1;/*Less words*/
				}
				char *aux = (char*) malloc(sizeof(char*));
				delete_spaces(aux, word);
				for (int j = 0; j < ingredients; j++) {
					int result = strcmp(difQuantities[j], aux);
					if(result == 0){
						flag = true;
					}
				}
				if (flag == false) {
					strcpy(difQuantities[ingredients], aux);
					ingredients++;
				}
	}
        return ingredients;
}

int get_ingredients_count(FILE * restrict fp, int quantities[], char difQuantities[20][10]){
    char lines[1024];
	bool flag;
    int lineCounter = 0;
	int termsCounter = 0;
	int ingredients = 0;
    int ingredientsNumber = 0;
	
    while(fgets(lines, 1024,fp)){
        char *word;
        char *rest = lines;
        //Coincidence validation between dishes and lines
        if(lineCounter==0){
            bool isNTPPCorrect;
            quantities = get_quantities(quantities, word, rest, termsCounter);
            isNTPPCorrect = check_NTPP(quantities);
            if(!isNTPPCorrect){
                return -2; /*NTPP not correct*/
            }
            lineCounter++;
        }else{
            word= strtok_r(rest," ", &rest);
            ingredientsNumber = atoi(word);
            if (ingredientsNumber == 0){
                return -3; /*Invalid ingredients number*/
            }

            ingredients = read_ingredients_per_dish(ingredientsNumber, word, rest, flag, ingredients, difQuantities);
            if (ingredients == -1){
                return -4; /*Less words*/
            }
            lineCounter++;
        }
    }
    if ((lineCounter-1) != quantities[0]) {
        return -1;
    }
    return ingredients;
}








