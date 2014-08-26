#include <stdio.h>

int main()
{
  int n,a,v,ma=1,mv=-1;
  scanf("%d",&n);
  for(;n-->0;){
    scanf("%d%d",&a,&v);
    if(mv<v || (mv==v && a<ma)){
      ma = a;
      mv = v;
    }
  }
  printf("%d %d\n",ma,mv);
  return 0;
}
