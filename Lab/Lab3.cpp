#include <stdio.h>
#include <stdlib.h>

struct student {
    char Name[ 20 ] ;
    int Age;
};
typedef struct student SS ;

void GetStudent(int *N, SS ***students) {
    printf( " Enter number of groups (max 5): " ) ;
    scanf( " %d ", N ) ;

    if ( *N > 5 ) *N = 5 ; 
    if ( *N <= 0 ) {
        printf( " Error: Invalid group count.\n " ) ;
        exit(1) ;
    }

    // จองหน่วยความจำสำหรับกลุ่มนักเรียน
    *students = (SS **)malloc( *N * sizeof(SS *) ) ;
    for (int i = 0; i < *N; i++) {
        ( *students )[ i ] = ( SS * )malloc( 4 * sizeof(SS) ) ;
    }

    for (int i = 0; i < *N; i++) {
        printf("Class %d:\n", i + 1);
        for (int j = 0; j < 4; j++) {
            printf( " [ %d/4 ] Enter Student Info (Name Age): " , j + 1 ) ;
            scanf( " %19s %d ", ( *students )[ i ][ j ].Name, &( *students )[ i ][ j ].Age ) ;
        }
    }
}

void PrintStudent( SS **students, int N ) {
    for ( int i = 0 ; i < N ; i++ ) {
        printf( " Class %d:\n ", i + 1 ) ;
        for ( int j = 0; j < 4; j++ ) {
            printf( " %s %d\n ", students[ i ][ j ].Name, students[ i ][ j ].Age ) ;
        }
    }
}

void FreeMemory( SS **students, int N ) {
    for ( int i = 0 ; i < N ; i++ ) {
        free( students[ i ] ) ;
    }
    free( students ) ;
}

int main() {
    SS **children ;
    int group ;

    GetStudent( &group, &children ) ;
    PrintStudent( children, group ) ;
    FreeMemory( children, group ) ;

    return 0 ;
}
