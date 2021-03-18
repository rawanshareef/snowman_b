#include <string>
#include <iostream>
#include <array>
#include "snowman.hpp"
using namespace std;
const int dev = 10;
const int MaxD = 8;
const int maxDig = 4;
const int minDig = 1;
const int RA = 5;
const int T = 6;
const int B = 7;
const int TheMin = 11111111;
const int TheMax = 44444444;

//check if the input true
bool check_num(int x)
{
    bool flage = true;
    int help = x;
    while (help > 0)
    {
        if (help % dev > maxDig || help % dev < minDig)
        {
            return !flage;
        }

        help = help / dev;
    }

    return flage;
}

string Bulid_snow(int x)
{
    string snowmanB;
    const array<string,4> hat = {" _===_", "  ___\n .....", "   _\n  /_\\", "  ___\n (_*_)"};
    const array<string,4> NoseAndMouth = {",",".","_"," "};
    const array<string,4> LeftEye = {"(.","(o","(O","(-"};
    const array<string,4> RightEye = {".)","o)","O)","-)"};
    const array<string,4> LeftArm_up = {" ","\\"," "," "};
    const array<string,4> LeftArm_under ={"<"," ","/"," "};
    const array<string,4> RightArm_up = {"","/"," "," "};
    const array<string,4> RightArm_under ={">"," ","\\"," "};
    const array<string,4> Torso = {"( : )","(] [)","(> <)","(   )"};
    const array<string,4> Base = {" ( : )"," (\" \")"," (___)"," (   )"};

    int help = x;
    array<int, MaxD> answer = {0};
    for (int i = MaxD - 1; i >= 0; i--)
    {
        answer.at(i) = help % dev;
        help = help / dev;
    }
    /* HHHHH
       HHHHH
      X(LNR)Y
      X(TTT)Y
       (BBB) 
            */
    //HNLRXYTB

    //bulid hat
    /* HHHHH
       HHHHH*/
    snowmanB += hat.at(answer[0] - 1);
    snowmanB += "\n";

    // X(LNR)Y
    //bulid Left Arm up
    snowmanB+= LeftArm_up.at(answer[4] - 1);

    //bulid  Left Eye
    snowmanB += LeftEye.at(answer[2] - 1);

    //bulid NOSE\MOTH
    snowmanB += NoseAndMouth.at(answer[1] - 1);

    //bulid Right Eye
    snowmanB += RightEye.at(answer[3]-1);

    //bulid Right Arm up
    snowmanB += RightArm_up.at(answer[RA] - 1);
    snowmanB+= "\n";

    //X(TTT)Y
    //bulid Left Arm under
    snowmanB += LeftArm_under.at(answer[4] - 1);
    //bulid T
    snowmanB += Torso.at(answer[T] - 1);
    

    //bulid Right Arm under
    snowmanB += RightArm_under.at(answer[RA] - 1);
    snowmanB+= "\n";
    
    // (BBB)
    //bulid BSES
    snowmanB += Base.at(answer[B] - 1);

    return snowmanB;
}

string ariel::snowman(int x) 
{
    bool res = check_num(x);
    if (!res)
    {
        throw string("x not takeen" + to_string(x));
    }
    if ((x < TheMin) || (x > TheMax))
    {
        throw string("x not bhla" + to_string(x));
    }
    return Bulid_snow(x);
}
