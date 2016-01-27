/*
 * AllClasses.cpp
 *
 *  Created on: 13 gen. 2016
 *      Author: roure
 */


#include "AllClasses.h"

using namespace std;

/**************************************************************************************************
 *
 * BASE CONCRETE
 *
 * *************************************************************************************************/

FatherConcrete::FatherConcrete() {
	fatherName = "Father";
}


FatherConcrete::FatherConcrete(const string & name) {
	fatherName = "Father";
	givenByDerivedName = name;
}

string FatherConcrete::getFatherName() {
	return fatherName;
}

string FatherConcrete::getGivenName() {
	return givenByDerivedName;
}

string FatherConcrete::getName() {
	return fatherName;
}

string FatherConcrete::getNameVirtual() {
	return fatherName;
}

void FatherConcrete::setGivenName(const string &given) {
	givenByDerivedName = given;
}


/**************************************************************************************************
 *
 * DERIVED FROM CONCRETE
 *
 * *************************************************************************************************/

SonFromConcrete::SonFromConcrete(const string &name, const string &givenName) : FatherConcrete(givenName) {
	derivedName = name; //copying names. It's NOT a reference
}

string SonFromConcrete::getName() {
	return derivedName;
}

string SonFromConcrete::getNameVirtual() {
	return derivedName;
}


/**************************************************************************************************
 *
 * BASE ABSTRACT
 *
 * *************************************************************************************************/

FatherAbstract::FatherAbstract() {
	fatherName = "Father";
}


FatherAbstract::FatherAbstract(const string &name) {
	fatherName = "Father";
	givenByDerivedName = name;
}

string FatherAbstract::getFatherName() {
	return fatherName;
}

string FatherAbstract::getGivenName() {
	return givenByDerivedName;
}

string FatherAbstract::getName() {
	return fatherName;
}

string FatherAbstract::getNameVirtual() {
	return fatherName;
}


/**************************************************************************************************
 *
 * DERIVED FROM Abstract
 *
 * *************************************************************************************************/

SonFromAbstract::SonFromAbstract(const string& name, const string& givenName) : FatherAbstract(givenName) {
	derivedName = name; //copying names. It's NOT a reference
}

string SonFromAbstract::getName() {
	return derivedName;
}

string SonFromAbstract::getNameVirtual() {
	return derivedName;
}

string SonFromAbstract::getMessage() {
	return "I'm the son from the abstract super class";
}


/**************************************************************************************************
 *
 * Composition
 *
 * *************************************************************************************************/


//A composed member must be created in the constructor before the "{"
ComposeAggregate::ComposeAggregate(const string &name, const string &givenName): composed(name, givenName) {
	aggregated = NULL; // The aggregated member can be created whenever. Usually outside the class.
}

ComposeAggregate::~ComposeAggregate() {

}

string & ComposeAggregate::toString(string & str) {

	str += "Copmpose name: " + this->getComposed().getNameVirtual() + "\n";
	str += "Aggregated name: " + this->getAggregated()->getNameVirtual() + "\n";

	return str;
}

FatherAbstract * ComposeAggregate::getAggregated() {
	return aggregated;
}

SonFromAbstract & ComposeAggregate::getComposed() {
	return composed;
}


void ComposeAggregate::setAggregated(FatherAbstract *p) {
	aggregated = p;
}

