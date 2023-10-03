#include<cmath>
#include"network.h"
#include"matrix.h"




struct NW_data
{
    int num;
    double* pixels;
};


NW_data* ReadData(const std::string filename, int &exaples )
{
    NW_data* data;
    std::ifstream fin;
    fin.open(filename);

    if (!fin) {
    std::cerr << "Failed to open file on second attempt: " << filename << std::endl;
    }
    if (!fin.is_open())
    {
        
        std::cout<<"Reading err"<<std::endl;
        system("pause");
    }
    else
    {
        std::cout<<"loading"<<std::endl;
    }
    std::string tmp;
    fin>>tmp;
    if (tmp=="Examples")
    {
        fin>>exaples;
        std::cout<<"Examples: "<<exaples<<std::endl;
        data=new NW_data[exaples];
        for (int i = 0; i < exaples; i++)
        {
            data[i].pixels=new double[784];
        }
        for (int i = 0; i < exaples; i++)
        {
            fin>>data[i].num;
            for (int j = 0; j < 784; j++)
            {
                fin>>data[i].pixels[j];                
            }
            //std::cout<<std::endl<<"i "<<i<<" "<<std::endl;
        }
        fin.close();
        std::cout<<"reading\n";
        return data;
    }
    else
    {
        std::cout<<"err read"<<filename<<std::endl;
        fin.close();
        return nullptr;
    
    }    
}


int main()
{
    try
    {
        int row,col;
        std::cout<<"Введите через пробел колличество row/col"<<std::endl;
        std::cin>>row>>col;
        
        NW_data* data;
        int right;
        int pred;
        double lr;
        int examples;
        double ra=0;
        bool repeat=true;
        int stady;
        network NW(row,col);
        while (repeat)
        {
            int epoch=0;
            std::cout<<"stady? "<<std::endl;
            std::cin>>stady;
            if (stady==1)
            {
                data=ReadData("lib_MNIST_edit.txt", examples);
                /* std::cout<<"Введите коэфициент обучения=";
                std::cin>>lr;
                std::cout<<"Коэфициент обучения="<<lr<<std::endl; */
                while (ra/examples*100<100)
                {
                    lr=0.15* exp((-epoch/20.));//
                    ra=0;
                    for (int i = 0; i < examples; i++)
                    {
                        NW.Input(data[i].pixels);
                        right=data[i].num;
                        NW.forward();
                        pred=NW.Pred();
                        //std::cout<<"real="<<data[i].num<<" pred="<<pred<<"\n";
                        
                        if (pred!=data[i].num)
                        {
                            NW.NRIG(data[i].num);
                            NW.QNERR();
                            NW.WUpdate();
                        }
                        else
                        {
                            ra++;
                        }    
                    }
                    std::cout<<"Точность:"<<ra/examples*100<<"%"<<std::endl;
                    epoch++; 
                    if (epoch==2)
                    {
                        break;
                    }
                }
                for (int i = 0; i < examples; i++)
                {
                    delete[] data[i].pixels;
                }
                delete[] data;
                NW.SaveW();
                NW.SaveB();
            }
            else if (stady==2)
            {
                ra=0;
                data=ReadData("lib_10k.txt", examples);
                NW.ReadB();
                NW.ReadW();
                for (int i = 0; i < examples; i++)
                {
                    NW.Input(data[i].pixels);
                    NW.forward();
                    pred=NW.Pred();
                    //std::cout<<"real="<<data[i].num<<" pred="<<pred<<"\n";
                    if (pred==data[i].num)
                    {
                        ra++;
                    }
                }
                std::cout<<"Точность:"<<ra  / examples * 100<<std::endl;
                for (int i = 0; i < examples; i++)
                {
                    delete[] data[i].pixels;
                }
                delete[] data;


            }
            else 
            {
                break;
            }            
        }
        return 0;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
        
}