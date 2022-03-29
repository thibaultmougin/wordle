#include <stdio.h>
#include <stdlib.h>

int len(char* s){
    int n=0;
    while (!(s[n]==0)){
        n++;
    }
    return n;
}

int main(int argc,char const *argv[]){
    char s[20];
    printf("Ecrivez votre mot de 5 lettres: ");
    scanf("%19s", s);
    printf("%d",len(s));
    return 0;
}