#include <stdio.h>

int main()
{
    FILE* fp;
    fp=fopen("a.bin", "wb+");
    int a[]={0,1,2};
    char b[]="ABC";
    float c[]={1.1,1.2,1.3};
    fwrite(a,sizeof(int),sizeof(a)/sizeof(int),fp);
    fwrite(b,sizeof(char),sizeof(b)/sizeof(char),fp);
    fwrite(c,sizeof(float),sizeof(c)/sizeof(float),fp);
    fclose(fp);
    fp=fopen("a.bin", "rb");
    int reada[5];
    char readb[5];
    float readc[5];
    fread(reada,sizeof(int),sizeof(reada)/sizeof(int),fp);
    fread(readb,sizeof(char),sizeof(readb)/sizeof(char),fp);
    fread(readc,sizeof(float),sizeof(readc)/sizeof(float),fp);
    fclose(fp);
    for(int i=0;i<3;i++){
        printf("%d ",reada[i]);
    }
    printf("\n");
       for(int i=0;i<3;i++){
        printf("%c ",readb[i]);
    }
    printf("\n");
       for(int i=0;i<3;i++){
        printf("%lf ",readc[i]);
    }
    printf("\n");
    return 0;
}
