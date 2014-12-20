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
		std::string GetMainMessage() const;
		std::string GetAdditionalMessage() const;
		int GetExceptionCode() const;
	private:
		ExceptionCode excCode;
		std::string mainMsg, addMsg;
		void SetMainMessage();
};


#endif

