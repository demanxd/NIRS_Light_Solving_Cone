#include <iostream>
#include <cmath>
#include "math_func.h"
#include "error_lib.h"
#include "structs.h"
#include "V3d_auxiliary.h"
#include "constants.h"



int main()
{
    int DEGREES = 360; // 360 degrees
    double START_l = 0.001;


    Greetings();

    double alpha;
    double l;
    double q;
    double R;

    std::cout << "Input the opening angle" << std::endl;
    std::cin >> alpha;
    std::cout << "Input length of antenna's shoulder" << std::endl;
    std::cin >> l;
    std::cout << "Input the charge of antenna" << std::endl;
    std::cin >> q;
    std::cout << "Input the distance for measuring" << std::endl;
    std::cin >> R;

    alpha /= 2;

    int degr = std::ceil( 2 * Pi * l * cos(tacos * alpha));


    Sector S1,S2,S3,S4;
    S1.SectorZeroFiller(alpha,START_l,l, std::ceil(degr / 4.0));
    S2.SectorFiller(S1,1);
    S3.SectorFiller(S1,2);
    S4.SectorFiller(S1,3);


    std::cout << "-=-=-=-\n evaluating starting\n-=-=-=-" << std::endl;

    std::cout << "Status of progress:" << std::endl;


    WaitingEnter();
    return 0;
}
