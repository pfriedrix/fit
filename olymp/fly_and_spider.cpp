#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double distance (double X1,double X2,double Y1,double Y2)
{
    return (sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2)));
}
int main() {
    cout.precision(2);
    double A, B, C;
    cin>>A>>B>>C;
    double X2, Y2, X1, Y1, Z2;
    cin>>X1>>Y1;
    cin>>X2>>Y2>>Z2;
    double s=250000000;
    if (Z2==0) s=distance (X1,X2,Y1,Y2);//"floor" case
    else
    {
        if (X2==0) {X2=-Z2; s=distance (X1,X2,Y1,Y2);}//"left wall" case
        if (X2==A) {X2=A+Z2; s=distance (X1,X2,Y1,Y2);}//"right wall" case
        if (Y2==0) {Y2=-Z2; s=min(s, distance (X1,X2,Y1,Y2));}//"near wall" case
        if (Y2==B) {Y2=B+Z2; s=min(s, distance (X1,X2,Y1,Y2));}//"distant wall" case
    }
    cout<<fixed<<s;
    return 0;
}