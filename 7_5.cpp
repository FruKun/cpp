#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
double fact(double a)
{
    if (a < 0)
        return 0;
    if (a == 0)
        return 1;
    return a * fact(a - 1);
}
class Sinh
{
public:
    static int N;
    double x;

    double func()
    {
        double s;
        for (int i = 0; i <= N; i++)
        {
            s += pow(x, 2 * i + 1) / fact(2 * i + 1);
        }
        return s;
    }
};
int Sinh::N;

int main()
{
    Sinh::N = 100;
    Sinh a;
    a.x = 5;
    cout << a.func() << endl;
    cout << sinh(a.x) << endl;
}