/*************************************************************************** 
   Readout program for NERO
   using Ring DAQ of NSCL DAQ 10.2-106
   Program includes:
    - Starting from a scratch Skeleton.h/cpp files
    - 1 Wienner VC32 CAMAC Controller (NERO)
    - VME Crate (number 1)
    - CAMAC Crate (number 2)

   08/25/2014 - First version created by Tony Ahn.
***************************************************************************/

#include <config.h>
#include <stdint.h>
#include <CEventSegment.h>
#include <wienercamac.h> //Include Wienner CAMAC controller
#include <CaenIO.h>

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

class NEROIO : public CEventSegment
{
private:
  CCaenIO* m_pIOREGISTER;
  
public:
  NEROIO(uint32_t base, int crate = 0);
  ~NEROIO();

  virtual void initialize();
  virtual void clear();
  virtual size_t read(void* pBuffer, size_t maxwords);
};
