#include "triangle.h"

int main() {
    Triangle t1 = initTriangle(5.0, 5.0, 5.0);
    Triangle t2 = initTriangle(3.0, 3.0, 3.0);
    Triangle t3 = initTriangle(12.0, 12.0, 12.0);

    int largest = findLargest(t1, t2,t3);
    printf("Наибольшая площадь у треугольника №%d\n", largest);

    return 0;
}
