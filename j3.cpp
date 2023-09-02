#include <iostream>

#define ll int64_t

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string in;
  int prev = 0;
  cin >> in;

  for (int i = 0; i < in.length(); i++) {
    if (in[i] == '+' || in[i] == '-') {
      int thing = 0;
      for (int j = i + 1; j < in.length(); j++) {
        if (!(in[j] >= '0' && in[j] <= '9')) {
          thing = j;
          break;
        }
      }
      if (!thing) {
        thing = in.length();
      }

      cout << in.substr(prev, i - prev)
           << (in[i] == '+' ? " tighten " : " loosen ")
           << in.substr(i + 1, thing - i - 1) << "\n";
      i = thing - 1;
      prev = i + 1;
    }
  }

  return 0;
}
