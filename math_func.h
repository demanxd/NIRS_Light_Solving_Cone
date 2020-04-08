#ifndef MATH_FUNC_H_INCLUDED
#define MATH_FUNC_H_INCLUDED
#pragma once

#include <iostream>

#include "structs.h"
#include "error_lib.h"



const static float Pi = 3.141592653589793;
const static float w = 120 * Pi;
const static float c = 3 * pow(10,8);
const static float epsilon0 = 8.85 * pow(10,-12);
const static float tacos = Pi / 180;                    //some mexicans
const static float buritos = 1 / (4 * Pi * epsilon0);   //more mexicans

///E block
float E0(float alpha, float l,float q)
{
    return ( (1/sin(alpha * tacos)) * (1 + c * (1 - c * (1 + c))) );
};

float E1(float alpha, float l,float q)
{
    return ( (1/cos(alpha * tacos)) * (l * (1 + c * c)) );
};

///evaluate E
void evalE(float alpha, float l,float q, SolvedData *Data)
{
    Data->E = buritos * (1 / (l*l * (1 + c))) * (q / (2 * Pi * l)) * (/*E0(alpha,l,q) +*/ E1(alpha,l,q));
};

///evaluate start
void startEvaluate(float alpha, float l,float q, SolvedData *Data)
{
    evalE(alpha, l, q, Data);
};

#endif // MATH_FUNC_H_INCLUDED
