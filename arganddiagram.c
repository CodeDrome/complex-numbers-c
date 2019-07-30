#include<stdio.h>
#include<math.h>

#include"svg.h"
#include"arganddiagram.h"

// --------------------------------------------------------
// FUNCTION argand_diagram
// --------------------------------------------------------
void argand_diagram(argandconfig config, double complex cplxnums[], int complexnumbercount, char* filename)
{
    if(config.minreal > 0)
    {
        config.minreal = 0.0;
    }

    if(config.minimag > 0)
    {
        config.minimag = 0.0;
    }

    int graph_height = config.height - (config.margin * 2);
    int graph_width = config.width - (config.margin * 2);
    double pixels_per_unit_real = (double)graph_width / (double)(config.maxreal - config.minreal);
    double pixels_per_unit_imag = (double)graph_height / (double)(config.maximag - config.minimag);
    double realzero = config.margin + (double)(fabs(config.minreal) * pixels_per_unit_real);
    double imagzero = config.margin + (double)(config.maximag * pixels_per_unit_imag);
    double x;
    double y;
    char number_string[8];

    // Create svg struct
    svg* psvg;
    psvg = svg_create(config.width, config.height);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {
        svg_fill(psvg, "#FFFFFF");

        // axis lines
        svg_line(psvg, "#808080", 2, realzero, config.margin, realzero, config.height - config.margin);
        svg_line(psvg, "#808080", 2, config.margin, imagzero, config.width - config.margin, imagzero);

        // real indexes
        x = config.margin;
        for(int i = config.minreal; i <= config.maxreal; i+= config.indexspacingreal)
        {
            svg_line(psvg, "#808080", 2, x, imagzero, x, imagzero + 4);

            if(i != 0)
            {
                sprintf(number_string, "%d", i);
                svg_text(psvg, x, imagzero + 16, "sans-serif", 10, "#000000", "#000000", "middle", number_string);
            }

            x += (config.indexspacingreal * pixels_per_unit_real);
        }

        // imaginary indexes
        y = config.margin;
        for(int i = config.maximag; i >= config.minimag; i-= config.indexspacingimag)
        {
            svg_line(psvg, "#808080", 2, realzero - 4, y, realzero, y);

            if(i != 0)
            {
                sprintf(number_string, "%d", i);
                svg_text(psvg, realzero - 8, y + 4, "sans-serif", 10, "#000000", "#000000", "end", number_string);
            }

            y += (config.indexspacingimag * pixels_per_unit_imag);
        }

        // complex numbers
        for(int c = 0; c < complexnumbercount; c++)
        {
            x = realzero + (creal(cplxnums[c]) * pixels_per_unit_real);
            y = imagzero - (cimag(cplxnums[c]) * pixels_per_unit_imag);

            svg_circle(psvg, "#0000FF", 0, "#0000FF", 3, x, y);
        }

        svg_finalize(psvg);

        svg_save(psvg, filename);

        puts("File saved");

        svg_free(psvg);
    }
}
