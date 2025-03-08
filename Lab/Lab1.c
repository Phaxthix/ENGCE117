/*
เขียนคำสั่งในการสร้างและเรียกใช้ฟังก์ชัน GetStudent() ตามโปรโตไทป์ต่อไปนี้ เพื่อรับจำนวนห้องเรียน และข้อมูลของนักเรียนห้องละ 10 คนจากคีย์บอร์ด

#include <stdio.h>

void GetStudent( struct student child[][ 10 ], int *room ) ;

int main() {
    struct student children[ 20 ][ 10 ] ;
    int group ;
    GetStudent( children, &group ) ;
    return 0 ;
}//end function
*/

#include <stdio.h>
#include <string.h>

struct student {
    char name[ 20 ] ;
} ; 


void GetStudent( struct student child[][ 10 ] , int *room ) ;

int main() {
    struct student children[ 20 ][ 10 ] ; 
    int group ;
    printf( "Enter Room " ) ;
    scanf( "%d" , &group ) ;
    getchar() ; 

    GetStudent( children, &group ) ;
    return 0 ;
}//end function

void GetStudent( struct student child[][ 10 ] , int *room ) {
    for ( int i = 0 ; i < *room ; i++ ) {
        printf( "Room %d :\n" , i + 1 ) ;
         for ( int j = 0; j < 10 ; j++ ) {
            printf( "Student %d : " , j + 1 ) ;
            fgets( child[ i ][ j ].name , sizeof( child[i][j].name  ) , stdin ) ;
            child[ i ][ j ].name[ strcspn( child[ i ][ j ].name , "\n" ) ] = '\0' ;
        }//end for scan 10 user
    }//end for scan room
    printf( "\n" ) ;
    for ( int i = 0; i < *room ; i++ ) {
        printf( "Room %d: 10 students entered.\n" , *room ) ;
    }//end for print room
}//end GetStudent