#include <iostream> 
#include <ctime>
#include <random> 

using namespace std; 

char board[9] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };
void show_board(); 

// Player's input 
void get_x_player_choice(); 
void get_o_player_choice();

// computer as artificial player 
void get_computer_choice(); 
int count_board(char symbol); 

//check win/lose condition
char check_winner();
void computer_vs_player(); 
void player_vs_player(); 

int main()
{
	computer_vs_player();
	/*get_x_player_choice();
	get_o_player_choice();

	get_computer_choice();
	char check_winner();

	int count_board(char symbol);
	show_board(); */
	return 0;
}

void computer_vs_player()
{
	string player_name;
	cout << "Enter Your Name: ";
	cin >> player_name;

	while (true) {
		system("cls");		//clear screen for a new game  
		show_board();		//display fresh game board
		if(count_board('X') == count_board('O')) //If there's a position is unmarked, X & O is equal. player always use 'X' to mark board. 
		{
			cout << player_name << "'s Turn." << endl; 
				get_x_player_choice(); 
		}
		else
		{
			get_computer_choice();
		}
		char winner = check_winner(); 
		if (winner == 'X')
		{
			system("cls");
			show_board();
			cout << player_name << " Won The Game." << endl; 
			break; 
		}
		else if (winner == 'O')
		{
			system("cls");
			show_board();
			cout << "Computer Won The Game." << endl;
			break;
		}
		else if (winner == 'D')
		{
			cout << "The Game is a Draw." << endl;
			break;
		}
		if (winner == 'X')
		{
			system("cls");
			show_board();
			cout << player_name << " Won The Game." << endl;
			break;
		}
		else if (winner == 'O')
		{
			system("cls");
			show_board();
			cout << "Computer Won The Game." << endl;
			break;
		}
		else if (winner == 'D')
		{
			cout << "The Game is a Draw." << endl;
			break;
		}
	}
}

void get_computer_choice()
{
	srand(time(0)); // this ensures 100% random number
	int choice;
	// check for space availability. If a spot alredy marked, comp must choose another position. 
	do {
		choice = rand() % 10; //this will ensure the number returned is only between 0 - 9
	} while (board[choice] != ' '); //this sets the loop to run if the position is not equal to an empty space, vice versa
		board[choice] = 'O'; //sets default value 'O' as comp input
}



void get_x_player_choice()
{
	while (true) {
		cout << "Select Your Position (1 - 9): ";
		int choice;
		cin >> choice;
		choice--; //
		if (choice < 0 || choice > 8) { //this warns player their choice is not within bounds. 
			cout << "Invalid input! Please Choose From (1 - 9)." << endl; 
		}
		else if (board[choice] != ' ') { //this ask player to pick another unoccupied box.
			cout << "Invalid input! Please Select An Empty Position." << endl; 
		}
		else { //this registers the player's legitimate move.
			board[choice] = 'X';
			break;
		}
	}
}

void get_o_player_choice()
{
	while (true) {
		cout << "Select Your Position (1 - 9): ";
		int choice;
		cin >> choice;
		choice--; //
		if (choice < 0 || choice > 8) { //this warns player their choice is not within bounds. 
			cout << "Invalid input! Please Choose From (1 - 9)." << endl;
		}
		else if (board[choice] != ' ') { //this ask player to pick another unoccupied box.
			cout << "Invalid input! Please Select An Empty Position." << endl;
		}
		else { //this registers the player's legitimate move.
			board[choice] = 'O';
			break;
		}
	}
}

//Method counts the symbol(input) passed into the board and controls how amny times it appears on the board. 
int count_board(char symbol) { //this accepts a character symbol 
	int total = 0; 
	for (int i= 0; i<9; i++)
	{
		if (board[i] == symbol)
			total += 1; 
	}
	return total; 
}

char check_winner() 
{
	//Method checks row+column-wise to see if any R/C is filled with a same character
	//then it marks the game as a draw when board runs out of space before a win condition is found 
	// checking winner in horizontal/row
	if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
		return board[0];
	if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
		return board[3];
	if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
		return board[6];

	// checking winner in vertical/column
	if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
		return board[0]; 
	if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
		return board[1];
	if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
		return board[2];

	//checking winner diagonally
	if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
		return board[0];
	if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
		return board[2];

	//check if game sld continue or ends
	if (count_board('X') + count_board('O') < 9) // Game carries on 
		return 'C';
	else // Ends in a Draw 
		return 'D';
}


void show_board()
{
	cout << "   " << "    |   " << "    |   " << endl; 
	cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << endl; 
	cout << "   " << "    |   " << "    |   " << endl;

	cout << "------------------------" << endl; 
	cout << "   " << "    |   " << "    |   " << endl;
	cout << "   " << "    |   " << "    |   " << endl;

	cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << endl;
	cout << "------------------------" << endl; 
	cout << "   " << "    |   " << "    |   " << endl;
	cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << endl;
	cout << "   " << "    |   " << "    |   " << endl;

}