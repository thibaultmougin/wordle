#include <stdio.h>
#include <stdlib.h>

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