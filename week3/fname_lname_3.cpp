#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

struct FullName{
    string f_name;
    string l_name;
};

void Print_last_names(const vector<string>& lnames){
    if (lnames.size() == 2)
        cout << lnames[1];
    else{
        cout << lnames[lnames.size() - 1] << " (";
        for (auto i = lnames.size() - 2; i > 1; i--)
            cout << lnames[i] << ", ";
        cout << lnames[1] << ")";
    }
}

void Print_first_names(const vector<string>& fnames){
    if (fnames.size() == 2)
        cout << fnames[1];
    else{
        cout << fnames[fnames.size() - 1] << " (";
        for (auto i = fnames.size() - 2; i > 1; i--)
            cout << fnames[i] << ", ";
        cout << fnames[1] << ")";
    }
}

class Person {
public:
    Person(){}
    Person(const string& f, const string& l, const int& y){
        info_person[y].f_name = f;
        info_person[y].l_name = l;
    }
    void ChangeFirstName(int year, const string& first_name) {
        if (year >= info_person.begin()->first){
            if (info_person.count(year) == 0 && year > info_person.begin()->first)
                info_person[year].l_name = "";
            info_person[year].f_name = first_name;
        }
        //Print_map(info_person);
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year >= info_person.begin()->first){
            if (info_person.count(year) == 0)
                info_person[year].f_name = "";
            info_person[year].l_name = last_name;
        }
        //Print_map(info_person);
    }
    /*void Print_map(const map<int, FullName>& m){
        for (auto i:m) {
            cout << i.first << ": " << i.second.f_name << " " << i.second.l_name << endl;
        }
        cout << endl;
    }*/
    string GetFullName(const int& year) const {
        if (year < info_person.begin()->first)
            return "No person";
        else {
            string fname = "", lname = "";
            for (auto i: info_person) {
                if (i.first <= year && i.second.f_name != "")
                    fname = i.second.f_name;
                if (i.first <= year && i.second.l_name != "")
                    lname = i.second.l_name;
            }

            if (fname == "") return lname + " with unknown first name";
            else
            if (lname == "") return fname + " with unknown last name";
            else return fname + " " + lname;
        }
    }
    string GetFullNameWithHistory(const int& year) const {
        if (year < info_person.begin()->first)
            return "No person";
        else{
            string fname = "", lname = "";
            vector<string> history_fnames, history_lnames;


            history_fnames.push_back("");
            history_lnames.push_back("");

            for (auto i: info_person) {
                if (i.first <= year && i.second.f_name != ""){
                    fname = i.second.f_name;
                    if (fname != history_fnames[history_fnames.size() - 1])
                        history_fnames.push_back(i.second.f_name);
                }
                if (i.first <= year && i.second.l_name != ""){
                    lname = i.second.l_name;
                    if (lname != history_lnames[history_lnames.size() - 1])
                        history_lnames.push_back(i.second.l_name);
                }
            }

            if (history_fnames.size() == 1){
                Print_last_names(history_lnames);
                return " with unknown first name";
            }
            else
            if (history_lnames.size() == 1){
                Print_first_names(history_fnames);
                return  " with unknown last name";
            }
            else {
                Print_first_names(history_fnames);
                cout << " ";
                Print_last_names(history_lnames);
                return "";
            }
        }
    }
private:
    map<int, FullName> info_person;
};

int main() {

    Person person("-1_first", "-1_last", -1);

    int year = -1;
    person.ChangeFirstName(year, std::to_string(2) + "_first");
    person.ChangeLastName(year, std::to_string(2) + "_last");

    year = 5;
    person.ChangeFirstName(year, std::to_string(year) + "_first");
    person.ChangeLastName(year, std::to_string(year) + "_last");


    year = 7;
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullName(year) << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    return 0;
}
