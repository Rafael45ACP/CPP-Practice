#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cctype>
#include <thread>
#include <chrono>

using namespace std;

int getStart();
int getBet(int x);
int randCard();
string toLow(string txt);
string getHit(int total);
bool playAgain();
bool canSplit(int x, int y);
int getTotal(const vector<int> &num);
string getSplit();

int main()
{

    srand(time(0));

    int random = rand() % 11 + 1;

    vector<int> userc;
    vector<int> compc;

    vector<int> usercSplit;

    int startM = 0;

    int bet = 0;

    int uCard1 = 0;
    int uCard2 = 0;
    bool split = false;

    char uStatus = 'n';
    char pcStatus = 'n';

    bool play = true;

    while (play == true)
    {
        this_thread::sleep_for(chrono::milliseconds(600));
        startM = getStart();

        this_thread::sleep_for(chrono::milliseconds(600));
        cout << "\nCurrent Balance: " << startM << endl;

        do
        {

            if (bet == 0)
            {
                bet = getBet(startM);
            }

            compc.push_back(randCard());
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "\nDealer gets " << compc.at(0) << endl;
            
            userc.push_back(randCard());
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "\nPlayer gets " << userc.at(0) << endl;
            
            compc.push_back(randCard());
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "\nDealer gets ??" << endl;
            
            userc.push_back(randCard());
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "\nPlayer gets " << userc.at(1) << endl;

            this_thread::sleep_for(chrono::milliseconds(600));
            cout << "\nDealer has " << compc.at(0) << ", ?? " << endl;

            this_thread::sleep_for(chrono::milliseconds(600));
            cout << "Player has " << userc.at(0) << ", " << userc.at(1) << endl;

            int uTotal = 0;
            int pcTotal = 0;

            uCard1 = userc.at(0);
            uCard2 = userc.at(1);

            split = canSplit(uCard1, uCard2);

            string sChoice = "n";

            if(split == true){
                sChoice = getSplit();  
            }

            if(sChoice == "y" || sChoice == "yes"){
                usercSplit.push_back(userc.back());
                userc.pop_back();
            }

            

            uTotal = getTotal(userc);
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "\nPlayer has a total of " << uTotal << endl;

            pcTotal = getTotal(compc);

            string choice;

            choice = getHit(uTotal);

            while (choice == "h" || choice == "hit")
            {

                userc.push_back(randCard());
                this_thread::sleep_for(chrono::milliseconds(600));
                cout << "\nPlayer gets " << userc.back() << endl;

                uTotal = getTotal(userc);

                this_thread::sleep_for(chrono::milliseconds(600));
                cout << "\nPlayer has a total of " << uTotal << endl;

                if (uTotal > 21)
                {
                    this_thread::sleep_for(chrono::milliseconds(800));
                    cout << "\nBust! You lose! \n";
                    uStatus = 'b';
                    choice = "s";
                    break;
                }
                if (uTotal == 21)
                {
                    this_thread::sleep_for(chrono::milliseconds(800));
                    cout << "\nBlackjack!\n";
                    choice = "s";
                    break;
                }
                choice = getHit(uTotal);
            }

            if (choice == "s" || choice == "stand")
            {

                this_thread::sleep_for(chrono::milliseconds(400));

                cout << "\nDealer has " << compc.at(0) << ", " << compc.at(1) << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                cout << "\nDealer has a total of " << pcTotal << endl;

                while (pcTotal <= 16 && uStatus != 'b')
                {

                    compc.push_back(randCard());
                    this_thread::sleep_for(chrono::milliseconds(600));
                    cout << "\nDealer gets " << compc.back() << endl;

                    pcTotal = getTotal(compc);

                    this_thread::sleep_for(chrono::milliseconds(600));
                    cout << "\nDealer has a total of " << pcTotal << endl;

                    if (pcTotal > 21)
                    {
                        this_thread::sleep_for(chrono::milliseconds(800));
                        cout << "\nBust! Player Wins! \n";
                        pcStatus = 'b';
                        break;
                    }
                    if (pcTotal == 21)
                    {
                        this_thread::sleep_for(chrono::milliseconds(800));
                        cout << "\nDealer gets Blackjack!\n";
                        break;
                    }
                }
                this_thread::sleep_for(chrono::milliseconds(400));
                if (uStatus == 'b')
                {
                    // cout << "\nYou lose!\n";
                    startM -= bet;
                }
                else if (pcStatus == 'b')
                {
                    startM += bet;
                }
                else if (uTotal > pcTotal)
                {
                    this_thread::sleep_for(chrono::milliseconds(600));
                    cout << "\nYou Win!\n";
                    startM += bet;
                }
                else if (pcTotal > uTotal)
                {
                    this_thread::sleep_for(chrono::milliseconds(600));
                    cout << "\nYou lose!\n";
                    startM -= bet;
                }
                else
                {
                    this_thread::sleep_for(chrono::milliseconds(600));
                    cout << "\nIt's a draw!\n";
                }
            }
            userc.clear();
            compc.clear();

            uStatus = 'n';
            pcStatus = 'n';

            bet = 0;

            cout << "\nCurrent Balance: " << startM << endl;

        } while (startM != 0);

        cout << "Game Over! \n";
        play = playAgain();
    }

    return 0;
}

int getStart()
{
    int x;
    do
    {
        cout << "\nWhat is your starting money?\n";
        cin >> x;

        if (cin.fail())
        {
            cout << "\nInvalid input! Enter only integers!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clean input
        }
    } while (x <= 0);
    return x;
}

int getBet(int x)
{
    int y;
    do
    {
        cout << "\nHow much do you want to bet?\n";
        cin >> y;

        if (cin.fail())
        {
            cout << "\nInvalid input! Enter only integers!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clean input
        }
    } while (y <= 0 || y > x);
    return y;
}

int randCard()
{

    int random = rand() % 10 + 1;

    return random;
}

string getHit(int total)
{
    string c;

    this_thread::sleep_for(chrono::milliseconds(700));

    while (true)
    {
        cout << "\nHit or Stand?\n";
        cin >> c;

        if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        c = toLow(c);

        if (c == "h" || c == "hit" || c == "s" || c == "stand"){
            break;
        }
        else{
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "\nInvalid choice! (Hit or Stand)\n";
            cout << "Player has a total of " << total << endl;
        }
    }

    return c;
}

string toLow(string txt)
{
    for (char &c : txt)
    {
        c = tolower(c);
    }

    return txt;
}

int getTotal(const vector<int> &num)
{
    int sum = 0;
    for (int t : num)
    {
        sum += t;
    }
    return sum;
}

bool playAgain()
{
    char choice;

    cout << "\nDo you want to play again? (y/n)\n";
    cin >> choice;

    if (choice == 'y')
    {
        return true;
    }
    else{
        cout << "\nI'm counting that as a no.\n";
        return false;
    }
}

bool canSplit(int x, int y){
    if(x == y){
        return true;
    }
    else return false;
}

string getSplit(){
    string sc;

     this_thread::sleep_for(chrono::milliseconds(700));

    while (true)
    {
        cout << "\nSplitable!\n";
        cout << "Do you want to split the cards?\n";
        cin >> sc;

        sc = toLow(sc);

        if(sc == "y" || sc == "yes" || sc == "n" || sc == "no"){
            break;
        }
        else 
        {
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "\nInvalid choice! (Y/N)\n";
        }

    }
    return sc;

}