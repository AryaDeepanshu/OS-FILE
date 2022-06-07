#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* fp;
    char ch;
    fp = fopen("file.txt", "r");
    if (fp == NULL){
        printf("Unable to open file ");
        return 0;
    }
    do{
        ch=getc(fp);
        printf("%c",ch);
    }
    while(ch !=EOF);
    fclose(fp);
    printf("\n");
    return 0;
}