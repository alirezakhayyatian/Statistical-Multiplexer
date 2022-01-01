// WirelessHW1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

#include  "multiplexer/multiplexer.h"
#include  "Tests/MultiplexerTest.h"


using namespace std;


int main()
{

	//Tests::OneMultiplexer();

	Tests::ThreeMultiplexer();
	
    return 0;
}



