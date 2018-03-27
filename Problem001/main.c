#include <stdio.h>
#define LOOPMAX 10000

int nPlus1(int input_number);

void main(void){
    int input_a, input_b, rslt_a, rslt_b;
    input_a=0;
    input_b=0;
    rslt_a=1;
    rslt_b=1;
    scanf("%d %d",&input_a,&input_b);
    printf("%d %d\n",input_a,input_b);

    rslt_a=nPlus1(input_a);
    rslt_b=nPlus1(input_b);

    printf("%d %d %d\n",input_a,input_b,((rslt_a>rslt_b)?rslt_a:rslt_b) ) ;

}

int nPlus1(int input_number){
    //printf("function start\n");
    int i=0;
    int rslt=0;

    for(i=1;i<=LOOPMAX;i++){
        if(input_number==1){
            rslt=i;
            break;
        }
        else if(input_number%2==0){
            input_number/=2;
        }
        else if(input_number%2==1){
            input_number=input_number*3+1;
        }
        //printf("now %d\n",input_number);
    }
    //printf("function END with %d\n",rslt);
    return rslt;
}