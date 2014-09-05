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
    // todo
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
