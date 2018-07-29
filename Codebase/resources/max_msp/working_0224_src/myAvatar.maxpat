{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 249.0, 320.0, 1410.0, 477.0 ],
		"bglocked" : 0,
		"defrect" : [ 249.0, 320.0, 1410.0, 477.0 ],
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
					"text" : "loadbang",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 712.0, 7.0, 60.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-24",
					"outlettype" : [ "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "initializeMe",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 712.0, 32.0, 70.0, 18.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-23",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "compile",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 641.0, 29.0, 54.0, 18.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-22",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "open",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 614.0, 9.0, 39.0, 18.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-32",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "js myAvatar.js",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 598.0, 69.0, 85.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-29",
					"outlettype" : [ "", "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "class, pattNo",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 178.0, 92.0, 80.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-63"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "input list will grow with further development",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 134.0, 54.0, 239.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-59"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "class, pattNo,statically declaring 3 positional args to 0",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 196.0, 134.0, 297.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-50"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "outputScalar",
					"fontname" : "Arial",
					"numinlets" : 7,
					"patching_rect" : [ 308.0, 219.0, 220.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"id" : "obj-49",
					"outlettype" : [ "signal", "signal", "signal", "signal", "signal", "signal" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "outputScalar",
					"fontname" : "Arial",
					"numinlets" : 7,
					"patching_rect" : [ 860.0, 219.0, 220.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"id" : "obj-48",
					"outlettype" : [ "signal", "signal", "signal", "signal", "signal", "signal" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 1248.0, 48.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"id" : "obj-43",
					"outlettype" : [ "" ],
					"comment" : "ui fx lvl"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "sub group volume scalar for ui SFX",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 1115.0, 195.0, 198.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-44"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"varname" : "myavatar_sfx_amplitude_level[1]",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 1062.0, 195.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-47",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 509.0, 52.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"id" : "obj-1",
					"outlettype" : [ "" ],
					"comment" : "my avatar's fx lvl"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "sub group volume scalar for my avatar's SFX",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 562.0, 164.0, 250.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-26"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"varname" : "myavatar_sfx_amplitude_level",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 509.0, 165.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-21",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "would probably need to preprocess or do some kind of lookup (i.e. what effect for which key pressed) based on message from client before sending UI sfx message list to pattern player",
					"linecount" : 3,
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 862.0, 83.0, 349.0, 48.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-42"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "UI SFX",
					"fontname" : "Arial Bold",
					"numinlets" : 1,
					"patching_rect" : [ 863.0, 45.0, 185.0, 34.0 ],
					"fontsize" : 24.0,
					"numoutlets" : 0,
					"id" : "obj-25"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "our pattern player is general enough at the moment to work for UI sounds rather nicely, just need to create specific instrument(s) to play UI sfx",
					"linecount" : 3,
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 952.0, 140.0, 300.0, 48.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-9"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "ui_sfx_player",
					"text" : "aPlayer",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 859.0, 195.0, 187.5, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"id" : "obj-6",
					"outlettype" : [ "signal", "signal", "", "", "", "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 859.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-35",
					"comment" : "ui sfx out 1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 899.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-36",
					"comment" : "ui sfx out 2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 941.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-37",
					"comment" : "ui sfx out 3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 982.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-38",
					"comment" : "ui sfx out 4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 1022.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-39",
					"comment" : "ui sfx out 5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 1063.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-40",
					"comment" : "ui sfx out 6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "avatar_0",
					"text" : "anAvatar",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 104.0, 194.0, 391.5, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 12,
					"id" : "obj-41",
					"outlettype" : [ "signal", "signal", "", "", "", "", "signal", "signal", "", "", "", "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 509.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-10",
					"comment" : "fx out 6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 469.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-16",
					"comment" : "fx out 5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 429.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-17",
					"comment" : "fx out 4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 388.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-18",
					"comment" : "fx out 3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 348.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-19",
					"comment" : "fx out 2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 308.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-20",
					"comment" : "fx out 1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack a 0 0. 0. 0.",
					"fontname" : "Arial",
					"numinlets" : 5,
					"patching_rect" : [ 859.0, 164.0, 96.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-5",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack a 0 0. 0. 0.",
					"fontname" : "Arial",
					"numinlets" : 5,
					"patching_rect" : [ 104.0, 135.0, 96.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-4",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "unpack a 0",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 104.0, 93.0, 69.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-3",
					"outlettype" : [ "", "int" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 273.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-14",
					"comment" : "music out 6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 239.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-15",
					"comment" : "music out 5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 206.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-12",
					"comment" : "music out 4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 172.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-13",
					"comment" : "music out 3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 138.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-11",
					"comment" : "music out 2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 104.0, 246.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-7",
					"comment" : "music out 1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 104.0, 52.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"id" : "obj-2",
					"outlettype" : [ "" ],
					"comment" : "message list"
				}

			}
 ],
		"lines" : [ 			{
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
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-48", 0 ],
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
					"source" : [ "obj-6", 2 ],
					"destination" : [ "obj-48", 2 ],
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
					"source" : [ "obj-6", 4 ],
					"destination" : [ "obj-48", 4 ],
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
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-49", 6 ],
					"hidden" : 0,
					"midpoints" : [  ]
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
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-41", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
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
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-3", 0 ],
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
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-4", 0 ],
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
 ]
	}

}
