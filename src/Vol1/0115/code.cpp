#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Point
{
  double pos[3];

  string to_s() const
  {
    ostringstream out;
    out << "(" << pos[0] << ", " << pos[1] << ", " << pos[2] << ")";
    return out.str();
  }

  const Point operator - (const Point& dr) const
  {
    Point ret;
    for (int i = 0; i < 3; ++i) ret.pos[i] = this->pos[i] - dr.pos[i];
    return ret;
  }
};

struct Triangle
{
  Point points[3];

  string to_s() const
  {
    ostringstream out;
    out << points[0].to_s() << " - " << points[1].to_s() << " - " << points[2].to_s();
    return out.str();
  }

  void rebase(const Point& base)
  {
    for (int i = 0; i < 3; ++i) this->points[i] = this->points[i] - base;
  }

  bool hit(const Point& target)
  {
    int i, j;
    double m[3][3], a[3];
    for (i = 0; i < 3; ++i) {
      a[i] = target.pos[i];
      for (j = 0; j < 3; ++j)
        m[i][j] = points[j].pos[i];
    }
    double det
      = m[0][0]*m[1][1]*m[2][2] + m[1][0]*m[2][1]*m[0][2] + m[2][0]*m[0][1]*m[1][2]
      - m[0][0]*m[2][1]*m[1][2] - m[2][0]*m[1][1]*m[0][2] - m[1][0]*m[0][1]*m[2][2];

    double md[3][3];
    md[0][0] = m[1][1]*m[2][2] - m[1][2]*m[2][1];
    md[0][1] = m[0][2]*m[2][1] - m[0][1]*m[2][2];
    md[0][2] = m[0][1]*m[1][2] - m[0][2]*m[1][1];

    md[1][0] = m[1][2]*m[2][0] - m[1][0]*m[2][2];
    md[1][1] = m[0][0]*m[2][2] - m[0][2]*m[2][0];
    md[1][2] = m[0][2]*m[1][0] - m[0][0]*m[1][2];

    md[2][0] = m[1][0]*m[2][1] - m[1][1]*m[2][0];
    md[2][1] = m[0][1]*m[2][0] - m[0][0]*m[2][1];
    md[2][2] = m[0][0]*m[1][1] - m[0][1]*m[1][0];

    for (i = 0; i < 3; ++i) for (j = 0; j < 3; ++j) md[i][j] /= det;
    double stu[3];
    for (i = 0; i < 3; ++i) {
      stu[i] = 0;
      for (j = 0; j < 3; ++j) {
        stu[i] += md[i][j] * a[j];
      }
    }

    if (stu[0] <= 0 || stu[1] <= 0 || stu[2] <= 0) return false;
    if (stu[0] + stu[1] + stu[2] < 1.0) return false;
    return true;
  }
};

Point load_point()
{
  Point p;
  for (int i = 0; i < 3; ++i) {
    int n;
    cin >> n;
    p.pos[i] = n;
  }
  return p;
}

Triangle load_triangle()
{
  Triangle tri;
  for (int i = 0; i < 3; ++i) {
    tri.points[i] = load_point();
  }
  return tri;
}

int main()
{
  Point uaz = load_point();
  Point enemy = load_point();
  Triangle barrier = load_triangle();
  Point beam = enemy - uaz;
  barrier.rebase(uaz);
  cout << (barrier.hit(beam)? "MISS":"HIT") << endl;
  return 0;
}
