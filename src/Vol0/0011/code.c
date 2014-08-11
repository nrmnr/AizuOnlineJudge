#include <stdio.h>

int a,b,w,r[99],*p=r+1;
int main(){
  for(scanf("%d%*d",&w);w--;r[w+1]=w+1);
  for(;~scanf("%d,%d",&a,&b);r[a]^=r[b]^=r[a]^=r[b]);
  for(;*p;printf("%d\n",*p++));
  return 0;
}
