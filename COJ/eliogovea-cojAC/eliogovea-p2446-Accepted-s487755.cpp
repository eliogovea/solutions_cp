#include<cstdio>
#include<iostream>
using namespace std;

string b,w;
char B,W;



int main()
{
    //scanf("%s %s",&b,&w);
    cin >> b >> w;

    if(b=="WWW")B='s';
    else if(b=="BBB")B='r';
    else B='p';

    if(w=="WWW")W='s';
    else if(w=="BBB")W='r';
    else if(w=="BBW"||w=="BWB"||w=="WBB")W='r';
    else if(w=="WWB"||w=="WBW"||w=="BWW")W='s';

    if(B=='s' && W=='p')printf("Bianka won with Scissors\nWilliams lost with Paper\n");
    else if(B=='p' && W=='s')printf("Williams won with Scissors\nBianka lost with Paper\n");
    else if(B=='s' && W=='r')printf("Williams won with Rock\nBianka lost with Scissors\n");
    else if(B=='r' && W=='s')printf("Bianka won with Rock\nWilliams lost with Scissors\n");
    else if(B=='r' && W=='p')printf("Williams won with Paper\nBianka lost with Rock\n");
    else if(B=='p' && W=='r')printf("Bianka won with Paper\nWilliams lost with Rock\n");

    return 0;
}
