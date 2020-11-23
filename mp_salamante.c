/*
 
 SALAMANTE, STEPHEN E.
 11831014
 CCPROG1 X22
 NOV. (sumfin), 2018
 
 Filename: machine_project.c
 
 This program is a game called "Find that shoe!"
 Where the player has to find the missing shoe in the house.
 
 */


/*
 
 Arriving in a location options:
 — Look for the shoe
 — Go to other locations (only the ones that are adjacent to the current location)
 — Pick up toy (if there is a toy)
 – Pet your dog (if dog shows up)
 — Put toy in bin (only if in Bedroom #2, Garage, or Covered Terrace)
 — Quit finding the shoe
 
 */


/*
 
 ROOM VALUES
 
 [FIRST FLOOR]                                  [SECOND FLOOR]
 1 — Garage                                     10 — Master Bedroom
 2 — Covered Entry                                  11 — Walk-in Closet (M.B.)
 3 — Foyer (+ stairs)                               12 — Bathroom (M.B.)
 4 — Powder Room                                13 — Your Bedroom (#2)
 5 — Living Room                                    14 — Walk-in Closet (Y.B.)
 6 — Dining Room                                15 — Guest Suite / Den (if not guest)
 7 — Kitchen                                    16 — Common Bathroom (#2)
 8 — Covered Terrace                            17 — Laundry Room
 9 — Garden                                     18 — Linen Closet
 (thru covered entry or terrace)                19 — Hallway (+ stairs)
 
 */

/*
 
 TIME ESSENTIALS
 
 [Action]                                       [Result]
 1 — Petting dog                                -2 each heart
 2 — Collecting toys (and returning to bin)     -2 each heart
 3 — Stepping on toy                            +3
 4 — Looking for shoe (five chances)            +2
 
 */

/*
 
 CURRENT USER-DEFINED FUNCTIONS!
 
 1 — initRandom — essential for random generator (pt.1)
 2 — getRandomNum — essential for random generator (pt.2)
 3 — print_randomLocation — prints your current location
 4 — get_dogGender — assigns if the dog's a girl or boy (for the name)
 5 — get_dogCheck — to check if the dog's in the same room as the player
 6 — get_toyGenerate — generate the toy around the house
 7 — print_nextLocation — for moving around the house
 8 — get_chooseAction — action picker
 9 — get_shoeRandomGenerator — to generate where the shoe is in the house
 9 — print_intro — introduction + instructions
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


// Random locations (for initial position)
int print_randomLocation()
{
    
    switch (getRandomNum (1,19))
    {
            
            // FIRST FLOOR ROOMS
            
        case 1:
            printf("FIRST FLOOR — You're in the garage!\n");
            return 1; break;
            
        case 2:
            printf("FIRST FLOOR — You're at the covered entry!\n");
            return 2; break;
            
        case 3:
            printf("FIRST FLOOR — You're at the foyer!\n");
            return 3; break;
            
        case 4:
            printf("FIRST FLOOR — You're in the powder room!\n");
            return 4; break;
            
        case 5:
            printf("FIRST FLOOR — You're in the living room!\n");
            return 5; break;
            
        case 6:
            printf("FIRST FLOOR — You're in the dining room!\n");
            return 6; break;
            
        case 7:
            printf("FIRST FLOOR — You're in the kitchen!\n");
            return 7; break;
            
        case 8:
            printf("FIRST FLOOR — You're at the covered terrace!\n");
            return 8; break;
            
        case 9:
            printf("FIRST FLOOR — You're at the garden!\n");
            return 9; break;
            
            
            // SECOND FLOOR ROOMS
            
        case 10:
            printf("SECOND FLOOR — You're in the master bedroom!\n");
            return 10; break;
            
        case 11:
            printf("SECOND FLOOR — You're in the walk-in closet of the master bedroom!\n");
            return 11; break;
            
        case 12:
            printf("SECOND FLOOR — You're in the bathroom of the master bedroom!\n");
            return 12; break;
            
        case 13:
            printf("SECOND FLOOR — You're in your bedroom!\n");
            return 13; break;
            
        case 14:
            printf("SECOND FLOOR — You're in the walk-in closet of your bedroom!\n");
            return 14; break;
            
        case 15:
            
            switch (getRandomNum (1,2))
        {
                
            case 1:
                printf("SECOND FLOOR — You're in the guest suite (there's a guest)!\n");
                return 15; break;
                
            case 2:
                printf("SECOND FLOOR — You're in the den (there's no guest)!\n");
                return 15; break;
                
        }
            
            break;
            
        case 16:
            printf("SECOND FLOOR — You're in the common bathroom (#2)!\n");
            return 16; break;
            
        case 17:
            printf("SECOND FLOOR — You're in the laundry room!\n");
            return 17; break;
            
        case 18:
            printf("SECOND FLOOR — You're in the linen closet!\n");
            return 18; break;
            
        case 19:
            printf("SECOND FLOOR — You're in the hallway!\n");
            return 19; break;
            
    }
    
    return 0;
    
}


// Dog Gender
int get_dogGender()
{
    
    getRandomNum (0,1);
    switch (getRandomNum (0,1))
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


// Dog Checker
int get_dogCheck(int *heart)
{
    
    int playerDogDecision;
    getRandomNum (0,1);
    switch (getRandomNum (0,1))
    {
            
        case 0:
            printf("Dog's not in here!\n");
            return 0; break;
            
        case 1:
            get_dogGender(); printf(" is here!\n");
            printf("Would you like to pet "); get_dogGender(); printf("? (1 — Yes, 2 — No): ");
            scanf("%d", &playerDogDecision);
            
            switch (playerDogDecision)
        {
                
            case 1: // pet the dog
                printf("\nYay! For that kindhearted action, you get a heart!\n");
                
                return ++*heart++; break;
                
            case 2: // did not pet the dog :(
                get_dogGender(); printf(" is sad. Okay, moving on.\n");
                return 0; break;
                
        }
            
    }
    
    return 0;
    
}


// Toy Generator
int get_toyGenerate (int *hands, int *time)
{
    
    int toyChoice;
    getRandomNum (0,2);
    switch (getRandomNum (0,2))
    {
            
        case 0: case 1: // no toy
            printf("There's no toy on the ground!\n");
            return 0; break;
            
        case 2: // there's a toy
            getRandomNum (1,3);
            
            switch (getRandomNum (1,3))
        {
                
            case 1: // a chew toy
                printf("There's a chew toy on the floor!\n");
                
                switch (*hands)
            {
                    
                    
                case 0:
                    printf("Would you like to pick up the toy? ( 1 - Yes, 2 - No ): ");
                    scanf("%d", &toyChoice);
                    
                    switch (toyChoice)
                {
                        
                    case 1:
                        printf("\nOkay! You are now holding 1 toy, return it to a bin immediately!");
                        return ++*hands++; break;
                        
                    case 2:
                        printf("\nOkay, let's continue.\n");
                        return 0; break;
                        
                }
                    
                case 1:
                    printf("Would you like to pick up the toy? ( 1 - Yes, 2 - No ): ");
                    scanf("%d", &toyChoice);
                    
                    switch (toyChoice)
                {
                        
                    case 1:
                        printf("\nOkay! You are now holding 2 toys, return it to a bin immediately!");
                        return ++*hands++; break;
                        
                    case 2:
                        printf("\nOkay, let's continue.\n");
                        return 0; break;
                        
                }
                    
                    
                case 2:
                    printf("Oh no! You've stepped on the toy, adding 3 seconds to your total time.\n");
                    return *time += 3;
                    break;
                    
            } break;
                
            case 2: // a rope
                printf("There's a rope on the floor!");
                
                switch (*hands)
            {
                    
                    
                case 0:
                    printf("Would you like to pick up the toy? ( 1 - Yes, 2 - No ): ");
                    scanf("%d", &toyChoice);
                    
                    switch (toyChoice)
                {
                        
                    case 1:
                        printf("\nOkay! You are now holding 1 toy, return it to a bin immediately!");
                        return ++*hands++; break;
                        
                    case 2:
                        printf("\nOkay, let's continue.\n");
                        return 0; break;
                        
                }
                    
                case 1:
                    printf("Would you like to pick up the toy? ( 1 - Yes, 2 - No ): ");
                    scanf("%d", &toyChoice);
                    
                    switch (toyChoice)
                {
                        
                    case 1:
                        printf("\nOkay! You are now holding 2 toys, return it to a bin immediately!");
                        return ++*hands++; break;
                        
                    case 2:
                        printf("\nOkay, let's continue.\n");
                        return 0; break;
                        
                }
                    
                    
                case 2:
                    printf("Oh no! You've stepped on the toy, adding 3 seconds to your total time.\n");
                    return *time += 3;
                    break;
                    
            } break;
                
            case 3: // a ball
                printf("There's a ball on the floor!");
                
                switch (*hands)
            {
                    
                    
                case 0:
                    printf("Would you like to pick up the toy? ( 1 - Yes, 2 - No ): ");
                    scanf("%d", &toyChoice);
                    
                    switch (toyChoice)
                {
                        
                    case 1:
                        printf("\nOkay! You are now holding 1 toy, return it to a bin immediately!");
                        return ++*hands++; break;
                        
                    case 2:
                        printf("\nOkay, let's continue.\n");
                        return 0; break;
                        
                }
                    
                case 1:
                    printf("Would you like to pick up the toy? ( 1 - Yes, 2 - No ): ");
                    scanf("%d", &toyChoice);
                    
                    switch (toyChoice)
                {
                        
                    case 1:
                        printf("\nOkay! You are now holding 2 toys, return it to a bin immediately!");
                        return ++*hands++; break;
                        
                    case 2:
                        printf("\nOkay, let's continue.\n");
                        return 0; break;
                        
                }
                    
                    
                case 2:
                    printf("Oh no! You've stepped on the toy, adding 3 seconds to your total time.\n");
                    return *time += 3;
                    break;
                    
            } break;
                
        }
            
    }
    
    return 0;
    
}


// For movement of player
int print_nextLocation(int nextLocation)
{
    
    switch (nextLocation)
    {
            
            // FIRST FLOOR
            
        case 1:
            printf("(1) Foyer\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 3; break;
                
        }
            break;
            
        case 2:
            printf("(1) Foyer, (2) Garden\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 3; break;
            case 2: return 9; break;
                
        }
            
            
            break;
            
        case 3:
            printf("(1) Upstairs, (2) Garage, (3) Living Room\n"); // stairs = hallway (19)
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 19; break;
            case 2: return 1; break;
            case 3: return 5; break;
                
        }
            
            break;
            
        case 4:
            printf("(1) Living Room\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 5; break;
                
        }
            
            break;
            
        case 5:
            printf("(1) Covered Terrace, (2) Dining Room, (3) Kitchen, (4) Powder Room\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 8; break;
            case 2: return 6; break;
            case 3: return 7; break;
            case 4: return 4; break;
                
        }
            
            break;
            
        case 6:
            printf("(1) Covered Terrace, (2) Kitchen, (3) Living Room\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 8; break;
            case 2: return 7; break;
            case 3: return 5; break;
                
        }
            
            break;
            
        case 7:
            printf("(1) Dining Room, (2) Living Room\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 6; break;
            case 2: return 5; break;
                
        }
            
            break;
            
        case 8:
            printf("(1) Garden, (2) Dining Room, (3) Living Room\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 9; break;
            case 2: return 6; break;
            case 3: return 5; break;
                
        }
            
            break;
            
        case 9:
            printf("(1) Covered Entry, (2) Covered Terrace\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 2; break;
            case 2: return 8; break;
                
        }
            
            break;
            
            // SECOND FLOOR
            
        case 10:
            printf("(1) Hallway, (2) Walk-in Closet [Master Bedroom]\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 19; break;
            case 2: return 11; break;
                
        }
            
            break;
            
        case 11:
            printf("(1) Bathroom [Master Bedroom], (2) Master Bedroom\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 12; break;
            case 2: return 10; break;
                
        }
            
            break;
            
        case 12:
            printf("(1) Walk-in Closet [Master Bedroom]\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 11; break;
                
        }
            
            break;
            
        case 13:
            printf("(1) Hallway, (2) Walk-in Closet [Your Bedroom]\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 19; break;
            case 2: return 14; break;
                
        }
            
            break;
            
        case 14:
            printf("(1) Your Bedroom\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 13; break;
                
        }
            
            break;
            
        case 15:
            printf("(1) Hallway\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 19; break;
                
        }
            
            break;
            
        case 16:
            printf("(1) Hallway\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 19; break;
                
        }
            
            break;
            
        case 17:
            printf("(1) Hallway\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 19; break;
                
        }
            
            break;
            
        case 18:
            printf("(1) Hallway\n");
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 19; break;
                
        }
            
            break;
            
        case 19:
            printf("(1) Laundry Room, (2) Linen Closet, (3) Guest Suite/Den, (4) Bathroom #2, (5) Your Bedroom, (6) Downstairs\n"); // stairs = foyer (3)
            scanf("%d", &nextLocation);
            
            switch (nextLocation)
        {
                
            case 1: return 17; break;
            case 2: return 18; break;
            case 3: return 15; break;
            case 4: return 16; break;
            case 5: return 13; break;
            case 6: return 3; break;
                
        }
            
            break;
            
    }
    
    return 0;
    
}


// Locations (not random)
int print_location(int location)
{
    
    switch (location)
    {
            
            // FIRST FLOOR ROOMS
            
        case 1:
            printf("FIRST FLOOR — You're in the garage!\n");
            return 1; break;
            
        case 2:
            printf("FIRST FLOOR — You're at the covered entry!\n");
            return 2; break;
            
        case 3:
            printf("FIRST FLOOR — You're at the foyer!\n");
            return 3; break;
            
        case 4:
            printf("FIRST FLOOR — You're in the powder room!\n");
            return 4; break;
            
        case 5:
            printf("FIRST FLOOR — You're in the living room!\n");
            return 5; break;
            
        case 6:
            printf("FIRST FLOOR — You're in the dining room!\n");
            return 6; break;
            
        case 7:
            printf("FIRST FLOOR — You're in the kitchen!\n");
            return 7; break;
            
        case 8:
            printf("FIRST FLOOR — You're at the covered terrace!\n");
            return 8; break;
            
        case 9:
            printf("FIRST FLOOR — You're at the garden!\n");
            return 9; break;
            
            
            // SECOND FLOOR ROOMS
            
        case 10:
            printf("SECOND FLOOR — You're in the master bedroom!\n");
            return 10; break;
            
        case 11:
            printf("SECOND FLOOR — You're in the walk-in closet of the master bedroom!\n");
            return 11; break;
            
        case 12:
            printf("SECOND FLOOR — You're in the bathroom of the master bedroom!\n");
            return 12; break;
            
        case 13:
            printf("SECOND FLOOR — You're in your bedroom!\n");
            return 13; break;
            
        case 14:
            printf("SECOND FLOOR — You're in the walk-in closet of your bedroom!\n");
            return 14; break;
            
        case 15:
            
            switch (getRandomNum (1,2))
        {
                
            case 1:
                printf("SECOND FLOOR — You're in the guest suite (there's a guest)!\n");
                return 15; break;
                
            case 2:
                printf("SECOND FLOOR — You're in the den (there's no guest)!\n");
                return 15; break;
                
        }
            
            break;
            
        case 16:
            printf("SECOND FLOOR — You're in the common bathroom (#2)!\n");
            return 16; break;
            
        case 17:
            printf("SECOND FLOOR — You're in the laundry room!\n");
            return 17; break;
            
        case 18:
            printf("SECOND FLOOR — You're in the linen closet!\n");
            return 18; break;
            
        case 19:
            printf("SECOND FLOOR — You're in the hallway!\n");
            return 19; break;
            
    }
    
    return 0;
    
}


// Shoe Random Generator
int get_shoeRandomGenerator()
{
    
    int shoeRandom = getRandomNum (1,18);
    return shoeRandom;
    
}


// Find Shoe Option
int get_findShoe(int time)
{
    
    int i;
    
    if ((get_shoeRandomGenerator() == print_randomLocation()) || (get_shoeRandomGenerator() == print_randomLocation()))
    {
        
        printf("Congratulations! You found the shoe!\n");
        return 0;
        
    }
    
    else if ((get_shoeRandomGenerator() != print_randomLocation())) // should be looped 5 times
    {
        
        for ( i = 1; i <= 5; i++)
        {
            
            printf("Sorry, the shoe is not in here, but you could try looking for it again.\n");
            time += 2;
            return 1;
            
        }
        
    }
    
    return 0;
    
}


// Bin Location
int get_binLocation (int *hands, int *heart)
{
    
    if ((print_randomLocation() == 1) || (print_randomLocation() == 8) || (print_randomLocation() == 13))
    {
        
        if (get_toyGenerate (hands, heart) == 2)
        {
            
            *hands -= 2;
            *heart += 2;
            return 0;
            
        }
        
        else if (get_toyGenerate (hands, heart) == 1)
        {
            
            *hands -= 1;
            *heart += 1;
            return 0;
            
        }
        
        else if (get_toyGenerate (hands, heart) == 0)
        {
            
            *hands -= 0;
            *heart += 0;
            return 0;
            
        }
        
        
    }
    
    return 0;
}


// Action Picker
int get_chooseAction()
{
    
    int action, quit_choice;
    
    printf("ACTIONS:\n");
    printf("   (1) Look for shoe.\n");
    printf("   (2) Go to other location.\n");
    printf("   (3) Pick up toy.\n");
    printf("   (4) Pet your dog.\n");
    printf("   (5) Put toy in bin.\n");
    printf("   (6) Quit finding shoe.\n\n");
    
    printf("Pick an action: ");
    scanf("%d", &action);
    printf("\n");
    
    switch (action)
    
    {
        case 1: get_findShoe(time); break;
        case 2: print_nextLocation(nextLocation); break;
            //case 3: get_toyGenerate (&hands, &time); break;
            //case 4: get_dogCheck (&heart); break;
            //case 5: get_binLocation(&hands, &heart); break;
        case 6:
            printf("Are you sure you want to quit? [1 - Yes, 2 - No]: ");
            scanf("%d", &quit_choice);
            
            switch (quit_choice)
        {
                
            case 1: printf("\nSee you next time!\n"); exit(0);
            case 2: printf("\nOkay, we shall continue.\n\n"); get_chooseAction();
            default: printf("\nSorry, invalid input! Try again.\n\n"); get_chooseAction();
                
        }
            
            
            
    }
    
    return 0;
    
}


// Intro Message + Instructions
int print_intro()
{
    int begin;
    
    printf("FIND THAT SHOE!\n\n");
    
    printf("You are tasked to find a shoe that is located somewhere in the house.\n\n");
    
    printf("The game will tell your initial location at the house, \n");
    printf("and actions that you can choose from.\n\n");
    
    printf("You can look for the shoe in that location, which will add 2 seconds to your time (5 tries only),\n");
    printf("or move on to another location that's adjacent to your current one.\n\n");
    
    printf("Your dog, "); get_dogGender(); printf(", can show up occasionally while you're looking for the shoe.\n");
    printf("If you pet your dog, you'll get a heart, which subtracts 2 seconds from the\n");
    printf("whole duration of your gameplay.\n\n");
    
    printf("Also, there are three types of toys that are littered around the house, \n");
    printf("namely: A chew toy, a rope, and a ball.\n\n");
    
    printf("If you've managed to pick up and put the toys in the bin that are located\n");
    printf("at your bedroom, the garage, and the covered terrace, you will receive a heart.\n\n");
    
    printf("But warning, you can only hold onto two toys at a time, which might make you step\n");
    printf("on a toy—adding 3 seconds to your total time, so return the toys quick into the bin!\n\n");
    
    printf("With that being said, good luck!\n\n\n\n");
    
    printf("Begin? [ 1 — Yes, 2 — No ]: ");
    scanf("%d", &begin);
    
    switch (begin)
    {
            
        case 1:
            printf("\nOkay! Let's proceed.\n\n");
            break;
        case 2:
            printf("\nOkay bye!");
            exit(0);
        default: printf("\nSorry, invalid input! Try again.\n\n"); print_intro();
            
            
    }
    
    return 0;
    
}


int main()
{
    
    initRandom();
    
    //int heart = 0, hands = 0, time = 0;
    int randomLocation, nextLocation;
    
    randomLocation = print_randomLocation();
    
    print_intro();
    
    printf("Initial Position: "); print_location(randomLocation);
    printf("\n");
    
    nextLocation = print_location(randomLocation);
    
    while (get_shoeRandomGenerator() != nextLocation) // shoe == location && hand == 0
    {
        
        // do not include pet dog and pick up toy in menu
        get_chooseAction();
        
    }
    
    get_chooseAction();
    
    // compute total time, heart, bin
    
    return 0;
    
}


/* NOTES!
 
 FOR TOY BINS
 print_randomLocation() == 13, 1, 8
 
 
 get_findShoe == 0 && hands == 0; end game (success)
 
 MAKE GUEST SUITE / DEN FUNCTION!
 
 */
