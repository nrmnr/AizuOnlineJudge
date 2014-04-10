#include <stdio.h>
#include <math.h>

float g(float *x, float *y){
  int i;
  float a, b;
  for (a=b=0, i=3; i--; x++, y++){
    a += 2 * *x * (y[2] - y[1]);
    b += (pow(x[2],2) - *x * *x) * y[1] - (y[2] - *y) * y[2] * *y;
  }
  return b/a;
}
int main(){
  int i, n;
  float X, Y, x[5], y[5];
  for (scanf("%d",&n); n--;){
    for (i=3; i--;) scanf("%f%f", x+i, y+i);
    x[3] = *x; x[4] = x[1];
    y[3] = *y; y[4] = y[1];
    X = g(x,y);
    Y = g(y,x);
    printf("%.3f %.3f %.3f\n", X, Y, hypot(X-*x,Y-*y));
  }
  return 0;
}
