#include <stdio.h>

double f(double x, int mode);
double RootOfFunction(double xl, double xr, double epsilon, int mode);

int main() {
    double root, first_value;
    int mode = 0;
    scanf("%d %lf", &mode, &first_value);
    printf("Ans =\n");
    root = RootOfFunction(-1, first_value, 0.1, mode);
    printf("root = %.1f", root);
    return 0;
}

double f(double x, int mode) {
    // ฟังก์ชันที่ใช้ในการคำนวณ เช่น 2x - 5
    return 2 * x - 5;
}

double RootOfFunction(double xl, double xr, double epsilon, int mode) {
    double root;
    double xm = (xl + xr) / 2; // คำนวณค่ากลางระหว่าง xl และ xr
    printf("%.1f %.1f %.1f\n", xl, xm, xr); // พิมพ์ค่าของ xl, xm, xr

    // ตรวจสอบเงื่อนไขการหยุดของการคำนวณ
    if ((xr - xl) < epsilon) {
        root = xm;
    } else if (f(xm, mode) == 0) {
        root = xm;
    } else if ((f(xl, mode) * f(xm, mode)) < 0) {
        // ถ้าฟังก์ชันที่ xl กับ xm มีเครื่องหมายต่างกัน
        root = RootOfFunction(xl, xm, epsilon, mode);
    } else {
        // ถ้าฟังก์ชันที่ xm กับ xr มีเครื่องหมายต่างกัน
        root = RootOfFunction(xm, xr, epsilon, mode);
    }
    return root;
}