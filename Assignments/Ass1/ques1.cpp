#include <iostream>
#include <exception>
#include <typeinfo>
using namespace std;

class GameEntry { 
    public:
    	GameEntry(const string &n = "", int s = 0); 
    	string getName() const;						
    	int getScore() const;						
    private:
    	string name; 
    	int score;	 
};

GameEntry::GameEntry(const string &n, int s) : name(n), score(s) {
}
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

class Scores { 
    public:
    	Scores(int maxEnt = 10);				  
    	~Scores();								  
    	void add(const GameEntry &e);			  
    	GameEntry remove(int i) ; 
    	void printAllScores();
    private:
    	int maxEntries;
    	int numEntries;
    	GameEntry *entries;
};

Scores::Scores(int maxEnt) {
	maxEntries = maxEnt;
	entries = new GameEntry[maxEntries];
	numEntries = 0;
}

Scores::~Scores() { 
	delete[] entries;
}

void Scores::add(const GameEntry &e) {
	int scoreToAdd = e.getScore();
	if(maxEntries == numEntries)
		entries[maxEntries-1] = e; // array is full, can't add more elements
	else {
		numEntries++; // increasing the number of entries
		entries[numEntries-1] = e; // adding the new entry
	}
	return;
}

GameEntry Scores::remove(int i) {
	if ((i < 0) || (i >= numEntries))
		throw("IndexOutOfBounds - Invalid index");
	
	GameEntry removeEntry = entries[i];
	GameEntry lastEntry = entries[numEntries-1];

	entries[numEntries-1] = entries[i];
	entries[i] = lastEntry;

	numEntries--;
	return removeEntry;
}

void Scores::printAllScores() {
	for (int i = 0; i < numEntries; i++) {
		cout << entries[i].getName() << " : " << entries[i].getScore() << "\n";
	}
}

void showOptions() {
	cout << "1: Add Player\n"
		 << "2: Remove Player By Index\n"
		 << "3: Print Scores\n"
		 << "4: Exit\n";
}

int main() {
	Scores scoresObj;
	int option;
	string playerName;
	int score;

	while (true) {
		showOptions();
		cin >> option;
		switch (option) {
		case 1:
			cout << "Enter Player Name and Score\n";
			cin >> playerName >> score;
			scoresObj.add(GameEntry(playerName, score));
			break;
		case 2:
			int index;
			cout << "Enter the index\n";
			cin >> index;
			scoresObj.remove(index);
			break;
		case 3:
			scoresObj.printAllScores();
			break;
		case 4:
			return EXIT_SUCCESS;
		default:
		    cout<<"wrong input, Try again"<< endl;
		    continue;
		}
	}
}