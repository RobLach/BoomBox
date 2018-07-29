{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 266.0, 625.0, 1433.0, 323.0 ],
		"bglocked" : 0,
		"defrect" : [ 266.0, 625.0, 1433.0, 323.0 ],
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
					"text" : "loadmess 0.2",
					"numinlets" : 1,
					"patching_rect" : [ 1221.0, 89.0, 82.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"id" : "obj-2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "unpack 0. 0. 0. 0.",
					"numinlets" : 1,
					"patching_rect" : [ 1074.0, 67.0, 103.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 4,
					"outlettype" : [ "float", "float", "float", "float" ],
					"fontname" : "Arial",
					"id" : "obj-11"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"numinlets" : 1,
					"patching_rect" : [ 1083.0, 242.0, 44.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"id" : "obj-1",
					"minimum" : 0.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "master lvl",
					"numinlets" : 1,
					"patching_rect" : [ 1079.0, 218.0, 62.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "music lvl",
					"numinlets" : 1,
					"patching_rect" : [ 340.0, 131.0, 68.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-9"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"numinlets" : 1,
					"patching_rect" : [ 348.0, 154.0, 44.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"id" : "obj-10",
					"minimum" : 0.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "ambient lvl",
					"numinlets" : 1,
					"patching_rect" : [ 1025.0, 131.0, 68.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-7"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"numinlets" : 1,
					"patching_rect" : [ 1033.0, 154.0, 44.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"id" : "obj-8",
					"minimum" : 0.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "fx lvl",
					"numinlets" : 1,
					"patching_rect" : [ 683.0, 131.0, 34.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"numinlets" : 1,
					"patching_rect" : [ 680.0, 154.0, 44.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"id" : "obj-5",
					"minimum" : 0.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "fxOutput",
					"numinlets" : 1,
					"patching_rect" : [ 391.0, 192.0, 56.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-36"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "outputScalar",
					"numinlets" : 7,
					"patching_rect" : [ 449.0, 192.0, 250.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"outlettype" : [ "signal", "signal", "", "", "", "" ],
					"fontname" : "Arial",
					"id" : "obj-37"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "ambientOutput",
					"numinlets" : 1,
					"patching_rect" : [ 712.0, 193.0, 89.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-34"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "outputScalar",
					"numinlets" : 7,
					"patching_rect" : [ 801.0, 192.0, 250.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"outlettype" : [ "signal", "signal", "", "", "", "" ],
					"fontname" : "Arial",
					"id" : "obj-35"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "musicOutput",
					"numinlets" : 1,
					"patching_rect" : [ 35.0, 192.0, 78.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-33"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "outputScalar",
					"numinlets" : 7,
					"patching_rect" : [ 116.0, 193.0, 250.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"outlettype" : [ "signal", "signal", "", "", "", "" ],
					"fontname" : "Arial",
					"id" : "obj-32"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "masterOutput",
					"numinlets" : 1,
					"patching_rect" : [ 762.0, 268.0, 83.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-31"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "outputScalar",
					"numinlets" : 7,
					"patching_rect" : [ 852.0, 267.0, 250.0, 20.0 ],
					"fontsize" : 12.0,
					"numoutlets" : 6,
					"outlettype" : [ "signal", "signal", "", "", "", "" ],
					"fontname" : "Arial",
					"id" : "obj-29"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 116.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-84",
					"comment" : "ch. 1 music in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 155.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-85",
					"comment" : "ch. 2 music in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 801.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-86",
					"comment" : "ch. 1 ambient in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 193.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-87",
					"comment" : "ch. 3 music in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 840.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-88",
					"comment" : "ch. 2 ambient in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 449.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-89",
					"comment" : "fx in 1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 232.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-90",
					"comment" : "ch. 4 music in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 488.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-91",
					"comment" : "fx in 2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 878.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-92",
					"comment" : "ch. 3 ambient in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 270.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-93",
					"comment" : "ch. 5 music in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 917.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-94",
					"comment" : "ch. 4 ambient in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 526.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-95",
					"comment" : "fx in 3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 309.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-96",
					"comment" : "ch. 6 music in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 565.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-97",
					"comment" : "fx in 4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 955.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-98",
					"comment" : "ch. 5 ambient in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 994.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-99",
					"comment" : "ch. 6 ambient in"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 603.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-100",
					"comment" : "fx in 5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 1074.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-101",
					"comment" : "master amplitude messages"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "inlet",
					"numinlets" : 0,
					"patching_rect" : [ 642.0, 38.0, 25.0, 25.0 ],
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-102",
					"comment" : "fx in 6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 852.0, 293.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-103",
					"comment" : "to hardware 1"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 898.0, 293.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-104",
					"comment" : "to hardware 2"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 944.0, 293.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-105",
					"comment" : "to hardware 3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 991.0, 293.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-106",
					"comment" : "to hardware 4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 1037.0, 293.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-107",
					"comment" : "to hardware 5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "outlet",
					"numinlets" : 1,
					"patching_rect" : [ 1083.0, 293.0, 25.0, 25.0 ],
					"numoutlets" : 0,
					"id" : "obj-108",
					"comment" : "to hardware 6"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1230.5, 204.0, 1065.0, 204.0, 1065.0, 240.0, 1092.5, 240.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1230.5, 111.0, 1011.0, 111.0, 1011.0, 153.0, 1042.5, 153.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1230.5, 111.0, 678.0, 111.0, 678.0, 150.0, 689.5, 150.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1230.5, 111.0, 327.0, 111.0, 327.0, 153.0, 357.5, 153.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-37", 6 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-89", 0 ],
					"destination" : [ "obj-37", 0 ],
					"hidden" : 0,
					"midpoints" : [ 458.5, 63.0, 458.5, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-91", 0 ],
					"destination" : [ "obj-37", 1 ],
					"hidden" : 0,
					"midpoints" : [ 497.5, 63.0, 497.0, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-95", 0 ],
					"destination" : [ "obj-37", 2 ],
					"hidden" : 0,
					"midpoints" : [ 535.5, 63.0, 535.5, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-97", 0 ],
					"destination" : [ "obj-37", 3 ],
					"hidden" : 0,
					"midpoints" : [ 574.5, 63.0, 574.0, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-100", 0 ],
					"destination" : [ "obj-37", 4 ],
					"hidden" : 0,
					"midpoints" : [ 612.5, 63.0, 612.5, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-102", 0 ],
					"destination" : [ "obj-37", 5 ],
					"hidden" : 0,
					"midpoints" : [ 651.5, 63.0, 651.0, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 5 ],
					"destination" : [ "obj-29", 5 ],
					"hidden" : 0,
					"midpoints" : [ 689.5, 252.0, 1054.0, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 4 ],
					"destination" : [ "obj-29", 4 ],
					"hidden" : 0,
					"midpoints" : [ 643.299988, 252.0, 1015.5, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 3 ],
					"destination" : [ "obj-29", 3 ],
					"hidden" : 0,
					"midpoints" : [ 597.099976, 252.0, 977.0, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 2 ],
					"destination" : [ "obj-29", 2 ],
					"hidden" : 0,
					"midpoints" : [ 550.900024, 252.0, 938.5, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 1 ],
					"destination" : [ "obj-29", 1 ],
					"hidden" : 0,
					"midpoints" : [ 504.700012, 252.0, 900.0, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [ 458.5, 252.0, 861.5, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-35", 6 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-86", 0 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"midpoints" : [ 810.5, 63.0, 810.5, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-88", 0 ],
					"destination" : [ "obj-35", 1 ],
					"hidden" : 0,
					"midpoints" : [ 849.5, 63.0, 849.0, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-92", 0 ],
					"destination" : [ "obj-35", 2 ],
					"hidden" : 0,
					"midpoints" : [ 887.5, 63.0, 887.5, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-94", 0 ],
					"destination" : [ "obj-35", 3 ],
					"hidden" : 0,
					"midpoints" : [ 926.5, 63.0, 926.0, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-98", 0 ],
					"destination" : [ "obj-35", 4 ],
					"hidden" : 0,
					"midpoints" : [ 964.5, 63.0, 964.5, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-99", 0 ],
					"destination" : [ "obj-35", 5 ],
					"hidden" : 0,
					"midpoints" : [ 1003.5, 63.0, 1003.0, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 5 ],
					"destination" : [ "obj-29", 5 ],
					"hidden" : 0,
					"midpoints" : [ 1041.5, 252.0, 1054.0, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 4 ],
					"destination" : [ "obj-29", 4 ],
					"hidden" : 0,
					"midpoints" : [ 995.299988, 252.0, 1015.5, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 3 ],
					"destination" : [ "obj-29", 3 ],
					"hidden" : 0,
					"midpoints" : [ 949.099976, 252.0, 977.0, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 2 ],
					"destination" : [ "obj-29", 2 ],
					"hidden" : 0,
					"midpoints" : [ 902.900024, 252.0, 938.5, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 1 ],
					"destination" : [ "obj-29", 1 ],
					"hidden" : 0,
					"midpoints" : [ 856.700012, 252.0, 900.0, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [ 810.5, 252.0, 861.5, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-32", 6 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-84", 0 ],
					"destination" : [ "obj-32", 0 ],
					"hidden" : 0,
					"midpoints" : [ 125.5, 63.0, 125.5, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-85", 0 ],
					"destination" : [ "obj-32", 1 ],
					"hidden" : 0,
					"midpoints" : [ 164.5, 63.0, 164.0, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-87", 0 ],
					"destination" : [ "obj-32", 2 ],
					"hidden" : 0,
					"midpoints" : [ 202.5, 63.0, 202.5, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-90", 0 ],
					"destination" : [ "obj-32", 3 ],
					"hidden" : 0,
					"midpoints" : [ 241.5, 63.0, 241.0, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-93", 0 ],
					"destination" : [ "obj-32", 4 ],
					"hidden" : 0,
					"midpoints" : [ 279.5, 63.0, 279.5, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-96", 0 ],
					"destination" : [ "obj-32", 5 ],
					"hidden" : 0,
					"midpoints" : [ 318.5, 63.0, 318.0, 63.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 5 ],
					"destination" : [ "obj-29", 5 ],
					"hidden" : 0,
					"midpoints" : [ 356.5, 252.0, 1054.0, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 4 ],
					"destination" : [ "obj-29", 4 ],
					"hidden" : 0,
					"midpoints" : [ 310.299988, 252.0, 1015.5, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 3 ],
					"destination" : [ "obj-29", 3 ],
					"hidden" : 0,
					"midpoints" : [ 264.100006, 252.0, 977.0, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 2 ],
					"destination" : [ "obj-29", 2 ],
					"hidden" : 0,
					"midpoints" : [ 217.899994, 252.0, 938.5, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 1 ],
					"destination" : [ "obj-29", 1 ],
					"hidden" : 0,
					"midpoints" : [ 171.699997, 252.0, 900.0, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [ 125.5, 252.0, 861.5, 252.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-29", 6 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-103", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 1 ],
					"destination" : [ "obj-104", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 2 ],
					"destination" : [ "obj-105", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 3 ],
					"destination" : [ "obj-106", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 4 ],
					"destination" : [ "obj-107", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 5 ],
					"destination" : [ "obj-108", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1083.5, 117.0, 327.0, 117.0, 327.0, 153.0, 357.5, 153.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 1 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1111.5, 117.0, 678.0, 117.0, 678.0, 150.0, 689.5, 150.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 2 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1139.5, 117.0, 1011.0, 117.0, 1011.0, 153.0, 1042.5, 153.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 3 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1167.5, 204.0, 1065.0, 204.0, 1065.0, 240.0, 1092.5, 240.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-101", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
