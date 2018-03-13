/*
Daniel Moster, Section 5, d.moster@me.com
Description: This program is a Plinko game simulator (using functions), where the player can select numbers to drop virtual chips into 
   virtual slots. The game then calculates the player's winnings ($) based on where the chip(s) land.

This lab was completed using Visual Studio.
Please allow me the use of 2 late days for this lab.

Test Cases:
Test 1:
Input: (2, 90, 5)
Expected output: A value around $200000.00
Result: $111.11 - helped me discover that my ComputeWinnings function was returning the wrong variable value.

Test 2:
Input: (4, asdf)
Expected output: "Invalid selection. Enter 4 to see options."
Result: Infinite loop - led to discovery of extraneous error checking code from previous version of lab still at the bottom of main().

Test 3:
Input: (3, 460)
Expected output: Winnings per slot and per chip in each slot
Result: Passed
*/

#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 12;
const int BOARD_HEIGHT = NUM_ROWS - 1;
const int NUM_SLOTS = 9;
const int BOARD_RIGHT_LIMIT = NUM_SLOTS - 1;
const int NUM_CHIPS_CODE = 1;
const int NUM_SLOT_CODE = 2;
const int MENU_OPTION_CODE = 3;
const int SINGLE_DROP = 1;
const int MULTI_DROP = 2;
const int MULTI_SLOT = 3;
const int MENU = 4;
const int QUIT = 5;

// Compute Winnings
double ComputeWinnings(int slot) {
   const double WINNINGS[] = {100.0, 500.0, 1000.0, 0.0, 10000.0, 0.0, 1000.0, 500.0, 100.0};

   return WINNINGS[slot];
}

// Single Chip
void PrintSingleChipPath(int distanceDropped, double chipLocation) {
   if (distanceDropped < BOARD_HEIGHT) {
      cout << chipLocation << ", ";
   }
   else {
      cout << chipLocation << "]" << endl;
   }

   return;
}

double SingleChip(double chipLocation, double menuSelection = 2) {

   const double MOVEMENT_INCREMENT = 0.5;
   double winnings = 0.0;
   
   for (int howFarDropped = 0; howFarDropped <= BOARD_HEIGHT; ++howFarDropped) {
      if (chipLocation == 0) {
         chipLocation = chipLocation + MOVEMENT_INCREMENT;
      }
      else if (chipLocation == BOARD_RIGHT_LIMIT) {
         chipLocation = chipLocation - MOVEMENT_INCREMENT;
      }
      else if ((rand() % 2) == 0) {
         chipLocation = chipLocation - MOVEMENT_INCREMENT;
      }
      else {
         chipLocation = chipLocation + MOVEMENT_INCREMENT;
      }
      if (menuSelection == 1) {
         PrintSingleChipPath(howFarDropped, chipLocation);
      }
   }

   winnings = ComputeWinnings(chipLocation);    

   return winnings;
}

// Multiple Chips
double MultiChipOneSlot(int numChips, double chipLocation) {
   double winnings = 0.0;
   double totalWinnings = 0.0;

   for (int i = numChips; i > 0; --i) {
      winnings = SingleChip(chipLocation);
      totalWinnings = totalWinnings + winnings;
   }

   return totalWinnings;
}

// Error Checking
bool CheckIfInteger(int num, int numToCheck) {
   bool isValidInput = true;
   const int INVALID_NUM = -1;

   if (cin.fail()) {
      num = INVALID_NUM;
   }

   if ((num <= 0) && (numToCheck == NUM_CHIPS_CODE)) {
      cout << "Invalid number of chips." << endl << endl;
      isValidInput = false;
   }
   else if (((num < 0) || (num > BOARD_RIGHT_LIMIT)) && (numToCheck == NUM_SLOT_CODE)) {
      cout << "Invalid slot." << endl << endl;
      isValidInput = false;
   }
   else if (((num < SINGLE_DROP) || (num > QUIT)) && (numToCheck == MENU_OPTION_CODE)) {
      cout << "Invalid selection. Enter " << MENU << " to see options." << endl << endl;
      isValidInput = false;
   }

   if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }

   return isValidInput;
}

// Getting User Values
int GetNumChips() {
   bool isValidInput = false;
   int numChips = 0;
   while (isValidInput == false) {
      cout << "How many chips do you want to drop (>0)? ";
      cin >> numChips;
      cout << endl << endl;

      isValidInput = CheckIfInteger(numChips, NUM_CHIPS_CODE);
   }

   return numChips;
}

int GetSlotNum() {
   bool isValidInput = false;
   int slotSelection = 0;
   while (isValidInput == false) {
      cout << "Which slot do you want to drop the chip in (0-" << BOARD_RIGHT_LIMIT << ")? ";
      cin >> slotSelection;
      cout << endl;

      isValidInput = CheckIfInteger(slotSelection, NUM_SLOT_CODE);
   }

   return slotSelection;
}

int GetMenuSelection() {
   bool isValidInput = false;
   int menuSelection = 0;
   while (isValidInput == false) {
      cout << "Enter your selection now: ";
      cin >> menuSelection;
      cout << endl;

      isValidInput = CheckIfInteger(menuSelection, MENU_OPTION_CODE);
   }

   return menuSelection;
}


int main() {
   int menuSelection = 0;
   int slotSelection = 0;

   double chipLocation = 0.0;
   int howFarDropped = 0;
   const int SEED = 42;
   const int SET_PRECISION_MONEY = 2;
   const int SET_PRECISION_SLOTS = 1;
   double winnings = 0.0;
   double totalWinnings = 0.0;
   int numChips = 0;
   double averageWinnings = 0.0;
   int i = 0;

   srand(SEED);

   cout << "Welcome to the Plinko simulator! Enter " << MENU << " to see options." << endl << endl;

   menuSelection = GetMenuSelection();


   while (menuSelection != QUIT) {
      while ((menuSelection >= SINGLE_DROP) || (menuSelection <= QUIT)) {

         // Single Chip
         if (menuSelection == SINGLE_DROP) {
            cout << "*** Drop a single chip ***" << endl << endl;
            
            slotSelection = GetSlotNum();

            cout << "*** Dropping chip into slot " << slotSelection << " ***" << endl;
            cout << "Path: [";

            chipLocation = slotSelection;
            cout << fixed << setprecision(SET_PRECISION_SLOTS) << chipLocation << ", ";
            
            winnings = SingleChip(chipLocation, menuSelection);
            cout << fixed << setprecision(SET_PRECISION_MONEY) << "Winnings: $" << winnings << endl << endl;
            break;
         }

         // Multiple Chips
         if (menuSelection == MULTI_DROP) {
            cout << "*** Drop multiple chips ***" << endl << endl;
            
            numChips = GetNumChips();

            slotSelection = GetSlotNum();
            
            totalWinnings = MultiChipOneSlot(numChips, slotSelection);
            cout << fixed << setprecision(SET_PRECISION_MONEY) << "Total winnings on " << numChips << " chips: $" <<
               totalWinnings << endl << endl;
            averageWinnings = totalWinnings / numChips;
            cout << "Average winnings per chip: $" << averageWinnings << endl << endl;
            break;
         }

         // Multiple Chips in Each Slot
         if (menuSelection == MULTI_SLOT) {
            cout << "*** Sequentially drop multiple chips ***" << endl << endl;

            numChips = GetNumChips();

            for (int i = 0; i <= BOARD_RIGHT_LIMIT; ++i) {
               totalWinnings = MultiChipOneSlot(numChips, i);
               cout << fixed << setprecision(SET_PRECISION_MONEY) << "Total winnings on slot " << i << " chips: " <<
                  totalWinnings << endl;
               averageWinnings = totalWinnings / numChips;
               cout << "Average winnings per chip: " << averageWinnings << endl << endl;
            }
            break;
         }
         
         // Options
         if (menuSelection == MENU) {
            cout << "Menu: Please select one of the following options:" << endl << endl;
            cout << SINGLE_DROP << " - Drop a single chip into one slot" << endl;
            cout << MULTI_DROP << " - Drop multiple chips into one slot" << endl;
            cout << MULTI_SLOT << " - Drop multiple chips into each slot" << endl;
            cout << MENU << " - Show the options menu" << endl;
            cout << QUIT << " - Quit the program" << endl;
            cout << endl << endl;
            break;
         }

         // Quit
         if (menuSelection == QUIT) {
            break;
         }
      }

      menuSelection = GetMenuSelection();
   }

   cout << "Goodbye!" << endl;


   system("pause");
   return 0;
}