/*เมื่อลิงค์ลิสมีจุดเริ่มต้น (start) และโหนดปัจจุบัน (now) เป็นพอยน์เตอร์ 1 ระดับ ถูกประกาศใน main แล้ว...

ฟังก์ชัน AddNode() ทำหน้าที่เพิ่มโหนดต่อท้ายลิงค์ลิส ให้ now ชี้ node ใหม่

ส่วนฟังก์ชัน InsertNode() ทำหน้าที่แทรกโหนดใหม่ต่อจากโหนดปัจจุบัน

และฟังก์ชัน DelNode() มีหน้าที่ลบโหนดที่ต่อจากโหนดปัจจุบัน จะทำงานเป็นขั้นตอนอย่างไร?

จงนำทฤษฏีดังกล่าวมาสร้างฟังก์ชัน AddNode(), InsNode() และ DelNode() รองรับการเรียกใช้งาน

#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void ShowAll( struct studentNode *walk ) ;

int main() {
    struct studentNode *start, *now ;
    start = NULL ;
    now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
    now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
    InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
    InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
    DelNode( now ) ; ShowAll( start ) ;
 return 0 ;
}//end function

void showAll( struct studentNode *walk ) {
    while( walk != NULL ) {
        printf( "%s ", walk->name ) ;
        walk = walk->next ;
    }//end while
    printf( " " ) ;
}//end function
*/