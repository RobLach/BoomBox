{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 940.0, 97.0, 809.0, 501.0 ],
		"bglocked" : 0,
		"defrect" : [ 940.0, 97.0, 809.0, 501.0 ],
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
					"text" : "class, note, amp, posX, posY, distance",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 468.0, 261.0, 231.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-19"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "note, amp",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 432.0, 228.0, 64.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-18"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "input list will grow with further development",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 364.0, 54.0, 239.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-59"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "class, pattNo, posX, posY, distance",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 438.0, 146.0, 199.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-63"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "unpack a 0.",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 357.0, 228.0, 73.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-17",
					"outlettype" : [ "", "float" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "pack a 0 0. 0. 0. 0.",
					"fontname" : "Arial",
					"numinlets" : 6,
					"patching_rect" : [ 335.0, 261.0, 130.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-16",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 470.0, 328.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-14",
					"comment" : ""
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 443.0, 328.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-15",
					"comment" : ""
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 416.0, 328.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-12",
					"comment" : ""
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 389.0, 328.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-13",
					"comment" : ""
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 362.0, 328.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-11",
					"comment" : ""
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 335.0, 328.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-7",
					"comment" : ""
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "patMod",
					"text" : "patternModifiers",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 357.0, 206.0, 97.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-10",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "cs",
					"text" : "channelStrip",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 335.0, 290.0, 154.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"id" : "obj-6",
					"outlettype" : [ "signal", "signal", "", "", "", "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r printDebug",
					"fontname" : "Arial",
					"numinlets" : 0,
					"patching_rect" : [ 30.0, 33.0, 78.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-9",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numinlets" : 1,
					"patching_rect" : [ 30.0, 57.0, 20.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-8",
					"outlettype" : [ "int" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "aPlayer_print_msgIn_gate",
					"text" : "gate",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 30.0, 86.0, 35.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-4",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "patPl",
					"text" : "patternPlayer",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 358.0, 183.0, 82.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-3",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "unpack a 0 0. 0. 0.",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 335.0, 147.0, 109.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 5,
					"id" : "obj-1",
					"outlettype" : [ "", "int", "float", "float", "float" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 335.0, 52.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"id" : "obj-2",
					"outlettype" : [ "" ],
					"comment" : "list of avatar info input"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-6", 5 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 4 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 3 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 2 ],
					"destination" : [ "obj-13", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
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
					"destination" : [ "obj-7", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 1 ],
					"destination" : [ "obj-16", 2 ],
					"hidden" : 0,
					"midpoints" : [ 420.5, 249.0, 388.899994, 249.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
					"destination" : [ "obj-16", 1 ],
					"hidden" : 0,
					"midpoints" : [ 366.5, 249.0, 366.700012, 249.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 4 ],
					"destination" : [ "obj-16", 5 ],
					"hidden" : 0,
					"midpoints" : [ 434.5, 168.0, 558.0, 168.0, 558.0, 258.0, 455.5, 258.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 3 ],
					"destination" : [ "obj-16", 4 ],
					"hidden" : 0,
					"midpoints" : [ 412.0, 174.0, 551.0, 174.0, 551.0, 255.0, 433.299988, 255.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 2 ],
					"destination" : [ "obj-16", 3 ],
					"hidden" : 0,
					"midpoints" : [ 389.5, 180.0, 545.0, 180.0, 545.0, 252.0, 411.100006, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 1 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
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
					"destination" : [ "obj-4", 1 ],
					"hidden" : 0,
					"midpoints" : [ 344.5, 80.0, 55.5, 80.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-17", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
