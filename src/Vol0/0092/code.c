#include <stdio.h>
#include <stdlib.h>

int cells[1001][1001];

int min(int x, int y)
{
  return (x < y)? x : y;
}

int min3(int x, int y, int z)
{
  return min(min(x, y), z);
}

int main()
{
  int i,j,n,s;
  char line[1002];
  for(;scanf("%d\n", &n) && n;){
    s = 0;
    for(i=1; i<=n; ++i){
      fgets(line, 1001, stdin);
      for(j=1; j<=n; ++j){
        cells[i][j] = (line[j-1] == '.')? min3(cells[i-1][j-1], cells[i-1][j], cells[i][j-1]) + 1 : 0;
        if(s < cells[i][j]) s = cells[i][j];
      }
    }
    printf("%d\n", s);
  }
  return 0;
}
