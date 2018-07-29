/*

basic DAC toggle 

*/

outlets = 2;
sketch.default2d();
var myfrgb  = new Array([1,.25,.25], [.25,1,.25]);
var myval = 0;
	
draw();
refresh();

function draw()
{
	var str;

	with (sketch) {
		fontsize(0.8*(box.rect[3]-box.rect[1]));
		font("Arial Black");
		glclearcolor(myfrgb[myval]);
		glclear();	
		textalign("center","center");		
		moveto(0,0)
		if (myval)
		{
			glcolor(0,.5,0);
			text("Audio Running");
		}
		else 
	    {
			glcolor(.5,0,0);
			text("Audio Stopped");
		}
	}
}

function msg_int(v)
{
	if (v==0)
		myval = 0;
	else
		myval = 1;
	draw();
	refresh();
	notifyclients();
	outlet(0,myval);
}

function bang()
{
	myval = 1 - myval; // toggle 0/1
	msg_int(myval);
}

function onresize(w,h)
{
	draw();
	refresh();
}
onresize.local = 1; //private

// not using any mouse args
function onclick()
{
	bang();
}
onclick.local = 1; //private

