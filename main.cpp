#include <iostream>
#include <list>
#include <iterator>
#include <chrono>
#include <fstream>
#include <string>
#include "partOne.h"
#include "partTwo.h"
#include "partThree.h"

using namespace std;

/*
 * A main method for calling test functions representing each of the three parts of the assignment.
 */
int main(int argc, const char* argv[])
{

    cout << "==PART ONE==\n\n";
	partOne();

    cout << "==PART TWO==\n\n";
    partTwo();

    cout << "==PART THREE==\n\n";
    partThree(argc, argv);

	return 0;
};

