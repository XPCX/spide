#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>


#if !defined(CEXT)
	#define CEXT extern "C"
#endif

#if !defined(sz)
	#define sz const char*
	#define szvec std::vector<const char*>
	/*#define sz const char*; 
	#define szvec std::vector<const char*>; 
*/
#endif

#if defined(ENABLE_LOGGING) && ENABLE_LOGGING
	#if !defined(LOG)
		#define LOG(...) printf(__VA_ARGS__)
	#endif
	#if !defined(LOG_ME)
	#define LOG_ME() LOG( \
		"# %66s #\n%-57s # Line %03d #\n", \
		__FILE__, __PRETTY_FUNCTION__, \
		__LINE__-1 )
	#endif
	#if !defined(LOG_TIME)
		#define LOG_TIME(MSG, T) LOG("# %64s %-1d #\n", MSG, T)
	#endif
#else

/*
	#if !defined(ENABLE_LOGGING)
	#define ENABLE_LOGGING false
	#endif
*/
	#if !defined(LOG)
		#define LOG(...) do{} while(0) 
	#endif
	#if defined(LOG_ME)
		#define LOG_ME() do{} while(0) 
	#endif
	#if !defined(LOG_TIME)
		#define LOG_TIME(MSG, T) do{} while(0)
	#endif
#endif

#endif