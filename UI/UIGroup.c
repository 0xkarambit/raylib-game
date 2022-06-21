#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>


#include "UIGroup.h"

void print_data(Element_data_t* data)
{
	printf("int x, y, w, h, fs = %d,%d,%d,%d,%d\n", data->x, data->y, data->w, data->h, data->fs);
	printf("char *text %s\n", data->text);
}

void UIGroup_setup(UIGROUP_t* grp, int elm_count, Element_data_t* data)
{
	grp->elm_count = elm_count;
	grp->elements = calloc(sizeof(Element_t), elm_count);
	printf("ye toh theek he \n");

	for (int i = 0; i < elm_count; ++i)
	{
		Element_t *thisElm = &grp->elements[i];
		*thisElm = ui_create_button(data->text);

		thisElm->bg_color = data->bg_color;
		thisElm->color = data->color;
		thisElm->x = data->x;
		thisElm->y = data->y;

		thisElm->w = data->w;
		thisElm->h = data->h;

		thisElm->fs = data->fs;

		// todo: add custom click logic to swap scene
		thisElm->onClick = data->onClick;
		data++;
	}
}

void UIGroup_render(UIGROUP_t* grp)
{
	for (int i = 0; i < grp->elm_count; ++i)
	{
		Element_t *thisElm = &grp->elements[i];
		thisElm->render(thisElm);
	}
}

void UIGroup_update(UIGROUP_t* grp)
{
	for (int i = 0; i < grp->elm_count; ++i)
	{
		Element_t *thisElm = &grp->elements[i];
		thisElm->pollClick(thisElm);
	}
}

bool UIGroup_exit(UIGROUP_t* grp)
{
	for (int i = 0; i < grp->elm_count; ++i)
	{
		Element_t *thisElm = &grp->elements[i];
		thisElm->onFree(thisElm);
	}
	free(grp->elements);
	return true;
};