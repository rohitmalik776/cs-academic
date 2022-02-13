#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/mman.h>

int main(){
    const int SIZE = 4096;
    const char *name = "my_route";
    int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    printf("%d\n", shm_fd);
    ftruncate(shm_fd, SIZE);
    void *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    const char *message = "hello world";
    char input[100];
    while(input[0] != 'q'){
        gets(input);
        sprintf(ptr, "%s", input);
        // ptr += strlen(input);
    }
    return 0;
}