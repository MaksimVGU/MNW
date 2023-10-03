#include<ctime>
#include<iostream>
#include"matrix.h"


double* matrix::multi(double** weight, double* input, int row, int col)
{
    srand(time(NULL));
    double *c=new double[row];
    /* std::cout<<row; */
    for (int i = 0; i < row; i++)
    {
        c[i] = 0.0; 
        for (int j = 0; j < col; j++)
        {
            c[i]+=weight[i][j]*input[j];    
            /* std::cout<<weight[i][j]<<" "; */
        }
/*         std::cout<<"\n"; */
        

    }
/*     std::cout<<"\n\n\n"; */
    return c;
}

double* matrix::sumv(double* mlt, double* bias, int row)
{
    double *c=new double[row];
/*     for (int i = 0; i < row; i++)
    {
        std::cout<<mlt[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl; */

    for (int i = 0; i < row; i++)
    {
        //std::cout<<"\n"<<c[i]<<"="<<mlt[i]<<"+"<<bias[i]<<std::endl;
        c[i]=mlt[i]+bias[i];
        //std::cout<<"c="<<c[i]<<"\n";
    }
    return c;
}

