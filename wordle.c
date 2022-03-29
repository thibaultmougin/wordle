#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


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
    printf("Ecrivez votre mot de 5 lettres: \n");


    while (!(win)){
    scanf("%19s", s);
    int lon = len(s);
    if (lon!=5){
        printf("Votre mot ne fait pas 5 lettres\n");
        continue;
    }

    n++;
    printf("%d",n);}

    return 0;
}