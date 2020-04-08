#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#pragma once

struct SolvedData
{
    float E = 0;
};


///number of inputed values
struct Nvalues
{
    int _Nalpha;
    int _Nl;
    int _Nq;
    Nvalues();
    void Input(float *alpha, float *l, float *q);
    void InputAuto(float *alpha, float *l, float *q); //spec_func only for test
    int Sum();
    void Norm_alpha(float *betta);
};

Nvalues::Nvalues()
{
    std::cout << "Please, input number of alpha angles" << std::endl;
    std::cin >> this->_Nalpha;
    std::cout << "\nPlease, input number of l" << std::endl;
    std::cin >> this->_Nl;
    std::cout << "\nPlease, input number of charges" << std::endl;
    std::cin >> this->_Nq;
};

void Nvalues::Input(float *alpha, float *l, float *q)
{
    std::cout << "Please, input your " << this->_Nalpha << " values for angles alpha" << std::endl;
    for (int i = 0; i < this->_Nalpha; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> alpha[i];
    }
    std::cout << "Please, input your " << this->_Nl << " values for l" << std::endl;
    for (int i = 0; i < this->_Nl; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> l[i];
    }
    std::cout << "Please, input your " << this->_Nq << " values for charges" << std::endl;
    for (int i = 0; i < this->_Nq; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> q[i];
    }
    std::cout << "All values added" << std::endl;
};

void Nvalues::Norm_alpha(float *alpha)
{
    for (int i = 0; i < this->_Nalpha; ++i)
    {
        alpha[i]/=2;
    }
    std::cout << "All angles are normed" << std::endl;
}

//spec_func only for test
void Nvalues::InputAuto(float *alpha, float *l, float *q)
{
    for (int i = 0; i < this->_Nalpha; ++i)
    {
        alpha[i] = i+1;
    }
    for (int i = 0; i < this->_Nl; ++i)
    {
        l[i] = i+1;
    }
    for (int i = 0; i < this->_Nq; ++i)
    {
        q[i] = i+1;
    }
    std::cout << "All values added" << std::endl;
};

int Nvalues::Sum()
{
    return this->_Nalpha * this->_Nl * this->_Nq;
};

#endif // STRUCTS_H_INCLUDED
