#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* binToGray(char* binary){
    int binary_size=strlen(binary);
    char* gray=malloc(sizeof(char)*binary_size);
    gray[0]=binary[0];
   
    for(int i=1; i<binary_size;i++){
        int prev=binary[i-1]-'0';
        int next=binary[i]-'0';
        int sum;
        if(prev==1 && next==1){
            sum=0+'0';
        }
        else{
            sum=(prev+next)+'0';
        }
        gray[i]=sum;
    }
    return gray;
}

char* grayToBin(char* gray){
    int gray_size=strlen(gray);
    char* binary=malloc(sizeof(char)*gray_size);
    binary[0]=gray[0];
   
    for(int i=1; i<gray_size;i++){
        int prev=binary[i-1]-'0';
        int next=gray[i]-'0';
        int sum;
        if(prev==1 && next==1){
            sum=0+'0';
        }
        else{
            sum=(prev+next)+'0';
        }
        binary[i]=sum;
    }
    return binary;
}

int main(int argc,char** argv){
    char* binary=argv[1];
    char* gray=binToGray(binary);
    char* binary_2=grayToBin(gray);

    printf("Binary : %s \n",binary);
    printf("Gray : %s\n",gray);
    printf("Binary : %s \n",binary_2);
    return 0;
}