#include "GUIUtils.h"

void charToString(char in[20], String^ *out) {
	*out = gcnew String(in);
}

void StringToChar(char out[20], String^ in) {
	marshal_context ^ context = gcnew marshal_context();
	const char * temp = context->marshal_as<const char*>(in);
	strcpy(out, temp);
	delete context;
}