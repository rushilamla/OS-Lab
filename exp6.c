#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
	size_t bytes_to_allocate=atol(argv[1])*1024*1024;
	void *mem=malloc(bytes_to_allocate);
	memset(mem,0,bytes_to_allocate);
	printf("%ld mb of memory allocated\n",atol(argv[1]));
	char r;
	printf("press any key to free the memory\n");
	getchar();
	free(mem);
	printf("Memory freed\n");
	return 0;
}

