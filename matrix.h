#ifndef MATRIX_H
#define MATRIX_H
class matrix
{
public:
    double* multi(double** weight, double* input, int row, int col);
    double* sumv(double* mlt, double* bios, int row);
};
#endif 