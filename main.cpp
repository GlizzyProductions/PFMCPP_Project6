/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types ***>>> WHERE POSSIBLE <<<***
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference and don't change the return type either.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    int value;
    std::string name;

    T(int v, const char* charA) :    
    value(v),
    name(charA)
    {
        
    }
};

struct Comparison
{
    T* compare(T& a, T& b)
    {
        //if(a != nullptr && b != nullptr)
        {
            if( a.value < b.value ) return &a;
            if( a.value > b.value ) return &b;
        }
        return nullptr;
    }
};

struct U
{
    float num1 { 0 }, num2 { 0 };
    float updateNums(const float& updated)      //12
    {
        //if(updated != nullptr)
        {
            std::cout << "U's num1 value: " << num1 << std::endl;
            num1 = updated;
            std::cout << "U's num1 updated value: " << num1 << std::endl;
        
            while( std::abs(num2 - num1) > 0.001f )
            {
                num2 += 1.f;
            }
            std::cout << "U's num2 updated value: " << num2 << std::endl;
        }   
        return num2 * num1;
    }
};

struct UpdateThat
{
    static float updateNums(U& that, const float& updated )        //10
    {
        //if(that != nullptr && updated != nullptr)
        {
            std::cout << "U's num1 value: " << that.num1 << std::endl;
            that.num1 = updated;
            std::cout << "U's num1 updated value: " << that.num1 << std::endl;
        
            while( std::abs(that.num2 - that.num1) > 0.001f )
            {
                that.num2 += 1.f;
            }
            std::cout << "U's num2 updated value: " << that.num2 << std::endl;
        }
        return that.num2 * that.num1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T one(1, "a");                                             //6
    T two(2, "b");                                             //6
    
    Comparison f;                                            //7
    auto* smaller = f.compare(one, two);                              //8
    if(smaller == nullptr)
    {
        std::cout << "T one & T two are equal \n";//9
    }
    else
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; 
    }
    
    U uFirst;
    float updatedValue = 5.f;
    std::cout << "updateNums uFirst's multiplied values: " << UpdateThat::updateNums(uFirst, updatedValue ) << std::endl;                  //11
    
    U uSecond;
    std::cout << "updateNums uSecond's multiplied values: " << uSecond.updateNums(updatedValue) << std::endl;
}
