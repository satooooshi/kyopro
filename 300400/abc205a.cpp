#include <iostream>
#include <iomanip>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  // std::fixed -> 固定小数点で出力することを指定
  // std::setprecision(int n) -> 小数点以下 n 桁で出力することを指定
  cout << fixed << setprecision(7);
  cout << A * B / 100.0 << '\n';
  return 0;
}