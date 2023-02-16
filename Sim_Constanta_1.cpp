//Subiectul 1
//1.b
//2.d
//3.b
//4.a
//5.d

//Subiectul 2
//1.

//2.
struct angajat{
int numar;
  struct {
    char nume;
    float salariu;
    int vechime;
  } [51];
}a;

//3.
#include <iostream>
using namespace std;
int main(){
    int n, M[25][25];
    cin>>n;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
         M[i][j]=i*j%10;

    for(int i=1;i<=n;i++)
    cout<<endl;
      for(int j=1;j<=n;j++)
         cout<<M[i][j]<<' ';

}

//Subiectul 3
//1
//2
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  int n,k,voc[]={"aeiou"},cons;
  char c[11];
  cin>>n>>k;
  while(cin>>c)
  {
    cons=0;
    for(int i=0;i<=strlen(c);i++)
      if(strchr(voc,c[i]))
        cons++;

    if(cons%2==0)
       for(int i=0;i<=strlen(c);i++)
         cout<<c[i];        
  }

}