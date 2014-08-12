#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CODE {
  char c;
  char code[9];
} codes[] = {
  { ' ', "101"      }, { '\'',"000000"   }, { ',', "000011"   }, { '-', "10010001" },
  { '.', "010001"   }, { '?', "000001"   }, { 'A', "100101"   }, { 'B', "10011010" },
  { 'C', "0101"     }, { 'D', "0001"     }, { 'E', "110"      }, { 'F', "01001"    },
  { 'G', "10011011" }, { 'H', "010000"   }, { 'I', "0111"     }, { 'J', "10011000" },
  { 'K', "0110"     }, { 'L', "00100"    }, { 'M', "10011001" }, { 'N', "10011110" },
  { 'O', "00101"    }, { 'P', "111"      }, { 'Q', "10011111" }, { 'R', "1000"     },
  { 'S', "00110"    }, { 'T', "00111"    }, { 'U', "10011100" }, { 'V', "10011101" },
  { 'W', "000010"   }, { 'X', "10010010" }, { 'Y', "10010011" }, { 'Z', "10010000" },
};
int CN = sizeof(codes) / sizeof(codes[0]);

char *table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";

char *find(char c){
  int i;
  for(i = 0; i < CN; ++i){
    if(codes[i].c == c) return codes[i].code;
  }
  return 0;
}

void output(char *code){
  int n = strtol(code, NULL, 2);
  putchar(table[n]);
}

int main()
{
  char c, stack[99],*sp=stack;
  int i,j,l;
  for(;;){
    c = getchar();
    if(c == EOF || c == '\n'){
      if((l = strlen(stack))>0){
        for(;l<5;++l){
          stack[l] = '0';
        }
        stack[l] = '\0';
        output(stack);
      }
      if(c == EOF) break;
      puts("");
      sp = stack;
      *sp = '\0';
      continue;
    }
    char *code = find(c);
    strcpy(sp, code);
    sp = sp + strlen(code);
    for(i=0, l=strlen(stack); l-i >= 5; i+=5){
      char tmpcode[6];
      strncpy(tmpcode, stack+i, 5);
      tmpcode[5] = '\0';
      output(tmpcode);
    }
    if(i > 0){
      for(j=0;stack[i];++i,++j){
        stack[j] = stack[i];
      }
      stack[j] = '\0';
      sp = stack + j;
    }
  }
  return 0;
}
