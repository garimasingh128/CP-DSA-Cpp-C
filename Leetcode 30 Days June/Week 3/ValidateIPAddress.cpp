class Solution {
public:
    bool check(char a)
    {
        a=tolower(a);
        if(a>='a' and a<='f')
            return true;

        return false;
    }
    bool ip4(string tmp)
    {
        if(tmp.length()==0 or tmp.length()>3)
            return false;

        bool zero=(tmp[0]=='0');

        if(zero and tmp.length()>1)
            return false;

        for(int i=0;i<tmp.length();i++)
        {
            if(!isdigit(tmp[i]))
                return false;

            if(i>0 and zero)
            {
                if(tmp[i]>'0')
                    return false;
            }
        }
        if(tmp.length()<3)
            return true;

        if(tmp<"256")
            return true;

        return false;
    }
    bool ip6(string tmp)
    {
        if(tmp.length()<1 or tmp.length()>4)
            return false;

        for(int i=0;i<tmp.length();i++)
        {
            if(!(isdigit(tmp[i]) or check(tmp[i])))
                return false;

        }
        return true;
    }
    bool ipv4(vector<string> tmp)
    {
        for(int i=0;i<tmp.size();i++)
        {
            if(!ip4(tmp[i]))
                return false;
        }
        return true;
    }
    bool ipv6(vector<string> tmp)
    {
        for(int i=0;i<tmp.size();i++)
        {
            if(!ip6(tmp[i]))
                return false;
        }
        return true;
    }
    string validIPAddress(string IP)
    {
        vector<string> ip;
        string tmp="";
        int count=0;

        for(int i=0;i<IP.length();i++)
        {
            if(IP[i]=='.' or IP[i]==':')
            {
                count++;

                if(tmp=="")
                    return "Neither";
                ip.push_back(tmp);
                tmp="";
                continue;
            }
            tmp+=IP[i];
        }
        if(tmp!="")
            ip.push_back(tmp);

        string res="Neither";

        if(ip.size()==4 and count==3)
        {
            if(ipv4(ip))
                res="IPv4";
        }
        else if(ip.size()==8 and count==7)
        {
            if(ipv6(ip))
                res="IPv6";
        }
        return res;
    }
};
