/*
Test Case 1:                MENU:
Please select one:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop the same number of chips into each of the 9 slots
4 - Quit the program
5

        INVALID ENTRY
                MENU:

1
        ***Drop Single Chip***

Which slot would you like to drop your chip into?
(Enter a number 0-8)
1
[1 0.5 1 1.5 1 1.5 2 2.5 3 2.5 3 3.5 3]
Winnings: $500.00


Test Case 2:               MENU:
Please select one:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop the same number of chips into each of the 9 slots
4 - Quit the program
2
        ***Drop Multiple Chips***

How many chips would you like to drop?
5

Which slot would you like to drop your chips into?
5
The total winnings for dropping the chip down slot 5 was: $1000.00
The average winnings is: $200.00

Test Case 3:                MENU:
Please select one:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop the same number of chips into each of the 9 slots
4 - Quit the program
3
        ***Drop Chips Into Each Slot***

How many chips would you like to drop in each slot?
4
The total winnings for dropping the chip down slot 0 was: $700.00
The average winnings is: $175.00

The total winnings for dropping the chip down slot 1 was: $1500.00
The average winnings is: $375.00

The total winnings for dropping the chip down slot 2 was: $1000.00
The average winnings is: $250.00

The total winnings for dropping the chip down slot 3 was: $2000.00
The average winnings is: $500.00

The total winnings for dropping the chip down slot 4 was: $1000.00
The average winnings is: $250.00

The total winnings for dropping the chip down slot 5 was: $12500.00
The average winnings is: $3125.00

The total winnings for dropping the chip down slot 6 was: $1100.00
The average winnings is: $275.00

The total winnings for dropping the chip down slot 7 was: $11100.00
The average winnings is: $2775.00

The total winnings for dropping the chip down slot 8 was: $11100.00
The average winnings is: $2775.00
*/

#include <iostream>
#include <math.h>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;
void fixing_menu()
{
	cin.clear();
	cin.ignore(4000, '\n');
}
double SingleChipDrop(int starting_slot, int users_choice, string menu, double &slot_location)
{
	 {
		for (int row = 0; row < 12; row++) {
			if (row == 0) {
				cout << "[" << starting_slot << " ";
			}
			int random_number = rand() % 2;
			if (random_number == 0) {
				if (slot_location == 0) {
					slot_location += .5;
				}
				else {
					slot_location -= .5;
				}
				if (row != 11) {
					cout << slot_location << " ";
				}
				else {
					cout << slot_location;
				}
			}
			else if (random_number == 1) {
				if (slot_location == 8) {
					slot_location -= .5;
				}
				else {
					slot_location += .5;
				}
				if (row != 11) {
					cout << slot_location << " ";
				}
				else {
					cout << slot_location;
				}
			}
		} cout << "]";

	}
	
	slot_location = starting_slot;
	// Lets the chip fall, and follows its course (also keeps the chip within the board)
	
	return slot_location;
}

//This function simulates a chip falling and reports the end location.
double LetTheChipsFall(double slot_location, int random_number) 
{
	for (int row = 0; row < 12; row++) {
		random_number = rand() % 2;
		if (random_number == 0) {
			if (slot_location == 0) {
				slot_location += .5;
			}
			else {
				slot_location -= .5;
			}
		}
		else if (random_number == 1) {
			if (slot_location == 8) {
				slot_location -= .5;
			}
			else {
				slot_location += .5;
			}
		}
	}
	return slot_location;
}

//This function reports how much money is won, depending on the slot location.
double CalculatePrizeMoney(double Winnings, double slot_location)
{
	if (slot_location == 0) {
		Winnings = 100;
	}
	else if (slot_location == 1) {
		Winnings = 500;
	}
	else if (slot_location == 2) {
		Winnings = 1000;
	}
	else if (slot_location == 3) {
		Winnings = 0;
	}
	else if (slot_location == 4) {
		Winnings = 10000;
	}
	else if (slot_location == 5) {
		Winnings = 0;
	}
	else if (slot_location == 6) {
		Winnings = 1000;
	}
	else if (slot_location == 7) {
		Winnings = 500;
	}
	else if (slot_location == 8) {
		Winnings = 100;
	} return Winnings;
}

void Option2(int number_of_chips, int random_number, double &Winnings, double &TotalWinnings, int starting_slot) {	
			for (int l = 0; l < number_of_chips; l++) {
				double slot_location = starting_slot;
					
				// Lets the chips fall, then reports the total and average winnings (also keeps the chip from falling off the board)
				if (starting_slot >= 0 && starting_slot <= 8) {
					slot_location = LetTheChipsFall(slot_location, random_number);
					// Outputs the users winnings
					Winnings = CalculatePrizeMoney(Winnings, slot_location);
				}
				TotalWinnings = TotalWinnings + Winnings;
				if (l == number_of_chips - 1) {
					return;
				}
			}
}
void Option3(int number_of_chips, int random_number, double &Winnings, double &TotalWinnings, int starting_slot) 
{ 
	
		for (int l = 0; l < number_of_chips; l++) {
			double slot_location = starting_slot;

			// Lets the chips fall, then reports the total and average winnings (also keeps the chip from falling off the board)
			if (starting_slot >= 0 && starting_slot <= 8) {
				slot_location = LetTheChipsFall(slot_location, random_number);
				// Outputs the users winnings
				Winnings = CalculatePrizeMoney(Winnings, slot_location);
			}
			TotalWinnings = TotalWinnings + Winnings;
			if (l == number_of_chips - 1) {
				return;
			}
		}
}

int main()
{
	srand(time(0));
	// part: 1
	const int option_one = 1;
	const int option_two = 2;
	const int option_three = 3;
	const int option_four = 4;
	int users_choice;
	string menu = "\t\tMENU:\nPlease select one:\n1 - Drop a single chip into one slot\n2 - Drop multiple chips into one slot\n3 - Drop the same number of chips into each of the 9 slots\n4 - Quit the program";
	string quit = "GOODBYE";
	int starting_slot = 0;
	double Winnings = 0;
	double slot_location = 0;
	int random_number = 0;
	int number_of_chips;
	double TotalWinnings = 0;
	
	while (true) {// This will loop if the user's choice is a 1, 2 or 3 and quit if 4. 

		cout << menu << endl;
		cin >> users_choice;

		if (cin.fail()) {
			cout << endl << "\tINVALID ENTRY" << endl;
			fixing_menu();	
			continue;
		}
		if (users_choice < 1 || users_choice > 4) {
			cout << endl << "\tINVALID ENTRY" << endl;
			continue;
		}
		if (users_choice == option_one) {/* if choice is one only one chip will drop. The winnings will be reported as well
										 the path the chip fell*/
			cout << "\t***Drop Single Chip***\n\nWhich slot would you like to drop your chip into?\n" <<
				"(Enter a number 0-8)" << endl;
			cin >> starting_slot;
			if (cin.fail()) {
				fixing_menu();
				cout << "\tINVALID ENTRY" << endl;
				continue;
			}
			else if (starting_slot >= 0 && starting_slot <= 8){
				slot_location = SingleChipDrop(starting_slot, users_choice, menu, slot_location);
			}
			else {
				cout << "\tINVALID ENTRY" << endl;
				continue;

			}
			// Outputs the users winnings
			Winnings = CalculatePrizeMoney(Winnings, slot_location);
			cout << endl << "Winnings: $" << setprecision(2) << fixed << Winnings << endl << endl;
		}
		if (users_choice == option_two) {/* if option two is chosen the user can drop multiple chips and select the slot
										 to drop the chip. Only the total and average winnings are reported*/
			cout << "\t***Drop Multiple Chips***\n\nHow many chips would you like to drop?" << endl;
			cin >> number_of_chips;
			if (cin.fail()) {
				fixing_menu();
				cout << "\tINVALID ENTRY" << endl;
				continue;
			}
			else if (number_of_chips <= 0) {
				cout << "\tINVALID ENTRY" << endl << endl << menu << endl;
				continue;
			}
			else {
				cout << endl << "Which slot would you like to drop your chips into?" << endl;
				cin >> starting_slot;
				if (starting_slot < 0 || starting_slot > 8) {
					cout << "\tINVALID ENTRY" << endl;
					continue;
				}
				if (cin.fail()) {
					fixing_menu();
					cout << "\tINVALID ENTRY" << endl;
					continue;
				}
				Option2(number_of_chips, random_number, Winnings, TotalWinnings, starting_slot);
				cout << "The total winnings for dropping the chip down slot " << starting_slot << " was: $" << setprecision(2) << fixed << TotalWinnings << endl;
				double averageWinnings = TotalWinnings / number_of_chips;
				cout << "The average winnings is: $" << setprecision(2) << fixed << averageWinnings << endl << endl;
			}
		}
		if (users_choice == option_three) {
			cout << "\t***Drop Chips Into Each Slot***\n\nHow many chips would you like to drop in each slot?" << endl;
			cin >> number_of_chips;

			if (cin.fail()) {
				fixing_menu();
				cout << "\tINVALID ENTRY" << endl;
				continue;
			}
			else if (number_of_chips <= 0) {
				cout << "\tINVALID ENTRY" << endl;
				continue;
			}
			else {
				for (starting_slot = 0; starting_slot <= 8; starting_slot++) {
					TotalWinnings = 0;
					Option3(number_of_chips, random_number, Winnings, TotalWinnings, starting_slot);
					cout << "The total winnings for dropping the chip down slot " << starting_slot << " was: $" << setprecision(2) << fixed << TotalWinnings << endl;
					double averageWinnings = TotalWinnings / number_of_chips;
					cout << "The average winnings is: $" << setprecision(2) << fixed << averageWinnings << endl << endl;
				}
				
			}
		
		}
		if (users_choice == option_four) {
			cout << "GOODBYE" << endl;
			break;
		}
		
		
	} 
		
		system("pause");
		return 0;
}

