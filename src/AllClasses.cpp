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
	nameGivenBySon = name;
}

string FatherConcrete::getFatherName() {
	return fatherName;
}

string FatherConcrete::getGivenName() {
	return nameGivenBySon;
}

string FatherConcrete::getName() {
	return fatherName;
}

string FatherConcrete::getNameVirtual() {
	return fatherName;
}

void FatherConcrete::setGivenName(const string &given) {
	nameGivenBySon = given;
}


/**************************************************************************************************
 *
 * DERIVED FROM CONCRETE
 *
 * *************************************************************************************************/

SonFromConcrete::SonFromConcrete(const string &name, const string &givenName) : FatherConcrete(givenName) {
	sonsName = name; //copying names. It's NOT a reference
}

string SonFromConcrete::getName() {
	return sonsName;
}

string SonFromConcrete::getNameVirtual() {
	return sonsName;
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
	nameGivenBySon = name;
}

string FatherAbstract::getFatherName() {
	return fatherName;
}

string FatherAbstract::getGivenName() {
	return nameGivenBySon;
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
	sonsName = name; //copying names. It's NOT a reference
}

string SonFromAbstract::getName() {
	return sonsName;
}

string SonFromAbstract::getNameVirtual() {
	return sonsName;
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
	aggregated = NULL; // The aggregated member can be created wherever. Usually outside the class.
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

