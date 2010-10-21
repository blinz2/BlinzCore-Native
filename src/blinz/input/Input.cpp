#include "SDL/SDL_events.h"
#include "SDL/SDL_keyboard.h"
#include "SDL/SDL_mouse.h"
#include "Input.hpp"

int keyIndex[400];

void init() {
	keyIndex[SDLK_0] = KEY_0;
	keyIndex[SDLK_1] = KEY_1;
	keyIndex[SDLK_2] = KEY_2;
	keyIndex[SDLK_3] = KEY_3;
	keyIndex[SDLK_4] = KEY_4;
	keyIndex[SDLK_5] = KEY_5;
	keyIndex[SDLK_6] = KEY_6;
	keyIndex[SDLK_7] = KEY_7;
	keyIndex[SDLK_8] = KEY_8;
	keyIndex[SDLK_9] = KEY_9;
	keyIndex[SDLK_a] = KEY_A;
	keyIndex[SDLK_b] = KEY_B;
	keyIndex[SDLK_c] = KEY_C;
	keyIndex[SDLK_d] = KEY_D;
	keyIndex[SDLK_e] = KEY_E;
	keyIndex[SDLK_f] = KEY_F;
	keyIndex[SDLK_g] = KEY_G;
	keyIndex[SDLK_h] = KEY_H;
	keyIndex[SDLK_i] = KEY_I;
	keyIndex[SDLK_j] = KEY_J;
	keyIndex[SDLK_k] = KEY_K;
	keyIndex[SDLK_l] = KEY_L;
	keyIndex[SDLK_m] = KEY_M;
	keyIndex[SDLK_n] = KEY_N;
	keyIndex[SDLK_o] = KEY_P;
	keyIndex[SDLK_p] = KEY_P;
	keyIndex[SDLK_q] = KEY_Q;
	keyIndex[SDLK_r] = KEY_R;
	keyIndex[SDLK_s] = KEY_S;
	keyIndex[SDLK_t] = KEY_T;
	keyIndex[SDLK_u] = KEY_U;
	keyIndex[SDLK_v] = KEY_V;
	keyIndex[SDLK_w] = KEY_W;
	keyIndex[SDLK_y] = KEY_Y;
	keyIndex[SDLK_z] = KEY_Z;
	keyIndex[SDLK_BACKSLASH] = KEY_BACKSLASH;
	keyIndex[SDLK_SLASH] = KEY_SLASH;
	keyIndex[SDLK_COMMA] = KEY_COMMA;
	keyIndex[SDLK_COLON] = KEY_COLON;
	keyIndex[SDLK_SEMICOLON] = KEY_SEMICOLON;
	keyIndex[SDLK_QUOTE] = KEY_APOSTROPHE;
	keyIndex[SDLK_BACKQUOTE] = KEY_BACKAPOSTROPHE;
	keyIndex[SDLK_QUOTEDBL] = KEY_QUOTE;
	keyIndex[SDLK_PERIOD] = KEY_PERIOD;
	keyIndex[SDLK_LESS] = KEY_LESS;
	keyIndex[SDLK_GREATER] = KEY_GREATER;
	keyIndex[SDLK_LEFTBRACKET] = KEY_LEFT_BRACKET;
	keyIndex[SDLK_RIGHTBRACKET] = KEY_RIGHT_BRACKET;
	keyIndex[SDLK_EXCLAIM] = KEY_EXCLAIM;
	keyIndex[SDLK_AT] = KEY_AT;
	keyIndex[SDLK_HASH] = KEY_POUND;
	keyIndex[SDLK_CARET] = KEY_DOLLAR;
	keyIndex[SDLK_AMPERSAND] = KEY_AMPERSAND;
	keyIndex[SDLK_ASTERISK] = KEY_ASTERISK;
	keyIndex[SDLK_RIGHTPAREN] = KEY_RIGHT_PARENTHESIS;
	keyIndex[SDLK_LEFTPAREN] = KEY_LEFT_PARENTHESIS;
	keyIndex[SDLK_UNDERSCORE] = KEY_UNDERSCORE;
	keyIndex[SDLK_PLUS] = KEY_PLUS;
	keyIndex[SDLK_EQUALS] = KEY_EQUALS;
	keyIndex[SDLK_RETURN] = KEY_ENTER;
	keyIndex[SDLK_BACKSPACE] = KEY_BACKSPACE;
	keyIndex[SDLK_DELETE] = KEY_DELETE;
	keyIndex[SDLK_INSERT] = KEY_INSERT;
	keyIndex[SDLK_CAPSLOCK] = KEY_CAPSLOCK;
	keyIndex[SDLK_SCROLLOCK] = KEY_SCROLL;
	keyIndex[SDLK_SYSREQ] = KEY_SYSREQ;
	keyIndex[SDLK_PAUSE] = KEY_PAUSE;
	keyIndex[SDLK_BREAK] = KEY_BREAK;
	keyIndex[SDLK_UP] = KEY_UP;
	keyIndex[SDLK_DOWN] = KEY_DOWN;
	keyIndex[SDLK_LEFT] = KEY_LEFT;
	keyIndex[SDLK_RIGHT] = KEY_RIGHT;
	keyIndex[SDLK_F1] = KEY_F1;
	keyIndex[SDLK_F2] = KEY_F2;
	keyIndex[SDLK_F3] = KEY_F3;
	keyIndex[SDLK_F4] = KEY_F4;
	keyIndex[SDLK_F5] = KEY_F5;
	keyIndex[SDLK_F6] = KEY_F6;
	keyIndex[SDLK_F7] = KEY_F7;
	keyIndex[SDLK_F8] = KEY_F8;
	keyIndex[SDLK_F9] = KEY_F9;
	keyIndex[SDLK_F10] = KEY_F10;
	keyIndex[SDLK_F11] = KEY_F11;
	keyIndex[SDLK_F12] = KEY_F12;
	keyIndex[SDLK_HOME] = KEY_HOME;
	keyIndex[SDLK_END] = KEY_END;
	keyIndex[SDLK_PAGEUP] = KEY_PAGEUP;
	keyIndex[SDLK_PAGEDOWN] = KEY_PAGEDOWN;
	keyIndex[SDLK_RSUPER] = KEY_RIGHTSUPER;
	keyIndex[SDLK_LSUPER] = KEY_LEFTSUPER;
}

/*
 * Event:
 * 	bits
 * 	00     0 = key/button status alteration, 1 = mouse wheel scroll
 * Button/Key status alteration events:
 * 	01     0 = keyboard, 1 = mouse
 * 	02     0 = release, 1 = press
 * 	03-31  button/key identification
 * 	32-48  x coordinate of the cursor on screen
 * 	48-64  y coordinate of the cursor on screen
 * Mouse wheel scroll:
 * 	01-31  scroll distance
 * 	32-48  x coordinate of the cursor on screen
 * 	48-64  y coordinate of the cursor on screen
 */

long mouseButtonPress(short button, long x, long y) {
	long yout = y << 48;
	long xout = x << 32;
	return (((((long) button)) << 3) | 5) | yout | xout;
}

long mouseButtonRelease(short button, long x, long y) {
	long yout = y << 48;
	long xout = x << 32;
	return (((((long) button)) << 3) | 2) | yout | xout;
}

long mouseWheelScroll(short scrollDistance, long x, long y) {
	long yout = y << 48;
	long xout = x << 32;
	return ((((long) scrollDistance) << 1) | 1) | yout | xout;
}

long keyPress(short key) {
	return ((((long)key) << 3) | 4);
}

long keyRelease(short key) {
	return ((((long)key) << 3) | 2);
}

long updateInput() {
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type) {
		case SDL_KEYDOWN:
			return keyPress(e.key.keysym.sym);
		case SDL_KEYUP:
			return keyRelease(e.key.keysym.sym);
		case SDL_MOUSEBUTTONDOWN:
			switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					return mouseButtonPress(0, e.button.x, e.button.y);
				case SDL_BUTTON_MIDDLE: 
					return mouseButtonPress(1, e.button.x, e.button.y);
				case SDL_BUTTON_RIGHT:
					return mouseButtonPress(2, e.button.x, e.button.y);
			}
		case SDL_MOUSEBUTTONUP:
			switch (e.button.button) {
				case SDL_BUTTON_LEFT:
					return mouseButtonRelease(0, e.button.x, e.button.y);
				case SDL_BUTTON_MIDDLE: 
					return mouseButtonRelease(1, e.button.x, e.button.y);
				case SDL_BUTTON_RIGHT:
					return mouseButtonRelease(2, e.button.x, e.button.y);
			}
	}
}

