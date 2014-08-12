#include <stdlib.h>
char s[99],*p=s,h,f;double r[80];
int d(c){return '0'<=c&&c<='9'||c=='.';}
int b(c){return c==32||c==10||c==13;}
int main(){
  int c;
  for(;~(c=getchar());){
    if(b(c)){
      *p=0;p=s;
      if(d(*s))
        r[h++]=atof(s);
      else{
        h--;
        if(*s=='+')r[h-1]+=r[h];
        if(*s=='-')r[h-1]-=r[h];
        if(*s=='*')r[h-1]*=r[h];
        if(*s=='/')r[h-1]/=r[h];
      }
      if(c!=32)
        printf("%lf\n",*r),h=f=0;
    }else
      *p++=c,f=1;
  }
  if(f)printf("%lf\n",*r);
  return 0;
}
