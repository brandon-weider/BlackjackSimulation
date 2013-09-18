//This program will simulate an game of blackjack that is nicknamed
//lackjack because it does not use any of the face cards or aces.

#include <iostream>
using namespace std;

//Variables
int dealerCardOne;
int dealerCardTwo;
int dealerTotal;
int playerCardOne;
int playerCardTwo;
int playerTotal;
int playerCardHit;
int dealerDraw;
double playerBet;
double newBank = 100.00;
char playAgain;
char hitStand;
char win; //might not use
void failurePA ();
void successHS ();
void failureHS ();
void successPA ();
int main ();

//functions used to determine if they used correct letters during the command prompt
void failureHS () {
	cout << "Please enter either an H or a S." << endl;
	cout << "Would you like to hit or stay (H/S)" << endl;
	cin >> hitStand;
	if (hitStand != 'H' && hitStand != 'h' && hitStand != 'S' && hitStand !='s') {
		failureHS ();
	}
	else if (hitStand == 'H' || hitStand == 'h' || hitStand == 'S' || hitStand =='s') {
		successHS (); 
	}
}

void successHS () {
	if (hitStand == 'H' || hitStand == 'h'){
		playerCardHit = 2 + rand() % 9;
		playerTotal += playerCardHit;
		cout << "Your new card total is " << playerTotal << endl;
	}
	if (hitStand == 'S' || hitStand == 's'){
		cout << "Your total will stay at " << playerTotal << endl;
	}
}

void failurePA () {
	cout << "Please enter either a Y or a N." << endl;
	cout << "Would you like to play another hand? (Y/N)";
	cin >> playAgain;
	if (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n') {
		failurePA ();
	}
	else if (playAgain == 'Y' || playAgain == 'y' || playAgain == 'N' || playAgain == 'n'){
		successPA ();
	}
}

void successPA () {
	if (playAgain == 'Y' || playAgain == 'y') {
		main ();
	}
	else if (playAgain == 'N' || playAgain == 'n') {
		cout << "Thank you for playing at Brandons BlackJack Table!" << endl;
		exit(0);
	}
} 

int main () {
	if (newBank <= 0) {
		cout << "Sorry you have no more money left to bet. Thank you for playing." << endl;
		return 0;
	}
	
	cout << "You have a total of " << newBank << " dollars to bet with." << endl;
	cout << "How much would you like to bet? (You cannot bet more than you have)" << endl;
	cin >> playerBet;

	if (playerBet > newBank) {
		cout << "Sorry you do not have that much money to bet with. Please make a smaller bet." << endl;
		cout << "How much would you like to bet? (You cannot bet more than you have)" << endl;
		cin >> playerBet;
	}

	playerCardOne = 2 + rand() % 9;
	playerCardTwo = 2 + rand() % 9;
	playerTotal = playerCardOne + playerCardTwo;
	dealerCardOne = 2 + rand() % 9;
	dealerCardTwo = 2 + rand() % 9;
	dealerTotal = dealerCardOne + dealerCardTwo;

	cout << "Your card values are " << playerCardOne << " and " << playerCardTwo << endl;
	cout << "The dealer\'s first card is " << dealerCardOne << endl;
	cout << "Your card values total up to " << playerTotal << ". Would you like to hit or stand? (H/S)" << endl;
	cin >> hitStand;

	if (hitStand != 'H' && hitStand != 'h' && hitStand != 'S' && hitStand != 's') {
		failureHS ();
	}
	else if (hitStand == 'H' || hitStand == 'h' || hitStand == 'S' || hitStand == 's') {
		successHS ();
	}

	if (playerTotal > 21) {
		newBank -= playerBet;
		cout << "Sorry you bust. You lost the game." << endl;
		cout << "Would you like to play another hand? (Y/N)" << endl;
		cin >> playAgain;
		if (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n') {
			failurePA ();
		}
		else if (playAgain == 'Y' || playAgain == 'y' || playAgain == 'N' || playAgain == 'n') {
			successPA ();
		}
	}
	
	cout << "The dealer\'s second card is " << dealerCardTwo << endl;
	cout << "The dealer has a total of " << dealerTotal << endl;
	
	if (dealerTotal < 17) {
		dealerDraw = 2 + rand() % 9;
		cout << "The dealer drew a " << dealerDraw << endl;
		dealerTotal += dealerDraw;
		if (dealerTotal > 21) {
			newBank += (playerBet * 2);
			cout << "The dealer has busted. You win!" << endl;
			cout << "Would you like to play another hand? (Y/N)" << endl;
			cin >> playAgain;
			if (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n') {
				failurePA ();
			}
			else if (playAgain == 'Y' || playAgain == 'y' || playAgain == 'N' || playAgain == 'n') {
				successPA ();
			}
		}
	}
	else if (playerTotal > dealerTotal) {
		newBank += (playerBet * 2);
		cout << "You win! Would you like to play another hand? (Y/N)" << endl;
		cin >> playAgain;
		if (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n') {
			failurePA ();
		}
		else if (playAgain == 'Y' || playAgain == 'y' || playAgain == 'N' || playAgain == 'n') {
			successPA ();
		}
	}
	else if (playerTotal < dealerTotal) {
		newBank -= playerBet;
		cout << "You lost the game. Would you like to play another hand? (Y/N)" << endl;
		cin >> playAgain;
		if (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n') {
			failurePA ();
		}
		else if (playAgain == 'Y' || playAgain == 'y' || playAgain == 'N' || playAgain == 'n') {
			successPA ();
		}
	}
	
}