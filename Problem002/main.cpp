#include <iostream>

//function
char* check_mine_map(int, int, char*);
void print_mine_map(int, int, char*);

int main(void){
    
    int row(0), column(0);
    //get user input column and row
    std::cin>>row>>column;
    
    char mine_map[row][column];
    char unvailed_mine_map[row][column];
    
    //mine mapping
    for(int ii=0;ii<row;ii++){
        std::cin>>mine_map[ii];
    }
    
    for(int ii=0;ii<row;ii++){
        for(int jj=0;jj<column;jj++){
            std::cout<<mine_map[ii][jj];
        }
        std::cout<<std::endl;
    }

    &unvailed_mine_map[0][0]=check_mine_map(row,column,&mine_map[0][0]);
    print_mine_map(row,column,&unvailed_mine_map[0][0]);
    return 0;
}

// function for printing mine map
char* check_mine_map(int row, int column, char *user_mine_map_pointer){
    //cast to 2D array
    char user_mine_map[row][column];
    for (int ii=0;ii<row;ii++){
        for(int jj=0;jj<column;jj++){
            user_mine_map[ii][jj]=*(user_mine_map_pointer+ii*column+jj);
        }
    }

    for(int ii=0;ii<row;ii++){
        for(int jj=0;jj<column;jj++){
            if(user_mine_map[ii][jj]=='*'){//mine spotted
                for(int rowcounter=ii-1;rowcounter<=ii+1;rowcounter++){
                    for(int columncounter=jj-1;columncounter<=jj+1;columncounter++){
                        if(rowcounter<0 || columncounter<0 || rowcounter>=row || columncounter>=column) continue;
                        if(unvailed_mine_map[rowcounter][columncounter]=='*') continue;
                        else unvailed_mine_map[rowcounter][columncounter]+=1;
                    }//columncounter            
                }//rowcounter
                unvailed_mine_map[ii][jj]='*';
            }//if
        }
    }
    return &unvailed_mine_map[0][0];
}

void print_mine_map(int row, int column, char* printing_target){
    for(int ii=0;ii<row;ii++){
        for(int jj=0;jj<column;jj++){
            std::cout<<*(printing_target+column*ii+jj);
        }
        std::cout<<std::endl;
    }
}