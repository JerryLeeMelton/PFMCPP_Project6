/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

#include <iostream>
#include <string>
struct T
{
    int value;                //2
    std::string name;         //3

    T(int v, const char* n) :   //1
    value(v), 
    name(n)
    {

    }
};

struct Comparer                               //4
{ 
    T* compare(T& a, T& b) //5
    {
        if(a.value > b.value) 
        {
            return &a;
        }
        else 
        {
            return &b;
        }
    }
};

struct U
{
    float valueOne { 0 }, valueTwo { 0 };

    float updateValues(float& updatedValue)      //12
    {
        std::cout << "U's valueOne value: " << valueOne << std::endl;
        valueOne = updatedValue;
        std::cout << "U's valueOne updated value: " << valueOne << std::endl;
        while(std::abs(valueTwo - valueOne) > 0.001f)
        {
            valueTwo -= (valueTwo - valueOne) / 2;
        }
        std::cout << "U's valueTwo updated value: " << valueTwo << std::endl;
        return valueOne * valueTwo;
    }
};

struct UUpdater
{
    static float updateUValues(U& that, float& updatedValue)
    {
        std::cout << "U's valueOne value: " << that.valueOne << std::endl;
            that.valueOne = updatedValue;
            std::cout << "U's valueOne updated value: " << that.valueOne << std::endl;
            while( std::abs(that.valueTwo - that.valueOne) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
                that.valueTwo -= (that.valueTwo - that.valueOne) / 2;
            }
            std::cout << "U's valueTwo updated value: " << that.valueTwo << std::endl;
            return that.valueOne * that.valueTwo;
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
    T thingOne( 10, "Thing 1");                                             //6
    T thingTwo( 20, "Thing 2");                                             //6
    
    Comparer f;                                            //7
    auto* smaller = f.compare(thingOne, thingTwo);                              //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << UUpdater::updateUValues(u1, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.updateValues(updatedValue) << std::endl;
}
