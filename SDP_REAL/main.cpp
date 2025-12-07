#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHKeyboard.h"
#include "FEHRandom.h"


class Main_Menu
{
private:
        int loads=0, loads_streak, misses;
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
        static const int NUM_PILES = 2;
        int machineX = 270;
        int machineY = groundY - 40;
        int machineW = 30;
        int machineH = 40;
        int pileX[NUM_PILES];
        int pileY[NUM_PILES];
        int personW = 12;
        int personH = 20;
        static const int NUM_Person = 1;
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
}
;



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
    Main_Menu g1;
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
    while(true)
    {
        while (!LCD.Touch(&x,&y)) {};
        while (LCD.Touch(&t,&v)) {};
        if((x >= 135 && x <= 185) && (y >= 200 && y <= 222))
            {
                g1.Main_Screen();
            }
        if((x >= 50 && x <= 100) && (y >= 125 && y <= 147))
            {
                g1.chill_mode();
                
            }
        if((x >= 225 && x <= 275) && (y >= 125 && y <= 147))
            {
                g1.normal_mode();
            }
}
}


void Main_Menu::stats_button()
{
    Main_Menu g1;
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
                g1.play_button();
            }
        if((x >= 180 && x <= 260) && (y >= 190 && y <= 215))
            {
                g1.Main_Screen();
                
            }
        }
    }


void Main_Menu::credits_button()
{
    Main_Menu g1;
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
                g1.Main_Screen();
            }
    }

}


void Main_Menu :: Main_Screen ()
{
     float x,y,v,t;
    Main_Menu g1; 
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
            g1.play_button();
        }

    if((x >= 40 && x <= 90) && (y >= 172 && y <= 194))
        {
            g1.stats_button();
        }

    if((x >= 230 && x <= 280) && (y >= 128 && y <= 150))
        {
            g1.credits_button();
        }
    if((x >= 230 && x <= 280) && (y >= 172 && y <= 194))
        {        
            g1.tutorial();
        }
    }
    while (1) {
        LCD.Update();
        //nnever end
    }
    
}
 
void Main_Menu::tutorial()
{
    Main_Menu g1;
    playerY = groundY - playerH;
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();

    float lastFrameTime = TimeNow(); // initialize once

    while (true)
    {
        float currentTime = TimeNow();
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime; // update for next frame

        movement();
        updateFallingObject(deltaTime);
        collisions();
        piles();
        people();   
        bool touching =
            !(playerX + playerW < machineX ||
              machineX + machineW < playerX ||
              playerY + playerH < machineY ||
              machineY + machineH < playerY);

        if (touching && Keyboard.isPressed(KEY_SPACE))
        {
            LCD.Clear();
            LCD.SetFontColor(BLACK);
            LCD.WriteAt("Laundry Done!", 80, 90);
            LCD.WriteAt("Tutorial Complete!", 60, 130);

            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            g1.play_button();
            return;
        }

        LCD.Clear();
        LCD.SetFontColor(BLACK);
        LCD.SetFontScale(0.5);
        LCD.WriteAt("Tutorial: Try using up,left, and right to move!",10,10); 
        LCD.WriteAt("Use the spacebar to interact with washing machine!",10,25);
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);
        drawFallingObject();
        LCD.FillRectangle(playerX, playerY, playerW, playerH);
        LCD.DrawRectangle(machineX, machineY, machineW, machineH);
          // draw piles
    for (int i = 0; i < NUM_PILES; i++)
    {
        LCD.FillRectangle(pileX[i], pileY[i], pileW, pileH);
    }
    for (int i = 0; i < NUM_Person; i++)
    {
        LCD.FillRectangle(PersonX[i], PersonY[i], personW, personH);
    }
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
    float speed = 3.0f;
    float jumpMultiplier = 1.0f;  // full jump by default

    // Check if player is touching the fallen rectangle
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
            speed *= 0.5f;        // move slower
            jumpMultiplier = 0.6f; // jump lower (60% of normal jump)
        }
    }

    // Horizontal movement
    if (Keyboard.isPressed(KEY_RIGHT) && playerX + playerW < 320)
        playerX += (int)speed;
    if (Keyboard.isPressed(KEY_LEFT) && playerX > 0)
        playerX -= (int)speed;

    // Jump
    if (Keyboard.isPressed(KEY_UP) && !inAir)
    {
        inAir = true;
        velocityY = jumpStrength * jumpMultiplier; // apply reduced jump if needed
    }

    // Apply gravity
    if (inAir)
    {
        velocityY += gravity;
        playerY += (int)velocityY;

        // Ground collision
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
    // move piles left
    for (int i = 0; i < NUM_PILES; i++)
    {
        pileX[i] -= 2;

        // if off screen, respawn far right
        if (pileX[i] + pileW < 0)
        {
            pileX[i] = 320 + (Random.RandInt() % 150);
        }
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
    // move people right
    for (int i = 0; i < NUM_Person; i++)
    {
        PersonX[i] += 1;

        // if off right edge, respawn far left
        if (PersonX[i] > 320)
        {
            PersonX[i] = 0 - (Random.RandInt() % 150);
        }
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



void Main_Menu :: chill_mode () 
{
{
    Main_Menu g1;
    playerY = groundY - playerH;
    const int NUM_MACHINES = 8;

int machineX[NUM_MACHINES] = {
    270, 270,       // right column
    240, 240,       // right column left
    30, 30,         // far left
    60, 60          // near left
};

int machineY[NUM_MACHINES] = {
    groundY - 40, groundY - 80,
    groundY - 40, groundY - 80,
    groundY - 40, groundY - 80,
    groundY - 40, groundY - 80
};

int machineW = 30;
int machineH = 40;

    float levelTime = 180.0f;
    float startTime = TimeNow();

    for (int i = 0; i < NUM_PILES; i++)
    {
        pileX[i] = 320 + 40 * i + (Random.RandInt()%40);
        pileY[i] = groundY - pileH;
    }

    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();

    while (true)
    {
        float elapsed = TimeNow() - startTime;
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
            g1.stats_button();
            return;
        }

        if (Keyboard.isPressed(KEY_RIGHT) && playerX + playerW < 320) playerX += 3;
        if (Keyboard.isPressed(KEY_LEFT) && playerX > 0) playerX -= 3;
        if (Keyboard.isPressed(KEY_UP) && !inAir)
{
    inAir = true;
    velocityY = jumpStrength;   // give upward velocity
}

// Apply gravity if in the air
if (inAir)
{
    velocityY += gravity;       // get pulled down each frame
    playerY += (int)velocityY;  // move player

    // Ground collision
    if (playerY >= groundY - playerH)
    {
        playerY = groundY - playerH;
        inAir = false;
        velocityY = 0;
    }
}

        for (int i = 0; i < NUM_PILES; i++)
        {
            pileX[i] -= 2;
            if (pileX[i] + pileW < 0) 
            pileX[i] = 320 + 150 + (Random.RandInt()%100);
        }

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

       for (int i = 0; i < NUM_MACHINES; i++)
{
    bool touching =
        !(playerX + playerW < machineX[i] ||
          machineX[i] + machineW < playerX ||
          playerY + playerH < machineY[i] ||
          machineY[i] + machineH < playerY);

    if (touching && Keyboard.isPressed(KEY_SPACE))
    {
        loads++;
        loads_streak++;
        break;   // stop after first machine touched
    }
}
        LCD.Clear();
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);

        LCD.FillRectangle(playerX, playerY, playerW, playerH);

        for (int i = 0; i < NUM_PILES; i++)
        {
            LCD.FillRectangle(pileX[i], pileY[i], pileW, pileH);
        }
        
        g1.machines();
        LCD.SetFontScale(0.5);
        LCD.WriteAt("loads done:", 40, 70);
        LCD.WriteAt(loads, 200, 70);
        LCD.Update();
    }
}
}

void Main_Menu::normal_mode()
{

}

void Main_Menu::pain_mode()
{
    
}