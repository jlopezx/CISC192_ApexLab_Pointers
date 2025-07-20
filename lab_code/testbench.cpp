//
// Don't modify code in this file, with the exception
// of adding test cases.
//
#include "apex_code.h"
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

static int testNum = 0;
static int testsCorrect = 0;

static int funcTestNum = 0;
static int funcTestCorrect = 0;

bool near(double expected, double result, double threshold) {
  return abs(expected - result) < threshold;
}

// Use when testing double values
bool testNear(double expected, double result) {
  funcTestNum++;
  testNum++;

  if (false == near(expected, result, 0.002)) {
    cout << "FAILED: Expected " << expected << ", received " << result << ".\n";
  } else {
    cout << "PASS\n";
    testsCorrect++;
    funcTestCorrect++;
  }

  return expected == result;
}

// Use for everything other than doubles/floats
template <typename T> bool test(T expected, T result) {
  funcTestNum++;
  testNum++;

  if (expected != result) {
    cout << "FAILED: Expected " << expected << ", received " << result << ".\n";
  } else {
    cout << "PASS\n";
    testsCorrect++;
    funcTestCorrect++;
  }

  return expected == result;
}

/**
 * Mark the starting point for the tests of a specific function.
 *
 * @param startFuncName the function name to start testing
 */
void startTests(string startFuncName) {
  cout << "----- Start of testing " << startFuncName << " -----" << endl;

  funcTestNum = 0;
  funcTestCorrect = 0;
}

/**
 * Mark the ending point for the tests of a specific function.
 *
 * @param endFuncName the function name to end testing
 */
void endTests(string endFuncName) {
  if (funcTestNum == funcTestCorrect) {
    cout << "----- All tests passed for " << endFuncName << "! -----" << endl;
  } else {
    cout << "----- Some tests failed for " << endFuncName << " :( -----"
         << endl;
  }
  cout << endl;
}

/**
 * Mark the end of the test suite.
 */
void endAllTests() {
  if (testsCorrect == testNum) {
    cout << "All tests passed! Let's goooo" << endl;
  } else {
    cout << "Some tests failed. Keep trying!" << endl;
  }
}

int main() {
  // To add a test case, duplicate the test lines below
  // You can add more local cup instances

  Cup unitCup(1, 1, 1);
  Cup twoCup(2, 1, 1);
  Cup cup(5.3, 4.0, 9.0);

  Cup *cupPtr = new Cup(twoCup);

  // test capacityInMls
  startTests("capacityInMls");
  (void)testNear(3.1415, unitCup.capacityInMls());
  (void)testNear(7.3303, twoCup.capacityInMls());
  cupPtr->heightCms = 2;
  (void)testNear(14.6608, cupPtr->capacityInMls());
  cupPtr->bottomRadiusCms = 2;
  (void)testNear(25.1327, cupPtr->capacityInMls());
  endTests("capacityInMls");

  // test addFluid and howFull
  startTests("howFull and addFluid");
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
  endTests("howFull and addFluid");

  startTests("mlPerDollar");
  double output;
  (void)testNear(true, mlPerDollar(cup, 3.25, output));
  (void)testNear(189.3365, output);
  (void)testNear(false, mlPerDollar(cup, -3.25, output));
  (void)testNear(189.3365, output);
  (void)testNear(true, mlPerDollar(cup, 100.05, output));
    (void)testNear(6.15036, output);
  endTests("mlPerDollar");

  endAllTests();

  return 0;
}
