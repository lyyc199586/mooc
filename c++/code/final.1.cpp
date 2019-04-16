/* 字典编码（15分）
题目内容：

编写程序，给一段文本中的每个单词一个整数编码，输出文本的整数编码序列。要求（1）编码从1开始，按单词出现的先后顺序依次编码；（2）重复单词不重复编码；（3）输出的每个编码占3位，不足的前面补0。

输入:一段英文文本，一行，其中只有单词，单词由一个或多个空格分隔末尾可能有多于的空格，文本中没有标点和数字。文本长度不超过1000，单词数不超过300，每个单词的字符个数不超过20,字母均小写。

输出：整数编码序列。

样例1输入：

hello hello how are you

样例1输出：

001001002003004
*/ 

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    string input[300];
    int seq[300];
    static int len = 0;
    for (len; len < 300;len++){
        if(cin.get()=='\n'){
            break;
        }
        cin >> input[len];
    }
    //cout << len << endl;
    seq[0] = 1;
    for (int i = 1; i < len;i++){
        if(!input[i].compare(input[i-1])){
            seq[i] = seq[i - 1];
        }
        else{
            seq[i] = seq[i-1]+1;
        }
    }
    
    for (int i = 0; i < len;i++){
       cout.width(3);
       cout.fill('0'); 
       cout << seq[i];
    }
    return 0;
}
