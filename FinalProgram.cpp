#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>
using namespace std;

const int CURRENT_YEAR = 2023; //This is due in 2023, so I'm keeping this simple. (Change this if you're running this program in the future)

int nameID = 0;

class animal {
private:
    int ID;
    string name;
    int age;
    string birthday;
    string sex;
    string species;
    string birth_season;
    string color;
    int weight;
    string origin_zoo;
    string origin_country;
public:
    // Encapsulation:
    // age
    void setAge(int i) {
        age = i;
    };
    int getAge() {
        return age;
    };
    //sex
    void setSex(string i) {
        sex = i;
    };
    string getSex() {
        return sex;
    };
    // species
    void setSpecies(string i) {
        species = i;
    };
    string getSpecies() {
        return species;
    };
    // birth season
    void setBirthSeason(string i) {
        birth_season = i;
    };
    string getBirthSeason() {
        return birth_season;
    };
    // color
    void setColor(string i) {
        color = i;
    };
    string getColor() {
        return color;
    };
    // weight
    void setWeight(int i) {
        weight = i;
    };
    int getWeight() {
        return weight;
    };
    // origin zoo
    void setOriginZoo(string i) {
        origin_zoo = i;
    };
    string getOriginZoo() {
        return origin_zoo;
    };
    // origin country
    void setOriginCountry(string i) {
        origin_country = i;
    };
    string getOriginCountry() {
        return origin_country;
    };
    // calculate birthday
    void setBDay() {
        int bYear = (CURRENT_YEAR - age);
        birthday = birth_season + " of " + to_string(bYear);
    };
    string getBDay() {
        return birthday;
    }
    // set unique id
    void setID(int index) {
        ID = index + 1;
    };// My previous solution involved having a global variable that incremented every time an ID was generated, but I can eliminate that by just using the vector index which increments anyway.
    int getID() {
        return ID;
    }
};

std::vector<animal> animalVector;          // dynamically create objects!!!


//               Parsing functions
// / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
int findAge(string data) {
    int digits = data.find(" ");
    string ageS = data.substr(0, digits);
    int age = stoi(ageS);                  // string (data from the file) to integer (usable value)
    return age;
};
string findSex(string data) {
    int where = data.find("old ") + 4;          //find where the sex starts
    string start = data.substr(where, 8);
    int length = start.find(" ");               //find where the sex ends
    string sex = data.substr(where, length);
    return sex;
};
string findSpecies(string data) {
    int end = data.find(",");              // find where the species is (comma at end of species)
    string search = data.substr(0, end);   // generate area to search for end of listing
    int start = search.find("ale") + 4;    // find start point for species listing
    int length = (end - start);
    string species = data.substr(start, length);
    return species;
};
string findBirthSeason(string data) {
    int substr1pos = data.find(",") + 2;
    string substr1 = data.substr(substr1pos, data.length() - substr1pos);   // generate substring to search for length of season listing
    string substr2 = substr1.substr(0, substr1.find(","));
    
    if (substr2.find("unknown") != std::string::npos) {            // check if it says "unknown season" or "unknown"
        return "Unknown Season";
    }
    else if (substr2.find("spring") != std::string::npos) {
        return "spring";
    }
    else if (substr2.find("summer") != std::string::npos) {
        return "spring";
    }
    else if (substr2.find("fall") != std::string::npos) {
        return "spring";
    }
    else if (substr2.find("winter") != std::string::npos) {
        return "spring";
    }
    else {
        return "[Incorrect Syntax - Offending string: " + substr2 + "]"; // Handles incorrect syntax in the file (ie. it does not say "unknown" or a season)
    }
};
string findColor(string data) {
    int dataLength = data.length();                 //Remember: substring syntax: STRING.substr(STARTPOS, LENGTH)
    //The following process splits the "data" string into chunks of substrings at the positions of the commas
    int substr1pos = data.find(",") + 2;                                                    // substr1 begins at the first comma (starts at birth season)
    string substr1 = data.substr(substr1pos, dataLength - substr1pos);
    int substr1Length = substr1.length();
    int substr2pos = substr1.find(",") + 2;                                                 // substr2 begins at the first comma in substr1, which is the second comma in "data" (starts at the color)
    string substr2 = substr1.substr(substr2pos, substr1Length - substr2pos);
    
    int substr2end = substr2.find("color");                                             //find where the color is located
    string color = substr2.substr(0, substr2end - 1);
    return color;
};
int findWeight(string data) {
    if (data.find("color,") != std::string::npos) {
        if (data.find("pounds") != std::string::npos) {
            int substr1pos = data.find("color,") + 7;
            string substr1 = data.substr(substr1pos, data.length() - substr1pos);
            string substr2 = substr1.substr(0, substr1.find("pounds") - 1);
            return stoi(substr2);
        }
        else { return 0; }
    }
    else { return 0; }
};
string findOriginZoo(string data) {
    if (data.find("from") != std::string::npos) {
        int substr1pos = data.find("from");
        string substr1 = data.substr(substr1pos + 5, data.length() - substr1pos);
        string substr2 = substr1.substr(0, substr1.find(","));
        return substr2;
    }
    else { return "File Syntax Error"; }
};
string findOriginCountry(string data) {
    if (data.find("from") != std::string::npos) {
        int substr1pos = data.find("from");
        string substr1 = data.substr(substr1pos + 5, data.length() - substr1pos);
        string substr2 = substr1.substr(substr1.find(",") + 2, substr1.length());
        return substr2;
    }
    else { return "File Syntax Error"; }
};

//                        User Interface Functions 
// / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

void printAll(int vIndex) {
//    cout << "vIndex: " << vIndex << endl;
    cout << "ID#: " << animalVector[vIndex].getID() << endl;
    cout << "Species: " << animalVector[vIndex].getSpecies() << endl;
    cout << "Sex: " << animalVector[vIndex].getSex() << endl;
    cout << "Age: " << animalVector[vIndex].getAge() << " Years" << endl;
    cout << "Birthday: " << animalVector[vIndex].getBDay() << endl;
    cout << "Birth Season: " << animalVector[vIndex].getBirthSeason() << endl;
    cout << "Color: " << animalVector[vIndex].getColor() << endl;
    cout << "Weight: " << animalVector[vIndex].getWeight() << endl;
    cout << "Origin Zoo: " << animalVector[vIndex].getOriginZoo() << endl;
    cout << "Origin Country: " << animalVector[vIndex].getOriginCountry() << endl;
    cout << endl << endl;                                                               // adds space between objects in output, to make it more readable
}



int main()
{
 // Open and read the file
    fstream animalList;
    animalList.open("C:/cStuff/midProgFiles/arrivingAnimals.txt");
    int lines = 0;              //variable "lines" is how many lines the file has. Starts at 0 in case the file doenst open or have any lines, and so it's easier to work with the vector
    int vIndex = 0;             // "vIndex" is the index value for the vector, which is different since line 1 would have index 0.
    string lineContent;         //each line is temporarily stored as this variable while data is extracted

 // File parsing algorithm
    if (animalList.is_open()) {
        while (getline(animalList, lineContent)) {
            lines++;
            animalVector.resize(lines);
            vIndex = lines - 1;
            if (vIndex < 0) {
                cout << "Problem with the vector index variable!!!!" << endl; // hopefully this does NOT happen
                cout << "vIndex value: " << vIndex << ", lines value: " << lines << endl;
            }
            animalVector[vIndex].setAge(findAge(lineContent));
            animalVector[vIndex].setSex(findSex(lineContent));
            animalVector[vIndex].setSpecies(findSpecies(lineContent));
            animalVector[vIndex].setBirthSeason(findBirthSeason(lineContent));
            animalVector[vIndex].setColor(findColor(lineContent));
            animalVector[vIndex].setWeight(findWeight(lineContent));
            animalVector[vIndex].setOriginZoo(findOriginZoo(lineContent));
            animalVector[vIndex].setOriginCountry(findOriginCountry(lineContent));
            animalVector[vIndex].setBDay();
            animalVector[vIndex].setID(vIndex);
        }
        // for every line in the file, the line is written to its own object created by animalVector

        cout << "File parsed successfully." << endl;
        cout << "Number of aminals processed: " << lines << "\n\n";
        animalList.close();

        bool uiActive= true;
        while (uiActive) {
            char input;
            cout << "\n\nOptions:\n  q: Quit \n  i: Show the data of an animal with a specified ID \n  a: Show an abbreviated list of all animals \n  h: Show which animals belong in a habitat for the specified species \n";
            cout << "Export to file: \n  H: Export a list of animals in a habitat (for a specified species) \n";
            cout << "Debug options: \n  l: Show a full list of data for ALL animals at once" << endl;
            cout << "\nEnter your choice : ";
            cin >> input;
            cout << endl;

            if (input == 'q') {
                uiActive = false;
            }
            if (input == 'i') {
                int IDentry = 0;
                cout << "Animals are assigned IDs starting at 1. \nCurrently, there are " << lines << " animals, so you must enter an ID between 1 and " << lines << "." << endl;
                cout << "Enter the ID: ";
                cin >> IDentry;
                if (IDentry > 0 && IDentry <= lines) {
                    cout << endl;
                    printAll(IDentry - 1);
                }
                else { cout << "Out of range" << endl; }
            }
            if (input == 'h') {
                string spInput;
                cout << "Enter the species: ";
                cin >> spInput;
                cout << "\nThe following animals will be in the " << spInput << " habitat:" << endl;
                for (int i = 0; i < lines; i++) {
                    if (animalVector[i].getSpecies() == spInput) {
                        cout << "ID#: " << animalVector[i].getID() << ". ";
                        cout << animalVector[i].getSex() << " " << animalVector[i].getSpecies() << ". ";
                        cout << "Born " << animalVector[i].getBDay() << ". ";
                        cout << animalVector[i].getWeight() << " pounds. ";
                        cout << "From " << animalVector[i].getOriginZoo() << ", " << animalVector[i].getOriginCountry() << endl;
                    }
                }
            }
            if (input == 'H') {
                string spInput;
                string fName;
                fstream outputFile;
                cout << "Enter the species: ";
                cin >> spInput;
                cout << "\nEnter the file name: ";
                cin >> fName;
                outputFile.open("C:/cStuff/midProgFiles/" + fName + ".txt", ios::app);
                if (outputFile.is_open()) {
                    outputFile << spInput << " habitat:" << endl;
                    for (int i = 0; i < lines; i++) {
                        if (animalVector[i].getSpecies() == spInput) {
                            outputFile << "ID#: " << animalVector[i].getID() << ". ";
                            outputFile << animalVector[i].getSex() << " " << animalVector[i].getSpecies() << ". ";
                            outputFile << "Born " << animalVector[i].getBDay() << ". ";
                            outputFile << animalVector[i].getWeight() << " pounds. ";
                            outputFile << "From " << animalVector[i].getOriginZoo() << ", " << animalVector[i].getOriginCountry() << endl;
                        }
                    }
                    outputFile.close();
                    cout << "Successfully output to file" << endl;
                }
                else { cout << "File could not be opened" << endl; }

            }
            if (input == 'a') {
                for (int i = 0; i <= vIndex; i++) {
                    cout << "ID#: " << animalVector[i].getID() << ". ";
                    cout << animalVector[i].getSex() << " " << animalVector[i].getSpecies() << ". ";
                    cout << "Born " << animalVector[i].getBDay() << ". ";
                    cout << animalVector[i].getWeight() << " pounds. ";
                    cout << "From " << animalVector[i].getOriginZoo() << ", " << animalVector[i].getOriginCountry() << endl;
                }
            }
            if (input == 'l') {
                for (int i = 0; i <= vIndex; i++) {
                    printAll(i);
                }
            }
        }

    }
    else {
        cout << "File could not be opened" << endl;         //error handling
    }
}
