{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 270.0, 424.0, 1206.0, 554.0 ],
		"bglocked" : 0,
		"defrect" : [ 270.0, 424.0, 1206.0, 554.0 ],
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
					"maxclass" : "comment",
					"text" : "my avatar on/off",
					"numinlets" : 1,
					"patching_rect" : [ 232.0, 230.0, 100.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-25"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "click on box above to toggle audio engine on/off",
					"linecount" : 2,
					"numinlets" : 1,
					"patching_rect" : [ 12.0, 472.0, 150.0, 34.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-27"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"numinlets" : 1,
					"patching_rect" : [ 329.0, 205.0, 60.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"fontname" : "Arial",
					"id" : "obj-19"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numinlets" : 1,
					"patching_rect" : [ 329.0, 230.0, 20.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"id" : "obj-23"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "gate~",
					"numinlets" : 2,
					"patching_rect" : [ 369.0, 235.0, 41.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"fontname" : "Arial",
					"id" : "obj-17"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "gate~",
					"numinlets" : 2,
					"patching_rect" : [ 388.0, 258.0, 41.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"fontname" : "Arial",
					"id" : "obj-15"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "jsui",
					"numinlets" : 1,
					"patching_rect" : [ 18.0, 449.0, 141.0, 16.0 ],
					"jsarguments" : [  ],
					"numoutlets" : 2,
					"filename" : "dacToggle.js",
					"outlettype" : [ "", "" ],
					"id" : "obj-7",
					"presentation_rect" : [ 0.0, 0.0, 63.0, 63.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "meter~",
					"numinlets" : 1,
					"patching_rect" : [ 419.0, 291.0, 12.0, 59.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"id" : "obj-3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "meter~",
					"numinlets" : 1,
					"patching_rect" : [ 391.0, 292.0, 12.0, 58.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"id" : "obj-5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "meter~",
					"numinlets" : 1,
					"patching_rect" : [ 52.0, 204.0, 12.0, 58.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"id" : "obj-1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "meter~",
					"numinlets" : 1,
					"patching_rect" : [ 28.0, 204.0, 12.0, 58.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"id" : "obj-2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "meter~",
					"numinlets" : 1,
					"patching_rect" : [ 183.0, 440.0, 12.0, 85.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"id" : "obj-36"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "meter~",
					"numinlets" : 1,
					"patching_rect" : [ 164.0, 440.0, 12.0, 85.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"id" : "obj-35"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "music, fx, ambient, master",
					"numinlets" : 1,
					"patching_rect" : [ 867.0, 251.0, 151.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-33"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "music, myAvatar fx, ui fx, fx master, ambient, master",
					"numinlets" : 1,
					"patching_rect" : [ 902.0, 180.0, 365.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-32"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack 0. 0. 0. 0.",
					"numinlets" : 4,
					"patching_rect" : [ 773.0, 253.0, 89.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"id" : "obj-30"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "unpack 0. 0. 0. 0. 0. 0.",
					"numinlets" : 1,
					"patching_rect" : [ 773.0, 181.0, 129.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"outlettype" : [ "float", "float", "float", "float", "float", "float" ],
					"fontname" : "Arial",
					"id" : "obj-29"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "dac~ 2",
					"numinlets" : 1,
					"patching_rect" : [ 230.0, 422.0, 47.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-11"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "dac~ 1",
					"numinlets" : 1,
					"patching_rect" : [ 94.0, 422.0, 47.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-8"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "masterMixer",
					"numinlets" : 19,
					"patching_rect" : [ 94.0, 369.0, 698.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"outlettype" : [ "signal", "signal", "", "", "", "" ],
					"fontname" : "Arial",
					"id" : "obj-6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : ";\rmax maxwindow",
					"linecount" : 2,
					"numinlets" : 2,
					"patching_rect" : [ 107.0, 107.0, 99.0, 32.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"id" : "obj-4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"numinlets" : 1,
					"patching_rect" : [ 8.0, 80.0, 60.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"fontname" : "Arial",
					"id" : "obj-13"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "set 7400",
					"numinlets" : 2,
					"patching_rect" : [ 8.0, 107.0, 57.0, 18.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"id" : "obj-12"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "otherAvatars",
					"numinlets" : 1,
					"patching_rect" : [ 8.0, 180.0, 346.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 12,
					"outlettype" : [ "signal", "signal", "", "", "", "", "signal", "signal", "", "", "", "" ],
					"fontname" : "Arial",
					"id" : "obj-10"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "myAvatar",
					"numinlets" : 3,
					"patching_rect" : [ 391.0, 211.0, 337.5, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 18,
					"outlettype" : [ "signal", "signal", "", "", "", "", "signal", "signal", "", "", "", "", "signal", "signal", "", "", "", "" ],
					"fontname" : "Arial",
					"id" : "obj-9"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "debug",
					"numinlets" : 1,
					"patching_rect" : [ 34.0, 27.0, 48.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-22"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "s printDebug",
					"numinlets" : 1,
					"patching_rect" : [ 11.0, 51.0, 79.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-21"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numinlets" : 1,
					"patching_rect" : [ 11.0, 27.0, 20.0, 20.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"id" : "obj-20"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "port #",
					"numinlets" : 1,
					"patching_rect" : [ 61.0, 131.0, 41.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-18"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"numinlets" : 1,
					"patching_rect" : [ 8.0, 130.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"fontname" : "Arial",
					"id" : "obj-16"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "oscReceiver",
					"numinlets" : 1,
					"patching_rect" : [ 8.0, 155.0, 784.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "" ],
					"fontname" : "Arial",
					"id" : "obj-14"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-19", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [ 27.5, 466.0, 15.0, 466.0, 15.0, 418.0, 103.5, 418.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-6", 18 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 13 ],
					"destination" : [ "obj-6", 7 ],
					"hidden" : 0,
					"midpoints" : [ 644.058838, 354.0, 367.555542, 354.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 12 ],
					"destination" : [ "obj-6", 6 ],
					"hidden" : 0,
					"midpoints" : [ 625.323547, 354.0, 329.833344, 354.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 7 ],
					"destination" : [ "obj-6", 7 ],
					"hidden" : 0,
					"midpoints" : [ 531.647034, 354.0, 367.555542, 354.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 6 ],
					"destination" : [ "obj-6", 6 ],
					"hidden" : 0,
					"midpoints" : [ 512.911743, 354.0, 329.833344, 354.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 1 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 6 ],
					"destination" : [ "obj-6", 6 ],
					"hidden" : 0,
					"midpoints" : [ 195.863632, 354.0, 329.833344, 354.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 7 ],
					"destination" : [ "obj-6", 7 ],
					"hidden" : 0,
					"midpoints" : [ 225.590912, 354.0, 367.555542, 354.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-20", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-13", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-13", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [ 17.5, 102.0, 116.5, 102.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 1 ],
					"destination" : [ "obj-9", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 4 ],
					"destination" : [ "obj-30", 2 ],
					"hidden" : 0,
					"midpoints" : [ 870.5, 240.0, 829.166687, 240.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 3 ],
					"destination" : [ "obj-30", 1 ],
					"hidden" : 0,
					"midpoints" : [ 848.5, 240.0, 805.833313, 240.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [ 782.5, 240.0, 782.5, 240.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 2 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 1 ],
					"destination" : [ "obj-9", 1 ],
					"hidden" : 0,
					"midpoints" : [ 804.5, 203.0, 559.75, 203.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 2 ],
					"destination" : [ "obj-9", 2 ],
					"hidden" : 0,
					"midpoints" : [ 826.5, 207.0, 719.0, 207.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 5 ],
					"destination" : [ "obj-30", 3 ],
					"hidden" : 0,
					"midpoints" : [ 892.5, 240.0, 852.5, 240.0 ]
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
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-2", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 1 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 0,
					"midpoints" : [ 17.5, 354.0, 103.5, 354.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 1 ],
					"destination" : [ "obj-6", 1 ],
					"hidden" : 0,
					"midpoints" : [ 47.227272, 201.0, 75.0, 201.0, 75.0, 354.0, 141.222229, 354.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 1 ],
					"destination" : [ "obj-15", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 0,
					"midpoints" : [ 397.5, 288.0, 425.0, 288.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-17", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [ 378.5, 288.0, 397.0, 288.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-6", 1 ],
					"hidden" : 0,
					"midpoints" : [ 397.5, 279.0, 141.222229, 279.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 0,
					"midpoints" : [ 378.5, 267.0, 103.5, 267.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-17", 0 ],
					"hidden" : 0,
					"midpoints" : [ 338.5, 252.0, 354.0, 252.0, 354.0, 231.0, 378.5, 231.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 0,
					"midpoints" : [ 338.5, 252.0, 366.0, 252.0, 366.0, 255.0, 397.5, 255.0 ]
				}

			}
 ]
	}

}
