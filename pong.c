#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define LIN 6
#define COL 7



char arr[LIN][COL];
char bot[] = "  1   2   3   4   5   6   7  ";
char structure[] = "|---|---|---|---|---|---|---|";
char sign_1 = 'X';
char sign_2 = 'O';
char actual_sign = 'X';
int col = 0;





void array_init();
void print_array();
void current_arr();
void choice();
void fill_col();



main()
{  
    array_init();
    print_array();
    current_arr();

    while (42) {  
        printf("Player %c, it's your turn !\n", actual_sign);
        choice();
        printf("\n\n\n");
        current_arr();
    }

    return 0;
}








// Initialize the array
void array_init(void) {

  int x, y;

  for( x = 0; x < LIN; x++) {  

      for( y  = 0; y < COL; y++) { 
          arr[x][y] = ' ';
      }
  }
    
}


void print_array() {  
    int x, y;

    for( x = 0; x < LIN; x++) {  
    
      for( y  = 0; y < COL; y++) {  
        printf("%c", arr[x][y]);
    } 
    printf("\n");

  }

}
// Print the current array
void current_arr() {  

    printf("%s\n", structure);  /* Head of grid */

    int x, y;

    for(x = 0; x < LIN; x++) { 

      for( y = 0; y < COL; y++) { 

        printf("| %c ", arr[x][y]);
        
        }
        printf("|\n");
        printf("%s\n", structure);
        

    }
    printf("%s\n", bot);
}

// Fill the choosed column with the actual player's sign
void fill_col(){
    int lvl ; /* Actual bottom of the grid */

    for(lvl = LIN - 1; lvl >= 0; lvl--){  
        if(arr[lvl][col] == ' '){  
            arr[lvl][col] = actual_sign;
            break; 
        }
    }

}

// The player choose the column 
void choice() {
    char c; 

    while (42) {  
        printf("\nChoose the column : ");
        scanf(" %c", &c);
        switch (c) {
            case '1':
                col = 0;
                break;
            case '2':
                col = 1;
                break;
            case '3':
                col = 2;
                break;
            case '4':
                col = 3;
                break;
            case '5':
                col = 4;
                break;
            case '6':
                col = 5 ;
                break;
            case '7' :
                col = 6;
                break;
            default :
                col = 666;
                printf("\nWrong insert ! Try Again ! \n\n");
                current_arr();

        }

        if((col >= 0 && col <= 6) && (arr[0][col] == ' ')){
            fill_col();
            actual_sign = (actual_sign == sign_1) ? sign_2 : sign_1;
            break;
        }
    }
  

}










// Comment section

/*


*/