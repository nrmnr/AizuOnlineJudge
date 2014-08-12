#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
  char token[99];
  double stack[99];
  int sp = 0;
  for(;;){
    if(scanf("%s",token)==-1) break;
    if(strcmp(token, "+") == 0){
      sp--; stack[sp-1] += stack[sp];
    } else if(strcmp(token, "-") == 0){
      sp--; stack[sp-1] -= stack[sp];
    } else if(strcmp(token, "*") == 0){
      sp--; stack[sp-1] *= stack[sp];
    } else if(strcmp(token, "/") == 0){
      sp--; stack[sp-1] /= stack[sp];
    } else {
      stack[sp++] = atof(token);
    }
    if(getchar() == '\n'){
      printf("%f\n",stack[0]);
      sp = 0;
    }
  }
  return 0;
}
