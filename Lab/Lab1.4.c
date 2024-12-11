/*จงเขียนคำสั่งในการสร้างและเรียกใช้งานฟังก์ชัน GetSet() เพื่อรับจำนวนสมาชิกและค่าของแต่ละสมาชิกในเซต จากคีย์บอร์ด ตามโปรโตไทป์ต่อไปนี้
#include <stdio.h>

int GetSet( int [] ) ;

int main() {
    int *data, num ;
    num = GetSet( &data ) ;
    return 0 ;
}//end function
*/

#include <stdio.h>

int GetSet( int *arr[] ) ;

int main() {
    int *data[ 100 ] , num ;
    num = GetSet( data ) ;
    return 0 ;
}//end function

int GetSet( int *data[] ) {
    int n ;

    printf( "Enter the number of elements:" ) ;
    scanf( "%d" , &n ) ;

    printf( "Enter the elements : " ) ;
    for ( int i = 0 ; i < n ; i++ ) {
        scanf( "%d" , &data[ i ] ) ;

    }
    printf( "Enter the elements" ) ;
    for ( int i = 0 ; i < n ; i++ ) {
        printf( "%d " , data[ i ] ) ;
    }//end for แสดงค่า

    return 0 ;
}//end GetSet