// game.h

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <ctime>


class game {
private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numberOfGuesses;
    void printGameResult();

public:


    game(int maxNum);
    game();
    void play();

protected:

};

game::game(int maxNum) {
    maxNumber = maxNum;
    srand(static_cast<unsigned int>(time(nullptr)));
    randomNumber = rand() % maxNumber + 1;
    numberOfGuesses = 0;
}

game::game() : game(10) {

}

void game::play() {
    while (true) {
        std::cout << "Arvaa luku valilta 1-" << maxNumber << ": ";
        std::cin >> playerGuess;
        numberOfGuesses++;

        if (playerGuess < randomNumber) {
            std::cout << "Liian pieni! Yrita uudelleen." << std::endl;
        } else if (playerGuess > randomNumber) {
            std::cout << "Liian iso! Yrita uudelleen." << std::endl;
        } else {
            printGameResult();
            break;
        }
    }
}

void game::printGameResult() {
    std::cout << "Oikein! Arvasit luvun " << randomNumber << " " << "yrityksella " << numberOfGuesses << "." << std::endl;
}




#endif // GAME_H
