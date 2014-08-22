#include <stdio.h>
#include <math.h>

typedef struct {
  double x;
  double y;
} Point;
Point pts[100];
Point cs_pts[9900];

double sq(double x)
{
  return x * x;
}

double dist(const Point *p1, const Point *p2)
{
  return sqrt(sq(p1->x - p2->x) + sq(p1->y - p2->y));
}

int main()
{
  int n,i,j,cs_count,ans,count;
  double d,theta,amp,x,y;
  for(;scanf("%d", &n) && n;){
    for(i=0; i<n; ++i){
      scanf("%lf,%lf", &pts[i].x, &pts[i].y);
    }

    cs_count = 0;
    for(i=0; i<n-1; ++i){
      for(j=i+1; j<n; ++j){
        d = dist(&pts[i], &pts[j]);
        if(d > 2.0) continue;
        theta = acos(d/2.0);
        amp = atan2(pts[j].y - pts[i].y, pts[j].x - pts[i].x);
        x = pts[i].x; y = pts[i].y;
        cs_pts[cs_count].x = x + cos(theta + amp);
        cs_pts[cs_count].y = y + sin(theta + amp);
        cs_count++;
        if(d == 0.0) continue;
        cs_pts[cs_count].x = x + cos(theta - amp);
        cs_pts[cs_count].y = y + sin(theta - amp);
        cs_count++;
      }
    }

    ans = 1;
    for(i=0; i<cs_count; ++i){
      count = 0;
      for(j=0; j<n; ++j){
        if(dist(&cs_pts[i], &pts[j]) <= 1.0) count++;
      }
      ans = (ans > count)? ans : count;
    }
    printf("%d\n", ans);
  }
  return 0;
}
