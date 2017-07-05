#include <iostream>
using namespace std;

static const int MAX = 100000;
static const int NIL = -1;

struct Node
{
  int parent, child, sibling;
  Node():parent(NIL),child(NIL),sibling(NIL){};
};

Node nodes[MAX];
int n;
int all_depth[MAX];

void calc_all_depth(int i, int d)
{
  all_depth[i] = d;
  if (nodes[i].sibling != NIL) {
    calc_all_depth(nodes[i].sibling, d);
  }
  if (nodes[i].child != NIL) {
    calc_all_depth(nodes[i].child, d+1);
  }
}

void print_node(int i)
{
  const Node& n = nodes[i];
  cout << "node " << i << ": "
       << "parent = " << n.parent << ", "
       << "depth = " << all_depth[i] << ", ";

  if (n.parent == NIL) cout << "root, ";
  else if (n.child == NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";
  for (int c = n.child; c != NIL; c = nodes[c].sibling) {
    if (c != n.child) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[])
{
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int id, k, c, prev;
    cin >> id >> k;
    for (int j = 0; j < k; ++j, prev = c) {
      cin >> c;
      if (j == 0) nodes[id].child = c;
      else nodes[prev].sibling = c;
      nodes[c].parent = id;
    }
  }
  int root;
  for (int i = 0; i < n; ++i) {
    if (nodes[i].parent == NIL) root = i;
  }
  calc_all_depth(root, 0);
  for (int i = 0; i < n; ++i) print_node(i);
  return 0;
}
