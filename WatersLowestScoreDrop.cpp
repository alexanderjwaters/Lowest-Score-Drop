//  Created by Alex Waters on 9/18/18.
//  main.cpp
//  Chapter6Assignment - Lowest Score Drop
//  This program calculates the average of a group of test
//  scores, and drops the lowest score in the group using
//  functions.
//
//  Copyright © 2018 Alex Waters. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototype
void getScore(int &);
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);

int main()
{
    // Holds users testScores.
    int score1,
        score2,
        score3,
        score4,
        score5;
    
    //  Display program to user
    cout << "Enter 5 test scores and get the average\n"
         << "with the lowest score dropped..." << endl;
    
    //  Get 5 testScores from user.
    getScore(score1);
    getScore(score2);
    getScore(score3);
    getScore(score4);
    getScore(score5);
    
    //  Calculate and display average score.
    calcAverage(score1, score2, score3, score4, score5);
    
    //  Display exit message
    cout << "\nSee ya soon!" << endl;
    
    return 0;
}

//***********************************************************
//  Definition of function getScores.                       *
//  Asks user for test score and stores it in reference     *
//  variable and validates it.                              *
//***********************************************************

void getScore(int &testScore)
{
    static short iterations = 1;    // To hold functions iterations
    
    //  Get test score from user.
    cout << "\nEnter test score " << "#" << iterations << ": ";
    cin >> testScore;
    
    // Input Validation: score must be 1 - 100.
    while (testScore < 1 || testScore > 100)
    {
        //  Display error to user and get new testScore.
        cout << "\nError! Must enter test score 1 - 100\n"
             << "Re-Enter test score: ";
        cin >> testScore;
    }
    iterations++;
}

//***********************************************************
//  Definition of function calcAverage.                     *
//  Calculates and displays the average of the four highest *
//  scores.                                                 *
//***********************************************************

void calcAverage(int test1, int test2, int test3, int test4, int test5)
{
    int lowest;     // To hold lowest testScore
    float average;  // To hold average testScore
    
    //  Find lowest testScore
    lowest = findLowest(test1, test2, test3, test4, test5);
    
    //  Find average testScore
    average = ((test1 + test2 + test3 + test4 + test5) - lowest) / 4.0;
    
    //  Set up numeric output formatting
    cout << fixed << showpoint << setprecision(2);
    
    //  Display average testScore
    cout << "\nAverage test score is " << average << endl;
}

//***********************************************************
//  Definition of function findLowest.                      *
//  Returns the lowest of 5 testScores passed to it.        *
//***********************************************************

int findLowest(int test1, int test2, int test3, int test4, int test5)
{
    int lowestScore;    //  To hold lowest testScore
    
    if (test1 < test2 && test1 < test3 &&
        test1 < test4 && test1 < test5)
        lowestScore = test1;
    else if (test2 < test1 && test2 < test3 &&
             test2 < test4 && test2 < test5)
        lowestScore = test2;
    else if (test3 < test1 && test3 < test2 &&
             test3 < test4 && test3 < test5)
        lowestScore = test3;
    else if (test4 < test1 && test4 < test2 &&
             test4 < test3 && test4 < test5)
        lowestScore = test4;
    else
        lowestScore = test5;
    
    return lowestScore;
}
