#include "Exception.h"


Exception::Exception() : excCode( UNKNOWN_EXCEPTION ), addMsg( "" )
{
	SetMainMessage();
}


Exception::Exception( ExceptionCode excType ) : excCode( UNKNOWN_EXCEPTION ), addMsg( "" )
{
	SetMainMessage();
}


Exception::Exception( ExceptionCode excType, std::string msg ) : excCode( UNKNOWN_EXCEPTION ), addMsg( msg )
{
	SetMainMessage();
}


Exception::~Exception()
{
}


std::string Exception::GetMainMessage() const
{
	return mainMsg;
}


std::string Exception::GetAdditionalMessage() const
{
	return addMsg;
}


int Exception::GetExceptionCode() const
{
	return static_cast<int> ( excCode );
}


void Exception::SetMainMessage()
{
	mainMsg = "Error! ";
	switch ( excCode )
	{
		case ( UNKNOWN_EXCEPTION ) :
			mainMsg = "Error! Unknown exception!";
			break;
		case ( WRONG_ID ) :
			mainMsg = "Error! Wrong card ID!";
			break;
	}
}