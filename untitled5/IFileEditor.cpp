#pragma once
class IObserver {
public:
    virtual ~IObserver() {};
    virtual void Update(int size, bool existing) = 0;
};

class IFileEditor
{ public:
    virtual ~IFileEditor() {}
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};
