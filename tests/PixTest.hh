#ifndef PIXTEST_H
#define PIXTEST_H

#ifdef __CINT__
#undef __GNUC__
typedef char __signed; 
typedef char int8_t; 
#endif

#include <string>
#include <map>
#include <list>

#include <TQObject.h> 
#include <TH1.h> 
#include <TH2.h> 
#include <TDirectory.h> 
#include <TFile.h>
#include <TSystem.h>

#include "api.h"

#include "PixInitFunc.hh"
#include "PixSetup.hh"
#include "PixTestParameters.hh"

class PixTest: public TQObject {
public:
  PixTest(PixSetup *a, std::string name);
  PixTest();
  virtual ~PixTest();
  void init();
  void bookHist(std::string name);
  virtual void setToolTips();
  virtual std::string getSummaryTip() {return fSummaryTip;}
  virtual std::string getTestTip() {return fTestTip;}
  virtual std::string getHistOption(TH1*);

  int pixelThreshold(std::string dac, int ntrig, int dacmin, int dacmax);
  std::vector<TH2D*> efficiencyMaps(std::string name, uint16_t ntrig = 10); 
  std::vector<TH1*> scurveMaps(std::string dac, std::string name, int ntrig = 10, int daclo = 0, int dachi = 255, int result = 3); 
  std::vector<TH1*> thrMaps(std::string dac, std::string name, int ntrig = 10);

  int histCycle(std::string hname);
  TH1D* bookTH1D(std::string sname, std::string title, int nbins, double xmin, double xmax); 
  TH2D* bookTH2D(std::string sname, std::string title, int nbinsx, double xmin, double xmax, int nbinsy, double ymin, double max); 

  //  std::vector<TH1*> mapsVsDac(std::string name, std::string dac, int ntrig = 10); 

  virtual void sparseRoc(int npix = 8);

  TH1D* distribution(TH2D *, int nbins, double xmin, double xmax, bool zeroSuppressed = false); 
  bool threshold(TH1 *); 
  int simpleThreshold(TH1 *); 
  
  void cache(std::string dacname); 
  void restore(std::string dacname); 

  TH2D* moduleMap(std::string histname); 
  void fillMap(TH2D *hmod, TH2D *hroc, int iroc); 

  void clearHistList(); 
  virtual void doTest(); 
  virtual void runCommand(std::string command); 
  virtual void doAnalysis();
  
  
  std::string getName() {return fName; }
  void resetDirectory();
  TDirectory* getDirectory() {return fDirectory;}
  std::vector<std::pair<std::string, std::string> > getParameters() {return fParameters;} 
  bool getParameter(std::string parName, int &); 
  bool getParameter(std::string parName, float &); 
  void dumpParameters(); 
  void setTitles(TH1 *h, const char *sx, const char *sy, 
		 float size = 0.05, float xoff = 1.1, float yoff = 1.1, float lsize = 0.05, int font = 42);

  virtual bool setParameter(std::string parName, std::string sval); 

  void setId2Idx(std::map<int, int> a);
  bool selectedRoc(int id);

  static std::string stripPos(std::string); 
  
  void testDone(); // *SIGNAL*
  void update();  // *SIGNAL*
  TH1* nextHist(); 
  TH1* previousHist(); 
  

protected: 
  pxar::api            *fApi;
  PixSetup             *fPixSetup; 
  PixTestParameters    *fTestParameters; 
  PixInitFunc          *fPIF;   

  double               fThreshold, fThresholdE, fSigma, fSigmaE; 

  std::string           fName, fTestTip, fSummaryTip; 

  std::vector<std::pair<std::string, std::string> > fParameters;

  std::vector<uint8_t>  fCacheVal; 
  std::string           fCacheDac;

  TDirectory            *fDirectory; 
  std::list<TH1*>       fHistList;
  std::map<TH1*, std::string> fHistOptions;
  std::list<TH1*>::iterator fDisplayedHist;  

  std::vector<std::pair<int, int> > fPIX; // range of enabled pixels for time-consuming tests
  std::map<int, int>    fId2Idx; // map the ROC ID onto the (results vector) index of the ROC

  ClassDef(PixTest, 1); // testing PixTest

};

#endif
