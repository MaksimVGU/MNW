#include<fstream>
#include<ctime>
#include<iostream>
#include<random>
#include"matrix.h"
#include"activation.h"
class network
{
public:
    double** weight;
    double* input; 
    double* bios; 
    double* neron_val;//
    double* neron_err;//
    double* neron_right;
    double lr;
    int row,col;//
    activation func;
    matrix matr;
public:
    network();
    network(int row, int col);
    int Pred();
    void WUpdate();
    void Input(double* _input);
    void forward();
    void NRIG(int num);
    void QNERR();
    void ReadW();
    void SaveW();
    void ReadB();
    void SaveB();
    ~network();
};