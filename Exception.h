#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>


class Exception
{
	public:
		enum ExceptionCode { UNKNOWN_EXCEPTION, WRONG_ID };
		Exception();
		Exception( ExceptionCode excType );
		Exception( ExceptionCode excType, std::string msg );
		~Exception();
		std::string GetMainMessage();
		std::string GetAdditionalMessage();
		int GetExceptionCode();
	private:
		ExceptionCode excCode;
		std::string mainMsg, addMsg;
		void SetMainMessage();
};


#endif

