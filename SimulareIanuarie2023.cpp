// Subiectul 3
// 1)
#include <iostream>
using namespace std;

void ecran(unsigned n)
{
    unsigned s, x, aux = n, inv = 0, nr, counter;
    while (aux)
    {
        inv = inv * 10 + aux % 10;
        aux /= 10;
        nr++;
    }

    unsigned v[nr];
    for (int i = 0; i < nr; i++)
    {
        v[i] = inv % 10;
        inv /= 10;
    }

    cout << n << '*' << n << endl;
    x = 3;
    counter = nr;
    while (n / 10 != 0)
    {
        cout << n / 10;
        s = x;
        while (s != 0)
        {
            cout << '*';
            s--;
        }

        for (int i = nr - counter + 1; i < nr; i++)
        {
            cout << v[i];
        }
        cout << endl;
        x += 2;
        counter--;
        n /= 10;
    }
    s = x;
    while (s != 0)
    {
        cout << '*';
        s--;
    }
}

int main()
{
    ecran(202334);
    return 0;
}

// 2)
#include <iostream>
using namespace std;

int n, m, a[10000][10000], l1, l2, c1, c2, maxim = 0, minim = INT_MAX;
bool spatiu;
int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] > maxim)
            {
                maxim = a[i][j];
                l1 = i;
                c1 = j;
            }
            if (a[i][j] < minim)
            {
                minim = a[i][j];
                l2 = i;
                c2 = j;
            }
        }
    }

    if (l1 != l2 && c1 != c2)
        cout << n - 2 << ' ' << m - 2;
    else if (l1 == l2)
        cout << n - 1 << ' ' << m - 2;
    else if (c1 == c2)
        cout << n - 2 << ' ' << m - 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == l1 || j == c1 || i == l2 || j == c2)
            {
                spatiu = true;
                continue;
            }
            else
            {
                cout << a[i][j] << ' ';
            }
        }
        if (spatiu)
            cout << endl;
    }
    spatiu = false;

    return 0;
}
