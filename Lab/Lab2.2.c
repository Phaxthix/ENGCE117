/*เขียนคำสั่งในการสร้างและเรียกใช้ฟังก์ชัน reverse() ตามโปรโตไทป์ต่อไปนี้ เพื่อนำข้อความจาก str1 มากลับอักขระหน้าไปหลัง และเก็บไว้ใน str2
ตัวอย่างเช่น str1 = "I love you"
จะได้ str2 = "uoy evol I"
#inclue <stdio.h>
char* reverse( char str1[]) ;
int main() {
    char text[ 50 ] = "I Love You" ;
    char *out ;
    out = reverse( text ) ;
}//end function
*/

#include <stdio.h>
#include <string.h>

char* reverse(char str1[]) {
    static char str2[50] ; // Static array to store reversed string
    int len = strlen( str1 ) ; // Find the length of the string

    for ( int i = 0; i < len; i++ ) {
        str2[i] = str1[len - i - 1] ; // Copy characters in reverse order
    }
    str2[len] = '\0'; // Null-terminate the reversed string

    return str2 ;
}

int main() {
    char text[50] = "I Love You" ;
    char *out;

    out = reverse(text); // Call reverse function

    printf( "Original: %s\n", text ) ;
    printf( "Reversed: %s\n", out ) ;

    return 0 ;
}



