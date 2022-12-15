# Cplusplus
#Bilet 13

#include <iostream>
using namespace std;
int main()
{
    int n = 2, m[100][100] = { 0 };
    cin>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = j + 1 + i;
            if (k > n) {
                m[i][j] = k - n;
            }
            else {
                m[i][j] = j + 1 + i;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout<<endl;
        for (int j = 0; j < n ; j++) {
             cout << m[i][j]<<' ';
        }
    }
    return 0;
}

#Bilet 14

#include <iostream>
#include<fstream>
using namespace std;
int test_fibo(int n){
    int n1 = 0, n2 = 1, lastTerm = 0;
      for (int i = 1; i <= n; ++i) {
        if(lastTerm != n){
          lastTerm = n1 + n2;
          n1 = n2;
          n2 = lastTerm;
        }
        else break;
    }
     return lastTerm;
}
int main() {
    int v[100],n;
    ifstream f("date.in");
    ofstream g("date.out");
    f>>n;
    for(int i=1;i<=n;i++){
       f>>v[i];
       if(v[i] == test_fibo(v[i])){
        g<<v[i]<<' ';
       }
    }
    return 0;
}

#Bilet 15


