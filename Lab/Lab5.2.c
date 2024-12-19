/*เมื่อลิงค์ลิสต์มีจุดเริ่มต้น (start) เป็นพอยน์เตอร์ 1 ระดับ และ โหนดปัจจุบัน (now) เป็นพอยน์เตอร์ 2 ระดับ ถูกประกาศใน main() แล้ว...

ฟังก์ชัน InsertNode() ทำหน้าที่แทรกโหนดใหม่ที่อยู่ก่อนโหนดปัจจุบัน

และฟังก์ชัน DelNode() มีหน้าที่ลบโหนดปัจจุบัน จะทำงานเป็นขั้นตอนอย่างไร?

จงนำหลักการนี้มาสร้างฟังก์ชัน GoNext(), InsNode() และ DelNode() รองรับการเรียกใช้งานดังต่อไปนี้
#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void ShowAll( struct studentNode **walk ) ;

int main() {
    struct studentNode *start, **now ;
    start = NULL ; now = &start ;
    InsNode( now, "one", 6, 'M', 3.11 ) ; ShowAll( &start ) ;
    InsNode( now, "two", 8, 'F', 3.22 ) ; ShowAll( &start ) ;
    GoNext( &now ) ;
    InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( &start ) ;
    InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( &start ) ;
    GoNext( &now ) ;
    DelNode( now ) ; ShowAll( s&tart ) ;
    return 0 ;
}//end function

void showAll( struct studentNode **walk ) {
    while( *walk != NULL ) {
        printf( "%s ", (*walk)->name ) ;
        walk = &(*walk)->next ;
    }//end while
    printf( " " ) ;
}//end function

*/