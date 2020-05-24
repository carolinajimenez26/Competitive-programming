// See https://cp-algorithms.com/num_methods/ternary_search.html
#include <iostream>
using namespace std;

// this should be replaced with an unimodal function
double F(double x) {
  return 0;
}

double TernarySearch(double l, double r) {
  double eps = 1e-9; //set the error limit here
  while (r - l > eps) {
    // if (r - l < 3) break;
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = F(m1);  //evaluates the function at m1
    double f2 = F(m2); //evaluates the function at m2
    if (f1 < f2)
      l = m1;
    else
      r = m2;
  }
  return F(l); //return the maximum of f(x) in [l, r]
}

int main(void) {
  return 0;
}