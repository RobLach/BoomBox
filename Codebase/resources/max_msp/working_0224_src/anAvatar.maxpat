{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 378.0, 492.0, 861.0, 480.0 ],
		"bglocked" : 0,
		"defrect" : [ 378.0, 492.0, 861.0, 480.0 ],
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
					"maxclass" : "meter~",
					"numinlets" : 1,
					"patching_rect" : [ 98.0, 247.0, 12.0, 85.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"id" : "obj-5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "meter~",
					"numinlets" : 1,
					"patching_rect" : [ 74.0, 247.0, 12.0, 85.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"id" : "obj-13"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "class, pattNo, posX, posY, distance",
					"numinlets" : 1,
					"patching_rect" : [ 149.0, 188.0, 199.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-11"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "class, pattNo, posX, posY, distance",
					"numinlets" : 1,
					"patching_rect" : [ 392.0, 116.0, 199.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-63"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "input list will grow with further development",
					"numinlets" : 1,
					"patching_rect" : [ 319.0, 27.0, 239.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-59"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "would probably need to preprocess or do some kind of lookup (i.e. what effect) based on message from client before sending sfx message list to pattern player",
					"linecount" : 3,
					"numinlets" : 1,
					"patching_rect" : [ 396.0, 207.0, 303.0, 48.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-12"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack a 0 0. 0. 0.",
					"numinlets" : 5,
					"patching_rect" : [ 394.0, 271.0, 96.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"id" : "obj-3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack a 0 0. 0. 0.",
					"numinlets" : 5,
					"patching_rect" : [ 55.0, 189.0, 96.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"id" : "obj-7"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "an_avatar_unpacker",
					"text" : "unpack a 0 0. 0. 0.",
					"numinlets" : 1,
					"patching_rect" : [ 287.0, 116.0, 109.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 5,
					"outlettype" : [ "", "int", "float", "float", "float" ],
					"fontname" : "Arial",
					"id" : "obj-10"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r printDebug",
					"numinlets" : 0,
					"patching_rect" : [ 51.0, 6.0, 78.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"id" : "obj-2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numinlets" : 1,
					"patching_rect" : [ 51.0, 30.0, 20.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"id" : "obj-8"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "anAvatar_print_msgIn_gate",
					"text" : "gate",
					"numinlets" : 2,
					"patching_rect" : [ 51.0, 59.0, 35.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"id" : "obj-4",
					"ignoreclick" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "MUSIC",
					"numinlets" : 1,
					"patching_rect" : [ 55.0, 139.0, 88.0, 34.0 ],
					"fontsize" : 24.0,
					"numoutlets" : 0,
					"fontname" : "Arial Bold",
					"id" : "obj-26"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "FX",
					"numinlets" : 1,
					"patching_rect" : [ 399.0, 171.0, 43.0, 34.0 ],
					"fontsize" : 24.0,
					"numoutlets" : 0,
					"fontname" : "Arial Bold",
					"id" : "obj-25"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "our pattern player is general enough at the moment to work for effects rather nicely, just need to create specific instrument(s) to play sfx",
					"linecount" : 3,
					"numinlets" : 1,
					"patching_rect" : [ 552.0, 272.0, 273.0, 48.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-9"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "fxPlayer",
					"text" : "aPlayer",
					"numinlets" : 1,
					"patching_rect" : [ 394.0, 299.0, 155.5, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"outlettype" : [ "signal", "signal", "", "", "", "" ],
					"fontname" : "Arial",
					"id" : "obj-6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "musicPlayer",
					"text" : "aPlayer",
					"numinlets" : 1,
					"patching_rect" : [ 55.0, 220.0, 155.5, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"outlettype" : [ "signal", "signal", "", "", "", "" ],
					"fontname" : "Arial",
					"id" : "obj-1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 287.0, 25.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-27",
					"comment" : "music messages in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 55.0, 355.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-29",
					"comment" : "music out 1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 82.0, 355.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-30",
					"comment" : "music out 2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 109.0, 355.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-31",
					"comment" : "music out 3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 137.0, 355.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-32",
					"comment" : "music out 4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 164.0, 355.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-33",
					"comment" : "music out 5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 192.0, 355.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-34",
					"comment" : "music out 6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 395.0, 434.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-35",
					"comment" : "fx out 1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 422.0, 434.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-36",
					"comment" : "fx out 2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 449.0, 434.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-37",
					"comment" : "fx out 3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 476.0, 434.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-38",
					"comment" : "fx out 4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 503.0, 434.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-39",
					"comment" : "fx out 5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 531.0, 434.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-40",
					"comment" : "fx out 6"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 4 ],
					"destination" : [ "obj-7", 4 ],
					"hidden" : 0,
					"midpoints" : [ 386.5, 174.0, 141.5, 174.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 3 ],
					"destination" : [ "obj-7", 3 ],
					"hidden" : 0,
					"midpoints" : [ 364.0, 174.0, 122.25, 174.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 2 ],
					"destination" : [ "obj-7", 2 ],
					"hidden" : 0,
					"midpoints" : [ 341.5, 174.0, 103.0, 174.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 1 ],
					"destination" : [ "obj-7", 1 ],
					"hidden" : 0,
					"midpoints" : [ 319.0, 174.0, 83.75, 174.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-7", 0 ],
					"hidden" : 0,
					"midpoints" : [ 296.5, 174.0, 64.5, 174.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-4", 1 ],
					"hidden" : 0,
					"midpoints" : [ 296.5, 54.0, 76.5, 54.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 1 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 2 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 3 ],
					"destination" : [ "obj-32", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 4 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 5 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 1 ],
					"destination" : [ "obj-36", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 2 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 3 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 4 ],
					"destination" : [ "obj-39", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 5 ],
					"destination" : [ "obj-40", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-13", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 1 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
