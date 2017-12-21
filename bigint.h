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
        BigInt();
        void FromString(string& From, bool Reverse = true);
        void Set_Sign(string& From);
        void Set_Sign(bool What);
	string ToString();
	BigInt operator+(BigInt& rhs);



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
