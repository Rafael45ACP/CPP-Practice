#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int getStart();
int getBet(int x);
// void gameStart();
int randCard();

int main()
{

    srand(time(0));

    int random = rand() % 11 + 1;

    vector<int> userc;
    vector<int> compc;

    int startM = 0;

    int bet = 0;

    startM = getStart();
    // bool game = true;

    while (startM != 0)
    {

        if (bet == 0)
        {
            bet = getBet(startM);
        }

        compc.push_back(randCard());
        userc.push_back(randCard());
        compc.push_back(randCard());
        userc.push_back(randCard());

        // cout << compc.at(0);
        // cout << compc.at(1);

        break;
    }

    return 0;
}

int getStart()
{
    int x;
    do
    {
        cout << "What is your starting money?\n";
        cin >> x;
    } while (x <= 0);
    return x;
}

int getBet(int x)
{
    int y;
    do
    {
        cout << "How much do you want to bet?\n";
        cin >> y;
    } while (y <= 0 || y > x);
    return y;
}

int randCard()
{

    int random = rand() % 10 + 1;

    return random;
}
