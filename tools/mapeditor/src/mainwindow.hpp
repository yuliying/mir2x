// generated by Fast Light User Interface Designer (fluid) version 1.0303

#ifndef mainwindow_hpp
#define mainwindow_hpp
#include <FL/Fl.H>
#include <vector>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_Double_Window.H>
#include "drawarea.hpp"
#include <FL/Fl_Menu_Bar.H>
#include <string>
#include "mir2map.hpp"
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/fl_ask.H>
#include <algorithm>
#include "cropconfigurewindow.hpp"
#include "groundinfowindow.hpp"
#include "aboutwindow.hpp"
#include <FL/Fl_Scrollbar.H>

class MainWindow {
  std::string m_WilFilePathName; 
public:
  MainWindow();
  Fl_Double_Window *m_Window;
private:
  inline void cb_m_Window_i(Fl_Double_Window*, void*);
  static void cb_m_Window(Fl_Double_Window*, void*);
public:
  DrawArea *m_DrawArea;
  Fl_Menu_Bar *m_MenuBar;
  static Fl_Menu_Item menu_m_MenuBar[];
private:
  inline void cb_New_i(Fl_Menu_*, void*);
  static void cb_New(Fl_Menu_*, void*);
  inline void cb_Load_i(Fl_Menu_*, void*);
  static void cb_Load(Fl_Menu_*, void*);
  inline void cb_Load1_i(Fl_Menu_*, void*);
  static void cb_Load1(Fl_Menu_*, void*);
  inline void cb_Extract_i(Fl_Menu_*, void*);
  static void cb_Extract(Fl_Menu_*, void*);
  inline void cb_Save_i(Fl_Menu_*, void*);
  static void cb_Save(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *m_MenuItemBaseTileLine;
  static Fl_Menu_Item *m_MenuItemGroundObjectLine;
  static Fl_Menu_Item *m_MenuItemOverGroundObjectLine;
  static Fl_Menu_Item *m_MenuItemGroundInfoLine;
  static Fl_Menu_Item *m_MenuItemReversedGroundInfoLine;
  static Fl_Menu_Item *m_MenuItemBaseTileLayer;
  static Fl_Menu_Item *m_MenuItemGroundObjectLayer;
  static Fl_Menu_Item *m_MenuItemOverGroundObjectLayer;
  static Fl_Menu_Item *m_MenuItemClearBackground;
private:
  inline void cb_Working_i(Fl_Menu_*, void*);
  static void cb_Working(Fl_Menu_*, void*);
  inline void cb_Wil_i(Fl_Menu_*, void*);
  static void cb_Wil(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *m_MenuItemEnableEdit;
private:
  inline void cb_m_MenuItemEnableEdit_i(Fl_Menu_*, void*);
  static void cb_m_MenuItemEnableEdit(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *m_MenuItemEditGround;
private:
  inline void cb_include_i(Fl_Menu_*, void*);
  static void cb_include(Fl_Menu_*, void*);
  inline void cb_Crop_i(Fl_Menu_*, void*);
  static void cb_Crop(Fl_Menu_*, void*);
  inline void cb_Ground_i(Fl_Menu_*, void*);
  static void cb_Ground(Fl_Menu_*, void*);
  inline void cb_About_i(Fl_Menu_*, void*);
  static void cb_About(Fl_Menu_*, void*);
public:
  Fl_Scrollbar *m_VSBar;
private:
  inline void cb_m_VSBar_i(Fl_Scrollbar*, void*);
  static void cb_m_VSBar(Fl_Scrollbar*, void*);
public:
  Fl_Scrollbar *m_SBar;
private:
  inline void cb_m_SBar_i(Fl_Scrollbar*, void*);
  static void cb_m_SBar(Fl_Scrollbar*, void*);
public:
  void ShowAll();
  void LoadMir2MapImage();
  void LoadMir2Map();
  void AfterLoadMir2Map();
  void SetWorkingPathName();
  void SetWilFilePathName();
  void CachePNG(uint32_t nFileIndex, uint32_t nImageIndex, int nX, int nY);
  void SavePNG(uint32_t *pBuff, uint32_t nFileIndex, uint32_t nImageIndex, int nW, int nH);
  Fl_Shared_Image * RetrievePNG(uint32_t nFileIndex, uint32_t nImageIndex);
  Fl_Shared_Image * RetrieveCachedPNG(uint32_t nFileIndex, uint32_t nImageIndex, int nX, int nY);
  void RedrawAll();
  void UpdateScrollBar(double fXP, double fYP);
  static void UpdateFrame(void *);
  bool ShowBaseTileLine();
  bool ShowGroundObjectLine();
  bool ShowOverGroundObjectLine();
  bool ShowGroundInfoLine();
  bool ReversedShowGroundInfoLine();
  bool ShowBaseTileLayer();
  bool ShowGroundObjectLayer();
  bool ShowOverGroundObjectLayer();
  bool EnableEdit();
  void MakeWorkingFolder();
  void SaveMap();
  bool EqualGroundInfoBlock(int nStartX, int nStartY, int nSize);
  void QTreePreOrder(int nStartX, int nStartY, int nSize, std::vector<bool> &stBitV, std::vector<uint32_t> &stAttributeV);
  void MapCrop(int nStartX, int nStartY, int nW, int nH);
  bool ClearBackground();
};
#endif