#include <stdio.h>
#include <stdlib.h>

void ReadMatrix( int matrix[ ], int rows, int cols ) ;

int main( ) {
    int rows , cols ;

    // รับขนาดเมทริกซ์จากผู้ใช้
    printf( " Enter the number of rows: " ) ;
    scanf( " %d " , &rows ) ;
    printf( " Enter the number of columns: " ) ;
    scanf( " %d ", &cols ) ;

    // ตรวจสอบขนาดของเมทริกซ์
    if ( rows == 0 && cols == 0 ) {
        printf( " Matrix:\n(Empty)\n " )  ;
        return 0 ;
    } else if ( rows == 0 || cols == 0 ) {
        printf( " Error: Invalid matrix dimensions.\n " ) ;
        return 0 ;
    }

    // จองหน่วยความจำให้กับเมทริกซ์
    int *matrix = ( int* )malloc( rows * cols * sizeof(int) ) ;
    if ( matrix == NULL ) {
        printf( " Error: Memory allocation failed.\n " ) ;
        return 1 ;
    }

    // อ่านค่าจากผู้ใช้
    ReadMatrix( matrix, rows, cols ) ;

    // แสดงเมทริกซ์
    printf( " Matrix (%d x %d):\n ", rows, cols ) ;
    for ( int i = 0 ; i < rows; i++ ) {
        for ( int j = 0 ; j < cols; j++ ) {
            printf( " %d ", matrix[i * cols + j] ) ;
        }
        printf( " \n " ) ;
    }

    // คืนหน่วยความจำ
    free( matrix ) ;

    return 0 ;
}

void ReadMatrix( int matrix[], int rows, int cols ) {
    printf( " Enter the matrix elements: "  ) ;
    for (int i = 0 ; i < rows ; i++) {
        for ( int j = 0 ; j < cols ; j++ ) {
            scanf( "%d", &matrix[i * cols + j] ) ;
        }
    }
}