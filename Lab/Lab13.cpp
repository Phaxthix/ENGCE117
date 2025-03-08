#include <stdio.h>

int KnapsackBT( int *w, int *v, int n, int wx, int i, int *x );

int main() {
    int n = 5, wx = 11, vx, i ;
    
    // รับข้อมูลจำนวนไอเทม (n) และน้ำหนักสูงสุดที่กระเป๋าสามารถรับได้ (wx)
    printf( "Enter n : " ) ;
    scanf( "%d", &n ) ;
    printf( "Enter wx : " ) ;
    scanf( "%d", &wx ) ;
    
    // กำหนดอาร์เรย์สำหรับน้ำหนักและมูลค่าของแต่ละไอเทม
    int *w = new int[ n ] ;
    int *v = new int[ n ] ;
    
    // รับข้อมูลน้ำหนักของแต่ละไอเทม
    for( i = 0 ; i < n ; i++ ) {
        printf( "weight for item %d : ", i ) ;
        scanf( "%d", &w[ i ] ) ;
    }
    
    // รับข้อมูลมูลค่าของแต่ละไอเทม
    for( i = 0 ; i < n ; i++ ) {
        printf( "value for item %d : ", i ) ;
        scanf( "%d", &v[ i ] ) ;
    }
    
    // กำหนดอาร์เรย์สำหรับเก็บผลการเลือกไอเทมที่ดีที่สุด
    int *x = new int[n] ;
    
    // เรียกใช้ฟังก์ชัน KnapsackBT เพื่อตรวจสอบการเลือกไอเทมที่ดีที่สุด
    vx = KnapsackBT( w, v, n, wx, 0, x ) ;
    
    // แสดงผลการเลือกไอเทมที่ดีที่สุด
    printf("Selected items: ");
    for( int i = 0 ; i < n ; i++ ) {
        printf( "%d ", x[ i ] ) ;
    }
    
    // คำนวณและแสดงมูลค่าที่ดีที่สุดที่สามารถบรรจุในกระเป๋า
    printf( "\nValue = %d", vx ) ;
    return 0 ;
}

// ฟังก์ชัน KnapsackBT ที่ใช้ Backtracking ในการหาคำตอบ
int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {
    int b = 0, a = 0;
    int y[100] = {0}; // ใช้เพื่อเก็บสถานะการเลือกไอเทมในแต่ละรอบ
    for (int k = i; k < n; k++) {
        // ตรวจสอบว่าไอเทมนี้สามารถเลือกได้หรือไม่
        if (w[k] <= wx) {
            y[k] = 1; // เลือกไอเทม
            // เรียกฟังก์ชันซ้ำเพื่อพิจารณาไอเทมตัวถัดไป
            a = v[k] + KnapsackBT(w, v, n, wx - w[k], k + 1, y);
            
            // หากการเลือกนี้ได้มูลค่าสูงกว่า ให้เก็บค่าใหม่และอัปเดตการเลือก
            if (a > b) {
                b = a;
                // คัดลอกผลการเลือกไอเทมที่ดีที่สุดไปยัง x
                for (int j = 0; j < n; j++) {
                    x[j] = y[j];
                }
            }
            y[k] = 0; // ยกเลิกการเลือกไอเทมนี้
        }
    }
    return b; // คืนค่ามูลค่าสูงสุด
}