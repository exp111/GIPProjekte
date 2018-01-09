#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;
using namespace cimg_library;

const char* title = "Campus_Eupener_Str.bmp";
int main()
{
	while (gip_window_not_closed())
	{
		gip_load_image(title);
		gip_stop_updates();
		unsigned int mouse_x = gip_mouse_x(), mouse_y = gip_mouse_y();
		for (unsigned int i = 0; i < gip_win_size_x; i++)
		{
			for (unsigned int j = 0; j < gip_win_size_y; j++)
			{
				if (gip_distance(i, j, mouse_x, mouse_y) > 100)
					gip_set_grey(i, j, 0);
				else
				{
					//gip_color clr;
					//gip_get_color(i, j, clr);
					//gip_set_grey(i, j, (0.33 * clr[0] + 0.33 * clr[1] + 0.33 * clr[2]));
					gip_set_grey(i, j, gip_get_grey(i, j));
				}
			}
		}
		gip_start_updates();
		gip_sleep(1);
	}
	return 0;
}