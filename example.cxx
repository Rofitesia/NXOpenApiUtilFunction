 
#ifndef N_J_JUNIT
#define FUN_J_JUNIT
#ifdef _MSC_VER
#pragma once
#endif
#include <uf.h>
#include <atlstr.h>
#include <io.h>
#include <vector>
#include <sstream>
#include <iostream>
#include<algorithm>
#include <map>
#include <uf_ui.h>
#include <Windows.h>
#include <NXOpen/ListingWindow.hxx>
#undef CreateDialog;
#include <NXOpen/NXString.hxx>
#include <NXOpen/BlockStyler_Tree.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/ModelingView.hxx>
#include <NXOpen/ModelingViewCollection.hxx>
#include <NXOpen/View.hxx>
#include <NXOpen/Part.hxx>
#include <NXOpen/PartCollection.hxx>
#include <NXOpen/Selection.hxx>
#include <NXOpen/UI.hxx> 
#include <NXOpen/NXObjectManager.hxx> 
#include<NXOpen/Features_Feature.hxx>
#include<NXOpen/Features_BodyFeature.hxx>
#include<NXOpen/Features_FeatureCollection.hxx>
#include <uf_obj.h>
#include <uf_modl.h>
#include <uf_assem.h>
#include <NXOpen/BodyCollection.hxx>
#include <NXOpen/Body.hxx>
#include<NXOpen/Features_MoveObject.hxx>
#include<NXOpen/Features_MoveObjectBuilder.hxx>
#include <NXOpen/Features_BaseFeatureCollection.hxx>
#include <NXOpen/SelectNXObjectList.hxx>
#include <NXOpen/SelectObject.hxx>
#include <NXOpen/SelectObjectList.hxx>
#include <NXOpen/Direction.hxx>
#include <NXOpen/DirectionCollection.hxx>
#include <uf_evalsf.h>
#include <uf_part.h>
#include <uf_mb.h>
#include <NXOpen/DraftingManager.hxx>
#include <NXOpen/Drawings_DrawingSheet.hxx>
#include <NXOpen/Drawings_DrawingSheetCollection.hxx>
#include <NXOpen/View.hxx>
#include <NXOpen/ViewCollection.hxx>
#include <NXOpen/DisplayManager.hxx>
#include <NXOpen/DisplayableObject.hxx>
#include <NXOpen/Layer.hxx>
#include <NXOpen/Layer_LayerManager.hxx> #include <uf_layer.h>
#include <NXOpen/LineCollection.hxx>
#include <NXOpen/Line.hxx>
#include <NXOpen/Annotations.hxx>
#include <NXOpen/Annotations_AnnotationManager.hxx>
#include <NXOpen/Annotations_GdtDatumCollection.hxx>
#include <NXOpen/DatumCollection.hxx>
#include <NXOpen/Annotations_BaseDatum.hxx>
#include <NXOpen/Annotations_BaseDatum.hxx>
#include <NXOpen/DatumAxis.hxx>
#include <NXOpen/Annotations_Note.hxx>
#include <NXOpen/Annotations_NoteCollection.hxx>
#include <NXOpen/Curve.hxx>
#include <NXOpen/CurveCollection.hxx>
#include <NXOpen/SplineCollection.hxx>
#include <NXOpen/Spline.hxx>
#include <uf_attr.h>
#include <uf_draw.h>
#include <uf_view.h>
#include <NXOpen/Unit.hxx>
#include <NXOpen/UnitCollection.hxx>
#include <NXOpen/MeasureBodies.hxx>
#include<uf_trns.h>
#include <NXOpen/Annotations_IdSymbol.hxx>
#include <NXOpen/Annotations_IdSymbolCollection.hxx>
#include <NXOpen/Annotations_Label.hxx>
#include <NXOpen/Annotations_LabelCollection.hxx>
#include <NXOpen/Annotations_Hatch.hxx>
#include <NXOpen/Annotations_HatchCollection.hxx>
#include <NXOpen/Annotations_Dimension.hxx>
#include <NXOpen/Annotations_DimensionCollection.hxx>
#include <NXOpen/Annotations_VerticalDimension.hxx>
#include <NXOpen/Point.hxx>
#include <NXOpen/PointCollection.hxx>
#include <NXOpen/MeasureDistanceBuilder.hxx>
#include <NXOpen/Features_Cylinder.hxx>
#include <NXOpen/Face.hxx>
#include <NXOpen/MeasureBuilder.hxx>
#include <NXOpen/MeasureDistance.hxx>
#include <NXOpen/MeasureDistanceBuilder.hxx>
#include <NXOpen/SelectDisplayableObject.hxx>
#include <NXOpen/SelectDisplayableObjectList.hxx>
#include<time.h>
#include<uf_vec.h>
#include <NXOpen/FileNew.hxx>
#include <NXOpen/PDM_PartFromTemplateBuilder.hxx>
#include <NXOpen/PDM_PartManager.hxx>
#include<NXOpen/ScalarCollection.hxx>
#include<NXOpen/Scalar.hxx>
#include<uf_mtx.h>
#include<uf_csys.h>
#include<NXOpen/Edge.hxx>
#include<NXOpen/Point.hxx>
#include<NXOpen/PointCollection.hxx>
#include<NXOpen/LogFile.hxx>
#include<NXOpen/NXMessageBox.hxx>
#include<NXOpen/Information.hxx>
#include<io.h>
#include<NXOpen/NXColor.hxx>
#define UF_CALL(X) (JUnit::report_error( __FILE__, __LINE__, #X, (X)))
//鼠标事件
#define KEY_DOWN(VK_NONAME)((GetAsyncKeyState(VK_NONAME)&0x8000)?1:0)
#define TEST 1
using namespace std;
using namespace NXOpen;
class TTool;
class  TTool
{ private:
 static void  testMsgUC(NXOpen::NXString str1, int n) {
  char c[256];
  sprintf(c, "%s , %d", str1.GetLocaleText(), n);
  UI::GetUI()->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeInformation, c);
 }
 static void  testMsgUC(NXOpen::NXString str1, tag_t tag) {
  char c[256];
  sprintf(c, "%s , %d", str1.GetLocaleText(), (int)tag);
  UI::GetUI()->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeInformation, c);
 }
 static void  testMsgUC(NXOpen::NXString str1, double d[3]) {
  char c[256];
  sprintf(c, "%s , %f,%f,%f", str1.GetLocaleText(), d[0], d[1], d[2]);
  UI::GetUI()->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeInformation, c);  }
 static void  testMsgUC(NXOpen::NXString str1, double n) {
  char c[256];
  sprintf(c, "%s , %f", str1.GetLocaleText(), n);
  UI::GetUI()->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeInformation, c);  }
 static void  testMsgUC(NXOpen::NXString str1, NXOpen::NXString str2) {
  ostringstream oss;
  oss << str1.GetLocaleText() << " , " << str2.GetLocaleText();
  UI::GetUI()->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeInformation, oss.str());
 }
 static void  testMsgUC(NXOpen::NXString str) {   UI::GetUI()->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeInformation, str);  }
 static void  testMsgUC(int n) {   char c[256];
  sprintf(c, "%d", n);
  UI::GetUI()->NXMessageBox()->Show("Block Styler", NXOpen::NXMessageBox::DialogTypeInformation, c);  }
 static void  testMsgUC(double d) {   char c[256];
  sprintf(c, "%f", d);
  uc1601(c, 1);
 }
 static void  outMsgL(NXOpen::NXString str) {   stringstream ss;
  ss << str.GetLocaleText();   UF_UI_open_listing_window();   UF_UI_write_listing_window(ss.str().c_str());
 }
 static void  outMsg(NXOpen::NXString str1, tag_t n) {   TTool::outMsg(str1, (int)n);
 }
 static void  outMsg(NXOpen::NXString str1, int n) {   char c[256];
  sprintf(c, "%s : %d", str1.GetLocaleText(), n);
  logical isOpen = false;
  UF_UI_is_listing_window_open(&isOpen);
  if (!isOpen)UF_UI_open_listing_window();   UF_UI_write_listing_window(c);
  UF_UI_write_listing_window("\n");
 }
 static void  outMsg(NXOpen::NXString str1, size_t n) {   char c[256];
  sprintf(c, "%s : %d", str1.GetLocaleText(), int(n));
  logical isOpen = false;
  UF_UI_is_listing_window_open(&isOpen);
  if (!isOpen)UF_UI_open_listing_window();   UF_UI_write_listing_window(c);
  UF_UI_write_listing_window("\n");
 }
 static void  outMsg(NXOpen::NXString str1, double n) {
  char c[256];
  sprintf(c, "%s : %f", str1.GetLocaleText(), n);
  UF_UI_open_listing_window();   UF_UI_write_listing_window(c);
  UF_UI_write_listing_window("\n");
 }
 static void  outMsg(NXOpen::NXString str1, NXOpen::NXString str2) {
  ostringstream oss;
  oss << str1.GetLocaleText() << ":" << str2.GetLocaleText();
  UF_UI_open_listing_window();
  UF_UI_write_listing_window(oss.str().c_str());
  UF_UI_write_listing_window("\n");
 }  static void  outMsg(NXOpen::NXString str) {
  UF_UI_open_listing_window();   UF_UI_write_listing_window(str.GetLocaleText());
  UF_UI_write_listing_window("\n");
 }
 static void  outMsg(double d) {
  char c[1000];
  sprintf(c, "%f", d);
  UF_UI_open_listing_window();   UF_UI_write_listing_window(c);
  UF_UI_write_listing_window("\n");
 }
 static void  outMsg(Point3d p) {
  char c[1000];
  sprintf(c, "%f,%f,%f", p.X, p.Y, p.Z);
  UF_UI_open_listing_window();   UF_UI_write_listing_window(c);
  UF_UI_write_listing_window("\n");
 }
 static void  outMsg(double* arr) {
  logical flag = false;
  UF_UI_open_listing_window();   char c[1000];
  sprintf(c, "%.8f,%.8f,%.8f,%.8f,%.8f,%.8f,%.8f,%.8f,%.8f", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8]);
  UF_UI_write_listing_window(c);
  UF_UI_write_listing_window("\n");
 }
 static void  outMsg(double* arr, int size) {
  logical isOpen = false;
  UF_UI_is_listing_window_open(&isOpen);
  if (!isOpen)UF_UI_open_listing_window();
  for (int i = 0; i < size; i++) {
   char c[1000];
   sprintf(c, " %f,", arr[i]);
   UF_UI_write_listing_window(c);
  }
  UF_UI_write_listing_window("\n");
 }
 static void  outMsg(std::vector<double> list, int size) {
  logical isOpen = false;
  UF_UI_is_listing_window_open(&isOpen);
  if (!isOpen)UF_UI_open_listing_window();
  for (int i = 0; i < size; i++) {
   char c[1000];
   sprintf(c, " %f,", list[i]);
   UF_UI_write_listing_window(c);
  }
  UF_UI_write_listing_window("\n");
 }
 static void  outMsg(int* arr, int size) {
  logical isOpen = false;
  UF_UI_is_listing_window_open(&isOpen);
  if (!isOpen)UF_UI_open_listing_window();
  for (int i = 0; i < size; i++) {
   char c[1000];
   sprintf(c, " %d,", arr[i]);
   UF_UI_write_listing_window(c);
  }
  UF_UI_write_listing_window("\n");
 }
 static void  outMsg(size_t d) {
  char c[1000];
  sprintf(c, "%d", (int)d);
  UF_UI_open_listing_window();   UF_UI_write_listing_window(c);
  UF_UI_write_listing_window("\n");
 }
 static void  outMsgL(int d) {
  char c[1000];
  sprintf(c, "%d", d);
  UF_UI_open_listing_window();   UF_UI_write_listing_window(c);
 }
 static void  outMsg(tag_t objTag) {
  TTool::outMsg((int)objTag);
 }
 static void  outMsg(int d) {   char c[1000];
  sprintf(c, "%d", d);
  UF_UI_open_listing_window();   UF_UI_write_listing_window(c);
  UF_UI_write_listing_window("\n");
 }
public:
 //打印信息
 template<class T>
 static void errorMsg(T str) {   TTool::outMsg(str);
 }
 template<class T1, class T2>
 static void errorMsg(T1 t1, T2 t2) {   TTool::outMsg(t1, t2);
 }
 template<class T>
 static void testMsg(T str) {
  if (TEST)return;
  TTool::outMsg(str);
 }
 template<class T1, class T2>
 static void testMsg(T1 t1, T2 t2) {
  if (TEST)return;
  TTool::outMsg(t1, t2);
 }
 template<class T>
 static void testMsgL(T str) {
  TTool::outMsgL(str);
 }
 template<class T>
 static void testUC(T t1) {
  TTool::testMsgUC(t1);
 }
 template<class T1, class T2>
 static void testUC(T1 t1, T2 t2) {
  TTool::testMsgUC(t1, t2);
 }
};
#include <NXOpen/ViewDependentDisplayManager.hxx>
#include<NXOpen/Drawings_DraftingView.hxx>
//JUnit工具声明
namespace JUnit {
 inline bool isCloseEdge(Edge* edge) {
  Point3d p1;
  Point3d p2;
  edge->GetVertices(&p1, &p2);
  double dist = 0;
  double pt1[3] = { p1.X,p1.Y,p1.Z };
  double pt2[3] = { p2.X,p2.Y,p2.Z };
  UF_VEC3_distance(pt1, pt2, &dist);
  if (dist < 0.01) return true;
  return false;
 }
 inline int getBodyMassCenter(tag_t bodyTag, double massCenter[3]);
 /*指定方向是否通透*/
 inline bool checkCylindricalFaceByDir(tag_t bodyTag, Face* face, double viewDir[3]);
 inline void setViewLineColor(std::vector<tag_t> faceList, tag_t viewTag, int color) {
  
  Session* theSession = Session::GetSession();
  Part* workPart(theSession->Parts()->Work());
  Part* displayPart(theSession->Parts()->Display());
  Drawings::DraftingView* baseView1(dynamic_cast<Drawings::DraftingView*>(NXObjectManager::Get(viewTag)));
  if (baseView1 != NULL) {
   std::vector<double> segmentStart1(1);
   segmentStart1[0] = 0.0;
   std::vector<double> segmentEnd1(1);
   segmentEnd1[0] = 1.0;
   for (int i = 0; i < faceList.size(); i++) {
    Face* face1 = dynamic_cast<Face*>(NXObjectManager::Get(faceList[i]));
    
    std::vector<Edge*> edgelist;
    if (face1) edgelist = face1->GetEdges();
    for (int j = 0; j < edgelist.size();j++) {
     if (edgelist[j] != NULL) {
      baseView1->DependentDisplay()->ApplySegmentEdit(edgelist[j], NXColor::Factory::_Get(color), ViewDependentDisplayManager::FontSolid, ViewDependentDisplayManager::WidthTwo, segmentStart1, segmentEnd1);
     }
    }
    
   }
  }  }
 inline void setViewLineColor(std::vector<tag_t> faceList, tag_t viewTag, int color, ViewDependentDisplayManager::Font font, ViewDependentDisplayManager::Width lineWidth) {   Session* theSession = Session::GetSession();
  Part* workPart(theSession->Parts()->Work());
  Part* displayPart(theSession->Parts()->Display());
  Drawings::DraftingView* baseView1(dynamic_cast<Drawings::DraftingView*>(NXObjectManager::Get(viewTag)));
  if (baseView1 != NULL) {
   std::vector<double> segmentStart1(1);
   segmentStart1[0] = 0.0;
   std::vector<double> segmentEnd1(1);
   segmentEnd1[0] = 1.0;
   for (int i = 0; i < faceList.size(); i++) {
    Face* face1 = dynamic_cast<Face*>(NXObjectManager::Get(faceList[i]));     std::vector<Edge*> edgelist;
    if (face1) edgelist = face1->GetEdges();
    for (int j = 0; j < edgelist.size(); j++) {
     if (edgelist[j] != NULL) {
      baseView1->DependentDisplay()->ApplySegmentEdit(edgelist[j], NXColor::Factory::_Get(color), font, lineWidth, segmentStart1, segmentEnd1);
     }
    }    }
  }  }
 inline bool folderExist(std::string floder) {
  return _access(floder.c_str(),0)==0;
 }
 inline void getChildFolders(std::string folderPath, std::string folderPrefix, std::vector<std::string>& folderList) {
  if (JUnit::folderExist(folderPath)) {
   WIN32_FIND_DATA findFileData;
   HANDLE hFind = FindFirstFile((folderPath + "\\*").c_str(), &findFileData);
   if (hFind == INVALID_HANDLE_VALUE) {
    TTool::errorMsg("error opening directory");
    return;
   }
   do {
    if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
     if (_tcsncmp(findFileData.cFileName, folderPrefix.c_str(), folderPrefix.size()) == 0) {
      //TTool::errorMsg(findFileData.cFileName);
      folderList.push_back(findFileData.cFileName);
     }
    }
   } while (FindNextFile(hFind, &findFileData) != 0);
   FindClose(hFind);
  }
 }
 inline bool fileExists(std::string file);
 inline tag_t createBaseView(tag_t bodyTag, Point3d origin);
 inline tag_t createBaseView(tag_t bodyTag, Point3d origin, double zDir[3], double xDir[3]);
 /*设置颜色*/
 inline void  setBodyColor(tag_t bodyTag, int Color);
 inline void  setFacesColor(std::vector<tag_t> faces, int Color);
 /*获取圆弧边的中心 */
 inline int  getCycleEdgeCenter(tag_t edge1Tag, double center[3]);
 inline int  getCycleEdgeCenter(tag_t edge1Tag, double center[3]);
 //错误报告
 inline int report_error(char* file, int line, char* call, int irc);
 //转成tag_t类型的列表
 inline std::vector<tag_t> toTagList(std::vector<TaggedObject*> list);
 //改变视图风格-0线框1正常
 inline void changeViewStyle(int n = 0);
 inline void addObjToSelList(tag_t* objs);
 //获取选择器中的所有对象
 inline std::vector<tag_t> getSelObjList();
 //获取选择器中的所有对象
 inline std::vector<tag_t> getSelObjList2();
 //打印信息
 
 inline void writeLog(NXOpen::NXString str);
 inline void writeLog(NXOpen::NXString str1, NXOpen::NXString str2);
 inline void writeLog(NXOpen::NXString str1,int n);
 inline void writeLog(NXOpen::NXString str1,size_t n);
 inline void writeLog(NXOpen::NXString str1,double n);
 inline void writeLog(NXOpen::NXString str1,double *d,int size);
 inline void writeLog(NXOpen::NXString str1,int *d,int size);
 inline void myMessageBox(std::string str);
 inline void myMessageBox(std::string str1, std::string str2);  //整数转字符串
 inline std::string toString(int n);
 //浮点数转字符串
 inline std::string toString(double n);
 //整数列表转字符串列表
 inline std::vector<NXOpen::NXString> toStrList(std::vector<int> list);
 //字符串转浮点数
 inline double toF(NXOpen::NXString str);
 //字符串转整数
 inline int toInt(NXOpen::NXString str);
 //判断是否是数字
 inline bool isNumber(NXOpen::NXString str1);
 //判断是否是可编辑表达式
 inline bool isEditableExp(NXOpen::NXString paramName);
 //xml中文乱码处理 
 inline NXString Utf8ToGB2312(const char* utf8);
 //去除字符串的空格
 inline NXString trimEmpty(const char* strs);
 //分割字符1
 inline std::vector<NXOpen::NXString> splitStr(NXOpen::NXString str, NXOpen::NXString c);
 inline std::vector<string> splitStr1(NXOpen::NXString str, NXOpen::NXString c);
 //分割字符
 inline std::vector<int> splitStrToIntArr(NXOpen::NXString str, NXOpen::NXString sign);
 //分割字符
 inline std::vector<double> splitStrToDoubleArr(NXOpen::NXString str, NXOpen::NXString sign);
 /*获取数字区间,例: 1-10,以“-”符号分隔*/
 inline std::vector<int> getNumbers(NXOpen::NXString str, NXOpen::NXString sign);
 //获取dll执行文件所在地址
 inline NXOpen::NXString getDllAddress();
 inline NXOpen::NXString getDllAddress(NXOpen::NXString dlxFileName);
 inline std::string getDllAddress1(NXOpen::NXString dlxFileName);
 //读环境变量
 inline NXOpen::NXString getEnvironmentVar(NXString fileName);
 inline std::string getEnvironmentVal1(std::string paramName, std::string fileName);
 //CString 转 NXString
 inline NXOpen::NXString cStrToNXString(CString tchar);
 //判断列表是否包含该元素
 template<class T>
 inline bool isContain(std::vector<T> list, T ele);
 //获取nx对象选择器
 inline std::vector<TaggedObject*> getSeleObjectUI();
 /*单选器*/
 inline tag_t singleSelectionUI();
 //打印对象的信息
 inline NXOpen::NXString getObjType(tag_t objTag);
 inline void getType(tag_t objTag);
 //获取特征类型
 inline NXString getFeatureType(tag_t feat);
 //获取事例信息
 inline NXString getOccInfo(tag_t occTag, bool isPartOcc =false);
 //判断是否是事例
 inline bool isOcc(tag_t objTag);
 //替换字符串
 inline string replaceStr1(NXOpen::NXString sourceStr,NXOpen::NXString substr, NXOpen::NXString replaceStr);
 //截取文件名
 inline NXString splitFileName(NXString str);
 //进度条
 inline void showLead(int count,int index);
 /*获取实体的型心*/
 inline Point3d getObjCenter(tag_t solidTag);
 /*获取当前工作部件中的所有实体*/
 inline std::vector<tag_t> getSolidBodies();
 /*移动对象*/
 inline  void moveObj(Body* body1, Vector3d vector1, double distance, bool isCopy = false);
 /*获取体的质心*/
 inline Point3d getMassCenter(std::vector<Point3d> pointList);
 /*从体上获取点云*/
 inline std::vector<Point3d> getPoints(tag_t bodyTag);
 /*获取当前显示部件的名称*/
 inline NXOpen::NXString getCurrentDisplayPartName();
 /*切换到制图模块*/
 inline void switchToDrawing();
 /*切换到建模模块*/
 inline void switchToModeling();
 /*打开图纸*/
 inline void openDrawSheet(NXOpen::NXString sheetName);
 /*隐藏对象*/
 inline void blankAll();
 inline  void showObjects(std::vector<tag_t> list);
 inline void unBlankAll();
 /*显示所有对象*/
 inline void unBlankObjects(const std::vector<tag_t> objs);
 
 /*获取属性值*/
 inline UF_ATTR_value_t getAttrValue(tag_t objTag,NXOpen::NXString title1);
 inline int getAttrValueStr(tag_t objTag,NXOpen::NXString title1, NXOpen::NXString& valStr);
 inline int getAttrValueStr(tag_t objTag,NXOpen::NXString title1,std::string& valStr);
 inline int getAttrValueInt(tag_t objTag,NXOpen::NXString title1,int &val);
 /*查找属性*/
 inline int findAttr(tag_t objTag, NXOpen::NXString title1);
 /*投影视图*/
 inline void improtView1(NXOpen::NXString title1,tag_t viewTag);
 //视图矩阵转换 uc6434
 /*将实体移动到指定图层*/
 inline void moveSolidToLayer(std::vector<tag_t>solidList,int layer);
 /*获取实体的重量*/
 inline double getWeight(tag_t bodyTag);
 /*获取当前时间*/
 inline std::string getDate();
 inline std::string getDate2();
 inline std::string getDate3();
 /*获取当前显示部件文件路径*/
 inline NXOpen::NXString getCurrentDisplayPartPath();
 /*判断路径是否有效和存在 否则创建路径*/
 inline void checkPath(std::string filePath);
 inline bool isDirectoryExists(const std::string& directoryPath);
 inline tag_t createCycle(double diameter, double drawPoint[2]);
 /*获取圆柱面的直径*/
 inline double getCylinderFaceDiam(NXOpen::Face* cylinderFace);
 /*获取两个对象指定方向的最小距离*/
 inline double getMinDistDirection(NXOpen::DisplayableObject* obj1, NXOpen::DisplayableObject* obj2,double direction[3]);
 inline double getMaxDistDirection(NXOpen::DisplayableObject* obj1, NXOpen::DisplayableObject* obj2,double direction[3]);
 inline double getMaxDist(NXOpen::DisplayableObject* obj1, NXOpen::DisplayableObject* obj2);
 inline double getMinDist(NXOpen::DisplayableObject* obj1, NXOpen::DisplayableObject* obj2);
 /*判断两个方向是否相同*/
 inline bool isEqualVec3(double v1[3],double v2[3]);
 /*判断两个方向是否平行*/
 inline bool isParallelVec3(double v1[3], double v2[3]);
 /*判断垂直*/
 inline bool isPerpendicularVec3(double v1[3], double v2[3]);
 
 /*连接曲线*/
 inline tag_t connectingCurve(std::vector<Curve*> curveList);
 /*string 转 wstring*/
 inline std::wstring s2ws(const std::string& s);
 inline std::wstring c2lp(const char* source, LPSTR lpstr) { // 获取转换后的宽字符所需的缓冲区大小
  int bufferSize = MultiByteToWideChar(CP_ACP, 0, source, -1, nullptr, 0);   // 分配缓冲区并进行转换
  wchar_t* wideBuffer = new wchar_t[bufferSize];
  MultiByteToWideChar(CP_ACP, 0, source, -1, wideBuffer, bufferSize);   // 获取转换后的多字节字符所需的缓冲区大小
  bufferSize = WideCharToMultiByte(CP_ACP, 0, wideBuffer, -1, nullptr, 0, nullptr, nullptr);   // 分配缓冲区并进行转换
  char* multiByteBuffer = new char[bufferSize];
  WideCharToMultiByte(CP_ACP, 0, wideBuffer, -1, multiByteBuffer, bufferSize, nullptr, nullptr);   // 转换后的 LPSTR 字符串
  lpstr = multiByteBuffer;   // 使用 lpstr 进行操作   // 释放内存
  delete[] wideBuffer;
  delete[] multiByteBuffer;
 }  inline CString s2cs(const NXOpen::NXString& s);
 inline std::string cs2s(CString cs);
 /*wstring 转 string*/
 inline std::string ws2s(const std::wstring& s);
 inline void writeAttrStr(tag_t objTag, NXOpen::NXString title1, NXOpen::NXString valueStr);
 inline void blandBody1(Part* part,tag_t bodyTag);
 /*新建部件*/
 inline tag_t newFile(NXOpen::NXString fileName);
 /*变更显示部件*/
 inline void setDisplayPart(tag_t partTag);
 /*交换数值*/
 inline void swapVec3(double* a, double* b);
 /*充字符串中提取所有数字*/
 inline std::vector<double> getNumbersOfStr(NXOpen::NXString str);
 /**/
 inline void getQuadrantFace(tag_t body, double mtx[9], std::vector<tag_t>& faces);
 /*获取面的法向*/
 void getFaceDir(tag_t faceTag,double dir[3]);
 /*判断两个方向是否大致同向即夹角小于90*/
 inline bool isSyntropyVec3(double v1[3], double v2[3]);
 inline double getAngleOf2Vec3(double v1[3], double v2[3]);
 /*获取圆弧边的中心*/
 inline void getCycleEdgeCenter1(tag_t edge1Tag, double p[3]);
 inline double getDiamOfCircularEdge(tag_t edge1Tag);
 /*获取面上直径最大的圆边*/
 inline bool getMaxDiamEdge(tag_t faceTag, tag_t*edgTag);
 /*检查圆柱面是否在沉头平面的两侧*/
 inline bool check2FaceSide(tag_t midstFace, tag_t checkedFaces[2], double dir[3]);
 inline bool check2FaceSide(tag_t midstFace, std::vector<tag_t> checkedFaces, double dir[3]);
 /*删除指定对象*/
 inline void deleteObjs(std::vector<NXObject* >&list);
 
 /*打开配置表*/
 inline void openFile(NXOpen::NXString file);
 inline void openFile(NXOpen::NXString file,std::string params);
 /*dll调用dll*/
 inline void dllCallDll(char dll_path[255]);
 /*四舍五入保留n位小数*/
 inline double round(double source, int n);
 inline void error_return(char* msg);
 inline  void report_error(int result, char* alt_msg);
 /*获取边的中点*/
 inline  Point3d getMidPointOfEdge(Edge* edge1);
 inline  void getMidPointOfEdge(Edge* edge1,double midPoint[3]);
 inline void  setWCS();
 /*射线检测*/
 inline  bool rayCheck(tag_t bodyTag,double point[3], double dir[3]);
 inline  bool rayCheck(tag_t bodyTag,double point[3], double dir[3],double hitPoint[3]);  inline  bool checkRW(NXOpen::NXString path);  inline void setBodyName(tag_t body1, NXOpen::NXString name);
 //替换字符串
 
 inline int replaceStr(std::string& str, const char* oldStr, const char* newStr);
 inline void replaceStr2(std::string& str, const char* oldStr, std::string newStr);
 /*圆括号*/
 inline void replaceStr3(std::string& str,std::string newStr);
 /*删除字符串前后空格*/
 inline void trimStr(std::string& str);
 /*取面的横向边*/
 inline NXOpen::Edge* getCrossEdges(Face* face1, double viewDir[3], double midPointOfEdges[3]);
 //获得面的面积
 inline  double getFaceArea(Face*face);
 //获得面的边数
 inline int getFaceEdgeCount(tag_t faceTag);
 /**/
 inline Point3d getEdgeMidPoint(tag_t edgeTag, double param);
 inline void getEdgeMidPoint(tag_t edgeTag, double param,double outPoint[3]);
 inline std::string getFileCreateTime();
 inline void deleNxobjects1();
 inline void createSymbol(char part_name[255], double origin[3], double diameter, tag_t view_tag, int col = 186, bool isFront = true);
 inline void  attachToView(tag_t note_tag, tag_t view_tag);
 /*[]*/
 inline void  getValBetweenBracket(std::string str,std::vector<std::string> &vals);
 /*<>*/
 inline void  getValBetweenBracket1(std::string str,std::vector<std::string> &vals);
 /*()*/
 inline void  getValBetweenBracket2(std::string str,std::vector<std::string> &vals);
 /*最后修改时间*/
 inline std::string getFileVesion();
 inline std::string getFileVesion(std::string numberStr);
 inline double getDistBetween2Point(double p1[3], double p2[3]);
 inline void fileCheckExist(const char * fileName);
 inline void getArcCenterPoint(tag_t arc, double* centerPt); }
bool JUnit::checkCylindricalFaceByDir(tag_t bodyTag, Face* face, double viewDir[3]) {
 if (face == NULL || bodyTag == NULL_TAG)return false;
 if (face->SolidFaceType() != Face::FaceTypeCylindrical)return false;
 //JUnit::getDiamOfCircularEdge
 double faceDir[3] = { 0 };
 JUnit::getFaceDir(face->Tag(), faceDir);
 double faceDiam = JUnit::getCylinderFaceDiam(face);
 std::vector<Edge*>edgelist = face->GetEdges();
 std::vector<Edge*>circularEdges;
 for (int i = 0; i < edgelist.size(); i++) {
  Edge* edge1 = edgelist[i];
  if (edge1->SolidEdgeType() == Edge::EdgeTypeCircular) {
   double edgeDiam = JUnit::getDiamOfCircularEdge(edge1->Tag());
   if (abs(edgeDiam - faceDiam) < 0.01) circularEdges.push_back(edge1);
  }
 }
 double checkPt[3] = { 0 };
 bool flag = false;
 for (int i = 0; i < circularEdges.size(); i++) {
  Edge* edge1 = circularEdges[i];
  double edgeCenter1[3] = { 0 };
  JUnit::getCycleEdgeCenter(edge1->Tag(), edgeCenter1);
  for (int j = i + 1; j < circularEdges.size(); j++) {
   Edge* edge2 = circularEdges[j];
   double edgeCenter2[3] = { 0 };
   JUnit::getCycleEdgeCenter(edge2->Tag(), edgeCenter2);
   double dist = 0;
   UF_VEC3_distance(edgeCenter1, edgeCenter2, &dist);
   if (dist > 0.01) {
    
    double dir1[3] = { 0 };
    UF_VEC3_sub(edgeCenter2, edgeCenter1, dir1);
    if (JUnit::isParallelVec3(dir1, faceDir)) {
     double fMagnitude1;
     UF_VEC3_unitize(dir1, 0.00254, &fMagnitude1, dir1);
     double edgeMidPt1[3] = { 0 };
     JUnit::getEdgeMidPoint(edge1->Tag(), 0.5, edgeMidPt1);
     double offsetDir[3] = { 0 };
     UF_VEC3_sub(edgeCenter1, edgeMidPt1, offsetDir);
     UF_VEC3_unitize(offsetDir, 0.00254, &fMagnitude1, offsetDir);
     double offsetPt[3] = { 0 };
     UF_VEC3_affine_comb(edgeMidPt1, 0.05, offsetDir, offsetPt);
     UF_VEC3_affine_comb(offsetPt, dist / 2, dir1, checkPt);
     /*tag_t ptTag = NULL_TAG;
     UF_CURVE_create_point(checkPt, &ptTag);
     UF_OBJ_set_color(ptTag, 186);*/
     flag = true;
     break;
    }
   }
  }
 }
 
 bool isTong = !JUnit::rayCheck(bodyTag, checkPt, viewDir);
 
 if (flag && isTong)return true;
 return false;
}
#include<NXOpen/Drawings_BaseViewBuilder.hxx>
#include<NXOpen/Drawings_ViewPlacementBuilder.hxx>
#include<NXOpen/Drawings_DraftingViewCollection.hxx>
#include<NXOpen/SelectNXObject.hxx>
inline int JUnit::getBodyMassCenter(tag_t bodyTag, double massCenter[3]) {  if (bodyTag) {
  double mtx[9] = { 1,0,0,0,1,0,0,0,1 };
  tag_t mtxTag = NULL_TAG;
  UF_CALL(UF_CSYS_create_matrix(mtx, &mtxTag));
  double origin[3] = { 0 };
  tag_t tempCsys = NULL_TAG;
  UF_CALL(UF_CSYS_create_temp_csys(origin, mtxTag, &tempCsys));
  UF_CALL(UF_CSYS_set_wcs(tempCsys));
  //
  int num_objs;
  int type = 1;
  int units;
  double density;
  int accuracy;
  double acc_value[11] = { 0.01,0,0,0,0,0,0,0,0,0,0 };
  double mass_props[47];
  double statistics[13];
  UF_MODL_ask_mass_props_3d(&bodyTag, 1, type, 3, 1.0, 1, acc_value, mass_props, statistics);
  massCenter[0] = mass_props[3] * 10;
  massCenter[1] = mass_props[4] * 10;
  massCenter[2] = mass_props[5] * 10;
  return 0;
 }
 return 1;
}
tag_t JUnit::createBaseView(tag_t bodyTag, Point3d viewOrigin) {
 tag_t baseViewTag = NULL_TAG;
 try
 {   Body* body1 = dynamic_cast<Body*>(NXObjectManager::Get(bodyTag));
  std::vector<Face*> faceList = body1->GetFaces();
  Face* maxPlanarFace = NULL;
  double area = 0;
  for (int i = 0; i < faceList.size(); i++) {
   if (faceList[i]->SolidFaceType() == Face::FaceTypePlanar) {
    double temp = JUnit::getFaceArea(faceList[i]);
    if (temp > area) {
     area = temp;
     maxPlanarFace = faceList[i];
    }
   }
  }
  if (maxPlanarFace == NULL)return baseViewTag;
  std::vector<Edge*> edges = maxPlanarFace->GetEdges();
  Edge* maxLenEdge = NULL;
  double len = 0;
  for (int i = 0; i < edges.size(); i++) {
   if (edges[i]->SolidEdgeType() == Edge::EdgeTypeLinear) {
    double temp = edges[i]->GetLength();
    if (temp > len) {
     len = temp;
     maxLenEdge = edges[i];
    }
   }
  }
  if (maxLenEdge == NULL)return baseViewTag;
  //
  Part* workPart = Session::GetSession()->Parts()->Work();
  Drawings::BaseView* nullBaseView(NULL);
  Drawings::BaseViewBuilder* baseViewBuilder1;
  baseViewBuilder1 = workPart->DraftingViews()->CreateBaseViewBuilder(nullBaseView);
  baseViewBuilder1->Placement()->SetAssociative(true);   baseViewBuilder1->Style()->ViewStyleBase()->SetPart(workPart);   baseViewBuilder1->Style()->ViewStyleBase()->SetPartName(workPart->FullPath());   ModelingView* modelingView1(dynamic_cast<ModelingView*>(workPart->ModelingViews()->FindObject("Top")));
  baseViewBuilder1->SelectModelView()->SetSelectedView(modelingView1);
  Assemblies::Arrangement* nullAssemblies_Arrangement(NULL);
  baseViewBuilder1->Style()->ViewStyleBase()->Arrangement()->SetSelectedArrangement(nullAssemblies_Arrangement);   Direction* direction1;
  direction1 = workPart->Directions()->CreateDirection(maxPlanarFace, SenseForward, SmartObject::UpdateOptionAfterModeling);
  baseViewBuilder1->Style()->ViewStyleOrientation()->Ovt()->SetNormalDirection(direction1);
  Direction* direction2;
  direction2 = workPart->Directions()->CreateDirection(maxLenEdge, SenseForward, SmartObject::UpdateOptionAfterModeling);
  baseViewBuilder1->Style()->ViewStyleOrientation()->Ovt()->SetXDirection(direction2);
  baseViewBuilder1->Placement()->Placement()->SetValue(NULL, workPart->Views()->WorkView(), viewOrigin);
  NXObject* nXObject1;
  nXObject1 = baseViewBuilder1->Commit();
  baseViewTag = nXObject1->Tag();
  baseViewBuilder1->Destroy();
 }
 catch (const std::exception& e)
 {
  cout << "exception int createBaseViewNX" << e.what() << endl;
 }  return baseViewTag;
}
tag_t JUnit::createBaseView(tag_t bodyTag, Point3d viewOrigin,double zDir[3],double xDir[3]) {
 tag_t baseViewTag = NULL_TAG;
 try
 {
  //
  Part* workPart = Session::GetSession()->Parts()->Work();
  Drawings::BaseView* nullBaseView(NULL);
  Drawings::BaseViewBuilder* baseViewBuilder1;
  baseViewBuilder1 = workPart->DraftingViews()->CreateBaseViewBuilder(nullBaseView);
  baseViewBuilder1->Placement()->SetAssociative(true);   baseViewBuilder1->Style()->ViewStyleBase()->SetPart(workPart);   baseViewBuilder1->Style()->ViewStyleBase()->SetPartName(workPart->FullPath());   ModelingView* modelingView1(dynamic_cast<ModelingView*>(workPart->ModelingViews()->FindObject("Top")));
  baseViewBuilder1->SelectModelView()->SetSelectedView(modelingView1);
  Assemblies::Arrangement* nullAssemblies_Arrangement(NULL);
  baseViewBuilder1->Style()->ViewStyleBase()->Arrangement()->SetSelectedArrangement(nullAssemblies_Arrangement);   Direction* direction1;
  //direction1 = workPart->Directions()->CreateDirection(maxPlanarFace, SenseForward, SmartObject::UpdateOptionAfterModeling);
  Point* p1 = workPart->Points()->CreatePoint(Point3d(0, 0, 0));
  direction1 = workPart->Directions()->CreateDirection(p1,Vector3d(zDir[0], zDir[1], zDir[2]));
  baseViewBuilder1->Style()->ViewStyleOrientation()->Ovt()->SetNormalDirection(direction1);
  Direction* direction2;
  //direction2 = workPart->Directions()->CreateDirection(maxLenEdge, SenseForward, SmartObject::UpdateOptionAfterModeling);
  direction2 = workPart->Directions()->CreateDirection(p1, Vector3d(xDir[0], xDir[1], xDir[2]));
  baseViewBuilder1->Style()->ViewStyleOrientation()->Ovt()->SetXDirection(direction2);
  baseViewBuilder1->Placement()->Placement()->SetValue(NULL, workPart->Views()->WorkView(), viewOrigin);
  NXObject* nXObject1;
  nXObject1 = baseViewBuilder1->Commit();
  baseViewTag = nXObject1->Tag();
  baseViewBuilder1->Destroy();
 }
 catch (const std::exception& e)
 {
  cout << "exception int createBaseViewNX" << e.what() << endl;
 }  return baseViewTag;
}
#include<uf_eval.h>
#include <Windows.h>
/*获取曲线的中心点*/
inline void JUnit::getArcCenterPoint(tag_t arc, double* centerPt)
{
 double arc_length;
 UF_EVAL_p_t elpt;
 UF_EVAL_initialize(arc, &elpt);
 bool isArc;
 UF_EVAL_is_arc(elpt, &isArc);
 if (isArc == false)
 {
  UF_EVAL_free(elpt);
  return;
 }
 UF_EVAL_arc_t lat;
 UF_EVAL_ask_arc(elpt, &lat);
 if (centerPt) UF_VEC3_copy(lat.center, centerPt);
 UF_EVAL_free(elpt); }
/*显示对象*/
inline  void  JUnit::showObjects(std::vector<tag_t> list) {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 std::vector<NXOpen::DisplayableObject*> disObjs;
 for (int i = 0; i < list.size(); i++) {
  Body* body1 = dynamic_cast<Body*>(NXObjectManager::Get(list[i]));
  disObjs.push_back(body1);
 }
 theSession->DisplayManager()->ShowObjects(disObjs, NXOpen::DisplayManager::LayerSettingChangeLayerToSelectable);
 workPart->Views()->WorkView()->FitAfterShowOrHide(View::ShowOrHideTypeHideOnly);
}
inline void JUnit::fileCheckExist(const char* fileName) {
 if (_access(fileName, 0) == 0)TTool::errorMsg("文件存在!");  if (_access(fileName, 4) == 0) TTool::errorMsg("缺少读取权限!");  if (_access(fileName, 2) == 0) TTool::errorMsg("缺少写入权限!");  //if (_access(fileName, 6) == 0) fprintf(stdout, "has both read and write premission\n");
}
inline double JUnit::getDistBetween2Point(double p1[3], double p2[3]) {
 double dist = 0;
 UF_VEC3_distance(p1, p2, &dist);
 return dist;
}
inline std::string JUnit::getFileCreateTime() {
 ostringstream oss;
 oss << "ADM";
 HMODULE hModule = GetModuleHandle(NULL); // 获取当前 DLL 的模块句柄  TCHAR filePath[MAX_PATH];
 if (GetModuleFileName(hModule, filePath, MAX_PATH) > 0)
 {
  WIN32_FILE_ATTRIBUTE_DATA fileAttrData;
  if (GetFileAttributesEx(filePath, GetFileExInfoStandard, &fileAttrData))
  {
   FILETIME creationTime = fileAttrData.ftLastWriteTime;    // 将 FILETIME 转换为系统时间（SYSTEMTIME）
   SYSTEMTIME sysTime, loaclTime;
   FileTimeToSystemTime(&creationTime, &sysTime);
   SystemTimeToTzSpecificLocalTime(NULL, &sysTime, &loaclTime);
   // 输出创建时间
   oss << loaclTime.wYear << loaclTime.wMonth << loaclTime.wDay << loaclTime.wHour << loaclTime.wMinute;
  }  }
 return oss.str();
}
inline std::string JUnit::getFileVesion() {
 std::string changeTime = "none";
 char temp[256];
 GetModuleFileNameA(_AtlBaseModule.GetModuleInstance(), temp, 256);
 HANDLE hDir = CreateFileA(temp, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
 if (hDir == INVALID_HANDLE_VALUE)
 {   TTool::testUC("Get the dictionary failed!\n");
  CloseHandle(hDir);
  return "";
 }
 //定义变量
 FILETIME IpCreationTime; //文件夹的创建时间  FILETIME IpLastAccessTime; //对文件夹的最近访问时间  FILETIME IpLastWriteTime; //文件夹的最近修改时间  FILETIME ftime;  SYSTEMTIME ktime;
 //获取文件夹的时间属性  if (GetFileTime(hDir, &IpCreationTime, &IpLastAccessTime, &IpLastWriteTime))
 {
  SYSTEMTIME rtime;
  FILETIME ltime;
  FileTimeToLocalFileTime(&IpLastWriteTime, &ltime);
  FileTimeToSystemTime(&ltime, &rtime); //将文件时间转化为系统时间   //if (wYear < rtime.wYear) change = 1;
  //if (wMonth < rtime.wMonth) change = 1;
  //if (wDay < rtime.wDay) change = 1;
  char* version[256];
  UF_get_release(version);
  ostringstream oss;
  oss << version[0]<<".ADM V"<< rtime.wYear << rtime.wMonth << rtime.wDay << rtime.wHour << rtime.wMinute;
  changeTime = oss.str();
 }
 if(hDir!=NULL)CloseHandle(hDir);
 return changeTime;
}
inline std::string JUnit::getFileVesion(std::string numberStr) {
  std::string changeTime = "NULL";
  char* version[256];
  UF_get_release(version);
  ostringstream oss;
  oss << version[0] <<".ADM"<< numberStr;
  changeTime = oss.str();  return changeTime;
}
#include <regex>
/*()*/
inline void  JUnit::getValBetweenBracket2(std::string str, std::vector<std::string>& vals) {
 std::regex regex("\\((.*?)\\)");
 std::smatch match;
 while (std::regex_search(str, match, regex)) {
  vals.push_back(match.str(1));
  str = match.suffix().str();
 }
}
/*<>*/
inline void  JUnit::getValBetweenBracket1(std::string str, std::vector<std::string>& vals) {
 std::regex regex("\\<(.*?)\\>");
 std::smatch match;
 while (std::regex_search(str, match, regex)) {
  vals.push_back(match.str(1));
  str = match.suffix().str();
 }
}
/*[]*/
inline void  JUnit::getValBetweenBracket(std::string str, std::vector<std::string>& vals) {
 std::regex regex("\\[(.*?)\\]");
 std::smatch match;
 while (std::regex_search(str, match, regex)) {
  vals.push_back(match.str(1));
  str = match.suffix().str();
 }
}
#include<NXOpen/CustomSymbols.hxx>
#include<NXOpen/Annotations_CustomSymbol.hxx>
#include<NXOpen/Annotations_DraftingCustomSymbolBuilder.hxx>
#include<NXOpen/Annotations_AnnotationManager.hxx>
#include<NXOpen/Annotations_CustomSymbolCollection.hxx>
#include<uf_drf.h>
inline void  JUnit::attachToView(tag_t note_tag, tag_t view_tag) { 
 double origin[3] = { 0,0,0 };  UF_DRF_associative_origin_p_t origin_data;  UF_CALL(UF_DRF_ask_associative_origin(note_tag, &origin_data, origin));  origin_data->origin_type = UF_DRF_ORIGIN_RELATIVE_TO_VIEW;  origin_data->view_eid = view_tag;  UF_CALL(UF_DRF_set_associative_origin(note_tag, origin_data, origin)); 
}
#include<NXOpen/Annotations_LeaderDataList.hxx>
inline void JUnit::createSymbol(char part_name[255], double origin[3], double diameter, tag_t view_tag, int color, bool isFront) {
 char diameter_text[133] = "";
 sprintf(diameter_text, "%.2f", diameter);
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 Part* displayPart(theSession->Parts()->Display());
 Annotations::CustomSymbol* nullAnnotations_CustomSymbol(NULL);
 Annotations::DraftingCustomSymbolBuilder* draftingCustomSymbolBuilder1;
 draftingCustomSymbolBuilder1 = workPart->Annotations()->CustomSymbols()->CreateDraftingCustomSymbolBuilder(nullAnnotations_CustomSymbol);
 draftingCustomSymbolBuilder1->Origin()->Plane()->SetPlaneMethod(Annotations::PlaneBuilder::PlaneMethodTypeXyPlane);
 draftingCustomSymbolBuilder1->Origin()->SetAnchor(Annotations::OriginBuilder::AlignmentPositionBottomLeft);
 draftingCustomSymbolBuilder1->Scale()->SetRightHandSide(diameter_text);
 draftingCustomSymbolBuilder1->Angle()->SetRightHandSide("0");
 draftingCustomSymbolBuilder1->Origin()->Plane()->SetPlaneMethod(Annotations::PlaneBuilder::PlaneMethodTypeXyPlane);
 Annotations::LeaderData* leaderData1;
 leaderData1 = workPart->Annotations()->CreateLeaderData();
 leaderData1->SetArrowhead(Annotations::LeaderData::ArrowheadTypeFilledArrow);
 draftingCustomSymbolBuilder1->Leader()->Leaders()->Append(leaderData1);
 leaderData1->SetStubSide(Annotations::LeaderSideInferred);
 leaderData1->SetStubSize(0.3);
 draftingCustomSymbolBuilder1->Origin()->SetInferRelativeToGeometry(false);
 draftingCustomSymbolBuilder1->SelectSymbol(part_name);
 Annotations::Annotation::AssociativeOriginData assocOrigin1;
 assocOrigin1.OriginType = Annotations::AssociativeOriginTypeDrag;
 View* nullView(NULL);
 assocOrigin1.View = nullView;
 assocOrigin1.ViewOfGeometry = nullView;
 Point* nullPoint(NULL);
 assocOrigin1.PointOnGeometry = nullPoint;
 assocOrigin1.VertAnnotation = NULL;
 assocOrigin1.VertAlignmentPosition = Annotations::AlignmentPositionTopLeft;
 assocOrigin1.HorizAnnotation = NULL;
 assocOrigin1.HorizAlignmentPosition = Annotations::AlignmentPositionTopLeft;
 assocOrigin1.AlignedAnnotation = NULL;
 assocOrigin1.DimensionLine = 0;
 assocOrigin1.AssociatedView = nullView;
 assocOrigin1.AssociatedPoint = nullPoint;
 assocOrigin1.OffsetAnnotation = NULL;
 assocOrigin1.OffsetAlignmentPosition = Annotations::AlignmentPositionTopLeft;
 assocOrigin1.XOffsetFactor = 0.0;
 assocOrigin1.YOffsetFactor = 0.0;
 assocOrigin1.StackAlignmentPosition = Annotations::StackAlignmentPositionAbove;
 draftingCustomSymbolBuilder1->Origin()->SetAssociativeOrigin(assocOrigin1);
 Point3d point1(origin[0], origin[1], origin[2]);
 draftingCustomSymbolBuilder1->Origin()->Origin()->SetValue(NULL, nullView, point1);
 draftingCustomSymbolBuilder1->Origin()->SetInferRelativeToGeometry(false);
 NXObject* nXObject1;
 nXObject1 = draftingCustomSymbolBuilder1->Commit();
 
 tag_t pin = nXObject1->Tag();
 UF_OBJ_set_color(pin, color);
 if (color != 186)
 {//LB:211螺丝 符号加载，正面实线，背面虚线
  if (isFront)
   UF_OBJ_set_font(pin, UF_OBJ_FONT_SOLID);
  else
   UF_OBJ_set_font(pin, UF_OBJ_FONT_DASHED);
 }
 //attachToView(pin, view_tag);
 draftingCustomSymbolBuilder1->Destroy();
}
#include<NXOpen/Drawings_DraftingViewCollection.hxx>
inline void JUnit::deleNxobjects1() {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 std::vector<NXObject*> nxobjs;
 nxobjs.reserve(2000);
 
 //符号标注
 Annotations::IdSymbolCollection* idSc = workPart->Annotations()->IdSymbols();
 for (Annotations::IdSymbolCollection::iterator it = idSc->begin(); it != idSc->end(); it++) {
  Annotations::IdSymbol* item = *(it);
  nxobjs.push_back(item);
 }
 //注解
 Annotations::NoteCollection* nc = workPart->Notes();
 for (Annotations::NoteCollection::iterator it = nc->begin(); it != nc->end(); it++) {
  Annotations::Note* item = (Annotations::Note*) * (it);
  nxobjs.push_back(item);
 }
 //曲线
 CurveCollection* cc = workPart->Curves();
 for (CurveCollection::iterator it = cc->begin(); it != cc->end(); it++) {
  Curve* item = *(it);
  nxobjs.push_back(item);
 }
 //样条
 SplineCollection* sc = workPart->Splines();
 for (SplineCollection::iterator it = sc->begin(); it != sc->end(); it++) {
  Spline* item = *(it);
  nxobjs.push_back(item);
 }
 //线
 LineCollection* lc = workPart->Lines();
 for (LineCollection::iterator it = lc->begin(); it != lc->end(); it++) {
  Line* line1 = *(it);
  nxobjs.push_back(line1);
 }
 JUnit::deleteObjs(nxobjs);
} //获得面的边数
inline int JUnit::getFaceEdgeCount(tag_t faceTag) {
 if (faceTag == NULL_TAG)return false;
 uf_list_p_t edgesList = NULL;
 UF_MODL_ask_face_edges(faceTag, &edgesList);
 int count = 0;
 UF_MODL_ask_list_count(edgesList, &count);
 UF_MODL_delete_list(&edgesList);
 return count;
}
inline void JUnit::getEdgeMidPoint(tag_t edgeTag, double param, double outPoint[3]) {
 double tangent1[3] = { 0 };
 double p_norm1[3] = { 0 };
 double b_norm1[3] = { 0 };
 double torsion = 0;
 double rad_of_cur = 0;
 UF_CALL(UF_MODL_ask_curve_props(edgeTag, param, outPoint, tangent1, p_norm1, b_norm1, &torsion, &rad_of_cur));
}
inline Point3d JUnit::getEdgeMidPoint(tag_t edgeTag, double param) {  double tangent1[3] = { 0 };
 double p_norm1[3] = { 0 };
 double b_norm1[3] = { 0 };
 double pt[3] = { 0 };
 double torsion = 0;
 double rad_of_cur = 0;
 UF_CALL(UF_MODL_ask_curve_props(edgeTag, param, pt, tangent1, p_norm1, b_norm1, &torsion, &rad_of_cur));
 return  Point3d(pt[0], pt[1], pt[2]);
}
#include<NXOpen/MeasureFaces.hxx>
/*面积过滤*/
inline  double JUnit::getFaceArea(Face* face)
{
 double area = 0;
 try
 {
  Session* theSession = Session::GetSession();
  Part* workPart(theSession->Parts()->Work());
  Part* displayPart(theSession->Parts()->Display());
  Unit* unit1(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("SquareMilliMeter")));
  Unit* unit2(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("MilliMeter")));
  vector<IParameterizedSurface*>object(1);
  object[0] = dynamic_cast<IParameterizedSurface*>(face);
  MeasureFaces* measureFaces1;
  measureFaces1 = workPart->MeasureManager()->NewFaceProperties(unit1, unit2, 0.9888, object);
  area= measureFaces1->Area();
  delete measureFaces1;
  
 }
 catch (const std::exception& e)
 {
  TTool::errorMsg("exception in method JUnit::getFaceArea",e.what());
 }
 return  area;
}
inline NXOpen::Edge* JUnit::getCrossEdges(Face* face1, double viewDir[3],double midPointOfEdges[3] ) {
 Edge* edge1 = NULL;
 try
 {
  if (face1 == NULL) return NULL;
  std::vector<Edge*>edgeList = face1->GetEdges();
  double temp = 90;
  double len = 0;
  double midpt[3];
  /*获取面的横向边*/
  for (int j = 0; j < edgeList.size(); j++) {
   Point3d v1;
   Point3d v2;
   Point3d mid;
   edgeList[j]->GetVertices(&v1, &v2);
   mid = JUnit::getMidPointOfEdge(edgeList[j]);
   double edgDir[3] = { mid.X - v1.X,mid.Y - v1.Y, mid.Z - v1.Z };
   double angle1 = JUnit::getAngleOf2Vec3(edgDir, viewDir);
   double n = fabs(angle1 - 90);
   if (n < temp) {
    temp = n;
    edge1 = edgeList[j];
    midPointOfEdges[0] = mid.X;
    midPointOfEdges[1] = mid.Y;
    midPointOfEdges[2] = mid.Z;
    len = edgeList[j]->GetLength();
    //if (temp < 0.01)break;
   }
   else if (n<0.01 && edgeList[j]->GetLength()> len) {
    edge1 = edgeList[j];
    midPointOfEdges[0] = mid.X;
    midPointOfEdges[1] = mid.Y;
    midPointOfEdges[2] = mid.Z;
    len = edgeList[j]->GetLength();
   }
  }  }
 catch (const std::exception& e)
 {
  TTool::testMsg("exception!! in AutoDrawingModeling::getCrossEdges", e.what());
 }
 return edge1; }
inline void  JUnit::setFacesColor(std::vector<tag_t> faces, int color) {
 if (color < 1 || color>255|| faces.empty()) return;
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 DisplayModification* displayModification1;
 displayModification1 = theSession->DisplayManager()->NewDisplayModification();  displayModification1->SetApplyToAllFaces(true);  displayModification1->SetApplyToOwningParts(false);  displayModification1->SetNewColor(color);  std::vector<DisplayableObject*> objects1;
 for (int i = 0; i < faces.size();i++) {
  Face* face1(dynamic_cast<Face*>(NXObjectManager::Get(faces[i])));
  if(face1)objects1.push_back(face1);
 }
 if(!objects1.empty())
 displayModification1->Apply(objects1);  delete displayModification1; }
#include<fstream>
inline bool  JUnit::fileExists(std::string filePath) {
 std::ifstream file(filePath.c_str());
 return file.good();
} inline void  JUnit::setBodyColor(tag_t bodyTag, int color) {
 if (color < 1 || color>255 || bodyTag==NULL_TAG) return;
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 Session::UndoMarkId markId1;
 markId1 = theSession->SetUndoMark(Session::MarkVisibilityVisible, "Edit Object Display");
 DisplayModification* displayModification1;
 displayModification1 = theSession->DisplayManager()->NewDisplayModification();  displayModification1->SetApplyToAllFaces(true);  displayModification1->SetApplyToOwningParts(false);  displayModification1->SetNewColor(color);  std::vector<DisplayableObject*> objects1(1);
 Body* body1(dynamic_cast<Body*>(NXObjectManager::Get(bodyTag)));
 if (body1) {
  objects1[0] = body1;
  displayModification1->Apply(objects1);
 }  delete displayModification1; }
/*获取圆弧边的中心 */
inline int JUnit::getCycleEdgeCenter(tag_t edge1Tag, double center[3]) {
 if (!edge1Tag) return 1;
 double arc_length;
 UF_EVAL_p_t elpt;
 UF_EVAL_initialize(edge1Tag, &elpt);
 bool isArc;
 UF_EVAL_is_arc(elpt, &isArc);
 if (isArc == false)
 {
  UF_EVAL_free(elpt);
  return 1;
 }
 UF_EVAL_arc_t lat;
 UF_EVAL_ask_arc(elpt, &lat);
 UF_VEC3_copy(lat.center, center);
 UF_EVAL_free(elpt);
 return 0;
}
/*删除字符串前后空格*/
inline void JUnit::trimStr(std::string& str) {
 // 去除字符串前面的空格
 size_t pos = str.find_first_not_of(" ");
 if (pos != string::npos)
 {
  str.erase(0, pos);
 }
 else {
  str.clear();
  return;
 }  // 去除字符串后面的空格
 pos = str.find_last_not_of(" ");
 if (pos != string::npos)
 {
  str.erase(pos + 1);
 }
}
inline int JUnit::replaceStr(std::string& str, const char* oldStr, const char* newStr) {
 if (str.find(oldStr) == std::string::npos) return 1;
 str.replace(str.find(oldStr), string(oldStr).size(), newStr);
 return 0;
}
#include <iostream>
#include <string>
#include <regex>
inline void JUnit::replaceStr3(std::string& str, std::string newStr) {  // 使用正则表达式查找带圆括号的内容（包括圆括号本身）
 std::regex regex("\\(.*?\\)");
 str = std::regex_replace(str, regex, newStr);
}
inline void JUnit::replaceStr2(std::string& str, const char* oldStr, std::string newStr) {
 if (str.find(oldStr) == std::string::npos) return;
 str.replace(str.find(oldStr), string(oldStr).size(), newStr);
}
//inline void JUnit::replaceStr(std::string& str,const string oldStr, const string newStr) {
// if (str.empty() || oldStr.empty())return;
// CString cstr = JUnit::s2cs(str);
// cstr.Replace(JUnit::s2cs(oldStr), JUnit::s2cs(newStr));
// str = JUnit::cs2s(cstr);
//}
inline void  JUnit::setBodyName(tag_t body1,NXOpen::NXString name) {
 if (body1 == NULL_TAG) return;
 Body* body = NULL;
 body = dynamic_cast<Body*>(NXObjectManager::Get(body1));
 if (body) {
  body->SetName(name);
  std::vector<Features::Feature*> featList = body->GetFeatures();
  for (int i = 0; i < featList.size();i++) {
   featList[i]->SetName(name);
  }
 }
}
inline  bool JUnit::checkRW(NXOpen::NXString path) {
 DWORD attr = GetFileAttributesA(path.GetLocaleText());
 if (attr == INVALID_FILE_ATTRIBUTES) {
  cout << "无法获取文件属性！" << endl;
  return 0;
 }
 if (attr & FILE_ATTRIBUTE_DIRECTORY) {
  cout << "当前路径为文件夹，有读写权限！" << endl;
 }
 else {
  if (attr & FILE_ATTRIBUTE_READONLY) {
   cout << "当前路径为只读文件，无写权限！" << endl;
  }
  else {
   cout << "当前路径为可读写文件，有读写权限！" << endl;
  }
 }
}
/*false 没有击中，true 击中*/
inline  bool JUnit::rayCheck(tag_t bodyTag, double point[3], double dir[3], double hitPoint[3]) {
 /*射线检测*/
 double transform[16];
 int number = 0;
 UF_MTX4_identity(transform);
 UF_MODL_ray_hit_point_info_p_t hit_list = NULL;
 UF_CALL(UF_MODL_trace_a_ray(1, &bodyTag, point, dir, transform, 0, &number, &hit_list));
 if (number >0) {/*防止吴射*/
   UF_VEC3_copy(hit_list->hit_point, hitPoint);
   if (number > 1&&fabs(hit_list->hit_point[0] - point[0]) < 0.01
    && fabs(hit_list->hit_point[1] - point[1]) < 0.01
    && fabs(hit_list->hit_point[2] - point[2]) < 0.01) {
    UF_VEC3_copy(hit_list[1].hit_point, hitPoint);
   }
  
  int n = 0;
  UF_MODL_ask_point_containment(hit_list->hit_point, bodyTag, &n);   if (n == 2)number = 0;
  
 }
 UF_free(hit_list);
 return number;
}
/*false 没有射中 */
inline  bool JUnit::rayCheck(tag_t bodyTag, double point[3], double dir[3]) {
 /*射线检测*/
 double transform[16];
 int number = 0;
 UF_MTX4_identity(transform);
 UF_MODL_ray_hit_point_info_p_t hit_list = NULL;
 UF_CALL(UF_MODL_trace_a_ray(1, &bodyTag, point, dir, transform, 0, &number, &hit_list));
 if (number > 0) {/*防止吴射*/
  int n = 0;
  UF_MODL_ask_point_containment(hit_list->hit_point, bodyTag, &n);
  if (n == 2)number = 0;
 }
 UF_free(hit_list);
 return (bool)number;
}
inline void JUnit::getMidPointOfEdge(Edge* edge1, double midPoint[3]) {
 if (edge1 == NULL) return ;
 Scalar* scalar1;
 Part* workPart = Session::GetSession()->Parts()->Work();
 scalar1 = workPart->Scalars()->CreateScalar(0.5, Scalar::DimensionalityTypeNone, SmartObject::UpdateOptionDontUpdate);
 Point* point1;
 point1 = workPart->Points()->CreatePoint(edge1, scalar1, SmartObject::UpdateOptionWithinModeling);
 Point3d p= point1->Coordinates();
 midPoint[0] = p.X;
 midPoint[1] = p.Y;
 midPoint[2] = p.Z;
}
#include<NXOpen/WCS.hxx>
inline void JUnit::setWCS(){
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 Part* displayPart(theSession->Parts()->Display());  Point3d origin1(0.0, 0.0, 0.0);
 Matrix3x3 matrix1;
 matrix1.Xx = 1.0;
 matrix1.Xy = 0.0;
 matrix1.Xz = 0.0;
 matrix1.Yx = 0.0;
 matrix1.Yy = 1.0;
 matrix1.Yz = 0.0;
 matrix1.Zx = 0.0;
 matrix1.Zy = 0.0;
 matrix1.Zz = 1.0;
 workPart->WCS()->SetOriginAndMatrix(origin1, matrix1);
}
inline Point3d JUnit::getMidPointOfEdge(Edge* edge1) {
 if (edge1 == NULL) return Point3d(0.0,0.0,0.0);
 Scalar* scalar1;
 Part* workPart = Session::GetSession()->Parts()->Work();
 scalar1 = workPart->Scalars()->CreateScalar(0.5, Scalar::DimensionalityTypeNone, SmartObject::UpdateOptionDontUpdate);
 Point* point1;
 point1 = workPart->Points()->CreatePoint(edge1, scalar1, SmartObject::UpdateOptionWithinModeling);
 return point1->Coordinates();
}
//inline void JUnit::getMidPointOfEdge(Edge* edge1,double centerPt[3]) {
// if (edge1 == NULL) return ;
// Scalar* scalar1;
// Part* workPart = Session::GetSession()->Parts()->Work();
// scalar1 = workPart->Scalars()->CreateScalar(0.5, Scalar::DimensionalityTypeNone, SmartObject::UpdateOptionDontUpdate);
// Point* point1;
// point1 = workPart->Points()->CreatePoint(edge1, scalar1, SmartObject::UpdateOptionWithinModeling);
// Point3d p= point1->Coordinates();
// centerPt[0] = p.X;
// centerPt[1] = p.Y;
// centerPt[2] = p.Z;
//}
inline void JUnit::error_return(char* msg)
{
 fprintf(stderr, "\n+++ERROR : %s.\n\n", msg);
 exit(1);
};
inline  void JUnit::report_error(int result, char* alt_msg)
{
 char err_message[200];
 int found = UF_get_fail_message(result, err_message);
 if (found != 0)
  error_return(alt_msg);
 else
  error_return(err_message);
}
inline double JUnit::round(double source, int n) {
 int num1 = int(pow(10.0, n));
 int num2 = int(source * num1 + 0.5);
 double result = double(num2) / double(num1);
 return result;
}
inline void JUnit::dllCallDll(char dll_path[255])
{
 UF_initialize();
 typedef void(*load_ufusr_f_p_t)(char* param, int* retcode, int paramLen);
 load_ufusr_f_p_t load_ufusr_ptr = NULL;
 int rc = UF_CALL(UF_load_library(dll_path, "ufusr", (UF_load_f_p_t*)& load_ufusr_ptr));
 if (load_ufusr_ptr != NULL)
 {
  int retcode;
  load_ufusr_ptr(dll_path, &retcode, 1);
  UF_unload_library(dll_path);
 }
 return;
}
inline void JUnit::openFile(NXOpen::NXString file, std::string params) {
 ShellExecuteA(NULL, "open", file.GetLocaleText(), params.c_str(), NULL, SW_SHOW);
}
inline void JUnit::openFile(NXOpen::NXString file) {
 if (!JUnit::fileExists(file.GetLocaleText()))
  JUnit::myMessageBox("文件不存在!",file.GetLocaleText());
 ::ShellExecuteA(NULL, "open", file.GetLocaleText(), NULL, NULL, SW_SHOW); };
#include<NXOpen/Preferences_SessionPreferences.hxx>
#include<NXOpen/Preferences_SessionModeling.hxx> inline void JUnit::deleteObjs(std::vector<NXObject* >&list) {
 try
 {
  if (list.empty()) return;
  Session* theSession = Session::GetSession();
  Part* workPart(theSession->Parts()->Work());
  //std::vector<NXObject* >list= workPart->Layers()->GetAllObjectsOnLayer(layer);
  Session::UndoMarkId markId1;
  markId1 = theSession->SetUndoMark(Session::MarkVisibilityInvisible, "Delete"); 
  theSession->UpdateManager()->ClearErrorList();   Session::UndoMarkId markId2;
  markId2 = theSession->SetUndoMark(Session::MarkVisibilityVisible, "Delete");   int nErrs1;
  nErrs1 = theSession->UpdateManager()->AddToDeleteList(list);   bool notifyOnDelete2;
  notifyOnDelete2 = theSession->Preferences()->Modeling()->NotifyOnDelete();   int nErrs2;
  nErrs2 = theSession->UpdateManager()->DoUpdate(markId2);   theSession->DeleteUndoMark(markId1, NULL);
  list.clear();
 }
 catch (const std::exception& e)
 {
  TTool::testMsg("exception in method:JUnit::deleteObjs", e.what());
 }
   }
/*flase在一侧*/
inline bool JUnit::check2FaceSide(tag_t midstFace, std::vector<tag_t> checkedFaces, double dir[3]) {
 if (checkedFaces.size() != 2)return false;
 Face* midstFace1(dynamic_cast<Face*>(NXObjectManager::Get(midstFace)));
 Face* checkedFace1(dynamic_cast<Face*>(NXObjectManager::Get(checkedFaces[0])));
 Face* checkedFace2(dynamic_cast<Face*>(NXObjectManager::Get(checkedFaces[1])));
 double dist1 = JUnit::getMaxDistDirection(midstFace1, checkedFace1, dir);
 double dist2 = JUnit::getMaxDistDirection(midstFace1, checkedFace2, dir);
 double dist3 = JUnit::getMaxDistDirection(checkedFace1, checkedFace2, dir);
 if (fabsf((dist1 + dist2) - dist3) >(double) 0.001) return false;
 return true; }
/*false在一侧*/
inline bool JUnit::check2FaceSide(tag_t midstFace, tag_t checkedFaces[2],double dir[3]) {
 Face* midstFace1(dynamic_cast<Face*>(NXObjectManager::Get(midstFace)));
 Face* checkedFace1(dynamic_cast<Face*>(NXObjectManager::Get(checkedFaces[0])));
 Face* checkedFace2(dynamic_cast<Face*>(NXObjectManager::Get(checkedFaces[1])));
 double dist1 = JUnit::getMaxDistDirection(midstFace1, checkedFace1, dir);
 double dist2 = JUnit::getMaxDistDirection(midstFace1, checkedFace2, dir);
 double dist3 = JUnit::getMaxDistDirection(checkedFace1, checkedFace2, dir);
 if (fabsf((dist1 + dist2) - dist3) > (double)0.001) return false;
 return true; }
#include<NXOpen/MeasureFaceBuilder.hxx>
//inline double getFaceArea(tag_t face) {
// Session* theSession = Session::GetSession();
// Part* workPart(theSession->Parts()->Work());
// Face* face1 = dynamic_cast<Face*>(NXObjectManager::Get(face));
// NXObject* nullNXObject(NULL);
// MeasureFaceBuilder * measureFaceBuilder1;
// measureFaceBuilder1 = workPart->MeasureManager()->CreateMeasureFaceBuilder(nullNXObject);
// measureFaceBuilder1->d
//}
inline bool JUnit::getMaxDiamEdge(tag_t faceTag, tag_t* edgTag) {
 if (!faceTag) return 0;
 Face* face1(dynamic_cast<Face*>(NXObjectManager::Get(faceTag)));
 std::vector<Edge*> edgesV=face1->GetEdges();
 double diamMax = 0;
 tag_t tempTag = NULL_TAG;
 for (int i = 0; i < edgesV.size();i++) {
  if (edgesV[i]->SolidEdgeType()== Edge::EdgeTypeCircular) {
   double temp=JUnit::getDiamOfCircularEdge(edgesV[i]->Tag());
   if (temp > diamMax) {
    diamMax = temp;
    tempTag = edgesV[i]->Tag();
   }
  }
 }
 if (tempTag == NULL_TAG) return 0;
 *edgTag = tempTag;
 return 1;
}
/*获取圆弧边的直径*/
double JUnit::getDiamOfCircularEdge(tag_t edge1Tag) {
 double dim=0;
 Edge* edge1(dynamic_cast<Edge*>(NXObjectManager::Get(edge1Tag)));
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());  Unit* unit1(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("MilliMeter")));
 MeasureDistance* measureDistance1;
 measureDistance1 = workPart->MeasureManager()->NewDistance(unit1, edge1, MeasureManager::RadialMeasureTypeDiameter);
 dim=measureDistance1->Value();
 return dim;
}
/*获取圆弧边的中心*/
void JUnit::getCycleEdgeCenter1(tag_t edge1Tag,double p[3]) {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 Edge* edge1(dynamic_cast<Edge*>(NXObjectManager::Get(edge1Tag)));
 //if(edge1->SolidEdgeType())
 Point* point1;
 point1 = workPart->Points()->CreatePoint(edge1, SmartObject::UpdateOptionWithinModeling);
 Point3d p1  = point1->Coordinates();  
 p[0] = p1.X;
 p[1] = p1.Y;
 p[2] = p1.Z;
 TTool::testMsg(p,3);
 tag_t pointTag = NULL_TAG;
 UF_CURVE_create_point(p, &pointTag);
 UF_CALL(UF_OBJ_set_color(pointTag, 186));
}
inline void JUnit::getFaceDir(tag_t faceTag, double dir[3]) {
 try
 {
  Session* theSession = Session::GetSession();
  Part* workPart(theSession->Parts()->Work());
  Face* face1 = dynamic_cast<Face*>(NXObjectManager::Get(faceTag));   Direction* direction1;
  direction1 = workPart->Directions()->CreateDirection(face1, SenseForward, SmartObject::UpdateOptionAfterModeling);
  Vector3d vec1 = direction1->Vector();
  dir[0] = vec1.X;
  dir[1] = vec1.Y;
  dir[2] = vec1.Z;
 }
 catch (const std::exception& e)
 {
  UF_OBJ_set_color(faceTag,1);
  TTool::testUC("exception in JUnit::getFaceDir",e.what());
 }
 
}
inline void JUnit::getQuadrantFace(tag_t body, double mtx[9],std::vector<tag_t>& faces) {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 Part* displayPart(theSession->Parts()->Display());
 
 Body* body1 = dynamic_cast<Body*>(NXObjectManager::Get(body));
 std::vector<Face*> faceV = body1->GetFaces();
 /*体的长宽高*/
 double distX = JUnit::getMaxDistDirection(body1, body1, &(mtx[0]));
 double distY = JUnit::getMaxDistDirection(body1, body1, &(mtx[3]));
 double distZ = JUnit::getMaxDistDirection(body1, body1, &(mtx[6]));
 /*体的中心点*/
 Point3d p= JUnit::getObjCenter(body);
 /*按坐标方向取点*/
 double vecP[3] = { p.X,p.Y,p.Z};
 double maxXP[3];
 double maxYP[3];
 double maxZP[3];
 UF_VEC3_affine_comb(vecP, distX *2, &(mtx[0]), maxXP);
 UF_VEC3_affine_comb(vecP, distY *2, &(mtx[3]), maxYP);
 UF_VEC3_affine_comb(vecP, distZ *2, &(mtx[6]), maxZP);
 Point* pX = workPart->Points()->CreatePoint(Point3d(maxXP[0], maxXP[1], maxXP[2]));
 Point* pY = workPart->Points()->CreatePoint(Point3d(maxYP[0], maxYP[1], maxYP[2]));
 Point* pZ = workPart->Points()->CreatePoint(Point3d(maxZP[0], maxZP[1], maxZP[2]));
 
 /*各点到体的最大最小距离*/
 double maxDistX= JUnit::getMaxDistDirection(body1, pX, &(mtx[0]));
 double minDistX= JUnit::getMinDistDirection(body1, pX, &(mtx[0]));
 double maxDistY = JUnit::getMaxDistDirection(body1, pY, &(mtx[3]));
 double minDistY = JUnit::getMinDistDirection(body1, pY, &(mtx[3]));
 double maxDistZ = JUnit::getMaxDistDirection(body1, pZ, &(mtx[6]));
 double minDistZ = JUnit::getMinDistDirection(body1, pZ, &(mtx[6]));  /*存放上下左右前后六个方向的外表平面*/
 tag_t  faceTagMinX = NULL_TAG;/*X负方向的面*/
 tag_t  faceTagMaxX = NULL_TAG;/*X正方向的面*/
 tag_t  faceTagMinY = NULL_TAG;/*Y负方向的面*/
 tag_t  faceTagMaxY = NULL_TAG;/*Y正方向的面*/
 tag_t  faceTagMinZ = NULL_TAG;/*Z负方向的面*/
 tag_t  faceTagMaxZ = NULL_TAG;/*Z正方向的面*/
 double angleXmin = 89;
 double angleXmax = 89;
 double angleYmin = 89;
 double angleYmax = 89;
 double angleZmin = 89;
 double angleZmax = 89;
 for (int i = 0; i < faceV.size(); i++) {
  int type = faceV[i]->SolidFaceType();
  if (type != Face::FaceTypePlanar)continue;
   /*面的法向*/
   double faceDir[3];
   JUnit::getFaceDir(faceV[i]->Tag(), faceDir);
   
   double bodyDirMinX[3] = { -mtx[0],-mtx[1],-mtx[2] };
   /*平面法向和零件坐X负标的夹角*/
   double angle1 = JUnit::getAngleOf2Vec3(faceDir, bodyDirMinX);
   /*取夹角最小的平面进行计算*/
   if (angle1 < angleXmin) {
    /*体外X方向的辅助点到面的最大距离*/
    double dist1 = JUnit::getMaxDistDirection(pX, faceV[i], &(mtx[0]));
    /*和零件x方向的最大长度进行比较*/
    if (fabsf(dist1 - maxDistX) < 0.001) {
     angleXmin = angle1;
     faceTagMinX = faceV[i]->Tag();
     //UF_OBJ_set_color(faceTagMinX, 186);
    }
   };
   double bodyDirMaxX[3] = { mtx[0],mtx[1],mtx[2] };
   angle1 = JUnit::getAngleOf2Vec3(faceDir, bodyDirMaxX);
   if (angle1 < angleXmax) {
    double dist2 = JUnit::getMinDistDirection(pX, faceV[i], &(mtx[0]));
    if (fabsf(dist2 - minDistX) < (double)0.001) {
     angleXmax = angle1;
     faceTagMaxX = faceV[i]->Tag();
     //UF_OBJ_set_color(faceTagMaxX, 11);
    }
   }
   double bodyDirMinY[3] = {- mtx[3],-mtx[4],-mtx[5] };
   angle1 = JUnit::getAngleOf2Vec3(faceDir, bodyDirMinY);
   if (angle1 < angleYmin) {
    
    double dist3 = JUnit::getMaxDistDirection(pY, faceV[i], &(mtx[3]));
    if (fabsf(dist3 - maxDistY) < 0.001) {
     angleYmin = angle1;
     faceTagMinY = faceV[i]->Tag();
     //UF_OBJ_set_color(faceTagMinY, 211);
    }
   }
   double bodyDirMaxY[3] = { mtx[3],mtx[4],mtx[5] };
   angle1 = JUnit::getAngleOf2Vec3(faceDir, bodyDirMaxY);
   if (angle1 < angleYmax) {
    double dist4 = JUnit::getMinDistDirection(pY, faceV[i], &(mtx[3]));
    if (fabsf(dist4 - minDistY) < 0.001) {
     angleYmax = angle1;
     faceTagMaxY = faceV[i]->Tag();
     //UF_OBJ_set_color(faceTagMaxY, 200);
    }
   }
   double bodyDirMinZ[3] = {- mtx[6],-mtx[7],-mtx[8] };
   angle1 = JUnit::getAngleOf2Vec3(faceDir, bodyDirMinZ);
   if (angle1 < angleZmin) {
    double dist5 = JUnit::getMaxDistDirection(pZ, faceV[i], &(mtx[6]));
    if (fabsf(dist5 - maxDistZ) < 0.001) {
     angleZmin = angle1;
     faceTagMinZ = faceV[i]->Tag();
     //UF_OBJ_set_color(faceTagMinZ, 216);
    }
   }
   double bodyDirMaxZ[3] = { mtx[6],mtx[7],mtx[8] };
   angle1 = JUnit::getAngleOf2Vec3(faceDir, bodyDirMaxZ);
   if (angle1 < angleZmax) {
    double dist6 = JUnit::getMinDistDirection(pZ, faceV[i], &(mtx[6]));
    if (fabsf(dist6 - minDistZ) < 0.001) {
     angleZmax = angle1;
     faceTagMaxZ = faceV[i]->Tag();
     //UF_OBJ_set_color(faceTagMaxZ, 1);
    }
   }
  
 }
 
 faces.push_back(faceTagMinX);
 faces.push_back(faceTagMaxX);
 faces.push_back(faceTagMinY);
 faces.push_back(faceTagMaxY);
 faces.push_back(faceTagMinZ);
 faces.push_back(faceTagMaxZ);
}
inline std::vector<double> JUnit::getNumbersOfStr(NXOpen::NXString str){
 std::vector<double> resultV;
 std::string tempStr(JUnit::trimEmpty(str.GetLocaleText()).GetLocaleText());
 std::string subStr="";
 //TTool::testMsg(tempStr);
 for (int i = 0; i < tempStr.size();i++) {
  
  if (tempStr[i] >= '0' && tempStr[i] <= '9') {
   subStr.push_back(tempStr[i]);
  }
  else if(tempStr[i] =='.'&& subStr.size()>0&& subStr.find(".")==std::string::npos){
   subStr.push_back(tempStr[i]);
  }
  else if (tempStr[i] =='-'&& subStr.size() == 0) {
   subStr.push_back(tempStr[i]);
  }
  else if(subStr.size() > 0){
    if (subStr.back() == '.') subStr.push_back('0');
    resultV.push_back(JUnit::toF(subStr));
    subStr.clear();
  }
  if ( i == tempStr.size() - 1&& subStr.size() > 0) {
   resultV.push_back(JUnit::toF(subStr));
   subStr.clear();
  }
 }
 
 //if (!resultV.empty())sort(resultV.begin(), resultV.end(), [](double a, double b)->bool {return a >b; });
 if (resultV.empty())resultV.push_back(0.0);
 return resultV;
}
inline void JUnit::swapVec3(double* a, double* b) {
 double temp[3];
 UF_VEC3_copy(a, temp);
 UF_VEC3_copy(b, a);
 UF_VEC3_copy(temp, b);
}
inline void JUnit::setDisplayPart(tag_t partTag) {
 
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 Part* displayPart(theSession->Parts()->Display());
 Part* part1= dynamic_cast<Part*>(NXObjectManager::Get(partTag));
 PartLoadStatus* partLoadStatus1;
 PartCollection::SdpsStatus status1;
 status1 = theSession->Parts()->SetDisplay(part1, true, true, &partLoadStatus1);  workPart = theSession->Parts()->Work();
 displayPart = theSession->Parts()->Display();
 delete partLoadStatus1;
}
inline tag_t JUnit::newFile(NXOpen::NXString fileName)
{
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 Part* displayPart(theSession->Parts()->Display());  FileNew* fileNew1;
 fileNew1 = theSession->Parts()->FileNew(); 
 fileNew1->SetTemplateFileName("model-plain-1-mm-template.prt");  fileNew1->SetApplication(FileNewApplicationModeling);  fileNew1->SetUnits(Part::UnitsMillimeters);  fileNew1->SetTemplateType(FileNewTemplateTypeItem);  fileNew1->SetNewFileName(fileName);  fileNew1->SetMasterFileName("");  fileNew1->SetUseBlankTemplate(false);  fileNew1->SetMakeDisplayedPart(true);  NXObject* nXObject1;
 nXObject1 = fileNew1->Commit();
 fileNew1->Destroy();
 return nXObject1->Tag();  // ----------------------------------------------
}
inline void JUnit::blandBody1(Part* part, tag_t bodyTag) {
 Session* theSession = Session::GetSession();
 NXOpen::PartLoadStatus* loadStatus= part->LoadFully();
 Part* workPart = part;
 std::vector<NXOpen::DisplayableObject*> disObj(1);
 Body* body1 = dynamic_cast<Body*>(NXObjectManager::Get(bodyTag));
 disObj[0] = body1;
 theSession->DisplayManager()->BlankObjects(disObj);
 workPart->Views()->WorkView()->FitAfterShowOrHide(View::ShowOrHideTypeHideOnly);
 delete loadStatus; }
inline void JUnit::writeAttrStr(tag_t objTag, NXOpen::NXString title1, NXOpen::NXString valueStr) {
 UF_ATTR_value_t value;
 value.type = UF_ATTR_string;
 value.value.string = const_cast<char*>(valueStr.GetLocaleText());  char title[UF_ATTR_MAX_TITLE_LEN + 1]="";
 sprintf_s(title, "%s", title1.GetLocaleText());
 UF_CALL(UF_ATTR_assign(objTag, title, value));
}
inline std::string JUnit::ws2s(const std::wstring& ws) {
  string curLocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "chs");
  const wchar_t* _Source = ws.c_str();
  size_t  _Dsize = 2 * ws.size() + 1;
  char* _Dest = new char[_Dsize];
  memset(_Dest, 0, _Dsize);
  wcstombs(_Dest, _Source, _Dsize);
  string str;
  str = _Dest;
  delete[]_Dest;
  setlocale(LC_ALL, curLocale.c_str());
  return str;
}
inline std::string JUnit::cs2s(CString cs) {
 char str[1024];
 wsprintfA(str, "%ls", cs.GetBuffer());
 return std::string(str);
}
inline CString JUnit::s2cs(const NXOpen::NXString& s) {
 std::string curLocale = setlocale(LC_ALL, "");
 const char* _Source = s.GetLocaleText();
 size_t _Dsize = mbstowcs(NULL, _Source, 0) + 1;
 wchar_t* _Dest = new wchar_t[_Dsize];
 wmemset(_Dest, 0, _Dsize);
 mbstowcs(_Dest, _Source, _Dsize);
 CString result = _Dest;
 delete[]_Dest;
 setlocale(LC_ALL, curLocale.c_str());
 return result;
}
inline std::wstring JUnit::s2ws(const std::string& s)
{
 std::string curLocale = setlocale(LC_ALL, "");
 const char* _Source = s.c_str();
 size_t _Dsize = mbstowcs(NULL, _Source, 0) + 1;
 wchar_t* _Dest = new wchar_t[_Dsize];
 wmemset(_Dest, 0, _Dsize);
 mbstowcs(_Dest, _Source, _Dsize);
 std::wstring result = _Dest;
 delete[]_Dest;
 setlocale(LC_ALL, curLocale.c_str());
 return result;
} /*连接曲线*/
inline tag_t  JUnit::connectingCurve(std::vector<Curve*> curveList) {
 tag_t linesJoin = NULL_TAG;
 int statu = 0;
 uf_list_p_t list = NULL;
 UF_MODL_create_list(&list);
 
 for (int i = 0; i < curveList.size(); i++) {
  UF_MODL_put_list_item(list, curveList[i]->Tag());
 }
 UF_CALL(UF_CURVE_create_joined_curve(list, 2, &linesJoin, &statu));
 UF_MODL_delete_list(&list);
 return linesJoin;
}
/*0-180*/
inline double  JUnit::getAngleOf2Vec3(double v1[3], double v2[3]) {  /*cosA=a*b/|a|*|b|*/
 return acos((v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2])/(sqrt(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2])* sqrt(v2[0] * v2[0] + v2[1] * v2[1] + v2[2] * v2[2])))/PI*180;
}
inline bool  JUnit::isSyntropyVec3(double v1[3], double v2[3]) {
 double temp;
 UF_VEC3_dot(v1, v2, &temp);
 return  temp > 0 ? true:false;
}
/*判断两个方向是否平行 1 平行 0不平行*/
inline bool  JUnit::isParallelVec3(double v1[3], double v2[3]) {
 int is_parallel = 0;
 UF_VEC3_is_parallel(v1, v2, 0.0254, &is_parallel);
 return (bool)is_parallel;
}
/*1 Vectors are perpendicular*/
inline bool JUnit::isPerpendicularVec3(double v1[3], double v2[3]) {
 int is_perpendicular = 0;
 UF_VEC3_is_perpendicular(v1, v2, 0.0254, &is_perpendicular);
 return (bool)is_perpendicular;
}
inline bool  JUnit::isEqualVec3(double v1[3], double v2[3]) {
 int result = 0;
 UF_VEC3_is_equal(v1, v2, 0.001, &result);
 return (bool)result;
}
inline double JUnit::getMinDistDirection(NXOpen::DisplayableObject* obj1, NXOpen::DisplayableObject* obj2, double direction[3]) {
 if (obj1 == NULL|| obj2==NULL) return -1;
 double diam = 0;
 try
 {
  Session* theSession = Session::GetSession();
  Part* workPart(theSession->Parts()->Work());   NXOpen::Direction* direction1 = workPart->Directions()->CreateDirection(Point3d(0, 0, 0), Vector3d(direction[0], direction[1], direction[2]), NXOpen::SmartObject::UpdateOptionDontUpdate);   Unit* unit1(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("MilliMeter")));
  MeasureDistance* measureDistance1;
  measureDistance1 = workPart->MeasureManager()->NewDistance(unit1, obj1, obj2, direction1, NXOpen::MeasureManager::ProjectionType::ProjectionTypeMinClearance);   diam = measureDistance1->Value();  }
 catch (const std::exception& e)
 {
  TTool::testMsg(e.what());
  TTool::testMsg("exception in method:JUnit::getCylinderFaceDiam");
 }
 return diam; }
/*最大投影距离*/
inline double JUnit::getMaxDist(NXOpen::DisplayableObject* obj1, NXOpen::DisplayableObject* obj2) {
 double diam = 0;
 try
 {
  Session* theSession = Session::GetSession();
  Part* workPart(theSession->Parts()->Work());
  Scalar* scalar1;
  scalar1 = workPart->Scalars()->CreateScalar(0.685416055614086, Scalar::DimensionalityTypeNone, SmartObject::UpdateOptionAfterModeling);   Unit* unit1(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("MilliMeter")));
  MeasureDistance* measureDistance1;
  measureDistance1 = workPart->MeasureManager()->NewDistance(unit1, NXOpen::MeasureManager::MeasureTypeMaximum, obj1, obj2);
  diam = measureDistance1->Value();  }
 catch (const std::exception& e)
 {
  TTool::testMsg(e.what());
  TTool::testMsg("exception in method:JUnit::getCylinderFaceDiam");
 }
 return diam;
}
inline double JUnit::getMinDist(NXOpen::DisplayableObject* obj1, NXOpen::DisplayableObject* obj2) {
 
 double diam = 0;
 if (obj1 == NULL || obj2 == NULL)return diam;
 try
 {
  Session* theSession = Session::GetSession();
  Part* workPart(theSession->Parts()->Work());
  Scalar* scalar1;
  scalar1 = workPart->Scalars()->CreateScalar(0.685416055614086, Scalar::DimensionalityTypeNone, SmartObject::UpdateOptionAfterModeling);   Unit* unit1(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("MilliMeter")));
  MeasureDistance* measureDistance1;
  measureDistance1 = workPart->MeasureManager()->NewDistance(unit1, NXOpen::MeasureManager::MeasureTypeMinimum,obj1, obj2);
  diam = measureDistance1->Value();  }
 catch (const std::exception& e)
 {
  TTool::errorMsg(e.what());
  TTool::errorMsg("exception in method:JUnit::getMinDist");
 }
 return diam;
}
/*面的深度*/
inline double JUnit::getMaxDistDirection(NXOpen::DisplayableObject* obj1, NXOpen::DisplayableObject* obj2, double direction[3]) {
 double diam = 0;
 try
 {
  Session* theSession = Session::GetSession();
  Part* workPart(theSession->Parts()->Work());
  Scalar* scalar1;
  scalar1 = workPart->Scalars()->CreateScalar(0.685416055614086, Scalar::DimensionalityTypeNone, SmartObject::UpdateOptionAfterModeling);   NXOpen::Direction* direction1 = workPart->Directions()->CreateDirection(Point3d(0,0,0), Vector3d(direction[0], direction[1], direction[2]),NXOpen::SmartObject::UpdateOptionDontUpdate);   Unit* unit1(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("MilliMeter")));
  MeasureDistance* measureDistance1;
  measureDistance1 = workPart->MeasureManager()->NewDistance(unit1,obj1,obj2, direction1,NXOpen::MeasureManager::ProjectionType::ProjectionTypeMaxClearance);   diam = measureDistance1->Value();
  
 }
 catch (const std::exception& e)
 {
  TTool::testMsg(e.what());
  TTool::testMsg("exception in method:JUnit::getCylinderFaceDiam");
 }
 return diam; }
inline double JUnit::getCylinderFaceDiam(NXOpen::Face* cylinderFace) {
 double diam = 0;
 try
 {
  if (cylinderFace->SolidFaceType() != Face::FaceType::FaceTypeCylindrical) return diam;
  Session* theSession = Session::GetSession();
  Part* workPart(theSession->Parts()->Work());   Unit* unit1(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("MilliMeter")));
  MeasureDistance* measureDistance1;
  measureDistance1 = workPart->MeasureManager()->NewDistance(unit1, cylinderFace, MeasureManager::RadialMeasureTypeDiameter);   diam = measureDistance1->Value();
 }
 catch (const std::exception& e)
 {
  TTool::testMsg(e.what());
  TTool::testMsg("exception in method:JUnit::getCylinderFaceDiam");
 }
 return diam;
 
} /*在图纸上创建圆*/
inline tag_t JUnit::createCycle(double diameter, double drawPoint[3]) {
 drawPoint[2] = 0;
 tag_t mtxId = NULL_TAG;
 double mtxVal[9] = {1,0,0,0,1,0,0,0,1};
 UF_CSYS_create_matrix(mtxVal, &mtxId);
 UF_CURVE_arc_t data = { 0 };
 data.matrix_tag = mtxId;
 data.start_angle = 0.0;
 data.end_angle = TWOPI;
 data.radius = diameter/2;
 UF_MTX3_vec_multiply(drawPoint, mtxVal, data.arc_center);
 tag_t arcId = NULL_TAG;
 UF_CURVE_create_arc(&data, &arcId); // 创建圆弧
 return arcId;
}
inline bool JUnit::isDirectoryExists(const std::string& directoryPath) {
 DWORD fileAttributes = GetFileAttributesA(directoryPath.c_str());
 return (fileAttributes != INVALID_FILE_ATTRIBUTES && (fileAttributes & FILE_ATTRIBUTE_DIRECTORY));
} inline void JUnit::checkPath(std::string filePath) {
  if (_access(filePath.c_str(), 0) == -1) {
   char code[256];
   sprintf(code, "mkdir %s", filePath.c_str());
   system(code);
  }
}
inline NXOpen::NXString  JUnit::getCurrentDisplayPartPath() {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 Part* displayPart(theSession->Parts()->Display());
 return displayPart->FullPath();
}
inline std::string JUnit::getDate() {
 time_t nowtime;
 nowtime = time(NULL);
 struct tm* local;
 local = localtime(&nowtime);//获取当前系统时间 
 char buf[80];
 strftime(buf, 80, "%Y/%m/%d %H:%M", local);
 return buf;
}
inline std::string JUnit::getDate2() {
 time_t nowtime;
 nowtime = time(NULL);
 struct tm* local;
 local = localtime(&nowtime);//获取当前系统时间 
 char buf[80];
 strftime(buf, 80, "%d%H%M%S", local);
 return buf;
}
inline std::string JUnit::getDate3() {
 time_t nowtime;
 nowtime = time(NULL);
 struct tm* local;
 local = localtime(&nowtime);//获取当前系统时间 
 char buf[80];
 strftime(buf, 80, "%Y%d%H%M%S", local);
 return buf;
}
inline double JUnit::getWeight(tag_t bodyTag) {
 try
 {
  Session* theSession = Session::GetSession();
  Part* workPart(theSession->Parts()->Work());
  Part* displayPart(theSession->Parts()->Display());    std::vector<NXOpen::IBody*> objects;/** Array of solid bodies */
  
   NXOpen::Body* body1 = dynamic_cast<NXOpen::Body*>(NXObjectManager::Get(bodyTag));
   objects.push_back(body1);
  
  std::vector<Unit*> massUnits1(5);
  Unit* unit1(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("SquareMilliMeter")));
  massUnits1[0] = unit1;
  Unit* unit2(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("CubicMilliMeter")));
  massUnits1[1] = unit2;
  Unit* unit3(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("Kilogram")));
  massUnits1[2] = unit3;
  Unit* unit4(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("MilliMeter")));
  massUnits1[3] = unit4;
  Unit* unit5(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("Newton")));
  massUnits1[4] = unit5;
  MeasureBodies* measureBodies1;
  measureBodies1 = workPart->MeasureManager()->NewMassProperties(massUnits1, 0.99, objects);
  NXObject* nullNXObject(NULL);
  MeasureBodyBuilder* measureBodyBuilder1;
  measureBodyBuilder1 = workPart->MeasureManager()->CreateMeasureBodyBuilder(nullNXObject);
  double weight = measureBodies1->Weight();   delete measureBodies1;
  
  return weight;
  
 }
 catch (const std::exception& e)
 {
  TTool::testMsg(e.what());
 }
 return 0;
}
/*将实体移动到指定图层*/
inline void JUnit::moveSolidToLayer(std::vector<tag_t>solidList, int layer) {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 std::vector<DisplayableObject*> objectArray1(solidList.size());
 for (int i = 0; i < solidList.size();i++) {
  Body*body1=dynamic_cast<Body* >( NXObjectManager::Get(solidList[i]));
  objectArray1[i] = body1;
 }
 workPart->Layers()->MoveDisplayableObjects(1, objectArray1);
}
/*投影视图*/
inline void JUnit::improtView1(NXOpen::NXString title1, tag_t viewTag) {
 //获取视图对象
 //tag_t viewTag = NULL_TAG;
 //UF_CALL(UF_OBJ_cycle_by_name_and_type(UF_ASSEM_ask_work_part(), "Top", UF_view_type, false, &viewTag));
 /*double  angle_value = 90;
 double axis[] = { 0,1,0 }; 
 UF_CALL(UF_VIEW_rotate_view(viewTag, axis, angle_value, 1));
 TTool::testMsg(angle_value);*/  tag_t drawTag = NULL_TAG;
 UF_CALL(UF_DRAW_ask_current_drawing(&drawTag));  
 double dwg_reference_point[2] = { 1000,1000 };
 
 UF_DRAW_view_info_t view_info;
 UF_DRAW_initialize_view_info(&view_info);
 tag_t topViewTag = NULL_TAG;
 UF_CALL(UF_DRAW_import_view(drawTag, viewTag, dwg_reference_point, &view_info, &topViewTag));
 
}
/*查找属性*/
inline int JUnit::findAttr(tag_t objTag, NXOpen::NXString title1) {
 if (objTag == NULL_TAG)return 0;
 char title[UF_ATTR_MAX_TITLE_LEN + 1]="";
 
 sprintf_s(title, "%s", title1.GetLocaleText());
 int titleType = 0;
 if (UF_CALL(UF_ATTR_find_attribute(objTag, UF_ATTR_any, title, &titleType))) {
  TTool::errorMsg("异常属性名 ",title1);
  TTool::errorMsg(strlen(title));
  return 0;
 };
 return titleType;
}
/*获取属性值*/
inline int JUnit::getAttrValueInt(tag_t objTag, NXOpen::NXString title1, int& intVal){
 UF_ATTR_value_t val;
 
 if (objTag == NULL_TAG) {
  TTool::testUC("exception in method:JUnit::getAttrValueStr,objTag==NULL_TAG");
  return 1;
 }
 char title[UF_ATTR_MAX_TITLE_LEN + 1] = "";
 sprintf(title, "%s", title1.GetLocaleText());
 int titleType = JUnit::findAttr(objTag, title);
 val.type = titleType;
 if (titleType == UF_ATTR_integer) {
  val.value.string = NULL;
  UF_CALL(UF_ATTR_read_value(objTag, title, UF_ATTR_integer, &val));
  intVal = val.value.integer;
  return 0;
 }
 return 1;
}
inline int JUnit::getAttrValueStr(tag_t objTag, NXOpen::NXString title1, NXOpen::NXString& valStr) {
 UF_ATTR_value_t val;
 valStr = "";
 if (objTag == NULL_TAG) {
  TTool::testUC("exception in method:JUnit::getAttrValueStr,objTag==NULL_TAG");
  return 1;
 }
 char title[UF_ATTR_MAX_TITLE_LEN] = "";
 sprintf(title, "%s", title1.GetLocaleText());
 int titleType = JUnit::findAttr(objTag, title);
 val.type = titleType;
 if (titleType == UF_ATTR_string) {
  val.value.string = NULL;
  UF_CALL(UF_ATTR_read_value(objTag, title, UF_ATTR_string, &val));
  valStr = val.value.string;
  UF_free(val.value.string);
  return 0;
 }
 return 1;
}
inline int JUnit::getAttrValueStr(tag_t objTag, NXOpen::NXString title1, std::string& valStr){
 UF_ATTR_value_t val;
 valStr = "";
 if (objTag == NULL_TAG||strlen(title1.GetLocaleText())<1) {
  TTool::testUC("exception in method:JUnit::getAttrValueStr,objTag==NULL_TAG or title1 null");
  return 1;
 }
 char title[UF_ATTR_MAX_TITLE_LEN + 1] = "";
 sprintf_s(title, "%s", title1.GetLocaleText());
 int titleType = JUnit::findAttr(objTag, title);
 val.type = titleType;
 if (titleType == UF_ATTR_string) {
  val.value.string = NULL;
  UF_CALL(UF_ATTR_read_value(objTag, title, UF_ATTR_string, &val));
  valStr = val.value.string;
  UF_free(val.value.string);
  return 0;
 }
 return 1;
}
inline UF_ATTR_value_t JUnit::getAttrValue(tag_t objTag, NXOpen::NXString title1) {
 UF_ATTR_value_t val;
 if (objTag==NULL_TAG) {
  TTool::testUC("exception in method:JUnit::getAttrValue,objTag==NULL_TAG");
  return val;
 }
 
 int titleType = JUnit::findAttr(objTag,title1);
 
 val.type = titleType;
 char title[UF_ATTR_MAX_TITLE_LEN + 1];
 sprintf(title, "%s", title1.GetLocaleText());
 if (titleType== UF_ATTR_string) {
  val.value.string = NULL;
  UF_CALL(UF_ATTR_read_value(objTag,title, UF_ATTR_string,&val));
 }
 else if (titleType == UF_ATTR_integer) {
  UF_CALL(UF_ATTR_read_value(objTag, title, UF_ATTR_integer, &val));
 }
 return  val;
} /*显示所有对象*/
inline void JUnit::unBlankObjects(const std::vector<tag_t> objs) {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 std::vector<NXOpen::DisplayableObject*> disObjs;  for (int i = 0; i < objs.size();i++) {
  Body *body1= dynamic_cast<Body*>(NXObjectManager::Get(objs[i]));
  disObjs.push_back(body1);
 }
 theSession->DisplayManager()->UnblankObjects(disObjs);
 workPart->Views()->WorkView()->FitAfterShowOrHide(View::ShowOrHideTypeHideOnly); } inline void JUnit::blankAll() {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 std::vector<NXOpen::DisplayableObject*> disObjs;
 //点
 PointCollection *pointColl= workPart->Points();
 for (PointCollection::iterator it = pointColl->begin(); it != pointColl->end(); it++) {
  Point * item = *(it);
  disObjs.push_back(item);
 }
 //尺寸
 Annotations::DimensionCollection * dimC=workPart->Dimensions();
 for (Annotations::DimensionCollection::iterator it = dimC->begin(); it != dimC->end(); it++) {
  Annotations::Dimension * item = *(it);
  disObjs.push_back(item);
 }  //剖面线
 Annotations::HatchCollection *hatchColl =workPart->Annotations()->Hatches();
 for (Annotations::HatchCollection::iterator it = hatchColl->begin(); it != hatchColl->end(); it++) {
  Annotations::Hatch* item = *(it);
  disObjs.push_back(item);
 }
 //标签
 Annotations::LabelCollection *labC=workPart->Labels();
 for (Annotations::LabelCollection::iterator it = labC->begin(); it != labC->end(); it++) {
  Annotations::Label* item = *(it);
  disObjs.push_back(item);
 }
 //符号标注
 Annotations::IdSymbolCollection* idSc=workPart->Annotations()->IdSymbols();
 for (Annotations::IdSymbolCollection::iterator it = idSc->begin(); it != idSc->end(); it++) {
  Annotations::IdSymbol* item = *(it);
  disObjs.push_back(item);
 }
 //线
 LineCollection* lc= workPart->Lines();
 
 for (LineCollection::iterator it = lc->begin(); it != lc->end();it++) {
  Line* line1= *(it);
  disObjs.push_back(line1);
 }
 //体
 BodyCollection* bc= workPart->Bodies();  for (BodyCollection::iterator it = bc->begin(); it != bc->end(); it++) {
  Body* body1 = *(it);
  disObjs.push_back(body1);
 }
 //曲线
 CurveCollection * cc= workPart->Curves();
 for (CurveCollection::iterator it = cc->begin(); it != cc->end(); it++) {
  Curve* item = * (it);
  disObjs.push_back(item);
 }
 //样条
 SplineCollection * sc= workPart->Splines();
 for (SplineCollection::iterator it = sc->begin(); it != sc->end(); it++) {
  Spline* item = *(it);
  disObjs.push_back(item);
 }
 //注解
 Annotations::NoteCollection * nc= workPart->Notes();
 for (Annotations::NoteCollection::iterator it = nc->begin(); it != nc->end(); it++) {
  Annotations::Note* item =(Annotations::Note*)*(it);
  disObjs.push_back(item);
 }
 
 theSession->DisplayManager()->BlankObjects(disObjs);
 workPart->Views()->WorkView()->FitAfterShowOrHide(View::ShowOrHideTypeHideOnly);
}
inline void JUnit::unBlankAll() {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 std::vector<NXOpen::DisplayableObject*> disObjs;
 //点
 PointCollection* pointColl = workPart->Points();
 for (PointCollection::iterator it = pointColl->begin(); it != pointColl->end(); it++) {
  Point* item = *(it);
  disObjs.push_back(item);
 }
 //尺寸
 Annotations::DimensionCollection* dimC = workPart->Dimensions();
 for (Annotations::DimensionCollection::iterator it = dimC->begin(); it != dimC->end(); it++) {
  Annotations::Dimension* item = *(it);
  disObjs.push_back(item);
 }  //剖面线
 Annotations::HatchCollection* hatchColl = workPart->Annotations()->Hatches();
 for (Annotations::HatchCollection::iterator it = hatchColl->begin(); it != hatchColl->end(); it++) {
  Annotations::Hatch* item = *(it);
  disObjs.push_back(item);
 }
 //标签
 Annotations::LabelCollection* labC = workPart->Labels();
 for (Annotations::LabelCollection::iterator it = labC->begin(); it != labC->end(); it++) {
  Annotations::Label* item = *(it);
  disObjs.push_back(item);
 }
 //符号标注
 Annotations::IdSymbolCollection* idSc = workPart->Annotations()->IdSymbols();
 for (Annotations::IdSymbolCollection::iterator it = idSc->begin(); it != idSc->end(); it++) {
  Annotations::IdSymbol* item = *(it);
  disObjs.push_back(item);
 }
 //线
 LineCollection* lc = workPart->Lines();  for (LineCollection::iterator it = lc->begin(); it != lc->end(); it++) {
  Line* line1 = *(it);
  disObjs.push_back(line1);
 }
 //体
 BodyCollection* bc = workPart->Bodies();  for (BodyCollection::iterator it = bc->begin(); it != bc->end(); it++) {
  Body* body1 = *(it);
  disObjs.push_back(body1);
 }
 //曲线
 CurveCollection* cc = workPart->Curves();
 for (CurveCollection::iterator it = cc->begin(); it != cc->end(); it++) {
  Curve* item = *(it);
  disObjs.push_back(item);
 }
 //样条
 SplineCollection* sc = workPart->Splines();
 for (SplineCollection::iterator it = sc->begin(); it != sc->end(); it++) {
  Spline* item = *(it);
  disObjs.push_back(item);
 }
 //注解
 Annotations::NoteCollection* nc = workPart->Notes();
 for (Annotations::NoteCollection::iterator it = nc->begin(); it != nc->end(); it++) {
  Annotations::Note* item = (Annotations::Note*) * (it);
  disObjs.push_back(item);
 }  theSession->DisplayManager()->UnblankObjects(disObjs);
 workPart->Views()->WorkView()->FitAfterShowOrHide(View::ShowOrHideTypeShowOnly);
}
/*打开图纸*/
inline void JUnit::openDrawSheet(NXOpen::NXString sheetName) {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 Part* displayPart(theSession->Parts()->Display());
 Drawings::DrawingSheet* drawingSheet1(dynamic_cast<Drawings::DrawingSheet*>(workPart->DrawingSheets()->FindObject(sheetName)));
 drawingSheet1->Open();  Session::UndoMarkId markId1;
 markId1 = theSession->SetUndoMark(Session::MarkVisibilityVisible, "Enter Drafting");  workPart->Views()->WorkView()->UpdateCustomSymbols();  workPart->Drafting()->SetTemplateInstantiationIsComplete(true); }
/*切换到建模模块*/
inline void JUnit::switchToModeling() {
 int button_id = 0, module_id = 0;
 HWND ugHwnd = NULL; UF_ask_application_module(&module_id);
 //if (module_id != UF_APP_MODELING) {
  ugHwnd = (HWND)UF_UI_get_default_parent();
  UF_CALL(UF_MB_ask_button_id("UG_APP_MODELING", &button_id));
  if (button_id != 0)
  {
   ::PostMessage(ugHwnd, WM_COMMAND, button_id, 0);
  }
 //} }
/*切换到制图模块*/
inline void JUnit::switchToDrawing() {
 try
 {   int button_id = 0, module_id = 0;
  HWND ugHwnd = NULL; UF_ask_application_module(&module_id);
  if (module_id != UF_APP_DRAFTING)
  {
   TTool::testMsg("do");
   ugHwnd = (HWND)UF_UI_get_default_parent();
   UF_CALL(UF_MB_ask_button_id("UG_APP_DRAFTING", &button_id));
   if (button_id != 0)
   {
    ::PostMessage(ugHwnd, WM_COMMAND, button_id, 0);    }
  } 
 }
 catch (const std::exception& ex)
 {
  TTool::testMsg(ex.what());
 } 
}
/*获取当前显示部件的名称*/
inline NXOpen::NXString JUnit::getCurrentDisplayPartName() {
 char partName[MAX_FSPEC_SIZE + 1];
 UF_PART_ask_part_name(UF_ASSEM_ask_work_part(), partName);
 char fileName1[256] = "";
 UF_CALL(uc4574(partName,2, fileName1));
 int i = 0;
 string str(fileName1);
 std::replace(str.begin(), str.end(), '&', '_');
 std::replace_if(str.begin(), str.end(), ::isspace, '_');
 return str.c_str();
}
inline std::vector<Point3d> JUnit::getPoints(tag_t bodyTag) {
 std::vector<Point3d> pointsList;
 if (bodyTag) {
  
  int uv = 3;
  double step = 1.0 / (uv + 1);
  uf_list_p_t faceList = NULL;
  UF_MODL_ask_body_faces(bodyTag,&faceList);
  int count=0;
  UF_MODL_ask_list_count(faceList,&count);
  TTool::testMsg(count);
  for (int i = 0; i < count;i++) {
   tag_t faceTag = NULL_TAG;
   UF_MODL_ask_list_item(faceList,i,&faceTag);    double uvPair[2] = {0.0,1.0};
   double uvBox[4] = { 0.0,1.0, 0.0,1.0 };
   UF_EVALSF_p_t evaluator = NULL;
   UF_EVALSF_initialize(faceTag,&evaluator);
   UF_EVALSF_ask_face_uv_minmax(evaluator, uvBox);
   for (int j = 1; j < uv + 1;j++) {
    
    uvPair[0] = uvBox[0] + j * step * (uvBox[1] - uvBox[0]);
    for (int k = 1; k < uv + 1;k++) {
     uvPair[1] = uvBox[2] + k * step * (uvBox[3] - uvBox[2]);
     UF_MODL_SRF_VALUE_t eval = { 0 };
     UF_EVALSF_evaluate(evaluator,UF_MODL_EVAL,uvPair,&eval);
     
     pointsList.push_back(Point3d(eval.srf_pos[0], eval.srf_pos[1], eval.srf_pos[2]));
    }
   }
   UF_EVALSF_free(&evaluator);
  }
 }
 return pointsList; }
inline Point3d JUnit::getMassCenter(std::vector<Point3d> pointList) {
 Point3d massCenter(0,0,0);
 
 for (int i = 0; i < pointList.size(); i++) {
  massCenter.X += pointList[i].X;
  massCenter.Y += pointList[i].Y;
  massCenter.Z += pointList[i].Z;
 }
 massCenter.X /= pointList.size();
 massCenter.Y /= pointList.size();
 massCenter.Z /= pointList.size();
 TTool::testMsg(massCenter.X);
 TTool::testMsg(massCenter.Y);
 TTool::testMsg(massCenter.Z);
 return massCenter;
}
//移动对象
inline  void JUnit::moveObj(Body* body1, Vector3d vector1, double distance, bool isCopy ) {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 Part* displayPart(theSession->Parts()->Display());
 Features::MoveObject* nullFeatures_MoveObject(NULL);  Features::MoveObjectBuilder* moveObjectBuilder1;
 moveObjectBuilder1 = workPart->BaseFeatures()->CreateMoveObjectBuilder(nullFeatures_MoveObject);  moveObjectBuilder1->TransformMotion()->DistanceAngle()->OrientXpress()->SetAxisOption(GeometricUtilities::OrientXpressBuilder::AxisPassive);  moveObjectBuilder1->TransformMotion()->DistanceAngle()->OrientXpress()->SetPlaneOption(GeometricUtilities::OrientXpressBuilder::PlanePassive);  moveObjectBuilder1->TransformMotion()->AlongCurveAngle()->AlongCurve()->SetPercentUsed(true);  moveObjectBuilder1->TransformMotion()->OrientXpress()->SetAxisOption(GeometricUtilities::OrientXpressBuilder::AxisPassive);  moveObjectBuilder1->TransformMotion()->OrientXpress()->SetPlaneOption(GeometricUtilities::OrientXpressBuilder::PlanePassive);  Point3d manipulatororigin1;
 manipulatororigin1 = moveObjectBuilder1->TransformMotion()->ManipulatorOrigin();  Matrix3x3 manipulatormatrix1;
 manipulatormatrix1 = moveObjectBuilder1->TransformMotion()->ManipulatorMatrix(); 
 moveObjectBuilder1->TransformMotion()->SetOption(GeometricUtilities::ModlMotion::OptionsDynamic); 
 moveObjectBuilder1->TransformMotion()->SetDeltaEnum(GeometricUtilities::ModlMotion::DeltaReferenceWcsWorkPart); 
 if (isCopy) {
  moveObjectBuilder1->SetMoveObjectResult(Features::MoveObjectBuilder::MoveObjectResultOptionsCopyOriginal);
 }
 else {
  moveObjectBuilder1->SetMoveObjectResult(Features::MoveObjectBuilder::MoveObjectResultOptionsMoveOriginal);
 }  bool added1;
 added1 = moveObjectBuilder1->ObjectToMoveObject()->Add(body1);  Point3d manipulatororigin2;
 manipulatororigin2 = moveObjectBuilder1->TransformMotion()->ManipulatorOrigin();  Matrix3x3 manipulatormatrix2;
 manipulatormatrix2 = moveObjectBuilder1->TransformMotion()->ManipulatorMatrix();  moveObjectBuilder1->TransformMotion()->SetOption(GeometricUtilities::ModlMotion::OptionsDistance);  //Vector3d vector1(0.0, 0.0, 1.0);
 Direction* direction1;
 direction1 = workPart->Directions()->CreateDirection(Point3d(0.0, 0.0, 0.0), vector1, SmartObject::UpdateOptionWithinModeling);  moveObjectBuilder1->TransformMotion()->SetDistanceVector(direction1);  Point3d origin2(0.0, 0.0, 0.0);
 direction1->SetOrigin(origin2);  moveObjectBuilder1->TransformMotion()->DistanceValue()->SetValue(distance); 
 NXObject* nXObject1;
 nXObject1 = moveObjectBuilder1->Commit();  moveObjectBuilder1->Destroy(); } inline std::vector<tag_t> JUnit::getSolidBodies() {
 NXOpen::Part* workPart = Session::GetSession()->Parts()->Work();
 NXOpen::BodyCollection * bodies= workPart->Bodies();
 std::vector<tag_t> list;
 UF_OBJ_disp_props_t dispProps;
 for (auto it = bodies->begin(); it != bodies->end();it++) {
  Body* body = (*it);
  int type = -1;
  int subType = -1;
  UF_CALL(UF_OBJ_ask_type_and_subtype(body->Tag(), &type, &subType));
  if (type==70&& subType==0) {
   //排除片体
   int bodytype = UF_MODL_SOLID_BODY;
   UF_MODL_ask_body_type(body->Tag(), &bodytype);
   if (bodytype == UF_MODL_SHEET_BODY) continue;
   
   UF_CALL(UF_OBJ_ask_display_properties(body->Tag(), &dispProps));
   if (dispProps.layer > 256 || dispProps.layer < 1)continue;
   int layer = dispProps.layer;
   list.push_back(body->Tag());
  }
 }
 return list;
}
/*获取对象的型心*/
inline Point3d JUnit::getObjCenter(tag_t solidTag) {
 double bdBox[6] = {0};
 UF_CALL(UF_MODL_ask_bounding_box(solidTag, bdBox));
 TTool::testMsg(bdBox,6);
 return Point3d((bdBox[0]+ bdBox[3])/2.0, (bdBox[1] + bdBox[4]) / 2.0, (bdBox[2] + bdBox[5]) / 2.0);
}
/*获取数字区间,例: 1-10,以“-”符号分隔*/
inline std::vector<int> JUnit::getNumbers(NXOpen::NXString str,NXOpen::NXString sign) {
 string tempStr(str.GetLocaleText());
 string sign1(sign.GetLocaleText());
 std::vector<int> tempV;
 if (tempStr.find(sign1)!=std::string::npos) {
  int i = -1;
  int size1 = 0;
  std::vector<int> numbers=JUnit::splitStrToIntArr(str, sign);
  if (numbers.size() != 2) {
   TTool::testUC("exception in JUnit::getNumbers:numbers.size() != 2");
   return tempV;
  }
  i = numbers[0];
  size1 = numbers[1];
  if (i >= 0 && size1 >=i) {
   for (i; i <= size1; i++) {
    tempV.push_back(i);
   }
  }
 }
 else if(JUnit::isNumber(tempStr)){
  tempV.push_back(JUnit::toInt(tempStr));
 }
 
 return tempV;
 
}
inline void JUnit::showLead(int count, int number) {
 char info[256];
 sprintf(info, "当前进度:%d/%d", number, count);
 UF_CALL(UF_UI_set_prompt(info)); }
inline NXString JUnit::splitFileName(NXString str) {
 
 std::string tempStr = string(str.GetLocaleText());
 if (tempStr.find("\\")!=std::string::npos) {
  tempStr = tempStr.substr(tempStr.find_last_of("\\")+1);
 }
 
 if (tempStr.find(".") != std::string::npos) {
  tempStr = tempStr.substr(0,tempStr.find_last_of("."));
 }
 return tempStr;
}
//
inline string JUnit::replaceStr1(NXOpen::NXString sourceStr, NXOpen::NXString substr, NXOpen::NXString replaceStr) {
 std::string str1 = string(sourceStr.GetLocaleText());
 std::string str2 = string(substr.GetLocaleText());
 std::string str3 = string(replaceStr.GetLocaleText());
 string result=str1.replace(str1.find(str2),str2.size(),str3);
 
 return result;
}
//判断是否是事例
inline bool JUnit::isOcc(tag_t objTag) {
 return UF_ASSEM_is_occurrence(objTag);
}
//获取事例信息
inline NXString JUnit::getOccInfo(tag_t occTag,bool isPartOcc) {
 NXOpen::NXString info= "未知";
 char part_name[MAX_FSPEC_SIZE + 1];
 char refset_name[MAX_ENTITY_NAME_SIZE + 1];
 char instance_name[UF_CFI_MAX_FILE_NAME_SIZE]="";
 double origin[3];
 double csys_matrix[9];
 double transform[4][4];  tag_t partOcc = occTag;
 if(!isPartOcc) partOcc = UF_ASSEM_ask_part_occurrence(occTag);
 if (partOcc)
 {
  
  UF_CALL(UF_ASSEM_ask_component_data(partOcc, part_name, refset_name, instance_name, origin, csys_matrix, transform));
  info= JUnit::splitFileName(part_name);
 }
 
 return info;
}
//特征类型
inline NXString JUnit::getFeatureType(tag_t featTag) {  NXOpen::NXString str = "";
 NXOpen::NXString type = "未知";
 int timeStamp = -1;
 int time = 0;
 if (!featTag)return str;
 NXOpen::Features::Feature* feature1 = dynamic_cast<NXOpen::Features::Feature*>(NXOpen::NXObjectManager::Get(featTag));
 type = feature1->FeatureType();
 time=feature1->Timestamp();
 //UF_MODL_ask_time_stamp_of_feature(featTag,&timeStamp);
 char c[256];
 sprintf(c,"%s(%d)",type.GetLocaleText(),time);
 str = c;
 if (strstr(c, "BREP")) {
  str = JUnit::replaceStr1(c,"BREP","body");
 }
 return str;
}
//对象信息
inline  void JUnit::getType(tag_t objTag) {
 int type = 0;
 int subtype = 0;
 UF_OBJ_ask_type_and_subtype(objTag,&type,&subtype);
 TTool::testMsgL("type-");
 TTool::testMsgL(type);
 TTool::testMsgL("-subType-");
 TTool::testMsg(subtype);
}
inline  NXOpen::NXString JUnit::getObjType(tag_t objTag) {
 
 NXOpen::NXString info = "";
 NXOpen::NXString occ;
 NXOpen::NXString featType ;
 
 try
 {
   occ = "";
   featType = "";
   int type = -1;
   int subType = -1;
   UF_CALL(UF_OBJ_ask_type_and_subtype(objTag, &type, &subType));
   /*TTool::testMsgL("type");
   TTool::testMsg(type);
   TTool::testMsgL("subType");
   TTool::testMsg(subType);*/    if (type == UF_feature_type) {//特征
    featType = JUnit::getFeatureType(objTag);
    
   }
   else if (type == 63 && subType == 1) {
    occ = JUnit::getOccInfo(objTag, true);
    
   }
   else if (type == 70 && subType == 0) 
   {
    featType = "体";     if (isOcc(objTag)) {//事例
     occ = JUnit::getOccInfo(objTag);
     
    } 
    uf_list_p_t featList;
    UF_CALL(UF_MODL_ask_body_feats(objTag, &featList));
    int count = 0;
    UF_CALL(UF_MODL_ask_list_count(featList, &count));
    tag_t featTag = NULL;
    if (count) {
     UF_CALL(UF_MODL_ask_list_item(featList, 0, &featTag));
     featType = JUnit::getFeatureType(featTag);
     
     UF_MODL_delete_list(&featList);
    }
    
    if (strstr(featType.GetLocaleText(),"body")) {
     
     int bodyType = -1;
     UF_MODL_ask_body_type(objTag, &bodyType);
     if (bodyType == UF_MODL_SOLID_BODY) {
      
      featType=JUnit::replaceStr1(featType, "body","实体");
     }else if (bodyType == UF_MODL_SHEET_BODY) {
      
      featType=JUnit::replaceStr1(featType, "body","片体");
     }
    }
        }else if(type== UF_datum_axis_type|| type == UF_datum_plane_type || type == UF_sketch_type 
     ||type == UF_line_type || type == UF_circle_type || type == UF_conic_type|| type == UF_spline_type) {
    
    tag_t featTag = NULL_TAG;
    UF_CALL(UF_MODL_ask_object_feat(objTag, &featTag));
    featType = JUnit::getFeatureType(featTag);
    
   }else {
    
    char c[256];
    sprintf(c,"tag:%d-type:%d-subtype:%d", (int)objTag,type,subType);
   
    featType =NXString(c);
   }    if (string(occ.GetLocaleText()).size() > 0 && string(featType.GetLocaleText()).size() >0) {
    occ = "/" + occ;
   }
   info = featType + occ;
   
   return info;
 }
 catch (const std::exception& exc)
 {
  TTool::testMsg(exc.what());
  
 }
 
 return info;
}
inline tag_t JUnit::singleSelectionUI() {
 int response = UF_UI_CANCEL;
 tag_t selObjTag = NULL_TAG;
 tag_t view = NULL_TAG;
 double cursor[3];
 UF_UI_select_with_single_dialog("选择对象", "选择对象", UF_UI_SEL_SCOPE_ANY_IN_ASSEMBLY, NULL, NULL, &response, &selObjTag, cursor, &view);
 if(response== UF_UI_CANCEL) selObjTag = NULL_TAG;
 return selObjTag;
}
//NX对象选择器
inline std::vector<TaggedObject*> JUnit::getSeleObjectUI() {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 UI* theUI = UI::GetUI();
 Selection::Response resp;
 
 std::vector<TaggedObject*> objList;
 //TaggedObject* object;
 //Point3d cursor;
 //resp = theUI->SelectionManager()->SelectTaggedObjects("请选择一个对象","选择",Selection::SelectionScopeUseDefault,true,false,&object,&cursor);
 resp = theUI->SelectionManager()->SelectTaggedObjects("请选择对象", "选择对象", Selection::SelectionScopeAnyInAssembly, true, false, objList);
 if (resp == Selection::ResponseCancel) {
  objList.clear();
  
 }
 return objList;
}
//JUnit工具实现
inline int JUnit::report_error(char* file, int line, char* call, int irc) {
 if (irc)
 {
  char err[133],
   msg[133];   sprintf_s(msg, 132, "*** ERROR code %d at line %d in %s:\n+++ ",
   irc, line, file);
  UF_get_fail_message(irc, err);   UF_print_syslog(msg, FALSE);
  UF_print_syslog(err, FALSE);
  UF_print_syslog("\n", FALSE);
  UF_print_syslog(call, FALSE);
  UF_print_syslog(";\n", FALSE);   if (!UF_UI_open_listing_window())
  {
   UF_UI_write_listing_window(msg);
   UF_UI_write_listing_window(err);
   UF_UI_write_listing_window("\n");
   UF_UI_write_listing_window(call);
   UF_UI_write_listing_window(";\n");
  }
 }  return(irc);
}; 
//转成tag_t类型的列表
inline std::vector<tag_t> JUnit::toTagList(std::vector<TaggedObject*> list) {
 std::vector<tag_t> tempList;
 for (int i = 0; i < list.size(); i++) {
  tempList.push_back(list[i]->Tag());
 }
 return tempList;
}
//改变视图风格-线框or正常
inline void JUnit::changeViewStyle(int n) {
 Session* theSession = Session::GetSession();
 Part* workPart(theSession->Parts()->Work());
 if (n) {
  workPart->ModelingViews()->WorkView()->SetRenderingStyle(View::RenderingStyleTypeShadedWithEdges);
 }
 else {   workPart->ModelingViews()->WorkView()->SetRenderingStyle(View::RenderingStyleTypeStaticWireframe);
 } }
inline void JUnit::addObjToSelList(tag_t* objs)
{
 typedef UF_UI_selection_p_t(*load_ufusr_f_p_t)(void);//定义传参
 load_ufusr_f_p_t SEL_ask_persistent_context = NULL;  UF_load_library("D:\\myProgram\\Siemens\\UGII\\libugui.dll", "?SEL_ask_persistent_context@@YAPEAUUGUI_selection_s@@XZ", (UF_load_f_p_t*)& SEL_ask_persistent_context);  if (SEL_ask_persistent_context != NULL) {
  UF_UI_selection_p_t select = SEL_ask_persistent_context();
  int num = sizeof(objs) / sizeof(objs[0]);   UF_UI_add_to_sel_list(select, num, objs, true);  } 
}
//获取ug选择器中的所有对象
inline std::vector<tag_t> JUnit::getSelObjList2() {
 std::vector<tag_t> tempList;
 int count = 0;
 tag_p_t objs=NULL;
 UF_CALL(UF_UI_ask_global_sel_object_list(&count,&objs));
 /*TTool::testMsgL("count:");
 TTool::testMsg(count);*/
 for (int i = 0; i < count; i++) {   tempList.push_back(objs[i]);
  /*TTool::testMsgL("tag:");
  TTool::testMsg((int)objs[i]);*/
 }
 return tempList;
}
//获取ug选择器中的所有对象
inline std::vector<tag_t> JUnit::getSelObjList()
{
 std::vector<tag_t> tempList;
 typedef UF_UI_selection_p_t(*load_ufusr_f_p_t)(void);//定义传参
 load_ufusr_f_p_t SEL_ask_persistent_context = NULL;  UF_load_library("D:\\myProgram\\Siemens\\UGII\\libugui.dll", "?SEL_ask_persistent_context@@YAPEAUUGUI_selection_s@@XZ", (UF_load_f_p_t*)& SEL_ask_persistent_context);  if (SEL_ask_persistent_context != NULL) {
  UF_UI_selection_p_t select = SEL_ask_persistent_context();
  int count = 0;
  //UF_UI_ask_sel_list_count(select,&count);
  tag_p_t objTags;   UF_UI_ask_sel_object_list(select, &count, &objTags);   for (int i = 0; i < count; i++) {    tempList.push_back(objTags[i]);
  }
 }
 return tempList;
} 
#include<NXOpen/LogFile.hxx>
inline void JUnit::writeLog(NXOpen::NXString str1, int* d, int size) {
 std::stringstream ss;
 ss << JUnit::getDate() << " : " << str1.GetLocaleText() << "::";
 for (int i = 0; i < size; i++) {
  ss << d[i] << ",";
 }
 Session::GetSession()->LogFile()->WriteLine(ss.str());
}
inline void JUnit::writeLog(NXOpen::NXString str1, double * d,int size) {
 std::stringstream ss;
 ss << JUnit::getDate() << " : " << str1.GetLocaleText() << "::";
 for (int i = 0; i < size;i++) {
  ss << d[i] << ",";
 }
 Session::GetSession()->LogFile()->WriteLine(ss.str());
}
inline void JUnit::writeLog(NXOpen::NXString str1, double d) {
 std::stringstream ss;
 ss << JUnit::getDate() << " : " << str1.GetLocaleText() << "::" << d;
 Session::GetSession()->LogFile()->WriteLine(ss.str());
}
inline void JUnit::writeLog(NXOpen::NXString str1, size_t n) {
 JUnit::writeLog(str1,(int)n);
}
inline void JUnit::writeLog(NXOpen::NXString str1, int n) {
 std::stringstream ss;
 ss << JUnit::getDate() << " : " << str1.GetLocaleText() << "::" << n;
 Session::GetSession()->LogFile()->WriteLine(ss.str());
}
inline void JUnit::writeLog(NXOpen::NXString str1, NXOpen::NXString str2){
 std::stringstream ss;
 ss << JUnit::getDate() << " : " << str1.GetLocaleText()<<","<< str2.GetLocaleText();
 Session::GetSession()->LogFile()->WriteLine(ss.str());
}
inline void JUnit::writeLog(NXOpen::NXString str) {
 std::stringstream ss;
 ss << JUnit::getDate() << " : " << str.GetLocaleText();
 Session::GetSession()->LogFile()->WriteLine(ss.str());
}
inline void JUnit::myMessageBox(std::string str) {
 MessageBox(NULL, JUnit::s2cs(str), TEXT("提示!!!"), MB_OK);
}
inline void JUnit::myMessageBox(std::string str,std::string str2) {
 ostringstream oss;
 oss << str << ":" << str2;
 MessageBox(NULL, JUnit::s2cs(oss.str() ), TEXT("提示!!!"), MB_OK);
} inline std::string JUnit::toString(int n) {
 stringstream ss;
 ss << n;
 return ss.str();
}
inline std::string JUnit::toString(double n) {
 char c[133];
 sprintf(c, "%.02f", n);
 return std::string(c);
}
inline std::vector<NXOpen::NXString> JUnit::toStrList(std::vector<int> list) {
 std::vector<NXOpen::NXString> tempV;
 for (int i = 0; i < list.size(); i++) {
  char c[256];
  sprintf(c, "%d", list[i]);
  tempV.push_back(NXOpen::NXString(c));
 }
 if (tempV.empty()) TTool::testMsg("exception int method: std::vector<NXOpen::NXString> toStrList,tempV.empty()");
 return tempV;
}
inline double JUnit::toF(NXOpen::NXString str) {
 std::string temp = str.GetLocaleText();
 if (temp.find_first_of(".") != std::string::npos) {
  if (temp.find_first_of(".") != temp.find_last_of(".")) {
   uc1601(const_cast<char*>(NXString(str + ":不是纯数字").GetLocaleText()), 1);
   return 0;
  }
 }
 if (temp.find_first_of("-") != std::string::npos) {
  if (temp.front()!= '-') {
   uc1601(const_cast<char*>(NXString(str + ":不是纯数字").GetLocaleText()), 1);
   return 0;
  }
 }
 for (int i = 0; i < temp.size(); i++) {
  if (!(temp[i] >= '0' && temp[i] <= '9' || temp[i] == '.'|| temp[i] == '-')) {
   uc1601(const_cast<char*>(NXString(str + ":不是纯数字").GetLocaleText()), 1);
   return 0;
  }
 }
 return atof(str.GetLocaleText());
}
inline int JUnit::toInt(NXOpen::NXString str) {
 std::string temp = str.GetLocaleText();
 if (temp.find_first_of(".") != std::string::npos) {
  if (temp.find_first_of(".") != temp.find_last_of(".")) {
   uc1601(const_cast<char*>(NXString(str + ":不是纯数字").GetLocaleText()), 1);
   return 0;
  }
 }
 if (temp.find_first_of("-") != std::string::npos) {
  if (temp.front() != '-') {
   uc1601(const_cast<char*>(NXString(str + ":不是纯数字").GetLocaleText()), 1);
   return 0;
  }
 }
 for (int i = 0; i < temp.size(); i++) {
  if (!(temp[i] >= '0' && temp[i] <= '9' || temp[i] == '.' || temp[i] == '-')) {
   uc1601(const_cast<char*>(NXString(str + ":不是纯数字").GetLocaleText()), 1);
   return 0;
  }
 }
 return atoi(str.GetLocaleText());
}
inline bool JUnit::isNumber(NXOpen::NXString str1) {
 std::string str(str1.GetLocaleText());
 if (str.size() < 1)return false;
 size_t index1 = str.find_first_of(".");
 size_t index2 = str.find_last_of(".");
 if (index1 != std::string::npos) {
  if (!(index1 == index2 && (index1 != 0 || index1 != str.size() - 1))) {
   return false;
  }
 }
 size_t index3 = str.find_first_of("-");
 size_t index4 = str.find_last_of("-");
 if (index3 != std::string::npos) {
  if (!(index3 == index4 && index3==0)) {
   return false;
  }
 }
 for (int i = 0; i < str.size(); i++) {
  if (!(str[i] >= '0' && str[i] <= '9' || str[i] == '.'|| str[i]=='-')) {
   return false;
  }
 }
 return true;
}
inline bool JUnit::isEditableExp(NXOpen::NXString paramName) {
 if (strcmp(paramName.GetLocaleText(), "压条长") == 0) return true;
 else if (strcmp(paramName.GetLocaleText(), "压条长") == 0) return true;
 else if (strcmp(paramName.GetLocaleText(), "压条高") == 0) return true;
 else if (strcmp(paramName.GetLocaleText(), "Z") == 0) return true;
 else if (strcmp(paramName.GetLocaleText(), "Y") == 0) return true;
 else if (strcmp(paramName.GetLocaleText(), "Z") == 0) return true;
 else if (strcmp(paramName.GetLocaleText(), "宽") == 0) return true;
 else if (strcmp(paramName.GetLocaleText(), "挂台高") == 0) return true;
 else if (strcmp(paramName.GetLocaleText(), "长") == 0) return true;
 else return false;
}
//xml中文乱码处理 
inline NXString JUnit::Utf8ToGB2312(const char* utf8)
{
 int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);  wchar_t* wstr = new wchar_t[len + 1];
 memset(wstr, 0, len + 1);  MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
 len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);  char* str = new char[len + 1];
 memset(str, 0, len + 1);  WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
 NXString nstr = str;
 if (wstr) { delete  wstr; }
 if (str) { delete  str; }
 return nstr;
}
inline NXString JUnit::trimEmpty(const char* strs)
{
 if (!strs) return "null";  char tempStr[400]; memset(tempStr, '\0', 399);
 int n = 0;
 for (size_t i = 0; strs[i] != '\0'; i++)
 {
  if (n > 0 && strs[i] == ' ')break;
  if (strs[i] != ' ' && strs[i] != '\n')
  {
   tempStr[n] = strs[i]; n++;
  }
 }
 return Utf8ToGB2312(tempStr);
}
//分割字符1
inline std::vector<NXOpen::NXString> JUnit::splitStr(NXOpen::NXString str, NXOpen::NXString c) {
 //存放起始值和终止值
 std::vector<NXOpen::NXString> numberStrV;  //^两边数据代表起始值和末值
 char* pt = strtok(const_cast<char*>(str.GetLocaleText()), c.GetLocaleText());
 while (pt) {
  //TestUnit::outMsg(pt);
  numberStrV.push_back(pt);
  pt = strtok(NULL, c.GetLocaleText());
 }
 return numberStrV;
}
inline std::vector<std::string> JUnit::splitStr1(NXOpen::NXString str, NXOpen::NXString c) {
 //存放起始值和终止值
 std::vector<std::string> numberStrV;  //^两边数据代表起始值和末值
 char* pt = strtok(const_cast<char*>(str.GetLocaleText()), c.GetLocaleText());
 while (pt) {
  //TestUnit::outMsg(pt);
  numberStrV.push_back(pt);
  pt = strtok(NULL, c.GetLocaleText());
 }
 return numberStrV;
}
inline std::vector<int> JUnit::splitStrToIntArr(NXOpen::NXString str, NXOpen::NXString sign) {
 
 //存放起始值和终止值
 std::vector<int> numberStrV;
 if (string(str.GetLocaleText()).size() < 1)return numberStrV;
 //^两边数据代表起始值和末值
 char* pt = strtok(const_cast<char*>(str.GetLocaleText()), sign.GetLocaleText());
 while (pt) {
  //TestUnit::outMsg(pt);   if (isNumber(pt)) {
   numberStrV.push_back(atoi(pt));
  }
  else {
   TTool::testMsg("-非数字", str);
  }   pt = strtok(NULL, sign.GetLocaleText());
 }
 return numberStrV; }
//分割字符
inline std::vector<double> JUnit::splitStrToDoubleArr(NXOpen::NXString str, NXOpen::NXString sign){
 //存放起始值和终止值
 std::vector<double> numberStrV;  //^两边数据代表起始值和末值
 char* pt = strtok(const_cast<char*>(str.GetLocaleText()), sign.GetLocaleText());
 while (pt) {
  //TestUnit::outMsg(pt);
  
  if (isNumber(pt)) {
   numberStrV.push_back(JUnit::round(stod(pt), 2));
  }
  else {
   TTool::testMsg("-非数字", str);
  }   pt = strtok(NULL, sign.GetLocaleText());
 }
 return numberStrV;
}
//获取dll执行文件所在地址
inline NXOpen::NXString JUnit::getDllAddress() {
 //WCHAR temp[256];
 char temp[256];
 GetModuleFileName(_AtlBaseModule.GetModuleInstance(), temp, 256);
 //wstring ws(temp);  string strDllPath(temp);  return strDllPath.substr(0, strDllPath.find_last_of("\\") + 1);
}
//获取dll执行文件所在地址
inline std::string JUnit::getDllAddress1(NXOpen::NXString dlxFileName) {
 //WCHAR temp[256];
 char temp[256];
 GetModuleFileName(_AtlBaseModule.GetModuleInstance(), temp, 256);
 //wstring ws(temp);  //string strDllPath(ws.begin(), ws.end());
 string strDllPath(temp);
 strDllPath = strDllPath.substr(0, strDllPath.find_last_of("\\") + 1);
 char str[256];
 sprintf(str, "\"%s%s\"", strDllPath.c_str(), dlxFileName.GetLocaleText());
 //TTool::testUC(str);
 return std::string(str);;
}
//获取dll执行文件所在地址 
inline NXOpen::NXString JUnit::getDllAddress(NXOpen::NXString dlxFileName) {
 //WCHAR temp[256];
 char temp[256];
 GetModuleFileNameA(_AtlBaseModule.GetModuleInstance(), temp, 256);
 //wstring ws(temp);
 string strDllPath(temp);
 strDllPath=strDllPath.substr(0, strDllPath.find_last_of("\\") + 1);
 char str[256];
 sprintf(str,"%s%s", strDllPath.c_str(), dlxFileName.GetLocaleText());
 //TTool::testUC(str);
 return NXOpen::NXString(str);;
}
//读环境变量
inline NXOpen::NXString JUnit::getEnvironmentVar(NXString fileName) {
 char  std_path[250]; //gstd_path
 size_t nsize; getenv_s(&nsize, NULL, 0, "VT_Application_DIR");
 if (nsize > 0)
 {
  char* usename = (char*)malloc(sizeof(char) * nsize);
  if (usename != NULL)
  {
   getenv_s(&nsize, usename, nsize, "VT_Application_DIR");    if (strlen(usename) > 3)
   {
    sprintf_s(std_path, 256, "%s\\%s", usename, fileName.GetLocaleText());
   }
   free(usename);
  }
 }  return NXString(std_path);
}
inline std::string JUnit::getEnvironmentVal1(std::string paramName, std::string fileName) {
 char  std_path[250]=""; //gstd_path
 size_t nsize; getenv_s(&nsize, NULL, 0, paramName.c_str());
 if (nsize > 0)
 {
  char* usename = (char*)malloc(sizeof(char) * nsize);
  if (usename != NULL)
  {
   getenv_s(&nsize, usename, nsize, paramName.c_str());    if (strlen(usename) > 3)
   {
    sprintf_s(std_path, 256, "%s\\%s", usename, fileName);
   }
   free(usename);
  }
 }  return string(std_path);
}
//CString 转 NXString
inline NXOpen::NXString JUnit::cStrToNXString(CString tchar)
{
 char tempstr[4224];
 /*int iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
 WideCharToMultiByte(CP_ACP, 0, tchar, -1, tempstr, iLength, NULL, NULL);*/
 return tempstr;
}
//判断是否包含
template<class T>
inline bool JUnit::isContain(std::vector<T> list, T ele) {
 for (int i = 0; i < list.size(); i++) {
  if (list[i] == ele) {
   return true;
  }
 }
 return false;
};
/*钩子*/
namespace MyHook {
 
 static HHOOK hookKB = NULL;
 inline LRESULT CALLBACK hookproc(UINT nCode, WPARAM wParam, LPARAM lParam)
 {
  TTool::testMsg("hookproc");
  //if (wParam == WM_KEYUP) // 只处理WM_MOUSEMOVE消息
  //{
  // //LPMOUSEHOOKSTRUCT pMouseHook = (MOUSEHOOKSTRUCT FAR*)lParam;
  // //POINT pt = pMouseHook->pt; // 像素坐标
  // //HWND delta = WindowFromPoint(pt);
  // //HWND parent = GetParent(delta);
  // TTool::testUC("1");   //}
  char szWriteText[256];
  char szWindowTittle[256];
  char szKeyTest[256];
  HWND hWnd;
  hWnd = ::GetActiveWindow();
  if (hWnd == NULL)
  {
   hWnd = ::GetForegroundWindow();
   if (hWnd == NULL) return CallNextHookEx(hookKB, nCode, wParam, lParam);
  }
  //得到窗口的标题
  GetWindowTextA(hWnd, szWindowTittle, 256);
  TTool::testMsg(szWindowTittle);
  //得到窗口的标题
  GetWindowTextA(hWnd, szWindowTittle, 256);
  //获取在在窗口输入的按键的内容
  if (nCode < 0 || nCode == HC_NOREMOVE) return CallNextHookEx(hookKB, nCode, wParam, lParam);
  if (lParam & 0x40000000) return CallNextHookEx(hookKB, nCode, wParam, lParam);   GetKeyNameTextA(lParam, szKeyTest, 256);
  TTool::testMsg(szKeyTest);
  return CallNextHookEx(hookKB, nCode, wParam, lParam);
 }
 /*卸载钩子*/
 inline void unLoadHook() {
  TTool::testMsg("unLoadHook");
  if (hookKB != NULL)
   UnhookWindowsHookEx(hookKB); // 卸载Hook
 }
 //挂载钩子
 inline void runHook() {
  TTool::testMsg("runHook");
  unLoadHook();
  // 启动Hook
  DWORD id = GetCurrentThreadId();
  //WH_KEYBOARD ,WH_MOUSE
  hookKB = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)hookproc, NULL, id);
 }
  }; class AttrTool {
public:
 static int finAttr(tag_t objTag, const char* attrName) {
  char title[UF_ATTR_MAX_TITLE_LEN + 1];
  strcpy_s(title, attrName);
  int titleType = 0;
  UF_CALL(UF_ATTR_find_attribute(objTag, UF_ATTR_any, title, &titleType));
  return titleType;
 }
 static bool getAttrValStr(tag_t objTag, const char* attrName, std::string& attrVal) {
  if (AttrTool::finAttr(objTag, attrName) != UF_ATTR_string)return false;
  UF_ATTR_value_t val;
  char title[UF_ATTR_MAX_TITLE_LEN + 1];
  strcpy_s(title, attrName);
  val.value.string = NULL;
  UF_CALL(UF_ATTR_read_value(objTag, title, UF_ATTR_string, &val));
  attrVal = val.value.string;
  UF_free(val.value.string);
  return !attrVal.empty();
 };
 static bool getAttrValInteger(tag_t objTag, const char* attrName, int& attrVal) {
  attrVal = -1;
  if (AttrTool::finAttr(objTag, attrName) != UF_ATTR_integer)return false;
  UF_ATTR_value_t val;
  char title[UF_ATTR_MAX_TITLE_LEN + 1];
  strcpy_s(title, attrName);
  UF_CALL(UF_ATTR_read_value(objTag, title, UF_ATTR_integer, &val));
  attrVal = val.value.integer;
  return attrVal >= 0;
 };
};
#include <ShlObj.h>
class JTool {
public:  static int selectFolder() {
  TCHAR szPath[MAX_PATH];
  BROWSEINFO browseInfo = { 0 };
  browseInfo.hwndOwner = NULL;
  browseInfo.pidlRoot = NULL;
  browseInfo.pszDisplayName = szPath;
  //browseInfo.lpszTitle = "Select a folder";
  browseInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE| BIF_USENEWUI;
  LPITEMIDLIST pid1 = SHBrowseForFolder(&browseInfo);
  if (pid1 != NULL) {
   SHGetPathFromIDList(pid1, szPath);
   TTool::errorMsg("路径:", szPath);
   CoTaskMemFree(pid1);
  }
  return 0;
 }
 static int selectFolder2() {
  IFileOpenDialog* pFileOpen;   HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, __uuidof(IFileOpenDialog), reinterpret_cast<void**>(&pFileOpen));   if (SUCCEEDED(hr)) {    hr = pFileOpen->SetOptions(FOS_PICKFOLDERS);//浏览文件夹模式    if (SUCCEEDED(hr)) {     HWND hd = GetForegroundWindow();
    hr = pFileOpen->Show(hd);     if (SUCCEEDED(hr)) {      IShellItem* psiResult;      hr = pFileOpen->GetResult(&psiResult);      if (SUCCEEDED(hr))      {       PWSTR pszFilePath = NULL;       hr = psiResult->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);       //if (SUCCEEDED(hr))Edit1->Text = pszFilePath;
      TTool::errorMsg("路径", JUnit::ws2s(pszFilePath).c_str());
      psiResult->Release();      }     }    }
   pFileOpen->Release();
  }
  return 0;
 }
 // 计算两个点之间的距离
 static double m_distance(NXOpen::Point3d p1, NXOpen::Point3d p2) {
  double dx = p1.X - p2.X;
  double dy = p1.Y - p2.Y;
  double dz = p1.Z - p2.Z;
  return sqrt(dx * dx + dy * dy + dz * dz);
 }
 // 计算点P到所有点的距离之和
 static double calculateDistance(NXOpen::Point3d p, vector<NXOpen::Point3d> points) {
  double sum = 0;
  for (int i = 0; i < points.size(); ++i) {
   sum += m_distance(p, points[i]);
  }
  return sum;
 }
 // 梯度下降法，找到距离所有点距离和最小的点
 static NXOpen::Point3d findMinDistancePoint(vector<NXOpen::Point3d> points) {
  // 初始值为所有点的平均值
  NXOpen::Point3d p(0, 0, 0);
  for (int i = 0; i < points.size(); ++i) {
   p.X += points[i].X / points.size();
   p.Y += points[i].Y / points.size();
   p.Z += points[i].Z / points.size();
  }
  // 梯度下降法
  double alpha = 0.01;
  double epsilon = 0.0001;
  while (true) {
   double dx = 0;
   double dy = 0;
   double dz = 0;
   for (int i = 0; i < points.size(); ++i) {
    double d = m_distance(p, points[i]);
    dx += (p.X - points[i].X) / d;
    dy += (p.Y - points[i].Y) / d;
    dz += (p.Z - points[i].Z) / d;
   }
   double oldDistance = calculateDistance(p, points);
   p.X -= alpha * dx;
   p.Y -= alpha * dy;
   p.Z -= alpha * dz;
   double newDistance = calculateDistance(p, points);
   if (oldDistance - newDistance < epsilon) {
    break;
   }
  }
  return p;
 }
 /*获取面的中心点*/
 static NXOpen::Point3d getFaceCenterPoint(tag_t faceTag) {
  if (!faceTag)return Point3d(0, 0, 0);
  uf_list_p_t edgeList = NULL;
  uf_loop_p_t loopList = NULL;
  int count = 0;
  UF_MODL_ask_face_loops(faceTag, &loopList);   UF_MODL_ask_loop_list_count(loopList, &count);
  int loopType = 0;
  for (int i = 0; i < count; i++) {
   UF_MODL_ask_loop_list_item(loopList, i, &loopType, &edgeList);
   if (loopType == 1)break;
  }
  if (edgeList == NULL) return Point3d(0, 0, 0);
  std::vector<Point3d> pList;
  UF_MODL_ask_list_count(edgeList, &count);
  if (count < 11) {
   while (edgeList)
   {
    pList.push_back(JUnit::getEdgeMidPoint(edgeList->eid, 0));
    pList.push_back(JUnit::getEdgeMidPoint(edgeList->eid, 1.0 / 4.0));
    pList.push_back(JUnit::getEdgeMidPoint(edgeList->eid, 2.0 / 4.0));
    pList.push_back(JUnit::getEdgeMidPoint(edgeList->eid, 3.0 / 4.0));
    edgeList = edgeList->next;
   }
  }
  else {
   while (edgeList)
   {
    pList.push_back(JUnit::getEdgeMidPoint(edgeList->eid, 0.5));
    edgeList = edgeList->next;
   }
  }   UF_MODL_delete_loop_list(&loopList);   return findMinDistancePoint(pList);
 };
 /*获取面的中心点*/
 static void getFaceCenterPoint(tag_t faceTag,double center[3]) {
  if (!faceTag)return;
  uf_list_p_t edgeList = NULL;
  uf_loop_p_t loopList = NULL;
  int count = 0;
  UF_MODL_ask_face_loops(faceTag, &loopList);   UF_MODL_ask_loop_list_count(loopList, &count);
  int loopType = 0;
  for (int i = 0; i < count; i++) {
   UF_MODL_ask_loop_list_item(loopList, i, &loopType, &edgeList);
   if (loopType == 1)break;
  }
  if (edgeList == NULL) return;
  std::vector<Point3d> pList;
  UF_MODL_ask_list_count(edgeList, &count);
  if (count < 11) {
   while (edgeList)
   {
    pList.push_back(JUnit::getEdgeMidPoint(edgeList->eid, 0));
    pList.push_back(JUnit::getEdgeMidPoint(edgeList->eid, 1.0 / 4.0));
    pList.push_back(JUnit::getEdgeMidPoint(edgeList->eid, 2.0 / 4.0));
    pList.push_back(JUnit::getEdgeMidPoint(edgeList->eid, 3.0 / 4.0));
    edgeList = edgeList->next;
   }
  }
  else {
   while (edgeList)
   {
    pList.push_back(JUnit::getEdgeMidPoint(edgeList->eid, 0.5));
    edgeList = edgeList->next;
   }
  }   UF_MODL_delete_loop_list(&loopList);   Point3d p= findMinDistancePoint(pList);
  center[0] = p.X;
  center[1] = p.Y;
  center[2] = p.Z;
 };
}; class FaceTool {
public:
 /*return:1 false ,0 success*/
 static int getCylinderFaceRadiu(Face* face, double& radiu) {
  if (face->SolidFaceType() == Face::FaceTypeCylindrical) {
   Session* theSession = Session::GetSession();
   Part* workPart(theSession->Parts()->Work());
   Part* displayPart(theSession->Parts()->Display());
   Unit* unit1(dynamic_cast<Unit*>(workPart->UnitCollection()->FindObject("MilliMeter")));
   MeasureDistance* measureDistance1;
   measureDistance1 = workPart->MeasureManager()->NewDistance(unit1, face, MeasureManager::RadialMeasureTypeRadius);
   radiu = measureDistance1->Value();
   return 0;
  }
  return 1;
 }; };
#endif;  