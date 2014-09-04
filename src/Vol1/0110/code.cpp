#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// 文字列反転
void rev(string& s)
{
  s = string(s.rbegin(), s.rend());
}

// 指定の長さまで末尾'0'埋め
void fill(string& s, int len)
{
  s += string(len - s.length(), '0');
}

/** 判定
 * 数値計算では桁あふれするため
 * 一の位から一桁ずつ計算(筆算の要領)
 * 事前に数値文字列を反転し，桁を0埋めで揃えておく
 */
bool judge(string dl, string dr, string ans)
{
  int len = max(max(dl.length(), dr.length()), ans.length());
  rev(dl);  fill(dl, len);
  rev(dr);  fill(dr, len);
  rev(ans); fill(ans, len);
  for (int i = 0, stock = 0; i < len; ++i) {
    int li = dl[i]-'0', ri = dr[i]-'0', ai = ans[i]-'0';
    if ((stock + li + ri) % 10 != ai) return false;
    stock = (stock + li + ri) / 10;
  }
  return true;
}

// 'X'を指定の数字に置換
string repl(string s, int n)
{
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'X') s[i] = char(n+'0');
  }
  return s;
}

// 'X'に'0'が使えるかどうか判定
bool enable_zero(const string& s)
{
  return (s.length() == 1 || s[0] != 'X');
}

// 解答を検索 正解がない場合は-1を返す
int seek(const string& s)
{
  string dl, dr, ans;
  size_t pl = s.find('+'), eq = s.find('=');
  dl = s.substr(0, pl);
  dr = s.substr(pl+1, eq-pl-1);
  ans = s.substr(eq+1);
  int b = (enable_zero(dl) && enable_zero(dr) && enable_zero(ans))? 0 : 1;
  for (int i = b; i < 10; ++i) {
    if (judge(repl(dl, i), repl(dr, i), repl(ans, i))) return i;
  }
  return -1;
}

int main()
{
  string s;
  for (;!cin.eof();) {
    getline(cin, s);
    if (s.empty()) break;
    int r = seek(s);
    if (r >= 0)
      cout << seek(s) << endl;
    else
      cout << "NA" << endl;
  }
  return 0;
}
