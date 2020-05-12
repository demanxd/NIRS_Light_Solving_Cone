#include "math_func.h"


V3d gen_vec_r(V3d first_point, V3d second_point)
{
    V3d r;
    r.SetV3d((first_point.GetV3d("x") - second_point.GetV3d("x")),
              (first_point.GetV3d("y") - second_point.GetV3d("y")),
               (first_point.GetV3d("z") - second_point.GetV3d("z")));
    return r;
}

void gen_mod (V3d start_vector, V3d end_vector, double *m)
{
    *m = sqrt(pow((start_vector.GetV3d("x") - end_vector.GetV3d("x")),2)          //x
              + pow((start_vector.GetV3d("y") - end_vector.GetV3d("y")),2)       //y
              + pow((start_vector.GetV3d("z") - end_vector.GetV3d("z")),2));    //z
}

double gen_devider(double mod, double vec)
{
    return 1 / (pow(mod, 2) * pow((1 - vec * c),3));
}
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
void evalR(V3d s_p, V3d e_p, V3d ev_p, V3d* vec_r, V3d* vec_r0, double* m, double* v, double* devider)
{
    V3d r = gen_vec_r(s_p, ev_p);
    V3d r0 = gen_vec_r(e_p, ev_p);

    gen_mod(r, r0, m);
    *v = 1.0;

    *devider = gen_devider(*m,*v);
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
double evalE(double devider, double charge, double dcharge, double vec_n, double mod_r)
{
    return (buritos * devider * (charge * (vec_n - c * (c*c + (1 - vec_n * c))) + dcharge * (vec_n + c) * (1/c) * mod_r * (1 - vec_n * c)));
};

///evaluate start
double EvaluateE(double q, double dq, V3d start_point, V3d end_point, V3d eval_point)
{
    V3d*  vec_r  = new V3d;
    V3d*  vec_r0 = new V3d;

    double*  mod     = new double;     //|r-r|
    double*  vec     = new double;     //(r-r)
    double*  devider = new double;

    evalR(start_point, end_point, eval_point, vec_r, vec_r0, mod, vec, devider);

    double E = evalE(*devider, q, dq, *vec, *mod);
    std::cout << "mod = " << *mod << "; addr mod = " << mod << "; E = " << E << std::endl;

    delete vec_r;
    delete vec_r0;

    delete mod;
    delete vec;
    delete devider;

    return E;
};

V3d gen_eval_point(double l, double angle)
{
    V3d tmp;
    tmp.SetV3d((l * cos(angle * tacos)), (l * sin(angle * tacos)), 0);
    return tmp;
}

double gen_q(double charge, double l, double alpha_norm)
{
    return (charge) / (2 * Pi * l * sin(alpha_norm * tacos));
}
