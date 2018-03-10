#include "VMProtectLib.h"

VMProtect::VMProtect()
{
	this->maxCount = sizeof(strings) / sizeof(void*);
	this->count = 0;
}

VMProtect::~VMProtect()
{
	this->Clean();
}

const void* VMProtect::Add(const void* input)
{
	this->strings[this->count] = (void*)input;
	this->count++;

	if (this->count == this->maxCount)
	{
		VMProtectFreeString(this->strings[0]);
		for (size_t i = 1; i < this->count; i++)
			this->strings[i - 1] = this->strings[i];
		this->count--;
	}
	return input;
}

void VMProtect::Clean()
{
	for (size_t i = 0; i < this->count; i++)
		VMProtectFreeString(this->strings[i]);
	this->count = 0;
}

#ifndef VMPROTECT
void VMProtectBegin(const char*)
{

}

void VMProtectBeginVirtualization(const char*)
{

}

void VMProtectBeginMutation(const char*)
{

}

void VMProtectBeginUltra(const char*)
{

}

void VMProtectEnd(void)
{

}

bool VMProtectIsProtected()
{
	return true;
}

bool VMProtectIsDebuggerPresent(bool)
{
	return false;
}

bool VMProtectIsVirtualMachinePresent(void)
{
	return false;
}

bool VMProtectIsValidImageCRC(void)
{
	return true;
}

const char* VMProtectDecryptStringA(const char* value)
{
	return value;
}

const wchar_t* VMProtectDecryptStringW(const wchar_t* value)
{
	return value;
}

bool VMProtectFreeString(const void*)
{
	return true;
}
#endif