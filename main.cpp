#include <iostream>
#include "bigint.h"
#include <exception>
using namespace std;

int main()
{   string ok = "999";
	BigInt a1;
//	a1.FromString(ok,true);
    cout <<"Enter valid number:"<<endl <<"-> ";
	cin >> a1;
	BigInt a2;
	//a2.FromString(ok,true);
	cout <<"Enter valid number:"<<endl <<"-> ";
	cin >> a2;
	BigInt a3 = a1 * a2;
	//a3 ;
	cout << "length "<<a3.GetN_Len()<<" sign " <<a3.Get_Sign()<<endl;
	cout << a1 << " * " << a2 <<" = " << a3<<endl;
	BigInt a4 = a1 + a2;
	cout <<endl<< "length "<<a4.GetN_Len()<<" sign " <<a4.Get_Sign()<<endl;
	cout << a1 << " + " << a2 <<" = " << a4<<endl;
	//BigInt a5 = -a1;
	//cout <<endl<< "length "<<a5.GetN_Len()<<" sign " <<a5.Get_Sign()<<endl;
	//cout<< a5 << endl;

	//cout<< a3.GetN_Len()<<endl;
	//a3 = a1 + a2;
	//a3 ;
	//cout << "length "<<a3.GetN_Len()<<" sign " <<a3.Get_Sign()<<endl;
	//cout << a1 << " + " << a2 <<" = " << a3;


    return 0;
}
