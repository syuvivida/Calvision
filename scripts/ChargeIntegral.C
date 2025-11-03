#include <TF1.h>


Double_t pulse(Double_t *x, Double_t *par)
{
   Double_t time =x[0];
   Double_t norm = par[0];
   Double_t riseTime = par[1];
   Double_t DecayTime = par[2];
   //   Double_t slope = -norm/riseTime;
   //   Double_t f = time < riseTime? slope*time:
   //     -norm*TMath::Exp(-(time-riseTime)/DecayTime);
   //   Double_t area = fabs(0.5*slope*riseTime*riseTime - norm*DecayTime);
   //   f = f/area;
   Double_t slope = -1/riseTime;
   Double_t f = time < riseTime? slope*time:
     -1.0*TMath::Exp(-(time-riseTime)/DecayTime);
   Double_t area = fabs(0.5*slope*riseTime*riseTime - 1.0*DecayTime);
   f = f*norm/area;
   return f;
}

void myfunc()
{
  auto f1 = new TF1("f1",pulse,0,3000,3);
  // norm
  //  f1->SetNpx(2000);
  // 
  double effCharge1 = //0.511*8000*5*1e5*0.2*1.6e-19*50/1e-9;
    //    0.511*8000*3*5e6*0.2*1.6e-19*50/1e-9;
    0.511*5200*5e5*0.2*1.6e-19*50/1e-9;
  //    0.511*5200*3*5e6*0.2*1.6e-19*50/1e-9;
  //  9*5200*5*1e5*0.2*1.6e-19*50/1e-9;    
  //    9*8000*5*1e5*0.2*1.6e-19*50/1e-9;    
    //8000*1e6*0.2*1.6e-19*0.5*50/1e-9;
  f1->SetParameter(0,effCharge1);
  f1->SetParameter(1,30);
  f1->SetParameter(2,300);
  f1->SetParNames("Norm","Rise time","Decay time");
  f1->Draw();

  auto f2 = new TF1("f2",pulse,0,3000,3);
  // norm
  double effCharge2 = //0.511*9000*5e5*0.2*1.6e-19*50/1e-9;
    0.511*9000*3*5e6*0.2*1.6e-19*50/1e-9;
    // 2*9000*5*1e5*0.2*1.6e-19*50/1e-9;
    //0.5*9000*1e6*0.2*1.6e-19*50/1e-9;
  f2->SetParameter(0,effCharge2);
  f2->SetParameter(1,12);
  f2->SetParameter(2,15);
  f2->SetParNames("Norm","Rise time","Decay time");
  f2->SetLineColor(4);
  f2->Draw();
  f1->Draw("same");
}
