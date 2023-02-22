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

int n, M[20][20], v[10] = {0}, val_min = 100, val_max = 0;
int main()
{
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

// bilet 20

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
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
        }
    }

    for (int i = 1; i <= s; i++)
    {
        g << v[i];
    }
    f.close();
    g.close();
    return 0;
}

// bilet 21

#include <fstream>
#include <string.h>
using namespace std;

ifstream f("doc.txt");
ofstream g("cnp.txt");

int main()
{
    char str[256];
    int n = 0;
    while (!f.eof())
    {
        f.getline(str, 256);
        int l = 0;
        for (int i = 0; i <= strlen(str); i++)
            if (str[i] >= '0' && str[i] <= '9')
            {
                l++;
                if (l == 13 && (str[i + 1] < '0' || str[i + 1] > '9'))
                {
                    n++;
                    for (int j = i - l + 1; j <= i; j++)
                        g << str[j];
                    g << endl;
                    l = 0;
                }
            }
            else
                l = 0;
    }
    if (n == 0)
        g << 0;
    return 0;
}

// bilet 22
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("numere.in");

int rotund(int n)
{
    int x, ok = 1, nrc = 0, copie = n;
    // cifrele egale
    while (n > 9)
    {
        x = n % 10;
        n = n / 10;
        if (n % 10 != x)
        {
            ok = 0;
            break;
        }
    }
    if (ok == 1)
        return 1;
    else
    {
        n = copie;
        while (n)
        {
            nrc++;
            n /= 10;
        }
        if (nrc % 2 == 1) // nr impar de cifre
            return 0;
        else
        {
            n = copie;
            if (n / (int)pow(10, nrc / 2) == n % (int)pow(10, nrc / 2))
                return 1;
        }
    }
}

int main()
{
    int n, nr, spatiu = 0;
    f >> n;
    for (int i = 1; i <= n; i++)
    {
        f >> nr;
        if (rotund(nr))
        {
            cout << nr << " ";
            spatiu++;
            if (spatiu == 2)
            {
                cout << endl;
                spatiu = 0;
            }
        }
    }
    return 0;
}

// bilet 23

#include <iostream>
#include <fstream>
using namespace std;
ofstream g("pag.txt");
int main()
{
    unsigned n, volume, cif;
    cin >> n;
    volume = n / (792 / 2);
    cif = n % 792;
    if (cif <= 9)
        g << volume << endl
          << cif;
    else
    {
        cif -= 9;
        if (cif < 181)
        {
            if (cif % 2 == 0)
                g << volume << endl
                  << 9 + cif / 2;
            else
                g << "imposibil";
        }
        else
        {
            cif -= 180;
            if (cif % 3 == 0)
                g << volume << endl
                  << 99 + cif / 3;
            else
                g << "imposibil";
        }
    }
    return 0;
}

// bilet 24

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("eur.in");
ofstream g("eur.out");
int main()
{
    int S, n, e, b = 0;
    f >> S >> n >> e;
    while (S)
    {
        if (S / (int)pow(e, n) != 0)
        {
            b += S / (int)pow(e, n);
            g << S / (int)pow(e, n) << " bancnote cu valoarea " << (int)pow(e, n) << endl;
            S = S % (int)pow(e, n);
            n -= 1;
        }
        else
        {
            n -= 1;
        }
    }
    g << b;
    return 0;
}

// bilet 25

#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.in");
ofstream g("numere.out");
int main()
{
    int fr[9999] = {0}, x, i;
    while (f >> x)
    {
        fr[x]++;
    }
    for (i = 9999; i > 0; i--)
    {
        if (fr[i] == 0)
            g << i << " ";
    }
    return 0;
}

// bilet 26

#include <iostream>
#include <fstream>
using namespace std;
ofstream g("numere.txt");
int main()
{
    short v[] = {1, 2, 3, 4, 5, 4, 3, 2, 1}, i;
    while (v[5] != 9)
    {
        for (i = 0; i <= 8; i++)
        {
            g << v[i];
            v[i]++;
        }
        g << " ";
    }
}

// bilet 27

#include <iostream>
#include <fstream>
using namespace std;
ifstream f("mat.in");
ofstream g("mat.out");
int main()
{
    short n, m, M[30][30], v[30], i, j, maxi = 0, sub = 0;

    f >> n >> m;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            f >> M[i][j];
            if (maxi < M[i][j])
                maxi = M[i][j];
            if (i == 1)
                v[j] = M[i][j];
            else if (v[j] > M[i][j])
                v[j] = M[i][j];
        }
    }

    for (i = 1; i <= n; i++)
    {
        if (i != 1)
            g << endl;
        for (j = 1; j <= m; j++)
        {
            if (M[i][j] == maxi)
            {
                M[i][j] = v[j];
                sub++;
            }
            g << M[i][j] << " ";
        }
    }
    g << endl
      << sub;

    return 0;
}
