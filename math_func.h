#ifndef MATH_FUNC_H_INCLUDED
#define MATH_FUNC_H_INCLUDED
#pragma once

#include <iostream>

#include "structs.h"
#include "error_lib.h"
#include "constants.h"


///r block

void gen_vec_r0 (V2d q_pos, V2d *v_r0)
{
    v_r0->SetV2d(q_pos.GetV2d("x") * 100,q_pos.GetV2d("y") * 100);
}

void gen_vec_r (float alpha, V2d v_r0, V2d *v_r)
{
    v_r->SetV2d((v_r0.GetV2d("x") - cos(alpha * tacos)),(v_r0.GetV2d("y") - sin(alpha * tacos)));
}

void gen_m (V2d v_r0, V2d v_r, float *m)
{
    *m = (float)sqrt(pow((v_r.GetV2d("x") - v_r0.GetV2d("x")),2) + pow((v_r.GetV2d("y") - v_r0.GetV2d("y")),2));
}


void evalR(float alpha, float l, V2d q_pos, V2d *v_r, V2d *v_r0, float* m, float* v)
{
    gen_vec_r0(q_pos, v_r0);
    gen_vec_r(alpha, *v_r0, v_r);

    gen_m(*v_r0, *v_r, m);
    //gen_v(*v_r0, *v_r, v);
}

///E block
float E0(float alpha, float l,float q)
{
    std::cout << "E0 = " << ( (1/sin(alpha * tacos)) * (1 - c * (1 - c * (1 - c))) ) << std::endl;
    return ( (1/sin(alpha * tacos)) * (1 - c * (1 - c * (1 - c))) );
};

float E1(float alpha, float l,float q, float mod)
{
    std::cout << "E1 = " << ( (1/cos(alpha * tacos)) * (1 / c) * (1 + c * c) * mod ) << std::endl;
    return ( (1/cos(alpha * tacos)) * (1 / c) * (1 + c * c) * mod ) ;
};

///evaluate E
void evalE(float alpha, float l, float q, float mod, SolvedData *Data)
{
    Data->E = /*buritos */ (1 / (mod * mod * (1 - 3 * c + 3 * c*c - c*c*c))) * (q / (2 * (int)(Pi * l * 100))) * (E0(alpha,l,q) + E1(alpha,l,q,mod)) * (int)(Pi * l * 100);
    std::cout << "buritos = " << buritos << "\nafter buritos = " << (mod * mod * (1 - 3 * c + 3 * c*c - c*c*c)) <<"\nPi l = " << (int)(Pi * l * 100) << "\n";
};

///evaluate start
void EvaluateE(float alpha, float l,float q, V2d q_pos, SolvedData *Data)
{
    V2d*   vec_r  = new V2d;
    V2d*   vec_r0 = new V2d;

    float*  mod = new float;     //|r-r|
    float*  vec = new float;     //(r-r)

    evalR(alpha, l * 100, q_pos, vec_r0, vec_r, mod, vec);

    evalE(alpha, l * 100, q, *mod, Data);


    delete vec_r0;
    delete vec_r;
};

#endif // MATH_FUNC_H_INCLUDED
