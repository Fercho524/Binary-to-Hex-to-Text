#include "lib.h"

void writeRowinFile(char* path,char* text,char* bin,char* hex){
  FILE *db=NULL;
  db=fopen(path,"a");
  int ascii_code=ascii(text[0]);

  if(db==NULL){
    fprintf(stderr,"Cannot open the file");
  }
  fprintf(db,"| %s | %s | %s | %d |\n",text,bin,hex,ascii_code);
  fclose(db);
}

void init(int argc, char **argv){
    char *input=argv[1];
    char *bin=stringToBinary(input);
    char *hex=binToHexadecimal(bin);
    writeRowinFile("db.txt",input,bin,hex);
}