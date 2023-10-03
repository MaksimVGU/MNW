#include"activation.h"
#include<iostream>

double* activation::use(double* value, int row)
{
    for (int i = 0; i < row; i++)
    {
        //std::cout<<"value="<<value[i]<<" ";

        if (value[i]>0)
        {
            value[i]=0.1*value[i];
        }
        else
        {
            value[i]=0;
        }
    }
    return value;
}