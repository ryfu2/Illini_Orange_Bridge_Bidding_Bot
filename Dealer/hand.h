#include <iostream>
#include <vector>
#include <string>
using std::string;

using std::vector;

class Hand {
    public:
        Hand(int seed);
        void print_wholehand();
        void generate_hand_file(int boardnum);
        class player {
            public:
                player();
                player(int S_len, int H_len, int D_len, int C_len, int HCP_, int LTC_);
                void print_hand();
                void get_card(int card);
                int len_S;
                int len_H;
                int len_D;
                int len_C;
                string shape;
                int HCP;
                int LTC;
                vector<int> cards;
                vector<int> spades;
                vector<int> hearts;
                vector<int> diamonds;
                vector<int> clubs;
                void finalization(); //sort the cards in ranks and generate shape; helper function
                void generate_player_log(int orientation, int boardnum);
        };
        player North;
        player South;
        player East;
        player West;
};