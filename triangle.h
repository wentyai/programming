#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdio.h>
#include <math.h>

typedef struct {
    double a, b, c;
} Triangle;


Triangle initTriangle(double a, double b, double c);

double area(Triangle t);

int findLargest(Triangle t1, Triangle t2, Triangle t3);

#endif
