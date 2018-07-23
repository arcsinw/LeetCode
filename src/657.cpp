#include <iostream>
#include <string>

using namespace std;

bool judgeCircle(string moves)
{
    int horizontal = 0;
    int vertical = 0;

    for (int i = 0; i < moves.length(); i++)
    {
        if (moves[i] == 'U')
        {
            vertical++;
        }
        else if (moves[i] == 'D')
        {
            vertical--;
        }
        else if (moves[i] == 'L')
        {
            horizontal++;
        }
        else if (moves[i] == 'R')
        {
            horizontal--;
        }
    }
    return (horizontal==0 && vertical==0);
}

int main()
{
    string road_1 = "UD";
    return judgeCircle(road_1);
}
