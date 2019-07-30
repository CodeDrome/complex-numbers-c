#include<stdio.h>
#include<complex.h>
#include<stdbool.h>

#include"arganddiagram.h"

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void complex_output(double complex, bool brackets, bool newline);
void complex_sizes();
void complex_arithmetic();
void complex_conjugate();
void complex_abs_arg();
void argand_arithmetic();
void argand_conjugate();

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
void main(void)
{
    puts("-------------------");
    puts("| codedrome.com   |");
    puts("| Complex Numbers |");
    puts("-------------------");

    complex_sizes();

    complex_arithmetic();

    complex_conjugate();

    complex_abs_arg();

    argand_arithmetic();

    argand_conjugate();
}

//--------------------------------------------------------
// FUNCTION complex_output
//--------------------------------------------------------
void complex_output(double complex z, bool brackets, bool newline)
{
    if(brackets)
    {
        printf("(");
    }

    printf("%g + %gi", creal(z), cimag(z));

    if(brackets)
    {
        printf(")");
    }

    if(newline)
    {
        puts("");
    }
}

//--------------------------------------------------------
// FUNCTION complex_sizes
//--------------------------------------------------------
void complex_sizes()
{
    puts("\nsizes of complex types\n----------------------");

    printf("sizeof(float) %ld\n", sizeof(float));
    printf("sizeof(float complex) %ld\n", sizeof(float complex));

    printf("sizeof(double) %ld\n", sizeof(double));
    printf("sizeof(double complex) %ld\n", sizeof(double complex));

    printf("sizeof(long double) %ld\n", sizeof(long double));
    printf("sizeof(long double complex) %ld\n", sizeof(long double complex));
}

//--------------------------------------------------------
// FUNCTION complex_arithmetic
//--------------------------------------------------------
void complex_arithmetic()
{
    puts("\ncomplex arithmetic\n------------------");

    double complex z1 = 1 + 3 * I;
    double complex z2 = 2 + 4 * I;

    double complex z_add = z1 + z2;
    double complex z_subtract = z1 - z2;
    double complex z_multiply = z1 * z2;
    double complex z_divide = z1 / z2;

    complex_output(z1, true, false);
    printf(" + ");
    complex_output(z2, true, false);
    printf(" = ");
    complex_output(z_add, true, true);

    complex_output(z1, true, false);
    printf(" - ");
    complex_output(z2, true, false);
    printf(" = ");
    complex_output(z_subtract, true, true);

    complex_output(z1, true, false);
    printf(" * ");
    complex_output(z2, true, false);
    printf(" = ");
    complex_output(z_multiply, true, true);

    complex_output(z1, true, false);
    printf(" / ");
    complex_output(z2, true, false);
    printf(" = ");
    complex_output(z_divide, true, true);
}

//--------------------------------------------------------
// FUNCTION complex_conjugate
//--------------------------------------------------------
void complex_conjugate()
{
    puts("\ncomplex conjugates\n------------------");

    double complex z1 = 9 + 6 * I;
    double complex z2 = -4 - 5 * I;

    double complex z1conj = conj(z1);
    double complex z2conj = conj(z2);

    complex_output(z1, false, true);
    printf("conjugate = ");
    complex_output(z1conj, false, true);

    complex_output(z2, false, true);
    printf("conjugate = ");
    complex_output(z2conj, false, true);
}

//--------------------------------------------------------
// FUNCTION complex_abs_arg
//--------------------------------------------------------
void complex_abs_arg()
{
    puts("\ncomplex absolute and argument\n-----------------------------");

    double complex z1 = 3 + 4 * I;
    double complex z2 = -6 - 8 * I;

    complex_output(z1, false, true);
    printf("absolute %f\n", cabs(z1));
    printf("argument %f radians\n", carg(z1));

    complex_output(z2, false, true);
    printf("absolute %f\n", cabs(z2));
    printf("argument %f radians\n", carg(z2));
}

//--------------------------------------------------------
// FUNCTION argand_arithmetic
//--------------------------------------------------------
void argand_arithmetic()
{
    puts("\nArgand diagram - arithmetic\n---------------------------");

    double complex cplxnums[6];

    double complex z1 = 1 + 3 * I;
    double complex z2 = 2 + 4 * I;

    double complex z_add = z1 + z2;
    double complex z_subtract = z1 - z2;
    double complex z_multiply = z1 * z2;
    double complex z_divide = z1 / z2;

    cplxnums[0] = z1;
    cplxnums[1] = z2;
    cplxnums[2] = z_add;
    cplxnums[3] = z_subtract;
    cplxnums[4] = z_multiply;
    cplxnums[5] = z_divide;

    argandconfig config = (argandconfig){.height = 720,
                                         .width = 720,
                                         .margin = 64,
                                         .indexspacingreal = 1,
                                         .indexspacingimag = 1,
                                         .minreal = -10,
                                         .maxreal = 5,
                                         .minimag = -2,
                                         .maximag = 10};

    argand_diagram(config, cplxnums, 6, "argand_arithmetic.svg");
}

//--------------------------------------------------------
// FUNCTION argand_conjugate
//--------------------------------------------------------
void argand_conjugate()
{
    puts("\nArgand diagram - conjugates\n---------------------------");

    double complex cplxnums[4];

    double complex z1 = 9 + 6 * I;
    double complex z2 = -4 - 5 * I;

    double complex z1conj = conj(z1);
    double complex z2conj = conj(z2);

    cplxnums[0] = z1;
    cplxnums[1] = z2;
    cplxnums[2] = z1conj;
    cplxnums[3] = z2conj;

    argandconfig config = (argandconfig){.height = 720,
                                         .width = 720,
                                         .margin = 64,
                                         .indexspacingreal = 1,
                                         .indexspacingimag = 1,
                                         .minreal = -6,
                                         .maxreal = 10,
                                         .minimag = -8,
                                         .maximag = 8};

    argand_diagram(config, cplxnums, 4, "argand_conjugates.svg");
}
