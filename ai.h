#include <stdio.h>
#include <time.h>


int dist(char* guess, char* hint, char* word);
/*
on se base sur les infos qu'on a deja grace au int donc start avec un truc qui donne le max d'infos 
ie check les frequences des lettres 
*/
char* optiword(char* guess, char* hint);
/* int main(int argc,char const *argv[]){

    float temps;
    clock_t t1,t2;

    t1 = clock();

    char buffer[256];

    for(int i = 0;i<6145;i++){
            readnthline("dicotrie.txt",i,buffer);
            if(dist("naise","xxxxx",buffer) <= 5){
            printf("%s, %d, ",buffer,dist("naise","xxxxx",buffer));}}

aines, 5, saine, 5, sanie, 5, 


    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;

    return 0;
}*/