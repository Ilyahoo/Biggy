#include<iostream>
#include<string>
#include<vector>
#include <exception>
#include <cstdlib>

#include "bigint.h"

BigInt::BigInt():G_Sign(true)
{
    //Number.push_back(0);
    //N_Len = Number.size();
}


istream& operator>>(istream& In,  BigInt& Passed){
            string Input_Str;
            In >> Input_Str;
            Passed.FromString(Input_Str);
            return In;
}


ostream& operator<<(ostream& Out, BigInt& Passed){
	string Output;
	if (!Passed.Get_Sign())
        Output += '-';
	Output += Passed.ToString();
	Out << Output;
	return Out;
}





string BigInt::ToString(){
	string Output;
	try{
        for(vector<int>::reverse_iterator It = Number.rbegin(); It != Number.rend(); It++){
            char ch = *It + 48;
            if(!isdigit(ch))
                throw 99;
            Output += ch; //It's for fucking casting in ASCII Mode
        }
	}catch(int x){
	    Catching_Error(x);}
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
                    break;
        }
    //return From;
}




void BigInt::FromString(string& From){
    FromString(From,1);
    }
void BigInt::Del_Fst_Zeros(string& From,bool Rev){
    if(Rev){
        string::iterator Wt = From.begin();
        if(*Wt=='0' && From.size()!=1){
            From.erase(Wt);
            Del_Fst_Zeros(From,1);
        }
    }
    else{
        string::iterator Wt = From.end();
        if(*Wt=='0' && From.size()!=1){
            From.erase(Wt-1);
            Del_Fst_Zeros(From,0);
        }
    }
}
void BigInt::FromString(string& From, bool Rev ){

        Set_Sign(From); //set sign imara togha rasss fuck fuck fuck sign jiht noghirin
        Del_Fst_Zeros(From, Rev);
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
	static BigInt Sum_Obj;
	string G_Sum;
	int C_Sum=0;
	int Carry = 0;
    int nm1,nm2;
	//wow wow wow
	//mana degga
	//adhrmohar ma achyadhaf gha rhs.number
	//manis tfakadh pffff
	//kemmer th compilidh th fitchadh

	int c_Size = (this->N_Len > rhs.N_Len)?this->N_Len:rhs.N_Len;

		for( int i = 0; i <= c_Size; i++){
                if(i==c_Size && Carry == 0)
                    break;

                if(i < this->N_Len){
                        nm1 = this->Number[i];
                }else{
                        nm1 = 0;
                        }
                if(i < rhs.N_Len){
                        nm2 = rhs.Number[i];
                }else{
                        nm2=0;
                        }



			C_Sum = nm1 + nm2 + Carry;
			Carry = C_Sum / 10;
			C_Sum %= 10;
			G_Sum += (C_Sum+48);
			}
    if(this->G_Sign && rhs.G_Sign){
	Sum_Obj.FromString(G_Sum,0);
	Sum_Obj.Set_Sign(1);
	}

	if(!this->G_Sign && !rhs.G_Sign){
	Sum_Obj.FromString(G_Sum,0);
	Sum_Obj.Set_Sign(0);
	}
	//Ya99imach dha mzal khmi G_Sign != rhs.G_sign
	//
	return Sum_Obj;
}




BigInt BigInt::operator*( BigInt& rhs)  {


    static BigInt Pro_Obj;
	unsigned long long C_Pro, Carry;
	unsigned long long Pre_Carry = 0;
	vector<int> G_Pro;
	int len_Vect1 = this->GetN_Len(), len_Vect2 = rhs.GetN_Len();
	int Total_Len = len_Vect1 + len_Vect2;

    if (this->Number[0] == 0 || rhs.Number[0]==0){
        Pro_Obj.Number.push_back(0);
        Pro_Obj.SetN_Len(1);
        Pro_Obj.Set_Sign(true);

        return Pro_Obj;
        }

	for(int i = 0; i < Total_Len; i++){

		C_Pro = 0;
		Carry = 0;
		for(int j = 0; j < len_Vect2; j++){


			if( j < rhs.Number.size() && i-j < this->Number.size() ){
				C_Pro += (rhs.Number[j]) * (this->Number[i-j]);
			}
		}
		C_Pro += Pre_Carry;
		if( C_Pro >= 10){
			Carry = C_Pro / 10;
			C_Pro %= 10;
		}

		if( !( i == Total_Len-1 && C_Pro == 0) ){
			G_Pro.push_back(C_Pro);
		}
		Pre_Carry = Carry;
	}

	Pro_Obj.FromVector_int(G_Pro);

	if( this->G_Sign == rhs.Get_Sign() ){
		Pro_Obj.Set_Sign(1);
	}
	else{
		Pro_Obj.Set_Sign(0);
	}

    return Pro_Obj;

}

/**BigInt BigInt::operator=(BigInt& rhs){
    this->Number.clear();
    this->Set_Sign(rhs.Get_Sign());
    this->SetN_Len(rhs.GetN_Len());
    this->FromVector_int(rhs.GetNumber());
    return *this;
    }**/



BigInt BigInt::operator-(){
    BigInt Res = *this;
    Res.Set_Sign(!G_Sign);
    return Res;
    }

void BigInt::FromVector_int(vector<int>& Passed){

    this->Number = Passed;
	this->N_Len = Number.size();
}


void BigInt::Catching_Error(int x) throw(){
     cerr << endl;
    cerr << "---> Ops!: Error " << x <<endl;
    switch(x){
    case 89:
        cerr << "\tYou should enter a valid number."   <<endl;
        break;
    case 99:
        cerr << "\tInternal value should be a digit."   <<endl;
        break;
    default:
        cerr << "\tError not defined. This program will killed..." <<endl;


}
    exit(x);
   // exception ok("Fuck");
   //  ok.what(" Fucking shit;");
     //ok.what("Ok bye");
   // throw "Fuck";
  //  errorOut("Whata fuck");
}

