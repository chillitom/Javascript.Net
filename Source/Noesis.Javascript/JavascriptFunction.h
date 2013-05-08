#pragma once

//////////////////////////////////////////////////////////////////////////

#include <v8.h>

#include "JavascriptContext.h"

using namespace v8;

//////////////////////////////////////////////////////////////////////////

namespace Noesis { namespace Javascript {

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// JavascriptFunction
//
// Wraps around JS function object and allow calling it in later time
//////////////////////////////////////////////////////////////////////////
public ref class JavascriptFunction
{
public:
	JavascriptFunction(v8::Handle<v8::Object> iFunction, JavascriptContext^ context);
	~JavascriptFunction();
	!JavascriptFunction();

	System::Object^ Call(... cli::array<System::Object^>^ args);

	static bool operator== (JavascriptFunction^ func1, JavascriptFunction^ func2);
	bool Equals(JavascriptFunction^ other);
	
	virtual bool Equals(Object^ other) override;

private:
	v8::Persistent<v8::Function>* mFuncHandle;
	JavascriptContext^ mContext;

private:
	JavascriptFunction() {}
};

//////////////////////////////////////////////////////////////////////////

} } // namespace Noesis::Javascript

//////////////////////////////////////////////////////////////////////////