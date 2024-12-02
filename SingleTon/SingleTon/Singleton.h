//Singleton.h

#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <mutex>

class Singleton { //Singleton Myersa
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton(const Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(const Singleton&&) = delete;

public:
    static Singleton& Instance() {
        static Singleton instance;
        return instance;
    }

    void Log(const std::string& text) {
        std::cout << "[" << std::chrono::system_clock::now().time_since_epoch().count() << "] " << text << std::endl;
    }
};

class SingletonD { //Singleton (Dynamiczna alokacja z mutexem) 
    static SingletonD* instance;
    static std::mutex _mutex;

    SingletonD() = default;
    SingletonD(const SingletonD&) = delete;
    SingletonD(const SingletonD&&) = delete;
    SingletonD& operator=(const SingletonD&) = delete;
    SingletonD& operator=(const SingletonD&&) = delete;

public:
    static SingletonD& Instance() {
        std::lock_guard<std::mutex> lock(_mutex);
        if (instance == nullptr) {
            instance = new SingletonD();
        }
        return *instance;
    }

    void Log(const std::string& text) {
        std::cout << "[" << std::chrono::system_clock::now().time_since_epoch().count() << "] " << text << std::endl;
    }
};

SingletonD* SingletonD::instance = nullptr;
std::mutex SingletonD::_mutex;