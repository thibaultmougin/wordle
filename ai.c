#include <stdio.h>
#include <time.h>

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

int dist(char* guess, char* hint, char* word){
    int res = 0;
    for(int i=0;i<5;i++){
        if (hint[i] == '.'){
            res+=3;
        }
        if (hint[i] == 'x'){
            if (veriflettre(guess[i],word)){
                res+=1;
            }
            else{res+=3;}
        
        }
    }
    return res;

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
/*
on se base sur les infos qu'on a deja grace au int donc start avec un truc qui donne le max d'infos 
ie check les frequences des lettres 
*/
char* optiword(char* guess, char* hint){
    char buffer[256];
    int mindist= 100;
    char* res;
    for (int i =0;i<6144;i++){
        readnthline("dicotrie.txt",i,buffer);
        if(dist(guess,hint,buffer) < mindist){
            res = buffer;
            mindist = dist(guess,hint,buffer) ;
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