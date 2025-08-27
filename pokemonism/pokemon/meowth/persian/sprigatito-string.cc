/**
 * @file        pokemon/meowth/persian/sprigatito-string.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

// ReSharper disable All
#include <pokemon/sprigatito/string.hh>

using namespace pokemon::sprigatito;

void stringConstructorCheck(void);
void stringOperatorSetCheck(void);
void stringSizeCheck(void);
void stringLengthCheck(void);
void stringMaxCheck(void);
void stringShrinkCheck(void);
void stringOperatorAtCheck(void);
void stringOperatorCatCheck(void);
void stringCatCheck(void);
void stringSetCheck(void);
void stringEraseCheck(void);
void stringReplaceCheck(void);

int main(int argc, char ** argv) {

    try {
        stringConstructorCheck();
        stringOperatorSetCheck();
        stringSizeCheck();
        stringLengthCheck();
        stringMaxCheck();
        stringShrinkCheck();
        stringOperatorAtCheck();
        stringOperatorCatCheck();
        stringCatCheck();
        stringSetCheck();
        stringEraseCheck();
        stringReplaceCheck();
    } catch (const pokemon::exception & o) {
        printf("%s\n", o.msg());
    }

    return 0;
}


void stringConstructorCheck(void) {
    string s0("Initial string");


    string s1;

    string s2(s0);
    string s3(s0, 8, 3);
    string s4("A character sequence");
    string s5("Another character sequence", 12);
    string s6a(10, 'x');
    string s6b(10, 42);

    // TODO: CHARACTER ITERATOR TO STRING `std::string s7 (s0.begin(), s0.begin()+7);`

    std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
    std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
    std::cout << "\ns6b: " << s6b << "\n";
    // std::cout << "\ns6b: " << s6b << "\ns7: " << s7 << '\n';
}

void stringOperatorSetCheck(void) {
    string str1, str2, str3;
    str1 = "Test string: ";   // c-string
    str2 = 'x';               // single character
    str3 = str1 + str2;       // string

    std::cout << str3  << '\n';
}

void stringSizeCheck(void) {
    string str ("Test string");
    std::cout << "The size of str is " << str.size() << " bytes.\n";
}

void stringLengthCheck(void) {
    string str ("Test string");
    std::cout << "The size of str is " << str.length() << " bytes.\n";
}

void stringMaxCheck(void) {
    string str ("Test string");
    std::cout << "size: " << str.size() << "\n";
    std::cout << "length: " << str.length() << "\n";
    std::cout << "capacity: " << str.capacity() << "\n";
    std::cout << "max_size: " << str.maximum() << "\n";
}

void stringShrinkCheck(void) {
    string str (100,'x');
    std::cout << "1. capacity of str: " << str.capacity() << '\n';

    str.cut(10);
    std::cout << "2. capacity of str: " << str.capacity() << '\n';

    str.shrink();
    std::cout << "3. capacity of str: " << str.capacity() << '\n';
}

void stringOperatorAtCheck(void) {
    string str ("Test string");
    for (int i=0; i < str.length(); ++i)
    {
        std::cout << str[i];
    }
    std::cout << std::endl;

    {
        string str ("Test string");
        for (int i=0; i < str.length(); ++i)
        {
            std::cout << str.at(i);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void stringOperatorCatCheck(void) {
    string name ("John");
    string family ("Smith");
    name += " K. ";         // c-string
    name += family;         // string
    name += '\n';           // character

    std::cout << name;
}

void stringCatCheck(void) {
    string str;
    string str2("Writing ");
    string str3("print 10 and then 5 more");

    // used in the same order as described above:
    str.cat(str2);                       // "Writing "
    std::cout << str << '\n';
    str.cat(str3,6,3);                   // "10 "
    std::cout << str << '\n';
    str.cat("dots are cool",5);          // "dots "
    std::cout << str << '\n';
    str.cat("here: ");                   // "here: "
    std::cout << str << '\n';
    str.cat('.', 10u);                    // ".........."
    std::cout << str << '\n';
    // str.cat(str3.begin()+8,str3.end());  // " and then 5 more"
    str.cat(0x2E, 5);                // "....."

    std::cout << str << '\n';
}

void stringSetCheck(void) {
    string str;
    string base("The quick brown fox jumps over a lazy dog.");

    // used in the same order as described above:

    str.set(base);
    std::cout << str << '\n';

    str.set(base,10,9);
    std::cout << str << '\n';         // "brown fox"

    str.set("pangrams are cool",7);
    std::cout << str << '\n';         // "pangram"

    str.set("c-string");
    std::cout << str << '\n';         // "c-string"

    str.set("*", 10);
    std::cout << str << '\n';         // "**********"

    str.set(0x2D, 10);
    std::cout << str << '\n';         // "----------"

    // str.assign(base.begin()+16,base.end()-12);
    std::cout << str << '\n';         // "fox jumps over"
}

void stringEraseCheck(void) {
    string str ("This is an example sentence.");
    std::cout << str << '\n';
    // "This is an example sentence."
    str.rem (10, 8);                        //            ^^^^^^^^
    std::cout << str << '\n';
    // "This is an sentence.
}

void stringReplaceCheck(void) {
    string base("this is a test string.");
    string str2("n example");
    string str3("sample phrase");
    string str4("useful.");

    // replace signatures used in the same order as described above:

    // Using positions:                 0123456789*123456789*12345
    string str(base);           // "this is a test string."
    str.mod(9,5,str2);          // "this is an example string." (1)
    std::cout << str << std::endl;
    str.mod(19,6,str3,7,6);     // "this is an example phrase." (2)
    std::cout << str << std::endl;
    str.mod(8,10,"just a");     // "this is just a phrase."     (3)
    std::cout << str << std::endl;
    str.mod(8,6,"a shorty",7);  // "this is a short phrase."    (4)
    std::cout << str << std::endl;
    str.mod(22,1,'!', 3);        // "this is a short phrase!!!"  (5)
    std::cout << str << std::endl;

}