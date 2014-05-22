/*
The class maintains a pointer to a CSIS3820 object. The CSIS3820 class 
provides hardware support for the module. The constructor and destructor 
just create and destroy this object:
*/

#include "NEROScaler.h"
#include <CSIS3820.h>
#include <iostream>
#include <vector>
/* Constructor: creates CSIS3820 object */
MainScaler::MainScaler(unsigned long base, int crate)
{
  try {
    m_pVMESCAL = new CSIS3820(base, crate);
  }
  catch(string msg) {
    cerr << "Error creating CSIS3820: " << msg << endl;
  }
  catch(...) {
    cerr << "Unexpected excpetion caught creating CSIS3820\n";
  }
}

MainScaler::~MainScaler() 
{
  delete m_pVMESCAL;
}

/*
To initialize the module, we need to set it in latching mode. 
In many applications, it is also important to selectively inhibit counting in
some channels of the scalers read. The SIS3820 allows the front panel inputs 
to be used to selectively inhibit groups of 8 channels. We will set up the 
module to support this as well. Finally, in order to prevent read/clear skew, 
we will program the module to clear the counters on a latch operation, clear 
the module and start the scaler counting.
*/

void MainScaler::Initialize() 
{

  /* Select SIS3820 operating mode: Latching mode*/
  m_pVMESCAL->setOperatingMode(CSIS3820::LatchingScaler);
  /* Select SIS3820 input mode: No NIM input signals*/ 
  m_pVMESCAL->setInputMode(CSIS3820::NoInputs);
  /* Clear the counters when latched --> Function as a scaler*/
  m_pVMESCAL->EnableClearOnLatch(); 
  /* Clear module*/
  m_pVMESCAL->ClearChannels(); 
  /* Arm and enable module */
  m_pVMESCAL->Arm();
  m_pVMESCAL->Enable();
}


/*
The module is read out by latching it and reading the channels. There's an 
impedance mismatch between the parameter types required by the CSIS3820 readout
functions and the parameters passed to Read. It is therefore necessary to read 
the data into an internal buffer and then copy it to the end of the output 
vector:
*/

void MainScaler::Read(vector<unsigned long>& scalers) 
{
  unsigned long data[32];           // 32 channel buffer.
  m_pVMESCAL->LatchAndRead(data);   // Latch and read module

  scalers.insert(scalers.end(),
                 data, data+32);
}

/*
The insert memeber function of the vector class is used to append all 32 
channels of data to the scalers vector in a single operation.

The Clear member function is called to clear the module after read. In our 
case we have covered all the clears by clearing the module when it is initialized and setting up the module to clear when latched. The clear member function is therefore empty:
*/

void MainScaler::Clear()
{
  /* Clear module*/
      m_pVMESCAL->ClearChannels(); 
}
