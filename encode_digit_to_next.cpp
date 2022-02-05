The "look and say" sequence is defined as follows: beginning with the term 1, each subsequent term visually describes the digits appearing in the previous term. The first few terms are as follows:

1
11             <- 1 one
21             <- 2 ones
1211           <- 1 two, 1 one
111221         <- 1 one, 1 two, 2 ones
312211         <- 3 ones, 2 twos, 1 one
Given an integer n, return the nth term of this sequence as a string.

Constraints

1 ≤ n ≤ 40
Example 1
Input
n = 3
Output
"21"
Example 2
Input
n = 4
Output
"1211"
Example 3
Input
n = 5
Output
"111221"

//code
string encode(string num) {
    int n = num.size();

    int i = 0;
    string text = "";
    int count = 1;
    while (i < n-1) {
        if (num[i] == num[i + 1]) {
            count++;
        } else {
            char cn='0'+(count);
            text += cn;
            text+=(num[i]);

            count=1;
        }
        i++;
    }
    char cn='0'+(count);
            text += cn;
            text+=(num[i]);

   return text;

}
string solve(int n) {
    string prev = "";
    string text = "1";

    if (n == 1) return "1";

    string rnum;
    int i = 2;
    while (i <= n) {
        text = encode(text);
        cout<<text<<'\n';
        i++;
    }

    return text;
}
