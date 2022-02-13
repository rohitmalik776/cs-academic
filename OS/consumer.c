#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/mman.h>

int min(int a, int b){
    return (a > b) ? b: a;
}

int isEqual(char *a, char *b){
    if(a == NULL || b == NULL)
        return 1;
    for(int i=0; i<min(strlen(a), strlen(b)); i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    const int SIZE = 4096;
    const char *name = "my_route";
    int shm_fd = shm_open(name, O_RDONLY, 0666);

    while(1){
        void *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
        printf("%s\n", (char*) ptr);
        sleep(1);
        // shm_unlink(name);
    }
    return 0;
}