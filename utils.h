#pragma once

#include "raylib.h"
#include <stdbool.h>
//int GetMonitorWidth(int monitor);                                       // Get specified monitor width (max available by monitor)
//int GetMonitorHeight(int monitor);                                      // Get specified monitor height (max available by monitor)
//void SetWindowPosition(int x, int y);                                   // Set window position on screen (only PLATFORM_DESKTOP)
//void SetWindowSize(int width, int height);                              // Set window dimensions
//
//Vector2 GetWindowPosition(void);                                        // Get window position XY on monitor
//int GetScreenWidth(void);                                               // Get current screen width
//int GetScreenHeight(void);                                              // Get current screen height


void fullscreen();
void returnToPrevScreen();
void toggleFullscreen();

void reTargetGrid();