#ifndef AUXILIARY_FUNCS_H_INCLUDED
#define AUXILIARY_FUNCS_H_INCLUDED

#pragma once

#include <fstream>
#include <cstring>
#include "error_lib.h"


const static std::string WAY = "Data/";



void WaitingEnter()
{
    std::cin.ignore(1024, '\n');
    std::cout << "\nPress [Enter] to continue...";
    std::cin.get();
}

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
    std::cout << "Version 1.0" <<std::endl;
    for (int i = 0; i < 27; ++i)
        std::cout << " ";
    std::cout << "You are welcome!" << std::endl;
    for (int i = 0; i < 70; ++i)
        std::cout << "=";
    for (int i = 0; i < 5; ++i)
        std::cout << "\n";
    std::cout << std::endl;
}
/*
void OutputConsole(SolvedData Data)
{
    std::cout << "E " << ":....  :"  << Data.E << std::endl;
}/**/

#endif // AUXILIARY_FUNCS_H_INCLUDED
