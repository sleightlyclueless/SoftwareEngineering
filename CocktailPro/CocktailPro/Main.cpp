// Main.cpp
/**
 *@author Di1-BauerKoobKooZill
 *
 */

#include "CocktailPro.h"
#include <iostream>

int main(int argc, char* argv[])
{
    CocktailPro cp(argc, argv[1]);
    const std::string startparam;
    cp.start(startparam);               // call start method to print interface and handle inputs
    cp.demo();
    return 0;
}