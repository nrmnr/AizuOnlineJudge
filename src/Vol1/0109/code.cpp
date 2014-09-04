/**
 * https://gist.github.com/draftcode/1357281
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

typedef string::const_iterator Context;
int expression(Context& c);
int term(Context& c);
int factor(Context& c);
int number(Context& c);

// 四則演算 ::= <乗除算> (+ or -) <乗除算> ...
int expression(Context& c)
{
  int r = term(c);
  for (;;) {
    switch (*c) {
    case '+': ++c; r += term(c); break;
    case '-': ++c; r -= term(c); break;
    default: return r;
    }
  }
}

// 乗除算 ::= <括弧|数値> (* or /) <括弧|数値> ...
int term(Context& c)
{
  int r = factor(c);
  for (;;) {
    switch (*c) {
    case '*': ++c; r *= factor(c); break;
    case '/': ++c; r /= factor(c); break;
    default: return r;
    }
  }
}

// 括弧|数値 ::= '(' <四則演算> ')' or <数値>
int factor(Context& c)
{
  if (*c == '(') {
    ++c; // skip '('
    int r = expression(c);
    ++c; // skip ')'
    return r;
  } else {
    return number(c);
  }
}

// 数値
int number(Context& c)
{
  int r = 0;
  for (; isdigit(*c); ++c) {
    r *= 10;
    r += (*c - '0');
  }
  return r;
}

int main()
{
  string s;
  int n;
  cin >> n; cin.ignore();
  for (;n-->0;) {
    getline(cin, s);
    Context c = s.begin();
    cout << expression(c) << endl;
  }
  return 0;
}
