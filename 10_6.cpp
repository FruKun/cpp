#include <cmath>
#include <iostream>
using namespace std;
class ComplexAlg
{
public:
  double Re, Im;

  void show()
  {
    cout << Re;
    if (Im < 0)
    {
      cout << "- i " << -Im << endl;
    }
    else
    {
      cout << "+ i " << Im << endl;
    }
  }
};

class ComplexGeom
{
public:
  double r, phi;

  void show() { cout << r << "e^(" << phi << "i)" << endl; }
};

ComplexGeom operator*(ComplexGeom x, ComplexAlg y)
{
  ComplexGeom res;
  res.r = x.r * sqrt(y.Re * y.Re + y.Im * y.Im);
  res.phi = x.phi + atan2(y.Im, y.Re);
  return res;
}

ComplexAlg operator*(ComplexAlg x, ComplexGeom y)
{
  ComplexAlg res;
  double Re = y.r * cos(y.phi);
  double Im = y.r * sin(y.phi);
  res.Re = x.Re * Re - x.Im * Im;
  res.Im = x.Re * Im + x.Im * Re;
  return res;
}

ComplexGeom operator/(ComplexGeom x, ComplexAlg y)
{
  ComplexGeom res;
  res.r = x.r / sqrt(y.Re * y.Re + y.Im * y.Im);
  res.phi = x.phi - atan2(y.Im, y.Re);
  return res;
}

ComplexAlg operator/(ComplexAlg x, ComplexGeom y)
{
  ComplexAlg res;
  res.Re = (x.Re * cos(y.phi) + x.Im * sin(y.phi)) / y.r;
  res.Im = (x.Im * cos(y.phi) - x.Re * sin(y.phi)) / y.r;
  return res;
}

int main()
{
  ComplexGeom A{5, M_PI / 3};
  ComplexAlg C{1, 2};
  (A * C).show();
  (C * A).show();
  (A / C).show();
  (C / A).show();
  return 0;
}
