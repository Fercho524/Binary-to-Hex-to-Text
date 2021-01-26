#include "lib.h"

void writeRowinFile(char *path, char *text, char *bin, char *hex)
{
  FILE *db = NULL;
  db = fopen(path, "a+");
  int size = strlen(text);
  int ascii_code = ascii(text[0]);

  if (db == NULL)
  {
    fprintf(stderr, "Cannot open the file\n");
  }
  fprintf(db, "| len | text | binary | hexadecimal | ascii code of 1st character |\n");
  fprintf(db, "|>%d<| %s | %s | %s | %d |\n", size, text, bin, hex, ascii_code);
  fclose(db);
}

void init(int argc, char **argv)
{
  for (int i = 1; i < argc; i++)
  {
    char *input = argv[i];
    char *bin = stringToBinary(input);
    char *hex = binToHexadecimal(bin);
    writeRowinFile("db.dat",input,bin,hex);
  }
}

void getFileLine(int strSize,char *path, char *text, char *bin, char *hex)
{
  FILE *db = NULL;
  db = fopen("db.txt", "r+");
  int size = strlen(text);
  int ascii_code = ascii(text[0]);
  char *buffer = (char *)malloc(sizeof(char) * 1024);
  if (db == NULL || buffer == NULL)
  {
    puts("No es posible continuar por un error en el archivo o en la memoria dinamica");
    exit(1);
  }
  int line;
  int lineCount=0;
  while(fgets(buffer,sizeof(char)*1024,db)!=NULL){
    if(line==strSize){
      fprintf(db, "| len | text | binary | hexadecimal | ascii code of 1st character |\n");
      fprintf(db, "|>%d<| %s | %s | %s | %d |\n", size, text, bin, hex, ascii_code);
    }
    fscanf(db,"|>%d<|",&line);
    printf("%s y su linea es: %d",buffer,line);
	}
  fclose(db);
}

