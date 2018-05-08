#define MAX_PEOPLE 1000 // maximum num. of people per triop
#define MAX_EXPENSE 10000.00 //maximum expense of a sigle people

#include <iostream>

int check_input_continue(void);
void get_user_input(int, float*);
float average_calculate(int, float*);
void minimum_money_transfer();
void printing_func();

int main(void){

    while(1)
    {
        int number_of_people=check_input_continue();
        if(number_of_people==0)
            break; // get out while when 0
        
        float expense_data[number_of_people]={0.0};
        get_user_input(number_of_people, expense_data);
/* debug code
        for(int ii=0;ii<number_of_people;ii++){
            std::cout<<expense_data[ii]<<"\n";
        }
*/
        float average_value=0.0;
        average_value = average_calculate(number_of_people, expense_data);
        minimum_money_transfer();
        printing_func();
    }
    return 0;
}

int check_input_continue(void){
    int number_of_people=0;
    std::cin>>number_of_people;
    return number_of_people;
}

void get_user_input(int number_of_people, float *return_data){
    for(int ii=0;ii<number_of_people;ii++)
    {
        std::cin>>*(return_data+ii);
    }
}

float average_calculate(int number_of_people, float *input_data){
    float temp_sum=0.0;
    
    for(int ii=0;ii<number_of_people;ii++){
        temp_sum += *(input_data+ii);        
    }
    // need rounding
    return temp_snm/number_of_people;
}