#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__


#define DISPLAY_TIME_SPLASH_SCENE 2
#define TRANSITION_TIME 0.5 
#define PIPE_SPAWN_FREQUENCY 0.002
#define PIPE_GAP 10
#define UPPER_SCREEN_PIPE_THRESHOLD 0.65
#define LOWER_SCREEN_PIPE_THRESHOLD 0.35

#define PIPE_MOVEMENT_SPEED 0.01

#define BIRD_COLLISION_BITMASK 0x000001
#define OBSTACLE_COLLISION_BITMASK 0x000002
#define POINT_COLLISION_BITMASK 0x000003


#define BIRD_FALLING_SPEED 0.0025
#define BIRD_FLYING_SPEED 0.00375
#define BIRD_FLY_DURATION 0.25

#define SCORE_FONT_SIZE 0.1

#define TIMEPIKACHU 150





#define SCENE_TRANSITION_TIME 1.0f
#define SPLASH_SCENE_SHOW_TIME 3.0f


#define SPLASH_SCENE_BACKGROUND_FILEPATH "Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Main Menu Background.png"
#define GAME_BACKGROUND_FILEPATH "Main Menu Background.png"
#define GAME_OVER_BACKGROUND "Pause Background.png"
#define PAUSE_BACKGROUND "Pause Background.png"

#define GAME_OVER_WINDOW "Pause Window.png"
#define PAUSE_WINDOW "Pause Window.png"

#define MAIN_MENU_TITLE_FILEPATH "Game Title.png"

#define MAIN_MENU_PLAY_BUTTON "Play Button.png"
#define MAIN_MENU_PLAY_BUTTON_PRESSED "Play Button.png"
#define SOUND_ON_BUTTON "Sound On.png"
#define SOUND_ON_BUTTON_PRESSED "Sound On.png"
#define SOUND_OFF_BUTTON "Sound Off.png"
#define SOUND_OFF_BUTTON_PRESSED "Sound Off.png"
#define ACHIEVEMENTS_BUTTON "Achievements.png"
#define ACHIEVEMENTS_BUTTON_PRESSED "Achievements.png"
#define RETRY_BUTTON "Retry1 Button.png"
#define RETRY_BUTTON_PRESSED "Retry1 Button.png"
#define HOME_BUTTON "Home Button.png"
#define HOME_BUTTON_PRESSED "Home Button.png"
#define PAUSE_BUTTON "Pause Button.png"
#define PAUSE_BUTTON_PRESSED "Pause Button.png"
#define RESUME_BUTTON "Resume Button.png"
#define RESUME_BUTTON_PRESSED "Resume Button.png"

#define MAIN_MENU_PLAY_BUTTON_OUTER "Play Button Outer.png"

#define GRID_FILEPATH "Grid.png"

#define X_PIECE_FILEPATH "X.png"
#define O_PIECE_FILEPATH "O.png"
#define X_WINNING_PIECE_FILEPATH "X Win.png"
#define O_WINNING_PIECE_FILEPATH "O Win.png"

#define TAG_MAIN_MENU_PLAY_BUTTON 0
#define TAG_ACHIEVEMENTS_BUTTON 1

#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE

#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92

#define PIECE_FADE_IN_TIME 0.5

#define GAME_OVER_BACKGROUND_FADE_IN_TIME 0.5
#define PAUSE_BACKGROUND_FADE_TIME 0.5

#define MENU_MOVE_BOUNCE_DURATION 1.5





#endif // __DEFINITIONS_H__
