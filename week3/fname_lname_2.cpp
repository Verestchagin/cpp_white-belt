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
        void ChangeFirstName(int year, const string& first_name) {
            if (info_person.count(year) == 0)
                info_person[year].l_name = "";
            info_person[year].f_name = first_name;
            //Print_map(info_person);
        }
        void ChangeLastName(int year, const string& last_name) {
            if (info_person.count(year) == 0)
                info_person[year].f_name = "";
            info_person[year].l_name = last_name;
            //Print_map(info_person);
        }
        void Print_map(const map<int, FullName>& m){
            for (auto i:m) {
                cout << i.first << ": " << i.second.f_name << " " << i.second.l_name << endl;
            }
            cout << endl;
        }
        string GetFullName(int year) {
            if (year < info_person.begin()->first)
                return "Incognito";
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
        string GetFullNameWithHistory(int year) {
            if (year < info_person.begin()->first)
                return "Incognito";
            else{
                string fname = "", lname = "";
                //int search_year; //old
                vector<string> history_fnames, history_lnames;

                /*for (auto i: info_person)
                    if (i.first <= year)
                        search_year = i.first;*/ //old

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

                /*for (auto i = search_year; i >= 0; i--){
                    if (history_fnames[history_fnames.size() - 1] != info_person[i].f_name && info_person[i].f_name != "")
                        history_fnames.push_back(info_person[i].f_name);
                    if (history_lnames[history_lnames.size() - 1] != info_person[i].l_name && info_person[i].l_name != "")
                        history_lnames.push_back(info_person[i].l_name);
                }
                if (history_fnames.size() == 2)
                    fname += history_fnames[1];
                if (history_lnames.size() == 2)
                    lname += history_lnames[1];
                if (history_fnames.size() > 2){
                    fname += history_fnames[1] + " (";
                    for (auto i = 2; i < history_fnames.size(); i++)
                        fname += history_fnames[i] + ", ";
                    fname.resize(fname.size() - 2);
                    fname += ")";
                }
                if (history_lnames.size() > 2){
                    lname += history_lnames[1] + " (";
                    for (auto i = 2; i < history_lnames.size(); i++)
                        lname += history_lnames[i] + ", ";
                    lname.resize(lname.size() - 2);
                    lname += ")";
                }
                if (history_fnames.size() == 1)
                    return lname + " " + "with unknown first name";
                    //fname += "with unknown first name";
                if (history_lnames.size() == 1)
                    return fname + " " + "with unknown last name";
                    //lname += "with unknown last name";
                return fname + " " + lname;*/ //old
            }
        }
        private:
        map<int, FullName> info_person;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1965, "Appolinaria");

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeLastName(1965, "Volkova");
    person.ChangeLastName(1965, "Volkova-Sergeeva");

    for (int year : {1964, 1965, 1966}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
