#include <iostream>
#include<time.h>

using namespace std;

int v, a[15], o, p, b[3];
void outputmass(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
}
void genmasr(int x[],int n)
{
    cout << "Input number of elements les than "<<n<<": ";
    cin>> v;
    srand((unsigned)(time(NULL)));
    for (int i = 0; i < v; i++)
    {
        x[i] = rand() % 20;
    }
}
int g(int x[])
{
    for ( int i = 0; i < 2; i++ ){
        
    }
    return o;
}
int gor(int a[], int o)
{
    int i = 0, k = 0, result{}, item{};
    while (i < v)
    {
        item = a[i] * pow(o, i);
        result += item;
        i++;
    }
    return result;
}
int main()
{
    genmasr(a, 15);
    outputmass(a,v);
    genmasr(b, 4);
    g(b);
    outputmass(b, v);
    cout << endl;
    cout << gor(a, o);


}
