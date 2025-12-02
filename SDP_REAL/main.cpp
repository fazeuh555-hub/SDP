#include "FEHLCD.h"
#include "FEHUtility.h"

class Main_Menu
{
private:
    
        int loads, loads_streak, misses;
    
public:
 void play_button();
 void stats_button();
 void credits_button();
 void Instructions_button();
 void Main_Screen ();
 




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
    LCD.WriteAt ("Gameplay Here",120,120);
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

void Main_Menu::stats_button()
{
    Main_Menu g1;
    float x,y,v,t;
    LCD.SetBackgroundColor(BLUE);
    LCD.Clear(); 
    LCD.SetFontColor (WHITE);
    LCD.WriteAt ("Stats",110,25);
    LCD.SetFontColor (WHITE);
    LCD.WriteAt ("Number of Loads completed: 254",73,75);
    LCD.SetFontColor (WHITE);
    LCD.WriteAt ("Highest streak: 174",110,125);
    LCD.SetFontColor (WHITE);
    LCD.WriteAt ("Number of misses: 1500",73,175);
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
    LCD.WriteAt ("Faiza Choudhry and Michael Tang",73,100);
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
    LCD.WriteAt ("How to play the game",110,25);
    LCD.WriteAt ("Press right and left buttons to move",73,75);
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
 
