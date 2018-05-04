#include <iostream>

float* matrix_multi3331(float aa[3][3], float bb[3]){
    static float rslt[3]={0.0,0.0,0.0};
    for (int ii=0;ii<3;ii++){
        for(int jj=0;jj<3;jj++){
            rslt[ii]+=aa[ii][jj]*bb[jj];
        }
    }
    return rslt;
}

int main(void){
    float aa[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    float bb[3]={1,2,3};
    float *rslt;

    rslt=matrix_multi3331(aa,bb);
    

    for( int ii=0;ii<3;ii++){
        
            printf("%f \n",rslt[ii]);
        
    }


    return 0;

}