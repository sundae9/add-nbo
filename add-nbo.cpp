#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char* argv[])
{
    FILE *file1;
    FILE *file2;

    file1=fopen(argv[1],"rb");
    file2=fopen(argv[2],"rb");

    if(file1 == NULL|| file2 == NULL){
        fputs("File error", stderr);
        exit(1);
    }

    uint32_t data1;
    uint32_t data2;

    fread(&data1,4,1,file1);
    fread(&data2,4,1,file2);

    data1=ntohl(data1);
    data2=ntohl(data2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",data1,data1,data2,data2,data1+data2,data1+data2);
    return 0;
}
