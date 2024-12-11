//จงเขียนคำสั่งในการสร้างและเรียกใช้งานฟังก์ชัน GetSet() เพื่อรับจำนวนสมาชิกและค่าของแต่ละสมาชิกในเซต จากคีย์บอร์ด ตามโปรโตไทป์ต่อไปนี้
/*
    #include <stdio.h>
    int *GetSet( int * ) ;

    int main() {
     int *data, num ;
     data = GetSet( &num ) ;
     return 0 ;
    }//end function
*/

#include <stdio.h>

int *GetSet( int *n ) ;

int main( ) {
    int num ;
    GetSet( &num ) ;
    return 0 ;
} //end function

int *GetSet( int *n ) {
    int set [ 100 ] ;


    printf( "Enter the number of set: " ) ;
    scanf( "%d" , n ) ;

    printf( "Enter the set : " ) ; 
    for ( int i = 0 ; i< *n ; i++ ) {
        scanf( "%d", &set[ i ] ) ;
    } // end for 

    printf( "Numder or set : %d\n , *n " ) ;

    for( int i =0 ; i< *n; i++ ) {
        printf( "%d" , set[ i ] ) ;
    } //end for
    return 0 ;
} //end Getset 