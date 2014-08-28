#include <stdio.h>

#define N 1000001

struct TAG {
  int num;
  int val;
  struct TAG *next;
};
struct TAG dp[N];

void ins(int a, int v)
{
  dp[a].val += v;
  if(!dp->next){
    dp->next = &dp[a];
    return;
  }

  struct TAG *t;

  for(t=dp;t->next;t=t->next){
    if(a == t->next->num){
      t->next = t->next->next;
      break;
    }
  }

  int val;
  for(t=dp;t->next;t=t->next){
    val = t->next->val;
    if(dp[a].val > val || (dp[a].val == val && a < t->next->num)){
      dp[a].next = t->next;
      t->next = &dp[a];
      return;
    }
  }
  t->next = &dp[a];
  dp[a].next = NULL;
}

int main()
{
  int n,q,a,v,i;
  for(i=0;i<N;++i) dp[i].num = i;
  scanf("%d%d",&n,&q);
  for(i=0;i<q;++i){
    scanf("%d%d",&a,&v);
    ins(a,v);
    printf("%d %d\n", dp->next->num, dp->next->val);
  }
  return 0;
}
