#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unac.h>
#include "ai.c"




int main(int argc,char const *argv[]){
    char s[256];
    bool win = 0;
    int n = 1;
    char buffer[256];
    int size = 6144;

    srand(time(NULL));
    int r = 1000*rand()%size; // indice random du dico

    int everyindex[6145];
    for (int y=0;y<6145;y++){
        everyindex[y]=y;
    }
    struct pos mots_possibles;
    mots_possibles.possibles = everyindex;
    mots_possibles.size = 6145;

    readnthline("dicotrie.txt",r,buffer);
    char* sol = remove_accents(buffer); //SOLUTION
    //printf("%s",sol); AFFICHER LA SOLUTION
    
    char aide[1];
    printf("Activer l'IA? : o/n \n");
    scanf("%s",aide);

    

    printf("\n Ecrivez votre mot de 5 lettres: \n\n");

    if (aide[0]=='o'){
            printf("\nL'IA conseille : saine\n");
        }

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


    if (strcmp(guess,sol)==0){
        win = 1;
    }
    if (win==0){
        printf("\nEssai %d :  \n",n);
        char* indice = hint(guess,sol);
        printf("%s\n\n",indice);
        if(aide[0] == 'o'){
            //char* opti = optiword(guess,indice,n%2); anncien algo IA : marche pas trop
            //printf("IA : %s \n",opti);
            
            mots_possibles = nvpossibles(guess,indice,mots_possibles);//ensemble des mots possibles d'apres dernier indice
        

            
            //printf("nb pos = %d \n",mots_possibles.size); AFFICHER NOMBRE DE MOTS POSSIBLES
            char nvbuffer[256];

            //ANALYSE FREQUENCES :
            if (n<3){
            char res[5];  
            int max = 0;
            for (int k =0;k<mots_possibles.size;k++){
                readnthline("dicotrie.txt",mots_possibles.possibles[k],nvbuffer);
                //printf("%s, ",nvbuffer);
                strcpy (nvbuffer,remove_accents(nvbuffer));
                if (freqscore(nvbuffer)>max){
                    strcpy(res,nvbuffer);
                    max = freqscore(nvbuffer);
                }

            }
            printf("L'IA conseille : %s \n\n",res);
            }
            else{//2EME ETAPE IA :
            meilleurmot(mots_possibles);
            }}
    }
    n++; 
    if (win==1){
        printf("Vous avez gagné \n");
    }
    if ((n==7) && (win==0)){
        printf("Perdu........... \n");
        break;
    }}

    return 0;
}