
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
gObjects.deletedObjCount			= 0;
gObjects.idArray					= new Array();

initializedFlag = false;


function initializeMe()
{
	if(!initializedFlag)
	{
		thisObj		= this.patcher.firstobject;
		i = 0;
		j = this.patcher.count;
		do
		{
			if(i!=0){thisObj = thisObj.nextobject;}
			if(thisObj.maxclass == "patcher" && thisObj.varname.indexOf("avatar_0") != -1)
			{
				this.createDebugObject(thisObj.subpatcher(), "MyAvatar");
			}
			if(thisObj.maxclass == "patcher" && thisObj.varname.indexOf("ui_sfx_player") != -1)
			{
				this.createDebugObject(thisObj.subpatcher(), "UI_SFX");
			}
			i++;
		}while(i<j)
		initializedFlag						= true;
	}

}

function resetMe()
{
	initializedFlag = false;
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
			newDebugPrintObj 		= aPatcherObj.newdefault(51, 100, "print", objID + "_" + thisObj.varname.substring(0, (thisObj.varname.indexOf("_print_msgIn_gate"))));
			aPatcherObj.connect(thisObj, 0, newDebugPrintObj, 0);
			newDebugPrintObj.message("created");
			//return 0;
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
		else if(thisObj.varname.indexOf("pattern_player_matrix") != -1)
		{
			thisObj.message("name", "pattern_player_matrix_" + objID);
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