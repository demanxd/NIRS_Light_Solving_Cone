#include "structs.h"

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
