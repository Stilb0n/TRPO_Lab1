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

private:
 list<IObserver*> list_observer_;
 string message_;
};
