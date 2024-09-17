
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

enum class AccessMode{read,write,append};


class Database{
private:
    std::fstream file;
    std::string filePath;
    AccessMode mode;
    std::map<std::string,std::string> contacts;
    bool isUpToDate = false;
    bool isOpened = false;
    void updateDatabase()
    {
        //open file
        this->file.open(filePath,std::ios::out);
        for(auto element:contacts)
        {
            file<<element.first<<','<<element.second<<std::endl;
        }
        //close file
        this->file.close();
        isUpToDate = true;
    }
public:
    //done
    void open(std::string filePath)
    {
        //copy parameters
        std::fstream testFile(filePath,std::ios::in);
        if(testFile.is_open())
        {
        this->filePath = filePath;
        //get Database
        this->contacts = GetDataBase();
        //makeUptoDate
        isUpToDate = true;
        //close the file
        isOpened = true;
        }
        else 
        {
            isOpened = false;
        }
    }
    //done
    void addcontact(std::string name,std::string number)
    {
        if(isOpened)
        {
            //get number (not up to date)
            contacts[name] = number;
            isUpToDate = false;
            //add to database to make up to date
            addToDatabase(name,number);
            isUpToDate = true;
        }
    }
    // 50%
    std::string GetNumber(std::string name)
    {
        if(isOpened)
        {
            if(isUpToDate)
            {
                return contacts[name];
            }
            else 
            {
                std::cerr<<"Trying to get number not in memory"<<std::endl;
                return "";
            }
        }
        return "";
    }
    std::map<std::string,std::string> GetDataBase()
    {
        std::map<std::string,std::string> result;
        std::vector<std::string> lines;
        std::string tempName;
        std::string tempNumber;
        //opening
        this->file.open(filePath,std::ios::in);
        while(std::getline(file,tempName,',')&&std::getline(file,tempNumber)){
            result[tempName] = tempNumber;
        }
        //closing
        this->file.close();
        return result;
    }
    void addToDatabase(std::string name,std::string number)
    {
        this->contacts[name] = number;
        //open the file for append
        this->file.open(filePath,std::ios::app);
        //add to database
        file<<name<<","<<number<<std::endl;
        //close the file after append
        this->file.close();
    }
    void removecontact(std::string name)
    {
        contacts.erase(name);
        isUpToDate = false;
        updateDatabase();
    }
    bool is_open()
    {
        return isOpened;
    }
    void removeAll()
    {
        if(isOpened == true)
        {
            file.open(filePath,std::ios::out);
            contacts.clear();
            isUpToDate = false;
            file<<"";
            isUpToDate = true;
            file.close();
        }
    }
};
class Printer
{
public:
    void print(Database &dB)
    {
        std::map<std::string,std::string>contacts = dB.GetDataBase();
        for(auto element:contacts)
        {
            std::cout<<"Name: "<<element.first<<std::endl;
            std::cout<<"Number: "<<element.second<<std::endl<<std::endl;
        }
    }
};

int main()
{
    const char Add =  '1';
    const char get_number =  '2';
    const char Show_all =  '3';
    const char Remove =  '4';
    const char RemoveAll = '5';
    const char EndProgram =  '0';
    Database myDB;
    Printer printer;
    myDB.open("database.db");
    if(myDB.is_open())
    {
        bool running_flag = true;
        while(running_flag)
        {
            std::string operation;
            std::cout<<"What do you want to do (1:Add,2:get number,3:show all,4:remove,5:to remove all,0:to End): ";
            std::cin>>operation;
            if(operation.length() == 1)
            {
                switch (operation[0]) {
                    case Add://Add
                    {

                        std::string name,number;
                        std::cout<<"Enter Name to add: ";
                        std::cin>>name;
                        std::cout<<"Enter number to add: ";
                        std::cin>>number;
                        myDB.addToDatabase(name,number);
                        break;
                    }
                    case Show_all:
                    {//Show
                        std::cout<<"Showing all the data: "<<std::endl;
                        printer.print(myDB);
                        break;
                    }
                    case get_number:
                    {//Show
                        std::string name;
                        std::cout<<"Enter the name to get the number: ";
                        std::cin>>name;
                        std::cout<<"The number is: "<<myDB.GetNumber(name)<<std::endl;
                        break;
                    }
                    case Remove:
                    {//Remove
                        std::string name;
                        std::cout<<"Enter Name to remove: ";
                        std::cin>>name;
                        myDB.removecontact(name);
                        break;
                    }
                    case RemoveAll:
                    {
                        std::string answer;
                        std::cout<<"Are you sure(y/n)? ";
                        std::cin>>answer;
                        if(((answer[0] == 'y')||(answer[0] == 'Y'))&&(answer.length() == 1))
                        {
                            myDB.removeAll();
                        }
                        break;
                    }
                    case EndProgram:
                    {
                        running_flag = false;
                        break;
                    }
                    default:{
                        std::cout<<"Wrong Input Please Try Again!"<<std::endl;
                    }
                }
            }
            else 
            {
                std::cout<<"Wrong input please try again!"<<std::endl;
            }
        }
    }
    else 
    {
        std::cout<<"Cannot open the file!";
    }
    return 0;    
}