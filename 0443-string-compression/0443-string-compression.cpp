class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int write=0, read=0;
        while(read<n){
            char currentChar=chars[read];
            int cnt=0;
            while(read<n && chars[read]==currentChar){
                cnt++; read++;
            }
            chars[write++]=currentChar;
            if(cnt>1){
                string cntstr=to_string(cnt);
                for(char c: cntstr) chars[write++]=c;
            }
        }
        return write;
    }
};