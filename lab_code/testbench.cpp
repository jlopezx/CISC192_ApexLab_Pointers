//
// Don't modify code in this file, with the exception
// of adding test cases.
//
#include <iostream>
#include <iomanip>
#include <random>
#include "apex_code.h"

using namespace std;

bool near(double expected, double result, double threshold)
{
    return abs(expected - result) < threshold;
}

// Use when testing double values
bool testNear(double expected, double result)
{
    if(false == near(expected, result, 0.002))
    {
        cout << "FAILED: Expected " << expected << ", received " << result << ".\n";
    }
    else {
        cout << "PASS\n";
    }

    return expected == result;
}

// Use for everything other than doubles/floats
template<typename T> bool test(T expected, T result)
{
    if(expected != result)
    {
        cout << "FAILED: Expected " << expected << ", received " << result << ".\n";
    }
    else {
        cout << "PASS\n";
    }

    return expected == result;
}
int main()
{
    // To add a test case, duplicate the test lines below
    // You can add more local cup instances

    Cup unitCup(1, 1, 1);
    Cup twoCup(2, 1, 1);
    Cup cup(5.3, 4.0, 9.0);

    Cup* cupPtr = new Cup(twoCup);

    // test capacityInMls
    (void)testNear(3.1415, unitCup.capacityInMls());
    (void)testNear(7.3303, twoCup.capacityInMls());
    cupPtr->HeightCms = 2;
    (void)testNear(14.6608, cupPtr->capacityInMls());
    cupPtr->BottomRadiusCms = 2;
    (void)testNear(25.1327, cupPtr->capacityInMls());
  
    // test addFluid and howFull
    (void)testNear(0.0, howFull(*cupPtr));
    test<bool>(true, addFluid(cupPtr, 25));
    (void)testNear(0.994718, howFull(*cupPtr));
    test<bool>(false, addFluid(cupPtr, 1));
    (void)testNear(0.994718, howFull(*cupPtr));

    (void)testNear(0.0, howFull(unitCup));
    test<bool>(true, addFluid(&unitCup, 2));
    (void)testNear(0.63662, howFull(unitCup));
    test<bool>(true, addFluid(&unitCup, -1));
    (void)testNear(0.31831, howFull(unitCup));
    test<bool>(false, addFluid(&unitCup, -2));
    (void)testNear(0.31831, howFull(unitCup));

    double output;
    (void)testNear(true, mlPerDollar(cup, 3.25, output));
    (void)testNear(189.3365, output);
    (void)testNear(false, mlPerDollar(cup, -3.25, output));
    (void)testNear(189.3365, output);
    //(void)testNear(0.251202, mlPerDollar(*cupPtr, 100.05));
    //(void)testNear(12.5664, mlPerDollar(cup, -3.25));

    return 0;
}
