#include <raylib.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "ui.h"



// btn spawner ???
Element_t ui_create_button(char* text)
{
	// color, pos, dimension should be set after creation
	Element_t btn;
	btn.render = &ui_render;
	btn.pollClick = &ui_poll_click;
	btn.onFree = &ui_free_text;

	btn.fs = 22;
	btn.text = strdup(text);
	btn.isTextDynamicallyAllocated = true;
	return btn;
}


// void ui_poll_click(Element_t *self, int mouse_x, int mouse_y)
void ui_poll_click(Element_t *self)
{
	//  we can call MousePress here too right ?
	// todo: `IsMouseButtonPressed etc` should not be here and should NOT be called so many times per frame for all the elements
	if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) return;
	int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();

	if (ui_core_clickInRect(mouse_x, mouse_y, self->x, self->y, self->w, self->h))
	{
		self->onClick(self);
	}
}

void ui_render(Element_t *self)
{
	// not checking if the function 
	DrawRectangle(self->x, self->y, self->w, self->h, self->bg_color);
	DrawText(self->text, self->x, self->y, self->fs, self->color);
}



void ui_free_text(Element_t *self)
{
	if (self->isTextDynamicallyAllocated) free(self->text);
}



bool ui_core_clickInRect(int mouse_x, int mouse_y, int x, int y, int w , int h)
{
	if (mouse_x > x && mouse_x < (x + w) && mouse_y > y && mouse_y < (y + h))
	{
		return true;
	}
	return false;
}