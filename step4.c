#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <pthread.h>

#define N 64

pthread_t threads[N];
int bufferSize;
char file[9];
FILE *fp;

void *copyFile(void *args)
{
    //printf("Thread Number: %d \n", (int) (size_t) args);
    FILE *fp1;

    char buff[0x100];
    snprintf(buff, sizeof(buff), "file%d_output.txt", (int) (size_t) args);

//    printf("Opening files... \n");

    fp1 = fopen(buff, "w");
    fclose(fp1);
    fp1 = fopen(buff, "a");

    int sizeOfBuffer = bufferSize;
    char buf[sizeOfBuffer];

//    printf("Opened files. Buffer Size: %d \n", sizeOfBuffer);

    while(fread(&buf, sizeof(buf), 1, fp))
    {
//        printf("Reading files... \n");
        fwrite(buf, strlen(buf), 1, fp1);
    }

    fclose(fp1);
//    printf("Exiting from thread. \n");
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage %s <testingFile> <buffer size> <Number of Threads> \n", argv[0]);
        return 1;
    }
//    FILE *fp;
    fp = fopen(argv[1], "r");

    bufferSize = atoi(argv[2]);
    strncpy(file, argv[1], sizeof(argv[1]));

//    printf("Creating Threads... \n");
    int i;
    for(i = 0; i < atoi(argv[3]); i++)
    {
        pthread_create(&threads[i], NULL, copyFile, (void *)(size_t) i);
    }

    for(i = 0; i < atoi(argv[3]); i++)
    {
        pthread_join(threads[i], NULL);
    }
//    printf("Finished joining all threads. \n");

    fclose(fp);

    return 0;
}