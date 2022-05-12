#include <stdio.h>
#include <time.h>
#include "utils.c"

int dist(char* guess, char* hint, char* word){
    int res = 0;
    for(int i=0;i<5;i++){
        if (hint[i] == 'x'){
            if (!(veriflettre(guess[i],word))){
                res+=10;
            }
        if (hint[i]=='X'){
            if (!(guess[i]==word[i])){
                res += 50;
            }
        }
        
        }
    }
    return res;

}


/*
on se base sur les infos qu'on a deja grace au int donc start avec un truc qui donne le max d'infos 
ie check les frequences des lettres 
*/
char* optiword(char* guess, char* hint,int sens){
    char buffer[256];
    int mindist= 100;
    char* res = malloc(5*sizeof(char));
    if (sens == 0){
    for (int i =0;i<6145;i++){
        readnthline("dicotrie.txt",i,buffer);
        if(dist(guess,hint,buffer) < mindist){
            strcpy(res,buffer);
            mindist = dist(guess,hint,buffer) ;
            //printf("%s %d",buffer,mindist);

            }
    }}
    else {
        for (int i =6144;i>0;i--){
        readnthline("dicotrie.txt",i,buffer);
        if(dist(guess,hint,buffer) < mindist){
            strcpy(res,buffer);
            mindist = dist(guess,hint,buffer) ;
            //printf("%s %d",buffer,mindist);

            }
    }
    }
    return res;
}
/*
int main(int argc,char const *argv[]){

    float temps;
    clock_t t1,t2;

    t1 = clock();

    char buffer[256];

    char* res = ai("elite", "XxxX.");
    printf("%s",res);

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;

    return 0;
}*/