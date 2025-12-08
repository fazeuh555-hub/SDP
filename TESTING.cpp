/*These are the libraries that are used to make the code funciton*/
#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHKeyboard.h"
#include "FEHRandom.h"
#include "FEHImages.h"
#include <string>
#include <cstring>

/*This is the class that contains all of the functions that run the code.*/
class Main_Menu
{
private:

        int loads=0, loads_streak=0, misses=0; /*Sets the scores on the stats page to zero*/
        
        float velocityY = 0.0f; /*This is the jump velocity (how high you can jump)*/
        float gravity = 0.4f; /*Sets up gravity (This brings you back down)*/
        float jumpStrength = -7.0f; /*Given by AI to help with the jump mechanic when it wasn't working properly*/
       
        int playerX = 40; /*Sets the spawn of the character's X position*/
        int playerY; /*Sets the spawn of the character's Y position*/
        int playerW = 14; /*Sets the width of the character*/
        int playerH = 18; /*Sets the height of the character*/
        
        int groundY = 200; /*This is the floor in the game.*/
        
        bool inAir = false; /*A condition to check if the player is airborne. This is false because the player hasn't jumped yet*/
        int pileW = 20; /*Sets the laundry piles' width*/
        int pileH = 12; /*Sets the laundry piles' height*/
        
        static const int NUM_PILES = 6; /*Sets the maximum allowed laundry piles spawned at six.*/
        static const int NUM_Person = 4; /*Sets the maximum allowed people spawned at four.*/
        
        int machineX = 300; /*Sets the x position of the first laundry machine at x=270.*/
        int machineY = groundY - 40; /*Sets the Y position of the first laundry machine at y = 160*/
        int machineW = 37; /*Sets the width of the first laundry machine.*/
        int machineH = 40; /*Sets the height of the first laundry machine.*/

        int pileX[NUM_PILES]; /*An array with the x positions of the laundry piles. (given how many laundry piles are allowed)*/
        int pileY[NUM_PILES]; /*An array with the y positions of the laundry piles. (given how many laundry piles are allowed)*/
        
        int personW = 12; /*Sets the person's width*/
        int personH = 20; /*Sets the person's height*/
        int PersonX[NUM_Person]; /*An array with the x positions of the people. (given how many people are allowed)*/
        int PersonY[NUM_Person]; /*An array with the y positions of the people. (given how many people are allowed)*/
        
       
        int fallX;         /*The spilled detergent will start at this x position*/
        int fallY;         /*The spilled detergent will start at this y position*/
        int fallR = 8;     /*The spilled detergent will be this big (a circle with radius eight pixels.)*/
        bool fallLanded;    /*A condition to see if the detergent reached the floor.*/
        int fallSpeed = 2;  /*How fast the ball will fall.*/
      
        int fallRectW = 50; /*The spilled detergent becomes a rectangle with this width.*/
        int fallRectH = 7;  /*The spilled detergent becomes a rectangle with this height.*/
        float fallTimer;    /*How long the detergent has been on the ground.*/
        float fallDuration = 3; /* The detergent will stay on the ground for this time.*/

        int activeMachine; /*Used to determine which machine is active.*/
        float machineTimer; /*Used to determine how long machine is active.*/
        

        float playerSpeed; /*Used to determine how fast the player will be.*/
        float jumpMultiplier; /*Used to determine how high the player can jump (as an addon).*/
        float pileSpeed; /*Used to determine how fast the laundry piles will be.*/
        float personSpeed; /*Used to determine how fast the people will be.*/
        float machineDuration; /*Used to determine how long machine is active before being noninteractable.*/
        int numPiles; /*Used to determine how many laundry piles will be spawned.*/
        int numPeople; /*Used to determine how many people will be spawned.*/

        //art assets for the game (background, piles, splash, player/people)
        FEHImage bg_img;
        FEHImage pile_img;
        FEHImage splash_img;
        FEHImage student_img;
        
  
public:
 Main_Menu(); /*A constructor for intializing variables for gameplay */

 void play_button(); /*Function for the play button.*/
 void stats_button(); /*Function for the statisics button.*/
 void credits_button(); /*Function for the credits button.*/
 void Main_Screen (); /*Function for the Main screen.*/
 void tutorial (); /*Function for the tutorial button (instructions).*/
 void code_screen(); /*A screen to put in the secret code (which is shown on the flyer).*/

 void chill_mode (); /*Function for the "easy" difficulty.*/
 void normal_mode (); /*Function for the "normal" difficulty.*/
 void pain_mode (); /*Function for the "hard" difficulty.*/

 void machines(); /*Function for the creation of the washing machines*/
 void movement(); /*Function for the player movement and slowed interaction with laundry detergent.*/
 void piles(); /*Function for the actual spawn of the piles. (offscreen)*/
 void collisions(); /*Function for the collisions between the player and the laundry piles and people.*/
 void people(); /*Function for the actual spawn of the people. (offscreen)*/

 void updateFallingObject(float a); /*Keeps track of the falling detergent from the sky*/
 void drawFallingObject(); /*Draws the falling detergent.*/

 void score_keeping(float a); /*Tracks the score (This being the loads done, the number of loads done consectutively and number of misses.)*/
 void setDifficulty(std::string mode); /*Function for selected difficulty (chill will be slower and easier and so forth.).*/
};


/*The function that starts upon opening the game. It will keep running until the player quits*/
/*It starts by opening the main menu screen.*/
/*Written by Michael*/
int main() {
    Main_Menu g1; 
    g1.Main_Screen();
    while (1) {
        LCD.Update();
        //nnever end
    }
    return 0;
}

/*The function that creates the difficulty selection screen.*/
/*It starts by creating the the chill, normal, back, and code buttons and registering if the player clicks on any of the buttons.*/
/*It also displays the text to select difficulty.*/
/*Written by Michael*/
 void Main_Menu::play_button()
{
    
    float x,y,v,t;
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();
    LCD.SetFontColor (WHITE);
    LCD.WriteAt ("Select Difficulty",110,25);
    
    LCD.SetFontColor (WHITE);
    LCD.DrawRectangle (50,125,50,22);
    LCD.FillRectangle (50,125,50,22);
    LCD.SetFontColor (BLACK);
    LCD.WriteAt ("Chill",60,130);
    
    LCD.SetFontColor (WHITE);
    LCD.DrawRectangle (225,125,50,22);
    LCD.FillRectangle (225,125,50,22);
    LCD.SetFontColor (BLACK);
    LCD.WriteAt ("Normal",232,130);
    
    LCD.SetFontColor (WHITE);
    LCD.DrawRectangle (135,200,50,22);
    LCD.FillRectangle (135,200,50,22);
    LCD.SetFontScale(0.5);
    LCD.SetFontColor (BLACK);
    LCD.WriteAt ("Back",147,205);
    
    LCD.SetFontColor (WHITE);
    LCD.DrawRectangle (137,125,50,22);
    LCD.FillRectangle (137,125,50,22);
    LCD.SetFontColor (BLACK);
    LCD.WriteAt ("Code?",147,130);
   
    while(true)
    {
        while (!LCD.Touch(&x,&y)) {};
        while (LCD.Touch(&t,&v)) {};
        if((x >= 135 && x <= 185) && (y >= 200 && y <= 222))
            {
                Main_Screen();
            }
        if((x >= 50 && x <= 100) && (y >= 125 && y <= 147))
            {
                chill_mode();
                
            }
        if((x >= 225 && x <= 275) && (y >= 125 && y <= 147))
            {
                normal_mode();
            }
        if((x >= 137 && x <= 187) && (y >= 125 && y <= 147))
            {
                code_screen();
            }
}
}

/*The function that creates the code input screen.(as a joke it displays that there is no secret code)*/
/*It also creates a clickable keyboard that contains the letters of the alphabet and a enter key*/
/*Each letter has its own square and detection if the player clicks on the letters*/
/*It then checks if the code was inputted correctly or if it wasn't. If not it displays invalid code*/
/*Supposing the code was correct, then pain mode is activated (which is also printed to the LCD screen.)*/
/*Written by Michael, using AI for debugging*/
/*I'll admit AI did quite a bit of this part to get the code and spacing working correctly.*/
void Main_Menu::code_screen()
{
    LCD.Clear();
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("There is no code", 113, 20);

    char code[30] = "";
    int index = 0;

    // Keyboard keys (27 keys total)
    const char* keys[3][9] = {
        {"A","B","C","D","E","F","G","H","I"},
        {"J","K","L","M","N","O","P","Q","R"},
        {"S","T","U","V","W","X","Y","Z","OK"}
    };

    // Sizes
    int keyW = 32; 
    int keyH = 30;
    int spacing = 3;

    int startX = 5;
    int startY = 80;

    while (true)
    {
       /*Draws the input box*/
        LCD.SetFontColor(WHITE);
        LCD.DrawRectangle(10, 45, 300, 25);
        LCD.WriteAt(code, 15, 50);


        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                int x = startX + c * (keyW + spacing);
                int y = startY + r * (keyH + spacing);

                LCD.SetFontColor(BLUE);
                LCD.DrawRectangle(x, y, keyW, keyH);
                LCD.WriteAt(keys[r][c], x + 8, y + 5);
            }
        }

    
        float tx, ty, tt, tv;
        while (!LCD.Touch(&tx, &ty)) {}
        while (LCD.Touch(&tt, &tv)) {}

    
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                int x = startX + c * (keyW + spacing);
                int y = startY + r * (keyH + spacing);

                if (tx >= x && tx <= x + keyW &&
                    ty >= y && ty <= y + keyH)
                {
                    const char* key = keys[r][c];

                    
                    if (strcmp(key, "OK") == 0)
                    {
                        code[index] = '\0';

                        if (strcmp(code, "PAINTRAIN") == 0 ||
                            strcmp(code, "paintrain") == 0)
                        {
                            LCD.Clear();
                            LCD.SetFontColor(RED);
                            LCD.WriteAt("PAIN MODE ACTIVATED!", 100, 100);
                            Sleep(1.0);
                            pain_mode();
                            return;
                        }
                        else
                        {
                            LCD.Clear();
                            LCD.SetFontColor(RED);
                            LCD.WriteAt("INVALID CODE!", 120, 100);
                            Sleep(1.2);
                            play_button();
                            return;
                        }
                    }

                    /*Creates a null character*/
                    if (index < 29)
                    {
                        code[index++] = key[0];
                        code[index] = '\0';
                    }
                }
            }
        }

        /*Redraws the text for each frame.*/
        LCD.Clear();
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Enter Cheat Code:", 60, 20);
    }
}



/*The function that handles displaying how the player did in the game.*/
/*Resets the previous scores by clearing the screen*/
/*Then creates text for the number of loads done, the number of consectutive loads, and number of misses and prints to screen.*/
/*Then it creates two buttons, one of which goes back to main menu and the other goes to difficulty selection.*/
/*Also handles click detection for the buttons*/
/*Written by Faiza with AI debugging when needed.*/
void Main_Menu::stats_button()

{
    float x, y, t, v;
    int selected_button = 0;

    
    LCD.SetBackgroundColor(BLUE);
    LCD.Clear();

   
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("stats", 135, 20);

    
    LCD.SetFontScale(0.5);
    LCD.WriteAt("loads done:", 40, 70);
    LCD.WriteAt(loads, 200, 70);

    LCD.WriteAt("misses:", 40, 110);
    LCD.WriteAt(misses, 200, 110);

    LCD.WriteAt("highest streak:", 40, 150);
    LCD.WriteAt(loads_streak, 200, 150);

   
    while(true)
    {
        
        LCD.SetFontColor(WHITE);
        LCD.DrawRectangle(60, 190, 100, 25);
        LCD.FillRectangle(60, 190, 100, 25);

        LCD.DrawRectangle(180, 190, 80, 25);
        LCD.FillRectangle(180, 190, 80, 25);

        //draw labels on buttons
        LCD.SetFontColor(BLACK);
        LCD.SetFontScale(0.5);
        LCD.WriteAt("play again", 70, 197);
        LCD.WriteAt("quit", 205, 197);

        while (!LCD.Touch(&x,&y)) {};
        while (LCD.Touch(&t,&v)) {};
        if((x >= 60 && x <= 160) && (y >= 190 && y <= 215))
            {
                play_button();
            }
        if((x >= 180 && x <= 260) && (y >= 190 && y <= 215))
            {
                Main_Screen();
                
            }
        }
    }

/*The function that handles the credits screen*/
/*It displays the authors of this code and a button that allows the user to go back to the home screen*/
/*Also handles click detection for that button*/
/*Written by Michael*/
void Main_Menu::credits_button()
{
    float x,y,v,t;
    LCD.SetBackgroundColor(GREEN);
    LCD.Clear();
    LCD.SetFontColor (WHITE);
    LCD.WriteAt ("Game was made by:",110,50);
    LCD.SetFontColor (WHITE);
    LCD.WriteAt ("Faiza Choudhry and Michael Tang",70,100);
    
    LCD.SetFontColor (WHITE);
    LCD.DrawRectangle (135,200,50,22);
    LCD.FillRectangle (135,200,50,22);
    LCD.SetFontScale(0.5);
    LCD.SetFontColor (BLACK);
    LCD.WriteAt ("Back",147,205);
        while(true)
        {
            while (!LCD.Touch(&x,&y)) {};
            while (LCD.Touch(&t,&v)) {};
            if((x >= 135 && x <= 185) && (y >= 200 && y <= 222))
            {
                Main_Screen();
            }
        }
}

/*The function that creates the main menu.*/
/*It creates the buttons that the user can interact with and their click detection*/
/*Written by Michael*/
void Main_Menu :: Main_Screen ()
{
     float x,y,v,t;
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    LCD.SetFontColor (BLACK);
    LCD.DrawRectangle (40,128,50,22);
    LCD.FillRectangle (40,128,50,22);
    
    LCD.SetFontColor (BLACK);
    LCD.DrawRectangle (230,128,50,22);
    LCD.FillRectangle (230,128,50,22);
    
    LCD.SetFontColor (BLACK);
    LCD.DrawRectangle (40,172,50,22);
    LCD.FillRectangle (40,172,50,22);
    
    LCD.SetFontColor (BLACK);
    LCD.DrawRectangle (230,172,50,22);
    LCD.FillRectangle (230,172,50,22);
    
    LCD.SetFontScale(2);
    LCD.WriteAt ("DormDash",60,10);
    
    LCD.SetFontColor (WHITE);
    LCD.SetFontScale(0.5);
    LCD.WriteAt ("Play",53,133);
    
    LCD.SetFontColor (WHITE);
    LCD.SetFontScale (0.5);
    LCD.WriteAt ("Stats",49,177);
    
    LCD.SetFontColor (WHITE);
    LCD.SetFontScale (0.5);
    LCD.WriteAt ("Credits",233,133);
    
    LCD.SetFontColor (WHITE);
    LCD.SetFontScale (0.5);
    LCD.WriteAt ("Tutorial",230,177);
    
    while(true){
    while (!LCD.Touch(&x,&y)) {};
    while (LCD.Touch(&t,&v)) {};
    
    if((x >= 40 && x <= 90) && (y >= 128 && y <= 150))
        {
            play_button();
        }

    if((x >= 40 && x <= 90) && (y >= 172 && y <= 194))
        {
            stats_button();
        }

    if((x >= 230 && x <= 280) && (y >= 128 && y <= 150))
        {
            credits_button();
        }
    if((x >= 230 && x <= 280) && (y >= 172 && y <= 194))
        {        
            tutorial();
        }
    }
    while (1) {
        LCD.Update();
        //nnever end
    }
    
}
/*The function that creates the tutorial*/ 
/*Its difficulty is set to easy to ease the player into the game.*/
/*Sets the player onto the ground and resets the stats.*/
/*Draws the singular washing machine for the tutorial*/
/*Sets the spilled detergent's position and the condition to false (its not on the ground)*/
/*Sets up time variables for the falling detergent*/
/*Calls in the functions that makes the player move, obstacles function, collsion for the machine to complete the tutorial and display simple instructions*/
/*Finally when the user beat the tutorial, the get to see a screen that says they completed the tutorial*/
/*Finally if they click anywhere, they can move to the difficulty selection.*/
/*Written by Michael using AI to debug when needed.*/
void Main_Menu::tutorial()
{
    setDifficulty("chill");

    playerY = groundY - playerH;
    loads = 0;
    loads_streak = 0;
    misses = 0;


    const int NUM_TUTORIAL_MACHINES = 1;
    int tutorialMachineX[NUM_TUTORIAL_MACHINES] = { 278 };
    int tutorialMachineY[NUM_TUTORIAL_MACHINES] = { groundY - 43 };
    int tutorialMachineW = 37;
    int tutorialMachineH = 40;


    fallX = Random.RandInt() % 300 + 10;
    fallY = 10;
    fallLanded = false;
    fallTimer = 0.0f;

    float lastFrameTime = TimeNow();

    while (true)
    {
        float currentTime = TimeNow();
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        // Update player movement
        movement();

        // Update falling objects
        updateFallingObject(deltaTime);

        // Check collisions with piles and people
        collisions();

        // Move piles and people
        piles();
        people();

        //Check interaction with the tutorial machine
        bool touching = 
            !(playerX + playerW < tutorialMachineX[0] ||
              tutorialMachineX[0] + tutorialMachineW < playerX ||
              playerY + playerH < tutorialMachineY[0] ||
              tutorialMachineY[0] + tutorialMachineH < playerY);

        if (touching && Keyboard.isPressed(KEY_SPACE))
        {
            // Tutorial complete
            LCD.Clear();
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Laundry Done!", 80, 90);
            LCD.WriteAt("Tutorial Complete!", 60, 130);

            // Wait for user touch to continue
            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            play_button();
            return;
        }

        //Draw frame with art
        LCD.Clear();
        //draw background laundry room art
        bg_img.Draw(0, 0);
        LCD.SetFontColor(BLACK);
        LCD.SetFontScale(0.5);

        // Instructions
        LCD.WriteAt("Tutorial: Use arrow keys to move!", 110, 10);
        LCD.WriteAt("Press SPACE to interact with machine!", 90, 25);

        // Ground line on top of background
        LCD.DrawLine(0, groundY, 320, groundY);

        // Draw player as character sprite
        student_img.Draw(playerX, playerY - 10);

        // Draw tutorial machine as rectangle in front of background
        LCD.SetFontColor(RED);
        LCD.DrawRectangle(tutorialMachineX[0], tutorialMachineY[0], tutorialMachineW, tutorialMachineH);

        // Draw piles as laundry art
        for (int i = 0; i < NUM_PILES; i++)
        {
            pile_img.Draw(pileX[i], pileY[i] - pileH);
        }

        // Draw people as students
        for (int i = 0; i < NUM_Person; i++)
        {
            student_img.Draw(PersonX[i], PersonY[i] - 10);
        }

        // Draw falling detergent art
        drawFallingObject();

        LCD.Update();
    }
}

/*A constructor that intializes spawn loactions for the laundry piles, people, and the spilled detergent. */
/*Written by Michael using AI to debug when overhauls created bugs.*/
Main_Menu::Main_Menu()
{
    
    for (int i = 0; i < NUM_PILES; i++)
    {
        pileX[i] = 320 + 80 * i;
        pileY[i] = groundY - pileH;
    }

    for (int i = 0; i < NUM_Person; i++)
    {
        PersonX[i] = -80 * i;
        PersonY[i] = groundY - personH;
    }
    fallX = Random.RandInt() % 300 + 10; // random X
    fallY = 10;                         // start offscreen
    fallLanded = false;
    fallTimer = 0.0f;
    activeMachine = Random.RandInt() % 8;
    machineTimer = 0.0f;

    //load art images from sd card / project folder for gameplay visuals
    //filenames must match these .png names exactly
    bg_img.Open("laundry_bg.png");
    pile_img.Open("laundry_pile.png");
    splash_img.Open("splash.png");
    student_img.Open("student.png");
}

/*A function to create the washing machines (their position and actually drawing them) in the actual game modes.*/
/*Written by Faiza.*/
void Main_Menu::machines()
{

    int groundY = 200;

    int machineX[] = {278, 278, 237, 237, 7, 7, 47, 47};
    int machineY[] = {groundY - 43, groundY - 83,
                      groundY - 43, groundY - 83,
                      groundY - 43, groundY - 83,
                      groundY - 43, groundY - 83};

    int machineW = 37;
    int machineH = 40;

    for (int i = 0; i < 8; i++)
    {
        LCD.DrawRectangle(machineX[i], machineY[i], machineW, machineH);
    }
}
/*The function that controlls the player's movement and slowed when in the detergent obstacle.*/
/*Written by Faiza using AI to debug when needed.*/
void Main_Menu::movement()
{
    float speed = playerSpeed;
    float jumpM = jumpMultiplier;

   
    if (fallLanded)
    {
        int rectX = fallX - fallRectW / 2;
        int rectY = fallY;

        bool touching =
            !(playerX + playerW < rectX ||
              rectX + fallRectW < playerX ||
              playerY + playerH < rectY ||
              rectY + fallRectH < playerY);

        if (touching)
        {
            speed *= 0.5f;
            jumpM *= 0.6f;
        }
    }

   
    if (Keyboard.isPressed(KEY_RIGHT) && playerX + playerW < 320)
        playerX += speed;

    if (Keyboard.isPressed(KEY_LEFT) && playerX > 0)
        playerX -= speed;

  
    if (Keyboard.isPressed(KEY_UP) && !inAir)
    {
        inAir = true;
        velocityY = jumpStrength * jumpM;
    }

    if (inAir)
    {
        velocityY += gravity;
        playerY += velocityY;

        if (playerY >= groundY - playerH)
        {
            playerY = groundY - playerH;
            inAir = false;
            velocityY = 0;
        }
    }
}

/*A function that determines where the laundry piles spawn */
/*Written by Michael using AI to debug when needed.*/
void Main_Menu::piles()
{
    for (int i = 0; i < numPiles; i++)
    {
        pileX[i] -= pileSpeed;

        if (pileX[i] + pileW < 0)
            pileX[i] = 320 + (Random.RandInt() % 150);
    }
}
/*The function that handles the player colliding with the laundry piles and people.*/
/*Written by Faiza using AI to debug when needed.*/
void Main_Menu::collisions()
{
    for (int i = 0; i < NUM_PILES; i++)
    {
        bool overlap =
            !(playerX + playerW < pileX[i] ||
              pileX[i] + pileW < playerX ||
              playerY + playerH < pileY[i] ||
              pileY[i] + pileH < playerY);

        if (overlap)
        {
            playerX -= 20;
            if (playerX < 0) playerX = 0;
        }
    }
    for (int i = 0; i < NUM_Person; i++)
    {
        bool overlap =
            !(playerX + playerW < PersonX[i] ||
              PersonX[i] + personW < playerX ||
              playerY + playerH < PersonY[i] ||
              PersonY[i] + personH < playerY);

        if (overlap)
        {
            playerX += 20;
            if (playerX > 320) playerX = 320;
        }
    }
}

/*A function that determines where the people spawn*/
/*Written by Michael using AI to debug when needed.*/
void Main_Menu::people()
{
    for (int i = 0; i < numPeople; i++)
    {
        PersonX[i] += personSpeed;

        if (PersonX[i] > 320)
            PersonX[i] = - (Random.RandInt() % 150);
    }
}


/*The function that handles the falling, landing, and clearing with respawning the spilled detergent obstacle.*/
/*Written by Michael using AI to debug when needed.*/
void Main_Menu::updateFallingObject(float deltaTime)
{
    if (!fallLanded)
    {
        //falling circle
        fallY += fallSpeed;

        //ground collision: turn into rectangle area on floor
        if (fallY + fallR >= groundY)
        {
            fallLanded = true;
            fallY = groundY - fallRectH;  
            fallTimer = 0.0f;            
        }
    }
    else
    {
       
        fallTimer += deltaTime;

        if (fallTimer >= 4.0f) 
        {
            //reset position and state for next spill
            fallX = Random.RandInt() % 300 + 10; 
            fallY = 10;                         
            fallLanded = false;
            fallTimer = 0.0f;
        }
    }
}

/*The function that handles drawing the spilled launrdry detergent when falling and landed.*/
/*Now uses splash art when it is on the floor.*/
/*Written by Michael using AI to debug when needed and art added with AI help.*/
void Main_Menu::drawFallingObject()
{
    if (!fallLanded)
    {
        //while falling, show a simple circle so player sees it coming down
        LCD.SetFontColor(BLACK);
        LCD.DrawCircle(fallX, fallY, fallR);
    }
    else
    {
        //when it lands, draw the splash image at the spill location
        splash_img.Draw(fallX - fallRectW/2, fallY - 10);
    }
}


/*The function that handles keeping track of the player's score */
/*It checks if the player reached to a machine on time or if they missed it.*/
/*It then updates the loads, load streak, and misses accordingly*/
/*Also handles the selection of a "open" machine by random and close it after a certain time.*/
/*The active machine is drawn as a filled red rectangle so it stands out on the background art.*/
/*Written by Faiza using AI to debug when needed.*/
void Main_Menu::score_keeping(float deltaTime)
{
    const int NUM_MACHINES = 8;
    int machineX[] = {278, 278, 237, 237, 7, 7, 47, 47};
    int machineY[] = {groundY - 43, groundY - 83,
                      groundY - 43, groundY - 83,
                      groundY - 43, groundY - 83,
                      groundY - 43, groundY - 83};

    int machineW = 37;
    int machineH = 40;

    machineTimer += deltaTime;

 
    bool touching =
        !(playerX + playerW < machineX[activeMachine] ||
          machineX[activeMachine] + machineW < playerX ||
          playerY + playerH < machineY[activeMachine] ||
          machineY[activeMachine] + machineH < playerY);

    if (touching && Keyboard.isPressed(KEY_SPACE))
    {
        loads++;
        loads_streak++;
        activeMachine = Random.RandInt() % NUM_MACHINES; 
        machineTimer = 0.0f;
    }


    if (machineTimer >= machineDuration)
    {
        misses++;
        loads_streak = 0;
        activeMachine = Random.RandInt() % NUM_MACHINES;
        machineTimer = 0.0f;
    }

    //draw machines over the background so the active one is clear
    for (int i = 0; i < NUM_MACHINES; i++)
    {
        if (i == activeMachine)
        {
            LCD.SetFontColor(RED);
            LCD.DrawRectangle(machineX[i], machineY[i], machineW, machineH);
        }
        else
        {
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(machineX[i], machineY[i], machineW, machineH);
        }
    }
}



/*This is the difficutly module that all of the gameplay functions will use*/
/*It sets everything from player movement (small tweaks), to how fast the people and laundry piles move.*/
/*This also edits how long you have to reach a machine, and how many people and laundry piles spawn at once.*/
/*Written by Michael using AI to debug when needed.*/
void Main_Menu::setDifficulty(std::string mode)
{
    if (mode == "chill") {
        playerSpeed = 3.0f;
        jumpMultiplier = 1.0f;
        pileSpeed = 2.0f;
        personSpeed = 1.0f;
        machineDuration = 5.0f;
        numPiles = 2;
        numPeople = 1;


    } else if (mode == "normal") {
        playerSpeed = 4.0f;
        jumpMultiplier = 0.9f;
        pileSpeed = 3.0f;
        personSpeed = 2.0f;
        machineDuration = 4.0f;
        numPiles = 3;
        numPeople = 2;


    } else if (mode == "pain") {
        playerSpeed = 5.0f;
        jumpMultiplier = 0.8f;
        pileSpeed = 4.0f;
        personSpeed = 3.0f;
        machineDuration = 3.0f;
        numPiles = 4;
        numPeople = 3;
    }
}



/*The function that handles the easy gamemode.*/
/*It calls in the functions required for movement, obstacles, scorekeeping, and washing machines.*/
/*It ends in three minutes and has a builtin score keeper.*/
/*Written by Faiza using AI to debug when needed.*/
void Main_Menu::chill_mode()
{
    setDifficulty("chill");
    loads=0, loads_streak=0, misses=0;
    playerY = groundY - playerH;
    

    float levelTime = 180.0f;
    float startTime = TimeNow();

    // Initialize piles
    for (int i = 0; i < NUM_PILES; i++)
    {
        pileX[i] = 320 + 40 * i + (Random.RandInt() % 40);
        pileY[i] = groundY - pileH;
    }

    float lastFrameTime = TimeNow();

    while (true)
    {
        //Timing 
        float currentTime = TimeNow();
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        float elapsed = currentTime - startTime;
        float remaining = levelTime - elapsed;
        if (remaining <= 0)
        {
            LCD.Clear();
            LCD.SetFontColor(WHITE);
            LCD.WriteAt("Time's up!", 110, 90);
            LCD.WriteAt("Chill Mode Complete", 100, 130);
            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            stats_button();
            return;
        }

        //Update game state 
        movement();
        updateFallingObject(deltaTime);
        collisions();
        piles();
        people();

        //Draw everything with art 
        LCD.Clear();
        //draw background art first
        bg_img.Draw(0, 0);
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);

        //player sprite
        student_img.Draw(playerX, playerY - 10);

        // Draw piles as art
        for (int i = 0; i < NUM_PILES; i++)
        {
            pile_img.Draw(pileX[i], pileY[i] - pileH);
        }

        // Draw people as other students
        for (int i = 0; i < NUM_Person; i++)
        {
            student_img.Draw(PersonX[i], PersonY[i] - 10);
        }

        //draw machines and update loads/misses/streak
        score_keeping(deltaTime);

        // Draw falling object
        drawFallingObject();

        // Draw HUD
        LCD.SetFontScale(0.5);
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("loads done:", 40, 10);
        LCD.WriteAt(loads, 200, 10);
        LCD.WriteAt("misses:", 40, 25);
        LCD.WriteAt(misses, 200, 25);
        LCD.WriteAt("streak:", 40, 40);
        LCD.WriteAt(loads_streak, 200, 40);
        LCD.WriteAt("Time left:", 40, 55);
        LCD.WriteAt((int)remaining, 200, 55);

        LCD.Update();
    }
}

/*The function that handles the normal gamemode.*/
/*It calls in the functions required for movement, obstacles, scorekeeping, and washing machines.*/
/*It ends in two minutes and has a builtin score keeper.*/
/*Written by Michael using AI to debug when needed.*/
void Main_Menu::normal_mode()
{
    setDifficulty("normal");
    loads=0, loads_streak=0, misses=0;
    playerY = groundY - playerH;
    

    float levelTime = 120.0f;
    float startTime = TimeNow();

    // Initialize piles
    for (int i = 0; i < NUM_PILES; i++)
    {
        pileX[i] = 320 + 40 * i + (Random.RandInt() % 40);
        pileY[i] = groundY - pileH;
    }

    float lastFrameTime = TimeNow();

    while (true)
    {
        //Timing 
        float currentTime = TimeNow();
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        float elapsed = currentTime - startTime;
        float remaining = levelTime - elapsed;
        if (remaining <= 0)
        {
            LCD.Clear();
            LCD.SetFontColor(WHITE);
            LCD.WriteAt("Time's up!", 110, 90);
            LCD.WriteAt("Normal Mode Complete", 100, 130);
            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            stats_button();
            return;
        }

        movement();
        updateFallingObject(deltaTime);
        collisions();
        piles();
        people();

        //Draw everything with art 
        LCD.Clear();
        bg_img.Draw(0, 0);
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);

        student_img.Draw(playerX, playerY - 10);

        for (int i = 0; i < NUM_PILES; i++)
        {
            pile_img.Draw(pileX[i], pileY[i] - pileH);
        }

        for (int i = 0; i < NUM_Person; i++)
        {
            student_img.Draw(PersonX[i], PersonY[i] - 10);
        }

        score_keeping(deltaTime);

        drawFallingObject();

        LCD.SetFontScale(0.5);
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("loads done:", 40, 10);
        LCD.WriteAt(loads, 200, 10);
        LCD.WriteAt("misses:", 40, 25);
        LCD.WriteAt(misses, 200, 25);
        LCD.WriteAt("streak:", 40, 40);
        LCD.WriteAt(loads_streak, 200, 40);
        LCD.WriteAt("Time left:", 40, 55);
        LCD.WriteAt((int)remaining, 200, 55);

        LCD.Update();
    }
}


/*The function that handles the hard gamemode.*/
/*It calls in the functions required for movement, obstacles, scorekeeping, and washing machines.*/
/*It ends in one minutes and has a builtin score keeper.*/
/*Written by Michael using AI to debug when needed.*/
void Main_Menu::pain_mode()
{
    setDifficulty("pain");
    loads=0, loads_streak=0, misses=0;
    playerY = groundY - playerH;
    

    float levelTime = 60.0f;
    float startTime = TimeNow();

    //Initialize piles
    for (int i = 0; i < NUM_PILES; i++)
    {
        pileX[i] = 320 + 40 * i + (Random.RandInt() % 40);
        pileY[i] = groundY - pileH;
    }

    float lastFrameTime = TimeNow();

    while (true)
    {
        //Timing 
        float currentTime = TimeNow();
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        float elapsed = currentTime - startTime;
        float remaining = levelTime - elapsed;
        if (remaining <= 0)
        {
            LCD.Clear();
            LCD.SetFontColor(WHITE);
            LCD.WriteAt("Time's up!", 110, 90);
            LCD.WriteAt("Pain Complete", 100, 130);
            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            stats_button();
            return;
        }

        //Update game state
        movement();
        updateFallingObject(deltaTime);
        collisions();
        piles();
        people();

        //Draw everything with art
        LCD.Clear();
        bg_img.Draw(0, 0);
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);

        student_img.Draw(playerX, playerY - 10);

        for (int i = 0; i < NUM_PILES; i++)
        {
            pile_img.Draw(pileX[i], pileY[i] - pileH);
        }

        for (int i = 0; i < NUM_Person; i++)
        {
            student_img.Draw(PersonX[i], PersonY[i] - 10);
        }

        score_keeping(deltaTime);

        drawFallingObject();

        LCD.SetFontScale(0.5);
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("loads done:", 40, 10);
        LCD.WriteAt(loads, 200, 10);
        LCD.WriteAt("misses:", 40, 25);
        LCD.WriteAt(misses, 200, 25);
        LCD.WriteAt("streak:", 40, 40);
        LCD.WriteAt(loads_streak, 200, 40);
        LCD.WriteAt("Time left:", 40, 55);
        LCD.WriteAt((int)remaining, 200, 55);

        LCD.Update();
    }
}