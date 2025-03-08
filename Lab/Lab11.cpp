#include <stdio.h>

//----| Greedy Algorithm : Shortest Path
void SetWeight(int *Town, int n, int i, int j, int Weight) {
    Town[i * n + j] = Weight;
}

int *Dijkstra(int *L, int n) {
    static int D[100];  // ใช้ static เพื่อเก็บค่าผลลัพธ์ของ D
    int C[100];  // เก็บเมืองที่ยังไม่ได้เลือก
    int v = -1;
    int sizeC = n - 1;

    // กำหนดค่าเริ่มต้นของ C (เมืองที่ยังไม่ได้เลือก)
    for (int i = 0; i < sizeC; i++) {
        C[i] = i + 1;
    }

    // ตั้งค่าระยะทางจากเมืองต้นทาง (เมือง 0) ไปยังเมืองอื่น
    for (int i = 1; i < n; i++) {
        D[i] = L[0 * n + i];
    }

    // ทำการคำนวณ Dijkstra โดยเลือกเมืองที่ใกล้ที่สุดทีละเมือง
    for (int count = 0; count < n - 1; count++) {
        int min = 9999;
        for (int i = 0; i < sizeC; i++) {
            if (D[C[i]] < min) {
                min = D[C[i]];
                v = C[i];
            }
        }

        // ลบเมืองที่เลือกออกจากรายการเมืองที่ยังไม่ได้เลือก
        for (int i = 0; i < sizeC; i++) {
            if (C[i] == v) {
                for (int j = i; j < sizeC - 1; j++) {
                    C[j] = C[j + 1];
                }
                sizeC--;
                break;
            }
        }

        // อัปเดตระยะทางไปยังเมืองอื่น ๆ ที่ยังไม่ได้เลือก
        for (int i = 0; i < sizeC; i++) {
            int w = C[i];
            if (D[w] > D[v] + L[v * n + w]) {
                D[w] = D[v] + L[v * n + w];
            }
        }
    }

    return D;  // ส่งคืนอาร์เรย์ D ที่เก็บระยะทางที่สั้นที่สุด
}

void InitializeGraph(int *g, int n, int value) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i * n + j] = value;  // ตั้งค่าทุกจุดในกราฟเป็นค่าเริ่มต้น
        }
    }
}

void PrintGraph(int *g, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", g[i * n + j]);
        }
        printf("\n");
    }
}

void PrintArrayAndMax(int *arr, int size) {
    int Max = -9999;
    for (int i = 1; i <= size; i++) {
        printf("%d ", arr[i]);
        if (arr[i] > Max) {
            Max = arr[i];
        }
    }
    printf("\nTotal Range = %d\n", Max);
}


//----| Greedy Algorithm : Knapsack Problem
int *KnapsackGreedy(int *w, int *v, int n, int wx) {
    static int x[100];  // ตัวแปรนี้จะเก็บผลลัพธ์ว่าเลือกสินค้าชิ้นไหน
    int weight = 0;

    for (int i = 0; i < n; i++) {
        x[i] = 0;  // เริ่มต้นไม่เลือกสินค้าชิ้นไหน
    }

    while (weight < wx) {
        int bestIndex = -1;
        float bestValuePerWeight = 0;

        for (int i = 0; i < n; i++) {
            if (x[i] == 0) {
                float valuePerWeight = (float)v[i] / w[i];  // คำนวณความคุ้มค่าของสินค้าต่อหน่วยน้ำหนัก
                if (valuePerWeight > bestValuePerWeight) {
                    bestValuePerWeight = valuePerWeight;
                    bestIndex = i;
                }
            }
        }

        if (bestIndex != -1) {
            if (weight + w[bestIndex] <= wx) {  // ถ้าน้ำหนักยังไม่เกินขีดจำกัด
                x[bestIndex] = 1;  // เลือกสินค้าชิ้นนี้
                weight += w[bestIndex];  // เพิ่มน้ำหนักรวม
            } else {
                break;  // ถ้าน้ำหนักเกินขีดจำกัด ให้หยุดการเลือกสินค้า
            }
        } else {
            break;  // ถ้าไม่มีสินค้าชิ้นไหนที่คุ้มค่ากว่า
        }
    }

    return x;  // ส่งคืนอาร์เรย์ที่บอกว่าเลือกสินค้าชิ้นไหนบ้าง
}

int main() {
    // ส่วนของ Shortest Path
    printf("Greedy Algorithm : Shortest Path\n");
    int n = 5, i, j, *d, *g, km;
    g = new int[n * n];

    printf("Enter number of towns: ");
    scanf("%d", &n);

    InitializeGraph(g, n, -1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter km from town %d to town %d: ", i, j);
            scanf("%d", &km);
            SetWeight(g, n, i, j, km);
        }
    }

    PrintGraph(g, n);

    d = Dijkstra(g, n);
    PrintArrayAndMax(d, n - 1);

    // ส่วนของ Knapsack Problem
    printf("\nGreedy Algorithm : Knapsack Problem\n");
    int wx = 11, ans = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter maximum weight of the knapsack: ");
    scanf("%d", &wx);

    int *w = new int[n];
    int *v = new int[n];

    for (i = 0; i < n; i++) {
        printf("Enter weight of item %d: ", i);
        scanf("%d", &w[i]);
    }
    for (i = 0; i < n; i++) {
        printf("Enter value of item %d: ", i);
        scanf("%d", &v[i]);
    }

    int *x = KnapsackGreedy(w, v, n, wx);
    printf("Selected items: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }

    for (int i = 0; i < n; i++) {
        if (x[i] == 1) ans += v[i];  // คำนวณผลรวมของมูลค่าของสินค้าที่เลือก
    }
    printf("\nTotal Value = %d\n", ans);

    return 0;
}
