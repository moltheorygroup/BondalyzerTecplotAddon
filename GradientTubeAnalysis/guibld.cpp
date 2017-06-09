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

  Sidebar1Manager = TecGUISidebarRegister("Gradient Tube Analysis",
                                      AddOnID,
                                      2799,
                                      5174,
                                      Sidebar1Activate_CB,
                                      Sidebar1Deactivate_CB);
  LabGTATitle_LBL_S1 = TecGUILabelAdd(Sidebar1Manager,
                                    190,
                                    74,
                    "Gradient Tube Analysis");

  LabCPList_LBL_S1 = TecGUILabelAdd(Sidebar1Manager,
                                  88,
                                  234,
                    "Using CPs:");

  MLCPs_MLST_S1 = TecGUIListAdd(Sidebar1Manager,
                              76,
                              367,
                              2623,
                              415,
                       1,
                       MLCPs_MLST_S1_CB);

  PBSelectCPs_BTN_S1 = TecGUIButtonAdd(Sidebar1Manager,
                                     88,
                                     851,
                                     1318,
                                     143,
                    "Select CPs",
                    PBSelectCPs_BTN_S1_CB);

  PBClear_BTN_S1 = TecGUIButtonAdd(Sidebar1Manager,
                                 1470,
                                 851,
                                 1216,
                                 143,
                    "Clear CPs",
                    PBClear_BTN_S1_CB);

  LabCutoffVar_LBL_S1 = TecGUILabelAdd(Sidebar1Manager,
                                     88,
                                     2352,
                    "Cutoff variable?");

  LabAngleStep_LBL_S1 = TecGUILabelAdd(Sidebar1Manager,
                                     63,
                                     3071,
                    "Angle start-end-step (deg)");

  LBL14_LBL_S1 = TecGUILabelAdd(Sidebar1Manager,
                              228,
                              3204,
                    "Slices");

  LBL15_LBL_S1 = TecGUILabelAdd(Sidebar1Manager,
                              1597,
                              3199,
                    "Streamtraces");

  OptSliceAngl_OPT_S1 = TecGUIOptionMenuAdd(Sidebar1Manager,
                                          101,
                                          3683,
                                          1128,
                                          143,
                        OptSliceAngl_OPT_S1_List,
                        OptSliceAngl_OPT_S1_CB);

  OptStreamAng_OPT_S1 = TecGUIOptionMenuAdd(Sidebar1Manager,
                                          1622,
                                          3683,
                                          1128,
                                          143,
                        OptStreamAng_OPT_S1_List,
                        OptStreamAng_OPT_S1_CB);

  TGLDeleteZon_TOG_S1 = TecGUIToggleAdd(Sidebar1Manager,
                                      88,
                                      4503,
                                      2547,
                                      127,
                               "Delete new zones",
                               TGLDeleteZon_TOG_S1_CB);

  PBQuit_BTN_S1 = TecGUIButtonAdd(Sidebar1Manager,
                                101,
                                4647,
                                621,
                                143,
                    "Quit",
                    PBQuit_BTN_S1_CB);

  PBRun_BTN_S1 = TecGUIButtonAdd(Sidebar1Manager,
                               2116,
                               4647,
                               608,
                               143,
                    "Run",
                    PBRun_BTN_S1_CB);

  TGLHideZones_TOG_S1 = TecGUIToggleAdd(Sidebar1Manager,
                                      88,
                                      4205,
                                      2357,
                                      127,
                               "Hide new zones",
                               TGLHideZones_TOG_S1_CB);

  MLSelectVar_MLST_S1 = TecGUIListAdd(Sidebar1Manager,
                                    101,
                                    1208,
                                    2623,
                                    1054,
                       1,
                       MLSelectVar_MLST_S1_CB);

  LabSelectVar_LBL_S1 = TecGUILabelAdd(Sidebar1Manager,
                                     88,
                                     1059,
                    "Integrate variable(s)?");

  LabCutoffVal_LBL_S1 = TecGUILabelAdd(Sidebar1Manager,
                                     88,
                                     2810,
                    "Cutoff");

  TFCutoff_TF_S1 = TecGUITextFieldAdd(Sidebar1Manager,
                                    1482,
                                    2794,
                                    1242,
                                    143,
                       TFCutoff_TF_S1_CB);

  RBCutoffDi_RADIO_S1 = TecGUIRadioBoxAdd(Sidebar1Manager,
                                        874,
                                        2709,
                                        583,
                                        298,
                                 "<",
                                 ">",
                                 (char *)NULL,
                                 (char *)NULL,
                                 (char *)NULL,
                                 RBCutoffDi_RADIO_S1_CB);

  OPTCutoffVar_OPT_S1 = TecGUIOptionMenuAdd(Sidebar1Manager,
                                          101,
                                          2470,
                                          2649,
                                          143,
                        OPTCutoffVar_OPT_S1_List,
                        OPTCutoffVar_OPT_S1_CB);

  LabRadOff_LBL_S1 = TecGUILabelAdd(Sidebar1Manager,
                                  114,
                                  3896,
                    "Radial offset for\nplacing streamtraces\n(as fraction of | P2-P1 |)");

  TFRadOffVal_TF_S1 = TecGUITextFieldAdd(Sidebar1Manager,
                                       1951,
                                       3960,
                                       773,
                                       143,
                       TFRadOffVal_TF_S1_CB);

  TGLShowOnly_TOG_S1 = TecGUIToggleAdd(Sidebar1Manager,
                                     88,
                                     4354,
                                     2978,
                                     127,
                               "Show only new zones",
                               TGLShowOnly_TOG_S1_CB);

  TFStBegAng_TF_S1 = TecGUITextFieldAdd(Sidebar1Manager,
                                      1622,
                                      3321,
                                      1128,
                                      143,
                       TFStBegAng_TF_S1_CB);

  TFSlcBegAng_TF_S1 = TecGUITextFieldAdd(Sidebar1Manager,
                                       101,
                                       3321,
                                       1128,
                                       143,
                       TFSlcBegAng_TF_S1_CB);

  TFSlcEndAng_TF_S1 = TecGUITextFieldAdd(Sidebar1Manager,
                                       101,
                                       3502,
                                       1128,
                                       143,
                       TFSlcEndAng_TF_S1_CB);

  TFStEndAng_TF_S1 = TecGUITextFieldAdd(Sidebar1Manager,
                                      1622,
                                      3502,
                                      1128,
                                      143,
                       TFStEndAng_TF_S1_CB);

}

/**
 */
void BuildDialog1(LgIndex_t  ParentDialog)
{
  if (Dialog1Manager != BADDIALOGID)
    return;

  Dialog1Manager = TecGUIDialogCreateModeless(ParentDialog,
                                             5039,
                                             184,
                                             "Gradient Tube Analysis",
                                             Dialog1Init_CB,
                                             Dialog1CloseButton_CB,
                                             Dialog1HelpButton_CB);
  LabCTRLRem_LBL_D1 = TecGUILabelAdd(Dialog1Manager,
                                   114,
                                   63,
                    "Remember to hold CTRL when selecting CPs!!");

}


/**
 */
void InitTGB(void)
{
/* Currently not used */
}
