// ExceptionHandling.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program aims to showcase modifiable examples of try, throw, catch, terminate(), and unexpected() exception handling.
// Uses both online resources and the slides for reference.
// The point of these is to respond to events that transpire in a function or such through the act of TRYing and THROWING things to CATCH.
// This also includes custom responses to termination and unexpected calls. While my custom terminate function still calls abort() in the end, it still alters the default process by adding a temporary message to explain what happened.
// These allow more flexibility with the program, and helps the developer avoid a broken program that doesn't attempt to fix or dodge errors that users could create intentionally or unintentionally.

#include <iostream>
#include <exception>
using namespace std;

// Just a basic implementation of the try, throw, catch exception handling mentioned, but with a catch all statement instead.
void Xhandler(int test) {
    try {
        if (test == 0) throw test; // throw int
        if (test == 1) throw 'a'; // throw char
        if (test == 2) throw 123.23; // throw double
    }
    catch(...) { // catch all exceptions
        cout << "Error caught!" << endl;
    }
}
// Some throws here will generate terminate() or unexpected(). String was addded for unexpcted(), as it doesn't suit the throw datatypes of int, char, or double.
void Xhandler2(int test) throw(int, char, double) {
    if (test == 0) throw test; // throw int
    if (test == 1) throw 'a'; // throw char
    if (test == 2) throw 123.23; // throw double
    if (test == 3) throw string("woops"); // throw string
}

void myTerminate() {
    cerr << "Terminate Handler Called" << endl;
    abort();
}

void myUnexpected() {
    cerr << "Unexpected Handler Called" << endl;
}



int main()
{
    set_terminate(myTerminate);
    set_unexpected(myUnexpected);
    int test = 0;
    do {
        cout << "Enter test number: " << endl;
        cin >> test;
        Xhandler(test); // catch all
        // The second function that results in different catch messages, and has an instance of terminate() and unexpected() being called depending on the value passed.
        cout << "Start" << endl;
       
        try {
            Xhandler2(3);
        }
        catch(int i) {
            cout << "Caught an integer" << endl;
        }
        catch (char c) {
            cout << "Caught a character" << endl;
        }
        catch (string s) {
            cout << "Exception in main(): " << endl;
        }
        /*catch (double d) {
            cout << "Caught a double" << endl;
        }*/
        
        cout << "End" << endl;
   
    } while (test != 90);
    
}
