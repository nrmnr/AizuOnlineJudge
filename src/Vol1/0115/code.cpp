#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

#define DEBUG

typedef vector<vector<double> > Matrix;

struct Vect
{
  Vect()
  {
    for (int i = 0; i < 3; ++i) pos[i] = 0;
  }

  double pos[3];

  string to_s() const
  {
    ostringstream out;
    out << "(" << pos[0] << ", " << pos[1] << ", " << pos[2] << ")";
    return out.str();
  }

  const Vect operator - (const Vect& dr) const
  {
    Vect ret;
    for (int i = 0; i < 3; ++i) ret.pos[i] = this->pos[i] - dr.pos[i];
    return ret;
  }

  bool operator == (const Vect& dr) const
  {
    for (int i = 0; i < 3; ++i) {
      if (pos[i] != dr.pos[i]) return false;
    }
    return true;
  }

  double dist(const Vect& dr) const
  {
    double d = 0;
    for (int i = 0; i < 3; ++i) {
      d += (dr.pos[i] - pos[i]) * (dr.pos[i] - pos[i]);
    }
    return sqrt(d);
  }
};

struct Triangle
{
  Vect points[3];

  string to_s() const
  {
    ostringstream out;
    out << points[0].to_s() << " - " << points[1].to_s() << " - " << points[2].to_s();
    return out.str();
  }

  const Triangle operator - (const Vect& base)
  {
    Triangle t(*this);
    for (int i = 0; i < 3; ++i) t.points[i] = t.points[i] - base;
    return t;
  }

  void show(Matrix& m)
  {
#ifdef DEBUG
    int var_count = m.size();
    for (int i = 0; i < var_count; ++i) {
      for (int j = 0; j < var_count+1; ++j) {
        cerr << setw(5) << m[i][j];
      }
      cerr << endl;
    }
    cerr << "------------" << endl;
#endif
  }

  /** ガウスの掃き出し法による解法
   * @param m 方程式の係数行列 末尾成分は方程式の右辺
   * @return true:解あり，false:それ以外
   */
  bool gauss(Matrix& m)
  {
    show(m);
    int var_count = m.size();
    int pivot; // 係数を1にしたい対角成分
    for (pivot = 0; pivot < var_count; ++pivot) {
      // 誤差を少なくするため，pivot列成分の絶対値が大きな行を選択
      double max_p = 0;
      int swap = pivot;
      for (int i = pivot; i < var_count; ++i) { // 既に処理した行が対象外
        if (fabs(m[i][pivot]) > max_p) {
          max_p = fabs(m[i][pivot]);
          swap = i;
        }
      }
      // 見つけた行をpivot行目にもってくる
      if (pivot != swap) {
        for (int j = 0; j < var_count+1; ++j) {
          double t = m[pivot][j]; m[pivot][j] = m[swap][j]; m[swap][j] = t;
        }
      }
      // pivot行pivot列の成分を1にする(行全体に同じ係数を掛ける)
      double fact = m[pivot][pivot];
      if (fact == 0) return false; // 不定
      for (int j = 0; j < var_count+1; ++j) {
        m[pivot][j] /= fact;
      }
      // pivot行以外の行については，pivot列が0となるよう，
      // 係数を掛け，pivot行と足し合わせる
      for (int i = 0; i < var_count; ++i) {
        if (i == pivot) continue;
        double fact = - m[i][pivot] / m[pivot][pivot];
        for (int j = 0; j < var_count+1; ++j) {
          m[i][j] += m[pivot][j] * fact;
        }
      }
      show(m);
    }
    return true;
  }

  // 線分上にtargetが乗っているか判定
  bool on_edge(const Vect& p1, const Vect& p2, const Vect& target)
  {
    if (p1 == target || p2 == target) return true;
    Vect a = target - p1, b = p2 - p1;
    double da = a.dist(Vect()), db = b.dist(Vect());
    for (int i = 0; i < 3; ++i) {
      if (a.pos[i] / da != b.pos[i] / db) return false;
    }
    return true;
  }

  bool on_edge(const Vect& target)
  {
    return (on_edge(points[0], points[1], target) ||
            on_edge(points[1], points[2], target) ||
            on_edge(points[2], points[0], target));
  }

  bool barriered(const Vect& target)
  {
    int i, j;
    Matrix m;
    for (i = 0; i < 3; ++i) {
      m.push_back(vector<double>());
      for (j = 0; j < 3; ++j) {
        m[i].push_back(points[j].pos[i]);
      }
      m[i].push_back(target.pos[i]);
    }
    if (gauss(m)) {
      if (m[0][3] < 0 || m[1][3] < 0 || m[2][3] < 0) return false;
      if (m[0][3] + m[1][3] + m[2][3] < 1.0) return false;
      return true;
    } else {
      return on_edge(target);
    }
  }
};

Vect load_point()
{
  Vect p;
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
  Vect uaz = load_point();
  Vect enemy = load_point();
  Triangle barrier = load_triangle();
  Vect beam = enemy - uaz;
  Triangle shift_barrier = barrier - uaz;
  cout << (shift_barrier.barriered(beam)? "MISS":"HIT") << endl;
  return 0;
}
