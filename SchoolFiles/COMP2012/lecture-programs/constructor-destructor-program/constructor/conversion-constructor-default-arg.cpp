#include <cstring>      /* File: conversion-constructor-default-arg.cpp */
class Word
{
    int frequency; char* str;
  public:
    Word(const char* s, int k = 1)   // Still conversion constructor!
    {
    	frequency = k;
        str = new char [strlen(s)+1]; strcpy(str, s);
    }
};

int main()
{
    Word *p = new Word {"action"};   // Explicit conversion
    Word movie("Titanic");           // Explicit conversion
    Word director = "James Cameron"; // Implicit conversion
}
