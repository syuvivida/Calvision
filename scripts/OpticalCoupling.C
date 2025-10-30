#include <TRandom2.h>
#include <TMath.h>
#include <TH1.h>
#include <iostream>

const double rIndex_BGO=2.15;
const double rIndex_PMT=1.5;
const unsigned int nTotal=10000;

using namespace std;

void OpticalCoupling(float rIndex_gel=1.4)
{
  TH1F* hInput = new TH1F("hInput","Incident Angle",100,0,2*TMath::Pi());
  TH1F* hInput2 = (TH1F*)hInput->Clone("hInput2");
  TH1F* hOutput = (TH1F*)hInput->Clone("hOutput");
  TH1F* hSinInput2 = new TH1F("hSinInput2","Sine of input2",100,-1,1);
  TH1F* hSinOutput = (TH1F*)hSinInput2->Clone("hSinOutput");
  
  unsigned int nOut=0;
  unsigned int nInput2=0;
  TRandom2* gRandom=new TRandom2();
  for(unsigned int i=0; i<nTotal; i++)
    {
      double in_angle = 0.5*TMath::Pi()*gRandom->Rndm(i);
      hInput->Fill(in_angle);
      double in2_sin = rIndex_BGO*TMath::Sin(in_angle)/rIndex_gel;
      hSinInput2->Fill(in2_sin);
      // if total internal reflection occurs
      if(fabs(in2_sin-1)<1e-6 || in2_sin>1)
	continue;
      nInput2++;
      double in2_angle = TMath::ASin(in2_sin);
      hInput2->Fill(in2_angle);

      // noew check the light from grease to PMT window
      double out_sin = rIndex_gel*TMath::Sin(in2_angle)/rIndex_PMT;
      hSinOutput->Fill(out_sin);
      // if total internal reflection occurs
      if(fabs(out_sin-1)<1e-6 || out_sin>1)
	continue;
      double out_angle = TMath::ASin(out_sin);
      hOutput->Fill(out_angle);
      nOut++;
      
    } // end of simulation

  double frac_Out = (double)nOut/(double)nTotal;
  cout << "Fraction of photons out is " << frac_Out << endl;
  double frac_stage1 = (double)nInput2/(double)nTotal;
  cout << "Fraction of photons out in stage 1 is " << frac_stage1 << endl;
  double frac_stage2 = (double)nOut/(double)nInput2;
  cout << "Fraction of photons out in stage 2 is " << frac_stage2 << endl;
  
}
