#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>


void main(void){
    printf("type change test \n");

    float aa = -11.4;
    printf("aa=%f\n",aa);
    float bb = 11.4;
    printf("bb=%f\n",bb);
    uint16_t aai =0;
    printf("aai=%d\n",aai);
    uint16_t bbi =0;
    printf("bbi=%d\n",bbi);

    aai=aa;
    bbi=bb;
    printf("aai=%d\n bbi=%d\n",aai,bbi);

    aa=fabs(aa);
    bb=fabs(bb);
    printf("aa=%f\n bb=%f\n",aa,bb);
    
    aai=aa;
    bbi=bb;
    printf("aai=%d\n bbi=%d\n",aai,bbi);
}