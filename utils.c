#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unac.h>

int len(char* s){
    int n=0;
    while (!(s[n]==0)){
        n++;
    }
    return n;
}


void readnthline(char* fichier, int n,char* buffer){
    FILE* fichier1 = fopen(fichier,"rb");
    if (fichier1 == NULL){
        printf("erreur ouverture fichier ");

    }
    int i =0;
    while (!feof(fichier1)){
        
        fscanf(fichier1,"%s",buffer);

        if (i==n){
            fclose(fichier1);
            break;
        }
        i++;
    }


}

char* remove_accents(char* word){
char* out = 0;
size_t out_length = 0;
if(unac_string("UTF-8", word, strlen(word), &out, &out_length)) {
    perror("unac_string"); } 
else  {
    return out;
}
}

int verifdico(char* mot, char* dico){
    FILE* fichier1 = fopen(dico,"rb");
    if (fichier1 == NULL){
        printf("erreur ouverture fichier ");
    }
    char buffer[256];
    while (!feof(fichier1)){
        fscanf(fichier1,"%s",buffer);
        if (strcmp(mot,remove_accents(buffer)) == 0 ){
            fclose(fichier1);
            return 1;
        }
    }
    fclose(fichier1);
    return 0;
}

int veriflettre(char guess,char* word)
{
    int n =0;
    while(word[n]!=0){
        
        if (word[n]==guess){
            return 1;
            
        }
        n++;
    }
    return 0;
}

int lettercount(char* word, char letter){
    int res = 0;
    for (int i =0;i <5;i++){
        if (word[i]==letter){
            res+= 1;
        }
    }
    return res;
}