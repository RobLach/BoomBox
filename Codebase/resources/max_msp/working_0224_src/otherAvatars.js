
// inlets and outlets
inlets = 1;
outlets = 2;

// global variables and arrays

//global objects
//global for debug stuff
gDebug		 	        			= new Global("debug");
gDebug.msg              			= "";

//global object keeper-tracker
gObjects		 	        		= new Global("myObjects");
gObjects.count              		= 0;
gObjects.hSize						= 100;
gObjects.idArray					= "";

initializedFlag = false;


//if (jsarguments.length>1)
    //myval = jsarguments[1];
    
function bang()
{
    mp("myvalue is " + myval);
}

function resetMe()
{
	thisObj		= this.patcher.firstobject;
	i = 0;
	j = this.patcher.count;
	do
	{
		if(thisObj.maxclass == "patcher" && thisObj.varname.indexOf("avatar_") != -1)
		{
			this.patcher.remove(thisObj);
			thisObj		= this.patcher.firstobject;
			i = 0;
			j = this.patcher.count;
			continue;
		}
		thisObj = thisObj.nextobject;
		i++;
	}while(i<j)
	gObjects.count		= 0;
	gObjects.idArray	= "";
}

function list()
{
	var a = arrayfromargs(arguments);
	if(gObjects.idArray.indexOf(a[0]) == -1)
	{
    	this.newOtherAvatar(a);
    }
	var thisObj		= this.patcher.firstobject;
	var i = 0;
	var j = this.patcher.count;
	do
	{
		if(i!=0){thisObj = thisObj.nextobject;}
		if(thisObj.varname.indexOf(a[0]) != -1)
		{
			thisObj.subpatcher().getnamed("an_avatar_unpacker").message(a.slice(1, a.length));
			//this.patcher.connect(this.patcher.getnamed("js_otherAvatars"), 0, thisObj, 0);
			//outlet(0, a.slice(1, a.length));
			//this.patcher.disconnect(this.patcher.getnamed("js_otherAvatars"), 0, thisObj, 0);
		}
		i++;
	}while(i<j)
}

function newOtherAvatar(a)
{
    //create our objects
	newAvatar 				= patcher.newdefault(50 + (gObjects.hSize * gObjects.count), 150, "anAvatar", a[0]);
	newAvatar.varname		= "avatar_" + a[0];
	gObjects.idArray += "," + a[0];
	newAvatarPatcher		= newAvatar.subpatcher();
	for(ii = 1; ii < 7; ii++)
	{
		this.patcher.connect(newAvatar, (ii - 1), this.patcher.getnamed("music_out_" + ii), 0);
		this.patcher.connect(newAvatar, (ii + 5), this.patcher.getnamed("fx_out_" + ii), 0);
	}
	var x = this.createDebugObject(newAvatarPatcher, a[0]);
	gObjects.count++;
}

function createDebugObject(aPatcherObj, objID)
{
	var thisObj		= aPatcherObj.firstobject;
	var i = 0;
	var j = aPatcherObj.count;
	do
	{
		if(i!=0){thisObj = thisObj.nextobject;}
		if(thisObj.varname.indexOf("_print_msgIn_gate") != -1)
		{
			newDebugPrintObj 		= aPatcherObj.newdefault(51, 150, "print", objID + "_" + thisObj.varname.substring(0, (thisObj.varname.indexOf("_print_msgIn_gate"))));
			aPatcherObj.connect(thisObj, 0, newDebugPrintObj, 0);
			newDebugPrintObj.message("created");
		}
		else if(thisObj.maxclass == "patcher")
		{
			var tagExt = "";
			if(thisObj.varname.indexOf("musicPlayer") != -1)
			{
				tagExt = "_music";
			}
			if(thisObj.varname.indexOf("fxPlayer") != -1)
			{
				tagExt = "_fx";
			}
			var x = this.createDebugObject(thisObj.subpatcher(), objID + tagExt);
		}
		i++;
	}while(i<j)
	return 1;
}


//add a new line to every post to make it more useful, er... readable
function mp(msg)
{
	post();
	post(msg);
}