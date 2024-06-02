#include "BigInteger.h"

int main() {
    // Increment & Decrement
    BigInteger increment = 5;
    cout << "Value before Increment: " << increment << endl;
    increment++;
    ++increment;
    cout << "Value after Increment: " << increment << endl << endl;

    BigInteger decrement = 7;
    cout << "Value before Decrement: " << decrement << endl;
    decrement--;
    --decrement;
    cout << "Value after Decrement: " << decrement << endl << endl<<endl;

    // Arithmetic Operations
    // Addition and Subtraction
    cout<<"Arithmetic Operations:"<<endl;
    BigInteger add1 = 9999998747;
    BigInteger add2 = 7783403478;
    cout << "Addition: " <<endl;
    cout<<add1<<" + "<<add2<<": "<< add1 + add2 << endl;
    add1 += add2;
    cout << "After Addition with Compound Assignment: " << add1 << endl << endl;

    BigInteger subtract1 = 88534434;
    BigInteger subtract2 = 555443;
    cout << "Subtraction: " <<endl;
    cout<<subtract1<<" - "<<subtract2<<": "<< subtract1 - subtract2 << endl;
    subtract1 -= subtract2;
    cout << "After Subtraction with Compound Assignment: " << subtract1 << endl << endl;

    // Multiplication
    BigInteger multiply1 = 1234;
    BigInteger multiply2 = 5678;
    cout << "Multiplication: " <<endl;
    cout<<multiply1<<" * "<<multiply2<<": "<< multiply1 * multiply2 << endl;
    multiply1 *= multiply2;
    cout << "After Multiplication with Compound Assignment: " << multiply1 << endl << endl;

    // Division
    BigInteger div1 = 9876543210;
    BigInteger div2 = 1234;
    cout << "Division: " <<endl;
    cout<<div1<<" / "<<div2<<": "<< div1 / div2 << endl;
    div1 /= div2;
    cout << "After Division with Compound Assignment: " << div1 << endl << endl;

    // Modulo
    BigInteger mod1 = 100;
    BigInteger mod2 = 3;
    cout << "Modulo: " <<endl;
    cout<<mod1<<" % "<<mod2<<": "<< mod1 % mod2 << endl;
    mod1 %= mod2;
    cout << "After Modulo with Compound Assignment: " << mod1 << endl << endl<<endl;

    // Comparison operators
    BigInteger comp1 = 12345;
    BigInteger comp2 = 54321;
    cout << "Comparison: " << endl;
    cout <<comp1<< " == "<< comp2<< ": " << (comp1 == comp2) << endl;
    cout <<comp1<< " != "<< comp2<< ": " << (comp1 != comp2) << endl;
    cout <<comp1<< " > "<< comp2<< ": " << (comp1 > comp2) << endl;
    cout <<comp1<< " >= "<< comp2<< ": " << (comp1 >= comp2) << endl;
    cout <<comp1<< " < "<< comp2<< ": " << (comp1 < comp2) << endl;
    cout <<comp1<< " <= "<< comp2<< ": " << (comp1 <= comp2) << endl;
    cout<<endl<<endl;

    cout<<"Functions: "<<endl;
    // Sqrt
    BigInteger sqrt1 = 16;
    cout << "Square Root of 16: " << sqrt(sqrt1) << endl;

    // Power
    BigInteger base = 2;
    BigInteger power = 10;
    cout << "Power: " << pow(base, power) << endl<<endl;

    // Swap
    BigInteger swap1 = 10;
    BigInteger swap2 = 20;
    cout << "Before Swap: swap1 = " << swap1 << ", swap2 = " << swap2 << endl;
    swap(swap1, swap2);
    cout << "After Swap: swap1 = " << swap1 << ", swap2 = " << swap2 << endl<<endl;

    // Sorting
    vector<BigInteger> numbers = {321, 123, 543, 234};
    cout << "Before Sorting: ";
    for (const auto &num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    sort(numbers.begin(), numbers.end());
    cout << "After Sorting: ";
    for (const auto &num : numbers) {
        cout << num << " ";
    }
    cout << endl<<endl;

    // Min and Max
    BigInteger minNum = min(BigInteger(10), BigInteger(20));
    BigInteger maxNum = max(BigInteger(10), BigInteger(20));
    cout << "Min: " << minNum << endl;
    cout << "Max: " << maxNum << endl;
}
