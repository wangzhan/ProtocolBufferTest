// ProtocolBufferTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "tutorial.Person.pb.h"

int _tmain(int argc, _TCHAR* argv[])
{
    tutoria::Person writer;
    writer.set_name("james");
    writer.set_id(123);
    writer.set_email("james@gmail.com");
    tutoria::Person::PhoneNumber &phone1 = *(writer.add_phone());
    phone1.set_number("123456");
    phone1.set_type(tutoria::Person_PhoneType_HOME);
    tutoria::Person::PhoneNumber &phone2 = *(writer.add_phone());
    phone2.set_number("23456");
    phone2.set_type(tutoria::Person_PhoneType_WORK);
    std::string strResult = writer.SerializeAsString();

    std::wcout << _T("writer result:") << std::endl;
    std::cout << strResult << std::endl;

    tutoria::Person reader;
    reader.ParseFromString(strResult);

    std::wcout << std::endl << std::endl;

    std::wcout << _T("reader result:") << std::endl;

    if (reader.has_name())
    {
        std::cout << reader.name() << std::endl;
    }

    if (reader.has_id())
    {
        std::cout << reader.id() << std::endl;
    }

    if (reader.has_email())
    {
        std::cout << reader.email() << std::endl;
    }

    for (int iIndex = 0; iIndex < reader.phone_size(); ++iIndex)
    {
        const tutoria::Person::PhoneNumber &tempPhone = reader.phone(iIndex);
        std::cout << tempPhone.number() << std::endl;
        std::cout << tempPhone.type() << std::endl;
    }

    getchar();

	return 0;
}

