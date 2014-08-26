#include <stdio.h>

int main()
{
  int y,ye,c,dc;
  for(dc=0;scanf("%d%d",&y,&ye) && (y || ye);++dc){
    if(dc) puts("");
    if(y%4) y=(y/4+1)*4;
    for(c=0;y<=ye;y+=4){
      if(y%400==0 || y%100!=0){
        printf("%d\n",y);
        ++c;
      }
    }
    if(!c) puts("NA");
  }
  return 0;
}
