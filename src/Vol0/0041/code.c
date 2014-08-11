#include <stdio.h>

int permulations[][4] = {
  {0,1,2,3}, {0,1,3,2}, {0,2,1,3}, {0,2,3,1}, {0,3,1,2}, {0,3,2,1},
  {1,0,2,3}, {1,0,3,2}, {1,2,0,3}, {1,2,3,0}, {1,3,0,2}, {1,3,2,0},
  {2,0,1,3}, {2,0,3,1}, {2,1,0,3}, {2,1,3,0}, {2,3,0,1}, {2,3,1,0},
  {3,0,1,2}, {3,0,2,1}, {3,1,0,2}, {3,1,2,0}, {3,2,0,1}, {3,2,1,0},
};
int PE_N = 24;

char ops[] = "+-*";
int OP_N = 3;

int calc(int dl, int dr, int op){
  switch (op){
  case 0: return dl + dr;
  case 1: return dl - dr;
  case 2: return dl * dr;
  default: return 0;
  }
}

int detect(int digits[], char *expr){
  int pe, d[4], op1, op2, op3, i;
  for (pe = 0; pe < PE_N; ++pe){
    for (i = 0; i < 4; ++i){
      d[i] = digits[permulations[pe][i]];
    }
    for (op1 = 0; op1 < OP_N; ++op1){
      for (op2 = 0; op2 < OP_N; ++op2){
        for (op3 = 0; op3 < OP_N; ++op3){
          if (calc(calc(calc(d[0], d[1], op1), d[2], op2), d[3], op3) == 10){
            sprintf(expr, "(((%d %c %d) %c %d) %c %d)", d[0], ops[op1], d[1], ops[op2], d[2], ops[op3], d[3]);
            return 1;
          } else if(calc(calc(d[0], calc(d[1], d[2], op2), op1), d[3], op3) == 10){
            sprintf(expr, "((%d %c (%d %c %d)) %c %d)", d[0], ops[op1], d[1], ops[op2], d[2], ops[op3], d[3]);
            return 1;
          } else if (calc(calc(d[0], d[1], op1), calc(d[2], d[3], op3), op2) == 10){
            sprintf(expr, "((%d %c %d) %c (%d %c %d))", d[0], ops[op1], d[1], ops[op2], d[2], ops[op3], d[3]);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

int main(){
  int i,d[4];
  char e[32];
  for(;scanf("%d%d%d%d",d,d+1,d+2,d+3),*d+d[1]+d[2]+d[3];puts(detect(d,e)?e:"0"));
  return 0;
}
