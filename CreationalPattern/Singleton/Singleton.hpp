#pragma once

class Singleton
{
    public:
    static Singleton& getInstance()
    {
        static Singleton singletonObject;
        return singletonObject;
    }

    Singleton();
    Singleton(Singleton&) = delete;
    Singleton& operator= (const Singleton&) = delete;
};