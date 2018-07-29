//globals
outlets = 5;
setoutletassist(0, "other avatars");
setoutletassist(1, "my avatar");
setoutletassist(2, "mixer");
setoutletassist(3, "my avatar");
setoutletassist(4, "mixer");
var myval=0;


if (jsarguments.length>1)
    myval = jsarguments[1];

function bang()
{
    mp("myvalue is " + myval);
}

function msg_int(v)
{
    mp("received and am ignoring int " + v);
    bang();
}

function msg_float(v)
{
    mp("received and am ignoring float " + v);
    bang();
}

function list()
{
    var a = arrayfromargs(arguments);
    mp("received and am ignoring list " + a);
    bang();
}

function anything()
{
    objList = messagename.split("//");
    //parse multiple messages into individuals
    for(i=0;i<objList.length;i++)
    {
    	//initialize output arrays
		out0List = new Array();
		out1List = new Array();
		out2List = new Array();
		out3List = new Array();
		out4List = new Array();
		//filter out garbage we aren't gonna understand
    	if(objList[i].length > 0)
    	{
    		//explicitly pull out the key value pairs of the message
			paramsList 	= objList[i].split(":")[1];
			kvPairs		= paramsList.split("&");
			
			//account for handling differences based on object type
			switch(objList[i].split(":")[0])
			{
				case "myavatar":
					//loop through the key value pairs
					for(j=0;j<kvPairs.length;j++)
					{
						//build an array out of our values
						switch(kvPairs[j].split("=")[0])
						{
							case "class":
								out1List[0] = kvPairs[j].split("=")[1];
								break;
								
							case "patternNumber":
								out1List[1] = parseInt(kvPairs[j].split("=")[1]);
								break;
								
							case "instrument":
								out1List[2] = parseInt(kvPairs[j].split("=")[1]);
								break;
								
							case "speed":
								out1List[3] = parseFloat(kvPairs[j].split("=")[1]);
								break;
								
							case "fxNumber":
								out1List[4] = parseInt(kvPairs[j].split("=")[1]);
								break;
								
							case "fxInstrument":
								out1List[5] = parseInt(kvPairs[j].split("=")[1]);
								break;
							
							default:
								break;
						}
					}
					break;
					
				case "otheravatar":
					//loop through the key value pairs
					for(j=0;j<kvPairs.length;j++)
					{
						//build an array out of our values
						switch(kvPairs[j].split("=")[0])
						{
							case "id":
								out0List[0] = parseInt(kvPairs[j].split("=")[1]);
								break;
								
							case "class":
								out0List[1] = kvPairs[j].split("=")[1];
								break;
								
							case "patternNumber":
								out0List[2] = parseInt(kvPairs[j].split("=")[1]);
								break;
								
							case "instrument":
								out0List[3] = parseInt(kvPairs[j].split("=")[1]);
								break;
								
							case "position":
								myCoords = kvPairs[j].split("=")[1].split("|");
								out0List[4] = parseFloat(myCoords[0]);
								out0List[5] = parseFloat(myCoords[1]);
								break;
								
							case "distance":
								out0List[6] = parseFloat(kvPairs[j].split("=")[1]);
								break;
								
							case "speed":
								out0List[7] = parseFloat(kvPairs[j].split("=")[1]);
								break;
								
							case "fxNumber":
								out0List[8] = parseInt(kvPairs[j].split("=")[1]);
								break;
								
							case "fxInstrument":
								out0List[9] = parseInt(kvPairs[j].split("=")[1]);
								break;
								
							
							default:
								break;
						}
					}
					break;
					
				case "mixer":
					//loop through the key value pairs
					for(j=0;j<kvPairs.length;j++)
					{
						//build an array out of our values
						switch(kvPairs[j].split("=")[0])
						{
							case "music":
								out2List[0] = parseFloat(kvPairs[j].split("=")[1]);
								break;
								
							case "my_avatar_sfx_submaster":
								out2List[1] = parseFloat(kvPairs[j].split("=")[1]);
								break;
								
							case "ui_sfx_submaster":
								out2List[2] = parseFloat(kvPairs[j].split("=")[1]);
								break;
								
							case "sfx_master":
								out2List[3] = parseFloat(kvPairs[j].split("=")[1]);
								break;
								
							case "ambient":
								out2List[4] = parseFloat(kvPairs[j].split("=")[1]);
								break;
								
							case "master":
								out2List[5] = parseFloat(kvPairs[j].split("=")[1]);
								break;
							
							default:
								break;
						}
					}
					break;
					
				case "editor":
					//loop through the key value pairs
					for(j=0;j<kvPairs.length;j++)
					{
						//build an array out of our values
						switch(kvPairs[j].split("=")[0])
						{
							case "requestPat":
								out3List[0] = parseInt(kvPairs[j].split("=")[1]);
								break;
								
							case "requestInst":
								out3List[1] = parseInt(kvPairs[j].split("=")[1]);
								break;
							
							default:
								break;
						}
					}
					break;
					
				case "uifx":
					//loop through the key value pairs
					for(j=0;j<kvPairs.length;j++)
					{
						//build an array out of our values
						switch(kvPairs[j].split("=")[0])
						{
							case "fxType":
								out4List[0] = kvPairs[j].split("=")[1];
								break;
								
							case "fxNumber":
								out4List[1] = parseInt(kvPairs[j].split("=")[1]);
								break;
							
							default:
								break;
						}
					}
					break;
					
				default:
					break;
			}
		}
		//send appropriate arrays out appropriate outlets
		outlet(0, out0List);
		outlet(1, out1List);
		outlet(2, out2List);
		outlet(3, out3List);
		outlet(4, out4List);
    }
    
    //if you wanna debug, use the functionality already in the Max patch
    //if you need to do it from here, uncomment the assignment and bang() call below, 
    //and recompile script from within oscReceiver object
    //myval = messagename;
    //bang();
}

//add a new line to every post to make it more useful, er... readable
function mp(msg)
{
	post();
	post(msg);
}