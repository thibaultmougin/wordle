#include <stdio.h>
#include <time.h>
#include "utils.c"


struct pos{
    int* possibles;
    int size; 
};
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

int freqscore(char* word){
    int res=0;
    for (int i=0;i<5;i++){
        if (word[i]=='a'){
            res += 9/lettercount(word,word[i]);
        }
        if (word[i]=='b'){
            res += 1/lettercount(word,word[i]);
        }
        if (word[i]=='c'){
            res += 3/lettercount(word,word[i]);
        }
        if (word[i]=='d'){
            res += 3/lettercount(word,word[i]);
        }
        if (word[i]=='e'){
            res += 16/lettercount(word,word[i]);
        }
        if (word[i]=='f'){
            res += 1/lettercount(word,word[i]);
        }
        if (word[i]=='g'){
            res += 1/lettercount(word,word[i]);
        }
        if (word[i]=='h'){
            res += 1/lettercount(word,word[i]);
        }
        if (word[i]=='i'){
            res += 8/lettercount(word,word[i]);
        }
        if (word[i]=='j'){
            res += 1/lettercount(word,word[i]);
        }
        if (word[i]=='k'){
            res += 0/lettercount(word,word[i]);
        }
        if (word[i]=='l'){
            res += 5/lettercount(word,word[i]);
        }
        if (word[i]=='m'){
            res += 3/lettercount(word,word[i]);
        }
        if (word[i]=='n'){
            res += 7/lettercount(word,word[i]);
        }
        if (word[i]=='o'){
            res += 5/lettercount(word,word[i]);
        }
        if (word[i]=='p'){
            res += 3/lettercount(word,word[i]);
        }
        if (word[i]=='q'){
            res += 1/lettercount(word,word[i]);
        }
        if (word[i]=='r'){
            res += 6/lettercount(word,word[i]);
        }
        if (word[i]=='s'){
            res += 8/lettercount(word,word[i]);
        }
        if (word[i]=='t'){
            res += 7/lettercount(word,word[i]);
        }
        if (word[i]=='u'){
            res += 6/lettercount(word,word[i]);
        }
        if (word[i]=='v'){
            res += 2/lettercount(word,word[i]);
        }
    
        
    }
    return res;
}
struct pos nvpossibles(char* guess, char* hint,struct pos base){
    struct pos res;
    res.possibles = malloc(6145*sizeof(int));
    res.size =0;
    char buffer[256];
    for (int i =0;i<base.size;i++){
        readnthline("dicotrie.txt",base.possibles[i],buffer);
        int ok = 1;
        strcpy (buffer,remove_accents(buffer));
        for (int j =0;j<5;j++){
            
        if (hint[j] == 'x'){
            if (!(veriflettre(guess[j],buffer))){
                ok =0;
            }}
        else if (hint[j]=='X'){
            if (!(guess[j]==buffer[j])){
                ok=0;
            }
        }
        else {
            if (veriflettre(guess[j],buffer)){
                ok=0;}
        }
        
        }
        if ((ok==1) && !(strcmp(guess,buffer)==0)){
        res.possibles[res.size]=base.possibles[i];
        res.size++;
        //printf("%s (%d) \n",buffer,freqscore(buffer));
        }
        
        }

    
    return res;
}


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

void meilleurmot(struct pos base){
    int n = base.size;
    /*char nvbuffer[5];
    for (int k =0;k<base.size;k++){
        readnthline("dicotrie.txt",base.possibles[k],nvbuffer);
        printf("%s, ",nvbuffer);}*/
    char bufferi[10];
    char bufferj[10];
    int vec[n];
    for (int i = 0; i<n;i++){
        int maxi = 1;
        readnthline("dicotrie.txt",base.possibles[i],bufferi);
        //printf("%s \n ",bufferi);
        for (int j =0; j <n;j++){
            readnthline("dicotrie.txt",base.possibles[j],bufferj);
            //printf("%s, ",bufferj);

            char* indice = hint(bufferi,bufferj);
            struct pos alors = nvpossibles(bufferi,indice,base);
            if (alors.size>maxi){
                vec[i] = maxi;
                maxi = alors.size;
            }
        }
    }
    char* bw;
    int mini = 1000;
    int res = 0;
    for(int k =0;k<n;k++){
        if (vec[k]<mini){
            res =k;
            mini = vec[k];
        }
    }
    readnthline("dicotrie.txt",base.possibles[res],bufferi);
    printf("IA : %s\n",bufferi);
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