#include"network.h"

network::network(int row, int col) :row(row) , col(col)
{
    weight=new double*[row];
    for (int i = 0; i < row; i++)
    {
        weight[i]=new double[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            weight[i][j]=0;
            weight[i][j]=0.01*(rand() % 101);
        }
    }
    input=new double[col];
    bios=new double[row];
    for (int i = 0; i < row; i++)
    {
        bios[i]=1;
    }
    neron_val=new double[row];
    neron_right=new double[row];
    neron_err=new double[row];
}
void network::Input(double* _input)
{
    input=_input;

    /* for (int i = 0; i < col; i++)
    {
        std::cout<<input[i]<<" ";
    }
    std::cout<< " \n"; */
}
void network::forward()
{
    neron_val=func.use(matr.sumv(matr.multi(weight, input, row, col), bios, row), row); 
}
void network::WUpdate()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
/*             std::cout<<"neron_err["<<i<<"]="<<neron_err[i]<<" "<<"lr="<<lr<<" "<<"input["<<j<<"]="<<input[j]<<"\n\n\n"; */
            weight[i][j]+=1*input[j]*neron_err[i];
        }
        bios[i]+=neron_err[i];
    }
/*     std::cout<<"веса ОБНОВИЛ\n";
 */}
int network::Pred()///////////////////////////
{
    int tmp=0;
    double max=neron_val[0];
    for (int i = 0; i < row; i++)
    {  
        if (max<neron_val[i])
        {
            max=neron_val[i];
            tmp=i;
        }
        /* std::cout<<neron_val[i]<<" "; */
    }
    /* std::cout<<tmp<<" tmp";
    std::cout<<"\n"; */
    /* std::cout<<"\n\n\n"; */
    return tmp;
}
void network::NRIG(int num)
{
    for (int i = 0; i < row; i++)
    {
        /* std::cout<<num<<" "<<i<<"\n"; */
        
        if (i==num)
        {
            neron_right[i]=1;
        }
        else
        {
            neron_right[i]=0;
        }
    }
}
void network::QNERR()
{
    for (int i = 0; i < row; i++)
    {
/*         std::cout << "neron_right[" << i << "] = " << neron_right[i] << ", ";
        std::cout << "neron_val[" << i << "] = " << neron_val[i] << " ";
         */
        neron_err[i]=neron_right[i]-neron_val[i];
/*         std::cout << "neron_err[" << i << "] = " << neron_err[i] << std::endl<< std::endl<< std::endl;
 */    }
}



void network::SaveW()
{
    std::ofstream fout;
    fout.open("W.txt");
    if (!fout.is_open()) 
    {
	    std::cout << "Error reading the file\n";
		system("pause");
	}
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fout<<weight[i][j]<<" ";
        }
    }
    std::cout<<"Веса сохранены"<<std::endl;
    fout.close();
}
void network::ReadW()
{
    std::ifstream fin;
	fin.open("W.txt");
	if (!fin.is_open()) 
    {
		std::cout << "Error reading the file"<<std::endl;
		system("pause");
	}
	for (int i = 0; i<row; ++i)
    {   
        for(int j=0; j<col; ++j)
        {    
            fin>>weight[i][j];
        }
    }
	std::cout << "Веса прочитаны"<<std::endl;
	fin.close();
}
void network::SaveB()
{
    std::ofstream fout;
    fout.open("B.txt");
    if (!fout.is_open()) 
    {
	    std::cout << "Error reading the file\n";
		system("pause");
	}
    for (int i = 0; i < row; i++)
    {
        fout<<bios[i];
    }
    std::cout<<"Биасы сохранены"<<std::endl;
    fout.close();
}
void network::ReadB()
{
    std::ifstream fin;
	fin.open("B.txt");
	if (!fin.is_open()) 
    {
		std::cout << "Error reading the file"<<std::endl;
		system("pause");
	}
	for (int i = 0; i<row; ++i)
    {
        fin>>bios[i];
    }
	std::cout << "Биасы прочитаны\n"<<std::endl;
	fin.close();
}
network::~network()
{
    delete[] neron_err;
    delete[] neron_val;
    delete[] neron_right;
    delete[] bios;
    delete[] input;
    for (int i = 0; i < row; i++)
    {
        delete[] weight[i];
    }
    delete[] weight;    
}