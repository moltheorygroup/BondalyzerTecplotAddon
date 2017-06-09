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
void BuildSidebar1(void)
{
  if (Sidebar1Manager != BADDIALOGID)
    return;

  Sidebar1Manager = TecGUISidebarRegister("Sidebar",
                                      AddOnID,
                                      2240,
                                      3068,
                                      Sidebar1Activate_CB,
                                      Sidebar1Deactivate_CB);
  TecGUIFrameAdd(Sidebar1Manager,
             103,
             252,
             2139,
             865,
                    "CP Sphere");

  TecGUIFrameAdd(Sidebar1Manager,
             111,
             1215,
             2104,
             1154,
                    "Gradient Bundles");

  SLSelSphere_SLST_S1 = TecGUIListAdd(Sidebar1Manager,
                                    214,
                                    331,
                                    1941,
                                    598,
                       0,
                       SLSelSphere_SLST_S1_CB);

  TGLSphereVis_TOG_S1 = TecGUIToggleAdd(Sidebar1Manager,
                                      274,
                                      970,
                                      1383,
                                      119,
                               "Visible",
                               TGLSphereVis_TOG_S1_CB);

  MLSelGB_MLST_S1 = TecGUIListAdd(Sidebar1Manager,
                                214,
                                1288,
                                1924,
                                689,
                       1,
                       MLSelGB_MLST_S1_CB);

  BTNTogMode_BTN_S1 = TecGUIButtonAdd(Sidebar1Manager,
                                    231,
                                    2183,
                                    1881,
                                    144,
                    "      Toggle Mode",
                    BTNTogMode_BTN_S1_CB);

  BTNExitRes_BTN_S1 = TecGUIButtonAdd(Sidebar1Manager,
                                    68,
                                    39,
                                    2199,
                                    144,
                    "Exit Results Viewer",
                    BTNExitRes_BTN_S1_CB);

  BTNSphereDel_BTN_S1 = TecGUIButtonAdd(Sidebar1Manager,
                                      1271,
                                      948,
                                      850,
                                      144,
                    "Delete",
                    BTNSphereDel_BTN_S1_CB);

  BTNAllGB_BTN_S1 = TecGUIButtonAdd(Sidebar1Manager,
                                  223,
                                  2006,
                                  1890,
                                  144,
                    "         Activate All",
                    BTNAllGB_BTN_S1_CB);

}

/**
 */
void BuildDialog1(LgIndex_t  ParentDialog)
{
  if (Dialog1Manager != BADDIALOGID)
    return;

  Dialog1Manager = TecGUIDialogCreateModeless(ParentDialog,
                                             7923,
                                             3109,
                                             "Gradient Bundle Analysis",
                                             Dialog1Init_CB,
                                             Dialog1CloseButton_CB,
                                             NULL)
;  TecGUIFrameAdd(Dialog1Manager,
             103,
             82,
             2740,
             1154,
                    " Select CP(s) ");

  TecGUIFrameAdd(Dialog1Manager,
             2989,
             79,
             4733,
             1158,
                    " Integration Variables ");

  TecGUIFrameAdd(Dialog1Manager,
             146,
             1320,
             7577,
             270,
                    " System Boundary Parameters ");

  TecGUIFrameAdd(Dialog1Manager,
             146,
             1692,
             7551,
             469,
                    " Sphere Mesh Parameters ");

  TecGUIFrameAdd(Dialog1Manager,
             146,
             2266,
             7525,
             779,
                    " Irreducible Bundle Detection Parameters ");

  MLSelCPs_MLST_D1 = TecGUIListAdd(Dialog1Manager,
                                 266,
                                 162,
                                 2388,
                                 1053,
                       1,
                       MLSelCPs_MLST_D1_CB);

  TGLInt_TOG_D1 = TecGUIToggleAdd(Dialog1Manager,
                                6409,
                                184,
                                1606,
                                119,
                               "Integrate",
                               TGLInt_TOG_D1_CB);

  MLSelVars_MLST_D1 = TecGUIListAdd(Dialog1Manager,
                                  3084,
                                  339,
                                  4561,
                                  869,
                       1,
                       MLSelVars_MLST_D1_CB);

  TGLOpenSys_TOG_D1 = TecGUIToggleAdd(Dialog1Manager,
                                    438,
                                    1418,
                                    2070,
                                    119,
                               "Open System",
                               TGLOpenSys_TOG_D1_CB);

  LBLCutoff_LBL_D1 = TecGUILabelAdd(Dialog1Manager,
                                  4553,
                                  1421,
                    "System Rho Cutoff:");

  TFCutoff_TF_D1 = TecGUITextFieldAdd(Dialog1Manager,
                                    6151,
                                    1403,
                                    1297,
                                    144,
                       TFCutoff_TF_D1_CB);

  LBLRad_LBL_D1 = TecGUILabelAdd(Dialog1Manager,
                               283,
                               1890,
                    "Radius:");

  TFRad_TF_D1 = TecGUITextFieldAdd(Dialog1Manager,
                                 945,
                                 1869,
                                 713,
                                 144,
                       TFRad_TF_D1_CB);

  LBLLevel_LBL_D1 = TecGUILabelAdd(Dialog1Manager,
                                 3505,
                                 1786,
                    "Refinement:");

  TFLevel_TFS_D1 = TecGUISpinTextFieldAdd(Dialog1Manager,
                                        4561,
                                        1764,
                                        678,
                                        144,
                       TFLevel_TFS_D1_ValueChanged_CB,
                       TFLevel_TFS_D1_ButtonUp_CB,
                       TFLevel_TFS_D1_ButtonDown_CB);

  LBLNumTri_LBL_D1 = TecGUILabelAdd(Dialog1Manager,
                                  5756,
                                  1786,
                    "--> Num Triangles");

  LBLIB2_LBL_D1 = TecGUILabelAdd(Dialog1Manager,
                               283,
                               2399,
                    "Two adjacent gradient paths are considered to terminate in the same IB if:");

  LBLIBDist_LBL_D1 = TecGUILabelAdd(Dialog1Manager,
                                  378,
                                  2680,
                    "1) Terminal points are separated by a distance of less then:");

  LBLIBAng_LBL_D1 = TecGUILabelAdd(Dialog1Manager,
                                 403,
                                 2843,
                    "or 2) if angle of terminal ends differ by less than:");

  TFIBDist_TF_D1 = TecGUITextFieldAdd(Dialog1Manager,
                                    5240,
                                    2662,
                                    945,
                                    144,
                       TFIBDist_TF_D1_CB);

  TFIBAng_TF_D1 = TecGUITextFieldAdd(Dialog1Manager,
                                   5232,
                                   2832,
                                   945,
                                   144,
                       TFIBAng_TF_D1_CB);

  LBLIBDeg_LBL_D1 = TecGUILabelAdd(Dialog1Manager,
                                 6237,
                                 2843,
                    "deg.");

  BTNRun_BTN_D1 = TecGUIButtonAdd(Dialog1Manager,
                                6486,
                                2525,
                                1022,
                                234,
                    "       Run\n",
                    BTNRun_BTN_D1_CB);

  LBL19_LBL_D1 = TecGUILabelAdd(Dialog1Manager,
                              4080,
                              2009,
                    "# Gradient path points:");

  TFSTPts_TF_D1 = TecGUITextFieldAdd(Dialog1Manager,
                                   6099,
                                   1980,
                                   773,
                                   144,
                       TFSTPts_TF_D1_CB);

  RBRadMode_RADIO_D1 = TecGUIRadioBoxAdd(Dialog1Manager,
                                       1847,
                                       1800,
                                       2207,
                                       299,
                                 "Abs.",
                                 "% of min CP dist.",
                                 (char *)NULL,
                                 (char *)NULL,
                                 (char *)NULL,
                                 RBRadMode_RADIO_D1_CB);

}


/**
 */
void InitTGB(void)
{
/* Currently not used */
}
