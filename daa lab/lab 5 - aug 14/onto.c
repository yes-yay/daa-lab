//sri rama jayam 
#include <iostream>

using namespace std;


int main()
{
    int n;
    cout << "Enter number of elements:";
    cin >> n;

    int a[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]= 0;

    int x, p, q;
    cout << "Enter number of nodes:";
    cin >> x;

    cout << "Enter elements:";
    for(int i=0;i<x;i++)
    {
        cin >> p >> q;
        a[p-1][q-1] = 1;
    }

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    int z;
    cout << "Enter number of elements in co-domain:";
    cin >> z;
    int codomain[z], range[z];
    cout << "Enter codomain:";
    for(int i=0;i<z;i++)
    {

        cin >> codomain[i];
    }


    int s=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

            if(a[j][i]==1)
                {range[s]=j+1;
                s++;}

        }

    }


    int flag=0;
    for(int i=0;i<z;i++)
    {
        for(int j=0;j<z;j++)
        {
            if(range[i]==codomain[j])
            {flag++;
            break;}
        }
    }
    if(flag==z)
        cout << " onto."<< endl;
    else
        cout << "Not onto." << endl;



    return 0;
}