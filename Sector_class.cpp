#include "Sector_class.h"
#include "math_func.h"

#include <cmath>

void Sector::SectorZeroFiller(double alpha_n, double l_f, double l_l, int slines) //l_f - at begin, l_l - at end; ||khuynja||
{
    V3d tmp;
    tmp.SetV3d((l_f * cos(alpha_n * tacos)), (l_f * sin(alpha_n * tacos) * cos(45 * tacos)), (l_f * sin(alpha_n * tacos) * cos(45 * tacos)));
    tmp.Show();
    _points.push_back(tmp);
    int step = std::ceil(90.0 / slines);
    for (int degrees = step; degrees < 90; degrees+=step)
    {
        tmp.SetV3d((l_l * cos(alpha_n * tacos)), (l_l * sin(alpha_n * tacos) * cos(degrees * tacos)), (l_l * sin(alpha_n * tacos) * sin(degrees * tacos)));
        tmp.Show();
        _points.push_back(tmp);
    }
}

void Sector::SectorFiller(Sector S, short quarter)
{
    switch(quarter)
    {
        case 1:
        {
            V3d tmp;
            for(auto vec : S._points)
            {
                tmp.SetV3d(vec.GetV3d("x"), - vec.GetV3d("y"), vec.GetV3d("z"));
                tmp.Show();
                _points.push_back(tmp);
            }
        }
        break;
        case 2:
        {
            V3d tmp;
            for(auto vec : S._points)
            {
                tmp.SetV3d(vec.GetV3d("x"), - vec.GetV3d("y"), - vec.GetV3d("z"));
                tmp.Show();
                _points.push_back(tmp);
            }
        }
        break;
        case 3:
        {
            V3d tmp;
            for(auto vec : S._points)
            {
                tmp.SetV3d(vec.GetV3d("x"), vec.GetV3d("y"), - vec.GetV3d("z"));
                tmp.Show();
                _points.push_back(tmp);
            }
        }
        break;
        case 4:
        {
            V3d tmp;
            for(auto vec : S._points)
            {
                tmp.SetV3d(-vec.GetV3d("x"), vec.GetV3d("y"), vec.GetV3d("z"));
                tmp.Show();
                _points.push_back(tmp);
            }
        }
        break;
    }
}

void Sector::Negate(Sector S)
{
    V3d tmp;

    for(auto vec : S._points)
    {
        tmp.SetV3d(- vec.GetV3d("x"), vec.GetV3d("y"), vec.GetV3d("z"));
        tmp.Show();
        _points.push_back(tmp);
    }
}

void Sector::Eval_E(double q, double dq, V3d eval_point)
{
    for (int i = 1; i < _points.size(); i++)
        _E.push_back(EvaluateE(q,dq,_points.at(0),_points.at(i), eval_point));
    _E.push_back(EvaluateE(dq,q,_points.at(std::ceil(_points.size() / 2)),_points.at(0), eval_point));
}


double Sector::Sum_E()
{
    double rez = 0.0;
    for(auto n : _E)
        rez += n;
    return rez;
}
