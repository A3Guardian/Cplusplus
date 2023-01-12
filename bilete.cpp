// Cplusplus
// #Bilet 13

#include <iostream>
using namespace std;
int main()
{
    int n = 2, m[100][100] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k = j + 1 + i;
            if (k > n)
            {
                m[i][j] = k - n;
            }
            else
            {
                m[i][j] = j + 1 + i;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            cout << m[i][j] << ' ';
        }
    }
    return 0;
}

// #Bilet 14

#include <iostream>
#include <fstream>
using namespace std;
int test_fibo(int n)
{
    int n1 = 0, n2 = 1, lastTerm = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (lastTerm != n)
        {
            lastTerm = n1 + n2;
            n1 = n2;
            n2 = lastTerm;
        }
        else
            break;
    }
    return lastTerm;
}
int main()
{
    int v[100], n;
    ifstream f("date.in");
    ofstream g("date.out");
    f >> n;
    for (int i = 1; i <= n; i++)
    {
        f >> v[i];
        if (v[i] == test_fibo(v[i]))
        {
            g << v[i] << ' ';
        }
    }
    return 0;
}

// #Bilet 15

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a, b, c, v[20], s = 0, k, nr = 1;
    ifstream f("numere.in");
    ofstream g("numere.out");
    f >> a >> b;
    c = a;
    while (b != 0)
    {
        c = c * 10 + b % 10;
        b = b / 10;
    }
    while (c != 0)
    {
        v[s] = c % 10;
        c = c / 10;
        s++;
    }
    for (int i = 0; i <= s; i++)
    {
        cout << v[i];
    }
    for (int i = 0; i <= s - 1; i++)
    {
        for (int j = i + 1; j <= s; j++)
        {
            if (v[i] < v[j])
            {
                swap(v[i], v[j]);
            }
        }
    }

    for (int i = 0; i <= s; i++)
    {
        g << v[i];
    }
    f.close();
    g.close();
    return 0;
}

// #Bilet 16

#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.in");
ofstream g("numere.out");

long baza10(int n, int b)
{ // trece n din baza b in baza 10
    int x = 0, p = 1;
    while (n)
    {
        x = x + n % 10 * p;
        n = n / 10;
        p = p * b;
    }
    return x;
}

long bazan(int n, int b)
{ // trece n din baza 10 in baza b
    int x = 0, p = 1;
    while (n)
    {
        x = x + n % b * p;
        n = n / b;
        p = p * 10;
    }
    return x;
}

int main()
{
    int b1, b2, b3, x, y;
    f >> b1 >> b2 >> b3 >> x >> y;
    g << bazan(baza10(x, b1) + baza10(y, b2), b3);
    f.close();
    g.close();
    return 0;
}

// #Bilet 17

#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int suma;

int suma_cifre(int x)
{
    if (x)
    {
        suma = suma + x % 10;
        suma_cifre(x / 10);
    }

    return suma;
}

int main()
{
    int n, v[100];
    f >> n;
    for (int i = 1; i <= n; i++)
    {
        f >> v[i];
        suma = 0;
        if (suma_cifre(v[i]) % 3 == 0)
        {
            g << v[i] << ' ';
        }
    }
    return 0;
}

// #Bilet 18

#include <iostream>
#include <fstream>
using namespace std;
ifstream f("multimi.in");
ofstream g("multimi.out");

int main()
{
    int n, m, prev, k, a[20];
    f >> n >> m;
    for (int i = 0; i < m + n; i++)
    {
        f >> a[i];
    }

    for (int i = 0; i < m + n; i++)
    {
        for (int j = 0; j < m + n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }

    for (int i = 0; i < m + n; i++)
    {
        prev = a[i - 1];
        if (a[i] != prev || i == 0)
        {
            g << a[i] << ' ';
            prev = a[i];
        }
    }

    return 0;
}

// Bilet 19

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n, M[20][20], v[10] = {0}, val_min = 100, val_max = 0;
    ifstream f("date.in");
    ofstream g("date.out");
    f >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            f >> M[i][j];
            if (M[i][j] > val_max)
                val_max = M[i][j];
            else if (M[i][j] < val_min)
                val_min = M[i][j];
        }
    cout << val_min << ' ' << val_max;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (M[i][j] == val_max)
                v[i] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (v[i])
                g << M[i][j] + val_min << ' ';
            else
                g << M[i][j] << ' ';

        g << endl;
    }
    return 0;
}
