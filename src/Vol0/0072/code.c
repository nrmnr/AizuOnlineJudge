#include <stdio.h>
#include <limits.h>
int g[100][100];
int lantern(int n){
  int i,j,amount,count,td,min_d,min_p,sel[100];
  for(i=1;i<100;++i) sel[i]=0;
  for(sel[0]=1,count=1,amount=0;count<n;){
    min_d=INT_MAX;
    min_p=-1;
    for(i=0;i<n;++i){
      if(sel[i]==0) continue;
      for(j=0;j<n;++j){
        if(i==j||sel[j]==1) continue;
        td=g[i][j];
        if(td<min_d){
          min_d=td;
          min_p=j;
        }
      }
    }
    sel[min_p]=1;
    amount+=(min_d-1);
    count++;
  }
  return amount;
}
int main(){
  int n,m,a,b,d,i,j;
  for(;scanf("%d%d",&n,&m),n;){
    for(i=0;i<n;++i){
      for(j=0;j<n;++j)
        g[i][j]=i==j?0:INT_MAX;
    }
    for(i=0;i<m;++i){
      scanf("%d,%d,%d\n",&a,&b,&d);
      g[a][b]=g[b][a]=d/100;
    }
    printf("%d\n",lantern(n));
  }
  return 0;
}
