#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

void mostrafigli(vector<vector<string>> vv){
    for(vector<string> v: vv){
        for(string f: v){
            cout << f<< ";";
        }
        cout <<endl;
    }
}
vector<string> splitstring (string str_){
    vector<string> ret = {""};
    int j = 0;
    for(char c: str_){
        if (c == ' '){
            ret.push_back("");
            j++;
        }
        else ret[j].push_back(c);
    }
    return ret;
}
int rand01(){
    return rand()%2;
}

vector<string> figliate(vector<string> gen1, vector<string>gen2){
    vector<string> figlio;
    for(int i = 0; i < 3; i++){
        string temp;
        vector<string> v = {"Oo", "Hh", "A0", "B0", "AB"};
        int _rand = rand()%2;
        temp.push_back(gen1[i][_rand]);
        _rand = rand()%2;
        temp.push_back(gen2[i][_rand]);
        if(find(v.begin(), v.end(), temp) == v.end()) reverse(temp.begin(), temp.end()); 
        figlio.push_back(temp);
    } 
    
    if (rand()%2==0) figlio.push_back("F");
    else figlio.push_back("M");
    return figlio;
}

int main(){
    srand(time(NULL));
    int n = 0;
    string temp;
    
    cout << "OCA2; HERC2; GRUPPO SANGUIGNO\n";
    
    getline(cin, temp);
    vector<string> p1 = splitstring(temp);

    getline(cin, temp);
    vector<string> p2 = splitstring(temp);
    
    cout<<"numero figli \n";
    cin>>n;
    vector<vector<string>> prole;
    cout << "generazione in corso...\n";
    for(int i = 0; i < n; i++){
        prole.push_back(figliate(p1, p2));
    }
    /*
    for(vector<string> v: prole){
        for(string f: v){
            cout << f<< ";";
        }
        cout <<endl;
    }
    */
    cout << "generazione completata!\n";
    cin.seekg(0,ios::end);
    cin.clear();

    string temp_;
    cout <<"seleziona genotipo figlio/a \nOCA2 HERC2 GRUPPO SESSO\n";
    while(temp_ != "close"){
        getline(cin, temp_);
        if (temp_ != "close" and temp_ != "show"){
            
            vector<string> figlio_voluto = splitstring(temp_);
            //cout << "genotipo confermato: " << figlio_voluto[0]<< figlio_voluto[1]<<figlio_voluto[2]<<figlio_voluto[3] << endl;
            int c = 0;
            for(vector<string> v: prole){
                if (v == figlio_voluto) c++;          
            }

            cout << "percentuale trovata: "<< float(c)/float(prole.size()) * 100<< "%\n";
        }
        else if(temp_ == "show"){
            mostrafigli(prole);
        }
        
    }
    
    system("pause");

    return 0;
}