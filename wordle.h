#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unac.h>

int len(char* s);


void readnthline(char* fichier, int n,char* buffer);

char* remove_accents(char* word);

int veriflettre(char guess,char* word);

void hint(char* guess,char* word);

void tridico(char* dico,char* dicotrie,int longueur);

int wordle(int argc,char const *argv[]);