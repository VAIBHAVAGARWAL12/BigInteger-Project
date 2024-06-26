#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <bits/stdc++.h>
using namespace std;

class BigInteger {
    string value;

public:    
    // Constructors
    BigInteger() : value("Empty") {}
    BigInteger(string val) : value(val) {
        reverseValue(); 
    }
    BigInteger(const char* val) : value(val) {
        reverseValue(); 
    }   
    BigInteger(int val) : value(to_string(val)) {
        reverseValue(); 
    }
    BigInteger(long val) : value(to_string(val)) {
        reverseValue(); 
    }
    BigInteger(long long val) : value(to_string(val)) {
        reverseValue(); 
    }

    // Reversing values at initialization
    void reverseValue();

    // Helper Functions
    // Divide by two
    friend BigInteger divideByTwo(const BigInteger &);
    // Binary Search
    friend BigInteger binarySearch(const BigInteger &,const BigInteger &);

    // Post/Pre - Incrementation
    BigInteger &operator++();
    BigInteger operator++(int);
    BigInteger &operator--();
    BigInteger operator--(int);

    // Addition and Subtraction
    friend BigInteger &operator+=(BigInteger &, const BigInteger &);
    friend BigInteger operator+(const BigInteger &, const BigInteger &);
    friend BigInteger &operator-=(BigInteger &, const BigInteger &);
    friend BigInteger operator-(const BigInteger &, const BigInteger &);

    // Comparison operators
    friend bool operator==(const BigInteger &, const BigInteger &);
    friend bool operator!=(const BigInteger &, const BigInteger &);
    friend bool operator>(const BigInteger &, const BigInteger &);
    friend bool operator>=(const BigInteger &, const BigInteger &);
    friend bool operator<(const BigInteger &, const BigInteger &);
    friend bool operator<=(const BigInteger &, const BigInteger &);

    // Multiplication and Division
    friend BigInteger &operator*=(BigInteger &, const BigInteger &);
    friend BigInteger operator*(const BigInteger &, const BigInteger &);
    friend BigInteger &operator/=(BigInteger &, const BigInteger &);
    friend BigInteger operator/(const BigInteger &, const BigInteger &);

    // Modulo
    friend BigInteger &operator%=(BigInteger &, const BigInteger &);
    friend BigInteger operator%(const BigInteger &, const BigInteger &);

    // Input & Output Declaration
    friend istream &operator>>(istream &, BigInteger &);
    friend ostream &operator<<(ostream &, const BigInteger &);
};

void BigInteger::reverseValue() {
    reverse(value.begin(), value.end());
}
// Functions 

/*
-> These function are not required to be created as the orignal function works fine.
-> I didnt know it so i created them...
Min and Max
BigInteger max(const BigInteger &a, const BigInteger &b) {
    return (a > b) ? a : b;
}

BigInteger min(const BigInteger &a, const BigInteger &b) {
    return (a < b) ? a : b;
}

Swap funciton
void swap(BigInteger &objA,BigInteger &objB){
    BigInteger objC = objA;
    objA = objB;
    objB = objC;
}
*/

// Power function
BigInteger pow(BigInteger x, const BigInteger &n){
    BigInteger ans = 1;
    BigInteger nn = n;
    BigInteger two = 2;
    BigInteger one = 1;
    BigInteger zero = 0;
    while(nn>zero){
        if((nn%two) == one){
            ans*=x;
            nn-=one;
        }
        else{
            x*=x;
            nn/=two;
        }
    }
    return ans;
}


// Sqrt function
BigInteger sqrt(const BigInteger &objA){
    BigInteger low = 1;
    BigInteger high = objA;
    BigInteger one = 1;
    while(low<=high){
        BigInteger mid = divideByTwo(low+high);
        BigInteger val = mid*mid;
        if(val <=objA){
            low = mid+one;
        }
        else high = mid-one;
    }
    return high;
}



// Helper Functions
// Divide By Two
BigInteger divideByTwo(const BigInteger &objA){
    BigInteger a = objA;
	int add = 0;
	for (int i = a.value.size() - 1; i >= 0;i--){
		int digit = ((a.value[i]-'0') >> 1) + add;
		add = (((a.value[i]-'0') & 1) * 5);
		a.value[i] = digit+'0';
	}
	while(a.value.size() > 1 && a.value.back() == '0')
		a.value.pop_back();
    return a;    
}

// Binary Search
BigInteger binarySearch(const BigInteger &objA,const BigInteger &objB){
    BigInteger start = 1;
    BigInteger end = objA;
    BigInteger ans = 0;
    BigInteger one = 1;
    while(start<=end){
        BigInteger sum = end+start;
        BigInteger mid = divideByTwo(sum);
        BigInteger multi = objB*mid;
        if(multi<=objA){
            ans = mid;
            start = mid+one;
        }
        else {
            end = mid-one;
        }
    }
    return ans; 
}

//Increment & Decrement
BigInteger &BigInteger::operator++(){
    BigInteger objB = 1;
    *this+=objB;
    return *this;
} 
BigInteger BigInteger::operator++(int) {
    BigInteger temp = *this;
    ++(*this);
    return temp;
}

BigInteger &BigInteger::operator--(){
    BigInteger objB = 1;
    *this-=objB;
    return *this;
}

BigInteger BigInteger::operator--(int){
    BigInteger temp = *this;
    --(*this);
    return temp;
}

// Addition && Subtraction
BigInteger &operator+=(BigInteger &objA, const BigInteger &objB) {
    BigInteger temp = objA + objB;
    objA = temp;
    return objA;
}

BigInteger operator+(const BigInteger &objA, const BigInteger &objB) {
    string a = objA.value;
    string b = objB.value;
    string ans = "";
    int carry = 0;
    
    int maxLength = max(a.size(), b.size());
    for (int i = 0; i < maxLength; ++i) {
        int tempA = (i < a.size()) ? a[i] - '0' : 0;
        int tempB = (i < b.size()) ? b[i] - '0' : 0;
        int sum = tempA + tempB + carry;
        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum + '0');
    }
    if (carry) ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
    BigInteger temp = ans;
    return temp;
}

BigInteger &operator-=(BigInteger &objA, const BigInteger &objB){
    BigInteger temp = objA - objB;
    objA = temp;
    return objA;
}

BigInteger operator-(const BigInteger &objA, const BigInteger &objB) {
    string a = objA.value;
    string b = objB.value;
    if(objA<objB)throw("Negative");
    string ans = "";
    bool carry = false;
    
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        int tempA = (i < a.size()) ? a[i] - '0' : 0;
        int tempB = (i < b.size()) ? b[i] - '0' : 0;
        if (carry) {
            if (tempA == 0) tempA = -1;
            else tempA--;
        }
        carry = tempA < tempB ? 1 : 0;
        if (carry) tempA += 10;
        int val = tempA - tempB;
        char sub = val + '0';
        ans.push_back(sub);
    }
    reverse(ans.begin(), ans.end());
    BigInteger temp = ans;
    return temp;
}


// Comparision
bool operator==(const BigInteger &objA, const BigInteger &objB){
    string a = objA.value;
    string b = objB.value;
    return a == b;
}

bool operator!=(const BigInteger &objA, const BigInteger &objB){
    string a = objA.value;
    string b = objB.value;
    return a != b;
}

bool operator>(const BigInteger &objA, const BigInteger &objB){
    if(objA == objB)return false;
    return !(objA<objB);
}

bool operator>=(const BigInteger &objA, const BigInteger &objB){
    return ((objA == objB) || (objA>objB));
}

bool operator<(const BigInteger &objA, const BigInteger &objB){
    string a = objA.value;
    string b = objB.value;
    int n = a.size();
    int m = b.size();
    if(n>m)return false;
    if(n<m)return true;
    if(a == b)return false;
    else{
        int i = n;
        bool ans = true;
        while(i){
            i--;
            if(a[i]<b[i]){
                break;
            }
            if(a[i]>b[i]){
                ans = false;
                break;
            }
        }
        return ans;
    }
    return false;
}

bool operator<=(const BigInteger &objA, const BigInteger &objB){
    return ((objA == objB) || (objA<objB));
}


// Multiplication and Division
BigInteger &operator*=(BigInteger &objA, const BigInteger &objB){
    BigInteger temp = objA * objB;
    objA = temp;
    return objA;
}

BigInteger operator*(const BigInteger &objA, const BigInteger &objB){
    if(objA.value == '0' || objB.value == '0'){
        BigInteger temp = 0;
        return temp;
    }
    string a  = objA.value;
    string b = objB.value;
    if(objA<objB)swap(a,b);
    int n = a.size();
    int m = b.size();
    vector<int>ans(n+m,0);
    for(int i = 0;i<m;i++){
        int carry = 0;
        int tempB = b[i]-'0';
        int k = i;
        for(int j= 0;j<n;j++){
            int tempA = a[j]-'0';
            int multiply = (tempA*tempB)+carry+ans[k];
            carry = multiply/10;
            ans[k] = multiply%10;
            k++;
        }
        while(carry){
            int multiply = carry+ans[k];
            carry = multiply/10;
            ans[k] = multiply%10;
            k++;
        }
    }
    int i = n+m;
    i--;
    while(ans[i] == 0){
        i--;
    }
    string val = "";
    while(i>=0){
        char ch = ans[i]+'0';
        val.push_back(ch);
        i--; 
    }
    BigInteger temp = val;
    return temp;
}

BigInteger &operator/=(BigInteger &objA, const BigInteger &objB){
    BigInteger temp = objA / objB;
    objA = temp;
    return objA;
}

BigInteger operator/(const BigInteger &objA, const BigInteger &objB){
    if(objB>objA){
        BigInteger temp = 0;
        return temp;
    }
    if(objB.value == '0')throw("Zero Division not possible");
    BigInteger ans = binarySearch(objA,objB);
    return ans;

}

// Modulo
BigInteger &operator%=(BigInteger &objA, const BigInteger &objB){
    BigInteger temp = objA % objB;
    objA = temp;
    return objA;
}
BigInteger operator%(const BigInteger &objA, const BigInteger &objB){
    BigInteger temp = objA/objB;
    BigInteger ans = objA-(objB*temp);
    string a = ans.value;
    int i = a.size()-1;
    while(a[i] == '0')i--;
    string val = "";
    while(i>=0)val.push_back(a[i--]);
    ans = val;
    return ans;
}


// Input & Output Definition
istream &operator>>(istream &in, BigInteger &a) {
    in >> a.value;
    reverse(a.value.begin(), a.value.end());
    return in;
}

ostream &operator<<(ostream &out, const BigInteger &a) {
    for (int i = a.value.size() - 1; i >= 0; i--)
        out << a.value[i];
    return out;
}


#endif // BIGINTEGER_H