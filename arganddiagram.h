#include<complex.h>

//--------------------------------------------------------
// STRUCT argandconfig
//--------------------------------------------------------
typedef struct argandconfig
{
    int width;
    int height;
    int margin;
    double indexspacingreal;
    double indexspacingimag;
    double minreal;
    double maxreal;
    double minimag;
    double maximag;
} argandconfig;

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void argand_diagram(argandconfig config, double complex cplxnums[], int complexnumbercount, char* filename);
