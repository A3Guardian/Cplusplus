//Subiectul 3
//1.
//2.
//3.
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream f("numere.txt");
  int x,digit,v[10] = {0};
  while (f >> x) {
    while (x) {
      digit = x % 10;
      if (digit % 2 == 0) {
        v[digit]++;
      }
      x /= 10;
    }
  }

  for (int i = 9; i >= 0; i--) {
    while (v[i]) {
      cout <<i;
      v[i]--;
    }
  }
  f.close();
  return 0;
}
