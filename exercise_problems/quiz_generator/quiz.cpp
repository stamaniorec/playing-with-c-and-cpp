#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define NUM_OF_QUESTIONS 5

void set_q_and_a(string &line, string &q, string &a)
{
    int index = line.find(':');
    q = line.substr(0, index);
    a = line.substr(index+1);
}

int main()
{
    ifstream questions_file("questions.txt");

    if(!questions_file.is_open())
    {
        cerr << "Error opening file." << endl;
        return -1;
    }

    srand(time(NULL));

    string current_question, current_answer, current_line, user_answer;
    int score = 0;
    int rand_number;
    int question_number; // to traverse the file
    bool checked[NUM_OF_QUESTIONS] = {false};

    for(int i = 0; i < NUM_OF_QUESTIONS; ++i)
    {
        question_number = -1; // we count from 0 to n-1
        rand_number = rand() % NUM_OF_QUESTIONS;

        while(getline(questions_file, current_line) && question_number < rand_number && !checked[question_number])
        {
            checked[question_number] = true;
            ++question_number;
        }

        set_q_and_a(current_line, current_question, current_answer);

        cout << current_question << endl;
        getline(cin, user_answer);

        if(user_answer == current_answer)
            ++score;
    }

    cout << "Score: " << (float)score/NUM_OF_QUESTIONS * 100 << "%" << endl;

    return 0;
}
