#include <stdio.h>

int SumLoop(int);
int SumRecur(int);
void TowerHanoi(int, int, int);

int main() {
    int n = 0, m = 0, i = 0, j = 0;
    scanf("%d %d %d %d", &n, &m, &i, &j);
    printf("%d\n", SumLoop(n));
    printf("%d\n", SumRecur(n));
    TowerHanoi(m, i, j);
    return 0;
}

int SumLoop(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int SumRecur(int n) {
    if (n == 1) {
        return 1;
    }
    return n + SumRecur(n - 1);
}

void TowerHanoi(int m, int start, int end) {
    if (m > 0) {
        int temp = 6 - start - end; // ปรับจากการหาค่า
        TowerHanoi(m - 1, start, temp); // ย้ายจากเริ่มต้นไปยังชั่วคราว
        printf("Move disc %d from %d to %d\n", m, start, end);
        TowerHanoi(m - 1, temp, end); // ย้ายจากชั่วคราวไปยังปลายทาง
    }
}