#include <iostream>
#include <string>
#include <strstream>
using namespace std;

struct Point
{
  int pos[3];

  string to_s() const
  {
    strstream out;
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
    strstream out;
    out << points[0].to_s() << " - " << points[1].to_s() << " - " << points[2].to_s();
    return out.str();
  }

  void rebase(const Point& base)
  {
    for (int i = 0; i < 3; ++i) this->points[i] = this->points[i] - base;
  }

  bool hit(const Point& target)
  {
    // todo
    return true;
  }
};

Point get_point()
{
  Point p;
  for (int i = 0; i < 3; ++i) cin >> p.pos[i];
  return p;
}

Triangle get_triangle()
{
  Triangle tri;
  for (int i = 0; i < 3; ++i) {
    tri.points[i] = get_point();
  }
  return tri;
}

int main()
{
  Point uaz = get_point();
  Point enemy = get_point();
  Triangle barrier = get_triangle();
  Point beam = enemy - uaz;
  barrier.rebase(uaz);
  cout << (barrier.hit(beam)? "MISS":"HIT") << endl;
  return 0;
}
