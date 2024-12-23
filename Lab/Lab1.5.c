/*จงเขียนคำสั่งในการสร้างและเรียกใช้งานฟังก์ชัน GetSet() เพื่อรับจำนวนสมาชิกและค่าของแต่ละสมาชิกในเซต จากคีย์บอร์ด ตามโปรโตไทป์ต่อไปนี้

#include <stdio.h>

void GetMatrix( int value[], int *row, int *col ) ;

int main() {
    int *data, m, n ;
    GetMatrix( &data, &m, &n ) ;
    return 0 ;
}//end function
*/


#include <stdio.h>
#include <stdlib.h>

void GetMatrix( int value[][ 5 ] , int *row , int *col ) ;

int main() {
    int data[ 100 ][ 5 ] , m , n ;
    GetMatrix( data , &m , &n ) ;
    return 0 ;
}//end function

void GetMatrix( int value[ ][ 5 ] , int *row , int *col ) {
    char ch ;
    int count = 0 ;

    printf("Enter the number of rows: ") ;
    scanf( "%d" , row) ;

    printf( "Enter the number of columns: " ) ;
    scanf( "%d" , col ) ;

    if ( *row == 0 && *col == 0 ) {
        printf( "Matrix:\n(empty)" ) ;    
    } else if ( *row == 0 && *col != 0 || *col == 0 && *row != 0 ) {
         printf( "Error: Invalid matrix dimensions." ) ;
    } else {
        printf( "Enter Enter the matrix elements: " ) ; //input
        for( int i = 0 ; i < *row ; i++ ) {
            for( int j = 0 ; j < *col ; j++ ) {
                scanf( "%d" , &value[ i ][ j ] ) ;
                ch = getchar() ; //เอาไว้เก็บ /n
                if ( ch == '\n' && j != *col - 1 ) {
                    printf( "Error: Incorrect number of elements." ) ;
                    exit( 1 ) ;
                }//end if เช็คว่ากรอกครบหรือยัง
                count += 1 ;
            }//end for columns
        }//end for rows

        printf( "Matrix ( %d x %d )\n" , *row , *col ) ; //output
        for( int i = 0 ; i < *row ; i++ ) {
            for( int j = 0 ; j < *col ; j++ ) {
                printf( "%d " , value[ i ][ j ] ) ;
            }//end for columns
            printf( "\n" ) ;
        }//end for rows
    }//end else
}//end GetMatrix
