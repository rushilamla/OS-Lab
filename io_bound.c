#include<stdio.h>
int main(){
    FILE *fp=fopen("file.txt","w");
    int i=0;
    while(i<=1000){
        fprintf(fp,"Hello World\n");
        i++;
    }
    fclose(fp);
    return 0;
}