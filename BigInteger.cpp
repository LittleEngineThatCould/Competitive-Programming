class BigInt
{
public:
    vector<int> v;
    BigInt()
    {
        v.pb(0);
    }
 
    void output()
    {
        for(int i = v.size()-1; i >= 0; i--)
        {
            cout << v[i];
        }
    }
 
    BigInt operator+ (BigInt const &a)
    {
        int carry = 0;
        int mx = max(a.v.size(), this->v.size());
        vector<int> tmp(mx);
        for(int i = 0; i < mx || carry; i++)
        {
            if(i > mx-1) tmp.pb(0);
            tmp[i] = (i > a.v.size()-1 ? 0: a.v[i]) + (i > this->v.size()-1 ? 0 : this->v[i]) + carry;
            carry = (int)(tmp[i] >= 100000000);
            if(carry) tmp[i] -= 100000000;
        }
        BigInt ans;
        ans.v = tmp;
        return ans;
    }
};
