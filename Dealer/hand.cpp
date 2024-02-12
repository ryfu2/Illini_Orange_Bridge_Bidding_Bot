#include "hand.h"
#include <random>
#include <bits/stdc++.h> 
#include <ctime>
#include <fstream>
Hand::player::player() {
    //Initialize an empty player had
    len_S = 0;
    len_H = 0;
    len_D = 0;
    len_C = 0;
    HCP = 0;
    LTC = 0;
    cards.resize(0);
    spades.resize(0);
    hearts.resize(0);
    diamonds.resize(0);
    clubs.resize(0);

}

Hand::Hand(int seed)
{
    //Deal a hand
    vector<int> deck;   //Initialize the deck
    srand(time(0) + (seed % time(0)));
    for (int i = 0; i <= 51; ++i) {
        deck.push_back(i);
    }

    for (int i = 0; i < 13; ++i) {  //Deal 13 cards to north
        int temp = std::rand() % deck.size();
        int cur = deck[temp];
        deck.erase(deck.begin() + temp);
        North.get_card(cur);
    }
    North.finalization();

    for (int i = 0; i < 13; ++i) {  //Deal 13 cards to south
        int temp = std::rand() % deck.size();
        int cur = deck[temp];
        deck.erase(deck.begin() + temp);
        South.get_card(cur);
    }
    South.finalization();

    for (int i = 0; i < 13; ++i) {  //Deal 13 cards to east
        int temp = std::rand() % deck.size();
        int cur = deck[temp];
        deck.erase(deck.begin() + temp);
        East.get_card(cur);
    }
    East.finalization();

    for (int i = 0; i < 13; ++i) {  //Deal 13 cards to west
        int temp = std::rand() % deck.size();
        int cur = deck[temp];
        deck.erase(deck.begin() + temp);
        West.get_card(cur);
    }
    West.finalization();
}

void Hand::print_wholehand()
{
    std::cout<< "North:" << std::endl;
    North.print_hand();
    std::cout<< "South:" << std::endl;
    South.print_hand();
    std::cout<< "East:" << std::endl;
    East.print_hand();
    std::cout<< "West:" << std::endl;
    West.print_hand();
}

void Hand::generate_hand_file(int boardnum)
{
    North.generate_player_log(0, boardnum);
    South.generate_player_log(1, boardnum);
    East.generate_player_log(2, boardnum);
    West.generate_player_log(3, boardnum);
}

Hand::player::player(int S_len, int H_len, int D_len, int C_len, int HCP_, int LTC_) {
    //Create a hand with specific requirements
    return;
}

void Hand::player::print_hand()
{
    //Print out a player's hand
    std::cout << "Spades: ";
    for (auto i = 0; i < spades.size(); ++i) {
        int rank = spades[i] % 13;
        if (rank == 8) {
            std::cout << "T";
        }
        else if (rank == 9) {
            std::cout << "J";
        } else if (rank == 10) {
            std::cout << "Q";
        } else if (rank == 11) {
            std::cout << "K";
        } else if (rank == 12) {
            std::cout << "A";
        } else {
            string cur = std::to_string(rank + 2);
            std::cout << cur;
        }
    }
    std::cout << "\n";
    
    std::cout << "Hearts: ";
    for (auto i = 0; i < hearts.size(); ++i) {
        int rank = hearts[i] % 13;
        if (rank == 8) {
            std::cout << "T";
        }
        else if (rank == 9) {
            std::cout << "J";
        } else if (rank == 10) {
            std::cout << "Q";
        } else if (rank == 11) {
            std::cout << "K";
        } else if (rank == 12) {
            std::cout << "A";
        } else {
            string cur = std::to_string(rank + 2);
            std::cout << cur;
        }
    }
    std::cout << "\n";
    
    std::cout << "Diamonds: ";
    for (auto i = 0; i < diamonds.size(); ++i) {
        int rank = diamonds[i] % 13;
        if (rank == 8) {
            std::cout << "T";
        }
        else if (rank == 9) {
            std::cout << "J";
        } else if (rank == 10) {
            std::cout << "Q";
        } else if (rank == 11) {
            std::cout << "K";
        } else if (rank == 12) {
            std::cout << "A";
        } else {
            string cur = std::to_string(rank + 2);
            std::cout << cur;
        }
    }
    std::cout << "\n";
        
    std::cout << "Clubs: ";
    for (auto i = 0; i < clubs.size(); ++i) {
        int rank = clubs[i] % 13;
        if (rank == 8) {
            std::cout << "T";
        }
        else if (rank == 9) {
            std::cout << "J";
        } else if (rank == 10) {
            std::cout << "Q";
        } else if (rank == 11) {
            std::cout << "K";
        } else if (rank == 12) {
            std::cout << "A";
        } else {
            string cur = std::to_string(rank + 2);
            std::cout << cur;
        }
    }
    std::cout << "\n";

    std::cout << "HCP: "
            <<HCP;
    std::cout << "\n";
    std::cout << "Shape: "
            <<shape;
    std::cout << "\n" << std::endl;
}

void Hand::player::get_card(int card)
{
    //Update hand information based on the card that is dealt
    cards.push_back(card);

    //Determine the suit
    if (card >= 0 && card <= 12) {
        spades.push_back(card);
        len_S += 1;
    } else if (card >= 13 && card <= 25) {
        hearts.push_back(card);
        len_H += 1;
    } else if (card >= 26 && card <= 38) {
        diamonds.push_back(card);
        len_D += 1;
    } else if (card >= 39 && card <= 51) {
        clubs.push_back(card);
        len_C += 1;
    }

    //Update HCP of the hand according to rank
    int rank = card % 13;
    if (rank == 9) {
        HCP += 1;
    } else if (rank == 10) {
        HCP += 2;
    } else if (rank == 11) {
        HCP += 3;
    } else if (rank == 12) {
        HCP += 4;
    }
}

void Hand::player::finalization()
{
    //Sort the cards by rank
    sort(cards.rbegin(), cards.rend());
    sort(spades.rbegin(), spades.rend());
    sort(hearts.rbegin(), hearts.rend());
    sort(diamonds.rbegin(), diamonds.rend());
    sort(clubs.rbegin(), clubs.rend());

    //Generate the shape string; Append is used to prevent incredible shapes such as 11 1 1 0
    //which a player has a suit with more than one digit in length
    shape.append(std::to_string(int(spades.size())));
    shape.append(" ");
    shape.append(std::to_string(int(hearts.size())));
    shape.append(" ");
    shape.append(std::to_string(int(diamonds.size())));
    shape.append(" ");
    shape.append(std::to_string(int(clubs.size())));
}

void Hand::player::generate_player_log(int orientation, int boardnum)
{
    std::ofstream newFile ("playerhand.txt", std::fstream::app);
    if (orientation == 0) {
        newFile << "#"
            << boardnum
            << "\n";
        newFile << "---------------------------------------------- \n";
        newFile << "North: \n";
    } else if (orientation == 1) {
        newFile << "South: \n"; 
    } else if (orientation == 2) {
        newFile << "East: \n"; 
    } else if (orientation == 3) {
        newFile << "West: \n"; 
    } 
    newFile << "Spades: ";
    for (auto i = 0; i < spades.size(); ++i) {
        int rank = spades[i] % 13;
        if (rank == 8) {
            newFile << "T";
        }
        else if (rank == 9) {
            newFile << "J";
        } else if (rank == 10) {
            newFile << "Q";
        } else if (rank == 11) {
            newFile << "K";
        } else if (rank == 12) {
            newFile << "A";
        } else {
            string cur = std::to_string(rank + 2);
            newFile << cur;
        }
    }
    newFile << "\n";
    
    newFile << "Hearts: ";
    for (auto i = 0; i < hearts.size(); ++i) {
        int rank = hearts[i] % 13;
        if (rank == 8) {
            newFile << "T";
        }
        else if (rank == 9) {
            newFile << "J";
        } else if (rank == 10) {
            newFile << "Q";
        } else if (rank == 11) {
            newFile << "K";
        } else if (rank == 12) {
            newFile << "A";
        } else {
            string cur = std::to_string(rank + 2);
            newFile << cur;
        }
    }
    newFile << "\n";
    
    newFile << "Diamonds: ";
    for (auto i = 0; i < diamonds.size(); ++i) {
        int rank = diamonds[i] % 13;
        if (rank == 8) {
            newFile << "T";
        }
        else if (rank == 9) {
            newFile << "J";
        } else if (rank == 10) {
            newFile << "Q";
        } else if (rank == 11) {
            newFile << "K";
        } else if (rank == 12) {
            newFile << "A";
        } else {
            string cur = std::to_string(rank + 2);
            newFile << cur;
        }
    }
    newFile << "\n";
        
    newFile << "Clubs: ";
    for (auto i = 0; i < clubs.size(); ++i) {
        int rank = clubs[i] % 13;
        if (rank == 8) {
            newFile << "T";
        }
        else if (rank == 9) {
            newFile << "J";
        } else if (rank == 10) {
            newFile << "Q";
        } else if (rank == 11) {
            newFile << "K";
        } else if (rank == 12) {
            newFile << "A";
        } else {
            string cur = std::to_string(rank + 2);
            newFile << cur;
        }
    }
    newFile << "\n";

    newFile << "HCP: "
            <<HCP;
    newFile << "\n";
    newFile << "Shape: "
            <<shape;
    newFile << "\n";
    newFile << "\n";
    newFile.close();
}
