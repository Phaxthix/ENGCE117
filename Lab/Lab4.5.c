/*จากการสร้างสตรัคท์ studentNode ,​ประกาศตัวแปร และกำหนดค่าใน main ดังต่อไปนี้ จงเขียนคำสั่งในการสร้างและเรียกใช้ฟังก์ชัน GoNext2() ตามโปรโตไทป์ต่อไปนี้
 เพื่อตรวจว่ามีโหนดถัดไปหรือไม่ถ้ามีก็ให้เปลี่ยน now2 ไปชี้ที่ข้อมูลโหนดถัดไป และแสดงข้อมูลในโหนดนั้น (สังเกตด้วยว่าหลังเรียกใช้ฟังก์ชันแล้ว now2 เปลี่ยนที่ชี้หรือไม่)
 
 #include <stdio.h>
#include <string.h>

structure studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void saveNode( struct studentNode *child, char n[], int a, char s, float g ) ;
void GoNext2( struct studentNode **walk ) ;

int main() {
    structure studentNode *start, *now1, **now2 ;
    start = new struct studentNode ;
    SaveNode( start, "one", 6, 'M', 3.11 ) ;
 
    start->next = new struct studentNode ;
    SaveNode( start->next, "two", 8, 'F', 3.22 ) ;
 
    start->next->next = new struct studentNode ;
    SaveNode( start->next->next, "three", 10, 'M', 3.33 ) ;

    start->next->next->next = new struct studentNode ;
    SaveNode( start->next->next->next, "four", 12, 'F', 3.44 ) ;

    now1 = start ;
    now2 = &start ;

    GoNext2( now2 ) ;
    printf( "%s ", (*now2)->name ) ;

    return 0 ;
}//end function

void SaveNode( struct studentNode *child, char n[], int a, char s, float g ) {
    strcpy( child->name, n ) ;
    child->age = a ;
    child->sex = s ;
    child->gpa = g ;
}//end function
 */