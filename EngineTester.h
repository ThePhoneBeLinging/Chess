//
// Created by Elias Aggergaard Larsen on 16/07/2024.
//

#ifndef CHESS_ENGINETESTER_H
#define CHESS_ENGINETESTER_H


class EngineTester
{
public:
    EngineTester ();

    void testEngines ();

    int getDraws () const;

    int getEngine1Wins () const;

    int getEngine2Wins () const;

private:
    int draws;
    int engine1Wins;
    int engine2Wins;
    int avgTimeUsed1;
    int avgTimeUsed2;
    int movesMade1;
    int movesMade2;
};


#endif //CHESS_ENGINETESTER_H
