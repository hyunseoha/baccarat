#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    // define shoe, player & banker's card, random for drawing
    vector <int> shoe, collectedCard, drawing {} ;

    // define scores and random numbers
    int playerbaccaratScore, bankerbaccaratScore, random {};    
    
    // define the balance
    int balance_player, balance_player_after_bet {};
    
    // define the bet account
    int bet_player, bet_tie, bet_banker {};
    
    // building up the shoe-
    for (int i = 0; i < 13; i++) {
        shoe.push_back(i);
    }
    // shoe has to have four 0. 
    for (int i = 0 ; i < 3; i++) {
        shoe.at(i+10) = 0;
    }
    // shoe is built up 4 different pattern, now here i dont put any patter.
    for (int i = 0; i<3; i++){
        for (int i = 0; i<13;i++) {
            shoe.push_back(shoe.at(i));
        }
    } 
    // the shoe is shown.
    cout << endl;
    cout << shoe.size() << endl;
    cout << endl;
    for (int i = 0; i < 52; i++) {
        cout << shoe.at(i) << " " ;
    }
    // how many cards are in the shoe.
    cout << endl << "we have " << shoe.size() << " cards in the shoe."<< endl;
    cout << endl;    

    // defind the random number and organise a random deck into drawing vector.
    unsigned seed = time(0);
    srand(seed);
    for (int i = 0;i<52;i++){
        random = rand() % (52);
        drawing.push_back(random);
    }
    // Finished with random number organising.
    
    // setup the deck
    for (int i = 0; i < 52; i++) {
        collectedCard.push_back(drawing.at(i));
    }

    // deposit setup
    cout << "how much do you want to deposit ?" << endl;
    cin >> balance_player;
    
    
    // show that the bet begins.
    cout << endl;
    int rounds {5};
    for(int i = 0; i < rounds ; i++){ 
        cout << endl;
        cout << "................ the Casino is opened  No " << i <<"................" << endl;
        cout << ".............Your current balance is " << balance_player << " € ............"<< endl;
        cout << endl;
    
    // begins bet
        cout << "place your bet. the order is player and banker. put the bet with one space." << endl;
        cin >> bet_player >> bet_banker;
        cout << "do you want to bet tie ?" << endl;
        cin >> bet_tie ;
    
    // show the balance after the bet.
        balance_player_after_bet = balance_player - bet_player - bet_banker - bet_tie;
    
        cout << endl << "your current balance is " << balance_player_after_bet << endl;
    // score compute

        playerbaccaratScore = (collectedCard.at(4*i) + collectedCard.at(4*i+2)) % 10;
        bankerbaccaratScore = (collectedCard.at(4*i+1) + collectedCard.at(4*i+3)) % 10;

    // showing the score
        cout << endl;
        cout << " the player's score " << playerbaccaratScore << endl;
        cout << " the banker's score " << bankerbaccaratScore << endl;

    // judge the winner.
        if (playerbaccaratScore > bankerbaccaratScore) {
            balance_player += bet_player * 2; // bet_player
            balance_player -= bet_banker ; // bet_banker
            balance_player -= bet_tie; // bet_tie but not come up
            cout << "Player won !" << endl;
        } else if (playerbaccaratScore == bankerbaccaratScore) {
            balance_player += bet_tie * 8;    // bet_tie yes come up
            balance_player -= bet_banker | bet_player;
            cout << "TIE" << endl;
        } else {
            balance_player -= bet_player ;     // bet_banker 
            balance_player += bet_banker * 2 - bet_banker * 0.05; // bet_player
            balance_player -= bet_tie; // bet_tie but not come up
            cout << "Banker won !" << endl;
        }
        cout << ".............Your current balance is " << balance_player << " € ............"<< endl;
        cout << endl;
    }
return 0;
}
