#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>
using namespace std;

bool debugging;

map <string,float> possibleBlood =
{
    {"AA", 0},
    {"BB", 0},
    {"A0", 0},
    {"B0", 0},
    {"AB", 0},  
    {"00", 0},
};

map <int, string> bloodID;

vector <string> bg_outcomes;

string bloodMom;
string bloodDad;

int bloodInput = -1;

void BG_SetMom(int _input)
{
    switch(_input)
    {
        case 0:
        {
            bloodMom = "AA";
        }
        break;
        
        case 1:
        {
            bloodMom = "BB";
        }
        
        break;
        
        case 2:
        {
            bloodMom = "A0";
        }
        break;
        
        case 3:
        {
            bloodMom = "B0";
        }
        
        break;
        
        case 4:
        {
            bloodMom = "AB";
        }
        
        break;
        
        case 5:
        {
            bloodMom = "00";
        }
        
        break;
    }
    cout<<endl;
}

void BG_SetDad(int _input)
{
    switch(_input)
    {
        case 0:
        {
            bloodDad = "AA";
        }
        break;
        
        case 1:
        {
            bloodDad = "BB";
        }
        
        break;
        
        case 2:
        {
            bloodDad = "A0";
        }
        break;
        
        case 3:
        {
            bloodDad = "B0";
        }
        
        break;
        
        case 4:
        {
            bloodDad = "AB";
        }
        
        break;
        
        case 5:
        {
            bloodDad = "00";
        }
        
        break;
    }
    cout<<endl;
}

vector<string> BG_SetOutcomes()
{
    int lastID = -1;
    int ocIndex = 0;
    vector<string> oc = {"qq", "qq", "qq", "qq"};
    
    for (int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            oc[ocIndex] = bloodMom.substr(i, 1) + bloodDad.substr(j,1);
            ocIndex++;
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
        if(oc[i][0] == '0' || oc[i] == "BA")
        {
            swap(oc[i][0], oc[i][1]);
        }
        
        bloodID.insert({lastID+1, oc[i]});
        lastID++;
        
        possibleBlood[oc[i]] += .25f;
    }
    
    return oc;
}

void OutPut_BG_Probs()
{
    cout<<"probabilità matematiche (gruppo sanguigno):\n";
    for (const auto& pair : possibleBlood) {
        cout<< pair.first << ": " << pair.second << '\n';
    }
    cout<<endl;
}

void OutPut_BG_ID()
{
    vector<pair<int, string>> vec(bloodID.begin(), bloodID.end());

    sort(vec.begin(), vec.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.second < b.second;
    });

    bloodID.clear();

    for (size_t i = 0; i < vec.size(); ++i) {
        bloodID[i + 1] = vec[i].second;
    }

    if(debugging)
    {
        cout << "BloodIDs:\n";
        for (const auto& pair : bloodID) {
            cout << pair.first << ": " << pair.second << '\n';
        }
        cout<<endl;
    }
}

void Blood()
{
    cout<<"inserisci il gruppo sanguigno di tua mamma\n";
    cout<<"usa i numeri:\n"<<"0: AA\n"<<"1: BB\n"<<"2: A0\n"<<"3: B0\n"<<"4: AB\n"<<"5: 00\n";
    cin>>bloodInput;
    
    while (bloodInput < 0 || bloodInput > 5)
    {
        cout<<"ID non valido\n";
        cin>>bloodInput;
    }
    
    BG_SetMom(bloodInput);

    cout<<"inserisci il gruppo sanguigno di tuo padre\n";
    cout<<"usa i numeri:\n"<<"0: AA\n"<<"1: BB\n"<<"2: A0\n"<<"3: B0\n"<<"4: AB\n"<<"5: 00\n";
    cin>>bloodInput;
    
    while (bloodInput < 0 || bloodInput > 5)
    {
        cout<<"ID non valido\n";
        cin>>bloodInput;
    }
    
    BG_SetDad(bloodInput);
    
    vector<string> bg_outcomes = {"qq", "qq", "qq", "qq"};
    
    bg_outcomes = BG_SetOutcomes();
    
    if(debugging)
    {
        cout<<"possibili combinazioni del genotipo del sangue\n";
        for (int i = 0; i < 4; i++)
        {
            cout<<i<<": "<<bg_outcomes[i]<<endl;
        }
        cout<<endl;
    }
    
    OutPut_BG_ID();
}

/////////////////////////////////////////////////////////////////////////////////////////////////

map <string,float> possibleEye =
{
    {"HHOO", 0},
    {"HhOO", 0},
    {"HHOo", 0},
    {"HhOo", 0},
    {"hhOO", 0},  
    {"hhOo", 0},
    {"HHoo", 0},
    {"Hhoo", 0},
    {"hhoo", 0},
};

map <int, string> momComb;
map <int, string> dadComb;

map <int, string> eyeID;

vector <string> e_outcomes;

string eyeMom;
string eyeDad;
int eyeInput = -1;

void Eye_SetMom(int _input)
{
    switch(_input)
    {
        case 0:
        {
            eyeMom = "HHOO";
        }
        break;
        
        case 1:
        {
            eyeMom = "HhOO";
        }
        break;
        
        case 2:
        {
            eyeMom = "HHOo";
        }
        break;
        
        case 3:
        {
            eyeMom = "HhOo";
        }
        break;
        
        case 4:
        {
            eyeMom = "hhOO";
        }
        break;
        
        case 5:
        {
            eyeMom = "hhOo";
        }
        break;
        
        case 6:
        {
            eyeMom = "HHoo";
        }
        break;
        
        case 7:
        {
            eyeMom = "Hhoo";
        }
        break;
        
        case 8:
        {
            eyeMom = "hhoo";
        }
        break;
    }
    cout<<endl;
}

void Eye_SetDad(int _input)
{
    switch(_input)
    {
        case 0:
        {
            eyeDad = "HHOO";
        }
        break;
        
        case 1:
        {
            eyeDad = "HhOO";
        }
        break;
        
        case 2:
        {
            eyeDad = "HHOo";
        }
        break;
        
        case 3:
        {
            eyeDad = "HhOo";
        }
        break;
        
        case 4:
        {
            eyeDad = "hhOO";
        }
        break;
        
        case 5:
        {
            eyeDad = "hhOo";
        }
        break;
        
        case 6:
        {
            eyeDad = "HHoo";
        }
        break;
        
        case 7:
        {
            eyeDad = "Hhoo";
        }
        break;
        
        case 8:
        {
            eyeDad = "hhoo";
        }
        break;
    }
    cout<<endl;
}

void SetParentSubCombinations()
{
    string h_mom = eyeMom.substr(0, 2);
    string o_mom = eyeMom.substr(2, 2);
    int mom_id = 0;
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            momComb.insert( {mom_id, h_mom.substr(i, 1) + o_mom.substr(j, 1)} );
            mom_id++;
        }
    }
    
    string h_dad = eyeDad.substr(0, 2);
    string o_dad = eyeDad.substr(2, 2);
    int dad_id = 0;
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            dadComb.insert( {dad_id, h_dad.substr(i, 1) + o_dad.substr(j, 1)} );
            dad_id++;
        }
    }
    cout<<endl;
}

vector <string> Eye_SetOutcomes()
{
    vector <string> oc;
    int lastID = 10;
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            string h_parent = momComb[i].substr(0, 1) + dadComb[j].substr(0, 1);
            string o_parent = momComb[i].substr(1, 1) + dadComb[j].substr(1, 1);
            
            if(h_parent == "hH")
            {
                h_parent = "Hh";
            }
            if(o_parent == "oO")
            {
                o_parent = "Oo";
            }
            
            string temp = h_parent + o_parent;
            oc.push_back(temp);
            
            eyeID.insert({lastID+1, temp});
            lastID++;
            
            possibleEye[temp] += 0.0625;
        }
    }
    
    return oc;
}

void OutPut_EyeProbs()
{
    cout<<"probabilità matematiche (occhi):\n";
    for (const auto& pair : possibleEye) {
        cout << pair.first << ": " << pair.second << '\n';
    }
    cout<<endl;
}

void OutPut_EyeIDs()
{
    vector<pair<int, string>> vec(eyeID.begin(), eyeID.end());

    sort(vec.begin(), vec.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.second < b.second;
    });

    eyeID.clear();

    int newKey = 11;
    for (const auto& pair : vec) {
        eyeID[newKey++] = pair.second;
    }

    if(debugging)
    {
        cout << "EyeIDs:\n";
        for (const auto& pair : eyeID) {
            cout << pair.first << ": " << pair.second << '\n';
        }
        cout<<endl;
    }
}

void Eye()
{
    cout<<"inserisci i geni degli occhi di tua mamma\n";
    cout<<"usa i numeri:\n"<<"0: HHOO, 1: HhOO, 2: HHOo, 3: HhOo, 4: hhOO\n";
    cout<<"5: hhOo, 6: HHoo, 7: Hhoo, 8: hhoo\n";
    cin>>eyeInput;
    
    while (eyeInput < 0 || eyeInput > 8)
    {
        cout<<"ID non valido\n";
        cin>>eyeInput;
    }
    
    Eye_SetMom(eyeInput);
    
    cout<<"inserisci i geni degli occhi di tuo papà\n";
    cout<<"usa i numeri:\n"<<"0: HHOO, 1: HhOO, 2: HHOo, 3: HhOo, 4: hhOO\n";
    cout<<"5: hhOo, 6: HHoo, 7: Hhoo, 8: hhoo\n";
    cin>>eyeInput;
    
    while (eyeInput < 0 || eyeInput > 8)
    {
        cout<<"ID non valido\n";
        cin>>eyeInput;
    }
    
    Eye_SetDad(eyeInput);
    
    cout<<"mom: "<<eyeMom<<" dad: "<<eyeDad<<endl;
    
    SetParentSubCombinations();
    
    e_outcomes = Eye_SetOutcomes();
    
    if(debugging)
    {
        cout<<"possibili combinazioni del genotipo degli occhi:\n";
        for(int i = 0; i < e_outcomes.size(); i++)
        {
            cout<<e_outcomes[i]<<", ";
            if((i + 1) % 4 == 0)
            {
                cout<<endl;
            }
        }
        
        cout<<endl;
    }
    
    //OutPut_EyeProbs();
    
    OutPut_EyeIDs();
}

/////////////////////////////////////////////////////////////////////////////////////////////////

vector<string> allChildrenGenerated;
map <string, double> freqRelGender =
{
    {"M", 0},
    {"F", 0}
};

map <string, double> freqRelBlood;
map <string, double> freqRelEyeColor;

int randomCharacterID(int range, int offset)
{
    return rand() % range + offset;
}

void CreateRandomChild()
{
    int maxSamples = 0;
    cout<<"Quanti figli vuoi generare\n";
    cin>>maxSamples;
    cout<<endl;
    
    for(int i = 0; i < maxSamples; i++)
    {
        int sex = randomCharacterID(2, 1);
        if(sex == 1)
        {
            freqRelGender["M"] += 1; 
        }
        else
        {
            freqRelGender["F"] += 1;
        }
        
        int bg = randomCharacterID(4, 1);
        string bg_s = bloodID[bg];
        
        if (freqRelBlood.find(bg_s) == freqRelBlood.end()) 
        {
            freqRelBlood.insert({bg_s, 1});
        }
        else 
        {
            freqRelBlood[bg_s] += 1;
        }
        
        int ec = randomCharacterID(16, 11);
        string ec_s = eyeID[ec];

        if (freqRelEyeColor.find(ec_s) == freqRelEyeColor.end()) 
        {
            freqRelEyeColor.insert({ec_s, 1});
        }
        else 
        {
            freqRelEyeColor[ec_s] += 1;
        }
        
        allChildrenGenerated.push_back(to_string(sex) + to_string(bg) + to_string(ec));
    }
    
    for(int i = 0; i < freqRelGender.size(); i++)
    {
        auto it = freqRelGender.begin();
        advance(it, i);
        string it_s = it->first;
        freqRelGender[it_s] /= maxSamples;
    }
    
    for(int i = 0; i < freqRelBlood.size(); i++)
    {
        auto it = freqRelBlood.begin();
        advance(it, i);
        string it_s = it->first;
        freqRelBlood[it_s] /= maxSamples;
    }
    
    for(int i = 0; i < freqRelEyeColor.size(); i++)
    {
        auto it = freqRelEyeColor.begin();
        advance(it, i);
        string it_s = it->first;
        freqRelEyeColor[it_s] /= maxSamples;
    }
    
    cout << "Gender Freq Rel:\n";
    for (const auto& pair : freqRelGender) {
        cout << pair.first << ": " << pair.second << '\n';
    }
    cout<<endl;
    
    cout << "Blood Freq Rel:\n";
    for (const auto& pair : freqRelBlood) {
        cout << pair.first << ": " << pair.second << '\n';
    }
    cout<<endl;
    
    cout << "EyeC Freq Rel:\n";
    for (const auto& pair : freqRelEyeColor) {
        cout << pair.first << ": " << pair.second << '\n';
    }
    cout<<endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void Possibilities()
{
    srand (time(NULL));
    
    int d = 0;
    cout<<"se vuoi vedere gli ID e le combinazioni dei vari genotipi(sangue e occhi) immetti 1 altrimenti 0\n";
    cin>>d;
    while(d < 0 || d > 1)
    {
        cout<<"debug not valid: if you want to see the ID input 1 otherwise input 0\n";
        cin>>d;
    }
    cout<<endl;
    
    if(d == 0)
    {
        debugging = false;
    }
    else
    {
        debugging = true;
    }
    
    Blood();
    Eye();
    
    cout<<"probabilità matematiche (sesso):\n";
    cout<<"M: 0.5\n";
    cout<<"F: 0.5\n\n";

    OutPut_BG_Probs();
    OutPut_EyeProbs();
    
    CreateRandomChild();
}

/////////////////////////////////////////////////////////////////////////////////////////////////

string childGender = "a";
string childGroup = "a";
string childEye = "aaaa";

int requestedGender = -1;
int requestedBlood = -1;
int requestedEye = -1;

float CalcolateProb(int g_in, int bg_in, int eye_in)
{
    float gender_prob = 0;
    if(g_in == 0)
    {
        gender_prob = freqRelGender["M"];
    }
    else
    {
        gender_prob = freqRelGender["F"];
    }
    
    float blood_prob = 0;
    if(bg_in == 0) //A
    {
        blood_prob = freqRelBlood["AA"] + freqRelBlood["A0"];
    }
    else if(bg_in == 1) //B
    {
        blood_prob = freqRelBlood["BB"] + freqRelBlood["B0"];
    }
    else if(bg_in == 2) //AB
    {
        blood_prob = freqRelBlood["AB"];
    }
    else if(bg_in == 3) //0
    {
        blood_prob = freqRelBlood["00"];
    }
    
    float eye_prob = 0;
    if(eye_in == 0) //neri
    {
        eye_prob = freqRelEyeColor["HH00"];
    }
    else if(eye_in == 1) //marroni
    {
        eye_prob = freqRelEyeColor["HhOO"] + freqRelEyeColor["HHOo"]+freqRelEyeColor["HhOo"];
    }
    else if(eye_in == 2) //marroni chiari
    {
        eye_prob = freqRelEyeColor["hhOO"] + freqRelEyeColor["hhOo"]+freqRelEyeColor["HHoo"]+freqRelEyeColor["Hhoo"];
    }
    else if(eye_in == 3) //azzurr
    {
        eye_prob = freqRelEyeColor["hhoo"];
    }
    
    return gender_prob * blood_prob * eye_prob;
}

void Shopping()
{
    cout<<"inserisci il sesso del figlio che vorresti\n";
    cout<<"usa i numeri:\n"<<"0: maschio, 1: femmina\n";
    cin>>requestedGender;
    
    while (requestedGender < 0 || requestedGender > 1)
    {
        cout<<"ID non valido\n";
        cin>>requestedGender;
    }
    
    cout<<"inserisci il grupo sanguigno del figlio che vorresti\n";
    cout<<"usa i numeri:\n"<<"0: A, 1: B, 2: AB, 3: 0\n";
    cin>>requestedBlood;
    
    while (requestedBlood < 0 || requestedBlood > 3)
    {
        cout<<"ID non valido\n";
        cin>>requestedBlood;
    }
    
    cout<<"inserisci i geni degli occhi del figlio che vorresti\n";
    cout<<"usa i numeri:\n"<<"0: neri, 1: marrone, 2: marrone chiaro, 3: azzurri\n";
    cin>>requestedEye;
    
    while (requestedEye < 0 || requestedEye > 3)
    {
        cout<<"ID non valido\n";
        cin>>requestedEye;
    }
    
    double totalProb = CalcolateProb(requestedGender, requestedBlood, requestedEye);
    cout<<"Hai la probabilità che esca del: "<<totalProb<<" ("<<totalProb*100<<"%)\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Possibilities();
    
    Shopping();

    system("pause");
}



