#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
int main()
{
    const double PI = 3.14159;
    double L,W,R;     // L = length , W = width , R = radius of the pool 
      
    double DD,DS ;    // DD = Depth of deep end ,DS = Depth of shallow end  of pool
      
    double LD,LS ;   //  LD = length of deep end , LS = length of shallow end of pool
      
    double hp = 0.5,Tc,V1,V2 ;  // hp = 6 inches space left in pool to fill water, Tc = Total pounds of chlorine treatment needed 
                                // V1 = Total volume of the pool  , V2 = Total volume of water to fill the pool 
                             
                                                   
    int Vp,Vw,Tw; // Vp = Total volume of the pool with ceil  , V2 = Total volume of water to fill the pool with ceil , Tw = Total US gallon of water to fill the pool 
                             
     cout << fixed << setprecision (1);
  
        cout << " Enter the Length of the pool : " ;
        cin  >>   L ;

        cout << " Enter the Width of the pool  : " ;
        cin  >>   W ;

        cout << " Enter the Radius of the pool : " ;
        cin  >>   R ;

        cout << " Enter the Depth of deep end  of the pool : " ;
        cin  >>   DD ;

        cout << " Enter the Depth of shallow end  of the pool : " ;
        cin  >>   DS;

        cout << " Enter the Length of deep end  of the pool : " ;
        cin  >>   LD ;

        cout << " Enter the Length of deep shallow  of the pool : " ;
        cin  >>   LS ;
    
           cout << "\nPool Dimensions (linear feet) \n \n"     ;
           cout << "Basic Length (excluding longue area) :   " << L << endl ;

           cout << "Basic Width                          :   " << W << endl ;

           cout << "Radius of semi-circular lounge area  :   " << R << endl ;

           cout << "Depth of deep end                    :   " << DD << endl;

           cout << "Depth of shallow end                 :   " << DS << endl;

           cout << "Length of deep end                   :   " << LD << endl;

           cout << "Length of shallow end                :   " << LS << endl;


               V1 = ((0.5*PI*R*R*DS) + (LS*DS*W) + (LD*W*DD) + (0.5*(L-(LS+LD)) * (DD-DS)*W) + (DS*(L-(LS+LD))*W));

               V2 = ((0.5*PI*R*R*(DS-hp)) + (LS*(DS-hp)*W) + (LD*W*(DD-hp)) + (0.5*(L-(LS+LD)) * (DD-DS)*W) + ((DS-hp) * (L-(LS+LD))*W));

               Tw = (ceil(V2)* 7.481);     //1 cubic foot or water = 7.481 US gallons 

               Tc = (Tw*0.0001);          // 0.0001  pounds per US gallon 

               Vp = ceil(V1)   ;

               Vw = ceil(V2)   ; 

               cout << "\nPool Volume : \n" << endl ;
               cout << "Total volume of the pool (cubic feet)                   :    " << Vp ;  
               cout << "\nTotal volume of water to fill the pool (cubic feet)     :    " << Vw ;
               cout << "\n\nTotal US gallon of water to fill the pool               :    " << Tw ;
               cout << "\nTotal pounds of chlorine treatment needed               :    " << Tc << endl;

     return 0;
 }