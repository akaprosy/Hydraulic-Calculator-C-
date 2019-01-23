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
     double horsePowerFormula(double pressure, double flow) {
     double horsepower = (pressure * flow)/1714;
     return horsepower;
}
//function for calculating force given pressure and area
    double cylinderForce(double pressure, double area) {
    double force = pressure * area;
    return force;
}
//function for calculating pressure given force and area
    double cylinderPressure(double force, double area) {
    ouble pressure = force/area;
    return pressure;
}
//function for calculating pistion area given force and pressure
    double cylinderArea(double force, double pressure) {
    double area = force/pressure;
    return area;
}
    double cylinderArea2(long double diameter) {
    double area = diameter * diameter *.7854;
    return area;
}
    double annularArea(double boreDiameter, double rodDiameter ) {
    double boreArea = boreDiameter * boreDiameter * .7854;
    double rodArea = rodDiameter * rodDiameter *.7854;
    double annArea = boreArea - rodArea;
    return annArea;
}
//Function for cylinder velocity extending or extending
    double velocity1(double stroke, double time) {
    double velocity = stroke * (60/time);
    return velocity;
}
//Function for flow requirement given cylinder velocity and area(extending)
    double cylinderFlow1(double velocity, double boreDiameter, double stroke){
    double boreArea = boreDiameter * boreDiameter * .7854;
    double area = stroke * boreArea;
    double flow = (velocity * area)/231;
    return flow;
}
//Function for flow requirement given cylinder velocity and area(retracting)
    double cylinderFlow2(double velocity, double rodDiameter, double boreDiameter,double stroke){
    double areaBore = boreDiameter * boreDiameter * .7854;
    double areaRod = rodDiameter * rodDiameter * .7854;
    double annArea = areaBore - areaRod;
    double area = stroke * annArea;
    double flow = (velocity * area)/231;
    return flow;
}
int main(){

    char calculatorOption;//main menu selector
    double pressureIn, flowIn;//hydraulic horsepower variables.Case A
    double cylForce, cylPressure, cylArea;//for case B, C, D.
    double diameter;//for case E
    double boreDia, rodDia;//for case F,H,I
    double cylStroke, extendTime; // for case G,H,I
    double cylVelocity;//for case H,I


   mainMenu();
   cout<<"Choose a calculator: ";
   cin>>calculatorOption;

switch(calculatorOption) {
   //calculate hydraulic horsepower
   case 'A':
   case 'a':

   cout<<"Enter pressure(psi): ";
   cin>>pressureIn;
   cout<<"Enter flow(gpm): ";
   cin>>flowIn;
   cout<<"Required horsepower is: "<<horsePowerFormula(pressureIn, flowIn)<<" hp"<<endl;
   break;

   //calculate force given pressure and area
   case 'B':
   case 'b':

   cout<<"Enter pressure(psi): ";
   cin>>cylPressure;
   cout<<"Enter cylinder piston area(square inches): ";
   cin>>cylArea;
   cout<<"Force generated: "<<cylinderForce(cylPressure, cylArea)<<" lbs."<<endl;
   break;
   //calculate pressure given force and area
   case 'C':
   case 'c':
   cout<<"Enter cylinder force(lbs.): ";
   cin>>cylForce;
   cout<<"Enter cylinder pistion area: ";
   cin>>cylArea;
   cout<<"Pressure required is: "<<cylinderPressure(cylForce, cylArea)<<" psi"<<endl;
   break;
   //Calculate cylinder piston area given force and pressure
   case 'D':
   case 'd':

   cout<<"Enter cylinder force(lbs.): ";
   cin>>cylForce;
   cout<<"Enter pressure(psi): ";
   cin>>cylPressure;
   cout<<"Cylinder area is: "<<cylinderArea(cylForce, cylPressure)<<" square inches"<<endl;
   break;
   //Calculate cylinder area given diameter
   case 'E':
   case 'e':

   cout<<"Enter cylinder bore diameter: ";
   cin>>diameter;
   cout<<"Cylinder area is: "<<cylinderArea2(diameter)<<" square inches"<<endl;
   break;
   //Calculate annular area given piston and rod diameter
   case 'F':
   case 'f':
   cout<<"Enter cylinder bore diameter: ";
   cin>>boreDia;
   cout<<"Enter cylinder rod diameter: ";
   cin>>rodDia;
   cout<<"Annular area is: "<<annularArea(boreDia, rodDia)<<" square inches"<<endl;
   break;
   //Find velocity of a cylinder extending given stroke and time
   case 'G':
   case 'g':

    cout<<"Enter stroke(inches): ";
    cin>>cylStroke;
    cout<<"Enter time to extend or retract(seconds): ";
    cin>>extendTime;
    cout<<"Velocity is: "<<velocity1(cylStroke, extendTime)<<" inches/seconds"<<endl;
    break;
    //flow requirment cylinder extending
   case 'H':
   case 'h':

    cout<<"Enter velocity(inches/minutes): ";
    cin>>cylVelocity;
    cout<<"Enter bore size(inches): ";
    cin>>boreDia;
    cout<<"Enter stroke(inches): ";
    cin>>cylStroke;
    cout<<"Flow is: "<<cylinderFlow1(cylVelocity, boreDia, cylStroke)<<" gpm"<<endl;
    break;
    //flow requirement cylinder retracting
    case 'I':
    case 'i':

    cout<<"Enter velocity(inches/minutes): ";
    cin>>cylVelocity;
    cout<<"Enter rod diameter(inches): ";
    cin>>rodDia;
    cout<<"Enter bore size(inches): ";
    cin>>boreDia;
    cout<<"Enter stroke(inches): ";
    cin>>cylStroke;
    cout<<"Flow is: "<<cylinderFlow2(cylVelocity, rodDia, boreDia, cylStroke)<<" gpm"<<endl;
    break;

   default:
   cout<<"Invalid Entry";
}
   return 0;

}

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
