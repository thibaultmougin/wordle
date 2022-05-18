#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unac.h>


//longueur d'une chaine
int len(char* s){
    int n=0;
    while (!(s[n]==0)){
        n++;
    }
    return n;
}

//lire la n-ième ligne du dico
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

//supprime les accents d'une chaine : necessite unac
char* remove_accents(char* word){
char* out = 0;
size_t out_length = 0;
if(unac_string("UTF-8", word, strlen(word), &out, &out_length)) {
    perror("unac_string"); } 
else  {
    return out;
}
}

//verifie qu'un mot est dans le dico linéairement
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

//verifie qu'une lettre est dans un mot 
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

//compte le nombres d'occurences d'un caractere dans un mot
int lettercount(char* word, char letter){
    int res = 0;
    for (int i =0;i <5;i++){
        if (word[i]==letter){
            res+= 1;
        }
    }
    return res;
}

//retourne l'indice wordle sous forme de string (. : case grise, x : case orange, X : case verte)
char* hint(char* guess,char* word){
    char* res = malloc(1);
    int i =0;
    int cnt[5];
    cnt[0] = 1;
    
    for (int j =0;j<5;j++){
        cnt[j]=0;
        for (int k =0;k<=j;k++){
            if (guess[k]==guess[j])
            {
                cnt[j]++;}
            
        }
    }
    
    while(i<5){
        if (guess[i]==word[i] ){
            res[i] = 'X';
        }
        
        else if (veriflettre(guess[i],word) && (cnt[i]<=lettercount(word,guess[i]))){
            res[i] = 'x';
        }
        else{
        res[i]='.';}
        i++;
    }
    res[5] = '\0';
    return res;
}