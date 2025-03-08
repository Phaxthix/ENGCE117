#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse( const char str1[] ) ;

int main() {
    char text[ 50 ] ;

    printf( " Enter str1: " ) ;
    scanf( " %49[^\n] ", text ) ;

    char *output = reverse( text ) ;
    if ( output == NULL ) {
        printf( " Error: Memory allocation failed.\n " ) ;
        return 1 ;
    }

    printf( " FUNC: %s\n ", output ) ;
    printf( " MAIN: %s\n ", output ) ;

    free( output ) ; // คืนหน่วยความจำ
    return 0 ;
}

char* reverse(const char str1[]) {
    int len = strlen(str1) ;
    char *str2 = (char*)malloc( (len + 1) * sizeof(char) ) ;

    if ( str2 == NULL ) return NULL ; // ตรวจสอบว่า malloc สำเร็จหรือไม่

    for ( int i = 0 ; i < len; i++ ) {
        str2[i] = str1[ len - i - 1 ] ;
    }
    str2[ len ] = '\0' ;

    return str2 ;
}


