#ifndef BIGINT_H
#define BIGINT_H

#include<iostream>
#include<string>
#include<vector>
#include<exception>

using namespace std;


class BigInt
{
    friend istream& operator>>(istream& In,  BigInt& Passed);
    friend ostream& operator<<(ostream& Out, BigInt& Passed);

    public:
        BigInt();//notice to overload this with different type and dont forgot to set len and sign
        void FromString(string& From);
        void FromString(string& From, bool Rev);
        void Del_Fst_Zeros(string& From, bool Rev);
        void Set_Sign(string& From);
        void Set_Sign(bool What);

	string ToString();
	void Del_Fst_Zeros(string& From);

	void FromVector_int(vector<int>& Passed);
	BigInt operator+(BigInt& rhs);
	BigInt operator*(BigInt& rhs);
	BigInt operator-();
 /**   BigInt operator=(BigInt& rhs);**/

        bool Get_Sign() { return G_Sign; }

        vector<int> GetNumber() { return Number; }
        void SetNumber(vector<int> val) { Number = val; }
        unsigned int GetN_Len() { return N_Len; }
        void SetN_Len(unsigned int val) { N_Len = val; }

    protected:
    private:
        bool G_Sign;
        vector<int> Number;
        unsigned int N_Len;
        void Catching_Error(int x) throw();
};

#endif // BIGINT_H
