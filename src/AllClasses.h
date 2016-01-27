/*
 * AllClasses.h
 *
 *  Created on: 13 gen. 2016
 *      Author: roure
 */

#ifndef ALLCLASSES_H_
#define ALLCLASSES_H_

#include <string>

#include "cppMemDbg.h"

using namespace std;

class FatherConcrete {
private:
	string fatherName;
	string givenByDerivedName;

public:
	FatherConcrete();
	FatherConcrete(const string &name);
	virtual ~FatherConcrete() {}; // virtual empty destructor

	string getFatherName();
	string getGivenName();
	string getName();
	virtual string getNameVirtual();
	virtual void setGivenName(const string &given);
};

class SonFromConcrete: virtual public FatherConcrete { // it's recommended to derive virtually always to avoid future problems with multiple inheritance
private:
	string derivedName;

public:
	SonFromConcrete(const string &name, const string &givenName);
	string getName();
	virtual string getNameVirtual();
};


/*
 *  ABSTRACT CLASS DEFINITION
 */
class FatherAbstract {
private:
	string fatherName;
	string givenByDerivedName;

public:
	FatherAbstract();
	FatherAbstract(const string &name);
	virtual ~FatherAbstract() {}; // virtual empty destructor

	string getFatherName();
	string getGivenName();
	string getName();
	virtual string getNameVirtual();
	virtual string getMessage() =0; //This is a pure virtual (not implemented) method. It makes the class abstract and objects can't be created
};

class SonFromAbstract: virtual public FatherAbstract { // it's recommended to derive virtually always to avoid future problems with multiple inheritance
private:
	string derivedName;

public:
	SonFromAbstract(const string &name, const string &givenName);
	string getName();
	virtual string getNameVirtual();
	virtual string getMessage();
};

/*
 *  CLASS COMPOSITION AND AGGREGATION
 */

class ComposeAggregate {
private:
	SonFromAbstract composed; //("Son A", "Given name A");
	FatherAbstract *aggregated;

public:
	ComposeAggregate(const string &name, const string &givenName);
	string & toString(string &str);
	FatherAbstract * getAggregated();
	SonFromAbstract & getComposed();
	void setAggregated(FatherAbstract *sp);
	~ComposeAggregate();
};

#endif /* ALLCLASSES_H_ */
