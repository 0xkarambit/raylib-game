#pragma once

#include <raylib.h>

typedef struct element_s Element_t;

struct element_s
{
	int x, y, w, h, fs;			// font-size
	Color bg_color;
	Color color;

	char *text;

	// render functions
	void (*render)(Element_t *self);					// would this be used for custom rendering ???

	// update functions
	void (*onClick)(Element_t *self);				// VIRTUAL 
	void (*onHover)(Element_t *self);				// VIRTUAL

	// constructor
	void (*onAlloc)(Element_t *self);				// do we even need this tbh

	// destructor
	void (*onFree)(Element_t *self);

	// core functions ??
	void (*pollClick)(Element_t *self); 			// calls the onClick function if click is inside the element
	bool isTextDynamicallyAllocated;

};


// to create a new btn !
Element_t ui_create_button(char* text);

// Element_t core functions
void ui_poll_click(Element_t *self);
void ui_render(Element_t *self);
void ui_free_text(Element_t *self);

// util function
bool ui_core_clickInRect(int mouse_x, int mouse_y, int x, int y, int w , int h);