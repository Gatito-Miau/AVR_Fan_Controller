#ifndef VERSION_H
#define VERSION_H

	//Date Version Types
	static const char DATE[] = "02";
	static const char MONTH[] = "01";
	static const char YEAR[] = "2012";
	static const char UBUNTU_VERSION_STYLE[] = "12.01";
	
	//Software Status
	static const char STATUS[] = "Release Candidate";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 0;
	static const long BUILD = 772;
	static const long REVISION = 2342;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1071;
	#define RC_FILEVERSION 1,0,772,2342
	#define RC_FILEVERSION_STRING "1, 0, 772, 2342\0"
	static const char FULLVERSION_STRING[] = "1.0.772.2342";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 0;
	

#endif //VERSION_H
