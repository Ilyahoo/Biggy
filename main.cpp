#include <iostream>
#include "bigint.h"
#include <vector>
#include <string>
#include <cstdlib> /** For exit() **/
#include <fstream> /** For Write in Files **/
#include <sstream>

using namespace std;
class Argements{

public:
    string Exec;
    string Prog;
    string FileName;
    string Num1;
    string Num2;
    string op;
    const char *FileNameC;

typedef bool flag;
flag SimplyRun;
flag IgnoreFlag;
flag JustKedding;
flag HasFile;
flag HasOperation ;



vector<string> lineCmd;
    Argements(int& ArgC, char *ArgV[])
    :SimplyRun(true), IgnoreFlag(false),
    JustKedding(false), HasFile(false), HasOperation(false){
        for(int i = 0; i < ArgC; i++){
            lineCmd.push_back(ArgV[i]);
        }

        Exec = lineCmd[0];
        lineCmd.erase(lineCmd.begin());
        stringstream ss(Exec); /** <-- You Should delete this**/
        string item;
        vector<string> after;
        while(getline(ss, item,'\\')){
            after.push_back( item );
        }
        Prog = after.back();
        Handle_Argements();
        }
void Handle_Argements(){
    int Argc = lineCmd.size();
    if(Argc == 0){
    }
    if(Argc == 1) {
        if (lineCmd[0] == "--help" || lineCmd[0] == "-h"){
            Help();
        }
        else if (lineCmd[0] == "--version" || lineCmd[0] == "-v"){
            Version();
        }
        else if (lineCmd[0].size() > 2){
            cerr<<"Unknown option -- "<<lineCmd[0]<<endl;
            SomeThingWrong();
        }
        else{
            FlagSet(lineCmd.begin(),0);
        }
    }
    lineCmd.push_back("EOLC");
    vector<string>::iterator i = lineCmd.begin();
    while(*i !="EOLC"){

            string Par = *i;
            if (isdigit(Par[0]) || isdigit(Par[1])){
                NumbersHere(i); /**Sending itterator**/

            Par = *i;

                }

            else if(Par.size() == 2){
                    if(Par[1]=='o'){
                        FileName = *(i+1);
                        FileNameC = FileName.c_str();
                        lineCmd.erase(i+1);
                        lineCmd.erase(i);
                        CheckFileName();
                       }
                    else{
                        FlagSet(i,1);
                        }
            Par = *i;
            }

            else if(Par.size()==3){

                FlagSet(i,1);
            Par = *i;
            }

            else if(Par == "EOLC"){
                break;
            }

            else{
                cerr<<Prog<<": Unknown option --end"<<Par<<endl;
                SomeThingWrong();
            }

        }
    };


void NumbersHere(vector<string>::iterator it){
    SimplyRun = false;
    string s3 = *(it+2);

    if(!isdigit(s3[1]) || !isdigit(s3[0])){
          SomeThingWrong();
        }
    else{
        Num1 = *it;
        op = *(it+1);
        Num2 = *(it+2);
        }

    lineCmd.erase(it+2);
    lineCmd.erase(it+1);
    lineCmd.erase(it);

    char ch = op[0];
        switch(ch){
    case '+':
        HasOperation = true;
        break;
    case 'x':
        HasOperation = true;
        break;
    default:
        cerr<<Prog<<": Unknown operator -- "<<ch<<endl;
        SomeThingWrong();
        }
};

void FlagSet(vector<string>::iterator it,bool cnt){
    string flagged = *it;

    if (cnt){
    lineCmd.erase(it);

    }
    for(int i = 1; i < flagged.size(); i++){
            char x = flagged[i];
        if(x == 'i'){
            IgnoreFlag = true;}

        else if(x == 'a'){
            JustKedding = true;}
        else{
        cerr<<Prog<<": Unknown option -- -"<<x<<endl;
        SomeThingWrong();
        }
    }
    SimplyRun = true;

};
void CheckFileName(){
    ofstream myfile;
    myfile.open(FileNameC);
    if(!myfile.is_open()){
            cerr<<Prog<<": You must enter valid file name!."<<endl;
            SomeThingWrong();
        }
    HasFile = true;
    myfile.close();
};
template<class T>
void WriteTo(T aa){
    ofstream myfile;
    myfile.open(FileNameC);
    if(!myfile.is_open()){
            cerr<<Prog<<": You must enter valid file name!."<<endl;
            SomeThingWrong();
        }
    myfile << aa<<endl;
    myfile.close();
}

void Help(){

    cout <<"Usage: "<<Prog<<" [OPTION]... NUMBER1 [+x] NUMBER2 [FILE]"<<endl;
    cout <<" Big integer Calculator."<<endl<<endl;
    cout <<" With no NUMBERS. Entry to interactive mode."<<endl<<endl;
    cout <<" With NUMBERS, No FILE . Write to standard output."<<endl;
    cout <<" With NUMBERS and FILE. Write the result to the FILE."<<endl<<endl;
    cout <<" With just FILE. Entry to interactive mode and write the"<<endl;
    cout <<"      result in standard output and FILE: BOTH."<<endl<<endl;
    cout <<" Options:"<<endl;
    cout <<"     -i\t\tIgnore the Error 89: With this Option the main program"<<endl;
    cout<<"\t\t will ignore non-digits character. e.g: 12R4 will be 124"<<endl;
    cout <<"     -o\t\tSet an output FILE. For both modes: interactive and command line"<<endl;
    cout<<"\t\t or for just command line. Notice that \'-o\' should followed by FILENAME."<<endl;
    cout <<"     -v\t\tShow actual version of this program. or use \'--version\'."<<endl<<endl;
    cout<<" Exit Status:"<<endl;
    cout<<"   0 if OK."<<endl;
    cout<<"  89 if Input number contain non-digit (e.g: 123i5)."<<endl;
    cout<<"  99 if Internal output contain non-digit (e.g: 123i5)."<<endl;
    cout<<" 127 if There is wrong argument (e.g: "<<Prog<<" -f)."<<endl<<endl;
    cout<<"For bug, please e-mail me:"<<endl;
    cout<<"<irens@live.nl>"<<endl;
    exit(0);


};
void Version(){
    cout<<Prog<<" V1.0"<<endl;
    cout<<" Copyright (C) 2018, LPEII FPN, NADOR"<<endl;
    cout<<"License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>."<<endl;
    cout<<"This is free software: you are free to change and redistribute it."<<endl;
    cout<<"There is NO WARRANTY;"<<endl<<endl;
    cout<<"Writted By: IP"<<endl;
    exit(0);

exit(0);};
void SomeThingWrong(){
    cerr<<"Try \'"<<Prog<<" -h\' or \'"<<Prog<<" --help\' for more information."<<endl;
    exit(127);
};
};
using namespace std;

int main(int argc, char* argv[])
{
    BigInt N1,N2;
    Argements Biggy(argc, argv);
    if(Biggy.SimplyRun){
        string op;
        cout << "Welcom to BIGINT Calculator v1.0 (use -h for more information)" << endl;
        cout << "1-Enter a valid BigInt number:" << endl;
        cin >> N1;
        cout <<"What operation: + x > < >= <= == != :" << endl;
        cin >> op;
        cout << "2-Enter a valid BigInt number:" << endl;
        cin >> N2;
        BigInt Res;
        if(!op.compare("+")){
            Res = N1 + N2;
        }
        if(!op.compare("x")){
            Res = N1 * N2;
        }

        if(Biggy.HasFile){
            //Biggy.writeTo()
            Biggy.WriteTo(Res);
        }
        cout << "The result is: " << endl;
        cout << Res << endl;
        }
    if(Biggy.HasOperation){
        string op = Biggy.op;
        BigInt Res;
        N1 = Biggy.Num1;
        N2 = Biggy.Num2;
        if(!op.compare("+")){
            Res = N1 + N2;
        }
        if(!op.compare("x")){
            Res = N2 * N2;
        }

        if(Biggy.HasFile){
            Biggy.WriteTo(Res);
        }
        cout << "The result is: " << endl;
        cout << Res << endl;
        }


    return 0;
}
