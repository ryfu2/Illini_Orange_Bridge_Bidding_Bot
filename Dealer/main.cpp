#include "hand.h"
#include <fstream>  
int main() {
    for (int i = 0; i < 999; i++) {
        Hand newhand = Hand(i);
        newhand.print_wholehand();
        // newhand->North.generate_player_log();
        newhand.generate_hand_file(i + 1);
    }
    return 0;
}