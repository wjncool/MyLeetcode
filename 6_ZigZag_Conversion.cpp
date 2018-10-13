/*********************************************************************
 将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：
 
 P   A   H   N
 A P L S I I G
 Y   I   R
 之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"
 
 实现一个将字符串进行指定行数变换的函数:
 
 string convert(string s, int numRows);
 示例 1:
 
 输入: s = "PAYPALISHIRING", numRows = 3
 输出: "PAHNAPLSIIGYIR"
 示例 2:
 
 输入: s = "PAYPALISHIRING", numRows = 4
 输出: "PINALSIGYAHRPI"
 解释:
 
 P     I    N
 A   L S  I G
 Y A   H R
 P     I

 大概思路： 如输入: s = "PAYPALISHIRING", numRows = 4，
 一开始0，1，2，3 行按顺序记录，然后 2，1行倒过来记录，再一次0，1，2，3 行按顺序记录，以此循环
 按顺序记录时，到哪一行哪一行就存字符，倒过来记录时，到哪一行哪一行存字符，此时别的行存空

*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string vec2string(vector<string> vec_str){
        string str;
        for(int i = 0; i < vec_str.size(); i++){
            for(int j = 0; j < vec_str[i].length(); j++){
                if(vec_str[i][j] != ' ')
                    str.push_back(vec_str[i][j]);
            }
        }
        return str;
    }
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int i = 0, is_forward = 1;
        vector<string> row(numRows);
        for(int n = 0; n < numRows; n++)
            row[n]="";
        while (1) {
            if(is_forward){
                for(; i < numRows; i++){
                    if(!s.empty()){
                        row[i].push_back(s[0]);
                        s.erase(s.begin());
                    }
                    else
                        return vec2string(row);
                    
                    if(i == (numRows-1)){
                        is_forward = 0;
                        break;
                    }
                }
            }
            if(!is_forward){
                for(i -= 1; i > 0; --i){
                    for(int j = 0; j < numRows; j++){
                        if(i == j){
                            if(!s.empty()){
                                row[i].push_back(s[0]);
                                s.erase(s.begin());
                            }
                            else
                                return vec2string(row);
                        }
                        else
                            row[j].push_back(' ');
                    }
                }
                is_forward = 1;
            }
        }
    }
};

int main(){
    string str = "ibgkxinzlgbjntwrvtlbmstfemisdnslpavokkovqphekfxiaijmaeugqcbtrvggvdxfnlcdajjnqgvqpedrizaabbtswbbteyatlcwnoiaeovvdbaxlzxlcygwwhzpnzpgkrfahnambyjhzlelkbwobfkxmkmcjbiwupwccwqguznwmrhyufmvkyszigbuhlsdbofdmxjjyyfkroiltuievcffigzrtrvuhcaucldakkldyvprszxnecsmkugendavhapjmukyexdcsutmutzyvumiosmbxmwfpnodhadnxgpsblevegvbahlqcxrzmqebfvgpvjcvpupqfvnlbiodsatuznvldcoixuxudcpvwelbcbodjejdecxgpttuviduecokeefaksdottsfabigfgmxbgryqusuziefojibcnpvjhcjklpstcpuiguydouewzjlkrmmhbkqlmzxzopssgmcnicswxwtwheibqvithyevzevptnicckpknjhmhakogspypzrwxyuycpoxewzgiqtxzcjgetxkmm";
    Solution s;
    cout << s.convert(str, 343) << endl;
    return 0;
}

