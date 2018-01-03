#include <iostream>
#include <string>
#include <vector>
#include <exception> /** <- Podha ateth n'hek... but ikhessas rkhadhmeth **/
#include <cstdlib>
#include "bigint.h"

BigInt::BigInt():G_Sign(true)
{
    //Number.push_back(0);
    //N_Len = Number.size();
}
BigInt::BigInt(string Init){
    FromString(Init);}
BigInt::BigInt(vector<int> Init):G_Sign(true){
    FromVector_int(Init);
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
            char ch = *It + 48;/**It's for casting in ASCII Mode**/
            if(!isdigit(ch))
                throw 99;/** It's an internal Error, Nehra ma th'ignorit**/
            Output += ch;
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
            Del_Fst_Zeros(From,1); /** Bash Nehra ma thraghad khikhfanas... ndarit dhi while**/
        }                           /**Rekho dhini lmochkil n Rev, From which is begin?**/
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

        Set_Sign(From); /**Set Sign,  But raja imara togha ghas jiht naghni.. Ala**/
        Del_Fst_Zeros(From, Rev);
    	try{

    		if(Rev){
	    		string::reverse_iterator s_It = From.rbegin();
	    		string::reverse_iterator s_ItEnd = From.rend();

 			for( ; s_It != s_ItEnd ; s_It++ ){

            			if(!isdigit(*s_It)){
                            if(0)
                                continue;
                			throw 89;}
                        Number.push_back(*s_It-48);

            		}


    		}

    		if(!Rev){
	    		string::iterator s_It = From.begin();
	    		string::iterator s_ItEnd = From.end();

 			for( ; s_It != s_ItEnd ; s_It++ ){

            			if(!isdigit(*s_It))
                			throw 89; /**Non digits Error, Wanita ath n ingora.**/
            			Number.push_back(*s_It-48);

            		}

    		}

     	}catch(int x){
       		 Catching_Error(x);}

    	N_Len = Number.size();

}





BigInt BigInt::operator+(BigInt& rhs){
	/** What we need first is to see both sign
	// after that we see the bigger num size
	// and we make some calculation
	// and imara sign wadji kifkif mmch
	// any way fekka dhayas
	// and we return the fucking number
	// store all the fucking shit in a class Obj **/
	static BigInt Sum_Obj;
	string G_Sum;
	int C_Sum=0;
	int Carry = 0;
    int nm1,nm2;
   /** if(this->G_Sign != rhs.G_Sign){
        Sum_Obj = *this - rhs;
        return Sum_Obj;
    }**/

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
	/** Ya99imach dha mzal khmi G_Sign != rhs.G_sign
	**/
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



void BigInt::Sub_Helper(vector<int>& nm1, vector<int>& nm2){
    if (nm1[nm1.size()-1] == nm2.size()-1){
        nm1.pop_back();
        nm2.pop_back();
        Sub_Helper(nm1,nm2);
    }
    }





BigInt BigInt::operator-(BigInt& rhs){
    BigInt G_Sub;
   /** if(!rhs.Get_Sign()){
        BigInt nm2 = rhs;
        nm2.Set_Sign(1);
        G_Sub = *this + rhs;
        return G_Sub;
    }**/
    vector<int> nm1 = this->GetNumber();
    vector<int> nm2 = rhs.GetNumber();
    bool rhsFlag = 0;
    bool thisFlag = 0;
    vector<int> res;
    vector<int> Bigger;
    if (nm1.size() == nm2.size()){
        Sub_Helper(nm1,nm2);
        if(nm1[nm1.size()-1] > nm2.size()-1){
            Bigger = nm1;
            thisFlag = 1;
        }else{
            Bigger = nm2;
            rhsFlag = 1;}
        }
    else if(nm1.size()>nm2.size()){
            Bigger = nm1;
            thisFlag = 1;
            }
    else{
            Bigger = nm2;
            rhsFlag = 1;
        }

    vector<int> Smaller = (Bigger == nm1)?nm2:nm1;
    int Swaday = 0;
    int Sennej = 0;
    int Sub = 0;
    int smlr;
    for(int i =0; i<Bigger.size(); i++){
            Sub  = 0;
            Sennej = 0;
            if(i < Smaller.size()){
                smlr = Smaller[i];
            }else{
                smlr = 0;
                }
            smlr += Swaday;
            if(smlr <= Bigger[i]){
            res.push_back(Bigger[i] - smlr);
            Swaday = 0;
            }else{
            res.push_back(Bigger[i] + 10 - smlr);
            Swaday = 1;
            }
    }
    if (rhsFlag){
        G_Sub.Set_Sign(0);
    }
    G_Sub.FromVector_int(res);
    return G_Sub;




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

bool BigInt::operator<(BigInt& rhs){
    bool lpos = this->Get_Sign();
    bool rpos = rhs.Get_Sign();
    if(lpos && !rpos){
        return false;}
    if(!lpos && rpos){
        return true;}
    if(this->GetN_Len() > rhs.GetN_Len()){
        return lpos ? false : true;}
    if(this->GetN_Len() < rhs.GetN_Len()){
        return lpos ? true : false;}
    vector<int> n1 = this->GetNumber();
    vector<int> n2 = rhs.GetNumber();
    while(n1.back() == n2.back()){
        n1.pop_back();
        n2.pop_back();
    }
    if(n1.back() < n2.back()){
            return lpos ? true : false;}
    if(n1.back() > n2.back()){
            return lpos ? false : true;}

    return false;
}

bool BigInt::operator<=(BigInt& rhs){
    bool lpos = this->Get_Sign();
    bool rpos = rhs.Get_Sign();
    if(lpos && !rpos){
        return false;}
    if(!lpos && rpos){
        return true;}
    if(this->GetN_Len() > rhs.GetN_Len()){
        return lpos ? false : true;}
    if(this->GetN_Len() < rhs.GetN_Len()){
        return lpos ? true : false;}
    vector<int> n1 = this->GetNumber();
    vector<int> n2 = rhs.GetNumber();
    while(n1.back() == n2.back()){
        n1.pop_back();
        n2.pop_back();
    }
    if(n1.back() < n2.back()){
            return lpos ? true : false;}
    if(n1.back() > n2.back()){
            return lpos ? false : true;}

    return true;
}

bool BigInt::operator>(BigInt& rhs){
    bool lpos = this->Get_Sign();
    bool rpos = rhs.Get_Sign();
    if(lpos && !rpos){
        return true;}
    if(!lpos && rpos){
        return false;}
    if(this->GetN_Len() > rhs.GetN_Len()){
        return lpos ? true : false;}
    if(this->GetN_Len() < rhs.GetN_Len()){
        return lpos ? false : true;}
    vector<int> n1 = this->GetNumber();
    vector<int> n2 = rhs.GetNumber();
    while(n1.back() == n2.back()){
        n1.pop_back();
        n2.pop_back();
    }
    if(n1.back() < n2.back()){
            return lpos ? false : true;}
    if(n1.back() > n2.back()){
            return lpos ? true : false;}

    return false;
}

bool BigInt::operator>=(BigInt& rhs){
    bool lpos = this->Get_Sign();
    bool rpos = rhs.Get_Sign();
    if(lpos && !rpos){
        return true;}
    if(!lpos && rpos){
        return false;}
    if(this->GetN_Len() > rhs.GetN_Len()){
        return lpos ? true : false;}
    if(this->GetN_Len() < rhs.GetN_Len()){
        return lpos ? false : true;}
    vector<int> n1 = this->GetNumber();
    vector<int> n2 = rhs.GetNumber();
    while(n1.back() == n2.back()){
        n1.pop_back();
        n2.pop_back();
    }
    if(n1.back() < n2.back()){
            return lpos ? false : true;}
    if(n1.back() > n2.back()){
            return lpos ? true : false;}

    return true;
}


bool BigInt::operator==(BigInt& rhs){
    string left = this->ToString();
    string right = this->ToString();
    if(!left.compare(right))
        return true;
    return false;
}
bool BigInt::operator!=(BigInt& rhs){
    string left = this->ToString();
    string right = this->ToString();
    if(left.compare(right))
        return true;
    return false;
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
}

