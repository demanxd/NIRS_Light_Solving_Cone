#ifndef SECTOR_CLASS_H
#define SECTOR_CLASS_H

#include "structs.h"


struct Sector
{
    std::vector<V3d> _points;  //_points[0] == _point_start; another - _points_end
    std::vector<double> _E;
    std::vector<double> _charges; //_charges[0] == _q_start; another - _q_end;
    Sector(){};
    ~Sector(){};
    void SectorZeroFiller(double, double, double, int);
    void SectorFiller(Sector, short);
    void Negate(Sector);
    void Eval_E(double, double, V3d);
    double Sum_E();
    void Clear_E();
};





#endif // SECTOR_CLASS_H
