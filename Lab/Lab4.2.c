/*มื่อพอยน์เตอร์ 2 ระดับถูกประกาศใน main() แล้วฟังก์ชันย่อยจะเปลี่ยนการชี้ไปที่อื่นๆ ได้อย่างไร? และจะนำข้อมูลที่ชี้อยู่มาใช้งานในฟังก์ชันได้อย่างไร?

#include <stdio.h>

void go( int ***p, int **z ) ;

int main() {
    int *b = new int ; *b = 10 ;
    int *c = new int ; *c = 20 ;
    int **a ;
    go( &a, &b ) ;
    printf( "%d %p %p %p \n", **a, *a, a, &a ) ;
    go( &a, &c ) ;
    printf( "%d %p %p %p \n", **a, *a, a, &a ) ;
    return 0 ;
}//end function
*/