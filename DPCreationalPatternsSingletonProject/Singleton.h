#pragma once
#include <iostream>
#include <mutex>

std::mutex m;


class Singleton
{
	static Singleton* instance;

	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(Singleton&) = delete;
public:
	static Singleton* Instance()
	{
		if (!instance)
			instance = new Singleton();
		return instance;
	}
};

Singleton* Singleton::instance = nullptr;



class OS
{
	static OS* os;
	std::string name;

	OS(std::string name) : name{ name } {}
public:
	std::string& Name() { return name; }

	static OS* GetOS(std::string name)
	{
		std::lock_guard<std::mutex> lg(m);
		if (!os)
			os = new OS(name);
		return os;
	}
};

OS* OS::os = nullptr;

class Computer
{
	OS* os;
public:
	OS*& OS() { return os; }

	void Launch(std::string name)
	{
		os = OS::GetOS(name);
	}
};

