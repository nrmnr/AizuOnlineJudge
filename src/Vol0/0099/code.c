#include <stdio.h>
#include <limits.h>

#define N (1<<20)

int st[N*2]; // segment tree
int dt_n, st_n;

int max(int x, int y){ return (x > y)? x : y; }

void restruct(int i)
{
  while(i>0){
    i=(i-1)/2;
    st[i] = max(st[i*2+1], st[i*2+2]);
  }
}

void set(int a, int v)
{
  int i = st_n + a - 1;
  st[i] = v;
  restruct(i);
}

void add(int a, int v)
{
  int i = st_n + a - 1;
  st[i] += v;
  restruct(i);
}

void init()
{
  int i;
  for(st_n=1;st_n<dt_n;st_n*=2);
  for(i=0;i<st_n*2-1;++i) st[i] = INT_MIN;
  for(i=0;i<dt_n;++i) set(i,0);
}

int get_id()
{
  int i=1, j=2;
  for(;;j=i+1){
    if(st[i] >= st[j]){
      if(i >= st_n-1) return i-st_n+1;
      i = 2*i+1;
    } else {
      if(j >= st_n-1) return j-st_n+1;
      i = 2*j+1;
    }
  }
}

int main()
{
  int q,a,v;
  scanf("%d%d",&dt_n,&q);
  init();
  for(0;q-->0;){
    scanf("%d%d",&a,&v);
    add(a-1,v);
    printf("%d %d\n", get_id()+1, st[0]);
  }
  return 0;
}
