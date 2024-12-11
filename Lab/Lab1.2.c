/*เขียนคำสั่งในการสร้างและเรียกใช้งานฟังก์ชัน GetSet() เพื่อรับจำนวนสมาชิกและค่าของแต่ละสมาชิกในเซต จากคีย์บอร์ด ตามโปรโตไทป์ต่อไปนี้

#include <stdio.h>

int GetSet( int [] ) ;

int main() {
    int *data, num ;
    num = GetSet( &data ) ;
    return 0 ;
}//end function
*/

#include <stdio.h>
#include <string.h>


void GetSet( int a[], int *num ) ;

int main() {
    int data[ 100 ] , n = 0 ;
    GetSet( data, &n ) ;
    return 0 ;
}//end function


void GetSet( int a[] , int *num ) {
    printf( "Enter n : ") ;
    scanf( "%d" , num ) ;

    printf( "Enter data : " ) ;
    for ( int i = 0 ; i < *num ; i++ ) {
        scanf( "%d" , &a[i] ) ;
    }//end for
    
    for ( int i = 0 ; i < *num ; i++ ) {
        printf( "%d " , a[ i ] ) ;
    }//end for
    
} //end GetSet