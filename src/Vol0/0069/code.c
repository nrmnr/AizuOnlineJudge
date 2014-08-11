#include <stdio.h>
#include <string.h>

int n,m,r,d,i,j;
char b[30][10],s[32];
int min(char a,char b){ return a<b?a:b; }
void lot(){
  int mn,mx,tr,tm;
  for(tr=r,i=d;i-->0;){
    for(j=1;j<n;++j)
      if(b[i][j]&&(j==tr||j+1==tr)) tr=j+j+1-tr;
  }
  if(tr==m){ printf("0\n"); return; }
  for(tm=m,i=0;i<d;++i){
    mn=min(tm,tr); mx=tm+tr-mn;
    if(mx-mn==1 && !b[i][mn] && !b[i][mn-1] && !b[i][mx]){
      printf("%d %d\n",i+1,mn); return;
    }
    for(j=1;j<n;++j)
      if(b[i][j]){
        if(j==tr||j+1==tr) tr=j+j+1-tr;
        if(j==tm||j+1==tm) tm=j+j+1-tm;
      }
  }
  printf("1\n");
}
int main(){
  for(;;){
    scanf("%d%d%d%d",&n,&m,&r,&d);
    if(!n) return 0;
    for(i=0;i<d;++i){
      scanf("%s\n",s);
      memset((void*)b[i],0,10);
      for(j=1;j<n;++j)
        b[i][j]=s[j-1]-'0';
    }
    lot();
  }
}
