#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unac.h>
#include "ai.c"
int len(char* s){
    int n=0;
    while (!(s[n]==0)){
        n++;
    }
    return n;
}

/*
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


}*/

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
/*
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
}*/
char* hint(char* guess,char* word){
    char* res = malloc(1);
    int i =0;
    while(i<5){
        if (guess[i]==word[i]){
            res[i] = 'X';
        }
        
        else if (veriflettre(guess[i],word)){
            res[i] = 'x';
        }
        else{
        res[i]='.';}
        i++;
    }
    printf("\n");
    res[5] = '\0';
    return res;
}

void tridico(char* dico,char* dicotrie,int longueur){
    FILE* fichier1 = fopen(dico,"rb");
    if (fichier1 == NULL){
        printf("erreur ouverture fichier ");

    }
    FILE* fichier2 = fopen(dicotrie,"wb");
    if (fichier2 == NULL){
        printf("erreur ouverture dicotrié");
    }
    char buffer[256];

    while (!feof(fichier1)){
        fscanf(fichier1,"%s",buffer);
        if (strlen(buffer)==longueur){
            fprintf(fichier2,"%s\n",buffer);

    }

}
    fclose(fichier1);
    fclose(fichier2);
}

int main(int argc,char const *argv[]){
    char s[256];
    bool win = 0;
    int n = 0;
    char buffer[256];
    int size = 6144;
    srand(time(NULL));
    int r = 1000*rand()%size;

    readnthline("dicotrie.txt",r,buffer);
    printf("%s",buffer);
    char* sol = remove_accents(buffer);
    printf("%s",sol);
    
    printf("\n Ecrivez votre mot de 5 lettres: \n");
    while (!(win)){

    scanf("%s", s);
    char* guess = s;
    guess = remove_accents(guess);
    int lon = strlen(guess);

    if (lon!=5){
        printf("Votre mot ne fait pas 5 lettres\n");
        continue;
    }
    if (!(verifdico(guess,"dicotrie.txt"))){
        printf("Ce mot n'existe pas\n");
        continue;
    }
    char* indice = hint(guess,sol);
    char* opti = optiword(guess,indice);
    printf("%s\n",indice);
    printf("IA : %s \n",opti);

    if (strcmp(guess,sol)==0){
        win = 1;
        printf("Vous avez gagné\n");
    }

    n++; 
    if (n==6){
        printf("perdu");
    }}

    return 0;
}