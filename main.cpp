#include <iostream>
#include <cmath>
#include "math_func.h"
#include "error_lib.h"
#include "structs.h"


int main()
{
    Greetings();
    Nvalues Nss;

    if(CountsError(Nss))
        return(0);

    float* alpha = new float[Nss._Nalpha];
    float* l = new float[Nss._Nl];
    float* q = new float[Nss._Nq];
    Nss.Input(alpha,l,q);
    Nss.Norm_alpha(alpha);

    std::cout << "-=-=-=-\n evaluating starting\n-=-=-=-" << std::endl;

    SolvedData* Data = new SolvedData[Nss.Sum()];
    //std::cout << "Size of Nvalues:" << sizeof(Nvalues) << std::endl;

    //std::cout << "Size of SolvedData:" << sizeof(SolvedData) << std::endl;

    int n_el = 0;
    int all = Nss.Sum();

    std::cout << "Status of progress:" << std::endl;

    for (int i = 0; i < Nss._Nalpha; ++i)
        for (int j = 0; j < Nss._Nl; ++j)
            for (int k = 0; k < Nss._Nq; ++k)
            {
                ++n_el;
                startEvaluate(alpha[i],l[j],q[k], &Data[n_el]);
                ShowProgress(Percent(all, n_el));
            }
/*
    for (int i = 0; i < Nss.Nr; ++i)
        for (int j = 0; j < Nss.Nl; ++j)
            for (int k = 0; k < Nss.Nb; ++k)
            {
                ++n_el;
                OutputConsoleMaxE(R[i],l[j],betta[k], &Data[n_el]);
            }
*/
    ChangeOutputInFile(Nss, Data, q, l, alpha);

    delete [] q;
    delete [] l;
    delete [] alpha;

    WaitingEnter();
    return 0;
}
