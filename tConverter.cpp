/**************************************
** Temperture convertor             **
** By Douglas L                     **
** created 12/8/2017                **
**************************************/


#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

//convert celcious to faranheight
double cToF(double c);

//convert faranheight to celcious
double fToC(double f);

//convert cecious to kelvin
double cToK(double c);

//convert kelvin to cecious
double kToC(double k);

//custom input function
#define getInput(output,input) cout << "| " << output << " >"; cin>>input

//graphical functions
string String_2Decimals(string arg);
void printLine(char weight);
void LeftString(string str);
void CenterString(string str);


struct Temperture{
  char type = '\0';
  double magnitude;
};

//gets temperture from user and returns it
Temperture getTemperture();

//prints temperture and its type
void printTemperture(Temperture T);

//converts tempurture to another type while changing its magnatude to keep the value correct
Temperture convertTemperture(Temperture T, char to);

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
      case '1': T = convertTemperture(T,'F'); break;
      case '2': T = convertTemperture(T,'C'); break;
      case '3': T = convertTemperture(T,'K'); break;
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

Temperture convertTemperture(Temperture T, char conversionType){
  switch (conversionType) {
    //Convert to F
    case 'F':
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
    break;

    //Convert to C
    case 'C':
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
    break;

    //Convert to K
    case 'K':
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
    break;
  }
  return T;
}

//convert celcious to faranheight
double cToF(double c){
  CenterString("*converting C to F*");
  return c * 1.8 + 32;
}

//convert faranheight to celcious
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