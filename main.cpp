#include <iostream>

using namespace std;
string mainMenu() {
    cout<<"Main Menu:"<<endl;
    cout<<"   (A) - Calculate hydraulic horsepower given pressure and flow."<<endl;
    cout<<"   (B) - Calculate force given pressure and area. "<<endl;
    cout<<"   (C) - Calculate pressure given force and area. "<<endl;
    cout<<"   (D) - Calculate area given force and pressure. "<<endl;
    cout<<"   (E) - Calculate area of a cylinder given diameter. "<<endl;
    cout<<"   (F) - Calculate annular area of a cylinder. "<<endl;
    cout<<"   (G) - Calculate cylinder velocity extending or retracting. "<<endl;
    cout<<"   (H) - Calculate cylinder flow requirement given cylinder area and velocity(Extending). "<<endl;
    cout<<"   (I) - Calculate cylinder flow requirement given cylinder area and velocity(Retracting). "<<endl;




}
//function for calculating hydraulic horsepower
long double horsePowerFormula(long double pressure, long double flow) {
     double horsepower = (pressure * flow)/1714;
     return horsepower;
}
//function for calculating force given pressure and area
long double cylinderForce(long double pressure, long double area) {
    long double force = pressure * area;
    return force;
}
//fuction for calculating pressure given force and area
long double cylinderPressure(long double force, long double area) {
    long double pressure = force/area;
    return pressure;
}
//fuction for calculating pistion area given force and pressure
long double cylinderArea(long double force, long double pressure) {
    long double area = force/pressure;
    return area;
}
long double cylinderArea2(long double diameter) {
    long double area = diameter * diameter *.7854;
    return area;
}
long double annularArea(long double boreDiameter, long double rodDiameter ) {
    long double boreArea = boreDiameter * boreDiameter * .7854;
    long double rodArea = rodDiameter * rodDiameter *.7854;
    long double annArea = boreArea - rodArea;
    return annArea;
}
//Function for cylinder velocity extending or extending
long double velocity1(long double stroke, long double time) {
    long double velocity = stroke * (60/time);
    return velocity;
}
//Function for flow requirement given cylinder velocity and area(extending)
long double cylinderFlow1(long double velocity, long double boreDiameter, long double stroke){
    long double boreArea = boreDiameter * boreDiameter * .7854;
    long double area = stroke * boreArea;
    long double flow = (velocity * area)/231;
    return flow;
}
//Function for flow requirement given cylinder velocity and area(retracting)
long double cylinderFlow1(long double velocity, long double rodDiameter, long double boreDiameter, long double stroke){
    long double areaBore = boreDiameter * boreDiameter * .7854;
    long double areaRod = rodDiameter * rodDiameter * .7854;
    long double annArea = areaBore - areaRod;
    long double area = stroke * annArea;
    long double flow = (velocity * area)/231;
    return flow;
}
int main(){

    char calculatorOption;//main menu selector
    long double pressureIn, flowIn;//hydraulic horsepower variables.Case A
    long double cylForce, cylPressure, cylArea;//for case B, C, D.
    long double diameter;//for case E
    long double boreDia, rodDia;//for case F,H,I
    long double cylStroke, extendTime; // for case G,H,I
    long double cylVelocity;//for case H,I


   mainMenu();
   cout<<"Choose a calculator: ";
   cin>>calculatorOption;

switch(calculatorOption) {
   //calculate hydraulic horsepower
   case 'A':

   cout<<"Enter pressure(psi): ";
   cin>>pressureIn;
   cout<<"Enter flow(gpm): ";
   cin>>flowIn;
   cout<<(horsePowerFormula(pressureIn, flowIn))<<endl;
   break;

   //calculate force given pressure and area
   case 'B':

   cout<<"Enter pressure(psi): ";
   cin>>cylPressure;
   cout<<"Enter cylinder piston area(square inches): ";
   cin>>cylArea;
   cout<<(cylinderForce(cylPressure, cylArea));
   break;
   //calculate pressure given force and area
   case 'C':

   cout<<"Enter cylinder force(lbs.): ";
   cin>>cylForce;
   cout<<"Enter cylinder pistion area: ";
   cin>>cylArea;
   cout<<(cylinderPressure(cylForce, cylArea));
   break;
   //Calculate cylinder piston area given force and pressure
   case 'D':

   cout<<"Enter cylinder force(lbs.): ";
   cin>>cylForce;
   cout<<"Enter pressure(psi): ";
   cin>>cylPressure;
   cout<<(cylinderArea(cylForce, cylPressure));
   break;
   //Calculate cylinder area given diameter
   case 'E':
   cout<<"Enter cylinder bore diameter: ";
   cin>>diameter;
   cout<<(cylinderArea2(diameter));
   break;
   //Calculate annular area given piston and rod diameter
   case 'F':
   cout<<"Enter cylinder bore diameter: ";
   cin>>boreDia;
   cout<<"Enter cylinder rod diameter: ";
   cin>>rodDia;
   cout<<(annularArea(boreDia, rodDia));
   break;
   //Find velocity of a cylinder extending given stroke and time
   case 'G':
    cout<<"Enter stroke(inches): ";
    cin>>cylStroke;
    cout<<"Enter time to extend or retract(seconds): ";
    cin>>extendTime;
    cout<<(velocity1(cylStroke, extendTime));
    break;
    //flow requirment cylinder extending
   case 'H':
    cout<<"Enter velocity(inches/minutes): ";
    cin>>cylVelocity;
    cout<<"Enter bore size(inches): ";
    cin>>boreDia;
    cout<<"Enter stroke(inches): ";
    cin>>cylStroke;
    cout<<(cylinderFlow1(cylVelocity, boreDia, cylStroke));
    break;
    //flow requirement cylinder retracting
    case 'I':
    cout<<"Enter velocity(inches/minutes): ";
    cin>>cylVelocity;
    cout<<"Enter rod diameter(inches): ";
    cin>>rodDia;
    cout<<"Enter bore size(inches): ";
    cin>>boreDia;
    cout<<"Enter stroke(inches): ";
    cin>>cylStroke;
    cout<<(cylinderFlow1(cylVelocity, rodDia, boreDia, cylStroke));
    break;

   default:
   cout<<"Invalid Entry";
}
   return 0;

}