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
//   friend Argements; //bach azayas nissi Argements
//friend Argements Biggy;

    public:
        BigInt();/**notice to overload this with few different type and dont forget to set len and sign**/
        BigInt(string init);
        BigInt(vector<int> init);
        void FromString(string& From);
        void FromString(string& From, bool Rev);
        void Del_Fst_Zeros(string& From, bool Rev);
        void Set_Sign(string& From);
        void Set_Sign(bool What);
        void Sub_Helper(vector<int>& nm1, vector<int>& nm2);
        void FromVector_int(vector<int>& Passed);
        void Del_Fst_Zeros(string& From);
        void SetNumber(vector<int> val) { Number = val; }
        void SetN_Len(unsigned int val) { N_Len = val; }




        BigInt operator+(BigInt& rhs);
        BigInt operator-(BigInt& rhs);
        BigInt operator*(BigInt& rhs);
        BigInt operator-();
 /**   BigInt operator=(BigInt& rhs);**/

        bool Get_Sign() { return G_Sign; }
        string ToString();
        vector<int> GetNumber() { return Number; }
        unsigned int GetN_Len() { return N_Len; }


        bool operator<(BigInt& rhs);
        bool operator>(BigInt& rhs);
        bool operator<=(BigInt& rhs);
        bool operator>=(BigInt& rhs);
        bool operator==(BigInt& rhs);
        bool operator!=(BigInt& rhs);




    private:
        bool G_Sign;
        vector<int> Number;
        unsigned int N_Len;
        void Catching_Error(int x) throw();
};

#endif // BIGINT_H
