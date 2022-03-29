#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int len(char* s){
    int n=0;
    while (!(s[n]==0)){
        n++;
    }
    return n;
}
/*
char* removeaccents(char* word){
    char* res;
    int i =0;
    while(word[i]!=0) {
        switch (word[i]) {
            case 'à': res[i] = 'a'; break;
            case 'è': res[i] = 'e'; break;
            case 'é': res[i] = 'e'; break;
            case 'ì': res[i] = 'i'; break;
            case 'ò': res[i] = 'o'; break;
            case 'ù': res[i] = 'u'; break;
            default : res[i] = word[i];
        }
        i++;

     }
     return res;
}*/

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

int verifdico(char* mot, char* dico){
    FILE* fichier1 = fopen(dico,"rb");
    if (fichier1 == NULL){
        printf("erreur ouverture fichier ");
    }
    char buffer[256];
    while (!feof(fichier1)){
        fscanf(fichier1,"%s",buffer);
        if (strcmp(mot,buffer) == 0 ){
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
void hint(char* guess,char* word){
    int i =0;
    while(guess[i]!=0){
        if (guess[i]==word[i]){
            printf("X");
        }
        
        else if (veriflettre(guess[i],word)){
            printf("x");
        }
        else{printf(".");}
        i++;
    }
    printf("\n");
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
        if (len(buffer)==longueur){
            fprintf(fichier2,"%s\n",buffer);

    }

}
    fclose(fichier1);
    fclose(fichier2);
}

int main(int argc,char const *argv[]){
    char s[20];
    bool win = 0;
    int n = 0;
    char buffer[256];
    int size = 6144;
    srand(time(NULL));
    int r = 1000*rand()%size;

    readnthline("dicotrie.txt",r,buffer);
    printf("%s",buffer);
    printf("\n Ecrivez votre mot de 5 lettres: \n");
    while (!(win)){
    scanf("%19s", s);
    int lon = len(s);
    if (lon!=5){
        printf("Votre mot ne fait pas 5 lettres\n");
        continue;
    }
    if (!(verifdico(s,"dicotrie.txt"))){
        printf("Ce mot n'existe pas\n");
        continue;
    }
    hint(s,buffer);
    if (strcmp(s,buffer)==0){
        win = 1;
        printf("Vous avez gagné");
    }

    n++; 
    if (n==6){
        printf("perdu");
    }}

    return 0;
}