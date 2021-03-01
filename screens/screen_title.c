#include "raylib.h"
#include "screens.h"

Texture2D protagonist;
Texture2D background;
static int finishScreen;

// Initialize title screen
void InitTitleScreen(void)
{
    finishScreen = 0;
    protagonist = LoadTexture("resources/title_man.png");
    background = LoadTexture("resources/title_background.png");
}

// Update title screen
void UpdateTitleScreen(void)
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) 
    {
        finishScreen = 1;
        PlaySound(point);
    }

    PlayMusicStream(ambient);
}

// Draw title screen
void DrawTitleScreen(void)
{
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(protagonist, 750, 220, WHITE);
    DrawText("Mosquito Rampage", GetScreenWidth() - 960, GetScreenHeight() - 600, 72, WHITE);
    DrawText("Press Enter to begin", GetScreenWidth() - 890, GetScreenHeight() - 180, 48, WHITE);
}

// Unload title screen
void UnloadTitleScreen(void)
{
    UnloadTexture(background);
    UnloadTexture(protagonist);
}

// Should title screen finish?
int FinishTitleScreen(void)
{
    return finishScreen;
}