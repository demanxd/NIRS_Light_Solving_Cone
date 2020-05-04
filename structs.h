#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#pragma once

#include "constants.h"
#include <vector>
#include <string>

struct V3d //vector 3 dimension
{
    void  SetV3d(double x, double y, double z);
    double GetV3d(std::string);
    void Show();

    double _x;
    double _y;
    double _z;
};

void V3d::Show()
{
    std::cout << _x << ";   " << _y << ";   " << _z << ";" << std::endl;
}

void V3d::SetV3d(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

double V3d::GetV3d(std::string str)
{

    if (str == "x")
        return _x;
    else if (str == "y")
        return _y;
    else if (str == "z")
        return _z;
    else
        std::cout << "error in GetV func. parameter str = " << str << std::endl;
        return 0;
}


struct V2d //vector 2 dimension
{
    void  SetV2d(double x, double y);
    double GetV2d(std::string);

    double _x;
    double _y;
};

void V2d::SetV2d(double x, double y)
{
    _x = x;
    _y = y;
}

double V2d::GetV2d(std::string str)
{

    if (str == "x")
        return _x;
    else if (str == "y")
        return _y;
    else
        std::cout << "error in GetV func. parameter str = " << str << std::endl;
        return 0;
}

struct SolvedData
{
    double E = 0;
};


struct Sector
{
    std::vector<V3d> _points;  //_points[0] == _point_start; inother - _points_end
    std::vector<double> _E;
    std::vector<double> _charges; //_charges[0] == _q_start; inother - _q_end;
    Sector(){};
    ~Sector(){};
    void SectorZeroFiller(double, double, double, int);
    void SectorFiller(Sector, short);
    //void FindE();
    //void FindPartE();
};
















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
    }
}


#endif // STRUCTS_H_INCLUDED
