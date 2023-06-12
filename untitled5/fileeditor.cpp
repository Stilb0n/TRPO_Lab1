#pragma once
#include <iostream>
#include <fstream>
#include "IFileEditor.cpp"
#include <list>
#include <QLabel>
#include <QString>
using namespace std;
class FileEditor : public IFileEditor
{
public:
bool existing = 1;
int size = 0;
fstream file;
bool edited = 0;
FileEditor()
{
    existing = 0;
}
FileEditor(const string& path)
{

    file.open(path);
     if (file.fail())
     existing = 0;
     else
     {
         file.seekg(0, ios::end);
         size = file.tellg();

     }
     file.seekg(0, ios::beg);
}

FileEditor (const FileEditor& other)
{
    this->existing=other.existing;
  //  other.path
    this->size=other.size;
    this->edited=other.edited;
    this->message_=other.message_;
    this->list_observer_=other.list_observer_;
}

void OpenFile(const char* path) {
    if (existing)
    file.close();
    file.open(path);
    if (file.fail())
    {
        existing = 0;
    }
    else
    {
        file.seekg(0, ios::end);
        size = file.tellg();
        existing = 1;
    }
    Notify();
}
~FileEditor() {
    if (existing)
    file.close();
}

void Write(string data) {
    if (existing)
    {
     file.seekg(0, ios::end);
        file << data;
        edited = 1;

        size = file.tellg();
    }
    Notify();

}
void Attach(IObserver* observer) override {
    list_observer_.push_back(observer);

}
void Detach(IObserver* observer) override {
    list_observer_.remove(observer);
}
void Notify() override { //!!!!!!!!!!!!!!!!
    list<IObserver*>::iterator iterator = list_observer_.begin();

    while (iterator != list_observer_.end()) {
        (*iterator)->Update(size, existing);

        ++iterator;
    }
}

private:
 list<IObserver*> list_observer_;
 string message_;
};
