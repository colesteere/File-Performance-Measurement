#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <pthread.h>

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        fprintf(stderr, "Usage %s <file2.txt> <Size of buffer N> \n", argv[0]);
        return 1;
    }

    FILE *fp;
    fp = fopen(argv[1], "r");

    int sizeOfBuffer = atoi(argv[2]);
    char buf[sizeOfBuffer];

    while(fread(&buf, sizeof(buf), 1, fp))
    {
        //printf("Reading buffer of size %d... \n", sizeOfBuffer);
    }

    fclose(fp);

    return 0;
}