# include <stdio.h>
# include <stdlib.h>
# include "udll.h"

int main (void)
{
	union Data d;
	
	d.i = 36;
	insert (0, d);
	d.i = 16;
	insert (0, d);
	d.i = 9;
	insert (0, d);
	d.i = 4;
	insert (0, d);
	d.i = 2;
	insert (0, d);
	d.i = 25;
	insert (4, d);
	d.i = 49;
	insert (6, d);
	removeNode (3);
	
	int len = length ();
	
	for(int x = 0; x < len; x++)
	{
		union Data dayta = get (x);
		printf("element %d = %d\n", x, dayta.i);
	}

	d.c = 'a';
	insert (0, d);

	d.f = 9.67832;
	insert (4, d);
}