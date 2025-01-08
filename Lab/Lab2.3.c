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

#include <stdio.h>
#include <string.h>

void explode( char str1[], char splitter, char str2[][10], int *count ) {
    int i = 0 , j = 0 , k = 0 ;
    *count = 0 ;

    while ( str1[i] != '\0' ) {
        if ( str1[i] == splitter ) {
            str2[j][k] = '\0' ; // End the current word
            j++ ; // Move to the next word
            k = 0 ; // Reset character index for the next word
        } else {
            str2[j][k++] = str1[i] ; // Add character to the current word
        }
        i++ ;
    }
    str2[j][k] = '\0' ; // Null-terminate the last word
    *count = j + 1 ; // Total number of words
}

int main() {
    char out[20][10] ; // Array to store split words
    int num ;

    explode( "I/Love/You" , '/' , out , &num ) ; // Call explode function

    printf( "Split words:\n" ) ;
    for ( int i = 0; i < num; i++ ) {
        printf( "str2[%d] = %s\n" , i , out[i] ) ;
    }
    printf( "Count = %d\n", num ) ;

    return 0 ;
}
