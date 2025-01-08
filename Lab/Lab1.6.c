/*เขียนคำสั่งในการสร้างและเรียกใช้ฟังก์ชัน GetMatrix() เพื่อรับจำนวนแถว คอลัมน์ และค่าของแต่ละสมาชิกในเมทริกซ์จากคีย์บอร์ดตามโปรโตไทป์ต่อไปนี้

#include <stdio.h>
int GetMatrix( int *row, int *col ) ;
int main() {
    int *data, m, n ;
    data = GetMatrix( &m, &n ) ;
    return 0 ;
}//end function
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n ;

    // รับจำนวนแถวและจำนวนคอลัมน์
    printf( "Enter number of rows: " ) ;
    scanf( "%d", &m ) ;

    printf( "Enter number of columns: " ) ;
    scanf( "%d", &n ) ;

    // จองหน่วยความจำสำหรับเมทริกซ์
    int *matrix = (int *)malloc(m * n * sizeof(int)) ;
    if ( matrix == NULL ) {
        printf( "Memory allocation failed!\n" ) ;
        return 1;
    }

    // รับค่าของแต่ละสมาชิกในเมทริกซ์
    printf( "Enter the elements of the matrix:\n" ) ;
    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            printf( "Element [%d][%d]: " , i + 1, j + 1 ) ;
            scanf( "%d", &matrix[i * n + j] ) ;
        }
    }

    // แสดงเมทริกซ์
    printf( "\nThe entered matrix is:\n" ) ;
    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            printf( "%d ", matrix[i * n + j] ) ;
        }
        printf( "\n" ) ;
    }

    // คืนหน่วยความจำที่จองไว้
    free(matrix) ;

    return 0 ;
}
