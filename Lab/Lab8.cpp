#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Customer {
    public :
        char Name[20] ;
        int Age ;
        char Category[20] ;
        char Product[20] ;
        float Price ;
    public : 
        void GetCustomerInfo( char StrMode[ 50 ] ) ;
} ;

class FileHandler {
    public :
        FILE *fp ;
        char FilePath[ 100 ] ;
        Customer C[ 500 ] ;
        int MaxCustomer ;
    public :
        FileHandler( char FilePath[ 100 ] ) ;
        void GetFilePath() ;
        void ReadFile() ;
        void SelectMode() ;
} ;

int main() {
    FileHandler *F = new FileHandler( "customer.csv" ) ;
    //FileHandler *F = new FileHandler( "customer.txt" ) ;
    while( 1 ) F->SelectMode() ;
    return 0;
}

void FileHandler :: SelectMode() {
    int Mode = 0 ;
    //printf( "Select Mode : " ) ;
    scanf( "%d", &Mode ) ;

    if( Mode == 0 ) { //Exit
        printf( "\nThank you!." ) ;
        exit(0) ;
    } else if( Mode == 1 ) { //Who bought higest price
        float max = -9999 ;
        Customer higest_price ;
        for ( int i = 0 ; i < MaxCustomer ; i ++) {
            if ( C[i].Price > max) {
                max = C[i].Price ;
                Customer higest_price = C[i] ;
            }
        }
        higest_price.GetCustomerInfo("Who bought highest price.");
        
    } else if( Mode == 2 ) { //Lines of file
        printf( "File data = %d records.\n", this->MaxCustomer ) ;
        
    } else if( Mode == 3 ) { //Average Price
        float Average_sum = 0  ;
        for ( int i = 0 ; i < MaxCustomer ; i ++) {
           Average_sum += C[i].Price ;
        }
        printf( "Average price = %.2f\n", Average_sum/MaxCustomer ) ;
        
    } else if( Mode == 4 ) { //Count People who age above average.
        float Average_age = 0 ;
        for ( int i = 0 ; i < MaxCustomer ; i ++) {
           Average_age += C[i].Age ;
        }
        printf( "Average age = %.2f\n", Average_age/MaxCustomer ) ;
        
    } else if( Mode == 5 ) { //Most Popular Product
        char Pop[100][100] ;
        int UniqueCount = 0 , Count[100] = {0} , j = 0 ;
        for ( int i = 0; i < MaxCustomer; i++) {
            for(  j = 0 ; j < UniqueCount ; j++ )
                if (strcmp(C[i].Product, Pop[j]) == 0) { 
                    Count[j] ++ ;
                    break ;
                } 
                if ( j == UniqueCount ) {
                    strcpy(Pop[UniqueCount], C[i].Product); 
                    Count[UniqueCount] = 1;  
                    UniqueCount++; 
                }
        }
        int Popular = -9999 ; char category [100] ;
        for ( int i = 0; i < UniqueCount; i++) {
            if ( Count[i] > Popular ) {
                Popular = Count[i] ;
                strcpy (category , C[i].Product ) ;
            }
        }
        printf( "Most popular product = %s (sold %d times).\n" , category , Popular) ;
        

    } else if( Mode == 6 ) { //Least Popular Product
          char Pop[100][100] ;
        int UniqueCount = 0 , Count[100] = {0} , j = 0 ;
        for ( int i = 0; i < MaxCustomer; i++) {
            for(  j = 0 ; j < UniqueCount ; j++ )
                if (strcmp(C[i].Category, Pop[j]) == 0) { 
                    Count[j] ++ ;
                    break ;
                } 
                if ( j == UniqueCount ) {
                    strcpy(Pop[UniqueCount], C[i].Category); 
                    Count[UniqueCount] = 1;  
                    UniqueCount++; 
                }
        }
        int Popular = 9999 ; char category [100] ;
        for ( int i = 0; i < UniqueCount; i++) {
            if ( Count[i] < Popular ) {
                Popular = Count[i] ;
                strcpy (category , C[i].Category ) ;
            }
        }
        printf( "Most popular product = %s (sold %d times).\n" , category , Popular) ;
        
    } else {
        printf( "\nThank you!." ) ;
        exit(0) ;
    }
}

FileHandler :: FileHandler( char FilePath[ 100 ] ) {
    strcpy( this->FilePath, FilePath ) ;
    this->ReadFile() ;
}

void FileHandler :: ReadFile() {
    fp = fopen( "./output/customer.csv" , "r");
    //fp = fopen( "customer.txt", "r"); 
    if ( fp == NULL) {
        //printf("Error opening file: %s\n", this->FilePath);
    } else {
        //printf("File opened successfully: %s\n", this->FilePath);
    }
    
    char line[100] ;
    int Member = 0 ;
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok( line , "," ) ;
        strcpy(C[Member].Name , token ) ;
        token = strtok( NULL , "," ) ;
        C[Member].Age = atoi(token) ;
        token = strtok( NULL , "," ) ;
        strcpy(C[Member].Category , token ) ;
        token = strtok( NULL , "," ) ;
        strcpy(C[Member].Product , token ) ;
        token = strtok( NULL , "," ) ;
        C[Member].Price = atof(token) ;
        
        this->MaxCustomer ++ ;
        Member++ ;
        
        
    }
    //for(int i = 0 ; i < Member ; i++) {
        //printf( " %s" , C[i].Name ) ;
        //printf( " %d" , C[i].Age ) ;
        //printf( " %s" , C[i].Category ) ;
        //printf( " %s" , C[i].Product ) ;
        //printf( " %0.f\n" , C[i].Price ) ;
    //}   
}

void Customer :: GetCustomerInfo( char StrMode[ 50 ] ) {
    printf( "--------| %-8s\n", StrMode ) ;
    printf("%-8s : %-10s\n", "Name", this->Name ) ; 
    printf("%-8s : %-4d\n", "Age", this->Age ) ;
    printf("%-8s : %-10s\n", "Category", this->Category ) ; 
    printf("%-8s : %-10s\n", "Product", this->Product ) ; 
    printf("%-8s : %-5.2f\n", "Price", this->Price ) ; 
}

void FileHandler :: GetFilePath() {
    printf("Current file path: %s\n", this->FilePath);
}