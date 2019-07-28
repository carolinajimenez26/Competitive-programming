#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2){
  return sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) );
}

int main(void){
  double X1, Y1, X2, Y2;
  cin >> X1 >> Y1 >> X2 >> Y2;
  cout << fixed << setprecision(4) << dist(X1,Y1,X2,Y2) << endl;
  return 0;
}
