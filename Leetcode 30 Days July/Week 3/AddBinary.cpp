class Solution {
public:
    string addBinary(string a, string b) {

        reverse(a.begin(),a.end());reverse(b.begin(),b.end());
        char carry='0';

        if(a.length()<b.length())
        {
            string t=a;
            a=b;
            b=t;
        }
        int i;
        for(i=0;i<b.length();i++)
        {
                if(b[i]=='1'&&a[i]=='0'&&carry=='0')
                    a[i]='1';
                else if(b[i]=='1'&&a[i]=='1'&&carry=='0')
                {
                    a[i]='0';
                    carry='1';
                }
                else if(b[i]=='0'&&a[i]=='0'&&carry=='1')
                {
                    a[i]='1';
                    carry='0';
                }
                else if(b[i]=='0'&&a[i]=='1'&&carry=='1')
                {
                    a[i]='0';
                }
            }

         while(carry=='1'&&i<a.length())
         {
                if(a[i]=='0')
                {
                    a[i]='1';
                    carry='0';
                }
                else
                    a[i]='0';
                i++;
        }
        reverse(a.begin(),a.end());

         if(carry=='1')
             a.insert(a.begin(),carry);

        return a;
    }
};
