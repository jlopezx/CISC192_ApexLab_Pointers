//
// Don't modify code in this file.
//
#define _USE_MATH_DEFINES
#include <cmath>

#ifndef APEXLAB_APEX_CODE_H
#define APEXLAB_APEX_CODE_H

// Constants declared to avoid magic numbers. Used in the truncated cone volume formula in apex_code.cpp
// One third factor is used to help calculate the volume of a cone
const double ONE_THIRD_FACTOR = 1.0/3.0;
// Square is used to square numbers
const int SQUARE = 2;

struct Cup
{
    double topRadiusCms;
    double bottomRadiusCms;
    double heightCms;
    double amountOfFluid;

    Cup(double topRadius, double bottomRadius, double height)
    {
        topRadiusCms = topRadius;
        bottomRadiusCms = bottomRadius;
        heightCms = height;
        amountOfFluid = 0;
    }

    double capacityInMls() const;
};

bool addFluid(Cup* cup, double mls);

double howFull(const Cup& cup);

bool mlPerDollar(const Cup& cup, double pricePerDrink, double& output);

#endif //APEXLAB_APEX_CODE_H
