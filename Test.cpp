/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}
//HNLRXYTB
TEST_CASE("Good snowman code")
{
    // for hat(H)
    //change for the snow man have nose(,)
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(21114411)) == nospaces(" ___ \n.....\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(31114411)) == nospaces("_\n/_\\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41114411)) == nospaces("  ___\n(_*_)\n(.,.)\n( : )\n( : )"));

    //change for the snow man have nose(.)
    CHECK(nospaces(snowman(22114411)) == nospaces(" ___ \n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(32114411)) == nospaces("_\n/_\\n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(42114411)) == nospaces("  ___\n(_*_)\n(...)\n( : )\n( : )"));

    //change for the snow man have nose(_)
    CHECK(nospaces(snowman(23114411)) == nospaces(" ___ \n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(33114411)) == nospaces("_\n/_\\\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(43114411)) == nospaces("  ___\n(_*_)\n(._.)\n( : )\n( : )"));

    //change for snow man that have left eye(o)
    CHECK(nospaces(snowman(21214411)) == nospaces(" ___ \n(o,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(31214411)) == nospaces("_\n/_\\n(o,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41214411)) == nospaces("  ___\n(_*_)\n(o,.)\n( : )\n( : )"));

    //change for snow man that have left eye(O)
    CHECK(nospaces(snowman(21314411)) == nospaces(" ___ \n(O,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(31314411)) == nospaces("_\n/_\n(O,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41314411)) == nospaces("  ___\n(_*_)\n( : )\n( : )"));

    //change for snow man that have left eye(-)
    CHECK(nospaces(snowman(21414411)) == nospaces(" ___ \n(-,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(31414411)) == nospaces("_\n/_\n(-,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41414411)) == nospaces("_===_\n(-,.)\n( : )\n( : )"));

 //for nose(N)
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(..)\n( : )\n( : )"));

//for left eyes(L)

    CHECK(nospaces(snowman(11214411)) == nospaces("_===_\n(o,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11314411)) == nospaces("_===_\n(O,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11414411)) == nospaces("_===_\n(-,.)\n( : )\n( : )"));

 //for right eyes(R)
    CHECK(nospaces(snowman(11124411)) == nospaces("_===_\n(.,o)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11134411)) == nospaces("_===_\n(.,O)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11134411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));

 //for Left Arm(X )
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
    CHECK(nospaces(snowman(11113411)) == nospaces("_===_\n(.,.)\n/( : )\n( : )"));

// for Torso(T)
    CHECK(nospaces(snowman(11114421)) == nospaces("_===_\n(.,.)\n(] [)\n( : )"));
    CHECK(nospaces(snowman(11114431)) == nospaces("_===_\n(.,.)\n(> <)\n( : )"));
    CHECK(nospaces(snowman(11114441)) == nospaces("_===_\n(.,.)\n(  )\n( : )"));

 //for Base( B  )
    CHECK(nospaces(snowman(11114412)) == nospaces("_===_\n(.,.)\n( : )\n( " " )"));
    CHECK(nospaces(snowman(11114413)) == nospaces("_===_\n(.,.)\n( : )\n( ___ )"));
    CHECK(nospaces(snowman(11114414)) == nospaces("_===_\n(.,.)\n( : )\n( )"));
}

TEST_CASE("Negative digit")
{

    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(-11111411));
}
TEST_CASE("The number of digit is less than 8")
{

    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(123456));
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(98562255));
    CHECK_THROWS(snowman(125));
    CHECK_THROWS(snowman(235585));
}
TEST_CASE("The number of digit is more than 8")
{

    CHECK_THROWS(snowman(111111111));
    CHECK_THROWS(snowman(123444441));
}
TEST_CASE("one of the digits is larger than 4")
{

    CHECK_THROWS(snowman(51111111));
    CHECK_THROWS(snowman(11124419));
}
TEST_CASE("one of the digits is smaller than 1")
{

    CHECK_THROWS(snowman(10124411));
}