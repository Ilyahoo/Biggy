#include<iostream>
#include<string>
#include<vector>
#include <exception>

#include "bigint.h"

BigInt::BigInt():G_Sign(true)
{
    //ctor
}
istream& operator>>(istream& In,  BigInt& Passed){
            string Input_St
            In >> Input_Str;
            Passed.FromString(Input_Str);
            return In;
}
ostream& operator<<(ostream& Out, BigInt& Passed){
	Out << Passed.ToString();
	return Out;
}


string BigInt:ToString(){
	String Output;
	for(vector<int>::reverse_iterator v_It = Number.rbegin(); v_It != Number.rend(); v_It++){
		Output += *v_It + 48; //It's for fucking casting in ASCII Mode
	}
	return Output;
}


void BigInt::Set_Sign(bool What){
    G_Sign = What;
}

void BigInt::Set_Sign(string& From){
    char Fst_Sign = From[0];
    switch(Fst_Sign){
        case '-' :  G_Sign = false;
                    From.erase(0,1);
                    break;
        case '+' :  G_Sign = true;
                    From.erase(0,1);
                    break;
        default:
                    G_Sign = true;
        }
}

void BigInt::FromString(string& From, bool Rev = true){
    Set_Sign(From);
    try{

    	if(Rev){
	    string::reverse_iterator s_It = From.rbegin();
	    string::reverse_iterator s_ItEnd = From.rend();

 		for( ; s_It != s_ItEnd ; s_It++ ){

            		if(!isdigit(*s_It))
                		throw 89; // 89 is a not numeric character
            		Number.push_back(*s_It-48);
            	}


    	}

    	if(!Rev){
	    string::iterator s_It = From.begin();
	    string::iterator s_ItEnd = From.end();

 		for( ; s_It != s_ItEnd ; s_It++ ){

            		if(!isdigit(*s_It))
                		throw 89; // 89 is a not numeric character
            		Number.push_back(*s_It-48);
            	}

    	}

     }catch(int x){
       	 Catching_Error(x);}
    
    N_Len = Number.size();

}


BigInt BigInt::operator+(BigInt& rhs){
	// What we need first is to see both sign
	// after thet we see the bigger num size
	// and we make some calculation
	// and we return the fucking number
	// stor all the fucking shit in a class Obj
	BigInt Sum_Obj;
	string G_Sum;
	int C_Sum;
	int Carry = 0;


	
	int c_Size = (this->N_len > rhs.N_len)?this->N_len:rhs.N_len;


	if(this->G_Sign && rhs.G_Sign){
		for(int i = 0; i < c_Size; i++){
			C_Sum = this->Number[i] + rhs.Number[i] + Carry;
			Carry = C_Sum / 10;
			C_Sum &= 10;
			G_Sum += C_Sum + 48;
			}
	Sum_Obj.FromString(G_Sum,0);
	}

	if(!this->G_Sign && !rhs.G_Sign){
		for(int i = 0; i < c_Size; i++){
			C_Sum = this->Number[i] + rhs.Number[i] + Carry;
			Carry = C_Sum / 10;
			C_Sum &= 10;
			G_Sum += C_Sum + 48;
			}
	Sum_Obj.Set_Sign(false);
	Sum_Obj.FromString(G_Sum,0);
	}
	//Ya99imach dha mzal khmi G_Sign != rhs.G_sign
	//
}

BigInt BigInt::operator*(BigInt& rhs){
	BigInt Pro_Obj;
	vector<int> Soms;
	vector<int> Lines = 0;


	Pro_Obj.Set_Sign((this->G_Sign==rhs.G_Sign)?1:0);
	for(vector<int>::iterator F_it = this->Number.begin(); F_it != this->Number.end(); F_it++){
		
		int C_Pro = 0;
		int Carry = 0;
		vector<int> Line_Pro = 0;
		
		for(vector<int>::iterator S_it = rhs.Number.begin(); S_it != rhs.Number.end(); S_it++){
			C_Pro = *S_it * *D_it + Carry;
			Carry = C_Pro / 10;
			C_Pro %= 10;
			Line_Pro.push_back(C_Pro);
		}
		unsigned long long Full_Line = 0;
		for(int N = 0; N < Line_Pro.size(); N++){
			Full_Line +=
			//Whata all this fucking shit... think on it
			//its not gonna work... hm I fucked it up
			//
			//think in otherr solution ..; yamalapata
			//aralla yema ralla yemma
			//pf


		
		



void BigInt::Catching_Error(int x) throw(){
    switch(x){
    case 89:
        cerr << endl;
        cerr << "--- Ops!: Error " << x <<endl;
        cerr << "You should enter a valid number."   <<endl;
        break;
    default:
        cerr << endl;
        cerr << "--- Ops!: Error " << x <<endl;
        cerr << "Error not defined. This program will killed..." <<endl;

}
   // exception ok("Fuck");
   //  ok.what(" Fucking shit;");
     //ok.what("Ok bye");
   // throw "Fuck";
  //  errorOut("Whata fuck");
}
