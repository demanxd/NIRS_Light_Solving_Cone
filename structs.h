#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#pragma once

#include "constants.h"

#include <vector>
#include <string>

#include <iostream>


struct V3d //vector 3 dimension
{
    void  SetV3d(double x, double y, double z);
    double GetV3d(std::string);
    void Show();

    double _x;
    double _y;
    double _z;

    V3d(){};
    ~V3d(){};
};

struct SolvedData
{
    double E = 0;
};

#endif // STRUCTS_H_INCLUDED
