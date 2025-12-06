#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHKeyboard.h"
#include "FEHRandom.h"


class Main_Menu
{
private:
        int loads, loads_streak, misses;
  
public:
 void play_button();
 void stats_button();
 void credits_button();
 void Main_Screen ();
 void chill_mode ();
 void normal_mode ();
 void pain_mode ();
 void tutorial ();
 void rectangles();
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
 
void Main_Menu :: tutorial () 
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

    

    for (int i = 0; i < NUM_PILES; i++)
    {
        pileX[i] = 320 + 40 * i + (Random.RandInt()%40);
        pileY[i] = groundY - pileH;
    }

    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();

    while (true)
    {
       

        if (Keyboard.isPressed(KEY_RIGHT) && playerX + playerW < 320) playerX += 3;
        if (Keyboard.isPressed(KEY_LEFT) && playerX > 0) playerX -= 3;

        if (Keyboard.isPressed(KEY_UP) && !inAir)
{
    inAir = true;
    jumpFrames = 0;
}

if (inAir)
{
    Sleep(1);
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

        LCD.FillRectangle(playerX, playerY, playerW, playerH);

        for (int i = 0; i < NUM_PILES; i++)
        {
            LCD.FillRectangle(pileX[i], pileY[i], pileW, pileH);
        }

        LCD.DrawRectangle(machineX, machineY, machineW, machineH);
        LCD.Update();
    }
}

void Main_Menu :: rectangles ()
{
    int groundY = 200;
    int machineX = 270;
    int machineY = groundY - 40;
    int machineW = 30;
    int machineH = 40;

        LCD.DrawRectangle(machineX, machineY, machineW, machineH);
        LCD.DrawRectangle(machineX, machineY-40, machineW, machineH);
        LCD.DrawRectangle(machineX-30, machineY, machineW, machineH);
        LCD.DrawRectangle(machineX-30, machineY-40, machineW, machineH);
        LCD.DrawRectangle(machineX-240, machineY, machineW, machineH);
        LCD.DrawRectangle(machineX-240, machineY-40, machineW, machineH);
        LCD.DrawRectangle(machineX-210, machineY, machineW, machineH);
        LCD.DrawRectangle(machineX-210, machineY-40, machineW, machineH);



}

void Main_Menu :: chill_mode () 
{
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
    jumpFrames = 0;
}

if (inAir)
{
    Sleep(1);
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
            loads++;
            loads_streak++;
        }

        LCD.Clear();
        LCD.SetFontColor(BLACK);
        LCD.DrawLine(0, groundY, 320, groundY);

        LCD.FillRectangle(playerX, playerY, playerW, playerH);

        for (int i = 0; i < NUM_PILES; i++)
        {
            LCD.FillRectangle(pileX[i], pileY[i], pileW, pileH);
        }
        
        g1.rectangles();
        LCD.Update();
    }
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

    float levelTime = 120.0f;
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
    
}