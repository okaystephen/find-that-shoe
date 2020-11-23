
/*
 
 SALAMANTE, STEPHEN E.
 11831014
 CCPROG1 — X22
 DEC. 3, 2018
 
 Filename: machine_project.c
 
 This program is a game called "Find that shoe!"
 Where the player has to find the missing shoe in the house.
 
 
 -- --
 
 
 Arriving in a location options:
 (A) Look for the shoe
 (B) Go to other locations (only the ones that are adjacent to the current location)
 (C) Put toy in bin (only if in Bedroom #2, Garage, or Covered Terrace)
 (D) Quit finding the shoe
 
 [ Options appear if getRandomNum() == 1 ]
 (1) Pet your dog (if dog shows up)
 (2) Pick up toy (if there is a toy)
 
 
 -- --
 
 
 ROOM VALUES
 
 [FIRST FLOOR]                                      [ADJACENT ROOMS]
 1 — Garage                                         3
 2 — Covered Entry                                  3, 9
 3 — Foyer (+ stairs)                               19, 1, 5, 2
 4 — Powder Room                                    5
 5 — Living Room                                    8, 6, 7, 4, 3
 6 — Dining Room                                    8, 7, 5
 7 — Kitchen                                        6, 5
 8 — Covered Terrace                                9, 6, 5
 9 — Garden (thru covered entry or terrace)         2, 8
 
 [SECOND FLOOR]
 10 — Master Bedroom                                19, 11
 11 — Walk-in Closet (M.B.)                         12, 10
 12 — Bathroom (M.B.)                               11
 13 — Your Bedroom (#2)                             19, 14
 14 — Walk-in Closet (Y.B.)                         13
 15 — Guest Suite / Den                             19
 16 — Common Bathroom (#2)                          19
 17 — Laundry Room                                  19
 18 — Linen Closet                                  19
 19 — Hallway (+ stairs)                            17, 18, 15, 16, 13, 10, 3
 
 * Toy Bins = 1 (Garage), 8 (Covered Terrace), 13 (Your Bedroom)
 
 -- --
 
 
 TIME ESSENTIALS
 
 [Action]                                       [Result]
 1 — Petting dog                                -2 each heart
 2 — Collecting toys (and returning to bin)     -2 each heart
 3 — Stepping on toy                            +3
 4 — Looking for shoe (five chances)            +2 each chance
 
 
 -- --
 
 
 CURRENT USER-DEFINED FUNCTIONS!
 
 Number     Data Type + Function Name       Description
 1          void initRandom                 Initial function for the random number generator to work
 2          int getRandomNum                Random Number Generator
 3          void print_endscreen            Game summary when shoe's found
 4          void print_quitscreen           Game summary when player has quitted
 5          int print_Location              Location Names
 6          int get_LocationValue           Room Values
 7          int print_nextLocation          For the movement of player
 8          int get_dogGender               Dog Gender Assigner (with name)
 9          int print_dogAppear             Dog appears or not in the room
 10         int print_toy                   Check if there's a toy in room
 11         int get_toybin                  Check if there's a toy bin in the room
 12         int get_chooseAction            Action Picker
 13         int print_intro                 Instructions + Intro prompt
 
 -- --
 
 NOTES:
 
 1. Added a "hallway" at the second floor
 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SHOELOOK_LIMIT 5 // set 'look for shoe' limit to 5

// global variables

int addtime = 0, addheart = 0, followingLocation, nextLocation, dogGender, get_shoeRandomGenerator;
int chewtoy, ropetoy, balltoy, chewtoy2, ropetoy2, balltoy2, addhand;

// Initial function for the random number generator to work
void initRandom()
{
    time_t random_seed;
    random_seed = time(NULL);
    srand(random_seed);
}


// Random Number Generator
int getRandomNum (int low, int high)
{
    
    int randomValue;
    randomValue = low + rand() % (high - low + 1);
    return randomValue;
    
}


// Print End Screen (when shoe is found)
void print_endscreen (time_t begin)
{
    
    time_t end;
    
    end = time(NULL);
    
    printf("You found the shoe!\n\n");
    printf("--------------------------------------------------------------------------------\n\n");
    printf("\tYOU WON!\n\n");
    printf("\tGAME SUMMARY:\n\n");
    printf("\tGame Duration: %.2f seconds\n", difftime(end, begin));
    printf("\tAddition to time: +%d seconds\n", addtime);
    printf("\tNumber of collected hearts: %d = -%d seconds\n", addheart, (addheart * 2));
    printf("\tTotal Game Duration: %.2f seconds \n\n", difftime(end, begin) + addtime - (addheart * 2));
    printf("--------------------------------------------------------------------------------\n\n");
    
    exit(0);
    
}


// Print Quit Screen
void print_quitscreen (time_t begin)
{
    
    time_t end;
    
    end = time(NULL);
    
    printf("\nYou've quitted, see you next time!\n\n");
    printf("--------------------------------------------------------------------------------\n\n");
    printf("\tYOU LOST!\n\n");
    printf("\tGAME SUMMARY:\n\n");
    printf("\tGame Duration: %.2f seconds\n", difftime(end, begin));
    printf("\tAddition to time: +%d seconds\n", addtime);
    printf("\tNumber of collected hearts: %d = -%d seconds\n", addheart, (addheart * 2));
    printf("\tTotal Game Duration: %.2f seconds \n\n", difftime(end, begin) + addtime - (addheart * 2));
    printf("--------------------------------------------------------------------------------\n\n");
    
    exit(0);
    
}


// Location names
int print_Location(int location)
{
    
    switch (location)
    {
            
            // FIRST FLOOR ROOMS
            
        case 1:
            printf("FIRST FLOOR - You're in the garage!\n");
            return 1; break;
            
        case 2:
            printf("FIRST FLOOR - You're at the covered entry!\n");
            return 2; break;
            
        case 3:
            printf("FIRST FLOOR - You're at the foyer!\n");
            return 3; break;
            
        case 4:
            printf("FIRST FLOOR - You're in the powder room!\n");
            return 4; break;
            
        case 5:
            printf("FIRST FLOOR - You're in the living room!\n");
            return 5; break;
            
        case 6:
            printf("FIRST FLOOR - You're in the dining room!\n");
            return 6; break;
            
        case 7:
            printf("FIRST FLOOR - You're in the kitchen!\n");
            return 7; break;
            
        case 8:
            printf("FIRST FLOOR - You're at the covered terrace!\n");
            return 8; break;
            
        case 9:
            printf("FIRST FLOOR - You're at the garden!\n");
            return 9; break;
            
            
            // SECOND FLOOR ROOMS
            
        case 10:
            printf("SECOND FLOOR - You're in the master bedroom!\n");
            return 10; break;
            
        case 11:
            printf("SECOND FLOOR - You're in the walk-in closet of the master bedroom!\n");
            return 11; break;
            
        case 12:
            printf("SECOND FLOOR - You're in the bathroom of the master bedroom!\n");
            return 12; break;
            
        case 13:
            printf("SECOND FLOOR - You're in your bedroom!\n");
            return 13; break;
            
        case 14:
            printf("SECOND FLOOR - You're in the walk-in closet of your bedroom!\n");
            return 14; break;
            
        case 15:
            printf("SECOND FLOOR - You're in the guest suite / den!\n");
            return 15; break;
            
        case 16:
            printf("SECOND FLOOR - You're in the common bathroom (#2)!\n");
            return 16; break;
            
        case 17:
            printf("SECOND FLOOR - You're in the laundry room!\n");
            return 17; break;
            
        case 18:
            printf("SECOND FLOOR - You're in the linen closet!\n");
            return 18; break;
            
        case 19:
            printf("SECOND FLOOR - You're in the hallway!\n");
            return 19; break;
            
        default: printf("Sorry, wrong input. Try again!\n");
            
    }
    
    return 0;
    
}


// Room Values
int get_LocationValue(int location)
{
    
    switch (location)
    {
            
            // FIRST FLOOR ROOMS
            
        case 1: return 1; break;
        case 2: return 2; break;
        case 3: return 3; break;
        case 4: return 4; break;
        case 5: return 5; break;
        case 6: return 6; break;
        case 7: return 7; break;
        case 8: return 8; break;
        case 9: return 9; break;
            
            // SECOND FLOOR ROOMS
            
        case 10: return 10; break;
        case 11: return 11; break;
        case 12: return 12; break;
        case 13: return 13; break;
        case 14: return 14; break;
        case 15: return 15; break;
        case 16: return 16; break;
        case 17: return 17; break;
        case 18: return 18; break;
        case 19: return 19; break;
            
    }
    
    return 0;
    
}


// For movement of player
int print_nextLocation(int next_Location)
{
    
    char nextLocation;
    
    printf("Where's your next move?\n\n");
    
    // FIRST FLOOR
    
    if (next_Location == 1)
    {
    next_Location1_goto:
        printf("    (A) Foyer \n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 3;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location1_goto;
            
        }
        
    }
    
    else if (next_Location == 2)
    {
    next_Location2_goto:
        printf("    (A) Foyer\n");
        printf("    (B) Garden\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 3;
        
        else if (nextLocation == 'B' || nextLocation == 'b')
            return 9;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location2_goto;
            
        }
        
    }
    
    else if (next_Location == 3) // stairs = hallway (19)
    {
    next_Location3_goto:
        printf("    (A) Upstairs\n");
        printf("    (B) Garage\n");
        printf("    (C) Living Room\n");
        printf("    (D) Covered Entry\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 19;
        
        else if (nextLocation == 'B' || nextLocation == 'b')
            return 1;
        
        else if (nextLocation == 'C' || nextLocation == 'c')
            return 5;
        
        else if (nextLocation == 'D' || nextLocation == 'd')
            return 2;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location3_goto;
            
        }
        
    }
    
    else if (next_Location == 4)
    {
    next_Location4_goto:
        printf("    (A) Living Room\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 5;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location4_goto;
            
        }
        
    }
    
    else if (next_Location == 5)
    {
    next_Location5_goto:
        printf("    (A) Covered Terrace\n");
        printf("    (B) Dining Room\n");
        printf("    (C) Kitchen\n");
        printf("    (D) Powder Room\n");
        printf("    (E) Foyer\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 8;
        
        else if (nextLocation == 'B' || nextLocation == 'b')
            return 6;
        
        else if (nextLocation == 'C' || nextLocation == 'c')
            return 7;
        
        else if (nextLocation == 'D' || nextLocation == 'd')
            return 4;
        
        else if (nextLocation == 'E' || nextLocation == 'e')
            return 3;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location5_goto;
            
        }
        
    }
    
    else if (next_Location == 6)
    {
    next_Location6_goto:
        printf("    (A) Covered Terrace\n");
        printf("    (B) Kitchen\n");
        printf("    (C) Living Room\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 8;
        
        else if (nextLocation == 'B' || nextLocation == 'b')
            return 7;
        
        else if (nextLocation == 'C' || nextLocation == 'c')
            return 5;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location6_goto;
            
        }
        
    }
    
    else if (next_Location == 7)
    {
    next_Location7_goto:
        printf("    (A) Dining Room\n");
        printf("    (B) Living Room\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 6;
        
        else if (nextLocation == 'B' || nextLocation == 'b')
            return 5;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location7_goto;
            
        }
        
    }
    
    else if (next_Location == 8)
    {
    next_Location8_goto:
        printf("    (A) Garden\n");
        printf("    (B) Dining Room\n");
        printf("    (C) Living Room\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 9;
        
        else if (nextLocation == 'B' || nextLocation == 'b')
            return 6;
        
        else if (nextLocation == 'C' || nextLocation == 'c')
            return 5;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location8_goto;
            
        }
        
    }
    
    else if (next_Location == 9)
    {
    next_Location9_goto:
        printf("    (A) Covered Entry\n");
        printf("    (B) Covered Terrace\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 2;
        
        else if (nextLocation == 'B' || nextLocation == 'b')
            return 8;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location9_goto;
            
        }
        
    }
    
    // SECOND FLOOR
    
    else if (next_Location == 10)
    {
    next_Location10_goto:
        printf("    (A) Hallway\n");
        printf("    (B) Walk-in Closet [Master Bedroom]\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 19;
        
        else if (nextLocation == 'B' || nextLocation == 'b')
            return 11;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location10_goto;
            
        }
        
    }
    
    else if (next_Location == 11)
    {
    next_Location11_goto:
        printf("    (A) Bathroom [Master Bedroom]\n");
        printf("    (B) Master Bedroom\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 12;
        
        else if (nextLocation == 'B' || nextLocation == 'b')
            return 10;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location11_goto;
            
        }
        
        
    }
    
    else if (next_Location == 12)
    {
    next_Location12_goto:
        printf("    (A) Walk-in Closet [Master Bedroom]\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 11;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location12_goto;
            
        }
        
    }
    
    else if (next_Location == 13)
    {
    next_Location13_goto:
        printf("    (A) Hallway\n");
        printf("    (B) Walk-in Closet [Your Bedroom]\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 19;
        
        else if (nextLocation == 'B' || nextLocation == 'b')
            return 14;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location13_goto;
            
        }
        
    }
    
    else if (next_Location == 14)
    {
    next_Location14_goto:
        printf("    (A) Your Bedroom\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 13;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location14_goto;
            
        }
        
    }
    
    else if (next_Location == 15)
    {
    next_Location15_goto:
        printf("    (A) Hallway \n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 19;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location15_goto;
            
        }
        
    }
    
    else if (next_Location == 16)
    {
    next_Location16_goto:
        printf("    (A) Hallway \n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 19;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location16_goto;
            
        }
        
    }
    
    else if (next_Location == 17)
    {
    next_Location17_goto:
        printf("    (A) Hallway \n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 19;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location17_goto;
            
        }
        
    }
    
    else if (next_Location == 18)
    {
        
    next_Location18_goto:
        
        printf("    (A) Hallway \n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 19;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location18_goto;
            
        }
        
    }
    
    else if (next_Location == 19)
    {
        
    next_Location19_goto:
        
        printf("    (A) Laundry Room\n");
        printf("    (B) Linen Closet\n");
        printf("    (C) Guest Suite/Den\n");
        printf("    (D) Bathroom #2\n");
        printf("    (E) Your Bedroom\n");
        printf("    (F) Master Bedroom\n");
        printf("    (G) Downstairs\n\n");
        printf("Enter choice: ");
        scanf(" %c", &nextLocation);
        
        if (nextLocation == 'A' || nextLocation == 'a')
            return 17;
        
        else if (nextLocation == 'B' || nextLocation == 'b')
            return 18;
        
        else if (nextLocation == 'C' || nextLocation == 'c')
            return 15;
        
        else if (nextLocation == 'D' || nextLocation == 'd')
            return 16;
        
        else if (nextLocation == 'E' || nextLocation == 'e')
            return 13;
        
        else if (nextLocation == 'F' || nextLocation == 'f')
            return 10;
        
        else if (nextLocation == 'G' || nextLocation == 'g')
            return 3;
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto next_Location19_goto;
            
        }
        
    }
    
    else
    {
        
        printf("\nSorry, wrong input. Try again!\n\n");
        print_nextLocation(next_Location);
        return 0;
        
    }
    
    return 0;
    
}


// Dog Gender
int get_dogGender(int dogGender)
{
    
    switch (dogGender)
    {
            
        case 0:
            printf("Bailey"); // male dog
            return 0; break;
            
        case 1:
            printf("Kahlua"); // female dog
            return 1; break;
            
    }
    
    return 0;
}


// A Wild Dog Appears!
int print_dogAppear()
{
    
    int dogRandom = getRandomNum (0,2);
    char dogDecision;
    
    if (dogRandom == 0 || dogRandom == 1)
    {
        
    dog_goto:
        
        printf("DOG CHECK: ");
        
        get_dogGender(dogGender); printf(" is here!, would you want to pet? (Y/N): ");
        scanf(" %c", &dogDecision);
        
        if (dogDecision == 'y' || dogDecision == 'Y')
        {
            
            printf("\nYay! For the action, you get a heart!\n\n");
            addheart++;
            
        }
        
        else if (dogDecision == 'n' || dogDecision == 'N')
        {
            
            printf("\nOkay, moving on.\n\n");
            
        }
        
        else
        {
            
            printf("\nSorry, wrong input. Try again!\n\n");
            goto dog_goto;
            
        }
        
    }
    
    else if (dogRandom == 2)
    {
        
        printf("DOG CHECK: ");
        
        get_dogGender(dogGender); printf(" is not here!\n\n");
        
    }
    
    return 0;
    
}


// A Toy Appears!
int print_toy()
{
    
    char picktoy_decision;
    
    printf("TOY CHECK: ");
    
    if ((addhand == 2 && ropetoy == followingLocation) || (addhand == 2 && chewtoy == followingLocation) || (addhand == 2 && balltoy == followingLocation) || (addhand == 2 && ropetoy2 == followingLocation) || (addhand == 2 && chewtoy2 == followingLocation) || (addhand == 2 && balltoy2 == followingLocation))
    {
        
        printf("Oh no! You've stepped on a toy! Adding 3 seconds to your time.\n\n");
        addtime += 3;
        
    }
    
    else if (chewtoy == followingLocation)
    {
        
        printf("The chew toy is on the floor! ");
        
    toy1_goto:
        
        printf("Would you like to pick up the chew toy? (Y/N): ");
        scanf(" %c", &picktoy_decision);
        
        if (picktoy_decision == 'Y' || picktoy_decision == 'y')
        {
            
            addhand++;
            printf("\nYou've picked up the chew toy. You're currently holding %d toy/s!\n\n", addhand);
            chewtoy = 0;
            
        }
        
        else if (picktoy_decision == 'N' || picktoy_decision == 'n')
        {
            
            printf("\nOkay, but be careful! You might step on this toy later on.\n\n");
            
        }
        
        else
        {
            
            printf("\nWrong input, try again.\n\n");
            goto toy1_goto;
            
        }
        
    }
    
    else if (chewtoy2 == followingLocation)
    {
        
        printf("The chew toy is on the floor! ");
        
    toy2_goto:
        
        printf("Would you like to pick up the chew toy? (Y/N): ");
        scanf(" %c", &picktoy_decision);
        
        if (picktoy_decision == 'Y' || picktoy_decision == 'y')
        {
            
            addhand++;
            printf("\nYou've picked up the chew toy. You're currently holding %d toy/s!\n\n", addhand);
            chewtoy2 = 0;
            
        }
        
        else if (picktoy_decision == 'N' || picktoy_decision == 'n')
        {
            
            printf("\nOkay, but be careful! You might step on this toy later on.\n\n");
            
        }
        
        else
        {
            
            printf("\nWrong input, try again.\n\n");
            goto toy2_goto;
            
        }
        
    }
    
    else if (ropetoy == followingLocation)
    {
        
        printf("The rope toy is on the floor! ");
        
    toy3_goto:
        
        printf("Would you like to pick up the rope toy? (Y/N): ");
        scanf(" %c", &picktoy_decision);
        
        if (picktoy_decision == 'Y' || picktoy_decision == 'y')
        {
            
            addhand++;
            printf("\nYou've picked up the rope toy. You're currently holding %d toy/s!\n\n", addhand);
            ropetoy = 0;
            
        }
        
        else if (picktoy_decision == 'N' || picktoy_decision == 'n')
        {
            
            printf("\nOkay, but be careful! You might step on this toy later on.\n\n");
            
        }
        
        else
        {
            
            printf("\nWrong input, try again.\n\n");
            goto toy3_goto;
            
        }
        
    }
    
    else if (ropetoy2 == followingLocation)
    {
        printf("The rope toy is on the floor! ");
        
    toy4_goto:
        
        printf("Would you like to pick up the rope toy? (Y/N): ");
        scanf(" %c", &picktoy_decision);
        
        if (picktoy_decision == 'Y' || picktoy_decision == 'y')
        {
            
            addhand++;
            printf("\nYou've picked up the rope toy. You're currently holding %d toy/s!\n\n", addhand);
            ropetoy2 = 0;
            
        }
        
        else if (picktoy_decision == 'N' || picktoy_decision == 'n')
        {
            
            printf("\nOkay, but be careful! You might step on this toy later on.\n\n");
            
        }
        
        else
        {
            
            printf("\nWrong input, try again.\n\n");
            goto toy4_goto;
            
        }
        
    }
    
    else if (balltoy == followingLocation)
    {
        
        printf("The ball toy is on the floor! ");
        
    toy5_goto:
        
        printf("Would you like to pick up the ball toy? (Y/N): ");
        scanf(" %c", &picktoy_decision);
        
        if (picktoy_decision == 'Y' || picktoy_decision == 'y')
        {
            
            addhand++;
            printf("\nYou've picked up the ball toy. You're currently holding %d toy/s!\n\n", addhand);
            balltoy = 0;
            
        }
        
        else if (picktoy_decision == 'N' || picktoy_decision == 'n')
        {
            
            printf("\nOkay, but be careful! You might step on this toy later on.\n\n");
            
        }
        
        else
        {
            
            printf("\nWrong input, try again.\n\n");
            goto toy5_goto;
            
        }
        
    }
    
    else if (balltoy2 == followingLocation)
    {
        
        printf("The ball toy is on the floor! ");
        
    toy6_goto:
        
        printf("Would you like to pick up the ball toy? (Y/N): ");
        scanf(" %c", &picktoy_decision);
        
        if (picktoy_decision == 'Y' || picktoy_decision == 'y')
        {
            
            addhand++;
            printf("\nYou've picked up the ball toy. You're currently holding %d toy/s!\n\n", addhand);
            balltoy2 = 0;
            
        }
        
        else if (picktoy_decision == 'N' || picktoy_decision == 'n')
        {
            
            printf("\nOkay, but be careful! You might step on this toy later on.\n\n");
            
        }
        
        else
        {
            
            printf("\nWrong input, try again.\n\n");
            goto toy6_goto;
            
        }
        
    }
    
    else
    {
        
        printf("There's no toy on the floor.\n\n");
        
    }
    
    return 0;
}


// Toy Bin!
int get_toybin()
{
    
    char toybin_choice;
    
    printf("TOY BIN CHECK: ");
    
    if (followingLocation == 1 || followingLocation == 8 || followingLocation == 13)
    {
        
        printf("There's a toy bin here!\n\n");
        
    toybin_goto:
        
        printf("Would you want to drop the toy/s that you're holding? (Y/N): ");
        scanf(" %c", &toybin_choice);
        
        if (toybin_choice == 'Y' || toybin_choice == 'y')
        {
            
            if (addhand == 2)
            {
                
                printf("\nYou've dropped 2 toys in the bin, which gives you 2 hearts!\n\n");
                addhand -= 2;
                addheart += 2;
                
            }
            
            else if (addhand == 1)
            {
                
                printf("\nYou've dropped 1 toy in the bin, which gives you a heart!\n\n");
                addhand -= 1;
                addheart += 1;
                
            }
            
            else if (addhand == 0)
            {
                
                printf("\nYou're not holding anything! Silly, moving on!\n\n");
                
            }
            
            else
            {
                
                printf("\nWhy are you holding %d toys.\n\n", addhand);
                
            }
            
        }
        
        else if (toybin_choice == 'N' || toybin_choice == 'n')
        {
            
            printf("\nOkay, moving on.\n\n");
            
        }
        
        else
        {
            
            printf("\nSorry, invalid input! Try again.\n\n");
            goto toybin_goto;
            
        }
        
    }
    
    else
    {
        
        printf("There's no bin in this room! Go to the garage, covered terrace, or your bedroom!\n\n");
        
    }
    
    return 0;
    
}


// Action Picker (after loop)
int get_chooseAction(time_t begin)
{
    
    char action_choice, quit_choice, shoelook_choice;
    int counter, shoerandom;
    
    
get_chooseAction_goto:
    
    printf("ACTIONS:\n\n");
    printf("   (A) Look for shoe.\n");
    printf("   (B) Go to other location.\n");
    printf("   (C) Drop toys in bin.\n");
    printf("   (D) Quit finding shoe.\n\n");
    
    printf("Pick an action: ");
    scanf(" %c", &action_choice);
    printf("\n");
    
    // ACTION 1 — Look for shoe
    if (action_choice == 'A' || action_choice == 'a')
    {
        
        if (get_shoeRandomGenerator == followingLocation)
        {
            
            if (addhand == 0)
            {
                
                shoerandom = getRandomNum(2,5);
                
                for (counter = 2; counter <= SHOELOOK_LIMIT; counter++)
                {
                    
                    if (counter != shoerandom || counter == shoerandom)
                    {
                        
                        printf("Cannot find the shoe! Would you like to look again? (Y/N): ");
                        scanf(" %c", &shoelook_choice);
                        
                        if (shoelook_choice == 'Y' || shoelook_choice == 'y')
                        {
                            
                            if (counter == shoerandom)
                            {
                                
                                printf("\n");
                                print_endscreen(begin);
                                
                            }
                            
                            else if (counter != shoerandom)
                            {
                                
                                printf("\nKeep on looking!\n\n");
                                addtime += 2;
                                
                            }
                            
                        }
                        
                        else if (shoelook_choice == 'N' || shoelook_choice == 'n')
                        {
                            
                            printf("\nOkay! Moving on.\n\n");
                            goto action_choice_goto;
                            break;
                            
                        }
                        
                    }
                    
                    
                }
                
            }
            
            else if (addhand == 1 || addhand == 2)
            {
                
                printf("You're still holding %d toy/s! Return it first to a bin!\n\n", addhand);
                printf("Moving on!\n\n");
                goto get_chooseAction_goto;
                
            }
            
        }
        
        else
        {
            
            int shoelook = 2;
            
            addtime += 2;
            
            while (shoelook <= SHOELOOK_LIMIT)
            {
                
                printf("Cannot find the shoe! Would you like to look again? (Y/N): ");
                scanf(" %c", &shoelook_choice);
                
                if (shoelook_choice == 'Y' || shoelook_choice == 'y')
                {
                    
                    printf("\nKeep on looking!\n\n");
                    addtime += 2;
                    shoelook++;
                    
                }
                
                else if (shoelook_choice == 'N' || shoelook_choice == 'n')
                {
                    
                    printf("\nOkay! Moving on.\n\n");
                    goto action_choice_goto;
                    
                }
                
                else
                {
                    
                    printf("\nSorry, invalid input! Try again.\n\n");
                    
                }
                
            }
            
            printf("You've already looked 5 times!.\n\n"); printf("Moving on!\n\n");
            
        action_choice_goto:
            
            printf("ACTIONS:\n\n");
            printf("   (A) Go to other location.\n");
            printf("   (B) Drop toys in bin.\n");
            printf("   (C) Quit finding shoe.\n\n");
            
            printf("Pick an action: ");
            scanf(" %c", &action_choice);
            printf("\n");
            
            if (action_choice == 'A' || action_choice == 'a')
            {
                
                goto followingLocation_goto;
                
            }
            
            else if (action_choice == 'B' || action_choice == 'b')
            {
                
                get_toybin();
                goto action_choice_goto;
                
            }
            
            else if (action_choice == 'C' || action_choice == 'c')
            {
                
                // goto quit_goto;
                
                printf("Are you sure you want to quit? (Y/N): ");
                scanf(" %c", &quit_choice);
                
                if (quit_choice == 'Y' || quit_choice == 'y')
                {
                    
                    print_quitscreen (begin);
                    
                }
                
                else if (quit_choice == 'N' || quit_choice == 'n')
                {
                    
                    printf("\nOkay, we shall continue.\n\n"); goto action_choice_goto;
                    
                }
                
                else
                {
                    
                    printf("\nSorry, invalid input! Try again.\n\n"); goto action_choice_goto;
                    
                }
                
            }
            
            else
            {
                
                printf("Sorry, invalid input! Try again.\n\n");
                goto action_choice_goto;
                return 0;
                
            }
            
            
        }
        
        
    }
    
    // ACTION 2 - Go to other location
    else if (action_choice == 'B' || action_choice == 'b')
    {
        
    followingLocation_goto:
        
        followingLocation = print_nextLocation(nextLocation);
        
        nextLocation = get_LocationValue(followingLocation);
        
        printf("\n");
        
        printf("--------------------------------------------------------------------------------\n\n");
        
        printf("CURRENT LOCATION: "); print_Location(followingLocation);
        
    }
    
    // ACTION 3 - Is there a toy bin here?
    else if (action_choice == 'C' || action_choice == 'c')
    {
        
    toybin_goto:
        
        get_toybin();
        get_chooseAction(begin);
        
    }
    
    // ACTION 4 - Quit!
    else if (action_choice == 'D' || action_choice == 'd')
    {
        
    quit_goto:
        
        printf("Are you sure you want to quit? (Y/N): ");
        scanf(" %c", &quit_choice);
        
        if (quit_choice == 'Y' || quit_choice == 'y')
        {
            
            print_quitscreen (begin);
            
        }
        
        else if (quit_choice == 'N' || quit_choice == 'n')
        {
            
            printf("\nOkay, we shall continue.\n\n"); get_chooseAction(begin);
            
        }
        
        else
        {
            
            printf("\nSorry, invalid input! Try again.\n\n"); goto quit_goto;
            
        }
        
    }
    
    else
    {
        
        printf("Sorry, invalid input! Try again.\n\n"); goto get_chooseAction_goto;
        
        
    }
    
    return 0;
    
}


// Intro Prompt
int print_intro()
{
    
    char begin_intro;
    
    printf("Begin? (Y/N): ");
    scanf(" %c", &begin_intro);
    
    if (begin_intro == 'Y' || begin_intro == 'y')
    {
        
        printf("\nOkay! Let's proceed.\n\n");
        
    }
    
    else if (begin_intro == 'N' || begin_intro == 'n')
    {
        
        printf("\nOkay, bye!\n");
        exit(0);
        
    }
    
    else
    {
        
        printf("\nSorry, invalid input! Let's try again.\n\n"); print_intro();
        
    }
    
    return 0;
    
}


int main()
{
    
    initRandom();
    
    time_t begin,end;
    int initialPosition;
    
    get_shoeRandomGenerator = getRandomNum (1,19); // assigns shoe in a location!
    chewtoy = getRandomNum (1,19);
    ropetoy = getRandomNum (1,19);
    balltoy = getRandomNum (1,19);
    chewtoy2 = getRandomNum (1,19);
    ropetoy2 = getRandomNum (1,19);
    balltoy2 = getRandomNum (1,19);
    
    // Changer of value if ever they become the same
    
    while ( chewtoy == ropetoy || chewtoy == balltoy || chewtoy == chewtoy2 || chewtoy == ropetoy2 || chewtoy == balltoy2 )
    {
        
        chewtoy = getRandomNum (1,19);
        
    }
    
    while ( ropetoy == chewtoy || ropetoy == balltoy || ropetoy == chewtoy2 || ropetoy == ropetoy2 || ropetoy == balltoy2 )
    {
        
        ropetoy = getRandomNum (1,19);
        
    }
    
    while ( balltoy == ropetoy || balltoy == chewtoy || balltoy == chewtoy2 || balltoy == ropetoy2 || balltoy == balltoy2 )
    {
        
        balltoy = getRandomNum (1,19);
        
    }
    
    while ( chewtoy2 == ropetoy || chewtoy2 == balltoy || chewtoy2 == chewtoy || chewtoy2 == ropetoy2 || chewtoy2 == balltoy2 )
    {
        
        chewtoy2 = getRandomNum (1,19);
        
    }
    
    while ( ropetoy2 == ropetoy || ropetoy2 == balltoy || ropetoy2 == chewtoy || ropetoy2 == chewtoy2 || ropetoy2 == balltoy2 )
    {
        
        ropetoy2 = getRandomNum (1,19);
        
    }
    
    while ( balltoy2 == ropetoy || balltoy2 == balltoy || balltoy2 == chewtoy || balltoy2 == ropetoy2 || balltoy2 == chewtoy2 )
    {
        
        balltoy2 = getRandomNum (1,19);
        
    }
    
    
    // INTRO + INSTRUCTIONS
    
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                                 FIND THAT SHOE!                              *\n");
    printf("*                                                                              *\n");
    printf("*                                  by STEPHEN S.                               *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n\n");
    printf("--------------------------------------------------------------------------------\n\n");
    
    printf("INSTRUCTIONS:\n\n");
    
    printf("The game will tell your initial location in the house and actions\n");
    printf("that you can choose from.\n\n");
    
    printf("You can look for the shoe in that location, which will add 2 seconds\n");
    printf("to your time (5 tries only), or move on to another location that's\n");
    printf("adjacent to your current one.\n\n");
    
    printf("Your dog, ");
    
    dogGender = get_dogGender(getRandomNum (0,1)); // assigns if Bailey or Kahlua!
    
    printf(", can show up occasionally while you're looking for the shoe.\n\n");
    printf("If you pet your dog, you'll get a heart, which subtracts 2 seconds from the\n");
    printf("whole duration of your gameplay, and if you don't pet, you don't get a heart!\n\n");
    
    printf("Also, there are three types of toys that are littered around the house, \n");
    printf("namely: A chew toy, a rope, and a ball.\n\n");
    
    printf("If you've managed to pick up and put the toys in the bin that are located\n");
    printf("at your bedroom, the garage, and the covered terrace, you will receive a heart.\n\n");
    
    printf("But warning, you can only hold onto two toys at a time, which might\n");
    printf("make you step on a toy -- adding 3 seconds to your total time,\n");
    printf("so return the toys quickly into the bin!\n\n");
    
    printf("With that being said, good luck!\n\n");
    printf("--------------------------------------------------------------------------------\n\n");
    
    print_intro();
    
    printf("--------------------------------------------------------------------------------\n\n");
    
    begin = time(NULL);
    
    // END OF INTRO
    
    // -- --
    
    // START OF GAME
    
    printf("INITIAL LOCATION: ");
    
    initialPosition = print_Location(getRandomNum (1,19)); // generator where the player starts!
    
    nextLocation = get_LocationValue(initialPosition);
    
    printf("\n");
    
    do
    {
        
        print_dogAppear();
        print_toy();
        get_chooseAction(begin);
        printf("\n");
        
        
    } while (get_shoeRandomGenerator != 0);
    
    end = time(NULL);
    
    printf("You found the shoe!\n\n");
    printf("--------------------------------------------------------------------------------\n\n");
    printf("\tGAME SUMMARY:\n\n");
    printf("\tGame Duration: %.2f seconds\n", difftime(end, begin));
    printf("\tAddition to time: +%d seconds\n", addtime);
    printf("\tNumber of collected hearts: %d = -%d seconds\n", addheart, (addheart * 2));
    printf("\tTotal Game Duration: %.2f seconds \n\n", difftime(end, begin) + addtime - (addheart * 2));
    printf("--------------------------------------------------------------------------------\n\n");
    
    return 0;
}

