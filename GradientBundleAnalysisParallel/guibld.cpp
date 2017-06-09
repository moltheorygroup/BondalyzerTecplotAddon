/***************************************************
 *                                                 *
 *  NOTE!  This file is automatically generated by *
 *         the Tecplot GUI Builder.  It is highly  *
 *         recommended that you never edit this    *
 *         file directly!                          *
 *                                                 *
 ***************************************************/



/**
 */
void BuildTab1_1(LgIndex_t  Parent)
{
  if (Tab1_1Manager != BADDIALOGID)
    return;

  Tab1_1Manager = TecGUITabAddPage(Parent,
                               "Setup");
  TecGUIFrameAdd(Tab1_1Manager,
             192,
             2204,
             9995,
             341,
                    "Gradient Bundle Parameters");

  TecGUIFrameAdd(Tab1_1Manager,
             192,
             1658,
             9965,
             459,
                    " Sphere Mesh Parameters ");

  TecGUIFrameAdd(Tab1_1Manager,
             192,
             1297,
             9995,
             267,
                    " System Boundary Parameters ");

  TecGUIFrameAdd(Tab1_1Manager,
             2587,
             74,
             7599,
             1136,
                    " Integration Variables ");

  TecGUIFrameAdd(Tab1_1Manager,
             147,
             80,
             2336,
             1136,
                    " Select CP(s) ");

  BTNRun_BTN_T1_1 = TecGUIButtonAdd(Tab1_1Manager,
                                  8590,
                                  2570,
                                  1020,
                                  235,
                    "       Run\n",
                    BTNRun_BTN_T1_1_CB);

  TFSTPts_TF_T1_1 = TecGUITextFieldAdd(Tab1_1Manager,
                                     8827,
                                     2303,
                                     768,
                                     142,
                       TFSTPts_TF_T1_1_CB);

  LBL19_LBL_T1_1 = TecGUILabelAdd(Tab1_1Manager,
                                6136,
                                2335,
                    "# Gradient path points:");

  LBLGPperGB_LBL_T1_1 = TecGUILabelAdd(Tab1_1Manager,
                                     3519,
                                     2409,
                    "Label");

  SCNumEdgeGPs_SC_T1_1 = TecGUIScaleAdd(Tab1_1Manager,
                                      3445,
                                      2285,
                                      1197,
                                      105,
                    0,
                    100,
                    0,
                    SCNumEdgeGPs_SC_T1_1_CB,
                    SCNumEdgeGPs_SCD_T1_1_CB);


  TecGUIScaleShowNumericDisplay(SCNumEdgeGPs_SC_T1_1,FALSE);

  LBL20_LBL_T1_1 = TecGUILabelAdd(Tab1_1Manager,
                                414,
                                2310,
                    "# Gadient paths \nper gradient bundle:");

  LBLNumTri_LBL_T1_1 = TecGUILabelAdd(Tab1_1Manager,
                                    8191,
                                    1800,
                    "--> Num Triangles");

  TFLevel_TFS_T1_1 = TecGUISpinTextFieldAdd(Tab1_1Manager,
                                          6224,
                                          1776,
                                          680,
                                          142,
                       TFLevel_TFS_T1_1_ValueChanged_CB,
                       TFLevel_TFS_T1_1_ButtonUp_CB,
                       TFLevel_TFS_T1_1_ButtonDown_CB);

  TFRad_TF_T1_1 = TecGUITextFieldAdd(Tab1_1Manager,
                                   1271,
                                   1831,
                                   709,
                                   142,
                       TFRad_TF_T1_1_CB);

  LBLRad_LBL_T1_1 = TecGUILabelAdd(Tab1_1Manager,
                                 369,
                                 1856,
                    "Radius:");

  RBRadMode_RADIO_T1_1 = TecGUIRadioBoxAdd(Tab1_1Manager,
                                         2469,
                                         1763,
                                         2868,
                                         298,
                                 "Absolute",
                                 "Fraction of min CP dist.",
                                 (char *)NULL,
                                 (char *)NULL,
                                 (char *)NULL,
                                 RBRadMode_RADIO_T1_1_CB);

  TFCutoff_TF_T1_1 = TecGUITextFieldAdd(Tab1_1Manager,
                                      8147,
                                      1372,
                                      1301,
                                      142,
                       TFCutoff_TF_T1_1_CB);

  LBLCutoff_LBL_T1_1 = TecGUILabelAdd(Tab1_1Manager,
                                    6017,
                                    1397,
                    "System Rho Cutoff:");

  TGLOpenSys_TOG_T1_1 = TecGUIToggleAdd(Tab1_1Manager,
                                      576,
                                      1391,
                                      2099,
                                      124,
                               "Open System",
                               TGLOpenSys_TOG_T1_1_CB);

  MLSelVars_MLST_T1_1 = TecGUIListAdd(Tab1_1Manager,
                                    2676,
                                    329,
                                    7437,
                                    869,
                       1,
                       MLSelVars_MLST_T1_1_CB);

  SCPrecise_SC_T1_1 = TecGUIScaleAdd(Tab1_1Manager,
                                   7023,
                                   192,
                                   1197,
                                   105,
                    0,
                    100,
                    0,
                    SCPrecise_SC_T1_1_CB,
                    SCPrecise_SCD_T1_1_CB);


  TecGUIScaleShowNumericDisplay(SCPrecise_SC_T1_1,FALSE);

  LBL23_LBL_T1_1 = TecGUILabelAdd(Tab1_1Manager,
                                5840,
                                167,
                    "Precision:");

  TGLVolInt_TOG_T1_1 = TecGUIToggleAdd(Tab1_1Manager,
                                     4376,
                                     161,
                                     1493,
                                     124,
                               "Volume",
                               TGLVolInt_TOG_T1_1_CB);

  TGLInt_TOG_T1_1 = TecGUIToggleAdd(Tab1_1Manager,
                                  2691,
                                  161,
                                  1641,
                                  124,
                               "Integrate",
                               TGLInt_TOG_T1_1_CB);

  MLSelCPs_MLST_T1_1 = TecGUIListAdd(Tab1_1Manager,
                                   221,
                                   142,
                                   2158,
                                   1055,
                       1,
                       MLSelCPs_MLST_T1_1_CB);

  LBLLevel_LBL_T1_1 = TecGUILabelAdd(Tab1_1Manager,
                                   4805,
                                   1800,
                    "Refinement:");

  LBLPrecise_LBL_T1_1 = TecGUILabelAdd(Tab1_1Manager,
                                     8782,
                                     186,
                    "Label");

}

/**
 */
void BuildTab2_1(LgIndex_t  Parent)
{
  if (Tab2_1Manager != BADDIALOGID)
    return;

  Tab2_1Manager = TecGUITabAddPage(Parent,
                               "Integrate");
  TecGUIFrameAdd(Tab2_1Manager,
             147,
             99,
             2410,
             2850,
                    " CP Sphere ");

  TecGUIFrameAdd(Tab2_1Manager,
             2691,
             105,
             4554,
             2850,
                    " Variables ");

  MLIntSelSph_MLST_T2_1 = TecGUIListAdd(Tab2_1Manager,
                                      221,
                                      167,
                                      2217,
                                      2688,
                       1,
                       MLIntSelSph_MLST_T2_1_CB);

  MLIntSelVar_MLST_T2_1 = TecGUIListAdd(Tab2_1Manager,
                                      2764,
                                      173,
                                      4376,
                                      2688,
                       1,
                       MLIntSelVar_MLST_T2_1_CB);

  TGLIntVolInt_TOG_T2_1 = TecGUIToggleAdd(Tab2_1Manager,
                                        7614,
                                        714,
                                        2469,
                                        124,
                               "Integrate Volume",
                               TGLIntVolInt_TOG_T2_1_CB);

  LBL6_LBL_T2_1 = TecGUILabelAdd(Tab2_1Manager,
                               8354,
                               124,
                    "Precision");

  SCIntPrecise_SC_T2_1 = TecGUIScaleAdd(Tab2_1Manager,
                                      7304,
                                      353,
                                      2188,
                                      105,
                    0,
                    100,
                    0,
                    SCIntPrecise_SC_T2_1_CB,
                    SCIntPrecise_SCD_T2_1_CB);


  TecGUIScaleShowNumericDisplay(SCIntPrecise_SC_T2_1,FALSE);

  BTNIntegrate_BTN_T2_1 = TecGUIButtonAdd(Tab2_1Manager,
                                        7629,
                                        2372,
                                        2158,
                                        142,
                    "Integrate                  ",
                    BTNIntegrate_BTN_T2_1_CB);

  LBLIntPrecis_LBL_T2_1 = TecGUILabelAdd(Tab2_1Manager,
                                       9625,
                                       378,
                    "Label");

}

/**
 */
void BuildTab3_1(LgIndex_t  Parent)
{
  if (Tab3_1Manager != BADDIALOGID)
    return;

  Tab3_1Manager = TecGUITabAddPage(Parent,
                               "Results");
  TecGUIFrameAdd(Tab3_1Manager,
             340,
             217,
             2247,
             1210,
                    " CP Sphere ");

  TecGUIFrameAdd(Tab3_1Manager,
             384,
             1496,
             2203,
             1167,
                    " Gradient Bundles ");

  TecGUIFrameAdd(Tab3_1Manager,
             2735,
             217,
             6343,
             1943,
                    "Variables");

  SLSelSphere_SLST_T3_1 = TecGUIListAdd(Tab3_1Manager,
                                      428,
                                      310,
                                      1936,
                                      689,
                       0,
                       SLSelSphere_SLST_T3_1_CB);

  TGLSphereVis_TOG_T3_1 = TecGUIToggleAdd(Tab3_1Manager,
                                        473,
                                        1117,
                                        1419,
                                        124,
                               "Visible",
                               TGLSphereVis_TOG_T3_1_CB);

  BTNSphereDel_BTN_T3_1 = TecGUIButtonAdd(Tab3_1Manager,
                                        1522,
                                        1099,
                                        842,
                                        142,
                    "Delete",
                    BTNSphereDel_BTN_T3_1_CB);

  SLSelVar_SLST_T3_1 = TecGUIListAdd(Tab3_1Manager,
                                   2838,
                                   353,
                                   6106,
                                   1782,
                       0,
                       SLSelVar_SLST_T3_1_CB);

  MLSelGB_MLST_T3_1 = TecGUIListAdd(Tab3_1Manager,
                                  458,
                                  1589,
                                  1981,
                                  689,
                       1,
                       MLSelGB_MLST_T3_1_CB);

  BTNAllGB_BTN_T3_1 = TecGUIButtonAdd(Tab3_1Manager,
                                    502,
                                    2310,
                                    1892,
                                    142,
                    "         Activate All",
                    BTNAllGB_BTN_T3_1_CB);

  BTNTogMode_BTN_T3_1 = TecGUIButtonAdd(Tab3_1Manager,
                                      532,
                                      2484,
                                      1877,
                                      142,
                    "      Toggle Mode",
                    BTNTogMode_BTN_T3_1_CB);

  TFNumContours_TF_T3_1 = TecGUITextFieldAdd(Tab3_1Manager,
                                           340,
                                           2744,
                                           1242,
                                           142,
                       TFNumContours_TF_T3_1_CB);

  LBL9_LBL_T3_1 = TecGUILabelAdd(Tab3_1Manager,
                               1744,
                               2775,
                    "Number of contours");

  RBLogLin_RADIO_T3_1 = TecGUIRadioBoxAdd(Tab3_1Manager,
                                        4006,
                                        2657,
                                        1035,
                                        298,
                                 "log",
                                 "linear",
                                 (char *)NULL,
                                 (char *)NULL,
                                 (char *)NULL,
                                 RBLogLin_RADIO_T3_1_CB);

  RBCntSrc_RADIO_T3_1 = TecGUIRadioBoxAdd(Tab3_1Manager,
                                        7688,
                                        2657,
                                        1330,
                                        298,
                                 "selected",
                                 "all",
                                 (char *)NULL,
                                 (char *)NULL,
                                 (char *)NULL,
                                 RBCntSrc_RADIO_T3_1_CB);

  LBLCntSrc_LBL_T3_1 = TecGUILabelAdd(Tab3_1Manager,
                                    5263,
                                    2763,
                    "Make contour values from");

  LBL13_LBL_T3_1 = TecGUILabelAdd(Tab3_1Manager,
                                8842,
                                2763,
                    "sphere(s)");

  BTNExport_BTN_T3_1 = TecGUIButtonAdd(Tab3_1Manager,
                                     3164,
                                     2297,
                                     1641,
                                     142,
                    "Export to CSV",
                    BTNExport_BTN_T3_1_CB);

  TGLExGBs_TOG_T3_1 = TecGUIToggleAdd(Tab3_1Manager,
                                    5115,
                                    2291,
                                    4820,
                                    124,
                               "Export gradient bundles (not functional)",
                               TGLExGBs_TOG_T3_1_CB);

  TGLExInt_TOG_T3_1 = TecGUIToggleAdd(Tab3_1Manager,
                                    5115,
                                    2415,
                                    3075,
                                    124,
                               "Export integration data",
                               TGLExInt_TOG_T3_1_CB);

  TGLShowMesh_TOG_T3_1 = TecGUIToggleAdd(Tab3_1Manager,
                                       487,
                                       1260,
                                       1922,
                                       124,
                               "Show Mesh",
                               TGLShowMesh_TOG_T3_1_CB);

}

/**
 */
void BuildDialog1(LgIndex_t  ParentDialog)
{
  if (Dialog1Manager != BADDIALOGID)
    return;

  Dialog1Manager = TecGUIDialogCreateModeless(ParentDialog,
                                             10550,
                                             3262,
                                             "Gradient Bundle Analysis",
                                             Dialog1Init_CB,
                                             Dialog1CloseButton_CB,
                                             NULL)
;  TAB1_TB_D1 = TecGUITabAdd(Dialog1Manager,
                          44,
                          186,
                          10453,
                          3055,
                    TAB1_TBA_D1_CB,
                    TAB1_TBD_D1_CB);

  BuildTab1_1(TAB1_TB_D1);
  BuildTab2_1(TAB1_TB_D1);
  BuildTab3_1(TAB1_TB_D1);
}


/**
 */
void InitTGB(void)
{
/* Currently not used */
}
