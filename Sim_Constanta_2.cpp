// Subiectul 1
// Subiectul 2
// 1.
// 2.
struct concert
{
    struct
    {
        char formatie[41];
        char stil[31];
        struct
        {
            int zi;
            int luna;
            int an;
        } data;
    }[10];
} c;

// 3.
int a[10][10];
for(i=1;i<=3;i++)       
   for(j=1;j<=5;j++) 
     if(i==1 || j==1)
       a[i][j]=1;
     if(i==2) 
       a[i][j]=pow(i,j)-1;
     if(i==3)
       a[i][j]=...
      