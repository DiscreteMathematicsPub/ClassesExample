//============================================================================
// Name        : ClassesExample.cpp
// Author      : Josep
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "AllClasses.h"
using namespace std;

int main() {


	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!


	/**********************************************
	 *     Value, reference, pointers. Coping objects
	 *********************************************/
	FatherConcrete father_A ("Given father A");		// This declares and creates an object of class FatherConcrete

	FatherConcrete &superClassReference = father_A;  //A reference to a class. Object not copied. Note that a reference MUST be initialized at declaration time
	FatherConcrete *superClassPointer; 				 //A pointer to a class. Object not copied
	FatherConcrete superClassCopy;

	superClassPointer = &father_A;		//Initialize pointer
	superClassCopy = father_A;			//The object father_A is copied into object superClassCopy. Usually operator = should be redefined. Use it carefully

	cout << "ORIGINAL  name: " << father_A.getFatherName() << ", Given Name: " << father_A.getGivenName() << endl;
	cout << "REFERENCE name: " << superClassReference.getFatherName() << ", Given Name: " << superClassReference.getGivenName() << endl;
	cout << "POINTER   name: " << superClassPointer->getFatherName() << ", Given Name: " << superClassPointer->getGivenName() << endl;
	cout << "COPY      name: " << superClassCopy.getFatherName() << ", Given Name: " << superClassCopy.getGivenName() << endl;
	cout << endl;

	//Change value of father_A and see what happens
	father_A.setGivenName("changed");
	cout << "ORIGINAL  name: " << father_A.getFatherName() << ", Given Name: " << father_A.getGivenName() << endl;
	cout << "REFERENCE name: " << superClassReference.getFatherName() << ", Given Name: " << superClassReference.getGivenName() << endl;
	cout << "POINTER   name: " << superClassPointer->getFatherName() << ", Given Name: " << superClassPointer->getGivenName() << endl;
	cout << "COPY      name: " << superClassCopy.getFatherName() << ", Given Name: " << superClassCopy.getGivenName() << endl;
	cout << endl;

	//Define and instantiate a pointer to an object class
	FatherConcrete * fc = new FatherConcrete("Father");
	cout << "POINTER   name: " << fc->getFatherName() << "\n\n";
	delete fc; // IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	/********************************************
	 *    Derived class example
	 ********************************************/
	SonFromConcrete son_A("Son A", "Given son A");

	cout << "Using son object A" << endl;
	cout << "Father name: " << son_A.getFatherName() << ", Given Name: " << son_A.getGivenName()
			<< ", Son's Name: " << son_A.getName() << ", Son's Name Virtual: " << son_A.getNameVirtual()<< endl;
	cout << endl;


	/********************************************
	 *    Polymorphism Example
	 ********************************************/
	// Polymorfism can only be achived with pointers or references
	FatherConcrete *polyPointer;			//Polymorphism with pointer
	FatherConcrete &polyReference = son_A;	//Polymorphism with reference. Note that a reference must be initialized at declaration time

	polyPointer = &son_A;

	cout << "Using Polymorphism" << endl;
	cout << "POLY POINTER   Father's name: " << polyPointer->getFatherName() << ", Given Name: " << polyPointer->getGivenName()
			<< ", Son's Name: " << polyPointer->getName() << ", Son's Name Virtual: " << polyPointer->getNameVirtual()<< endl;
	cout << "POLY REFERENCE Father's name: " << polyReference.getFatherName() << ", Given Name: " << polyReference.getGivenName()
			<< ", Son's Name: " << polyReference.getName() << ", Son's Name Virtual: " << polyReference.getNameVirtual()<< endl;
	cout << " *** In order to avoid surprises and have C++ work as Java does, declare all methods virtual ***" << endl;
	cout << endl;


	/********************************************
	 *    Polymorphism with abstract class. Working with references
	 ********************************************/
	SonFromAbstract sonAbs("Son Abs", "Given son Abs");
	FatherAbstract &polyAbs = sonAbs;

	cout << "Using Polymorphism with references: abstract class" << endl;
	cout << "POLYM Father name: " << polyAbs.getFatherName() << ", Given Name: " << polyAbs.getGivenName()
			<< ", Son's Name: " << polyAbs.getName() << ", Son's Name Virtual: " << polyAbs.getNameVirtual()<< endl;
	cout << endl;

	//error: Cannot create an object of an abstract class. Uncomment the following line in order to see the compiler error message
	//FatherAbstract fail("hola");


	/********************************************
	 *    Polymorphism with abstract class. Working with pointers
	 ********************************************/
	FatherAbstract *polyAbsPt;

	polyAbsPt = new SonFromAbstract("Son Abs pointer", "Given son Abs");
	cout << "Using Polymorphism with pointers: abstract class" << endl;
	cout << "POLYM Father name: " << polyAbsPt->getFatherName() << ", Given Name: " << polyAbsPt->getGivenName()
			<< ", Son's Name: " << polyAbsPt->getName() << ", Son's Name Virtual: " << polyAbsPt->getNameVirtual()<< endl;
	cout << endl;

	delete polyAbsPt; // IMPORTANT: we need to delete the object before we end or we loose reference to the object


	/********************************************
	 *    Composition & Aggregation
	 ********************************************/

	ComposeAggregate *c = new ComposeAggregate("Composed", "Given composed");

	FatherAbstract * agg = new SonFromAbstract("Aggregated", "Given aggregated");
	c->setAggregated(agg);

	string s("");
	cout << c->toString(s);

	delete agg;
	delete c;


	PrintMemoryLeakInfo();
	return 0;
}
