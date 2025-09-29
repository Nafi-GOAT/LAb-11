#include <iostream>
#include <string>
using namespace std;

// Struct to represent a Player in a game
struct Player {
    string username;   // Player's username
    int age;           // Player's age
    int numScores;     // How many scores they want to store
    int* scores;       // Dynamic array to hold scores

    // Constructor
    Player() {
        numScores = 0;
        scores = nullptr;
    }

    // Destructor (important to avoid memory leaks)
    ~Player() {
        delete[] scores;
        scores = nullptr; // Prevent dangling pointer
    }
};

// Function to input Player data
void inputPlayer(Player* p) {
    cout << "Enter player's username: ";
    getline(cin, p->username);

    cout << "Enter player's age: ";
    cin >> p->age;

    cout << "How many scores do you want to enter for " << p->username << "? ";
    cin >> p->numScores;
    cin.ignore(); // Clear newline character

    // Allocate memory for scores
    p->scores = new int[p->numScores];

    // Input scores
    for (int i = 0; i < p->numScores; i++) {
        cout << "  > Enter score #" << i + 1 << ": ";
        cin >> p->scores[i];
    }
    cin.ignore(); // Clear buffer for next getline
}

// Function to display Player data
void displayPlayer(Player* p) {
    cout << "\n--- Player Info ---\n";
    cout << "Username: " << p->username << endl;
    cout << "Age: " << p->age << endl;
    cout << "Scores: ";
    for (int i = 0; i < p->numScores; i++) {
        cout << p->scores[i];
        if (i < p->numScores - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    int numPlayers;

    cout << "How many players do you want to enter? ";
    cin >> numPlayers;
    cin.ignore(); // Clear newline

    // Create dynamic array of Players
    Player* players = new Player[numPlayers];

    // Input player data
    for (int i = 0; i < numPlayers; i++) {
        cout << "\nEntering data for Player #" << i + 1 << ":\n";
        inputPlayer(&players[i]);
    }

    // Display all players
    cout << "\n========== Displaying All Players ==========\n";
    for (int i = 0; i < numPlayers; i++) {
        displayPlayer(&players[i]);
    }

    // Free memory
    delete[] players;

    return 0;
}


