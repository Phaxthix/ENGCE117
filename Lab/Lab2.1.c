/*เขียนคำสั่งในการสร้างและเรียกใช้ฟังก์ชัน reverse() ตามโปรโตไทป์ต่อไปนี้ เพื่อนำข้อความจาก str1 มากลับอักขระหน้าไปหลัง และเก็บไว้ใน str2
ตัวอย่างเช่น str1 = "I love you"
จะได้ str2 = "uoy evol I"

#inclue <stdio.h>

void reverse( char str1[], char str2[] ) ;

int main() {
    char text[ 50 ] = "I Love You" ;
    char out[ 50 ] ;
    reverse( text, out ) ;
    return 0 ;
}//end function
*/

#include <stdio.h>

int main() {
    char text[50] = "I love you" ; // ข้อความต้นฉบับ
    char out[50] ; // พื้นที่สำหรับข้อความที่กลับด้าน
    int length = 0 ;

    // หาความยาวของ str1 (ไม่ใช้ strlen)
    while ( text[length] != '\0' ) {
        length++ ;
    }

    // กลับด้านข้อความ
    for ( int i = 0 ; i < length; i++ ) {
        out[i] = text[length - i - 1] ;
    }
    out[length] = '\0' ; // เติมเครื่องหมาย null เพื่อจบสตริง

    // แสดงผลลัพธ์
    printf( "Original String: %s\n", text ) ;
    printf( "Reversed String: %s\n", out ) ;

    return 0 ;
}



