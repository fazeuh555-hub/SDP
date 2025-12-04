#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHKeyboard.h"


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
 void jump_up();
 void gravity_down();
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
    x_move=160,y_move=195,r_move=5;
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    LCD.SetFontColor (BLACK);
    LCD.DrawCircle(x_move=160,y_move=195,r_move=5);
    LCD.FillCircle(x_move=160,y_move=195,r_move=5);
    LCD.SetFontColor (BLACK);
    LCD.DrawLine(0,201,320,201);
    while (true){
        LCD.Update();
        if(Keyboard.isPressed(KEY_RIGHT)&&(x_move<=312))
        {
            
            LCD.SetFontColor (WHITE);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move);
            x_move = x_move + 3;
            LCD.SetFontColor (BLACK);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move);
            Sleep(1); 
        }
        if(Keyboard.isPressed(KEY_LEFT)&&(x_move>=8))
        {
            
            LCD.SetFontColor (WHITE);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move);
            x_move = x_move - 3;
            LCD.SetFontColor (BLACK);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move); 
            Sleep(1);
        }
         if(Keyboard.isPressed(KEY_UP))
        {
            Main_Menu g1; 
            LCD.Update();
            g1.jump_up();
            Sleep(1000);
            g1.gravity_down();
            Sleep (1000);

        }
    }
}

void Main_Menu :: normal_mode () 
{
    x_move=160,y_move=195,r_move=5;
    LCD.SetBackgroundColor(WHITE);
    LCD.Clear();
    LCD.SetFontColor (BLACK);
    LCD.DrawCircle(x_move=160,y_move=195,r_move=5);
    LCD.FillCircle(x_move=160,y_move=195,r_move=5);
    LCD.SetFontColor (BLACK);
    LCD.DrawLine(0,201,320,201);
    while (true){
        LCD.Update();
        if(Keyboard.isPressed(KEY_RIGHT)&&(x_move<=312))
        {
            
            LCD.SetFontColor (WHITE);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move);
            x_move = x_move + 3;
            LCD.SetFontColor (BLACK);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move);
            Sleep(1); 
        }
        if(Keyboard.isPressed(KEY_LEFT)&&(x_move>=8))
        {
            
            LCD.SetFontColor (WHITE);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move);
            x_move = x_move - 3;
            LCD.SetFontColor (BLACK);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move); 
            Sleep(1);
        }
    }
}

void Main_Menu :: jump_up()
{
    int i;
        LCD.Update();
        for (i=0;i<=5;i++)
        {
            Sleep(1000);
            LCD.SetFontColor (WHITE);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move);
        LCD.Update();    
            y_move = y_move - 5;
        LCD.Update();    
            LCD.SetFontColor (BLACK);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move); 
        }
            
}


void Main_Menu :: gravity_down()
{
    int i;
    for (i=0;i>=5;i++)
    {
        LCD.Update();
            LCD.SetFontColor (WHITE);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move);
        LCD.Update();
            y_move = y_move + 5;
        LCD.Update();
            LCD.SetFontColor (BLACK);
            LCD.DrawCircle(x_move,y_move,r_move);
            LCD.FillCircle(x_move,y_move,r_move); 
            Sleep(1000);
    }
}