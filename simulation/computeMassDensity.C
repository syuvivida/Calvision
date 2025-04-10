#include <iostream>

using namespace std;
const double mass_B=10.81;
const double mass_Si=28.085;
const double mass_Al=26.9815385;
const double mass_Gd=157.25;
const double mass_Ce=140.116;
const double mass_O=15.999;
       

const double n_B=2;
const double n_Si=1;
const double n_Al=2;
const double n_Gd=2;
const double n_Ce=2;
const double n_B_O=3;
const double n_Si_O=2;
const double n_Al_O=3;
const double n_Gd_O=3;
const double n_Ce_O=3;

const double default_B2O3=17.5;
const double default_SiO2=19;
const double default_Al2O3=1;
const double default_Gd2O3=61.5;
const double default_Ce2O3=1;

void computeMassDensity(const float Frac_Gd2O3=61.5)
{
  std::cout << "Note the fraction is between 0 and 100" << std::endl;
  double total_mass = default_B2O3*(mass_B*n_B+mass_O*n_B_O)+
    default_SiO2*(mass_Si*n_Si+mass_O*n_Si_O)+
    default_Al2O3*(mass_Al*n_Al+mass_O*n_Al_O)+
    Frac_Gd2O3*(mass_Gd*n_Gd+mass_O*n_Gd_O)+
    default_Ce2O3*(mass_Ce*n_Ce+mass_O*n_Ce_O);

  double frac_B = default_B2O3*mass_B*n_B/total_mass;
  double frac_Si= default_SiO2*mass_Si*n_Si/total_mass;
  double frac_Al = default_Al2O3*mass_Al*n_Al/total_mass;
  double frac_Gd = Frac_Gd2O3*mass_Gd*n_Gd/total_mass;
  double frac_Ce = default_Ce2O3*mass_Ce*n_Ce/total_mass;
  double frac_O = (default_B2O3*mass_O*n_B_O+ default_SiO2*mass_O*n_Si_O+
		   default_Al2O3*mass_O*n_Al_O+Frac_Gd2O3*mass_O*n_Gd_O+default_Ce2O3*mass_O*n_Ce_O)/total_mass;
  
  std::cout << "Results are " << endl;
  std::cout << "<fraction n=\"" << Form("%.4f",frac_B) << "\" ref=\"B\"/>" << endl; 
  std::cout << "<fraction n=\"" << Form("%.4f",frac_Si) << "\" ref=\"Si\"/>" << endl; 
  std::cout << "<fraction n=\"" << Form("%.4f",frac_Al) << "\" ref=\"Al\"/>" << endl; 
  std::cout << "<fraction n=\"" << Form("%.4f",frac_Gd) << "\" ref=\"Gd\"/>" << endl; 
  std::cout << "<fraction n=\"" << Form("%.4f",frac_Ce) << "\" ref=\"Ce\"/>" << endl; 
  std::cout << "<fraction n=\"" << Form("%.4f",frac_O) << "\" ref=\"O\"/>" << endl; 

  
}
