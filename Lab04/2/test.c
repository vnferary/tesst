#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
 
int8_t read_buf[1024];
int8_t write_buf[1024]="Lab04 - Bai 2 - Hoang Van Thai\n";
int main()
{
    int fd;
 
	//mo file thiet bi
        fd = open("/dev/lab42", O_RDWR);

        if(fd < 0) {
                printf("Can't open file...\n");
                return 0;
        }
 
	write(fd, write_buf, strlen(write_buf)+1);

	read(fd, read_buf, 1024);

	printf("Data = %s", read_buf);

	close(fd);
}
