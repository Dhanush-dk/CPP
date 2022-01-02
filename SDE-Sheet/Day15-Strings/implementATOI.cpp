//GFG
// str is string with only numbers
// i.e str = "1234";
class Solution{
  public:
    int atoi(string str) {
        int result = 0;
        for(auto i : str){
            result = result*10 + (i-'0');
        }
        return result;
    }
};
