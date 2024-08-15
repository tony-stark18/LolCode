class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]!=5) return false;
        int i=0;
        while(i<bills.size() && bills[i]==5){
            i++;
        }
        int Fvs = i;
        int Tens = 0;
        // int Tws = 0;
        while(i<bills.size()){
            if(bills[i]==5){
                Fvs++;
            }
            else if(bills[i]==10){
                if(Fvs==0) return false;
                Fvs--;
                Tens++;
            }
            else{
                if(Tens>0 && Fvs>0){
                    Fvs--;
                    Tens--;
                }
                else if(Tens==0 && Fvs>2){
                    Fvs-=3;
                }
                else{
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};