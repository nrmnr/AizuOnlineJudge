#include <iostream>
#include <string>
#include <map>
using namespace std;

string dict_src[][2] = {
  { " ", "101" },
  { "\'","000000" },
  { ",", "000011" },
  { "-", "10010001" },
  { ".", "010001" },
  { "?", "000001" },
  { "A", "100101" },
  { "B", "10011010" },
  { "C", "0101" },
  { "D", "0001" },
  { "E", "110" },
  { "F", "01001" },
  { "G", "10011011" },
  { "H", "010000" },
  { "I", "0111" },
  { "J", "10011000" },
  { "K", "0110" },
  { "L", "00100" },
  { "M", "10011001" },
  { "N", "10011110" },
  { "O", "00101" },
  { "P", "111" },
  { "Q", "10011111" },
  { "R", "1000" },
  { "S", "00110" },
  { "T", "00111" },
  { "U", "10011100" },
  { "V", "10011101" },
  { "W", "000010" },
  { "X", "10010010" },
  { "Y", "10010011" },
  { "Z", "10010000" }
};
const int DICT_SZ = sizeof(dict_src) / sizeof(dict_src[0]);

map<string, char> dict;

void init_dict()
{
  for (int i = 0; i < DICT_SZ; ++i) {
    dict[dict_src[i][1]] = dict_src[i][0][0];
  }
}

map<char, string> bits;

string to_bits(int code)
{
  string r = "00000";
  for (int i = 0; i < 5; ++i) {
    if (code & (1 << i)) {
      r[4-i] = '1';
    }
  }
  return r;
}

void init_bits()
{
  for (char c = 'A'; c <= 'Z'; ++c) bits[c] = to_bits(c - 'A');
  bits[' ']  = to_bits(26);
  bits['.']  = to_bits(27);
  bits[',']  = to_bits(28);
  bits['-']  = to_bits(29);
  bits['\''] = to_bits(30);
  bits['?']  = to_bits(31);
}


int main()
{
  init_dict();
  init_bits();
  string input;
  for (;getline(cin, input);) {
    string code;
    code.reserve(200*5);
    for (string::iterator it = input.begin(); it != input.end(); ++it) {
      code += bits[*it];
    }

    string ans;
    for (int pos = 0, l = code.size(); pos < l; ) {
      int i;
      for (i = 1; i <= 8; ++i) {
        string sub = code.substr(pos, i);
        map<string, char>::iterator f = dict.find(sub);
        if (f != dict.end()) {
          ans += f->second;
          pos += f->first.size();
          break;
        }
      }
      if (i > 8) break;
    }

    cout << ans << endl;
  }
  cin.clear();
  return 0;
}
