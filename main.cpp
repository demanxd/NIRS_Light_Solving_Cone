#include <iostream>
#include <cmath>
#include "math_func.h"
#include "error_lib.h"
#include "structs.h"
#include "Sector_class.h"
#include "V3d_auxiliary.h"
#include "constants.h"
#include "auxiliary_funcs.cpp"



int main()
{
    int DEGREES = 360; // 360 degrees
    double START_l = 0.001;


    Greetings();

    double alpha;
    double l;
    double q0;
    double R;

    std::cout << "Input the opening angle" << std::endl;
    std::cin >> alpha;
    std::cout << "Input length of antenna's shoulder" << std::endl;
    std::cin >> l;
    std::cout << "Input the charge of antenna" << std::endl;
    std::cin >> q0;
    std::cout << "Input the distance for measuring" << std::endl;
    std::cin >> R;

    alpha /= 2;

    int degr = std::ceil( 2 * Pi * l * cos(tacos * alpha));


    Sector S1,S2,S3,S4;
    S1.SectorZeroFiller(alpha,START_l,l, std::ceil(degr / 4.0));
    S2.SectorFiller(S1,1);
    S3.SectorFiller(S1,2);
    S4.SectorFiller(S1,3);

    Sector NS1,NS2,NS3,NS4;
    NS1.Negate(S1);
    NS2.Negate(S2);
    NS3.Negate(S3);
    NS4.Negate(S4);


    double dq = gen_q(q0,START_l,alpha);
    double q  = gen_q(q0,l,alpha);

    std::cout << "-=-=-=-\n evaluating starting\n-=-=-=-" << std::endl;

    std::cout << "Status of progress:" << std::endl;

    int all_points = 360;

    for (int i = 0; i < all_points; i++)
    {
        ShowProgress(Percent(360,i));

        //V3d gen_eval_point(double l, double angle)

    }

    WaitingEnter();
    return 0;
}
