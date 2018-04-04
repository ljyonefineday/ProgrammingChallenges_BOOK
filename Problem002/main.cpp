#include <iostream>

//function
void check_mine_map(int, int, char*, char*);
void print_mine_map(int, int, char*);

int main(void){
    
    int row(0), column(0);
    //get user input column and row
    std::cin>>row>>column;
    
    //initialize
    char mine_map[row][column];
    char unvailed_mine_map[row][column];
    
    //mine mapping with user inputs
    for(int ii=0;ii<row;ii++){
        std::cin>>mine_map[ii];
    }
    //initialize "unvailed_mine_map"
    for(int ii=0;ii<row;ii++){
        for(int jj=0;jj<column;jj++){
            unvailed_mine_map[ii][jj]='0';
        }
    }
// printings for debugs
/*    //printing "mine_map"
    for(int ii=0;ii<row;ii++){
        for(int jj=0;jj<column;jj++){
            std::cout<<mine_map[ii][jj];
        }
        std::cout<<std::endl;
    }
    //printing "unvailed_mine_map"
    for(int ii=0;ii<row;ii++){
        for(int jj=0;jj<column;jj++){
            std::cout<<unvailed_mine_map[ii][jj];
        }
        std::cout<<std::endl;
    }
*/

    //
    check_mine_map(row,column,&mine_map[0][0],&unvailed_mine_map[0][0]);
    print_mine_map(row,column,&unvailed_mine_map[0][0]);
    return 0;
}

// function for printing mine map
void check_mine_map(int row, int column, char *user_mine_map_pointer, char *user_unvailed_map_pointer){
    for(int ii=0;ii<row;ii++){
        for(int jj=0;jj<column;jj++){
            if(*(user_mine_map_pointer+column*ii+jj)=='*'){//mine spotted
                //check mine
                *(user_unvailed_map_pointer+ii*column+jj)='*';
                //check mine numbers
                for(int rowcounter=ii-1;rowcounter<=ii+1;rowcounter++){
                    if(rowcounter<0||rowcounter>=row) continue;
                    for(int columncounter=jj-1;columncounter<=jj+1;columncounter++){
                        if(columncounter<0||columncounter>=column) continue;
                        if(*(user_unvailed_map_pointer+rowcounter*column+columncounter)=='*') continue;
                        *(user_unvailed_map_pointer+rowcounter*column+columncounter)+=1;
                    }
                }

            }
        }
    }
}

void print_mine_map(int row, int column, char* printing_target){
    for(int ii=0;ii<row;ii++){
        for(int jj=0;jj<column;jj++){
            std::cout<<*(printing_target+column*ii+jj);
        }
        std::cout<<std::endl;
    }
}