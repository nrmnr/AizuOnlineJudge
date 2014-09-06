#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

// #define DEBUG

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

  void show(double m[3][4])
  {
#ifdef DEBUG
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 4; ++j) {
        cerr << setw(5) << m[i][j];
      }
      cerr << endl;
    }
    cerr << "------------" << endl;
#endif
  }

  /** ガウスの掃き出し法による解法
   * @param m 方程式の係数行列 末尾成分は方程式の右辺
   */
  void gauss(double m[3][4])
  {
    show(m);
    int pivot; // 係数を1にしたい対角成分
    for (pivot = 0; pivot < 3; ++pivot) {
      // 誤差を少なくするため，pivot列成分の絶対値が大きな行を選択
      double max_p = 0;
      int swap = pivot;
      for (int i = pivot; i < 3; ++i) { // 既に処理した行が対象外
        if (fabs(m[i][pivot]) > max_p) {
          max_p = fabs(m[i][pivot]);
          swap = i;
        }
      }
      // 見つけた行をpivot行目にもってくる
      if (pivot != swap) {
        for (int j = 0; j < 4; ++j) {
          double t = m[pivot][j]; m[pivot][j] = m[swap][j]; m[swap][j] = t;
        }
      }
      // pivot行pivot列の成分を1にする(行全体に同じ係数を掛ける)
      double fact = m[pivot][pivot];
      for (int j = 0; j < 4; ++j) {
        m[pivot][j] /= fact;
      }
      // pivot行以外の行については，pivot列が0となるよう，
      // 係数を掛け，pivot行と足し合わせる
      for (int i = 0; i < 3; ++i) {
        if (i == pivot) continue;
        double fact = - m[i][pivot] / m[pivot][pivot];
        for (int j = 0; j < 4; ++j) {
          m[i][j] += m[pivot][j] * fact;
        }
      }
      show(m);
    }
  }

  bool hit(const Point& target)
  {
    int i, j;
    double m[3][4];
    for (i = 0; i < 3; ++i) {
      for (j = 0; j < 3; ++j) {
        m[i][j] = points[j].pos[i];
      }
      m[i][j] = target.pos[i];
    }
    gauss(m);
    if (m[0][3] <= 0 || m[1][3] <= 0 || m[2][3] <= 0) return false;
    if (m[0][3] + m[1][3] + m[2][3] < 1.0) return false;
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
