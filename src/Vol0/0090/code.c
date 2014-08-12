#include <stdio.h>
#include <math.h>

char over[100][100];
typedef struct {
  double x;
  double y;
} Point;
Point points[100];

double dist(const Point *p1, const Point *p2)
{
  double dx = p1->x - p2->x, dy = p1->y - p2->y;
  return sqrt(dx*dx + dy*dy);
}
int main()
{
  int n,i,j;
  for(;;){
    scanf("%d", &n);
    if(n == 0) break;

    for(i=0; i<100; ++i)
      for(j=0; j<100; ++j)
        over[i][j] = (i==j)?1:0;

    for(i=0; i<n; ++i){
      scanf("%lf,%lf", &points[i].x, &points[i].y);
      for(j=0; j<i; ++j){
        double d = dist(&points[i], &points[j]);
        over[i][j] = over[j][i] = (d <=2.0)? 1 : 0;
      }
    }

    for(i=0; i<n; ++i){
      for(j=0; j<n; ++j){
        fprintf(stderr, " %d", over[i][j]);
      }
      fprintf(stderr, "\n");
    }
  }
  return 0;
}
