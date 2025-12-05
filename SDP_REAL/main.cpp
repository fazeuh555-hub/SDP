#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHKeyboard.h"
#include "FEHRandom.h"


class Main_Menu
{
private:
        int x_move,y_move,r_move;
        int loads, loads_streak, misses;
  
public:
 void play_button();
 void stats_button();
 void credits_button();
 void Instructions_button();
 void Main_Screen ();
 void chill_mode ();
 void normal_mode ();
 void pain_mode ();
}
;



int main() {
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
    LCD.WriteAt ("Instruct",230,177);
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
            g1.Instructions_button();
        }
    }
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
        while(Keyboard.isPressed(KEY_P))
        {   
            LCD.Clear();
            LCD.SetBackgroundColor(WHITE);
            while(Keyboard.isPressed(KEY_A))
        {   
            LCD.Clear();
            LCD.SetBackgroundColor(BLACK);
            while(Keyboard.isPressed(KEY_I))
            
        {
            LCD.Clear();
            LCD.SetBackgroundColor(WHITE);
            while(Keyboard.isPressed(KEY_N))
        {
            LCD.Clear();
            LCD.SetBackgroundColor(BLACK);
            while(Keyboard.isPressed(KEY_T))
        {
            LCD.Clear();
            LCD.SetBackgroundColor (WHITE);
            while(Keyboard.isPressed(KEY_R))
        {
            LCD.Clear();
            LCD.SetBackgroundColor (BLACK);
            while(Keyboard.isPressed(KEY_A))
        {
            LCD.Clear();
            LCD.SetBackgroundColor (WHITE);
            while(Keyboard.isPressed(KEY_I))
        {
            LCD.Clear();
            LCD.SetBackgroundColor (BLACK);
            while(Keyboard.isPressed(KEY_N))
            {g1.pain_mode();}
        }    
        }
        }
        }
        }    
        }
        }
        }    
    }
} 

void Main_Menu::stats_button()
{
    Main_Menu g1;
    float x,y,v,t;
    LCD.SetBackgroundColor(BLUE);
    LCD.Clear(); 
    LCD.SetFontColor (WHITE);
    LCD.WriteAt ("Stats",140,25);
    LCD.SetFontColor (WHITE);
    LCD.WriteAt ("Number of Loads completed: 254",70,75);
    LCD.SetFontColor (WHITE);
    LCD.WriteAt ("Highest streak: 174",105,125);
    LCD.SetFontColor (WHITE);
    LCD.WriteAt ("Number of misses: 1500",85,175);
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

void Main_Menu::Instructions_button()
{
    Main_Menu g1;
    float x,y,v,t;
    LCD.SetBackgroundColor(RED);
    LCD.Clear();
    LCD.WriteAt ("How to play the game",105,25);
    LCD.WriteAt ("Press right and left buttons to move",60,75);
    LCD.WriteAt ("Press up to jump",110,125);
    LCD.WriteAt ("Press center to load machine",73,175);
    LCD.SetFontColor (WHITE);
    LCD.DrawRectangle (135,200,50,22);
    LCD.FillRectangle (135,200,50,22);
    LCD.SetFontScale(0.5);
    LCD.SetFontColor (BLACK);
    LCD.WriteAt ("Back",147,205);
    while (true)
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
    LCD.WriteAt ("Instruct",230,177);
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
            g1.Instructions_button();
        }
    }
    while (1) {
        LCD.Update();
        //nnever end
    }
    
}
 
void Main_Menu :: chill_mode () 
{
    Main_Menu g1;
    int playerX = 40;
    int playerY;
    int playerW = 14;
    int playerH = 18;
    int groundY = 200;
    playerY = groundY - playerH;

    bool inAir = false;
    int jumpFrames = 0;

    const int NUM_PILES = 2;
    int pileX[NUM_PILES];
    int pileY[NUM_PILES];
    int pileW = 20;
    int pileH = 12;

    int machineX = 270;
    int machineY = groundY - 40;
    int machineW = 30;
    int machineH = 40;

    float levelTime = 20.0f;
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
            LCD.WriteAt("Normal Over", 100, 130);

            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            g1.play_button();
            return;
        }

        if (Keyboard.isPressed(KEY_RIGHT) && playerX + playerW < 320) playerX += 3;
        if (Keyboard.isPressed(KEY_LEFT) && playerX > 0) playerX -= 3;

        if (Keyboard.isPressed(KEY_UP) && !inAir)
{
    inAir = true;
    jumpFrames = 0;
}

if (inAir)
{
    if (jumpFrames < 12) playerY -= 5;        
    else if (jumpFrames < 24) playerY += 5;   
    else {
        inAir = false;
        playerY = groundY - playerH;
    }
    jumpFrames++;
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
            LCD.WriteAt("Normal Complete!", 60, 130);

            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            g1.play_button();
            return;
        }

        LCD.Clear();
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);

        LCD.FillRectangle(playerX, playerY, playerW, playerH);

        for (int i = 0; i < NUM_PILES; i++)
        {
            LCD.FillRectangle(pileX[i], pileY[i], pileW, pileH);
        }

        LCD.DrawRectangle(machineX, machineY, machineW, machineH);
        LCD.Update();
    }
}

void Main_Menu::normal_mode()
{
    Main_Menu g1;
    int playerX = 40;
    int playerY;
    int playerW = 14;
    int playerH = 18;
    int groundY = 200;
    playerY = groundY - playerH;

    bool inAir = false;
    int jumpFrames = 0;

    const int NUM_PILES = 3;
    int pileX[NUM_PILES];
    int pileY[NUM_PILES];
    int pileW = 20;
    int pileH = 12;

    int machineX = 270;
    int machineY = groundY - 40;
    int machineW = 30;
    int machineH = 40;

    float levelTime = 20.0f;
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
            LCD.WriteAt("Normal Over", 100, 130);

            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            g1.play_button();
            return;
        }

        if (Keyboard.isPressed(KEY_RIGHT) && playerX + playerW < 320) playerX += 4;
        if (Keyboard.isPressed(KEY_LEFT) && playerX > 0) playerX -= 4;
        if (Keyboard.isPressed(KEY_UP) && !inAir)
{
    inAir = true;
    jumpFrames = 0;
}

if (inAir)
{
    if (jumpFrames < 12) playerY -= 5;        
    else if (jumpFrames < 24) playerY += 5;   
    else {
        inAir = false;
        playerY = groundY - playerH;
    }
    jumpFrames++;
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
            LCD.WriteAt("Normal Complete!", 60, 130);

            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            g1.play_button();
            return;
        }

        LCD.Clear();
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);

        LCD.FillRectangle(playerX, playerY, playerW, playerH);

        for (int i = 0; i < NUM_PILES; i++)
        {
            LCD.FillRectangle(pileX[i], pileY[i], pileW, pileH);
        }

        LCD.DrawRectangle(machineX, machineY, machineW, machineH);
        LCD.Update();
    }
}


void Main_Menu::pain_mode()
{
    Main_Menu g1;
    int playerX = 40;
    int playerY;
    int playerW = 14;
    int playerH = 18;
    int groundY = 200;
    playerY = groundY - playerH;

    bool inAir = false;
    int jumpFrames = 0;

    const int NUM_PILES = 4;
    int pileX[NUM_PILES];
    int pileY[NUM_PILES];
    int pileW = 20;
    int pileH = 12;

    int machineX = 270;
    int machineY = groundY - 40;
    int machineW = 30;
    int machineH = 40;

    float levelTime = 20.0f;
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
            LCD.WriteAt("Normal Over", 100, 130);

            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            g1.play_button();
            return;
        }

        if (Keyboard.isPressed(KEY_RIGHT) && playerX + playerW < 320) playerX += 4;
        if (Keyboard.isPressed(KEY_LEFT) && playerX > 0) playerX -= 4;
        if (Keyboard.isPressed(KEY_UP) && !inAir)
{
    inAir = true;
    jumpFrames = 0;
}

if (inAir)
{
    if (jumpFrames < 12) playerY -= 7;        
    else if (jumpFrames < 24) playerY += 7;   
    else {
        inAir = false;
        playerY = groundY - playerH;
    }
    jumpFrames++;
}

        for (int i = 0; i < NUM_PILES; i++)
        {
            pileX[i] -= 5;
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
            LCD.WriteAt("Normal Complete!", 60, 130);

            float tx, ty, tt, tv;
            while (!LCD.Touch(&tx,&ty)) {}
            while (LCD.Touch(&tt,&tv)) {}
            g1.play_button();
            return;
        }

        LCD.Clear();
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);

        LCD.FillRectangle(playerX, playerY, playerW, playerH);

        for (int i = 0; i < NUM_PILES; i++)
        {
            LCD.FillRectangle(pileX[i], pileY[i], pileW, pileH);
        }

        LCD.DrawRectangle(machineX, machineY, machineW, machineH);
        LCD.Update();
    }
}