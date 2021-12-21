#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string cardNames[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	return rand()%13+1;
}

int calScore(int x,int y,int z){
	int score;
	for ( int i = 0 ; i < 3 ; i++){
		cardNames[i] = cardScores[i];
		score += cardScores[i];
	}
}

int findYugiAction(int s){	
	if(s == 9) return 2; 
	else if(s < 6) return 1;
	else{
		int x = rand()%69;
		if ( x < 69 ) return 1;
		else return 2;
	}
}

void checkWinner(int p, int y){
	if ( p != y ){
		if ( p > y ){
		cout << "\n---------------------------------\n";
		cout <<   "|                               |"; 
		cout <<   "|         Player wins!!!        |"; 
		cout <<   "|                               |"; 
		cout << "\n---------------------------------\n";
		}
		if ( y > p ){
		cout << "\n---------------------------------\n";
		cout <<   "|                               |"; 
		cout <<   "|          Yugi wins!!!         |"; 
		cout <<   "|                               |"; 
		cout << "\n---------------------------------\n";
		}
	}else{
		cout << "\n---------------------------------\n";
		cout <<   "|                               |"; 
		cout <<   "|             Draw!!!           |"; 
		cout <<   "|                               |"; 
		cout << "\n---------------------------------\n";
	}
}
int main(){	
	srand(time(0));
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3]; 
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while( playerAction != 1 && playerAction != 2 );  
	if(playerAction == 1){
	drawCard();
	}
	cout << "------------ Turn end -------------------\n\n";
	
	checkWinner(playerScore,yugiScore);
	
}
