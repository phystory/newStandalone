/****************************************************************
 Declaration of Scaler class MainScaler
 Seven Scalers SIS3820 defined
 Jorge Pereira 10/26/2005
****************************************************************/

#ifndef __MAINSCALER_H
#define __MAINSCALER_H

#include <config.h>
#include <CScaler.h>
#include <vector>

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

class CSIS3820;

class MainScaler : public CScaler
{
private:
  CSIS3820*       m_pVMESCAL;

public:
  MainScaler(unsigned long base, int crate);     //contructor
  virtual ~MainScaler();                         //destructor
  virtual void Initialize();
  virtual void Read(vector<unsigned long>& scalers);
  virtual void Clear();
  virtual unsigned int size() {return 32;}
};

#endif
