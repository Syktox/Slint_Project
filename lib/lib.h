#pragma once

#include <print>

class Test
{
public:
    Test();
    ~Test();

    void sayHello() {   std::printf("Hello!");  }
    int getSecretValue() { return m_SecretValue; }

private:
    int m_SecretValue;

};