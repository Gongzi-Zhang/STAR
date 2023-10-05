#include <iostream>

using namespace std;
int main() {
  if (__cplusplus == 202101L) cout << "C++23";
  else if (__cplusplus == 202002L) cout << "C++20";
  else if (__cplusplus == 201703L) cout << "C++17";
  else if (__cplusplus == 201402L) cout << "C++14";
  else if (__cplusplus == 201103L) cout << "C++11";
  else if (__cplusplus == 199711L) cout << "C++98";
  else cout << "pre-standard C++." << __cplusplus;
  cout << "\n";
}
