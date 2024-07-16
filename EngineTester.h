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

};


#endif //CHESS_ENGINETESTER_H
