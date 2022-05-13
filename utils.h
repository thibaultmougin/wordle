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
int verifdico(char* mot, char* dico);
int veriflettre(char guess,char* word);
int lettercount(char* word, char letter);
char* hint(char* guess,char* word);