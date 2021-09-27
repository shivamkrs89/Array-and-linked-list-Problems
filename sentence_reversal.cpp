Given a list of strings sentence where each sentence[i] is a string with single character, reverse the order of the words in the sentence.

You may assume there's no extraneous spaces in the sentence. Can you do modify sentence in-place and solve in O(1)\mathcal{O}(1)O(1) space?

Constraints

    n ≤ 10,000 where n is the length of sentence.

Example 1
Input

sentence = ["h", "i", " ", "w", "o", "r", "l", "d"]

Output

["w", "o", "r", "l", "d", " ", "h", "i"]

//code
void rev(vector<string> & sentence,int low,int hi)
{
int n=sentence.size();
    int i;

 while(low<=hi)
 {
     swap(sentence[low],sentence[hi]);
     low++,hi--;
 }   

}


vector<string> solve(vector<string>& sentence) {
    int n=sentence.size();
    int i,flag=-1;
    for(i=0;i<n;i++)
    {
        if(sentence[i]==" ")
        {flag=1;break;}
    }
    if(flag==-1)
    return sentence;
    rev(sentence,0,n-1); //first reversing the entire sentence
    int low=0;
    for(i=0;i<n;i++)   
    {
       if(sentence[i]==" ")//reversing wherever we encounter " "
       {
           rev(sentence,low,i-1);
           low=i+1;
       }
    }
    rev(sentence,low,n-1);//last we reverse the part which is not reversed inside for loop
//inplace algorith returns sentence 
return sentence;
}
