#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SHORT 440
#define LONG 1280
#define MARGIN 150
#define INTRO 3500
#define INTRO2 1750
#define SEPARATOR 9880


char decode(int val1, int val2){
  if (abs(val1 - INTRO) < MARGIN && abs(val2 - INTRO2) < MARGIN)
    return '[';
  if (abs(val1 - SHORT) < MARGIN && abs(val2 - SHORT) < MARGIN)
    return '0';
  if (abs(val1 - SHORT) < MARGIN && abs(val2 - LONG) < MARGIN)
    return '1';
  if (abs(val1 - SHORT) < MARGIN && abs(val2 - SEPARATOR) < MARGIN)
    return ']'; 
}

int abs(int val){
  if (val < 0)
    return -val;
  else
    return val;
}

int main(int argc, char** argv){
  if (argc < 3){
    printf("usage = %s fileName output\n", argv[0]);
    exit(0);
  }
  int val1, val2;
  char delims[] = " ";
  char *result = NULL;
  FILE* f = fopen(argv[1],"r");
  FILE* out = fopen(argv[2],"w");
  char line[256];
  int index = 0;
  char* nIndex = 0;
  while (fgets(line, 256, f) != NULL){
    result = strtok( line, delims );
    index = 0;
    while( result != NULL ) {
      //printf( "result[%d] is \"%s\"\n", index, result );
      if (index & 1){
        if (nIndex = strchr(result,'\n')){
          //printf("New line detected in result\n");
          *nIndex = '\0';
        }
        val2 = atoi(result);
        char dec = decode(val1,val2);
        fprintf(out,"%c",dec);
      }else{
        val1 = atoi(result);
      }
      result = strtok( NULL, delims );
      index++;
    }
      //printf (line);
  }
  fprintf(out, "]\n");
  fclose(f);
  fclose(out);
}

