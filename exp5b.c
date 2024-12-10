#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 128

int main(int argc, char **argv){
    if (argc < 3){
        printf("Usage: %s <start> <end> <string>", argv[0]);
        return 0;
    }
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    char str[BUFSIZE+1];
    for (int i=3; i< argc; i++){
        strlcat(str, argv[i], BUFSIZE);
    }
    printf("Substring =  ");
    int len = 0;
    while (start <= end){
        putchar(str[ start++  ]);
        len++;
    }
    putchar('\n');
    printf("Length of Substring = %d\n", len);
    return 0;
}
