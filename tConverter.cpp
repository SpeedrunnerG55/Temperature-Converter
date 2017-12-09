/*************************************
** Temperture convertor             **
** By Douglas L                     **
** created 12/8/2017                **
**************************************/


#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

//tool to convert celcious to fahrenheit
double cToF(double c);

//tool to convert fahrenheit to celcious
double fToC(double f);

//tool to convert cecious to kelvin
double cToK(double c);

//tool to convert kelvin to cecious
double kToC(double k);

struct Temperture{
  char type = '\0';
  double magnitude;
};

//takes anny temperature type and converts to fahrenheit with proper conversion tools
Temperture converToF(Temperture T);

//takes anny temperature type and converts to cecious with proper conversion tools
Temperture converToC(Temperture T);

//takes anny temperature type and converts to Kelvin with proper conversion tools
Temperture converToK(Temperture T);

//custom input function
#define getInput(output,input) cout << "| " << output << " >"; cin>>input

//graphical functions
string String_2Decimals(string arg);
void printLine(char weight);
void LeftString(string str);
void CenterString(string str);




//gets temperture from user and returns it
Temperture getTemperture();

//prints temperture and its type
void printTemperture(Temperture T);

//display width
int display_Width = 30;

int main(){
  bool running = true;
  Temperture T;
  printLine('#');
  CenterString("Temperture Convertor");
  CenterString("Version 0.1");
  CenterString("By SpeedrunnerG55");
  printLine(' ');
  printLine(' ');
  T = getTemperture();

  do {
    char choice = '\0';
    printLine('-');
    printTemperture(T);
    printLine('-');
    printLine(' ');
    CenterString("What would you like to do?");
    LeftString(" 1. Convert to F");
    LeftString(" 2. Convert to C");
    LeftString(" 3. Convert to K");
    LeftString(" 4. Enter ew temperture");
    LeftString(" Q. to quit");
    getInput("",choice);

    switch (choice) {
      case '1': T = converToF(T); break;
      case '2': T = converToC(T); break;
      case '3': T = converToK(T); break;
      case '4': T = getTemperture(); break;
      case 'q':
      case 'Q':
      running = false;
      default:
      CenterString("Invalid operation");
    }
    
  } while(running);

  //end program
  CenterString("Bye");
  printLine('#');

  return 0;
}

Temperture getTemperture(){
  printLine('=');
  printLine(' ');
  //get magnitude
  Temperture T;
  do {
    getInput("Enter temperture",T.magnitude);
    printLine(' ');
    if(T.magnitude <= 0){
      CenterString("ERROR Temperture must be a positive number!");
    }
  } while(T.magnitude <= 0);
  bool invalidType;
  //get type
  do {
    //reset condition
    invalidType = false;
    //print choices
    LeftString(" 1. F");
    LeftString(" 2. C");
    LeftString(" 3. K");
    //get type

    //if cin failed clear the fuffer and reset flags
    if(cin.fail()){
      cin.clear();
      cin.ignore();
    }
    //get type
    int typeChoice = 0;
    getInput("Enter Type",typeChoice);
    switch (typeChoice) {
      case 1: T.type = 'F'; break;
      case 2: T.type = 'C'; break;
      case 3: T.type = 'K'; break;
      default: CenterString("Invalid Input tht is not a type");
      invalidType = true;
    }
  } while(invalidType);
  return T;
}

void printTemperture(Temperture T){
  string message = ">  ";
  message.append(to_string(T.magnitude));
  message.push_back(' ');
  message.push_back(T.type);
  LeftString(message);
}

Temperture converToF(Temperture T){
  switch (T.type) {
    case 'K':
    //K to C to F
    T.magnitude = kToC(T.magnitude);
    case 'C':
    //C to F
    T.magnitude = cToF(T.magnitude);
    break;
  }
  T.type = 'F';
  return T;
}

Temperture converToC(Temperture T){
  switch (T.type) {
    case 'F':
    //F to C
    T.magnitude = fToC(T.magnitude);
    break;
    case 'K':
    //C to F
    T.magnitude = kToC(T.magnitude);
    break;
  }
  T.type = 'C';
  return T;
}

Temperture converToK(Temperture T){
  switch (T.type) {
    case 'F':
    //F to C to K
    T.magnitude = fToC(T.magnitude);
    case 'C':
    //C to K
    T.magnitude = cToK(T.magnitude);
    break;
  }
  T.type = 'K';
  return T;
}

//convert celcious to fahrenheit
double cToF(double c){
  CenterString("*converting C to F*");
  return c * 1.8 + 32;
}

//convert fahrenheit to celcious
double fToC(double f){
  CenterString("*converting F to C*");
  return (f - 32) / 1.8;
}

//convert cecious to kelvin
double cToK(double c){
  CenterString("*converting C to K*");
  return c + 273.15;
}

//convert kelvin to cecious
double kToC(double k){
  CenterString("*converting K to C*");
  return k - 273.15;
}

/* sets decimal point to 2 place values */
string String_2Decimals(string arg){
  int i = 0;
  while(true){
    if(arg[i] == '.' && arg[i + 1] != '\0' && arg[i + 2] != '\0')
    arg.erase(i+3,arg.length());
    i++;
    if(arg[i] == '\0') break;
  }
  return arg;
}

/* prints a chatacter string across the display */
void printLine(char weight){
  cout << "|";
  cout << string(display_Width + 2, weight);
  cout << "|" << endl;
}

/* contains a message within the display boundries centered */
void LeftString(string str){
  cout << "| ";
  int str_length = str.length();
  cout << str;
  cout << string(display_Width - (str_length - 1),' ');
  cout << "|" << endl;
}

/* contains a message within the display boundries centered */
void CenterString(string str){
  cout << "| ";
  int str_length = str.length() / 2;
  if(display_Width % 2 != 0)
  cout << " ";
  if(str.length() % 2)
  cout << string(display_Width / 2 - str_length,' ');
  else
  cout << string(display_Width / 2 - str_length + 1,' ');
  cout << str;
  cout << string(display_Width / 2 - str_length,' ');
  cout << "|" << endl;
}
