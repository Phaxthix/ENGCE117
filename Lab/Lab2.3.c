/*เขียนคำสั่งในการสร้างและเรียกฟังก์ชัน explode() ตามโปรโตไทป์ต่อไปนี้ เพื่อนำข้อความจาก str1 มาแยกเป็นหลายข้อความเก็บไว้ใน str2 โดยใช้ตัวอักขระใน splitter เป็นตัวแบ่งแยก และ count เก็บจำนวนข้อความที่แบ่งได้

ตัวอย่างเช่น

str1 = "I/Love/You" splitter = '/'

จะได้ผลลัพธ์คือ

str2[0] = "I"
str2[1] = "Love"
str2[2] = "You" count = 3

#include <stdio.h>

void explode( char str1[], char splitter, char str2[][10], int *count ) ;

int main() {
    char out[ 20 ][ 10 ] ;
    int num ;
    explode( "I/Love/You", "/" ) ;
    return 0 ;
}//end function
*/
