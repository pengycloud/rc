#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
    if (argc<3){
        return 1;
    }
    char *buf,s[256],*key;
    size_t sz;

    FILE *f = fopen(argv[1],"rb");
    if (f == NULL) return 1;
    fseek(f,0,SEEK_END);
    sz = ftell(f);
    if (sz == 0) {
        fclose(f);
        return 1;
    }
    rewind(f);
    buf = malloc(sz);
    if (!fread(buf,sz,1,f)){
        fclose(f);
        return 1;
    }
    fclose(f);
    void swap(char *a,char *b){
        char c = *a;
        *a = *b;
        *b = c;
    }
    void rc4(unsigned char *s,unsigned char *key){
        for (int i=0;i<256;i++) s[i] = i;
        int j = 0;
        int len = strlen(key);

        for (int i=0;i<256;i++){
            j = (j+i+key[i%len])%256;
            swap(&s[i],&s[j]);
        }
        int i = 0;
        int t;
        j = 0;

        for (int k=0;k<sz;k++){
            i = (i+1)%256;
            j = (j+s[i])%256;
            swap(&s[i],&s[j]);
            t = (s[i]+s[j])%256;
            buf[k] ^= s[t];
        }
    }
    rc4(s,argv[2]);
    FILE *frc = fopen(argv[1],"wb");
    if (frc == NULL) return 1;
    if (!fwrite(buf,sz,1,frc)){
        fclose(frc);
        return 1;
    }
    fclose(frc);
    return 0;    
}