#include <raylib.h>
#include <stdio.h>

#include "../UI/ui.h"

// to extend/customize the ui.h functionality
void btn_clicked(Element_t* btn)
{
	printf("I got clicked !\n");
	printf("%s\n", btn->text);
}