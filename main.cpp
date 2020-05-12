#include <iostream>
#include <cmath>
#include <vector>


#include "math_func.h"
#include "error_lib.h"
#include "structs.h"
#include "Sector_class.h"
#include "V3d_auxiliary.h"
#include "constants.h"
#include "auxiliary_funcs.h"



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

    std::cout << "progress:" << std::endl;

    int all_points = 360;

    std::vector<double> rez_E;

    for (int i = 0; i < all_points; i++)
    {
        ShowProgress(Percent(360,i));

        V3d evaluating_point = gen_eval_point(l, i);
        //evaluating_point.Show();

        S1.Eval_E(q,dq,evaluating_point);
        S2.Eval_E(q,dq,evaluating_point);
        S3.Eval_E(q,dq,evaluating_point);
        S4.Eval_E(q,dq,evaluating_point);
        NS1.Eval_E(q,dq,evaluating_point);
        NS2.Eval_E(q,dq,evaluating_point);
        NS3.Eval_E(q,dq,evaluating_point);
        NS4.Eval_E(q,dq,evaluating_point);

        rez_E.push_back(S1.Sum_E() + S2.Sum_E() + S3.Sum_E() + S4.Sum_E() + NS1.Sum_E() + NS2.Sum_E() + NS3.Sum_E() + NS4.Sum_E());
        S1.Clear_E();
        S2.Clear_E();
        S3.Clear_E();
        S4.Clear_E();
        NS1.Clear_E();
        NS2.Clear_E();
        NS3.Clear_E();
        NS4.Clear_E();
    }

    WaitingEnter();

    for(int i = 0; i < all_points; i++)
    {
        OutputConsole(rez_E.at(i), i);
    }

    return 0;
}
