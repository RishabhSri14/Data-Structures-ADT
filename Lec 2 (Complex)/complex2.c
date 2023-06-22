#include <stdio.h>
#include "complex2.h"
#include <math.h>
complex2 Cx2Create(double real,double imag)
{
    struct complex2_ c;
    c.a=real;
    c.b=imag;
    return c;
}
double Cx2Arg(const complex2 cx)
{
    double r=cx.b/cx.a;
    
    return atan(r);

    
}
double Cx2Mod(const complex2 cx)
{
    double x= (cx.a)*(cx.a)+(cx.b)*(cx.b);
    return sqrt(x);
}
void Cx2Print(const complex2 cx)
{
    printf("%f + i%f",cx.a,cx.b);
}
complex2 Cx2Add(const complex2 c1,const complex2 c2)
{
    complex2 c;
    c.a=c1.a+c2.a;
    c.b=c1.b+c2.b;
    return c;
}
complex2 Cx2Mul(const complex2 c1,const complex2 c2)
{
    complex2 c;
    c.a=(c1.a*c2.a)-(c1.b*c2.b);
    c.b=(c1.a*c2.b)+(c1.b*c2.a);
    return c;
}
complex2 Cx2Inv(const complex2 cx)
{
    complex2 c;
    c.a=cx.a/((Cx2Mod(cx))*(Cx2Mod(cx)));
    c.b=-(cx.b/((Cx2Mod(cx))*(Cx2Mod(cx))));
    return c;

}
complex2 Cx2Conj(const complex2 cx)
{
    complex2 c;
    c.a=cx.a;
    c.b=-(cx.b);
    return c;
}
