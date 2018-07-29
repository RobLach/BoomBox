{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 547.0, 206.0, 1208.0, 543.0 ],
		"bglocked" : 0,
		"defrect" : [ 547.0, 206.0, 1208.0, 543.0 ],
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
					"maxclass" : "message",
					"text" : "$1 20",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 387.0, 268.0, 41.0, 18.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-44",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "line~ 0.",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 387.0, 290.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-45",
					"outlettype" : [ "signal", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess 10.",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 638.0, 133.0, 82.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-43",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess 10.",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 417.0, 133.0, 82.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-42",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadmess 14.",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 859.0, 132.0, 82.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-40",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "$1 20",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 830.0, 268.0, 41.0, 18.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-41",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "line~ 0.",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 830.0, 290.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-37",
					"outlettype" : [ "signal", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 830.0, 244.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-39",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 388.0, 246.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-38",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "meter~",
					"numinlets" : 1,
					"patching_rect" : [ 406.0, 416.0, 12.0, 85.0 ],
					"numoutlets" : 1,
					"id" : "obj-36",
					"outlettype" : [ "float" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "meter~",
					"numinlets" : 1,
					"patching_rect" : [ 343.0, 414.0, 12.0, 85.0 ],
					"numoutlets" : 1,
					"id" : "obj-35",
					"outlettype" : [ "float" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r printDebug",
					"fontname" : "Arial",
					"numinlets" : 0,
					"patching_rect" : [ 51.0, 42.0, 78.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-30",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numinlets" : 1,
					"patching_rect" : [ 51.0, 66.0, 20.0, 20.0 ],
					"numoutlets" : 1,
					"id" : "obj-33",
					"outlettype" : [ "int" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"varname" : "spat_print_msgIn_gate",
					"text" : "gate",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 51.0, 95.0, 35.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-34",
					"outlettype" : [ "" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "signal in",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 243.0, 62.0, 58.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-28"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "posX, posY, distance",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 483.0, 94.0, 123.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-22"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "input list might grow with further development",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 421.0, 60.0, 251.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"id" : "obj-16"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "DISTANCE",
					"fontname" : "Arial Bold",
					"numinlets" : 1,
					"patching_rect" : [ 1033.0, 162.0, 103.0, 27.0 ],
					"fontsize" : 18.0,
					"numoutlets" : 0,
					"id" : "obj-25"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Y",
					"fontname" : "Arial Bold",
					"numinlets" : 1,
					"patching_rect" : [ 584.0, 185.0, 23.0, 27.0 ],
					"fontsize" : 18.0,
					"numoutlets" : 0,
					"id" : "obj-24"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "X",
					"fontname" : "Arial Bold",
					"numinlets" : 1,
					"patching_rect" : [ 364.0, 187.0, 23.0, 27.0 ],
					"fontsize" : 18.0,
					"numoutlets" : 0,
					"id" : "obj-23"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "unpack 0. 0. 0.",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 388.0, 94.0, 89.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 3,
					"id" : "obj-21",
					"outlettype" : [ "float", "float", "float" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "*~ 0.",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 371.0, 385.0, 36.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-31",
					"outlettype" : [ "signal" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "*~ 0.",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 307.0, 385.0, 36.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-32",
					"outlettype" : [ "signal" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"varname" : "amplitude_radius_rolloff_coefficient",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 973.0, 142.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-26",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"varname" : "amplitude_max_usable_radius",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 859.0, 194.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-27",
					"outlettype" : [ "int", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "scale 100. 0. 0. 1. 1.",
					"fontname" : "Arial",
					"numinlets" : 6,
					"patching_rect" : [ 830.0, 220.0, 162.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-29",
					"outlettype" : [ "float" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 637.0, 415.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-19",
					"comment" : "(~)ch.6 signal out"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 573.0, 415.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-20",
					"comment" : "(~)ch.5 signal out"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 503.0, 415.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-17",
					"comment" : "(~)ch.4 signal out"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 439.0, 415.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-18",
					"comment" : "(~)ch.3 signal out"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"varname" : "spatial_spread_rolloff_Ycoefficient",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 752.0, 142.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-9",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"varname" : "spatial_spread_Ycoefficient",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 638.0, 160.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-11",
					"outlettype" : [ "int", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "* -1",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 638.0, 192.0, 32.5, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-12",
					"outlettype" : [ "int" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "scale -100 100 0. 1. 1.",
					"fontname" : "Arial",
					"numinlets" : 6,
					"patching_rect" : [ 609.0, 220.0, 162.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-14",
					"outlettype" : [ "float" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"varname" : "spatial_spread_rolloff_Xcoefficient",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 531.0, 142.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-10",
					"outlettype" : [ "float", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"varname" : "spatial_spread_Xcoefficient",
					"fontname" : "Arial",
					"numinlets" : 1,
					"patching_rect" : [ 417.0, 162.0, 50.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"id" : "obj-15",
					"outlettype" : [ "int", "bang" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "* -1",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 417.0, 192.0, 32.5, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-13",
					"outlettype" : [ "int" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "!-~ 1.",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 324.0, 322.0, 38.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-8",
					"outlettype" : [ "signal" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "scale -100 100 0. 1. 1.",
					"fontname" : "Arial",
					"numinlets" : 6,
					"patching_rect" : [ 388.0, 220.0, 162.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-7",
					"outlettype" : [ "float" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "*~ 0.",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 371.0, 347.0, 36.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-6",
					"outlettype" : [ "signal" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "*~ 0.",
					"fontname" : "Arial",
					"numinlets" : 2,
					"patching_rect" : [ 307.0, 347.0, 36.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"id" : "obj-5",
					"outlettype" : [ "signal" ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 388.0, 58.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"id" : "obj-1",
					"outlettype" : [ "" ],
					"comment" : "(int)spatialX"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 371.0, 415.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-4",
					"comment" : "(~)ch.2 signal out"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 307.0, 415.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-3",
					"comment" : "(~)ch.1 signal out"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 307.0, 58.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"id" : "obj-2",
					"outlettype" : [ "" ],
					"comment" : "(~)signal in"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-32", 1 ],
					"hidden" : 0,
					"midpoints" : [ 839.5, 381.0, 357.0, 381.0, 357.0, 381.0, 333.5, 381.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-31", 1 ],
					"hidden" : 0,
					"midpoints" : [ 839.5, 381.0, 397.5, 381.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 0 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-45", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [ 396.5, 316.0, 333.5, 316.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-5", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-45", 0 ],
					"destination" : [ "obj-6", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-44", 0 ],
					"destination" : [ "obj-45", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-42", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-40", 0 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 2 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [ 467.5, 129.0, 839.5, 129.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 1 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [ 432.5, 129.0, 618.5, 129.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-7", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-39", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
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
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-7", 5 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-6", 0 ],
					"hidden" : 0,
					"midpoints" : [ 316.5, 252.0, 380.5, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-13", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-7", 2 ],
					"hidden" : 0,
					"midpoints" : [ 426.5, 185.0, 454.700012, 185.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-13", 0 ],
					"destination" : [ "obj-7", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 0 ],
					"destination" : [ "obj-14", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 0 ],
					"destination" : [ "obj-14", 2 ],
					"hidden" : 0,
					"midpoints" : [ 647.5, 185.0, 675.700012, 185.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-14", 5 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-32", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-29", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-29", 5 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-30", 0 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-33", 0 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-34", 1 ],
					"hidden" : 0,
					"midpoints" : [ 397.5, 88.0, 76.5, 88.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-36", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-39", 0 ],
					"destination" : [ "obj-41", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 0 ],
					"destination" : [ "obj-44", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
