#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

struct Dict {
  char c;
  string bits;
};
Dict dict_src[] = {
  { ' ', "101" },
  { '\'',"000000" },
  { ',', "000011" },
  { '-', "10010001" },
  { '.', "010001" },
  { '?', "000001" },
  { 'A', "100101" },
  { 'B', "10011010" },
  { 'C', "0101" },
  { 'D', "0001" },
  { 'E', "110" },
  { 'F', "01001" },
  { 'G', "10011011" },
  { 'H', "010000" },
  { 'I', "0111" },
  { 'J', "10011000" },
  { 'K', "0110" },
  { 'L', "00100" },
  { 'M', "10011001" },
  { 'N', "10011110" },
  { 'O', "00101" },
  { 'P', "111" },
  { 'Q', "10011111" },
  { 'R', "1000" },
  { 'S', "00110" },
  { 'T', "00111" },
  { 'U', "10011100" },
  { 'V', "10011101" },
  { 'W', "000010" },
  { 'X', "10010010" },
  { 'Y', "10010011" },
  { 'Z', "10010000" }
};
const int DICT_SZ = sizeof(dict_src) / sizeof(dict_src[0]);
vector<Dict> dict(DICT_SZ);
Dict TERM = {'\0', ""};

bool comp(const Dict& d1, const Dict& d2)
{
  if (d1.bits.size() != d2.bits.size()) return d1.bits.size() < d2.bits.size();
  return d1.bits < d2.bits;
}

void init_dict()
{
  for (int i = 0; i < DICT_SZ; ++i) dict[i] = dict_src[i];
  sort(dict.begin(), dict.end(), comp);
}

Dict search(const string& bits, int pos)
{
  for (vector<Dict>::iterator it = dict.begin(); it != dict.end(); ++it) {
    if (bits.compare(pos, it->bits.size(), it->bits) == 0) {
      return *it;
    }
  }
  return TERM;
}

string to_bit(char c)
{
  if ('A' <= c && c <= 'Z') {
    int code = c - 'A';
    string r = "00000";
    for (int i = 0; i < 5; ++i) {
      if (code & (1 << i)) {
        r[4-i] = '1';
      }
    }
    return r;
  } else if (c == ' ') {
    return "11010";
  } else if (c == '.') {
    return "11011";
  } else if (c == ',') {
    return "11100";
  } else if (c == '-') {
    return "11101";
  } else if (c == '\'') {
    return "11110";
  } else if (c == '?') {
    return "11111";
  }
  return "";
}


int main()
{
  init_dict();
  string input;
  for (;getline(cin, input);) {
    string bits;
    bits.reserve(200*5);
    for (string::iterator it = input.begin(); it != input.end(); ++it) {
      bits += to_bit(*it);
    }

    string ans;
    for (int pos = 0, l = bits.size(); pos < l; ) {
      Dict d = search(bits, pos);
      if (d.c == '\0') break;
      ans += d.c;
      pos += d.bits.size();
    }

    cout << ans << endl;
  }
  cin.clear();
  return 0;
}
