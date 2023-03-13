#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
struct records{
    string name="";
    string license_plate;
    bool is_car;
    int months;
    double weight;
    double monthly_fee;
};
records getData()
{
    struct records tempData;
      int months;
    //cout << "Entering New Records" << endl;
    cout << "Enter the name :-";
     getline(cin, tempData.name);
     getline(cin, tempData.name);
    cout << "Enter the license plate:-";
    getline(cin, tempData.license_plate);
    cout << "Is the vehicle a car if yes '1' otherwise '0' :-";
    cin >> tempData.is_car;
    if (tempData.is_car == 0)
    {
        cout << "Enter the weight of the truck :-";
        cin >> tempData.weight;
    }
    cout << "How Many months do u want to rent the parking space:-";
    cin >> months;
    if (tempData.is_car==0)
    {
        tempData.months = months;
        if (months>60)
        {
            tempData.monthly_fee = int((tempData.weight*700000*months)*0.75);
        }
        else{
            tempData.monthly_fee = int((tempData.weight*700000*months));
        }
    }
    else
    {
        tempData.months = months;
        if (months>60)
        {
            tempData.monthly_fee = (tempData.weight*700000*months)*0.80;
        }
        else{
            tempData.monthly_fee = (tempData.weight*700000*months);
        }
    }
    return tempData;
}
void Search_Data_by_name(vector<records> record)
{
    string input;
    
    cout << "Enter the name u want to Search in the data :-";
    getline(cin, input);
    getline(cin, input);
    for (const records &e : record)
    {
        if (e.name == input)
        {
            cout << e.name << "     ";
            cout << e.license_plate <<" ";
            if (e.is_car == 0)
            {
                cout<< "is a Truck and the weight of the truck is "<< e.weight;
            }
            else
            {
                cout << "is it a car - " << e.is_car << " ";
            }
            cout << endl;
        }
        else
        {
            cout <<"No such record or please input the correct name"<< endl;
        }
    }
}

void Search_Data_by_license_plate(vector<records> record)
{
    string license_plate;
    cout << "Enter the licencse Plate number you want to search:-";
    getline(cin, license_plate);
    for (const records &e : record)
    {
        if (e.license_plate == license_plate)
        {
            cout << e.name << "     ";
            cout << e.license_plate <<" ";
            if (e.is_car == 0)
            {
                cout<< "is a Truck and the weight of the truck is "<< e.weight;
            }
            else
            {
                cout << "is a car - " << e.is_car << " ";
            }
            cout << endl;
        }
        else
        {
            cout <<"No such record or please input the correct license Plate number"<< endl;
        }
    }
}
void Search_Data_by_Vehicle_type(vector<records> record)
{
    int choice;
    cout << "Do u want to search a 1.car or a 2.Truck:- "<< endl;
    cin >> choice;
    if (choice ==1)
    {
        for (const records &e : record)
        {
            if (e.is_car == 1)
            {
                cout << e.name << "     ";
                cout << e.license_plate <<" ";
                cout << e.months<< " ";
                cout << e.monthly_fee<< " ";
            }
            else{
                cout << e.name << "     ";
                cout << e.license_plate <<" ";
                cout << e.months << " ";
                cout << e.monthly_fee << " "; 
                cout << e.months<< " ";
                cout << e.monthly_fee<< " ";
            }
        }
    }
}
void fees_greater_than(vector<records> record)
{
    int amount;
    bool exist;
    cout << "Enter the fees amount u want view entried greater than the amount:-";
    cin >> amount;
    for (const records &e : record)
    {
        if (e.monthly_fee >amount)
        {
            exist =1;
            cout << e.name << "     ";
            cout << e.license_plate <<" ";
            cout << e.months << " ";
            cout << e.monthly_fee << " ";
            if (e.is_car == 0)
            {
                cout<< "is a Truck and the weight of the truck is "<< e.weight;
            }
            else
            {
                cout << "is a car - " << e.is_car << " ";
            }
            cout << endl;
        }
    }
    if (exist==0)
    {
        cout << "There are no entire greater than that value" << endl;
    }
    
    
}
int main()
{
    vector <records> record;
    while(true)
    {
    cout << "          Menu of options      "<< endl;
    cout << "1.Do u want to add a new reocrd "<< endl;
    cout << "2.Do u want to see all records "<< endl;
    cout << "3.Search Vehicles by the Car owner's name" << endl;
    cout << "4.Search Vehicles by the license plate" << endl;
    cout << "5.Search Vehicles by the vehicle type" << endl;
    cout << "6.Search  for  vehicles  with  a  monthly  fee greater than an entered number" << endl;
    cout << "8.Do u want to exit "<< endl;
    
   int choice;
   cin >> choice;
   system("cls");
   if (choice == 1)
   {
        struct records temp = getData();
        record.push_back(temp);
        system("cls");
   }
   else if (choice == 2)
   {
    for (const records &e : record)
        {
            if (e.is_car == 0)
            {
                cout << "Name                "<< "       |License Plate "<< "  " <<"Weight of the TRuck  " <<  "|Number of months   "<<" " << "  Monthly Feee"<< endl;    
                cout << e.name << "     "<< e.license_plate<< "   "<< e.weight << e.months << "  "<< e.monthly_fee;
            }
            else
            {
                cout << "Name                "<< "       |License Plate "<< " " << "|Number of months       "<<" " << "    Monthly Feee" << endl;    
                cout << e.name << "     "<< e.license_plate<< "   "<< e.months << "  "<< e.monthly_fee;
            }
            cout << endl;
            cout << endl;
        }
        //system("cls");
   }
   else if (choice == 3)
   {
        Search_Data_by_name(record);
   }
   else if (choice == 4)
   {
        Search_Data_by_license_plate(record);
   }
   else if (choice == 5)
   {
        Search_Data_by_Vehicle_type(record);
   }
   else if (choice == 6)
   {
        fees_greater_than(record);
   }
   else 
   {
    cout << "wrong entry, input a correct option";
   }

}
    
}