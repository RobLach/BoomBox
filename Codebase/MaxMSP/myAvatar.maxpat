{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 355.0, 519.0, 1410.0, 477.0 ],
		"bglocked" : 0,
		"defrect" : [ 355.0, 519.0, 1410.0, 477.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"metadata" : [  ],
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "unpack 0 0.",
					"fontsize" : 12.0,
					"outlettype" : [ "int", "float" ],
					"patching_rect" : [ 556.0, 227.0, 73.0, 20.0 ],
					"id" : "obj-52",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "col $1",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 669.0, 422.0, 43.0, 18.0 ],
					"id" : "obj-61",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "begin_pattern",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 758.0, 424.0, 84.0, 18.0 ],
					"id" : "obj-58",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "sel 0",
					"fontsize" : 12.0,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 758.0, 267.0, 36.0, 20.0 ],
					"id" : "obj-56",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r boomClock",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 758.0, 242.0, 78.0, 20.0 ],
					"id" : "obj-86",
					"fontname" : "Arial",
					"numinlets" : 0,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "B 1 1 0.0.0.",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 34.0, 107.0, 72.0, 18.0 ],
					"id" : "obj-55",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"fontsize" : 12.0,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 34.0, 82.0, 60.0, 20.0 ],
					"id" : "obj-53",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "udpsend 127.0.0.1 7500",
					"fontsize" : 12.0,
					"patching_rect" : [ 610.0, 447.0, 140.0, 20.0 ],
					"id" : "obj-51",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack a 0 0 0. 0. 0.",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 374.0, 135.0, 111.0, 20.0 ],
					"id" : "obj-46",
					"fontname" : "Arial",
					"numinlets" : 6,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "uifx: fxType, fxNumber",
					"fontsize" : 12.0,
					"patching_rect" : [ 587.0, 136.0, 142.0, 20.0 ],
					"id" : "obj-45",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack 0 0",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 591.0, 111.0, 69.0, 20.0 ],
					"id" : "obj-33",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "unpack 0 0",
					"fontsize" : 12.0,
					"outlettype" : [ "int", "int" ],
					"patching_rect" : [ 591.0, 83.0, 69.0, 20.0 ],
					"id" : "obj-34",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack 0 0",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 514.0, 111.0, 69.0, 20.0 ],
					"id" : "obj-31",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "editor: pattNo, instr",
					"fontsize" : 12.0,
					"patching_rect" : [ 406.0, 83.0, 112.0, 20.0 ],
					"id" : "obj-28",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "unpack 0 0",
					"fontsize" : 12.0,
					"outlettype" : [ "int", "int" ],
					"patching_rect" : [ 514.0, 83.0, 69.0, 20.0 ],
					"id" : "obj-30",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"outlettype" : [ "" ],
					"patching_rect" : [ 590.0, 50.0, 25.0, 25.0 ],
					"id" : "obj-27",
					"numinlets" : 0,
					"numoutlets" : 1,
					"comment" : "fx control info in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"outlettype" : [ "" ],
					"patching_rect" : [ 515.0, 51.0, 25.0, 25.0 ],
					"id" : "obj-8",
					"numinlets" : 0,
					"numoutlets" : 1,
					"comment" : "control info in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"fontsize" : 12.0,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 1257.0, 270.0, 60.0, 20.0 ],
					"id" : "obj-24",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "initializeMe",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1257.0, 295.0, 70.0, 18.0 ],
					"id" : "obj-23",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "compile",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1186.0, 292.0, 54.0, 18.0 ],
					"id" : "obj-22",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "open",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1159.0, 272.0, 39.0, 18.0 ],
					"id" : "obj-32",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "js myAvatar.js",
					"fontsize" : 12.0,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 1143.0, 332.0, 85.0, 20.0 ],
					"id" : "obj-29",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "class, pattNo, instr, speed, fxPattern, fxInstr",
					"fontsize" : 12.0,
					"patching_rect" : [ 217.0, 94.0, 243.0, 20.0 ],
					"id" : "obj-63",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "input list will grow with further development",
					"fontsize" : 12.0,
					"patching_rect" : [ 134.0, 54.0, 239.0, 20.0 ],
					"id" : "obj-59",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "class, pattNo, instr, statically declaring 3 positional args to 0",
					"linecount" : 5,
					"fontsize" : 12.0,
					"patching_rect" : [ 9.0, 136.0, 89.0, 75.0 ],
					"id" : "obj-50",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "outputScalar",
					"fontsize" : 12.0,
					"outlettype" : [ "signal", "signal", "", "", "", "" ],
					"patching_rect" : [ 308.0, 238.0, 220.0, 20.0 ],
					"id" : "obj-49",
					"fontname" : "Arial",
					"numinlets" : 7,
					"numoutlets" : 6
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "outputScalar",
					"fontsize" : 12.0,
					"outlettype" : [ "signal", "signal", "", "", "", "" ],
					"patching_rect" : [ 860.0, 219.0, 220.0, 20.0 ],
					"id" : "obj-48",
					"fontname" : "Arial",
					"numinlets" : 7,
					"numoutlets" : 6
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"outlettype" : [ "" ],
					"patching_rect" : [ 1248.0, 48.0, 25.0, 25.0 ],
					"id" : "obj-43",
					"numinlets" : 0,
					"numoutlets" : 1,
					"comment" : "ui fx lvl"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "sub group volume scalar for ui SFX",
					"fontsize" : 12.0,
					"patching_rect" : [ 1115.0, 195.0, 198.0, 20.0 ],
					"id" : "obj-44",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"varname" : "myavatar_sfx_amplitude_level[1]",
					"fontsize" : 12.0,
					"outlettype" : [ "float", "bang" ],
					"patching_rect" : [ 1062.0, 195.0, 50.0, 20.0 ],
					"id" : "obj-47",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"outlettype" : [ "" ],
					"patching_rect" : [ 790.0, 52.0, 25.0, 25.0 ],
					"id" : "obj-1",
					"numinlets" : 0,
					"numoutlets" : 1,
					"comment" : "my avatar's fx lvl"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "sub group volume scalar for my avatar's SFX",
					"fontsize" : 12.0,
					"patching_rect" : [ 540.0, 165.0, 250.0, 20.0 ],
					"id" : "obj-26",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"varname" : "myavatar_sfx_amplitude_level",
					"fontsize" : 12.0,
					"outlettype" : [ "float", "bang" ],
					"patching_rect" : [ 790.0, 165.0, 50.0, 20.0 ],
					"id" : "obj-21",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "would probably need to preprocess or do some kind of lookup (i.e. what effect for which key pressed) based on message from client before sending UI sfx message list to pattern player",
					"linecount" : 3,
					"fontsize" : 12.0,
					"patching_rect" : [ 862.0, 83.0, 349.0, 48.0 ],
					"id" : "obj-42",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "UI SFX",
					"fontsize" : 24.0,
					"patching_rect" : [ 863.0, 45.0, 185.0, 34.0 ],
					"id" : "obj-25",
					"fontname" : "Arial Bold",
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "our pattern player is general enough at the moment to work for UI sounds rather nicely, just need to create specific instrument(s) to play UI sfx",
					"linecount" : 3,
					"fontsize" : 12.0,
					"patching_rect" : [ 952.0, 140.0, 300.0, 48.0 ],
					"id" : "obj-9",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "ui_sfx_player",
					"text" : "aPlayer",
					"fontsize" : 12.0,
					"outlettype" : [ "signal", "signal", "", "", "", "", "list" ],
					"patching_rect" : [ 859.0, 195.0, 187.5, 20.0 ],
					"id" : "obj-6",
					"fontname" : "Arial",
					"numinlets" : 2,
					"numoutlets" : 7
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 859.0, 246.0, 25.0, 25.0 ],
					"id" : "obj-35",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "ui sfx out 1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 899.0, 246.0, 25.0, 25.0 ],
					"id" : "obj-36",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "ui sfx out 2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 941.0, 246.0, 25.0, 25.0 ],
					"id" : "obj-37",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "ui sfx out 3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 982.0, 246.0, 25.0, 25.0 ],
					"id" : "obj-38",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "ui sfx out 4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 1022.0, 246.0, 25.0, 25.0 ],
					"id" : "obj-39",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "ui sfx out 5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 1063.0, 246.0, 25.0, 25.0 ],
					"id" : "obj-40",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "ui sfx out 6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "avatar_0",
					"text" : "anAvatar",
					"fontsize" : 12.0,
					"outlettype" : [ "signal", "signal", "", "", "", "", "signal", "signal", "", "", "", "", "list" ],
					"patching_rect" : [ 104.0, 194.0, 424.5, 20.0 ],
					"id" : "obj-41",
					"fontname" : "Arial",
					"numinlets" : 4,
					"numoutlets" : 13
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 509.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-10",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "fx out 6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 469.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-16",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "fx out 5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 429.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-17",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "fx out 4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 388.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-18",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "fx out 3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 348.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-19",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "fx out 2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 308.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-20",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "fx out 1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack a 0 0. 0. 0.",
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 859.0, 164.0, 96.0, 20.0 ],
					"id" : "obj-5",
					"fontname" : "Arial",
					"numinlets" : 5,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack a 0 0 0. 0. 0.",
					"fontsize" : 12.326273,
					"outlettype" : [ "" ],
					"patching_rect" : [ 104.0, 134.819824, 113.0, 21.0 ],
					"id" : "obj-4",
					"fontname" : "Arial",
					"numinlets" : 6,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "unpack a 0 0 0. 0 0",
					"fontsize" : 12.0,
					"outlettype" : [ "", "int", "int", "float", "int", "int" ],
					"patching_rect" : [ 104.0, 93.0, 113.0, 20.0 ],
					"id" : "obj-3",
					"fontname" : "Arial",
					"numinlets" : 1,
					"numoutlets" : 6
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 273.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-14",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "music out 6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 239.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-15",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "music out 5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 206.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-12",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "music out 4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 172.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-13",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "music out 3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 138.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-11",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "music out 2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"patching_rect" : [ 104.0, 265.0, 25.0, 25.0 ],
					"id" : "obj-7",
					"numinlets" : 1,
					"numoutlets" : 0,
					"comment" : "music out 1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"outlettype" : [ "" ],
					"patching_rect" : [ 104.0, 52.0, 25.0, 25.0 ],
					"id" : "obj-2",
					"numinlets" : 0,
					"numoutlets" : 1,
					"comment" : "message list"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-52", 1 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-86", 0 ],
					"destination" : [ "obj-61", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-61", 0 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-58", 0 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-56", 0 ],
					"destination" : [ "obj-58", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-86", 0 ],
					"destination" : [ "obj-56", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-34", 0 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-34", 1 ],
					"destination" : [ "obj-33", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 1 ],
					"destination" : [ "obj-31", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-49", 6 ],
					"hidden" : 0,
					"midpoints" : [ 799.5, 233.0, 518.5, 233.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-49", 5 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-49", 4 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-49", 3 ],
					"destination" : [ "obj-17", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-49", 2 ],
					"destination" : [ "obj-18", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-49", 1 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-49", 0 ],
					"destination" : [ "obj-20", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 5 ],
					"destination" : [ "obj-40", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 4 ],
					"destination" : [ "obj-39", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 3 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 2 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 1 ],
					"destination" : [ "obj-36", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 0 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-47", 0 ],
					"destination" : [ "obj-48", 6 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 0 ],
					"destination" : [ "obj-47", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1257.5, 191.0, 1121.0, 191.0, 1121.0, 191.0, 1071.5, 191.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-24", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 2 ],
					"destination" : [ "obj-4", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 1 ],
					"destination" : [ "obj-4", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-46", 0 ],
					"hidden" : 0,
					"midpoints" : [ 113.5, 126.0, 339.0, 126.0, 339.0, 126.0, 383.5, 126.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 4 ],
					"destination" : [ "obj-46", 1 ],
					"hidden" : 0,
					"midpoints" : [ 188.699997, 126.0, 339.0, 126.0, 339.0, 126.0, 401.899994, 126.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 5 ],
					"destination" : [ "obj-46", 2 ],
					"hidden" : 0,
					"midpoints" : [ 207.5, 126.0, 339.0, 126.0, 339.0, 126.0, 420.299988, 126.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 5 ],
					"destination" : [ "obj-48", 5 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 4 ],
					"destination" : [ "obj-48", 4 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 3 ],
					"destination" : [ "obj-48", 3 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 2 ],
					"destination" : [ "obj-48", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 1 ],
					"destination" : [ "obj-48", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-48", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-46", 0 ],
					"destination" : [ "obj-41", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 0 ],
					"destination" : [ "obj-7", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 1 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 2 ],
					"destination" : [ "obj-13", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 3 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 4 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 5 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 11 ],
					"destination" : [ "obj-49", 5 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 10 ],
					"destination" : [ "obj-49", 4 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 9 ],
					"destination" : [ "obj-49", 3 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 8 ],
					"destination" : [ "obj-49", 2 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 7 ],
					"destination" : [ "obj-49", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 6 ],
					"destination" : [ "obj-49", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-41", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-41", 1 ],
					"hidden" : 0,
					"midpoints" : [ 523.5, 180.0, 248.666672, 180.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-53", 0 ],
					"destination" : [ "obj-55", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-55", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 12 ],
					"destination" : [ "obj-52", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
