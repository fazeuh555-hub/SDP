#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHKeyboard.h"
#include "FEHRandom.h"


class Main_Menu
{
private:
        int loads=0, loads_streak=0, misses=0;
        float velocityY = 0.0f;
        float gravity = 0.4f;
        float jumpStrength = -7.0f;
        int playerX = 40;
        int playerY;
        int playerW = 14;
        int playerH = 18;
        int groundY = 200;
        bool inAir = false;
        int pileW = 20;
        int pileH = 12;
        static const int NUM_PILES = 6;
        static const int NUM_Person = 4;
        int machineX = 270;
        int machineY = groundY - 40;
        int machineW = 30;
        int machineH = 40;
        int pileX[NUM_PILES];
        int pileY[NUM_PILES];
        int personW = 12;
        int personH = 20;
        int PersonX[NUM_Person];
        int PersonY[NUM_Person];
        // Falling object
        int fallX;          // x position
        int fallY;          // y position
        int fallR = 8;      // circle radius
        bool fallLanded;    // true when turned into rectangle
        int fallSpeed = 2;  // falling speed
        // Rectangle after landing
        int fallRectW = 50;
        int fallRectH = 7;
        float fallTimer;        // counts how long rectangle has been on the ground
        float fallDuration = 3;
        int activeMachine;
        float machineTimer;
        // --- Difficulty parameters ---
        float playerSpeed;
        float jumpMultiplier;
        float pileSpeed;
        float personSpeed;
        float machineDuration;
        int numPiles;
        int numPeople;
        

        
  
public:
 void play_button();
 void stats_button();
 void credits_button();
 void Main_Screen ();
 void chill_mode ();
 void normal_mode ();
 void pain_mode ();
 void tutorial ();
 void machines();
 void movement();
 void piles();
 void collisions();
 Main_Menu();
void people();
void updateFallingObject(float a);
void drawFallingObject();
void score_keeping(float a);
void setDifficulty(std::string mode);
void code_screen();
};



int main() {
    float x,y,v,t;
    Main_Menu g1; 
    g1.Main_Screen();
    while (1) {
        LCD.Update();
        //nnever end
    }
    return 0;
}

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
        // Draw input box
        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(10, 45, 300, 25);
        LCD.WriteAt(code, 15, 50);

        // Draw keyboard
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

        // Wait for touch
        float tx, ty, tt, tv;
        while (!LCD.Touch(&tx, &ty)) {}
        while (LCD.Touch(&tt, &tv)) {}

        // Check which key was pressed
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

                    // --- OK pressed ---
                    if (strcmp(key, "OK") == 0)
                    {
                        code[index] = '\0';

                        if (strcmp(code, "PAINTRAIN") == 0 ||
                            strcmp(code, "paintrain") == 0)
                        {
                            LCD.Clear();
                            LCD.SetFontColor(RED);
                            LCD.WriteAt("PAIN MODE ACTIVATED!", 20, 100);
                            Sleep(1.0);
                            pain_mode();
                            return;
                        }
                        else
                        {
                            LCD.Clear();
                            LCD.SetFontColor(BLACK);
                            LCD.WriteAt("INVALID CODE!", 90, 100);
                            Sleep(1.2);
                            play_button();
                            return;
                        }
                    }

                    // --- Letter pressed ---
                    if (index < 29)
                    {
                        code[index++] = key[0];
                        code[index] = '\0';
                    }
                }
            }
        }

        // Redraw background for next frame
        LCD.Clear();
        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Enter Cheat Code:", 60, 20);
    }
}




void Main_Menu::stats_button()
{
    float x, y, t, v;
    int selected_button = 0;

    //set the stats screen background and clear any previous frame
    LCD.SetBackgroundColor(BLUE);
    LCD.Clear();

    //draw the title
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("stats", 135, 20);

    //draw the text labels and values
    LCD.SetFontScale(0.5);
    LCD.WriteAt("loads done:", 40, 70);
    LCD.WriteAt(loads, 200, 70);

    LCD.WriteAt("misses:", 40, 110);
    LCD.WriteAt(misses, 200, 110);

    LCD.WriteAt("highest streak:", 40, 150);
    LCD.WriteAt(loads_streak, 200, 150);

   
    while(true)
    {
        //clear the button area each frame
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
 
void Main_Menu::tutorial()
{
    setDifficulty("chill");
    // Set player on the ground
    playerY = groundY - playerH;
    loads = 0;
    loads_streak = 0;
    misses = 0;

    // Tutorial uses only 1 machine
    const int NUM_TUTORIAL_MACHINES = 1;
    int tutorialMachineX[NUM_TUTORIAL_MACHINES] = { 270 };
    int tutorialMachineY[NUM_TUTORIAL_MACHINES] = { groundY - 40 };
    int tutorialMachineW = 30;
    int tutorialMachineH = 40;

    // Reset falling object
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

        // --- Check interaction with the tutorial machine ---
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

        // --- Draw frame ---
        LCD.Clear();
        LCD.SetBackgroundColor(WHITE);
        LCD.SetFontColor(BLACK);
        LCD.SetFontScale(0.5);

        // Instructions
        LCD.WriteAt("Tutorial: Use arrow keys to move!", 10, 10);
        LCD.WriteAt("Press SPACE to interact with machine!", 10, 25);

        // Ground
        LCD.DrawLine(0, groundY, 320, groundY);

        // Draw player
        LCD.FillRectangle(playerX, playerY, playerW, playerH);

        // Draw tutorial machine
        LCD.FillRectangle(tutorialMachineX[0], tutorialMachineY[0], tutorialMachineW, tutorialMachineH);

        // Draw piles
        for (int i = 0; i < NUM_PILES; i++)
        {
            LCD.FillRectangle(pileX[i], pileY[i], pileW, pileH);
        }

        // Draw people
        for (int i = 0; i < NUM_Person; i++)
        {
            LCD.FillRectangle(PersonX[i], PersonY[i], personW, personH);
        }

        // Draw falling object
        drawFallingObject();

        LCD.Update();
    }
}


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
}

void Main_Menu::machines()
{

    int groundY = 200;

    int machineX[] = {270, 270, 240, 240, 30, 30, 60, 60};
    int machineY[] = {groundY - 40, groundY - 80,
                      groundY - 40, groundY - 80,
                      groundY - 40, groundY - 80,
                      groundY - 40, groundY - 80};

    int machineW = 30;
    int machineH = 40;

    for (int i = 0; i < 8; i++)
    {
        LCD.DrawRectangle(machineX[i], machineY[i], machineW, machineH);
    }
}

void Main_Menu::movement()
{
    float speed = playerSpeed;
    float jumpM = jumpMultiplier;

    // Slowdown on rectangle
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

    // Left/Right
    if (Keyboard.isPressed(KEY_RIGHT) && playerX + playerW < 320)
        playerX += speed;

    if (Keyboard.isPressed(KEY_LEFT) && playerX > 0)
        playerX -= speed;

    // Jump
    if (Keyboard.isPressed(KEY_UP) && !inAir)
    {
        inAir = true;
        velocityY = jumpStrength * jumpM;
    }

    // Gravity stuff (unchanged)
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


void Main_Menu::piles()
{
    for (int i = 0; i < numPiles; i++)
    {
        pileX[i] -= pileSpeed;

        if (pileX[i] + pileW < 0)
            pileX[i] = 320 + (Random.RandInt() % 150);
    }
}


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

void Main_Menu::people()
{
    for (int i = 0; i < numPeople; i++)
    {
        PersonX[i] += personSpeed;

        if (PersonX[i] > 320)
            PersonX[i] = - (Random.RandInt() % 150);
    }
}


void Main_Menu::updateFallingObject(float deltaTime)
{
    if (!fallLanded)
    {
        // falling circle
        fallY += fallSpeed;

        // ground collision: turn into rectangle
        if (fallY + fallR >= groundY)
        {
            fallLanded = true;
            fallY = groundY - fallRectH;  // snap rectangle to ground
            fallTimer = 0.0f;             // start timer
        }
    }
    else
    {
        // rectangle timer
        fallTimer += deltaTime;

        if (fallTimer >= 4.0f) // 4 seconds duration
        {
            // respawn a new circle at the top
            fallX = Random.RandInt() % 300 + 10; // random X
            fallY = 10;                         // start above screen
            fallLanded = false;
            fallTimer = 0.0f;
        }
    }
}

void Main_Menu::drawFallingObject()
{
    LCD.SetFontColor(BLACK);

    if (!fallLanded)
    {
        // draw the falling circle
        LCD.DrawCircle(fallX, fallY, fallR);
    }
    else
    {
        // draw rectangle after landing
        LCD.FillRectangle(fallX - fallRectW/2, fallY, fallRectW, fallRectH);
    }
}

void Main_Menu::score_keeping(float deltaTime)
{
    const int NUM_MACHINES = 8;
    int machineX[NUM_MACHINES] = { 270, 270, 240, 240, 30, 30, 60, 60 };
    int machineY[NUM_MACHINES] = { groundY - 40, groundY - 80,
                                   groundY - 40, groundY - 80,
                                   groundY - 40, groundY - 80,
                                   groundY - 40, groundY - 80 };
    int machineW = 30;
    int machineH = 40;

    // --- Update timer ---
    machineTimer += deltaTime;

    // --- Check if player interacted with active machine ---
    bool touching =
        !(playerX + playerW < machineX[activeMachine] ||
          machineX[activeMachine] + machineW < playerX ||
          playerY + playerH < machineY[activeMachine] ||
          machineY[activeMachine] + machineH < playerY);

    if (touching && Keyboard.isPressed(KEY_SPACE))
    {
        loads++;
        loads_streak++;
        activeMachine = Random.RandInt() % NUM_MACHINES; // pick new machine
        machineTimer = 0.0f;
    }

    // --- Timer expires without interaction ---
    if (machineTimer >= machineDuration)
    {
        misses++;
        loads_streak = 0;
        activeMachine = Random.RandInt() % NUM_MACHINES;
        machineTimer = 0.0f;
    }

    // --- Draw machines ---
    for (int i = 0; i < NUM_MACHINES; i++)
    {
        if (i == activeMachine)
        {
            LCD.SetFontColor(RED);
            LCD.FillRectangle(machineX[i], machineY[i], machineW, machineH);
        }
        else
        {
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(machineX[i], machineY[i], machineW, machineH);
        }
    }
}

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
        // --- Timing ---
        float currentTime = TimeNow();
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        float elapsed = currentTime - startTime;
        float remaining = levelTime - elapsed;
        if (remaining <= 0)
        {
            LCD.Clear();
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Time's up!", 110, 90);
            LCD.WriteAt("Chill Mode Complete", 100, 130);
            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            stats_button();
            return;
        }

       

        // --- Update game state ---
        movement();
        updateFallingObject(deltaTime);
        collisions();
        piles();
        people();

        

        // --- Draw everything ---
        LCD.Clear();
        LCD.SetBackgroundColor(WHITE);
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);
        LCD.FillRectangle(playerX, playerY, playerW, playerH);

        // Draw piles
        for (int i = 0; i < NUM_PILES; i++)
        {
            LCD.FillRectangle(pileX[i], pileY[i], pileW, pileH);
        }

        // Draw people
        for (int i = 0; i < NUM_Person; i++)
        {
            LCD.FillRectangle(PersonX[i], PersonY[i], personW, personH);
        }

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
        // --- Timing ---
        float currentTime = TimeNow();
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        float elapsed = currentTime - startTime;
        float remaining = levelTime - elapsed;
        if (remaining <= 0)
        {
            LCD.Clear();
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Time's up!", 110, 90);
            LCD.WriteAt("Normal Mode Complete", 100, 130);
            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            stats_button();
            return;
        }

       

        // --- Update game state ---
        movement();
        updateFallingObject(deltaTime);
        collisions();
        piles();
        people();

        

        // --- Draw everything ---
        LCD.Clear();
        LCD.SetBackgroundColor(WHITE);
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);
        LCD.FillRectangle(playerX, playerY, playerW, playerH);

        // Draw piles
        for (int i = 0; i < NUM_PILES; i++)
        {
            LCD.FillRectangle(pileX[i], pileY[i], pileW, pileH);
        }

        // Draw people
        for (int i = 0; i < NUM_Person; i++)
        {
            LCD.FillRectangle(PersonX[i], PersonY[i], personW, personH);
        }

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

void Main_Menu::pain_mode()
{
    setDifficulty("pain");
    loads=0, loads_streak=0, misses=0;
    playerY = groundY - playerH;
    

    float levelTime = 60.0f;
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
        // --- Timing ---
        float currentTime = TimeNow();
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        float elapsed = currentTime - startTime;
        float remaining = levelTime - elapsed;
        if (remaining <= 0)
        {
            LCD.Clear();
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Time's up!", 110, 90);
            LCD.WriteAt("Pain Complete", 100, 130);
            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            stats_button();
            return;
        }

       

        // --- Update game state ---
        movement();
        updateFallingObject(deltaTime);
        collisions();
        piles();
        people();

        

        // --- Draw everything ---
        LCD.Clear();
        LCD.SetBackgroundColor(WHITE);
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);
        LCD.FillRectangle(playerX, playerY, playerW, playerH);

        // Draw piles
        for (int i = 0; i < NUM_PILES; i++)
        {
            LCD.FillRectangle(pileX[i], pileY[i], pileW, pileH);
        }

        // Draw people
        for (int i = 0; i < NUM_Person; i++)
        {
            LCD.FillRectangle(PersonX[i], PersonY[i], personW, personH);
        }

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
