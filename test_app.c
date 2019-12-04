#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAX_SIZE 	1000
int main(void){
	int fd;

	char* buf_in = (char*)malloc(sizeof(char)*MAX_SIZE);
	char* buf_out = (char*)malloc(sizeof(char)*MAX_SIZE);
	if( (fd=open("/dev/mydevicefile", O_RDWR))<0 ){
		perror("open error");
		return -1;
	}
	strcpy(buf_out,"aaaaaaaaaaBBBBBBBBBBccccccccccDDDDDDDDDDeeeeeeeeeeFFFFFFFFFFggggggggggHHHHHHHHHHiiiiiiiiiiJJJJJJJJJJkkkkkkkkkkLLLLLLLLLLmmmmmmmmmmNNNNNNNNNNooooooooooPPPPPPPPPPqqqqqqqqqqRRRRRRRRRRssssssssssTTTTTTTTTTuuuuuuuuuuVVVVVVVVVVwwwwwwwwwwXXXXXXXXXXyyyyyyyyyyZZZZZZZZZZ");
	write(fd, buf_out, MAX_SIZE);
	read(fd, buf_in, MAX_SIZE);
	
	printf("%s\n,",buf_in);

	
	free(buf_in);
	free(buf_out);


	close(fd);
	return 0;
}
