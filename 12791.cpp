
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

multimap<int, string> m;
int main(){
    m.insert(make_pair(1967, "DavidBowie"));
    m.insert(make_pair(1969, "SpaceOddity"));
    m.insert(make_pair(1970, "TheManWhoSoldTheWorld"));
    m.insert(make_pair(1971, "HunkyDory"));
    m.insert(make_pair(1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"));
    m.insert(make_pair(1973, "AladdinSane"));
    m.insert(make_pair(1973, "PinUps"));
    m.insert(make_pair(1974, "DiamondDogs"));
    m.insert(make_pair(1975, "YoungAmericans"));
    m.insert(make_pair(1976, "StationToStation"));
    m.insert(make_pair(1977, "Low"));
    m.insert(make_pair(1977, "Heroes"));
    m.insert(make_pair(1979, "Lodger"));
    m.insert(make_pair(1980, "ScaryMonstersAndSuperCreeps"));
    m.insert(make_pair(1983, "LetsDance"));
    m.insert(make_pair(1984, "Tonight"));
    m.insert(make_pair(1987, "NeverLetMeDown"));
    m.insert(make_pair(1993, "BlackTieWhiteNoise"));
    m.insert(make_pair(1995, "1.Outside"));
    m.insert(make_pair(1997, "Earthling"));
    m.insert(make_pair(1999, "Hours"));
    m.insert(make_pair(2002, "Heathen"));
    m.insert(make_pair(2003, "Reality"));
    m.insert(make_pair(2013, "TheNextDay"));
    m.insert(make_pair(2016, "BlackStar"));
    int T;
    cin>>T;
    while(T--){
        int s,e;
        queue<pair<int,string>> q;
        cin>>s>>e;
        for(map<int,string>::iterator iter = m.begin(); iter!=m.end(); ++iter){
            if((*iter).first >= s && (*iter).first <= e) {
                q.push(make_pair((*iter).first, (*iter).second));
            }
        }
        int sz= q.size();
        cout<<sz<<"\n";
        for(int i=0; i<sz; i++){
            cout<<q.front().first<<" "<<q.front().second<<"\n";
            q.pop();
        }
    }
}
