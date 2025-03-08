#include <stdio.h>

int *KnapsackKP(int *w, int *v, int n, int wx);

int main() {
    int wx = 11, ans = 0, n, i;
    n = 5;

    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter wx : ");
    scanf("%d", &wx);

    int *w = new int[n];
    int *v = new int[n];
    
    for (i = 0; i < n; i++) {
        printf("Weight for item %d : ", i);
        scanf("%d", &w[i]);
    }
    for (i = 0; i < n; i++) {
        printf("Value for item %d : ", i);
        scanf("%d", &v[i]);
    }

    int *x = KnapsackKP(w, v, n, wx);
    
    printf("Selected items: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }

    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            ans += v[i];  // คำนวณผลรวมของมูลค่าของสินค้าที่เลือก
        }
    }
    
    printf("\nTotal Value = %d\n", ans);

    return 0;
}

int *KnapsackKP(int *w, int *v, int n, int wx) {
    int u[n][wx + 1];  // ตารางเก็บค่ามูลค่าสูงสุด
    int y[n][wx + 1];  // ตารางเก็บข้อมูลการเลือกไอเทม

    // กำหนดค่าเริ่มต้นในตาราง
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= wx; j++) {
            int a, b;
            
            // ถ้าเป็นกรณีที่ไม่สามารถเลือกไอเทมได้ (i == 0 หรือ j < w[i])
            if (i - 1 < 0) {
                a = 0;  // ไม่เลือกไอเทม
                y[i][j] = 0;
            } else {
                a = u[i - 1][j];  // มูลค่าที่ดีที่สุดจากการไม่เลือกไอเทม
                y[i][j] = y[i - 1][j];
            }

            // ตรวจสอบกรณีที่สามารถเลือกไอเทมได้
            if (j - w[i] < 0) {
                b = -1;  // ถ้าน้ำหนักเกิน ไม่สามารถเลือกไอเทมนี้ได้
            } else if (j - w[i] == 0 || i - 1 < 0) {
                b = v[i];  // ถ้าน้ำหนักเท่ากับค่าของไอเทม
            } else {
                b = u[i - 1][j - w[i]] + v[i];  // คำนวณมูลค่าที่ดีที่สุดจากการเลือกไอเทมนี้
            }

            // อัปเดตตาราง u และ y
            if (a > b) {
                u[i][j] = a;  // ไม่เลือกไอเทม
            } else {
                u[i][j] = b;  // เลือกไอเทม
                y[i][j] = y[i - 1][j - w[i]] | (1 << i);  // บันทึกการเลือกไอเทม
            }
        }
    }

    static int x[100];  // เก็บผลลัพธ์ว่าควรเลือกไอเทมไหน
    for (int i = 0; i < n; i++) {
        x[i] = (y[n - 1][wx] & (1 << i)) ? 1 : 0;  // ใช้ bitwise operation เพื่อเลือกไอเทมที่ดีที่สุด
    }

    return x;
}