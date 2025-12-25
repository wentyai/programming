#include "triangle.h"

Triangle initTriangle(double a, double b, double c) {
    Triangle t;
    t.a = a;
    t.b = b;
    t.c = c;
    return t;
}

double area(Triangle t) {
    double p = (t.a + t.b + t.c) / 2.0;
    return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}

int findLargest(Triangle t1, Triangle t2, Triangle t3) {
    double a1 = area(t1);
    double a2 = area(t2);
    double a3 = area(t3);

    if (a1 >= a2 && a1 >= a3) return 1;
    if (a2 >= a1 && a2 >= a3) return 2;
    return 3;
}