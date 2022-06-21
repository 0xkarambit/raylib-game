#pragma once
#include "ui.h"

typedef struct UIGROUP_s
{
	int elm_count;
	Element_t *elements;

	// these are wrappers for the custom functions on individual elements these cant be different
	// so i dont think we need to store them in the struct.
	// void (*setup)(void);
	// void (*update)(void);
	// void (*render)(void);
	// bool (*exit)(void);

} UIGROUP_t;


// these functions will just call all the elements' lifecycle methods using a loop !
void UIGroup_setup(UIGROUP_t *grp, int elm_count, Element_data_t* data);
void UIGroup_render(UIGROUP_t *grp);
void UIGroup_update(UIGROUP_t *grp);
bool UIGroup_exit(UIGROUP_t *grp);
