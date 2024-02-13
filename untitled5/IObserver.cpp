#pragma once
class IObserver {
public:
    virtual ~IObserver() {};
    virtual void Update(int size, bool existing) = 0;
};
