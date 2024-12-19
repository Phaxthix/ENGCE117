/*เมื่อพอยน์เตอร์ 1 ระดับ ถูกประกาศใน main() แล้วฟังก์ชันย่อยจะเปลี่ยนการชี้ไปที่อื่นๆ ได้อย่างไร? และจะนำข้อมูลที่ชี้อยู่มาใช้งานในฟังก์ชันได้อย่างไร?
#include <stdio.h>

void go( int **p, int *z ) ;

int main() {
    int *a, b = 10, c = 20 ;
    go( &a, &b ) ;
    printf( "%d %p %p\n", *a, a, &a ) ;
    go( &a, &c ) ;
    printf( "%d %p %p\n", *a, a, &a ) ;
    return 0 ;
}//end function
*/