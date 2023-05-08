//
// Don't modify code in this file.
//
#define _USE_MATH_DEFINES
#include <cmath>

#ifndef APEXLAB_APEX_CODE_H
#define APEXLAB_APEX_CODE_H

struct Cup
{
    double TopRadiusCms;
    double BottomRadiusCms;
    double HeightCms;
    double AmountOfFluid;

    Cup(double topRadius, double bottomRadius, double height)
    {
        TopRadiusCms = topRadius;
        BottomRadiusCms = bottomRadius;
        HeightCms = height;
        AmountOfFluid = 0;
    }

    double capacityInMls() const;
};

bool addFluid(Cup * cup, double mls);

double howFull(const Cup & cup);

bool mlPerDollar(const Cup & cup, double pricePerDrink, double & output);

#endif //APEXLAB_APEX_CODE_H
