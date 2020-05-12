#ifndef MATH_FUNC_H_INCLUDED
#define MATH_FUNC_H_INCLUDED
#pragma once

#ifdef AAA
#error AAAAAAAAAAAAAA
#endif
#define AAA


#include <iostream>

#include "structs.h"
#include "error_lib.h"
#include "constants.h"



V3d gen_vec_r(V3d first_point, V3d second_point);

void gen_mod (V3d start_vector, V3d end_vector, double *m);

double gen_devider(double mod, double vec);
/*
void gen_vec (V3d start_position, V3d end_position, double *v)
{
    *v = (pow((start_position.GetV3d("x") + end_position.GetV3d("x")),2)          //x
              + pow((start_position.GetV3d("y") + end_position.GetV3d("y")),2)       //y
              + pow((start_position.GetV3d("z") + end_position.GetV3d("z")),2));    //z
}/**/

///     s_p - start point  \
        e_p - end point     \
        v_ev - evaluate point\
        vec_r - vector r      \
        vec_r0 - vector r      \
        m - module r - r0       \
        v - vector r - r0
void evalR(V3d s_p, V3d e_p, V3d ev_p, V3d* vec_r, V3d* vec_r0, double* m, double* v, double* devider);

///E block
float E0(float alpha, float l,float q);

float E1(float alpha, float l,float q, float mod);

///evaluate E
double evalE(double devider, double charge, double dcharge, double vec_n, double mod_r);

///evaluate start
double EvaluateE(double q, double dq, V3d start_point, V3d end_point, V3d eval_point);

V3d gen_eval_point(double l, double angle);

double gen_q(double charge, double l, double alpha_norm);

#endif // MATH_FUNC_H_INCLUDED
