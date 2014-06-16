
using namespace std;

#define MaxHits 416
#define MaxCaenHits 160

class RFTimeClass{
public:
  RFTimeClass(){};
  short Time[2];

  void Reset(){    
    Time[0] = 0;    
    Time[1] = 0;    
  };
};

class IonChamberClass{
public:
  IonChamberClass(){};
  
  short RawE[4], Time[4];
  float CalE[4];
  float m[4];
  float b[4];

  void Reset(){    
    for (int i=0;i<4;i++){
      RawE[i] = 0;  Time[i] = 0;  CalE[i] = 0;
    }
  };

};

class S2Class{
public:
  S2Class(){};
  
  short RawE[32], Time[32];
  float CalE[32];

  //Coefficients for linear charge calibration.
  float m[32];  float b[32];

  //After the charge calibration is done, the linear energy calibration
  //coefficients can be applied to all the channels in the detector.
  float mE;      float bE;

  void Reset(){    
    for (int i=0;i<32;i++){
      RawE[i] = 0;  Time[i] = 0;  CalE[i] = 0;
    }
  };

};


class ASICHit {
// This class is for ASICs hit
public:
	ASICHit(){};
	Int_t Nhits,MBID[MaxHits],CBID[MaxHits],ChNum[MaxHits];
        Int_t Energy[MaxHits];
        Int_t Time[MaxHits];
        void zeroASICHit()
	{
	   Nhits = 0;
           for (Int_t i=0; i<MaxHits;i++) {
              MBID[i] = 0;
              CBID[i] = 0;
              ChNum[i] = 0;
              Energy[i] = 0;
              Time[i]  = 0;
           } 	
        };
};

class CAENHit {
//This class is for CAEN digitizer
public:
	CAENHit(){};
	Int_t Nhits,ID[MaxCaenHits],ChNum[MaxCaenHits];
        Int_t Data[MaxCaenHits];
        void zeroCAENHit()
	{
	    Nhits = 0;
            for (Int_t i=0; i<MaxCaenHits;i++) {
              ID[i] = 0;
              ChNum[i] = 0;
              Data[i]  = 0;
           }
         };
};

//The SuperX3 detectors have 12 channels which correspond to 4 back segments
//and 4 front silicon strips which have two signals each (left and right).
class SuperX3Class{
public:
  SuperX3Class(){};
  
  int RawE[12],Time[12];
  float CalE[12];
  float m[12];
  float b[12];

   void Reset(){    
    for (int i=0;i<12;i++){
      RawE[i] = 0;  Time[i] = 0; CalE[i] = 0;
    }
  };

   /*
   //DSG: I don't get why do we need this function if all the data is in the TTree anasen_data with the
   //SX3 structure.
   void SetRaw(short PRawE[32], short PTime[32]){
     for (i=0;i<32;i++){
       RawE[i]=PRawE[i];
       Time[i]=PTime[i];
     }
   };
   
   void Calibrate(){
    //How the parameters are assigned.
    //  Ar param[0-3]    
    //  Br param[4-7]
    //  Al param[8-11]
    //  Bl param[12-15]
    //  Ab param[16-19]
    //  Bb param[20-23]
    //  G  param[24-27]

    double Ar[4],Al[4],Ab[4];
    double Br[4],Bl[4],Bb[4];
    double G[4];

    //Left and right edges of detectors for each back channel.
    //               bch     8    9   10  11
    double LeftEdge[4]  = {-1.0,-0.5, 0 ,0.5};
    double RightEdge[4] = {-0.5, 0  ,0.5,1.0};
    
    double ql,qr,qb;
    short time;

    double chi2=0;

    for(int bch=8; bch<12; bch++){

      //Back charge and time of channel bch.
      qb = this->RawE[bch];
      time  = this->Time[bch];

      if(time>4400 && time<4600 && qb>0){

	for(int strip=0; strip<4; strip++){

	  //The left and right signal depend on the strip number.
	  switch(strip){	  
	  case 0: ql = this->RawE[1]; qr = this->RawE[0]; break;
	  case 1: ql = this->RawE[3]; qr = this->RawE[2]; break;
	  case 2: ql = this->RawE[4]; qr = this->RawE[5]; break;
	  case 3: ql = this->RawE[6]; qr = this->RawE[7]; break;
	  }
	  
	  if(ql>0 && qr>0){
	  
	    // set the calibration parameters 
	    for(int i=0; i<28; i++){

	      if(i>=0 && i<4)	Ar[i%4] = param[i];
	      if(i>=4 && i<8)	Br[i%4] = param[i];
	      if(i>=8 && i<12)	Al[i%4] = param[i];
	      if(i>=12 && i<16)	Bl[i%4] = param[i];
	      if(i>=16 && i<20)	Ab[i%4] = param[i];
	      if(i>=20 && i<24)	Bb[i%4] = param[i];
	      if(i>=24 && i<28)	 G[i%4] = param[i];
	      
	    }
	    
	    double Er = Ar[strip]*qr + Br[strip];
	    double El = Al[strip]*ql + Bl[strip];
	    double Eb = Ab[bch]*qb + Bb[bch];
	    double p  = G[strip]*(Er-El)/Eb;// + some offset??
	    
	    // calculate the fitresiduum for the data contained in class element
	    //Adding terms to the chi^2.
	    chi2 += (Eb-Er-El)*(Eb-Er-El);
	    
	    if(p-LeftEdge[bch]<0)
	      chi2 += (p-LeftEdge[j])*(p-LeftEdge[j]);
	    
	    if(p-RightEdge[bch]>0)
	      chi2 += (p-RightEdge[j])*(p-RightEdge[j]);
	    
	    
	  }
	}
      }
    }

    return chi2;
  
  };
   
   double fitfunction(int i,double param[28])
   {
     // get data for event i
     // set detector calibration from param[28]
     // calculate fit-residuum and return it
   }


   */

};

class AnalysisClass{

public: AnalysisClass(){};

float Kl[48],Kh[48],Exc[48],Qvalue[48];

  void Reset(){
  for(int i=0; i<48; i++)
    Kl[i]=Kh[i]=Exc[i]=Qvalue[i]=0;
  };

};

