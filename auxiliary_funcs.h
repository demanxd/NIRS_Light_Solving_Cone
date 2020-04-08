#ifndef AUXILIARY_FUNCS_H_INCLUDED
#define AUXILIARY_FUNCS_H_INCLUDED

#include <fstream>
#include <cstring>
#include "error_lib.h"

#pragma once

const static std::string WAY = "Data/";



void WaitingEnter()
{
    std::cin.ignore(1024, '\n');
    std::cout << "\nPress [Enter] to continue...";
    std::cin.get();
};

int Percent(int all, int now)
{
    return (now * 100) / all;
}


void ShowProgress(int stage)
{
    std::cout << "\r";
    for (int i = 0; i < stage/2; ++i)
        std::cout << ":";
    for (int i = 0; i < (100 - stage)/2; ++i)
        std::cout << ".";
}


void Greetings()
{
    for (int i = 0; i < 70; ++i)
        std::cout << "=";
    std::cout << std::endl;
    for (int i = 0; i < 5; ++i)
        std::cout << " ";
    std::cout << "Programm for solving field of triangular antennas parameters" << std::endl;
    for (int i = 0; i < 29; ++i)
        std::cout << " ";
    std::cout << "Version 2.1" <<std::endl;
    for (int i = 0; i < 27; ++i)
        std::cout << " ";
    std::cout << "You are welcome!" << std::endl;
    for (int i = 0; i < 70; ++i)
        std::cout << "=";
    for (int i = 0; i < 5; ++i)
        std::cout << "\n";
    std::cout << std::endl;
};

void OutputConsole(SolvedData Data)
{
    std::cout << "E " << ":....  :"  << Data.E << std::endl;
};

void OutputDifFiles(SolvedData Data, float alpha, float l, float q)
{
    std::string namefile = WAY + "Data alpha=" + std::to_string(alpha) + " l=" + std::to_string(l) + " q=" + std::to_string(q * 2) + ".csv";
    std::ofstream file;
    file.open(namefile);
    file << Data.E <<"; ";
    file << "\n";
    file.close();
};

void OutputOneFile(Nvalues Nss, SolvedData *Data, float *alpha, float *l, float *q)
{
    std::string namefile = WAY + "Data_All.csv";
    std::ofstream file;
    file.open(namefile);
    int n_el = 0;

    for (int j = 0; j < Nss._Nalpha; ++j)
        for (int i = 0; i < Nss._Nl; ++i)
            for (int k = 0; k < Nss._Nq; ++k)
            {
                file << "alpha = " << alpha[j] << " l = " << l[i]  << " q = " << q[k] * 2 << "\n";
                ++n_el;
                file << Data[n_el].E <<";\n";
                file << "\n";

            }
    file.close();
    std::cout << "\nOutput complete!" << std::endl;
};

void ChangeOutputInFile(Nvalues Nss, SolvedData *Data, float *alpha, float *l, float* q)
{
    int ch;
    std::cout << "\nEvaluate is over!\nHow do you want to write results?\n[1-in one file\\2-in different files\\3-in console]  :";
    std::cin >> ch;
    int n_el = 0;
    switch (ch)
    {
        case 1:
            OutputOneFile(Nss, Data, alpha, l, q);
        break;
        case 2:
            for (int i = 0; i < Nss._Nalpha; ++i)
                for (int j = 0; j < Nss._Nl; ++j)
                    for (int k = 0; k < Nss._Nq; ++k)
                    {
                        ++n_el;
                        OutputDifFiles(Data[n_el], alpha[i], l[j], q[k]);
                    }
            std::cout << "\nOutput complete!" << std::endl;
        break;
        case 3:
            for (int i = 0; i < Nss._Nalpha; ++i)
                for (int j = 0; j < Nss._Nl; ++j)
                    for (int k = 0; k < Nss._Nq; ++k)
                    {
                        ++n_el;
                        OutputConsole(Data[n_el]);
                    }
            std::cout << "\nOutput complete!" << std::endl;
        break;
        /*default:
            ChangeError();*/
    }
}


#endif // AUXILIARY_FUNCS_H_INCLUDED
