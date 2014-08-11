#include <stdio.h>
#include <math.h>

double p[8];
double d(int i, int j){
  return hypot(p[i]-p[j],p[i+1]-p[j+1]);
}
double r(int i, int j, int k){
  double a=d(i,j),b=d(j,k),c=d(k,i),s=(a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}
int h(){
  return r(6,0,2)+r(6,2,4)+r(6,4,0)-r(0,2,4)<1e-8;
}
int main(){
  int i;
  for(i=0; ~scanf("%lf",p+i); i==7 && printf(h()?"YES\n":"NO\n"), i=++i%8);
  return 0;
}
