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
    FILE *fp1;
    fp = fopen(argv[1], "r");
    fp1 = fopen("file3_output.txt", "w");
    fclose(fp1);
    fp1 = fopen("file3_output.txt", "a");

    int sizeOfBuffer = atoi(argv[2]);
    char buf[sizeOfBuffer];

    while(fread(&buf, sizeof(buf), 1, fp))
    {
        //printf("Writing buffer of size %d into file3_output.txt. \n", sizeOfBuffer);
        fwrite(buf, strlen(buf), 1, fp1); //strlen(buf)
    }

    fclose(fp);
    fclose(fp1);

    return 0;
}