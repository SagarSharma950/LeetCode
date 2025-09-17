class FoodRatings {
public:
    struct comp{
        bool operator()(const pair<string,int>& a, const pair<string,int>& b) const{
            if(a.second != b.second) return a.second > b.second;
            else{
                return a.first < b.first;
            }
        }
    };

    unordered_map<string, set<pair<string, int>, comp>> ratecheck;
    unordered_map<string, string> cuisinemap;
    unordered_map<string, int> foodrate;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0;i<n;i++){
            foodrate[foods[i]] = ratings[i];
            cuisinemap[foods[i]] = cuisines[i];
            ratecheck[cuisines[i]].insert({foods[i], ratings[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuis = cuisinemap[food];
        int prev_rate = foodrate[food];
        foodrate[food] = newRating;
        ratecheck[cuis].erase({food, prev_rate});
        ratecheck[cuis].insert({food, newRating});
    }
    
    string highestRated(string cuisine) {
        return ratecheck[cuisine].begin()->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */