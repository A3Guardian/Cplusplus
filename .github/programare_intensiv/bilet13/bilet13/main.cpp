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
